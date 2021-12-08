import zmq
import json
import pyvisa
import time

context = zmq.Context()

class gZeroMaster:
    def __init__(self, port):
        self.gZero_socket = context.socket(zmq.REQ)
        self.gZero_socket.connect("tcp://127.0.0.1:{}".format(port))
        with open("gZeroMaster_JSON.json") as json_file:
            self.gZero_obj = json.load(json_file)

    def send_command(self):
        json_str = json.dumps(self.gZero_obj)
        self.gZero_socket.send(json_str.encode())
        recv_msg = self.gZero_socket.recv()
        print(recv_msg.decode())
        
gZero_TX = gZeroMaster(5555)
gZero_RX = gZeroMaster(5556)

gZero_TX.send_command()
gZero_RX.send_command()

rm = pyvisa.ResourceManager()
inst = rm.open_resource(rm.list_resources()[0])
csv = open("result.csv", "w")
csv.write("Freq (GHz),Bit count,Error count,Bit Error Rate\n")

for ghz in range(1, 9):
    time.sleep(1)
    if (inst.query("*OPC?") == "1\n"):
        print("Frequency: {}GHz".format(ghz))

        inst.write("source1:pattern:select PRBS7")
        inst.write("source9:frequency {}e9".format(ghz))
        inst.write("sense1:eye:align:auto on")

        while True:
            time.sleep(1)
            state = inst.query("sense1:eye:align:auto?")
            #print(state)
            
            if (state == "CS_SUCCESSFUL\n"):
                print("Align successful")
                break
            elif (state == "CS_FAILED\n"):
                inst.write("sense1:eye:align:auto 0")
                print("Align failed: {}".format(inst.query("sense1:eye:align:message?").replace("\n","")))
                break
            
        inst.write("sense:gate:mode SING")
        inst.write("sense1:gate:manner TIME")
        inst.write("sense1:gate:period:time 3")
        inst.write("sense1:gate:state 1")

        while True:
            time.sleep(1)
            
            state = inst.query("sense1:gate:state?")
            if (state == "0\n"):
                break

        bcount = int(float(inst.query("fetch:sense2:bcount?").replace("\n","")))
        ecount = int(float(inst.query("fetch:sense1:ecount:all:full:total?").replace("\n","")))
        eratio = float(inst.query("fetch:sense1:eratio:all:full:total?").replace("\n",""))
        print("Total bit count: {}".format(bcount))
        print("Total error count: {}".format(ecount))
        print("Bit Error Ratio: {}".format(eratio))

        csv_data = "{},{},{},{}\n".format(ghz, bcount, ecount, eratio)
        csv.write(csv_data)
        time.sleep(1)
csv.close()
