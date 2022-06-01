# Práctica 4: ejercicio 2

## Materiales:
·ESP32
·1 LED
· 1 resistencia de 470ohms

## Presentación: 
En esta práctica observarmos como las dos tareas se sincronizan de manera que una apaga el led y la otra lo enciende.

## Explicación del código (con comentarios que explican el funcionamiento línea a línea) :
 
```
#include <Arduino.h>

const int led1 = 17; // Pin LED

void toggleLED2(void * parameter); //llamada de la tarea
void toggleLED(void * parameter); //llamada de la tarea

void setup(){
  Serial.begin(115200); //Establece la velocidad de datos en bits por segundo para la transmisión de datos
  pinMode(led1, OUTPUT); // pone el pin del LED como OUTPUT

xTaskCreate(
    toggleLED2,     // funcion que se tiene que llamar
    "Upload to AWS",    // Nombre de la tarea para poder debuggear
    1000,               // tamaño (bytes)
    NULL,               
    1,                  // prioridad de la tarea
    NULL     		//identificador de tareas
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
  for(;;){ // bucle infinito
  //enciende el LED
    digitalWrite(led1, HIGH);

    // pausa la tarea por 500ms
    vTaskDelay(500 / portTICK_PERIOD_MS);

    // apaga el LED
    digitalWrite(led1, LOW);

    //pausa la tarea otra vez por pinMode(led2, OUTPUT);500ms
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
  
    // al acabar mata la tarea
    vTaskDelete(NULL);
}


void toggleLED2(void * parameter){
  for(;;){ 
  // en este caso se empieza apagando el led
    digitalWrite(led1, LOW);

    vTaskDelay(500 / portTICK_PERIOD_MS);

    // enciende el LED
    digitalWrite(led1, HIGH);

    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
  
    vTaskDelete(NULL);
}

void loop(){

}

```

Las salidas se pueden ver con más claridad en el vídeo. 
