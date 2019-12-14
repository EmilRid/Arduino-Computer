#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
int cursorX = 3, cursorY = 1;
String button;
int input[4] = {0,0,0,0};

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.cursor();
}

void loop() {
  lcd.setCursor(0,1);
  for(int i=0;i!=4;i++){
    lcd.print(input[i]);
  }
  readInput();
  lcd.setCursor(cursorX, cursorY);
  
  if (button == "u"){
    input[cursorX] = 1;
    cursorX--;
    button = "";
  }
  if (button == "d"){
    input[cursorX] = 0;
    button = "";
    cursorX--;
  }
  if (button == "r"){
    cursorX++;
  button = "";
  }
  if (button == "l"){
    cursorX--;
  button = "";
  }
  delay(150);
  if (button == "s"){
    if (input[3] == 1 and input[2] == 0 and input[1] == 1 and input[0] == 0){
      test();
    }
  }
}

void readInput(){
  int x = analogRead(0);
  if(x < 90) { //this is Right button
    button = "r";
  }else if (x < 200) { //this is up button
    button = "u";
  }else if (x < 400){ //this is down button
    button = "d";
  }else if (x < 600){ //this is left button
    button = "l";
  }else if (x < 800){ //this is select button
    button = "s";
  }
}

void test(){
  for(int o;o!=-1;o++){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(o);
    delay(75);
    }
}

