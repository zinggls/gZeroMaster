import pyvisa

rm=pyvisa.ResourceManager()
print("resources = %s"%rm.list_resources())
inst = rm.open_resource(rm.list_resources()[0])

print(inst.query("*IDN?"))  #N4903B 기기 정보 확인
