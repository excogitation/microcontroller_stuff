##piddybot
Inspired from http://www.idlehandsproject.com/piddybot-a-self-balancing-teaching-tool/ but not willing to pay the 100USD
for parts ordering from Sparkfun I looked up the parts on aliexpress and ordered everything and a gyro with the same chips on it (GY-85).

Modified sources + schematic files are in piddybot.


##L6234

The L6234 is a three phase motordriver from ST (st.com)
datasheet - http://www.st.com/web/en/resource/technical/document/datasheet/CD00000046.pdf

It makes use of 3 half-bridges, enabling you to drive a bldc motor with your
favorite microcontroller and 3 pwm pins. (+ one additional output to enable the driver).

There is no feedback, so you rely on (like with a stepper motor) the load resistance being
lower than the motor torque (or you have to add some sort of feedback like an imu).

setup:
![test setup](https://lh6.googleusercontent.com/-kZpJjEVX8Ik/VJsOuHbK2eI/AAAAAAAAlZ8/nMfAdd5b4XE/s640/IMG_20141222_173939.jpg)
phase output of 2 phases:
![2phase output viewed with an oscilloscope](https://lh4.googleusercontent.com/-zENCOi27_vo/VJsOuCxgy4I/AAAAAAAAlYs/JeuuS_nsfDE/s640/IMG_20141222_175256.jpg)

##SSD1306
![SSD1306](https://lh3.googleusercontent.com/-yK1OUCjUUCY/Vg84WeBtuLI/AAAAAAAAye0/WlF1pN5If_E/s400-Ic42/IMG_20151003_014038.jpg)




