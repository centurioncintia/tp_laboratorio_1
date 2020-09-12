#include <stdio.h>
#include <stdlib.h>

#include "calculadora.h"


int suma(int operando1,int operando2)
{

int resultadoSuma =  operando1 +  operando2;



return resultadoSuma;
}

int resta(int operando1, int operando2)
{

int resta = operando1 - operando2;

return resta;
}

float division(int operando1, int operando2)
{


float resultadoDivision;

resultadoDivision =((float)operando1 / operando2);


return resultadoDivision;
}


long long int factorial(int operando1)
{
 int fact= 0;
 if(operando1  >= 0)
 {
    if(operando1 ==1 || operando1 ==0  )
    {
      fact =1;
    }
    else
    {
      fact = operando1* factorial(operando1 -1);

     }
 }

return fact;
}
int multiplicacion(int operando1, int operando2)
{

int multiplicacion = operando1 * operando2;

return multiplicacion;
}
