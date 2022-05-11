//define cada valor entrante a forma hexadecimal. 
#define _uint8_t    0x01
#define _int8_t     0x02
#define _uint16_t   0x03
#define _int16_t    0x04
#define _uint32_t   0x05
#define _int32_t    0x06
#define _uint64_t   0x07
#define _int64_t    0x08

//Crea la calse con sus valores y funciones. 
class class_serial {
//Define las variables. 
  public:
    char byte_recibido;
    String trama_recibida;
    uint8_t x;
//Define las funciones.
  public:
    void SerialEvent (void);
    uint64_t get_max (uint8_t);
    uint64_t get_min (uint8_t);
    void get_data (uint8_t);
    void imprimisida(uint64_t n);
};


void class_serial :: get_data (uint8_t data){
  //compara el dato entrante y dependiendo de cada caso ingresa al correcto.
 
  switch (data){
    //En cada caso de las variables sin signo se realiza una función y las variables con un signo se realizan dos funciones que son rango máximo y rango mínimo. 
    case _uint8_t:
      Serial.print("El rango maximo es: ");
      Serial.println(get_max(8)-1);
      Serial.print("El rango minimo es: ");
      Serial.println("0");
    break;
    case _uint16_t:
      Serial.print("El rango maximo es: ");
      Serial.println(get_max(16)-1);
      Serial.print("El rango minimo es: ");
      Serial.println("0");
    break;
    case _uint32_t:
      Serial.print("El rango maximo es: ");
      Serial.println(get_max(32)-1);
      Serial.print("El rango minimo es: ");
      Serial.println("0");
    break;
    case _uint64_t:
      Serial.print("El rango maximo es: ");
      Serial.println(get_max(64));
      Serial.print("El rango minimo es: ");
      Serial.println("0");
    break;
    case _int8_t:
      Serial.print("El rango maximo es: ");
      Serial.println(get_max(7)-1);
      Serial.print("El rango minimo es: -");
      Serial.println(get_min(7));
    break;
    case _int16_t:
      Serial.print("El rango maximo es: ");
      Serial.println(get_max(15)-1);
      Serial.print("El rango minimo es: -");
      Serial.println(get_min(15));
    break;
    case _int32_t:
      Serial.print("El rango maximo es: ");
      Serial.println(get_max(31)-1);
      Serial.print("El rango minimo es: -");
      Serial.println(get_min(31));
    break;
    case _int64_t:
      Serial.print("El rango maximo es: ");
      Serial.println(get_max(63)-1);
      Serial.print("El rango minimo es: -");
      Serial.println(get_min(63));
    break;
  }
} 
      
//Compara la entrada con el valor del principio y retorna el resultado. 
uint64_t class_serial :: get_max ( uint8_t exponente ){
  return(uint64_t)pow ( 2,exponente );
}

uint64_t class_serial :: get_min ( uint8_t exponente ){
  return(uint64_t)pow ( 2,(exponente) );
}
//imprime los valores. 
void class_serial::imprimisida(uint64_t n){
  uint8_t temp;
  String result = "";
  while(n){
    temp = n % 10;
    result = String(temp) + result;
    n=(n-temp)/10;
  }
  Serial.print(result);
  Serial.println();
}


//Imprime el valor ingresado más un salto de línea.
void class_serial::SerialEvent (void){
  byte_recibido= (char)Serial.read();
  trama_recibida += byte_recibido;

  if(byte_recibido == '\n') {
   Serial.println("Se ha recibido la trama: "+trama_recibida);
   if (trama_recibida == "uint8_t\n"){
    get_data(_uint8_t);
   }else if (trama_recibida == "uint16_t\n")
    get_data(_uint16_t);
   else if (trama_recibida == "uint32_t\n")
    get_data( _uint32_t );
   else if (trama_recibida == "uint64_t\n")
    get_data( _uint64_t );
   else if (trama_recibida == "int8_t\n")
    get_data( _int8_t );
   else if (trama_recibida == "int16_t\n")
    get_data( _int16_t );
   else if (trama_recibida == "int32_t\n")
    get_data( _int32_t );
   else if (trama_recibida == "int64_t\n")
    get_data( _int64_t );

   trama_recibida = "";
  }
}
