#define red_led 9
#define green_led 5
#define blue_led 10
#define yell_led 6

void setup() {
  // put your setup code here, to run once:
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(yell_led, OUTPUT);
  
  analogWrite(red_led, 0);
  analogWrite(green_led, 0);
  analogWrite(blue_led, 0);
  analogWrite(yell_led, 0);
  

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char led_spec = Serial.read();
    int led_brightness = Serial.parseInt();
    write_leds(led_spec, led_brightness);
  }
}

void write_leds(char led, int brightness){
  if(led == 'r'){
    analogWrite(red_led, brightness);
    return;
  }
  if(led == 'g'){
    analogWrite(green_led, brightness);
    return;
  }
  if(led == 'b'){
    analogWrite(blue_led, brightness);
    return;
  }
  if(led == 'y'){
    analogWrite(yell_led, brightness);
    return;
  }
}
