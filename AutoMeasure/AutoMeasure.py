import pyvisa
import time

def get_inst():
    rm = pyvisa.ResourceManager()
    inst = rm.open_resource("TCPIP0::192.168.0.66::INSTR")
    return inst

def set_frequency(inst, ghz):
    if (ghz >= 1 and ghz <= 9):
        inst.write("source9:frequency {}e9".format(ghz))
    else:
        print("Not available frequency: {}GHz".format(ghz))

def set_data_pattern(inst, pattern): # Programming guide p105.
    patt = pattern[0:4]
    num = pattern[4:]
    if (patt == "ZSUB" and pattern[4:9] == "stitut"):
        if (num == "7" or num == "10" or num == "11" or num == "13" or num == "15" or num == "23"):
            inst.write("source1:pattern:select {}".format(pattern))
        else:
            print("Not available data pattern: {}".format(pattern))
    elif (patt == "UPAT" and pattern[4:7] == "tern"):
        if (int(num) >= 1 and int(num) <= 12):
            inst.write("source1:pattern:select {}".format(pattern))
        else:
            print("Not available data pattern: {}".format(pattern))
    elif (patt == "MDEN" and pattern[4:7] == "sity"):
        if (num == "7" or num == "10" or num == "11" or num == "13" or num == "15" or num == "23"):
            inst.write("source1:pattern:select {}".format(pattern))
        else:
            print("Not available data pattern: {}".format(pattern))
    elif (patt == "PRBS" or patt == "PRBN" or patt == "MDEN" or patt == "ZSUB"):
        if (num == "7" or num == "10" or num == "11" or num == "15" or num == "23"):
            inst.write("source1:pattern:select {}".format(pattern))
        elif ((num == "13" and (patt == "PRBN" or patt == "MDEN" or patt == "ZSUB")) \
                 or (num == "31" and patt == "PRBS")):
            inst.write("source1:pattern:select {}".format(pattern))
        else:
            print("Not available data pattern: {}".format(pattern))
    elif (patt == "UPAT"):
        if (int(num) >= 1 and int(num) <= 12):
            inst.write("source1:pattern:select {}".format(pattern))
        else:
            print("Not available data pattern")
    elif (pattern[0:3] == "FIL" or pattern[0:8] == "FILename"):
        inst.write("source1:pattern:select {}".format(pattern))
    elif (pattern == "PRBS23P"):
        inst.write("source1:pattern:select {}".format(pattern))
    else:
        print("Not available data pattern: {}".format(pattern))

def accumulation_config(inst, mode, manner, period_time):
    inst.write("sense1:eye:align:auto 1")
    if (mode == 0):
        inst.write("sense:gate:mode SING")
    else:
        print("Not available mode: {}".format(mode))

    if (manner == "time" or manner == "t"):
        inst.write("sense:gate:manner TIME")
    else:
        print("Not available manner: {}".format(manner))

    if (period_time >= 0):
        inst.write("sense:gate:period:time {}".format(period_time))
    else:
        print("Not available time: {}".format(period_time))

def accumulation_run(inst):
    inst.write("sense1:gate:state 1")
    state = inst.query("sense1:gate:state?")
    
    while state.startswith("1"):
        time.sleep(0.01)
        state = inst.query("sense1:gate:state?")

    bit_count = int(float(inst.query("fetch:sense2:bcount?").replace("\n", "")))
    err_count = int(float(inst.query("fetch:sense1:ecount:all:full:total?").replace("\n", "")))
    BER = float(inst.query("fetch:sense1:eratio:all:full:total?").replace("\n", ""))

    if (BER >= 1.0):
        return bit_count, err_count, 1.0
    else:
        return bit_count, err_count, float(BER)
