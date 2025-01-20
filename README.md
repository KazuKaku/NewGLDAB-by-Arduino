# New GLDAB by Arduino Pro mini : gliding device using Arduino


New GLDAB is a device that detects the position of the wing with a magnetic sensor and stops the wing movement at the optimal position for gliding.

When the throttle is set to the lowest position, the wing continues to move at a preset speed, and when it reaches the optimal position for gliding (detected by the magnetic sensor), the wing movement stops.

The wing moves slightly in the opposite direction due to wind pressure, and the ratchet gets caught on the bolt on the gear, fixing it in the gliding position and allowing it to glide.

In order to make the Ornithopter glide, I created a device (New GLDAB) that uses a magnetic sensor to stop the wings in the gliding position using an Arduino pro mini board.

Write CODE to Arduino pro mini.

How New GLDAB Works

http://kakutaclinic.life.coocan.jp/GLDAB.htm

New GLDAB by Arduino Pro mini (My website)

http://kakutaclinic.life.coocan.jp/GLDABArd.html


How New GLDAB by Arduino Pro mini works

YouTube Video https://www.youtube.com/watch?v=KpQxz6biprs



In order to make the Ornithopter glide, I created a device (New GLDAB) that uses a magnetic sensor to stop the wings in the gliding position using an Arduino pro mini board.
Write CODE to Arduino pro mini.


 

Need : 

Arduino pro mini board

4.7KOhms resistor

Panasonic Hall Sensor IC DN6852-A 


Wiring

 

 

Manual of New GLDAB using Arduino Pro mini

 

Set the Throttle (3ch) to under 1000 msec and over 2000 msec.
When using a new ESC, please set the ESC‘s operating range with New GLDAB removed before doing the following.

1. Disconnect ESC and battery
2. Throttle stick to max high position
3. Connect the ESC and battery → The motor does not move, the LED turns on (lights up) once, then goes out.
After that, the LED turns on again.
4. Set the throttle to the lowest setting while the LED is ON—LED turns off and then turns ON (lights up) again.
5. While the LED is ON, set the throttle position to the speed at which you want the motor to move (Pre Glide Motor Speed: the speed at which the motor moves in 1 second after the throttle lever is set to the lowest position until the magnet is detected and the motor stops). 
6. When the motor stops (the set position is memorized) and the LED is flashing, lower the throttle to the lowest position.
7. When the LED stops blinking, it will return to normal mode.



The magnet sensor is sensitive, so if you touch it with your hand, it will detect a magnetic field.
Also, when testing magnetic field detection, it does not work correctly on a wooden board. It reacts well when carried out on foamed polypropylene, etc.

 

 

How New GLDAb by Arduino works 

  1. ThrottleUp  Motor Run
  2. Throttle max Low
  Red LED on and Motor Run on Setup speed
   After 1 second, Motor stops 
 When Magnet passes magnet sensor,
                                 Red LED off and Motor stops
When Magnet sensor contact magnet, 
           motor stops at max Low position of Throttle 

------If the above acts, GLDAB acts normally.





