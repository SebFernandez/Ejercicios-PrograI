#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Fecha.h>
#include <Archivos.h>
#define ERR_ARCH 1
#define OK 0

int main (int argc, char * argv []) {

    if (argc != 2)  {
        puts ("Demasiados parametros\n");
        return ERR_ARCH;
    }

    Empleado empleado;
    Empleado *pEmpleado = &empleado;

    if (!cargarEmpleados (pEmpleado, argv [1]))   {
        puts("\nEmpleados cargados con éxito!\n");
    }   else    {
        puts ("Ocurrió un error en el archivo.\n");
        return ERR_ARCH;
    }

    if (!mostrarEmpleados (pEmpleado, argv [1]))    {
        puts ("\nEmpleados cargados en el sistema hasta el momento.");
    }   else    {
        puts ("Ocurrió un error en el archivo.\n");
        return ERR_ARCH;
    }

    if (!actualizarSueldos(pEmpleado, argv [1]))    {
        puts ("\nSueldos actualizados");
    }   else    {
        puts ("Ocurrió un error en el archivo.\n");
        return ERR_ARCH;
    }

    if (!mostrarEmpleados (pEmpleado, argv [1]))    {
        puts ("\nSueldos al día de hoy.");
    }   else    {
        puts ("Ocurrió un error en el archivo.\n");
        return ERR_ARCH;
    }

    printf("\nGoodbye world!\n");
    return OK;
}
