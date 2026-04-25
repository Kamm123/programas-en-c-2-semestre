#include <stdio.h>

int main (int argc, char *argv[]) {
    char nombresP[5][30];
    float precioP [5];
    float cantidadP [5];

    int op = 0, op2 = 0, totalP, opStock, stock, opVenta, ventaC;
    float totalPrecio;

    do{
        printf("\n-----GESTION DE INVENTARIO-----");
        printf("\nSeleccione una opcion.");
        printf("\n1. Crear producto.");
        printf("\n2. Reabastecer stock.");
        printf("\n3. Vender producto.");
        printf("\n4. Mostrar inventario.");
        printf("\n5. Salir");
        printf("\n>>> ");
        scanf("%d", &op);

        switch (op){
        case 1:
            if (totalP >= 5){
                printf("\nYa alcanzaste el numero maximo de productos. ");
                break;
            }
            for (int i = 0; i < 5; i++)
            {
                printf("\nIngrese el nombre del producto %d que va a crear: ", totalP+1);
                getchar();
                fgets(nombresP[i], 30, stdin);
                totalP++;

                do{
                    printf("\nIngrese el precio del producto");
                    printf("\n>>> ");
                    scanf("%f", &precioP [i]);

                    if (precioP[i] < 0) {
                        printf("\nNo puede ingresar numeros negativos.");
                    }

                } while (precioP[i] < 0 );

                do{
                    printf("\nIngrese la cantidad del producto");
                    printf("\n>>> ");
                    scanf("%f", &cantidadP [i]);

                    if (cantidadP[i] < 0) {
                        printf("No puede ingresar numeros negativos.");
                    }

                } while (cantidadP[i] < 0);

                if (totalP == 5){
                    printf("\nYa has alcanzado el limite de productos.");
                    break;
                } else {
                    printf("\nDesea crear otro producto? 1. Si / 2. No ");
                    printf("\n>>> ");
                    scanf("%d", &op2);
                
                    if (op2 == 2) {
                        break;
                    }
                }
            }
            break;
        
        case 2:
            if (totalP == 0){
                printf("No hay ningun producto creado.\n");
                break;
            }

            printf("LISTA DE PRODUCTOS: ");
            printf("\nEscoga el numero del producto para reabastecer el stock: ");
            for (int i = 0; i < totalP; i++)
            {
                printf("\n%d. %s", i+1, nombresP[i]);
            }
            scanf("%d", &opStock);

            printf("\nIngrese la cantidad que desea reabastecer: ");
            printf("\n>>> ");
            scanf("%d", &stock);

            cantidadP[opStock-1] += stock;

            printf("\nReabastecimiento de stock, realizado correctamente.");
            printf("\nla cantidad de stock es de %.2f del producto %s.", cantidadP[opStock-1], nombresP[opStock-1]);
            break;

        case 3:
            printf("\nSeleccione el numero del producto que va a vender. ");
            for (int i = 0; i < totalP; i++)
            {
                printf("\n%d. %s", i+1, nombresP[i]);
            }
            printf("\n>>> ");
            scanf("%d", &opVenta);

            printf("\nIngrese cuantos productos va a vender. ");
            printf("\n>>> ");
            scanf("%d", &ventaC);

            totalPrecio = precioP[opVenta-1] * ventaC;
            printf("\nSu total a pagar del producto %s es de: %.2f", nombresP[opVenta-1], totalPrecio);

            cantidadP[opVenta-1] -= ventaC;
            printf("\nEl total del producto %s que queda disponible es de %.2f", nombresP[opVenta-1], cantidadP[opVenta-1]);
            break;

        case 4:
            printf("\n-----INVENTARIO-----");
            printf("\nProducto\t\tStock disponible");
            for (int i = 0; i < totalP; i++)
            {
                printf("\n%s\t\t%f", nombresP[i], cantidadP[i]);
            }
            break;

        case 5:
            printf("GRACIAS POR USAR EL SISTEMA.\n");
            break;

        default:
            printf("Opcion invalida, seleccione otra opcion.\n");
            break;
        }
    } while (op != 5);
    
    return 0;
}