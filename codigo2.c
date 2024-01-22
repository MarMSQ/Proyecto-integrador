#include <stdio.h>
#include <conio.h>
#include <time.h>

void intercambiar(int *a, int *b)
{
    int cont = *a;
    *a = *b;
    *b = cont;
}

int npr(num)
{
    int i;
    if (num < 2)
    {
        return 0;
    }
    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{

    int numero1, numero2, i, rep, cont;
    do
    {
        printf("Ingrese el primer numero: ");
        scanf("%i", &numero1);

        while (numero1 < 0 || numero1 > 1000)
        {
            printf("El numero ingresado es invalido, ingrese de nuevo \n");
            scanf("%i", &numero1);
        }
        printf("Ingrese el segundo numero: ");
        scanf("%i", &numero2);
        while (numero2 < 0 || numero2 > 1000)
        {
            printf("El numero ingresado es invalido, ingrese de nuevo \n");
            scanf("%i", &numero2);
        }

        if (numero1 > numero2)
        {
            intercambiar(&numero1, &numero2);
        }
        clock_t inicio = clock();

        printf("Los numeros primos gemelos entre %i y %i son:\n", numero1, numero2);

        for (i = numero1; i <= numero2 - 2; i++)
        {
            if (npr(i) && npr(i + 2))
            {

                printf("(%i, %i)\n", i, i + 2);
            }
        }
        clock_t fin = clock();
        double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
        printf("Tiempo de ejecucion: %f segundos\n", tiempo);

        cont = 0;
        printf("¿Quiere volver a repetir el programa?\n");
        printf("Si => 0 \n");
        printf("No => 1 \n");
        scanf("%i", &rep);
        if (rep == 1)
        {
            cont = 1;
        }
    } while (cont <= 0);

    printf("Muchas gracias por utilizar el programa");
    getch();
    return 0;
}