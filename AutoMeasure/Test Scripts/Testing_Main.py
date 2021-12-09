import ZeroMQ_Lib
import pyVISA_Lib
import time

gZero_TX = ZeroMQ_Lib.gZeroMaster_Lib(5555)
gZero_RX = ZeroMQ_Lib.gZeroMaster_Lib(5556)

gZero_TX.json_file_load("gZeroMaster_JSON.json")
gZero_RX.json_file_load("gZeroMaster_JSON.json")

gZero_TX.send_all_command()
gZero_RX.send_all_command()

#Atten = ZeroMQ_Lib.Attenuator_Lib(1234)
#Atten.set_atten(4)

pyVISA = pyVISA_Lib.pyVISA_Lib()
inst = pyVISA.get_inst()
csv = open("result.csv", "w")
csv.write("Freq (GHz),Bit count,Error count,Bit Error Rate\n")

for ghz in range(1, 10):
    time.sleep(1)
    if (pyVISA.get_opc() == True):
        pyVISA.set_frequency(ghz)
        ret = pyVISA.auto_align()
        if (ret == True):
            bcount, ecount, eratio = pyVISA.accumulate()

            csv_data = "{},{},{},{}\n".format(ghz, bcount, ecount, eratio)
        else:
            csv_data = "{},{},{},{}\n".format(ghz, "ALIGN FAILED", 0, 0)
        csv.write(csv_data)
        
csv.close()
