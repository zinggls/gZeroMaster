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
        Response:OK
{ "RX": {  "RX Data Interface":true} }
        Response:OK
{ "RX": {  "Limiting Amplifier Enable":false} }
        Response:OK
{ "RX": {  "Limiting Amplifier Enable":true} }
        Response:OK
{ "RX": {  "LNA Gain":0} }
        Response:OK
{ "RX": {  "LNA Gain":1} }
        Response:OK
{ "RX": {  "LNA Gain":2} }
        Response:OK
{ "RX": {  "LNA Gain":3} }
        Response:OK
{ "RX": {  "LNA Gain":4} }
        Response:OK
{ "RX": {  "LNA Gain":5} }
        Response:OK
{ "RX": {  "LNA Gain":6} }
        Response:OK
{ "RX": {  "LNA Gain":7} }
        Response:OK
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
            socket.send_string(raw2)
            print("\tResponse:%s" %socket.recv_string())

    if i=="LNA Gain":
        for v in range(8):
            raw2 = raw1 + str(v)
            raw2 += '} }'
            print(raw2)
            socket.send_string(raw2)
            print("\tResponse:%s" %socket.recv_string())