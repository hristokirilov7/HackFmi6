import RPi.GPIO as GPIO
from time import sleep
GPIO.setwarnings(False)

GPIO.setmode(GPIO.BCM)

Motor1E = 27
Motor1A = 17
Motor1B = 18


Motor2E = 26
Motor2A = 13 ## 19 13
Motor2B = 19#26

 

 
print "Going forwards"
GPIO.setup(Motor1E,1)
GPIO.setup(Motor1A,1)
GPIO.setup(Motor1B,0)


GPIO.setup(Motor2E,1)
GPIO.setup(Motor2A,1)
GPIO.setup(Motor2B,0)

 
sleep(2)
 
print "Going backwards"
GPIO.setup(Motor1A,1)
GPIO.setup(Motor1B,1)
GPIO.setup(Motor1E,0)
 
GPIO.setup(Motor2A,0)
GPIO.setup(Motor2B,1)
GPIO.setup(Motor2E,1)
 
sleep(2)
 
print "Now stop"
GPIO.setup(Motor1E,0)
GPIO.setup(Motor2E,0)
 
GPIO.cleanup()
