import serial
import time
import paho.mqtt.client as mqtt
import json
import RPi.GPIO as GPIO


MODE = 0  # mode = 0 is full-guto, mode = 1 is half-auto
if MODE == 1:
    EN_485 = 4
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(EN_485, GPIO.OUT)
    GPIO.output(EN_485, GPIO.HIGH)


HOST = "mqtt.sztuiot.cn"
PORT = 1883
client.connect(HOST, PORT, 60)
ser = serial.Serial("/dev/ttyS0", 115200, timeout=1)
print(ser.portstr)

commond = "01 03 00 1E 00 03 34 0D"
#commond = "01 03 00 12 00 02 65 CB"
print(bytes.fromhex(commond))
ser.write(bytes.fromhex(commond))
time.sleep(1)


recvdata = ""

while ser.inWaiting() > 0:
    recvdata = ser.readline()
    if data != "":
        print(recvdata)
        recvdata = ""

client.loop()

client.publish(PROP_POST_TOPIC, json.dumps(data), 2)

