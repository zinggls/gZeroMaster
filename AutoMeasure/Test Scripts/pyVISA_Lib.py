import pyvisa
import time

class pyVISA_Lib:
    def __init__(self):
        rm = pyvisa.ResourceManager()
        self.inst = rm.open_resource(rm.list_resources()[0])

    def get_inst(self):
        return self.inst

    def get_idc(self):
        return self.inst.query("*IDN?")

    def query(self, query_str):
        return self.inst.query(query_str).replace("\n", "")

    def write(self, write_str):
        self.inst.write(write_str)

    def get_opc(self):
        return bool(self.query("*OPC?"))
    
    def set_pattern(self, pattern):
        self.write("source9:pattern:select {}".format("PRBS7"))
        #self.write("source9:pattern:select {}".format(pattern))

    def set_frequency(self, ghz):
        self.write("source9:frequency {}e9".format(ghz))

    def auto_align(self):
        for cnt in range(5):
            self.write("sense1:eye:align:auto on")
            while True:
                time.sleep(1)
                state = self.query("sense1:eye:align:auto?")
                if (state == "CS_SUCCESSFUL"):
                    print("Align successful")
                    return True
                elif (state == "CS_FAILED"):
                    print("Align failed")
                    self.write("sense1:eye:align:auto 0")
                    print("{}".format(self.query("sense1:eye:align:message?")))
                    break
        print("Failed {}th time, align failed".format(cnt + 1))
        return False

    def accumulate(self):
        self.write("sense:gate:mode SING")
        self.write("sense1:gate:manner TIME")
        self.write("sense1:gate:period:time 3")
        self.write("sense1:gate:state 1")

        while True:
            time.sleep(1)
            state = self.query("sense1:gate:state?")
            if (state == "0"):
                break

        bcount = int(float(self.query("fetch:sense2:bcount?")))
        ecount = int(float(self.query("fetch:sense1:ecount:all:full:total?")))
        eratio = float(self.query("fetch:sense1:eratio:all:full:total?"))

        return bcount, ecount, eratio
