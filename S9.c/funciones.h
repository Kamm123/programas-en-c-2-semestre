/*Estado (cadena: "Disponible" o "Prestado").
•	Mostrar la lista completa de libros en formato tabla.
•	Buscar un libro por título o ID y mostrar toda su información.
•	Actualizar el estado de un libro (de "Disponible" a "Prestado" o viceversa).
•	Eliminar libro
Restricciones:
•	No se pueden agregar más de 10 libros.
•	El programa debe usar estructuras.
•	El código de producto debe ser único.
•	Validar entradas del usuario.
*/


typedef struct
{
    int id;
    char titulo [100];
    char autor [50];
    int anio;
    char estado[15];
}registrar;

int validarEntero(int a, int b);
void leerCadena (char *cadena, int n);
int menu();
void registro_libros(registrar *libros, int *numLibros);
void mostrar(registrar *libros, int *numLibros);
int buscarLibro (registrar *libros, int *numLibros);
void actualizar (registrar *libros, int *numLibros);
void eliminar (registrar *libros, int *numLibros);