#include <stdio.h>

int main (int argc, char *argv[]) {
    float a[3][2];
    float prom[2]={0.0};
    
    for (int i = 0; i < 2; i++)
    {
        printf("Ingrese las calificaciones del alumno %d:\n",i+1);
        printf("Nota 1: ");
        scanf("%f",&a[0][i]);
        printf("Nota 2: ");
        scanf("%f",&a[1][i]);
        printf("Nota 3: ");
        scanf("%f",&a[2][i]);
    }


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            prom[j]+=a[i][j];
        }
    }
    prom[0]/=3;
    prom[1]/=3;
    printf("El promedio del alumno 1 es: %f\n",prom[0]);
    printf("El promedio del alumno 2 es: %f\n",prom[1]);

    return 0;
}