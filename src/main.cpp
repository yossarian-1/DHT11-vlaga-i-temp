#include <Arduino.h>
#include<string.h>
#include <dht.h>
#include<LiquidCrystal.h>
LiquidCrystal DISP(12,11,5,4,3,2);
#define DHT11_PIN 7
#define DHTTYPE DHT11
DHT dht(DHT11_PIN, DHTTYPE);


int i; // brojac


/*void display_func(){
for(i=0;i<3;i++){

  
  DISP.clear();
  DISP.setCursor(0,0);
  DISP.print(variable_names[i]);
  DISP.setCursor(0,1);
  DISP.print(variable_values[i]);
  DISP.clear();
  delay(500); 
  
}
i=0;
}*/

void setup(){

  Serial.begin(9600);
  Serial.println(F("DHTxx test"));
  delay(1200);
  dht.begin();                //DHT.begin();
  DISP.begin(16,2);
  DISP.clear();
  
 
  }


void loop(){
static float h; //vlaznost
static float t ;  //temperatura
static float hindx; //osetna temperat
 
float variable_values[3]{h,t,hindx};// Inicirati varijable null
char * variable_names[]{"humidity","temperature", "Heat index"}; /*Koji tip stringa?, mora local scope
 */

h = dht.readHumidity();
delay(2000);
t= dht.readTemperature();
delay(2000);
if (isnan(h)||isnan(t)){Serial.println(F("Failed to read from DHT11"));
   return;}
hindx = dht.computeHeatIndex(t,h,false);

char stringbuffer_values[20];// vrednost buffer-a                  
dtostrf(variable_values[i],6,3,stringbuffer_values);// Koliki treba buffer da mi bude?
 for(i=0;i<3;i++){
Serial.println(variable_names[i]);
Serial.println(variable_values[i]);
Serial.println(i);
}
i=0; 
 
 
  
 delay(500);

}
 
  
 




