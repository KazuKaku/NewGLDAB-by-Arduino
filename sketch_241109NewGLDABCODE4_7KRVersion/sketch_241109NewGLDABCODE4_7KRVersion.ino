//Arduino GLDAB by Arduino 4.7KR version
//copyright Kazuhiko Kakuta Start 26-04-2021　Last 09-11-2024
#include <Servo.h>
#include <EEPROM.h>

//#define DOPRINTS // if you print on PC screen Data, delete”//” 

volatile int pwm_value = 0;
volatile int prev_time = 0;
volatile int PreGMS = 1300;// PreGlideMotorSpeed =900 + pgms*3  
volatile int pgms = 0;// pgms = (PreGlideMotorSpeed -900) / 3
             // int a = 0; EEPROM.write(a, pgms); pgms = EEPROM.read(a);
volatile int motorstop = 900;
int val = 0;
int a = 0;
volatile int flag = 0; // do wright of pgms in EEPROM
volatile int flag2 = 0; // do PreGM
volatile int flag3 = 0; // after setting PreGM do not only first PreGM 
const int LED1 =13;// LED on Arduino board 
const int Hole =6; // Hole Senser Detect pin set on 6pin D6
Servo myservo1; // create (ESC) object to control (ESC)

void setup() {
Serial.begin(9600);
// when pin D2 goes high, call the rising function
attachInterrupt(0,rising,RISING);//ESC signal from RX
myservo1.attach(5); // attaches esc on pin 5 
pinMode(LED1, OUTPUT);// Blink LED
pinMode(Hole, INPUT);//pin6 Hole senser detect pin set input
pgms = EEPROM.read(a);
PreGMS =900 + pgms*3;  
delay(2000);//Avoid abnormal positions at startup-wait 2 second until RX starts231004
}

void loop() { 
//Serial.print("flag-");  
//Serial.println(flag);

if ((pwm_value > 1950) && (flag == 0)){ 

digitalWrite(LED1, HIGH);  //RedLED ON
myservo1.writeMicroseconds(motorstop); //Motor stop pre ESC setting
//Need ESC calibration before connect new GLDAB

delay(3000); //if LED on, then set throttle stick down max low within 2second   
digitalWrite(LED1, LOW); //  LED Off                  
if (pwm_value < 1040){  
delay(2000);//Wait 2sec 
digitalWrite(LED1, HIGH);//  while LED ON set stick at PreGlideMotorSpeed 

for (int s = 0 ; s < 1500 ; s++ ){
myservo1.writeMicroseconds(pwm_value); 
PreGMS = pwm_value; //after 4sec set motor speed now to PreGlideMotorSpeed
pgms = (PreGMS - 900) / 3; 
EEPROM.write(a, pgms);// memory pgmr in EEPROM  

//Serial.print("setPreGMS-");
//Serial.println(PreGMS);    
//Serial.print("s-");
//Serial.println(s);
}
digitalWrite(LED1, LOW);    // turn the LED off and motor stop
delay(1000);
for(int k = 0 ; k < 4  ; k++){  
myservo1.writeMicroseconds(motorstop);//Stop motor
//Serial.print("k-");
//Serial.println(k);
digitalWrite(LED1, HIGH);//End of setting of PreGlideMotorSpeed
delay(500);
digitalWrite(LED1, LOW); 
delay(500);
}    

flag = 1 ;
}
}else
{
flag = 1;

myservo1.writeMicroseconds(pwm_value); // motor move by now throttle

//Serial.print("-");
//Serial.println(pwm_value);
if ( flag3 == 0){goto label;}
if (( pwm_value < 950 ) && (flag2 == 0 )){ 
digitalWrite(LED1, HIGH);
pgms = EEPROM.read(a);
PreGMS =900 + pgms*3;    
for(int i = 0 ; i <140 ; i++) {  //100=?second
myservo1.writeMicroseconds(PreGMS);//The motor runs at PreGMS speed for about 1 second.
//Serial.print("PreGMS--");
//Serial.println(PreGMS);
//Serial.print("i-");
//Serial.println(i);
val = digitalRead(Hole); //read pin6D6 magnet holesenser 

Serial.print("val-");// Not delete “Serial.print("val-")” and “Serial.println(val);”
Serial.println(val);// By repeating with these two lines 140 times, 
                //this system has a magnet detection time of about 1 second.
                // When a magnet is detected, Val=1 and the motor stops.


//if ( val == 1){ i = 140;}
if ( val == 0){ i = 140;}// When a magnet is detected, Val=0 and the motor stops



}
digitalWrite(LED1, LOW); 
label://remove;
flag2=1;
flag3=1;


}

if ( pwm_value > 951 ){flag2 = 0;}
}
}//loop

// Intake pwm_value at Now
void rising(){
attachInterrupt(0,falling,FALLING);
prev_time = micros();
}
void falling() {
attachInterrupt(0,rising,RISING);
pwm_value = micros()-prev_time;
}
