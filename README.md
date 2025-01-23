# New GLDAB by Arduino Pro mini : gliding device using Arduino

![230711-2 Pterasaur3small](/Image/230711-2%20Pterasaur3small%20.jpg)

![250120 New GLDAB by Arduino pro mini 4g](/Image/250120%20New%20GLDAB%20by%20Arduino%20pro%20mini%204g.jpg)


New GLDAB is a device that detects the position of the wing with a magnetic sensor and stops the wing movement at the optimal position for gliding.

When the throttle is set to the lowest position, the wing continues to move at a preset speed, and when it reaches the optimal position for gliding (detected by the magnetic sensor), the wing movement stops.

The wing moves slightly in the opposite direction due to wind pressure, and the ratchet gets caught on the bolt on the gear, fixing it in the gliding position and allowing it to glide.

![250117 NewGLDAB Action](/Image/250117%20NewGLDAB%20Action%20.jpg)

In order to make the Ornithopter glide, I created a device (New GLDAB) that uses a magnetic sensor to stop the wings in the gliding position using an Arduino pro mini board.



How New GLDAB Works

http://kakutaclinic.life.coocan.jp/GLDAB.htm

New GLDAB by Arduino Pro mini (My website)

http://kakutaclinic.life.coocan.jp/GLDABArd.html


How New GLDAB by Arduino Pro mini works

YouTube Video https://www.youtube.com/watch?v=KpQxz6biprs




## Need : 

Arduino pro mini board

4.7KOhms resistor

Panasonic Hall Sensor IC DN6852-A 

      (If you use Panasonic Hall Sensor IC DN6851, 

      Change "val == 1" to "val == 0" in Line 103.)


## Wiring

![240504 New GLDAB by Arduino 4.7KR wiring](/Image/240504%20New%20GLDAB%20by%20Arduino%204.7KR%20wiring.jpg)

 
## Manual of New GLDAB using Arduino Pro mini

Set the Throttle (3ch) to under 950 msec and over 1950 msec.

When using a new ESC, please set the ESC's operating range with New GLDAB removed before doing the following.

Setting of Pre Glide Motor Speed:
1. Disconnect ESC and battery
2. Throttle stick to max high position
3. Connect the ESC and battery -- The motor does not move, the LED turns on (lights up) once, then goes out.
After that, the LED turns on again.
4. Set the throttle to the lowest setting while the LED is ON--LED turns off and then turns ON (lights up) again.
5. While the LED is ON, set the throttle position to the speed at which you want the motor to move (Pre Glide Motor Speed: the speed at which the motor moves in 1 second after the throttle lever is set to the lowest position until the magnet is detected and the motor stops). 
6. When the motor stops (the set position is memorized) and the LED is flashing, lower the throttle to the lowest position.
7. When the LED stops blinking, it will return to normal mode.

How New GLDAb by Arduino works 

  1. ThrottleUp -- Motor Run
  2. Throttle max Low
  3. Red LED on and Motor Run on Setup speed
  4. After 1 second, Motor stops 

     The PreGlide time (the time the motor continues to run
     
      after the throttle stick is at its lowest position) is about 1 second.

    The PreGlide time can be changed by changing the i value.

    PreGlide time is approximately 1 second for Line88 "i<140" and Line103 "i=140".
    
    For longer PreGlide time increse i value ex. "i<200" and "i = 200".
      
  5. When Magnet passes magnet sensor,
                                 Red LED off and Motor stops
 When Magnet sensor contact magnet, 
           motor stops at max Low position of Throttle 

------If the above acts, GLDAB acts normally.





