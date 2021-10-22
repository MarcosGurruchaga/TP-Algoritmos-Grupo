#include <stdio.h>
#include <ctime>
#include <cstring>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

//***************************STRUCTS************************************
struct compra
{
	int id_compra;
	char fechactucom[17];
	float monto;
	int usid;
	int narticulo;
	int cantidad;
};

struct cliente
{
	int id_client;
	char fechcrea[9];
	bool estado;
	float totalcom;
	char mail[150];
};

//***************************FUNCIONES EXTRA************************************

void fechyho( char &fecha)
{
    char fec[17];
    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(fec,17,"%Y%m%d%H%M%S",timeinfo);
    strcpy(&fecha,fec);
    return ;
};


bool aceptar( )
{
    bool acep;
    char opcion;
    cout<< "Ingrese Y para aceptar o N para denegar"<<endl;
    cin>>opcion;
    if (opcion=='Y' || opcion== 'y')
    {
        acep=true;
    }else {acep=false;};
    return acep;
}

void menu (int prog)
{
    if (prog==0)
    {
        cout<<"GRACIAS POR UTILIZAR EL PROGRAMA"<<endl;
    }
    else
    {
        cout <<"Ingrese la opcion que desee efectuar:"<<endl;
        cout <<"1-Levantar clientes"<<endl;
        cout <<"2-Cargar un cliente"<<endl;
        cout <<"3-Desactivar un cliente un lote"<<endl;
        cout <<"4-Buscar cliente por ID o mail"<<endl;
        cout <<"5-Listar los clientes por importe"<<endl;
        cout <<"6-Procesar lote"<<endl;
        cout <<"7-Mostrar todas las compras de un cliente"<<endl;
        cout <<"8-Mostrar todas las compras de un cliente entre dos fechas (HTML)"<<endl;
        cout <<"9-Mostrar todas las compras de un cliente entre dos fechas (CSV)"<<endl;
        cout <<"10-Finalizar jornada y guardar datos"<<endl;
    }

};




//***************************PUNTO 1************************************
void levantarclientes()
{

    FILE* USERS;

    cliente variable;
    //levanto todos los usuarios
    if (USERS = fopen("USUARIOS.BIN","rb"))
    {

        fread(&variable,sizeof(cliente),1,USERS);

            while (!feof(USERS))
            {
                cout << "***************USUARIO******************" << endl;
                cout << "ID: " << variable.id_client  << endl;
                cout << "MAIL: " << variable.mail  << endl;
                cout << "IMPORTE: " << variable.totalcom  << endl;
                cout << "ESTADO: " << variable.estado  << endl;
                cout << "FECHA " << variable.fechcrea  << endl;
                fread(&variable,sizeof(cliente),1,USERS);
            }
        fclose(USERS);
    }


}

//***************************PUNTO 2************************************

void contacli(int &contador)
{   contador=1;
    FILE *USERS;
    USERS=fopen("USUARIOS.bin", "rb");
    if (USERS==NULL)
        exit(1);
    cliente cliloc;
    fread(&cliloc, sizeof(cliente), 1, USERS);
    while(!feof(USERS))
    {
        contador++;
        fread(&cliloc, sizeof(cliente), 1, USERS);
    }
    return ;
}

void cargarcli(int &b)
{
    FILE* USERS;
    char ff[9], dirmail[150];
    time_t rawtime=time(0);
    struct  tm timeinfo;
    timeinfo =*localtime(&rawtime);
    strftime(ff,80,"%Y-%m-%d",   &timeinfo);
    USERS = fopen("USUARIOS.bin", "ab+");
    fflush(stdin);
    //guardo un usuario en usuarios.bin
    cliente usuarios;
    usuarios.id_client=b;
    strcpy(usuarios.fechcrea,ff);
    cout << "Ingrese el importe del usuario" << endl;
    cin >> usuarios.totalcom;

    usuarios.estado=true;
    printf("Ingrese su mail: ");
    scanf ("%79s",dirmail);

    strcpy(usuarios.mail,dirmail);

    fwrite(&usuarios, sizeof(cliente), 1, USERS);
    fclose(USERS);

}


//***************************PUNTO 3************************************
void modificacion()
{
    FILE *f;
    f=fopen("USUARIOS.bin","rb+");
    if (f==NULL)
        exit(1);
    cout<<"Ingrese el mail del cliente a desactivar:   "<<endl;
    char mailloc[150];
    scanf ("%79s",mailloc);
    cliente clienteloc;
    int existe=0;
    fread(&clienteloc, sizeof(cliente), 1, f);
    while(!feof(f))
    {
        if (strcmp(clienteloc.mail,mailloc)==0)
        {
           bool condition;
           cout<< "Se procedera a desactivar al usuario: "<< clienteloc.mail<< " con un total de compra de "<< clienteloc.totalcom<< "$"<<endl;
           clienteloc.estado=false;
           int pos=ftell(f)-sizeof(cliente);
           fseek(f,pos,SEEK_SET);
           fwrite(&clienteloc, sizeof(cliente), 1, f);
           cout<< "Se ha desactivado el usuario"<<endl;
           existe=1;
           break;
        }
        fread(&clienteloc,  sizeof(cliente), 1, f);
    }
    if (existe==0)
        cout<<"No existe un usuario con dicho mail"<<endl ;
    fclose(f);
    return;
}

