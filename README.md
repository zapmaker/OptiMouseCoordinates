Optical mouse sensor interface program using Arduino. Sends data via serial
to program that displays output.

See zapmaker's modified OptiMouse library in the github zapmaker repo in order to use
this Arduino sketch.

This is experimental but it works with an older Microsoft Mouse.

I've cut the USB connector off and replaced with headers to plug into Arduino
shield connector, rewired the USB inside the mouse so I can talk to the 2620 sensor 
directly. I tried to modify the PCB as little as possible. It looks like a normal
mouse except that it connects direct to my Arduino 5v, gnd, and pins 2 and 3.

Currently this code reads the pixel data from the sensor. In the subfolder OptiMouseViewer
is a Processing program that displays the grayscale image data in 18x18 pixels.
See https://www.processing.org