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
    cout << "3 - --------- " << endl;
    cout << "4 - --------- " << endl;
    cout << "esc - Salir" << endl;
    char opcion;
    do
    {
       opcion=getch();
    } while ((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!=27));
    return opcion;
}

int main()
{
    cout << "Hello world!" << endl;
    char elegida;
    int n;
    char c[10]="";
    FILE *f;
    do {
    elegida = mostrarmenu();

    switch (elegida) {
    case '1':

        cout << "Ingrese la cantidad de valores a escribir:" << endl;
        cin >> n;

        int i;

        if (f = fopen("ejercicio1.txt","wb"))
        {
            for (i=0; i<n;i++)
            {
                cout << "Ingrese el valor " << i + 1 << ":" << endl;
                scanf("%79s",c);
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
        getch();

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
