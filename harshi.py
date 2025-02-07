import serial
import csv
from datetime import datetime

s = serial.Serial('COM14', 9600, timeout=2)

filename = "ultrasoinc_sensor.csv"
with open(filename, 'a', newline = '') as file:
    writer = csv.writer(file)
    writer.writerow({"Time", "Distance in (cm)"})

    try:
        while  True:
            if s.in_waiting > 0:
                distance = s.readline().decode('utf-8').strip()
                timestamp = datetime.now().strftime("%Y%m%d%H%M%S")
                writer.writerow({timestamp, distance})
                print(f"Information: {timestamp} : {Distance} cm" )
    except KeyboardInterrupt:
        print("Stopped")
        s.close()


       