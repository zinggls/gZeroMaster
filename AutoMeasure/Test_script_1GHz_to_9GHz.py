import AutoMeasure as AM

inst = AM.get_inst()
manufacturer, product, serial_num, firmware_ver = inst.query("*IDN?").replace("\n", "").split(",")
if (product == "N4903B"):
    print("Found BERT")

    csv = open("result.csv", "w")
    csv.write("Freq (GHz),Bit count,Error count,Bit Error Rate\n")
    for ghz in range(1, 10):
        AM.set_frequency(inst, ghz)
        AM.set_data_pattern(inst, "PRBS7")
        AM.accumulation_config(inst, 0, "t", 5)
        bit_count, err_count, BER = AM.accumulation_run(inst)

        print("Frequency: {}GHz".format(ghz))
        print("Bit count: {:,}".format(bit_count))
        print("Error count: {:,}".format(err_count))
        print("Bit Error Rate: {:E}".format(BER))

        data = "{},{:E},{:E},{:E}\n".format(ghz, bit_count, err_count, BER)
        csv.write(data)

    csv.close()
else:
    print("Not found BERT")
