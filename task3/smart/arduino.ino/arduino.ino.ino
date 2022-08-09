#include <Servo.h>




Servo shoulder;
Servo base;


double base_ang=90;
double shoulder_ang=90;



void setup() {
  // put your setup code here, to run once:
   base.write(base_ang);
  shoulder.write(shoulder_ang);
 

  Serial.begin(115200);
  Serial.setTimeout(10);

}
void changeangle(String movearm) {
 if (movearm == "right" || movearm== "رايت" || movearm == "Right") {
    base.write(base_ang -=20);
    }
    if (movearm == "left" || movearm == "Left" || movearm== "لفت") {
     base.write(base_ang += 20);
    }

    if (movearm == "top" || movearm== "توب" || movearm== "Top") {
     shoulder.write(shoulder_ang-=20);
    }

   if (movearm == "bottom"|| movearm == "بوتوم" || movearm == "Bottom") {
      shoulder.write(shoulder_ang+= 20);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
 String computerText = Serial.readStringUntil('@');
  computerText.trim();
  if (computerText.length() == 0) {
    return;

} 

 String command = getValue(computerText, ' ',0);
  changeangle(command );
  Serial.println(command);
  Serial.println("WORKING");
  delay(1000);

}
  /////////////
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
