# Practice 4-B: LED Task Synchronization on ESP32 (English Version)
## Materials
- ESP32
- 1 LED
- 1 resistor (470Ω)

## Introduction

In this practice for the Digital Processors course, we observe how two tasks can be synchronized so that one turns the LED off while the other turns it on.

## Code Explanation (with line-by-line comments)
```cpp
#include <Arduino.h>

const int led1 = 17; // LED pin

void toggleLED2(void * parameter); // Task declaration
void toggleLED(void * parameter);  // Task declaration

void setup(){
  Serial.begin(115200); // Set baud rate for serial communication
  pinMode(led1, OUTPUT); // Set LED pin as OUTPUT

  // Task 1: toggles LED starting OFF
  xTaskCreate(
    toggleLED2,           // Function to call
    "Toggle LED 2",       // Task name for debugging
    1000,                 // Stack size (bytes)
    NULL,                 
    1,                    // Task priority
    NULL                  // Task handle
  );

  // Task 2: toggles LED starting ON
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
  for(;;){ // Infinite loop
    digitalWrite(led1, HIGH);  // Turn LED ON
    vTaskDelay(500 / portTICK_PERIOD_MS); // Wait 500ms

    digitalWrite(led1, LOW);   // Turn LED OFF
    vTaskDelay(500 / portTICK_PERIOD_MS); // Wait 500ms
  }
  vTaskDelete(NULL); // Delete task when finished
}

void toggleLED2(void * parameter){
  for(;;){ // Infinite loop
    digitalWrite(led1, LOW);   // Start by turning LED OFF
    vTaskDelay(500 / portTICK_PERIOD_MS); // Wait 500ms

    digitalWrite(led1, HIGH);  // Turn LED ON
    vTaskDelay(500 / portTICK_PERIOD_MS); // Wait 500ms
  }
  vTaskDelete(NULL); // Delete task when finished
}

void loop(){
  // Empty loop, tasks handle LED
}
```

### How to Run

1. **Install PlatformIO**
   - Install [VS Code](https://code.visualstudio.com/)
   - Install the [PlatformIO extension](https://platformio.org/install/ide?install=vscode)

2. **Create a New Project**
   - Open PlatformIO in VS Code
   - Create a new project and select your board (**ESP32 Dev Module**)
   - Choose **Arduino framework**

3. **Add the Code**
   - Replace the contents of `src/main.cpp` with the code provided

4. **Connect the Hardware**
   - Connect **LED** to GPIO 17 with a **470Ω resistor** in series
   - Connect the ESP32 board to your computer via USB

5. **Build and Upload**
   - Click **Build (✓)** to compile the code
   - Click **Upload (→)** to flash the ESP32

6. **Observe the Result**
   - The LED will blink as the two tasks alternate: one turning it on, the other turning it off


### Resources
- **Video Demonstration in Spanish:** [Watch video](assets/practica4ej2.mp4)  
- **Arduino FreeRTOS Reference:** [Arduino FreeRTOS](https://www.freertos.org/FreeRTOS-quick-start-guide.html)  
- **LED Basics and Circuit Guide:** [Arduino LED Tutorial](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink)


# Práctica 4-B: Sincronización de Tareas con LED en ESP32 (Versión en Español)

## Materiales
- ESP32
- 1 LED
- 1 resistencia (470Ω)

## Introducción
En esta práctica del curso de Procesadores Digitales, observamos cómo dos tareas pueden sincronizarse de manera que una apaga el LED mientras la otra lo enciende.

## Explicación del código (con comentarios línea por línea):
 
```cpp
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
  // Bucle vacío, las tareas se encargan del LED
}

```

### Cómo Ejecutar

1. **Instalar PlatformIO**
   - Instala [VS Code](https://code.visualstudio.com/)
   - Instala la [extensión PlatformIO](https://platformio.org/install/ide?install=vscode)

2. **Crear un Nuevo Proyecto**
   - Abre PlatformIO en VS Code
   - Crea un nuevo proyecto y selecciona tu placa (**ESP32 Dev Module**)
   - Elige **framework Arduino**

3. **Agregar el Código**
   - Reemplaza el contenido de `src/main.cpp` con el código proporcionado

4. **Conectar el Hardware**
   - Conecta el **LED** al GPIO 17 con una **resistencia de 470Ω** en serie
   - Conecta la placa ESP32 a tu computadora mediante USB

5. **Compilar y Subir**
   - Haz clic en **Build (✓)** para compilar
   - Haz clic en **Upload (→)** para cargar la ESP32

6. **Observar el Resultado**
   - El LED parpadeará a medida que las dos tareas se alternan: una lo enciende y la otra lo apaga


### Recursos
- **Video demostrativo en español:** [Ver video](assets/practica4ej2.mp4)  
- **Referencia de Arduino FreeRTOS:** [Arduino FreeRTOS](https://www.freertos.org/FreeRTOS-quick-start-guide.html)  
- **Guía de LEDs y Circuitos:** [Tutorial Arduino LED](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink)

