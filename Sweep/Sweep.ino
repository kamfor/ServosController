#include <Servo.h>

Servo h;
Servo v;  


int hpos = 0;
int vpos = 0; 

void setup() {
  h.attach(5);
  v.attach(6); 
  Serial.begin(9600);
  while (!Serial) {
  }
}

void loop() {

  while (Serial.available() > 0) {
    
    int nvpos = Serial.parseInt();
    
    int nhpos = Serial.parseInt();
    
    nvpos = map(nvpos,0, 90, 25, 100);

    nhpos = map(nhpos,0, 180, 10, 165);
  
    if (Serial.read() == '\n') {
      
      while((!(vpos==nvpos))||(!(hpos==nhpos))){
        
        if((nvpos>vpos)&&(vpos!=nvpos)){
          v.write(vpos);
          vpos++; 
        }
        if((nvpos<vpos)&&(vpos!=nvpos)){
          v.write(vpos);
          vpos--; 
        }
         if((nhpos>hpos)&&(hpos!=nhpos)){
          h.write(hpos);
          hpos++; 
        }
        if((nhpos<hpos)&&(hpos!=nhpos)){
          h.write(hpos);
          hpos--; 
        } 
        delay(20); 
      }
    }
  }
}

