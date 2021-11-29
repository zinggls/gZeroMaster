import pyvisa

rm = pyvisa.ResourceManager()
inst = rm.open_resource("TCPIP0::192.168.0.66::INSTR")
manufacturer, product, serial_num, firmware_ver = inst.query("*IDN?").replace("\n", "").split(",")

if (product == "N4903B"):
    print("Found BERT")
else:
    print("Not found BERT")
