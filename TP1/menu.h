#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED



#endif // MENU_H_INCLUDED

/** \brief Muestra menu de ociones al usuario,
 *
 * \param Ingreso de numero
 * \param Ingreso de otro numero
 * \param opcion 3 resuelve Suma, resta, division, factorial, multiplicacion
 * \param opcion 4 Muestra resultado de las operaciones
 * \param error al ingresar opcion incorrecta.
 * \param El usuario debe ingresar todas las opciones  para imprimir resultados.
 * \return Resultado de las operaciones.
 *
 */

int mostrarMenu();



void mostrarCalculos(int numero1, int numero2);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
