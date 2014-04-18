// Display grayscale image from optical mouse sensor
// zapmaker.org
// Code idea from http://www.varesano.net/blog/fabio/serial-communication-arduino-and-processing-simple-examples-and-arduino-based-gamepad-int
import processing.serial.*;

Serial myPort;

int x = 275;
int y = 275;
int c = 0;

char in;

String buf;

void setup() 
{
  size(600, 600);
  myPort = new Serial(this, "COM10", 38400);
  myPort.clear();
}

void draw() {
  if (myPort.available() > 0) {
    buf = myPort.readStringUntil(10);
    if (buf != null) {
      String[] coords = splitTokens(trim(buf), ",");
      
      if (coords.length == 324) {
        int count = 0;
        for (int i = 0; i < 18; i++) {
          for (int j = 0; j < 18; j++) {
            fill(int(coords[count]) * 4);
            rect((i * 30) + 10, (j * 30) + 10, 30, 30);
            count++;    
          }
        }        
        
      }
      else {
        println("unexpected count=" + coords.length);
      }
      
    }
  }
}
/*
void draw() {
  if(myPort.available() > 0) {
    buf = myPort.readStringUntil(10);
    if (buf != null) {
      String[] coords = splitTokens(trim(buf), ",");
      if (coords.length == 2) {
        x = int(coords[0]) + 275;
        y = 275 - int(coords[1]);
        ellipse(x, y, 20, 20);
      }
    }
  }
}
*/
