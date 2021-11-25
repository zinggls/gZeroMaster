import pyvisa

rm = pyvisa.ResourceManager()
inst = rm.open_resource("TCPIP0::192.168.0.66::INSTR")
print(inst.query("*IDN?"))
print(inst.query("*OPC?"))
