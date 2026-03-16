from machine import Pin, Timer

builtInLED = 25

LED = Pin(builtInLED, Pin.OUT)

timer = Timer()

def Blinker(timer):

    led.toggle()

timer.init(freq=4, mode=Timer.PERIODIC, callback=Blinker)