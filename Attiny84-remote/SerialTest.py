import serial
ser = serial.Serial("/dev/ttyAMA0", baudrate=9600, timeout=3.0)

while True:
        line = ser.readline()
        #print(len(line))
        if len(str(line)) == 8:
                print(str(line[0:6]))