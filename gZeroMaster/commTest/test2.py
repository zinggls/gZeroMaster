import pyvisa
import time

rm=pyvisa.ResourceManager()
print("resources = %s"%rm.list_resources())
inst = rm.open_resource(rm.list_resources()[0])

print(inst.query("*IDN?"))                                      #N4903B 기기 정보 확인

inst.write("*rst")                                              #N4903B 리셋
print("N4903B 리셋")

inst.write("source1:voltage:level:immediate:high 6e-1")         #High 전압 600mV 설정
print("High 전압 600mV 설정")

inst.write("source1:voltage:level:immediate:low 4e-1")          #Low 전압 400mV 설정
print("Low 전압 400mV 설정")

inst.write("source1:voltage:level:immediate:offset 5e-1")       #Offset 전압 500mV 설정
print("Offset 전압 500mV 설정")

time.sleep (5)                                                  #전압을 읽어오기 전에 sleep, 5초 미만인 경우는 timeout됨

print(inst.query("source1:voltage:level:immediate:high?"))      #High 전압 확인
print("High 전압 확인")

print(inst.query("source1:voltage:level:immediate:low?"))       #Low 전압 확인
print("Low 전압 확인")

print(inst.query("source1:voltage:level:immediate:offset?"))    #Offset 전압 확인
print("Offset 전압 확인")

print(inst.write("source9:frequency 3e9"))                      #Data Rate 3GHz 설정
print("Data Rate 3GHz 설정")

print(inst.query("source9:frequency?"))                         #Data Rate 확인
print("Data Rate 확인")
