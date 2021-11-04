import time
import util

print("Connecting to gZeroMaster…")
socket = util.connect("tcp://localhost:5555")

jsonFilePath = "..\\tests\\rx.json"
print("Input json file=%s" %jsonFilePath)

json_data = util.jsonLoad(jsonFilePath)     #json_data type = <class 'dict'>
print("json load OK")
print(json_data)

data = util.readData(jsonFilePath)          #data type = <class 'str'>
print(data)

socket.send_string(data);
print("Response:%s" %socket.recv_string())

#LNA Gain을 0에서 부터 10까지 변경 테스트
#gZeroMaster에서 0~7까지는 범위내 값으로 받아들이고 8이후는 out of range 오류를 발생해야 함
for i in range(10):
    raw = r'{ "RX": {  "LNA Gain": '
    raw += str(i)
    raw += '} }'

    print("I=%s %s" %(i,raw))
    socket.send_string(raw)
    rtn = socket.recv_string()
    print("\tResponse:%s" %rtn)

    if rtn=="OK":   #성공하는 경우에만 json객체의 값을 업데이트 한다
        json_data["RX"]["LNA Gain"]=i
        print("\tjson_data updated")

    #time.sleep(1)

for key in json_data["RX"]:
    print("key="+key,",value="+str(json_data["RX"][key]))

"""
{ "RX": {  "LNA Gain":0} }
{ "RX": {  "LNA Gain":1} }
{ "RX": {  "LNA Gain":2} }
{ "RX": {  "LNA Gain":3} }
{ "RX": {  "LNA Gain":4} }
{ "RX": {  "LNA Gain":5} }
{ "RX": {  "LNA Gain":6} }
{ "RX": {  "LNA Gain":7} }
"""

raw0 = r'{ "RX": {  "'
for i in json_data["RX"]:
    if i=="LNA Gain":
        raw1 = raw0 + str(i)
        raw1 += r'":'
        for v in range(8):
            raw2 = raw1 + str(v)
            raw2 += '} }'
            print(raw2)


"""
{ "RX": {  "RX Data Interface":false} }
{ "RX": {  "RX Data Interface":true} }
{ "RX": {  "Limiting Amplifier Enable":false} }
{ "RX": {  "Limiting Amplifier Enable":true} }
{ "RX": {  "LNA Gain":0} }
{ "RX": {  "LNA Gain":1} }
{ "RX": {  "LNA Gain":2} }
{ "RX": {  "LNA Gain":3} }
{ "RX": {  "LNA Gain":4} }
{ "RX": {  "LNA Gain":5} }
{ "RX": {  "LNA Gain":6} }
{ "RX": {  "LNA Gain":7} }
"""

raw0 = r'{ "RX": {  "'
for i in json_data["RX"]:
    raw1 = raw0 + str(i)
    raw1 += r'":'
    if i=="RX Data Interface" or i=="Limiting Amplifier Enable":
        for v in range(2):
            raw2 = raw1 + str(bool(v)).lower()
            raw2 += '} }'
            print(raw2)

    if i=="LNA Gain":
        for v in range(8):
            raw2 = raw1 + str(v)
            raw2 += '} }'
            print(raw2)