#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char mostrarmenu()
{

    cout << "Ingrese una opcion: " << endl;
    cout << "1 - Ingresar un nuevo registro" << endl;
    cout << "2 - Mostrar registros actuales" << endl;
    cout << "3 - Terminar el dia " << endl;
    cout << "4 - --------- " << endl;
    cout << "esc - Salir" << endl;

    /*
    cout << "1 - Introducir nuevo cliente " << endl;
    cout << "2 - Desactivacion de un cliente " << endl;
    cout << "3 - Busqueda de un cliente " << endl;
    cout << "4 - Mostrar totalidad de clientes por total de importe ordenadamente " << endl;
    cout << "5 - Procesamiento de un lote de compras " << endl;
    cout << "6 - Compras realizadas de un cliente " << endl;
    cout << "Esc - Finalizar jornada " << endl;
    */

    char opcion;

    do
    {
        opcion=getch();
    } while ((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!=27));

    system("cls");
    return opcion;
}

int main()
{
    char elegida;
    int n;
    char c[10]="";
    FILE *f;

    do {
        elegida = mostrarmenu();

        switch (elegida)
        {
            case '1':
                cout << "Ingrese la cantidad de valores a escribir:" << endl;
                cin >> n;

                int i;

                if (f = fopen("ejercicio1.txt","ab"))
                {
                    for (i=0; i<n;i++)
                    {
                        cout << "Ingrese el valor " << i + 1 << ":" << endl;
                        cin >> c;
                        fwrite(&c,8,1,f);
                    }
                    fclose(f);
                }

                cout << "Muestra los valores" << endl;
                if (f = fopen("ejercicio1.txt","rb"))
                {
                    fseek(f,0,SEEK_SET);

                    while (fread(&c,8,1,f))
                    {
                        cout << "Leyo: " << c << endl;
                    }
                    fclose(f);
                }
                break;

            case '2':
                cout << "elegiste la segunda opcion" << endl;
                break;

            case '3':
                cout << "elegiste la segunda opcion" << endl;
                break;

            case '4':
                cout << "elegiste la segunda opcion" << endl;
                break;

        }

    getch();
    system("cls");

    } while (elegida!=27);

    return 0;
}
