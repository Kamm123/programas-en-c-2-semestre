#include <stdio.h>
#include <string.h>
#include "funciones.h"

int validarEntero(int a, int b){
    int aux;
    int n;
    do
    {
        aux= scanf("%d", &n);
        while(getchar() != '\n');
        if (aux != 1 || n < a || n > b)
        {
            printf("\nError, ingrese otra vez.");
            printf("\n>>> ");
        }
        
    } while (aux != 1 || n < a || n > b);
    return n;
}

float validarFlotante(float a, float b){
    int aux;
    float n;
    do
    {
        aux= scanf("%f", &n);
        while(getchar() != '\n');
        if (aux != 1 || n < a || n > b)
        {
            printf("\nError, ingrese otra vez.");
            printf("\n>>> ");
        }
        
    } while (aux != 1 || n < a || n > b);
    return n;
}

int menu(){
    int op;

    printf("\n**********GESTION DE PRODUCTOS***********");
    printf("\nIngrese una opcion.");
    printf("\n1. Ingresar Producto.");
    printf("\n2. Inventario.");
    printf("\n3. Buscar Producto.");
    printf("\n4. Editar Producto.");
    printf("\n5. Eliminar Producto.");
    printf("\n6. Salir");
    printf("\n>>> ");
    op = validarEntero(1, 6);
    return op;
}

int ingresarProducto(char nombres[3][25], float *precio, int *cantidad, int *recursos, int totalP){
    if (totalP >= 3)
    {
        printf("Error, ya ha ingresado el numero maximo de productos.\n");
        printf("Si desea ingresar otro producto debe eliminar un producto e ingresar uno nuevo.\n");
        return totalP;
    } else {
        printf("\nIngrese el nombre del producto %d: ", totalP+1);
        leerCadena(nombres[totalP], 25);
        printf("\nIngrese el precio del producto: ");
        precio[totalP] = validarFlotante(0, 100000);
        printf("\nIngrese la cantidad del producto: ");
        cantidad[totalP] = validarEntero(0, 10000);
        printf("\nIngrese la cantidad de recursos que necesita para hacer el producto: ");
        recursos[totalP] = validarEntero(0, 100000);
        return totalP + 1;
    }
}

void leerCadena (char *cadena, int n){
    int posicion;
    fgets(cadena, n, stdin);
    posicion = strlen(cadena) - 1;
    cadena[posicion] = '\0';
}

void mostrarInventario (char nombres[3][25], float *precio, int *cantidad, int *recursos, int totalP){
    printf("--------------------------------------------\n");
    printf("#\t\tProducto\t\tPrecio\t\tCantidad\t\tRecursos\n");
    for (int i = 0; i < totalP; i++)
    {
        printf("%d\t\t%s\t\t%.2f\t\t%d\t\t%d\n", i+1, nombres[i], precio[i], cantidad[i], recursos[i]);
    }
    
}

void editarProducto (char nombres[3][25], float *precio, int *cantidad, int *recursos, int totalP){
    int posicion, opc, opc2;
    printf("\nSeleccione el producto que desea editar: ");
    for (int i = 0; i < totalP; i++)
    {
        printf("\n%d %s", i + 1, nombres[i]);
    }
    printf("\n>>> ");
    opc = validarEntero(1, totalP);
    posicion = opc -1;

    printf("\nSeleccione lo que desea editar: ");
    printf("\n1. Nombre.");
    printf("\n2. Precio.");
    printf("\n3. Cantidad Disponible.");
    printf("\n4. Recursos Necesarios.");
    opc2 = validarEntero(1, 4);

    switch (opc2)
    {
    case 1:
        printf("\nIngrese el nuevo nombre del producto: ");
        printf("\n>>> ");
        leerCadena(nombres[posicion], 25);
        break;

    case 2:
        printf("\nIngrese el nuevo precio del producto: ");
        printf("\n>>> ");
        precio[posicion] = validarFlotante(0, 100000);
        break;

    case 3:
        printf("\nIngrese la nueva cantidad del producto: ");
        printf("\n>>> ");
        cantidad[posicion] = validarEntero(0, 100000);
        break;

    case 4:
        printf("\nIngrese los nuevos recursos del producto: ");
        printf("\n>>> ");
        recursos[posicion] = validarEntero(0, 100000);
        break;
    }
    printf("Se edito el producto correctamente.\n");
}

int buscaProducto (char buscado[25], char nombres[3][25], int totalP, float *precio, int *cantidad, int *recursos){
    printf("\nIngrese el nombre del producto que desea encontrar: ");
    leerCadena(buscado, 25);
    for (int i = 0; i < totalP; i++)
    {
        if (strcmp(buscado, nombres[i]) == 0)
        {
            printf("**********PRODUCTO ENCONTRADO***********\n");
            printf("#\t\tProducto\t\tPrecio\t\tCantidad\t\tRecursos\n");
            printf("%d\t\t%s\t\t%.2f\t\t%d\t\t%d\n", i+1, nombres[i], precio[i], cantidad[i], recursos[i]);
            return i;
        } 
    }
    printf("Producto NO encontrado.\n");
    return -1;
}

void eliminarProducto (char nombres[3][25], float *precio, int *cantidad, int *recursos, int *totalP){
    int opc, posicion;
    printf("\nSeleccione el numero del producto que desea eliminar:");
    for (int i = 0; i < *totalP; i++)
    {
        printf("\n%d %s", i + 1, nombres[i]);
    }
    printf("\n>>> ");
    opc = validarEntero(1, *totalP);
    posicion = opc -1;

    for (int i = posicion; i < *totalP -1; i++)
    {
        strcpy(nombres[i], nombres[i + 1]);

        precio[i] = precio[i + 1];
        cantidad[i] = cantidad[i + 1];
        recursos[i] = recursos[i + 1];
    }
    (*totalP)--;
    printf("Producto eliminado con exito.\n");
    
}