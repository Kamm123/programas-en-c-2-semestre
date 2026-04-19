#include <stdio.h>

int main (int argc, char *argv[]) {
    float calificaciones[5][3], prom[5]={0.0};
    char nombres[5][20];
    char asignatura[3][20]={"Matematica", "Fisica", "Biologia"};

    int op = 0, nombreA = 0, op2 = 0, aprobados = 0, reprobados = 0, posicionAsig = 0;
    float mayorCal, menorCal, mayorAsig, menorAsig;

    do{
        printf("\n                      SISTEMA DE CALIFICACIONES");
        printf("\nSeleccione una opcion.");
        printf("\n1. Ingresar los nombres y calificaciones por asignatura de los estudiantes.");
        printf("\n2. Promedio de calificaciones por estudiante.");
        printf("\n3. Promedio de calificaciones por asignatura.");
        printf("\n4. Calificacion mas alta y baja por estudiante. ");
        printf("\n5. Calificacion mas alta y baja por asignatura. ");
        printf("\n6. Numero de estudiantes aprobados por asignatura. ");
        printf("\n7. Numero de estudiantes reprobados por asignatura. ");
        printf("\n8. Salir. ");
        printf("\n>>> ");
        scanf("%d", &op);

        
        switch (op)
        {
        case 1: 
            for (int i = 0; i < 5; i++) {
                printf("\nINGRESE EL NOMBRE DEL ESTUDIANTE %d: ", nombreA+1);
                getchar();
                fgets(nombres[nombreA], 20, stdin);
                nombreA++; 

                for (int j = 0; j < 3; j++){
                    do{
                        printf("Ingrese la calificacion de %s en la asignatura de %s: \n", nombres[i], asignatura[j]);
                        scanf("%f", &calificaciones[i][j]);

                        if (calificaciones[i][j] > 10 || calificaciones[i][j] < 0){
                            printf("ERROR, LA NOTA DEBE SER ENTRE 0-10.\n");
                        }
                    }while (calificaciones[i][j] > 10 || calificaciones[i][j] < 0);
                    prom[i] += calificaciones[i][j];
                }
                prom[i] /= 3;
                if (prom[i] >= 6){
                    aprobados++;
                } else{
                    reprobados++;
                }

                do {
                    printf("Desea seguir ingresando los datos de otro estudiante? 1. SI, 2. No \n");
                    printf(">>> ");
                    scanf("%d", &op2);
                    if (op2 != 1 && op2 != 2 ){
                        printf("ERROR, el numero debe ser 1 o 2.\n");
                    }
                } while (op2 != 1 && op2 != 2);

                if (op2 == 2){
                    break;
                } 
            }
            break;

        case 2:
            printf("\n----------CALIFICACIONES POR ESTUDIANTES----------");
            printf("\nNombre\t\tPromedio");
            for (int i = 0; i < nombreA; i++) {
                printf("\n%s\t\t%.2f", nombres[i], prom[i]);
            }
            break;

        case 3:
            printf("\n----------CALIFICACIONES POR ASIGNATURA----------");
            printf("\nNombre\t\t%s\t\t%s\t\t%s", asignatura[0], asignatura[1], asignatura[2]);
            for (int i = 0; i < nombreA; i++) {
                printf("\n%s\t\t%.2f\t\t%.2f\t\t%.2f", nombres[i], calificaciones[i][0], calificaciones[i][1], calificaciones[i][2]);
            }
            break;

        case 4:
            for (int i = 0; i < nombreA; i++){
                mayorCal = 0;
                menorCal = 10;

                for (int j = 0; j < 3; j++){
                    if (calificaciones[i][j] > mayorCal){
                        mayorCal = calificaciones[i][j];
                    }

                    if (calificaciones[i][j] < menorCal){
                        menorCal = calificaciones[i][j];
                    }
                } 
                printf("\nNombre\t\tCalificacion mas alta\t\tCalificacion mas baja");
                printf("\n%s\t\t%f\t\t%f", nombres[i], mayorCal, menorCal);
            }
            break;

        case 5:
            printf("\n----------CALIFICACIONES MAS ALTAS POR ASIGNATURA----------");
            printf("\nNombre\t\tAsignatura\t\tNota");
            for (int i = 0; i < nombreA; i++){
                mayorAsig = calificaciones[i][0];

                for (int j = 0; j < 3; j++){
                    if (calificaciones[i][j] > mayorAsig){
                        mayorAsig = calificaciones[i][j];
                        posicionAsig = j;
                    }
                } 
                printf("\n%s\t\t%s\t\t%f", nombres[i], asignatura[posicionAsig], mayorAsig);
            }

            printf("\n----------CALIFICACIONES MAS BAJA POR ASIGNATURA----------");
            printf("\nNombre\t\tAsignatura\t\tNota");
            for (int i = 0; i < nombreA; i++){
                menorAsig = calificaciones[i][0];
                for (int j = 0; j < 3; j++){
                    if (calificaciones[i][j] < menorAsig){
                        menorAsig = calificaciones[i][j];
                        posicionAsig = j;
                    }
                } 
                printf("\n%s\t\t%s\t\t%f", nombres[i], asignatura[posicionAsig], menorAsig);
            }
            break;

        case 6:
            printf("\nEl numero de estudiantes que aprobaron fue de: %d", aprobados);
            break;

        case 7:
            printf("\nEl numero de estudiantes que NO aprobaron fue de: %d", reprobados);
            break;

        case 8:
            printf("GRACIAS POR USAR EL SISTEMA DE CALIFICACIONES.");
            printf("\nVUELVA PRONTO.");
            break;

        default:
            printf("OPCION NO ENCONTRADA, INTENTE OTRA VEZ.\n");
            break;
        }
    } while (op != 8);

    return 0;
}