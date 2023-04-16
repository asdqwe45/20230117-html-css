from gpiozero import LED
from time import sleep
from gpiozero import Button
from signal import pause

a=LED(17)
b=LED(27)
c=LED(22)
d=LED(24)
e=LED(9)
f=LED(11)
g=LED(8)
DP=LED(7)

LED1=LED(25)
button2=Button(2)

lst = [g, f, a, b, e, d, c, DP]

lst = [g, f, a, b, e, d, c, DP]
num = [[a, b, c, d, e, f],  # 0
       [b, c],  # 1
       [a, b, g, e, d],  # 2
       [a, b, g, c, d],  # 3
       [f, g, b, c],  # 4
       [a, f, g, c, d],  # 5
       [a, f, g, e, c, d],  # 6
       [f, a, b, c],  # 7
       [a, b, c, d, e, f, g],  # 8
       [a, b, c, d, g, f]]  # 9
now=-1

def LED_on():
    global now
    if(now==7):
        for k in range(3):
            LED1.on()
            sleep(0.5)
            LED1.off()
            sleep(0.5)

while True:
    for i in range(10):
        now=i
        for j in range(len(num[i])):
            num[i][j].on()
        sleep(1)
        for j in range(len(num[i])):
            num[i][j].off()

    for i in range(9,-1,-1):
        now=i
        for j in range(len(num[i])):
            num[i][j].on()
        sleep(1)
        for j in range(len(num[i])):
            num[i][j].off()

button2.when_pressed=LED_on