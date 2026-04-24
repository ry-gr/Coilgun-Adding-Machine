# Coilgun-Adding-Machine
THis is an adding machine, created with coilguns, capacitor banks, and disposable charging camera circuitry. It is completely over the top, but why not have fun with it?
This project was inspired by Matthias Wandel's adding machine, that was an incredible inspiration and resource. The gates are directly inspired by his own, just slightly scaled down.   
[Original Video](https://youtu.be/GcDshWmhF4A?si=AagFJ8iIVUzHyiSO)  
[Blog post detailing its creation](https://woodgears.ca/marbleadd/more.html)  




## Part List:
- 40TPS12A Thyristor  
- 2n2222a Transistor  
- 2x 450V 68uF Capacitors  
- Usb-C Pinout Board  
- LM2596 Buck Converter (5A)  
- Disposable Camera Flash Circuitry  
- 24AWG Magnet Wire  
- MUR1560G Diode  



## Operating Principle of the Electronics
The USB-C is connected to power, supplying 5v, which gets converted to 4.5V with the Buck Converter. This goes to the input of the camera flash circuitry, (technically the flash circuit only accepts 1.5v, but supplying it more makes it charge faster). From there it goes to the capacitors which are wired in parallel to make a 900V Capacitor. Boom, now after about 15seconds of charging we stop, and send a signal from the arduinos digital output. But uh-oh the arduino cant trigger the beefy 40TPS12A by itself, so that gets amplified big time to 200mA with the NPN transistor. Now the signal arrives at the gate, and the once open circuit closes. In an instant the current from the capacitors flows through the thyristor into the coilgun, where it rapidly creates a powerful electromagnetic field around the coil. This Field applies force to the steel .25inch ball sitting at the base of the coil, and the force overpowers gravity accelerating the ball to the coils core. Just as quickly the voltage source shuts off, the capacitors are now empty and the ball flies into the air with velocity. But wait, what about Faradays Principle? With the voltage cut, the coil wants very badly to continue the current it was once conducting so it send a massive voltage spike in the oppposite direction to try to get some more. But now the big boy diode, which is reverse biased awakes from its sleep and the massive voltage spike is consumed as mere heat by the didoe. Just that quickly we have consumed 380V. 

## Operating Principle of the Adding Machine
As explained in Mattias's Video, the machine originally holds 0. Each gate represents a number. Starting from the right, it goes from 2^0, then the gate to its left is 2^1. The one to the left of that is 2^2. This can go on forever. By using the definition of binary numbers, we can add numbers. 
For example: We put a marble into the empty machine on the furthest gate to the right. The rocker tilts and the marble is stuck. The internal value of the machine is now 2^0 = 1. We add a marble to the second gate, and it gets stuck there. By adding this we have added 2^1 = 2, to the internal value of the machine. So in total we have 2+1=3 in value. Now adding another marble to the furthest gate to the right, and whcih tilts the rocker discarding the stuck marble, and shooting the marble to the second gate, which does the same and shoots the marble to the third gate. Now our internal value is 2^2=4. We added 2+1+1, and the machine shows the final value.


> [!CAUTION]
> The Voltages needed to accelerate the projectile are dangerous and can potentially kill you. Not saying you shouldn't experiment, but please be very cautious. Have a good multimeter, and know how to use it.
