// zapmaker optical mouse sensor program
// http://zapmaker.org
// Based on tutorial: http://www.martijnthe.nl/optimouse/
// Based on the sketches by Beno�t Rousseau
// Free license to use/copy/modify

//#include "PAN3101.h"
// #include "ADNS2051.h"
// #include "ADNS2610.h"
#include "ADNS2620.h"
// #include "ADNS2083.h"

#define SCLK 2                            // Serial clock pin on the Arduino
#define SDIO 3                            // Serial data (I/O) pin on the Arduino

//PAN3101 Optical1 = PAN3101(SCLK, SDIO);   // Create an instance of the PAN3101 object
// ADNS2051 Optical1 = ADNS2051(SCLK, SDIO);
// ADNS2610 Optical1 = ADNS2610(SCLK, SDIO);
ADNS2620 Optical1 = ADNS2620(SCLK, SDIO);
// ADNS2083 Optical1 = ADNS2083(SCLK, SDIO);

signed long x = 0;                        // Variables for our 'cursor'
signed long y = 0;                        //
signed char squal = 0;
signed char shup = 0;
signed char shdown = 0;
signed char frame = 0;


int c = 0;                                // Counter variable for coordinate reporting
signed long lastx = 0;
signed long lasty = 0;

void setup()
{
  Serial.begin(38400);
  Optical1.begin();                       // Resync (not really necessary?)
}

void loop()
{

//  The status commands are available only for the PAN3101 and the ADNS2051:

//  Optical1.updateStatus();                // Get the latest motion status
//  if (Optical1.motion())                  // If the 'Motion' status bit is set,
//  {

    x += Optical1.dx();                   // Read the dX register and in/decrease X with that value
    y += Optical1.dy();                   // Same thing for dY register.....
    squal = Optical1.squal();
    shup = Optical1.shUp();
    shdown = Optical1.shDown();
    frame = Optical1.framePer();
    
//  }
  
  if (c++ & 0x10)
  { 
/*    // Report the coordinates once in a while...
    Serial.print("x=");
    Serial.print(x, DEC);
    Serial.print(" y=");
    Serial.print(y, DEC);
    Serial.print(" sq=");
    Serial.print(squal, DEC);
    Serial.print(" su=");
    Serial.print(shup, DEC);
    Serial.print(" sd=");
    Serial.print(shdown, DEC);
    Serial.print(" fr=");
    Serial.print(frame, DEC);
    Serial.println();*/

    if (lastx != x || lasty != y) {    
      Serial.print(x, DEC);
      Serial.print(",");
      Serial.print(y, DEC);
      Serial.println();
      lastx = x;
      lasty = y;
    }
    
    c = 0;                                // Reset the report counter
  }
}

