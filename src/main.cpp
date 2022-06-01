#include <Arduino.h>

const int led1 = 17; 
void toggleLED2(void * parameter);
void toggleLED(void * parameter); 

void setup(){
  Serial.begin(115200); 
  pinMode(led1, OUTPUT); 

xTaskCreate(
    toggleLED2,     
    "Upload to AWS",  
    1000,               
    NULL,               
    1,               
    NULL     		
);
    xTaskCreate(
    toggleLED,    
    "Toggle LED",   
    1000,            
    NULL,           
    1,               
    NULL         
  );
  


}


void toggleLED(void * parameter){
  for(;;){ 
  
    digitalWrite(led1, HIGH);


    vTaskDelay(500 / portTICK_PERIOD_MS);


    digitalWrite(led1, LOW);


    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
  
    
    vTaskDelete(NULL);
}


void toggleLED2(void * parameter){
  for(;;){ 
 
    digitalWrite(led1, LOW);

    vTaskDelay(500 / portTICK_PERIOD_MS);

    digitalWrite(led1, HIGH);

    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
  
    vTaskDelete(NULL);
}

void loop(){

}