//***************************PUNTO 4************************************
void busCli()
{
    char busquedamail[150];
    FILE* USERS;
    bool encontrado=false;
    cliente variable;
    int busquedaid=0;

    if (USERS = fopen("USUARIOS.BIN","rb"))
    {
        cout<< "Cómo desea encontrar al usuario"<<endl;
        cout << "1: Por ID" <<endl;
        cout << "2: Por Mail" <<endl;
        int opcion=0;
        while (opcion!=1 && opcion != 2)
        {
        cin >> opcion;
        }
        switch (opcion) {
            case 1:
            cout<< "Ingrese la ID del usuario que desea encontrar"<<endl;
            cin >> busquedaid;
            break;
            case 2:
            cout<< "Ingrese el mail del usuario que desea encontrar"<<endl;
            scanf ("%79s",busquedamail);

            break;
        }

        fread(&variable,sizeof(cliente),1,USERS);

            while (!feof(USERS))
            {
                if (strcmp(variable.mail,busquedamail)==0 || variable.id_client == busquedaid)
                {
                cout << "**********USUARIO ENCONTRADO************" << endl;
                cout << "ID: " << variable.id_client  << endl;
                cout << "MAIL: " << variable.mail  << endl;
                cout << "IMPORTE: " << variable.totalcom  << endl;
                cout << "ESTADO: " << variable.estado  << endl;
                cout << "FECHA " << variable.fechcrea  << endl;
                encontrado=true;
                }

                fread(&variable,sizeof(cliente),1,USERS);
            }
        fclose(USERS);
    } else
    {
        cout << "No hay ningun usuario aún" << endl;
    }

    if (encontrado==false)
    {
        cout << "No se encontro el usuario" << endl;
    }
    return;

}



//***************************PUNTO 5************************************
void levantaryordenar()
{

    FILE* USERS;
    int count;
    contacli(count);
    count--;

	int id_clientaux=0;
	char fechcreaaux[9];
	bool estadoaux=false;
	float totalcomaux;
	char mailaux[150];


    cliente *p = new cliente[count];
    int j=0;

    //levanto los clientes en base a la cantidad que hay
    if (USERS = fopen("USUARIOS.bin","rb"))
    {
         fread(&p[0],sizeof(cliente),1,USERS);
            while (!feof(USERS))
            {
                j++;
                fread(&p[j],sizeof(cliente),1,USERS);
            }
        fclose(USERS);
    }
    //ordeno burbujamente
    for (int i=1; i<count; i++) {
        for (int j=0; j<count - 1; j++) {
            if (p[j].totalcom > p[j+1].totalcom) {
            totalcomaux = p[j].totalcom;
            p[j].totalcom = p[j+1].totalcom;
            p[j+1].totalcom = totalcomaux;

            id_clientaux = p[j].id_client;
            p[j].id_client = p[j+1].id_client;
            p[j+1].id_client = id_clientaux;

            estadoaux = p[j].estado;
            p[j].estado  = p[j+1].estado;
            p[j+1].estado  = estadoaux;
            /*
            strcpy(fechcreaaux,p[j].fechcrea);
            strcpy(p[j].fechcrea,p[j+1].fechcrea);
            strcpy(p[j+1].fechcrea,fechcreaaux);
            */
            strcpy(mailaux,p[j].mail);
            strcpy(p[j].mail,p[j+1].mail);
            strcpy(p[j+1].mail,mailaux);

         }
      }
   }

    //muestro por totalcom ordenado
    cout << "**********ORDENADOS POR IMPORTE*********" << endl;
    for (int i=0; i<count; i++) {
    cout << "***************USUARIO******************" << endl;
    cout << "ID: " << p[i].id_client  << endl;
    cout << "MAIL: " << p[i].mail  << endl;
    cout << "IMPORTE: " << p[i].totalcom  << endl;
    cout << "ESTADO: " << p[i].estado  << endl;
    cout << "FECHA " << p[i].fechcrea  << endl;
    }
}


// **************PUNTO 7 MOSTRAR LAS COMPRAS POR PANTALLA***************** //

void MostrarComprasCliente (){

    FILE *pasaje;
    compra e;
    cliente c;
    int id;

    if (pasaje=fopen("Procesados.bin","rb")){

        cout << "Ingrese el ID del cliente: ";  cin >> id;
        fread(&e,sizeof(compra),1,pasaje);
        while (!feof(pasaje)){

            if (c.id_client == id){

                cout << "COMPRA_ID: " << e.id_compra << endl;
                cout << "FECHA Y HORA: " << e.fechactucom << endl;
                cout << "MONTO: " << e.monto << endl;
                cout << "USUARIO_ID: " << e.usid << endl;
                cout << "NRO_ARTICULO: " << e.narticulo << endl;
                cout << "CANTIDAD: " << e.cantidad << endl;


            }
        }
        fclose(pasaje);
    }
    else{
        cout << "No existen compras" << endl;
    }
}

