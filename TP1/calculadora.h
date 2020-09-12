#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED



#endif // CALCULADORA_H_INCLUDED

/** \brief Suma dos enteros
 *
 * \param Operando1 a Sumar
 * \param Operando2 a Sumar
 * \return La suma de  operando1 y Operando2
 *
 */
int suma(int operando1, int operando2);

/** \brief  Resta dos enteros
*
* \param Operando1 a Sumar
* \param Operando2 a Sumar
* \return La resta de  operando1 y Operando2
*
*/
int resta(int operando1, int operando2);

/** \brief Divide dos enteros
 *
 * \param operando1 a dividir
 * \param operando2 a dividir
 * \param mensaje de Error si operando2 es igual a 0. Ingrese otro numero.
 * \return flotante resultado de la division entre operando1 y operando2.
 *
 */
float division(int operando1, int operando2);


/** \brief Calcula factorial de dos enteros.
 *
 * \param factorial de operando1
 * \param factorial operando2
 * \return factorial solo de numeros mayores e igual a 0.
 *
 */
long long int factorial(int operando1);



/** \brief Multiplica dos enteros
 *
 * \param oerando1 a multiplicar
 * \param operando2 a multiplicar
 * \return Multiplicacion de operando1 y operando2.
 *
 */
int multiplicacion(int operando1, int operando2);
