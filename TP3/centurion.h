


#ifndef CENTURION_H_INCLUDED
#define CENTURION_H_INCLUDED



#endif // CENTURION_H_INCLUDED

/** \brief Solicita un numero al usuario, luego de verificarlo devuelve un numero
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param Es el mensaje a ser mostrado
 * \param Es el mensaje de Error a ser mostrado
 * \param Es el maximo a ser aceptado
 * \param Es el minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);




/** \brief pide ingreso de una cadena de char, valida que no supere largo maximo, lo carga en otro vector
 *
 * \param mensaje es puntero a char.
 * \param mensajeError es puntero a char
 * \param max es int, cantidad maxima de caracteres +1 ('/0') para el vector.
 * \param auxiliar es vector de char, es el vector donde se cargara la cadena ya validada
 * \return devuelve 1 si cargo bien el puntero, 0 si no pudo
 *
 */
int get_String(char* mensaje, char* mensajeError, int maxString, char* auxiliar);


/** \brief Verifica si la cadena ingresada es numerica
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0(EXITO) si se obtiene un numero entero y -1(ERROR) si no
 *
 */
int getInt(int* pResultado);



/** \brief verifica si la cadena ingresada es numerica
 *
 * \param cadena de caracteres a ser analizada
 * \return Retorna 1(verdadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
int esNumerica(char* cadena);





/** \brief Lee de stdin hasta que encuentra un '\0' o hasta que haya copiado en cadena
 *         un Maximo de 'Longitud - 1' caracteres
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char* cadena, int longitud);



int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);



/** \brief funcion que valida S/N
 *
 * \param
 * \param
 * \return devuelve char mayuscula
 *
 */
int verifica();


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);
