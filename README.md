# Coilgun-Adding-Machine
It is an adding machine, created with coilguns, capacitor banks, and disposable charging camera circuitry. It is completely over the top, but why not have fun with it?


## Part List:
-40TPS12A Thyristor  
-2n2222a Transistor  
-2x 450V 68uF Capacitors  
-Usb-C Pinout Board  
-LM2596 Buck Converter (5A)  
-Disposable Camera Flash Circuitry  
-24AWG Magnet Wire  
-MUR1560G Diode  


## Operating Principle
The USB-C is connected to power, supplying 5v, which gets converted to 4.5V with the Buck Converter. This goes to the input of the camera flash circuitry, (technically the flash circuit only accepts 1.5v, but supplying it more makes it charge faster). From there it goes to the capacitors which are wired in parallel to make a 900V Capacitor. Boom, now after about 15seconds of charging we stop, and send a signal from the arduinos digital output. But uh-oh the arduino cant trigger the beefy 40TPS12A by itself, so that gets amplified big time to 200mA with the NPN transistor. Now the signal arrives at the gate, and the once open circuit closes. In an instant the current from the capacitors flows through the thyristor into the coilgun, where it rapidly creates a powerful electromagnetic field around the coil. This Field applies force to the steel .25inch ball sitting at the base of the coil, and the force overpowers gravity accelerating the ball to the coils core. Just as quickly the voltage source shuts off, the capacitors are now empty and the ball flies into the air with velocity. But wait, what about Faradays Principle? With the voltage cut, the coil wants very badly to continue the current it was once conducting so it send a massive voltage spike in the oppposite direction to try to get some more. But now the big boy diode, which is reverse biased awakes from its sleep and the massive voltage spike is consumed as mere heat by the didoe. Just that quickly we have consumed 380V. 

