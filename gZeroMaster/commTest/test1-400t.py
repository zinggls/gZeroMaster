import time
import util

print("Connecting to gZeroMaster…")
socket = util.connect("tcp://localhost:5555")

jsonFilePath = "..\\tests\\400t.json"
print("Input json file=%s" %jsonFilePath)

json_data = util.jsonLoad(jsonFilePath)     #json_data type = <class 'dict'>
print("json load OK")
print(json_data)

data = util.readData(jsonFilePath)          #data type = <class 'str'>
print(data)