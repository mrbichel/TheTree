rør 
ø indre 105
ø ydre 110


Power input 12 V


Calculations:
- LED current is approximately equal to: 0.5 / R3
- R3 power: the power dissipated by the resistor is approximately: 0.25 / R3. choose a resistor value at least 2x the power calculated so the resistor does not get burning hot.

so for 700mA LED current:
R3 = 0.5 / 0.7 = 0.71 ohms. closest standard resistor is 0.75 ohms.
R3 power = 0.25 / 0.71 = 0.35 watts. we'll need at least a 1/2 watt rated resistor.



Brand new and high quality.
High brightness, light and color consistency.
Color: Red, Green, Blue.
Viewing Angle: 140 degree.
Wavelength: R:620-630nm G:515-525nm B:460-470nm.
Voltage(Vf): R:2.0-2.5V G:3.2-3.6V B:3.2-3.86.
Luminous intensity: R:30-35lm G:40-45lm B:15-20lm.
Current: each 350mA


Wo for 350mA LED current:
R3 = 0.5 / 0.35 = 1.42857142857 ohms. closest standard resistor is 1.5 ohms.
R3 power = 0.25 / 1.42857142857 = 0.175 watts.
We use two 3.3 Ohm resistors


3 in parralell calculation
We have 350 mA LEDS
x3 = 1050

R3 = 0.5/1.05 = 0.47619047619
R3 power = 0.25 / 0.47619047619 = 0.525 W 

Standard resistors are 1/4W so 2 of them si okish 
In parralllel the closest we get to 0.47619047619 ohm with two standard resistors is with two 1 ohm resistors



pcb2gcode --back /home/parallels/Desktop/psf/TheTree/3leds/series/inseries_copperBottom.gbl --drill /home/parallels/Desktop/psf/TheTree/3leds/series/inseries_drill.txt --outline /home/parallels/Desktop/psf/TheTree/3leds/series/inseries_contour.gm1 --zwork -0.2 --zsafe 25.0 --mill-feed 6 --mill-speed 30000 --metric --offset 2.0 --basename johandrill --zdrill -2.0 --zchange 10.0 --drill-feed 6 --drill-speed 20000 --cutter-diameter 3.0 --zcut -2.0 -cut-speed 20000
---

 pcb2gcode --back /home/parallels/Desktop/psf/TheTree/3leds/series/inseries_copperBottom.gbl --drill /home/parallels/Desktop/psf/TheTree/3leds/series/inseries_drill.txt --outline /home/parallels/Desktop/psf/TheTree/3leds/series/inseries_contour.gm1 --zwork -0.2 --zsafe 25.0 --mill-feed 6 --mill-speed 30000 --metric --offset 50 --basename johandrill --zdrill -2.0 --zchange 10.0 --drill-feed 6 --drill-speed 20000 --cutter-diameter 3.0 --zcut -2.0 --cut-speed 20000 --milldrill --fill-outline --outline-width 2

--fill-outline --outline-width 2 for using fritzing outline file


http://chilipeppr.com/tinyg

http://simplegcoder.com/js_editor/

http://jscut.org/jscut.html#

http://simplegcoder.com/js_editor_framework/

http://fablabamersfoort.nl/drill2gcode/

pcb2gcode --back /home/parallels/Desktop/psf/TheTree/3leds/series/inseries_copperBottom.gbl --drill /home/parallels/Desktop/psf/TheTree/3leds/series/inseries_drill.txt --outline /home/parallels/Desktop/psf/TheTree/3leds/series/inseries_contour.gm1 --zwork -0.008 --zsafe 1 --mill-feed 6 --mill-speed 30000 --offset 1 --basename __newdrill --zdrill -0.07 --zchange 0.4 --drill-feed 6 --drill-speed 20000 --cutter-diameter 0.015 --zcut -0.07 --cut-speed 20000 --fill-outline --outline-width 0.01

Remember to connect MAX485 pin to ground with jumper
