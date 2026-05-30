int validarEntero(int a, int b);
float validarFlotante(float a, float b);
int menu();
int ingresarProducto(char nombres[3][25], float *precio, int *cantidad, int *recursos, int totalP);
void leerCadena (char *cadena, int n);
void mostrarInventario (char nombres[3][25], float *precio, int *cantidad, int *recursos, int totalP);
int buscaProducto (char buscado[25], char nombres[3][25], int totalP, float *precio, int *cantidad, int *recursos);
void editarProducto (char nombres[3][25], float *precio, int *cantidad, int *recursos, int totalP);
void eliminarProducto (char nombres[3][25], float *precio, int *cantidad, int *recursos, int *totalP);