//PUNTO 7 (tiene que llegarle el vector con todas las compras)
void escribirReporteHTML(compra v[], int tam)
{

    FILE *f;
    char c1[17]="",c2[17]="";
    cout << "Indique una fecha con el formato DD/MM/AAAA" << endl;
    scanf ("%79s",c1);
    cout << "Indique otra fecha" << endl;
    scanf ("%79s",c2);

    f = fopen("Reporte de lotes en HTML.html", "wt");
    fprintf(f,"<html> \n");
    fprintf(f,"<style>\n");
    fprintf(f,"#clientes {font-family: Arial, Helvetica, sans-serif;border-collapse: collapse;width: 100%;}\n");
    fprintf(f,"#clientes tr:nth-child(even){ background-color: #f2f2f2;}\n");
    fprintf(f,"#clientes td, #clientes th { border: 1px solid #ddd; padding: 8px;}\n");
    fprintf(f,"#clientes tr:hover {background-color: #ddd;}\n");
    fprintf(f,"#clientes th {padding-top: 12px; padding-bottom: 12px; text-align: left; background-color: #04AA6D;color: white;}\n");
    fprintf(f,"</style>\n");
    fprintf(f,"<body> \n");

    fprintf(f,"<h1 style='font-family: Arial, Helvetica, sans-serif;'>Lotes entre el %s y el %s </h1>\n",c1,c2);
    fprintf(f,"<table id='clientes' >\n");
    fprintf(f,"<th>Cliente</th> <th>Fecha</th> <th>Nro de Articulo</th> <th>Monto</th> <th>N Articulo</th> <th>Cantidad</th>\n");
    int i= 0;

    while ((strlen(v[i].fechactucom) != 0))
    {
        if (strcmp(c1, v[i].fechactucom) <= 0 && strcmp(c2, v[i].fechactucom) >= 0) {
        fprintf(f,"<tr>\n");
        fprintf(f,"<td>%d</td><td>%s</td><td>%d</td><td>%d</td><td>%d</td><td>%d</td>\n",v[i].id_compra,v[i].fechactucom,v[i].monto,v[i].usid,v[i].narticulo,v[i].cantidad);
        fprintf(f,"</tr>\n");
        }
        i++;
    }
    fprintf(f, "</table>");
    fprintf(f, "</body>");
    fprintf(f, "</html>");
    fclose(f);
    return;
}

//PUNTO 8 (tiene que llegarle un vector con todas las compras)
void escribirReporteCSV(compra v[], int tam)
{

    FILE *f;
    f = fopen("Reporte de lotes en excel.csv", "wt");

    fprintf(f,"Cliente;Fecha;Nro de Articulo;Monto;N Articulo;Cantidad;\n");
    int i= 0;
    while (strlen(v[i].fechactucom) != 0)
    {
        fprintf(f,"%d;%s;%d;%d;%d;%d\n",v[i].id_compra,v[i].fechactucom,v[i].monto,v[i].usid,v[i].narticulo,v[i].cantidad);
        i++;
    }
    fclose(f);
    return;
}
//***************************MAIN************************************
int main ()
{
	int me=700, art=0, cantart=0, mont=0, totcom=0, montlot=0, cantlot=0, preart=0, montotxart=0, stop=1,comen=1, opcion,  a=0 ;
	char ffch[100];
	bool option=false;
	cliente aux;

    FILE *USERS;
    USERS = fopen("USUARIOS.bin", "ab");

    FILE *COMPRAS;
    USERS = fopen("COMPRAS.bin", "wb");
    cout<< "Ingrese 1 para comenzar y 0 para finalizar" << endl;
    cin>>comen;
    //system("cls"); ESTO SIRVE PARA LIMPIAR LA CONSOLA
    if (comen==1)
    {

         while (comen==1) {

            menu(comen);
            cin>>opcion;
            switch (opcion)
            {
                case 0:
                    comen=0;
                    break;
                case 1:
                    levantarclientes();
                    break;
                case 2:
                    int b;
                    contacli(b);
                    cargarcli(b);
                    break;
                case 3:
                    cout<<"Se procederaa modificar el estado de un usuario, esta seguro ?";
                    option=aceptar();
                    modificacion();
                    break;
                case 4:
                    busCli();
                    break;
                case 5:
                    levantaryordenar();
                    break;
            }
            cout << "Ingrese cualquier caracter para continuar" << endl;
            getch();
            //system("cls"); ESTO SIRVE PARA LIMPIAR LA CONSOLA
        }

    }
    return 0;
}
