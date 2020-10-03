#include <stdio.h>
#include <stdlib.h>
#include <Fecha.h>
#include <Archivos.h>
#define ERR_ARCH 1
#define OK 0

int cargarEmpleados (Empleado * pEmpleado, const char * nombreArchivo)  {

    int c;
    char decision = 'y';
    Fecha nacimiento;
    Fecha *nacFecha = &nacimiento;
    FILE *f = fopen(nombreArchivo, "wb");
    static int vectorDiasMes [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (!f)    {
        return ERR_ARCH;
    }

    puts ("\t\t\tIngresar empleado");

    while (decision == 'y') {
        do  {
            printf ("\nDNI: ", pEmpleado->dni);
            scanf("%d", &pEmpleado->dni);
        }   while (pEmpleado->dni < 0);

        while ( (c = getchar()) != '\n' && c != EOF );
        printf ("Nombre: ");
        fgets (pEmpleado->name, 30, stdin);

        printf("Ingresar fechad de nacimiento (DD/MM/YY): ");
        cargarFecha (nacFecha, vectorDiasMes);
        fflush(stdin);

        pEmpleado->nac.dia = nacFecha->dia;
        pEmpleado->nac.mes = nacFecha->mes;
        pEmpleado->nac.anio = nacFecha->anio;

        do  {
            printf ("Género (M/F): ");
            scanf ("%c", &pEmpleado->sexo);
            while ( (c = getchar()) != '\n' && c != EOF );
            pEmpleado->sexo = toupper(pEmpleado->sexo);
        }   while(pEmpleado->sexo != 'M' && pEmpleado->sexo != 'F');

        do  {
            printf ("Salario: ");
            scanf ("%f", &pEmpleado->salario);
        }   while (pEmpleado->salario < 0);

        //Forzar a limpiar lo que scanf dejó en el buffer.
        while ( (c = getchar()) != '\n' && c != EOF );

        fwrite (pEmpleado, sizeof (Empleado), 1, f);

        printf ("\nDesea ingresar otro empleado (Y/N): ");
        decision = tolower(getchar());
    }

    fclose(f);
    return OK;
}

int mostrarEmpleados (Empleado * pEmpleado, const char * nombreArchivo) {
    FILE *f = fopen(nombreArchivo, "rb");

    if (!f)    {
        return ERR_ARCH;
    }

    puts("DNI\t\tGénero\tSalario\tFecha nacimiento\t\tNombre");

    fread(pEmpleado, sizeof (Empleado), 1, f);
    while (!feof(f))   {
        printf("%08d \t %c \t %.2f \t %d/%d/%d \t %s", pEmpleado->dni, pEmpleado->sexo, pEmpleado->salario, pEmpleado->nac.dia, pEmpleado->nac.mes, pEmpleado->nac.anio, pEmpleado->name);
        fread(pEmpleado, sizeof (Empleado), 1, f);
    }

    fclose(f);

    return OK;
}

int actualizarSueldos (Empleado * pEmpleado, const char * nombreArchivo)    {

    FILE *f = fopen(nombreArchivo, "r+b");

    if (!f)    {
        return ERR_ARCH;
    }

    fread(pEmpleado, sizeof (Empleado), 1, f);
    while (!feof(f))    {
        printf("\n%sNuevo sueldo: ", pEmpleado->name);
        scanf("%f", &pEmpleado->salario);
        fseek(f, -sizeof(Empleado), SEEK_CUR);
        fwrite(pEmpleado, sizeof (Empleado), 1, f);
        fread(pEmpleado, sizeof (Empleado), 1, f);
    }

    fclose(f);

    return OK;
}
