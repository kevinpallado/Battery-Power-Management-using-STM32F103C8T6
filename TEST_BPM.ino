#include <OneWireSTM.h>

OneWire  ds(PA4);  // on pin 10 (a 4.7K resistor is necessary) for temperature

int const ADCsample = 3;
int const ADCarraySize = 10;
float max_voltage = 14.0;
float firstCell_ADCreading[ADCarraySize];
float secondCell_ADCreading[ADCarraySize];
float thirdCell_ADCreading[ADCarraySize];
float fourthCell_ADCreading[ADCarraySize];

float ADCsum,c1,c2,c3,c4,c1f,c2f,c3f,c4f;
int ADCpins[]{
PA0,PA1,PA2,PA3
}; // list all analog pins here
int SwitchPins[]{
  
}; // list all switching pins here
byte i;
byte present = 0;
byte type_s;
byte data[12];
byte addr[8];
float celsius, fahrenheit;
int pinCount = 4; // numbers of pins used
void setup() {
  Serial.begin(9600);
  while(!Serial);
  for (int thisPin = 0; thisPin < pinCount; thisPin++){
    pinMode(ADCpins[thisPin],INPUT_ANALOG); //  set ADC pins as input
    pinMode(SwitchPins[thisPin],OUTPUT); // set switchpins as output
  }
}

void loop() {
    //float firstCell_ADCvalue = firstCell_movingAverageADC(analogRead(ADCpins[0]));
    //int adc_normal = analogRead(ADCpins[0]);
    //float ADC_value = ADC_movingAverage(analogRead(ADCpins[0]),1);
    for(int pinNumber = 0; pinNumber < pinCount; pinNumber++){
      float analog_reading = analogRead(ADCpins[pinNumber]);
      float ADC_value = ADC_movingAverage(analog_reading,pinNumber);
      float voltage =  voltage_reading(ADC_value,pinNumber);
      Serial.print("ADC Value : ");
      Serial.print(ADC_value);
      Serial.print(' ');
      Serial.print("Cell number :");
      Serial.print(pinNumber);
      Serial.print(' ');
      Serial.print("Voltage : ");
      Serial.print(voltage);
    }
    temperature(); // call the reading temperature class
}
float voltage_reading(float ADC_val, int cellNumber){
  if(cellNumber == 0){ // cell  1 , 12volts
    c1 = (0.0039*ADC_val)-0.0565;
    cell_switching(c1,cellNumber);
    return c1;
  }
  else if(cellNumber == 1){ // cell 2 , 24volts
    c2f = (0.0076*ADC_val)+0.7394;
    c2 = c2f - c1;
    cell_switching(c2,cellNumber);
    return c2;
  }
  else if(cellNumber == 2){ // cell 3 , 36 volts
    c3f = (0.0109*ADC_val)+1.5062;
    c3 = c3f - c2f;
    cell_switching(c3,cellNumber);
    return c3;
  }
  else if(cellNumber == 3){ // cell 4 , 48 volts
    c4f = (0.0156*ADC_val)+0.4066;
    c4 = c4f - c3f;
    cell_switching(c4,cellNumber);
    return c4;
  }
}
void cell_switching(float voltage_cell,int battery_number){
  if(voltage_cell > max_voltage){
    digitalWrite(SwitchPins[battery_number],HIGH);
  }
  else{
    digitalWrite(SwitchPins[battery_number],LOW);
  }
}

