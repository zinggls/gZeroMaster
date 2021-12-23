import ZeroMQ_Lib
import pyVISA_Lib
import time

MIN_GHZ = 1
MAX_GHZ = 7
TRY_ALIGN = 1
ACCUMULATE_TIME = 3

gZeroMaster = ZeroMQ_Lib.gZeroMaster(5555, 5556)
TX_Mod = gZeroMaster.gZero_TX
RX_Mod = gZeroMaster.gZero_RX

TX_Mod.set_register("TX", "PA Gain Control1", 0x0)
TX_Mod.set_register("TX", "PA Gain Control2", 0x0)
TX_Mod.set_register("TX", "VCO Oscillation Freq", 0x1)

gZeroMaster.send_all()
gZeroMaster.save_all()
gZeroMaster.close_csv()

#Atten = ZeroMQ_Lib.Attenuator_Lib(12345)
#atten_list = [22, 20, 18, 14, 12, 10]
atten_list = [22]

csv = open("result.csv", "w")
for Atten_dB in atten_list:

    #Atten.set_atten(Atten_dB)

    pyVISA = pyVISA_Lib.pyVISA_Lib()
    inst = pyVISA.get_inst()
    csv.write("Freq (GHz) (ATT: {}dB),Bit count,Error count,Bit Error Rate\n".format(Atten_dB))

    for ghz in range(MIN_GHZ, MAX_GHZ + 1):
        time.sleep(1)
        if (pyVISA.get_opc() == True):
            pyVISA.set_frequency(ghz)
            time.sleep(2)
            ret = pyVISA.auto_align(TRY_ALIGN)
            if (ret == True): 
                bcount, ecount, eratio = pyVISA.accumulate(ACCUMULATE_TIME)
                #print("{} GHz".format(ghz))
                csv_data = "{},{},{},{}\n".format(ghz, bcount, ecount, eratio)
                csv.write(csv_data)
            else:
                csv_data = "{},{},{},{}\n".format(ghz, "ALIGN FAILED", "ERROR", "ERROR")
                csv.write(csv_data)
                break
        
csv.close()
