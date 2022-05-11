//manda a llamar la clase.
#include "clases.h"
//se asigna la clase a una variable.
class_serial c_serial;
//se inicializa el programa el cual noo devuelve nada porque es un void.
void setup (void) {
    Serial.begin(115200); //se define la velocidad del puerto serial.
}
//es un ciclo el cual repetirá todo lo que tenga dentro.
void loop (void){
    if (Serial.available( )){//compara la cantidad de bytes para ver si recibe datos.
        c_serial.SerialEvent( ); //LLama la función de la clase la cual se encarga de revisar el puerto para ver si recibe información. 
    }
}
