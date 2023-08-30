import serial
import serial.tools.list_ports
 
devList = serial.tools.list_ports.comports()

for dev in devList:
    print(dev.device)
    if dev.pid == 60000:
        print("ok")
        break
    else:
        raise Exception("No device Found")
        quit()

ser = serial.Serial()
ser.baudrate = 115200
ser.port = dev.device
ser.open()
 
ser.write("fdr".encode())
print(ser.readline().decode())
ser.close()

quit()