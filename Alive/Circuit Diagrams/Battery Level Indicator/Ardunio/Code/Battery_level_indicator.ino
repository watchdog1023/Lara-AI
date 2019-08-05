int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // resistance of R1 (100K)
float R2 = 10000.0; // resistance of R2 (10K)
int value = 0;

// the pin that the potentiometer is attached to
const int analogPin = A0;   
// the number of LEDs in the bar graph
const int ledCount = 10;    
// an array of pin numbers to which LEDs are attached
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
//Var for button state
int buttonState = 0;
//Battery Voltage
int batvolt = 30;
int voltlim = 19 * batvolt;

void setup()
{  
  Serial.begin(9600);
  pinMode(12, INPUT);
  for(int thisLed = 0; thisLed < ledCount; thisLed++) 
    {
      pinMode(ledPins[thisLed], OUTPUT);
    }
}

void loop()
{
  buttonState = digitalRead(12);
  // check if pushbutton is pressed.  if it is, the
  // buttonState is HIGH
  if (buttonState == HIGH) 
    {
      // turn LED on
      digitalWrite(13, HIGH);
      build_graph();
      delay(5000);
      clear_graph();
    } 
  else 
    {
      // turn LED off
      clear_graph();
    }
  delay(500);
}

void clear_graph()
{
  for (int thisLed = 0; thisLed < 10; thisLed++) 
      {    
          digitalWrite(ledPins[thisLed], LOW);
      }
}

void build_graph()
{
   // read the value at analog input
   value = analogRead(analogInput);
   vout = (value * 5.0) / 1024.0; // see text
   vin = vout / (R2 /(R1 + R2)); 
   if(vin < 0.09) 
    {
      vin = 0.0;//statement to quash undesired reading!
    } 
  // read the Source:
  int sensorReading = analogRead(analogPin);
  // map the result to a range from 0 to the number of LEDs:
  int ledLevel = map(sensorReading, 0, /*1687*/voltlim, 0, ledCount);
  //Serial.println(sensorReading);
  // loop over the LED array:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) 
    {
      // if the array element's index is less than ledLevel,
      // turn the pin for this element on:
      if (thisLed < ledLevel) 
        {
            digitalWrite(ledPins[thisLed], HIGH);
        }
      // turn off all pins higher than the ledLevel:
      else 
        {
        	digitalWrite(ledPins[thisLed], LOW);
        }
    }
  delay(500);
}
