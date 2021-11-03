import zmq
import time
import json

context = zmq.Context()

print("Connecting to gZeroMaster…")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

with open("..\\tests\\rx.json") as json_file:
    json_data = json.load(json_file)
    print("json load OK")

f = open("..\\tests\\rx.json",'r')
data = f.read()
f.close()

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

        time.sleep(1)