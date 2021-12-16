import ZeroMQ_Lib
import pyVISA_Lib
import time

gZero_TX = ZeroMQ_Lib.gZeroMaster_Lib(5555)
gZero_RX = ZeroMQ_Lib.gZeroMaster_Lib(5556)

gZero_TX.set_register("BIAS", "Core Current", 10)
gZero_RX.set_register("BIAS", "Core Current", 10)

#gZero_TX.send_all_command()
#gZero_RX.send_all_command()

gZero_TX.send_command()
gZero_RX.send_command()

Atten = ZeroMQ_Lib.Attenuator_Lib(12345)
atten_list = [20]

gZero_TX_reg_csv = open("reg_TX.csv", "w")
gZero_RX_reg_csv = open("reg_RX.csv", "w")
csv = open("result.csv", "w")
gZero_TX.save_all_in_csv(gZero_TX_reg_csv, 5555)
gZero_RX.save_all_in_csv(gZero_RX_reg_csv, 5556)
for Atten_dB in atten_list:

    Atten.set_atten(Atten_dB)

    pyVISA = pyVISA_Lib.pyVISA_Lib()
    inst = pyVISA.get_inst()
    csv.write("Freq (GHz) (ATT: {}dB),Bit count,Error count,Bit Error Rate\n".format(Atten_dB))

    for ghz in range(1, 10):
        time.sleep(1)
        if (pyVISA.get_opc() == True):
            pyVISA.set_frequency(ghz)
            time.sleep(2)
            ret = pyVISA.auto_align(1)
            if (ret == True):
                bcount, ecount, eratio = pyVISA.accumulate(3)
                #print("{} GHz".format(ghz))
                csv_data = "{},{},{},{}\n".format(ghz, bcount, ecount, eratio)
            else:
                csv_data = "{},{},{},{}\n".format(ghz, "ALIGN FAILED", 0, 0)
            csv.write(csv_data)
        
csv.close()
gZero_TX_reg_csv.close()
gZero_RX_reg_csv.close()
