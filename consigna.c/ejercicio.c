#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    int op, totalP = 0;
    char nombres[3][25];
    float precio[3];
    int cantidad[3];
    int recursos[3];
    char buscado[25]; 

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            totalP = ingresarProducto(nombres, precio, cantidad, recursos, totalP);
            break;
        case 2:
            mostrarInventario(nombres, precio, cantidad, recursos, totalP);
            break;
        case 3:
            buscaProducto(buscado, nombres, totalP, precio, cantidad, recursos);
            break;
        case 4: 
            editarProducto(nombres, precio, cantidad, recursos, totalP);
            break;
        case 5: 
            eliminarProducto(nombres, precio, cantidad, recursos, &totalP);
            break;
        default:
            break;
        }
    } while (op != 6);
    
    return 0;
}