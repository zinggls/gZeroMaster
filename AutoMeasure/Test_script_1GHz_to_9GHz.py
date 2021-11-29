import pyvisa

rm = pyvisa.ResourceManager()
inst = rm.open_resource("TCPIP0::192.168.0.66::INSTR")
manufacturer, product, serial_num, firmware_ver = inst.query("*IDN?").replace("\n", "").split(",")

def set_frequency(ghz):
    if (ghz >= 1 and ghz <= 9):
        inst.write("source9:frequency {}e9".format(ghz))
    else:
        print("Not available frequency")

def set_data_pattern(pattern): # Programming guide p105.
    patt = pattern[0:4]
    num = pattern[4:]
    if (patt == "ZSUB" and pattern[4:9] == "stitut"):
        if (num == "7" or num == "10" or num == "11" or num == "13" or num == "15" or num == "23"):
            inst.write("source1:pattern:select {}".format(pattern))
        else:
            print("Not available data pattern")
    elif (patt == "UPAT" and pattern[4:7] == "tern"):
        if (int(num) >= 1 and int(num) <= 12):
            inst.write("source1:pattern:select {}".format(pattern))
        else:
            print("Not available data pattern")
    elif (patt == "MDEN" and pattern[4:7] == "sity"):
        if (num == "7" or num == "10" or num == "11" or num == "13" or num == "15" or num == "23"):
            inst.write("source1:pattern:select {}".format(pattern))
        else:
            print("Not available data pattern")
    elif (patt == "PRBS" or patt == "PRBN" or patt == "MDEN" or patt == "ZSUB"):
        if (num == "7" or num == "10" or num == "11" or num == "15" or num == "23"):
            inst.write("source1:pattern:select {}".format(pattern))
        elif ((num == "13" and (patt == "PRBN" or patt == "MDEN" or patt == "ZSUB")) \
                 or (num == "31" and patt == "PRBS")):
            inst.write("source1:pattern:select {}".format(pattern))
        else:
            print("Not available data pattern")
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
        print("Not available data pattern")

if (product == "N4903B"):
    print("Found BERT")

    set_frequency(10)
    set_data_pattern("PRBS27")
else:
    print("Not found BERT")
