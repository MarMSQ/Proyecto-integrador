/*Construye un algoritmo que, al recibir como datos dos números enteros positivos, obtenga e 
imprima todos los números primos gemelos comprendidos entre dichos números. Los primos 
gemelos son una pareja de números primos con una diferencia entre sí de exactamente dos. El 
3 y el 5 son primos gemelos.
Datos: N1, N2 (variables de tipo entero que representan los números enteros positivos que se 
ingresan).
El programa debe permitir repetir el proceso mientras el usuario desee*/

#include <stdio.h>
#include <conio.h>
#include <time.h>

void intercambiar(int *a, int *b)
{
    int cont = *a;
    *a = *b;
    *b = cont;
}

int main()
{
    int num1, num2, i, primo1, primo2, j;
    char repetir;

    do
    {


        printf("Ingrese el primer numero: ");
        scanf("%i", &num1);
        printf("Ingrese el segundo numero: ");
        scanf("%i", &num2);

        if (num1 > num2)
        {
            intercambiar(&num1, &num2);
        }

        while (num1 < 0 || num2 < 0)
        {
            printf("Los numeros deben ser positivos enteros. Ingrese nuevamente.\n");
            printf("Ingrese el primer numero: ");
            scanf("%i", &num1);
            printf("Ingrese el segundo numero: ");
            scanf("%i", &num2);
        }

        while (num1 > 1000 || num2 > 1000)
        {
            printf("El rango que selecciono es muy grande. Ingrese nuevamente.\n");
            printf("Ingrese el primer numero: ");
            scanf("%i", &num1);
            printf("Ingrese el segundo numero: ");
            scanf("%i", &num2);
        }
        clock_t inicio = clock();
        if (num2 > num1)
        {

            printf("Numeros primos gemelos entre %d y %d:\n", num1, num2);
            for (i = num1; i <= num2 - 2; i++)
            {
                primo1 = 1;
                primo2 = 1;
                for (j = 2; j * j <= i; j++)
                {
                    if (i % j == 0)
                    {
                        primo1 = 0;
                        break;
                    }
                }
                for (j = 2; j * j <= (i + 2); j++)
                {
                    if ((i + 2) % j == 0)
                    {
                        primo2 = 0;
                        break;
                    }
                }
                if (primo1 && primo2)
                {
                    printf("(%d, %d)\n", i, i + 2);
                }
            }
        }

        clock_t fin = clock();

        double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
        printf("Tiempo de ejecucion: %f segundos\n", tiempo);

        printf("Desea repetir el proceso? (s/n): ");
        scanf(" %c", &repetir);

    } while (repetir == 'S' || repetir == 's');

    getch();
    return 0;
}
