#include <stdio.h>
#include <ctime>
#include <cstring>
#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

//***************************STRUCTS************************************
struct compra
{
	int id_compra;
	char fechactucom[17] = {'2', '0', '2', 'f', '/','f','f','/','f','f',' ','f','f',':','f','f','\n'};
	float monto;
	int usid;
	int narticulo;
	int cantidad;
};

struct cliente
{
	int id_client;
	char fechcrea[11];
	bool estado;
	float totalcom;
	char mail[30];
};

enum OPCIONES_MENU{

    LevantarUsers = 1,
    CargarUser = 2,
};

//***************************  PROTOTIPOS  ************************************

void fechyho(char &);
bool AceptarODenegar(void);
void MostrarMenu (int);
void LevantarClientes();
void ContarClientes(int &);
void CargarCliente(int &);
void DesactivarCliente(void);
void BuscarYMostrarCliente(void);
void ListarClientes(void);
void EscribirReporteHTML(compra [], int );
void EscribirReporteCSV(compra [], int );
void procesar_lote(bool);
void CompraRand(cliente,compra&,float&);
void MostrarComprasDeUsuario(int);
void cargarCiente(void);

///***************************  MAIN  ************************************

int main ()
{
	int me=700, art=0, cantart=0, mont=0, totcom=0, montlot=0, cantlot=0;
	int preart=0, montotxart=0, stop=1,comen=1, opcion,  a=0 ;
	char ffch[100];
	bool option=false;
	cliente aux;

    /*FILE *USERS;
    USERS = fopen("USUARIOS.bin", "ab");

    FILE *COMPRAS;
    USERS = fopen("COMPRAS.bin", "wb");*/


    //cout<< "Ingrese 1 para comenzar y 0 para finalizar" << endl;
    //cin>>comen;
    //system("cls"); ESTO SIRVE PARA LIMPIAR LA CONSOLA
    //if (comen==1)
    //{

    FILE *COMPRAS;
    COMPRAS = fopen("PROCESADOS.bin", "rw");
    if(!COMPRAS)procesar_lote(0);

    while(1){
        system("cls");
        MostrarMenu(comen);
        cin>>opcion;
        switch (opcion){

            case 0:

                return 0;

            break;

            case 1:
                system("cls");
                LevantarClientes();
                cout<< "\n PRESIONE CUALQUIER TECLA PARA REGRESAR";
                getch();


            break;

            case 2:
                system("cls");
                int b;
                //ContarClientes(b);
                //CargarCliente(b);
                cargarCiente();
                cout<< "\n PRESIONE CUALQUIER TECLA PARA REGRESAR";
                getch();


            break;

            case 3:
                system("cls");
                cout<<"�Se procederaa modificar el estado de un usuario, esta seguro ?";
                option=AceptarODenegar();
                DesactivarCliente();
                cout<< "\n PRESIONE CUALQUIER TECLA PARA REGRESAR";
                getch();

            break;
            case 4:
                system("cls");
                BuscarYMostrarCliente();
                cout<< "\n PRESIONE CUALQUIER TECLA PARA REGRESAR";
                getch();

            break;

            case 5:
                system("cls");
                ListarClientes();
                cout<< "\n PRESIONE CUALQUIER TECLA PARA REGRESAR";
                getch();

            break;

            case 6:
                system("cls");
                procesar_lote(1);
                cout<< "\n PRESIONE CUALQUIER TECLA PARA REGRESAR";
                getch();

            break;
            case 7:

                int id;
                system("cls");
                cout<< "Ingrese el id del usuario del que desea conocer sus compras: ";
                cin>>id;
                system("cls");
                MostrarComprasDeUsuario(id);
                cout<< "\n PRESIONE CUALQUIER TECLA PARA REGRESAR";
                getch();

            break;

        }
//cout << "Ingrese cualquier caracter para continuar" << endl;
//getch();
//system("cls"); ESTO SIRVE PARA LIMPIAR LA CONSOLA
    }

}




//***************************FUNCIONES EXTRA************************************

void MostrarComprasDeUsuario(int id){

    FILE*COMP;
    compra shop[1000], compraux[1000];
    int e =0, a=0;
    short posAencajar, primerPos=0, ultimaPos=0;

    if (COMP = fopen("PROCESADOS.bin","rb")){
        fread(&shop[e],sizeof(compra),1,COMP);

        while (!feof(COMP)){
            e++;
            fread(&shop[e],sizeof(compra),1,COMP);
        }
    }
    fclose(COMP);

    while( shop[primerPos].usid != id)primerPos++;
    while( shop[primerPos].usid == id){
            compraux[a] = shop[primerPos];
            a++;
            primerPos++;
    }

    cout<<"Las compras realizadas por el usuario "<<id<<" son:";

    for(int i = 0; i<a ; i++){

        cout << "\n ------------ COMPRA NUMERO "<<i+1<<" ------------ \n";
        cout << "ID_COMPRA: " << compraux[i].id_compra  << endl;
        cout << "NRO DE ARTC." << compraux[i].narticulo  << endl;
        cout << "FECHA Y HORA" << compraux[i].fechactucom;
        cout << "MONTO: $" << compraux[i].monto  << endl;
        cout << "CANTIDAD: " << compraux[i].cantidad  << endl;
        cout<<"\n --------------------------------------------------- \n";

    }
}

void CompraRand(cliente x, compra &comp, float &totc){

    float ArmC;

    comp.id_compra = rand()%9999+1;

    ArmC = rand()%1000+1;
    short i, mes, dia, hora, minu;
    i = rand()%4+1;
    if(i == 2)ArmC += 0.25;
    if(i == 3)ArmC += 0.50;
    if(i == 4)ArmC += 0.75;

    comp.monto = ArmC;

    short cant =  rand()%10+1;
    comp.cantidad = cant;

    totc = ArmC * cant;

    comp.usid = x.id_client;

    comp.narticulo = rand()%99999+1;

    comp.fechactucom[3] = (rand()%2+0) + '0';
    mes = rand()%12+1;
    comp.fechactucom[5] = (mes/10) + '0';
    comp.fechactucom[6] = (mes%10)+ '0';
    dia = rand()%31+1;
    comp.fechactucom[8] = (dia/10) + '0';
    comp.fechactucom[9] = (dia%10) + '0';
    hora = rand()%24+1;
    comp.fechactucom[11]=(hora/10) + '0';
    comp.fechactucom[12]=(hora%10) + '0';
    minu = rand()%60+1;
    comp.fechactucom[14]=(minu/10) + '0';
    comp.fechactucom[15]=(minu%10) + '0';


}

void procesar_lote(bool sec){

    srand((long)time(NULL));

    FILE* USERS, *COMP;
    int s=0, i=0, e = 0, cantU=0;
    ContarClientes(cantU);
    cliente *aux = new cliente[cantU-1];
    compra c;
    compra shop[1000];
    short cnt_cpr;
    float monto_x_c;

    if (USERS = fopen("USUARIOS.bin","rb")){

        fread(&aux[i],sizeof(cliente),1,USERS);
        while (!feof(USERS)){
            i++;
            fread(&aux[i],sizeof(cliente),1,USERS);
        }
    }
    else
        cout<<"error";

    fclose(USERS);

    for(short cnt = 0 ; cnt < cantU-1 ; cnt++){
        cout<<"\n"<<"id user "<<cnt+1<<": "<<aux[cnt].id_client<<endl;
        cout<<"Creacion: "<<aux[cnt].fechcrea<<endl;
        cout<<"Estado: "<<aux[cnt].estado<<endl;
        cout<<"Importe total de compras: "<<aux[cnt].totalcom<<endl;
        cout<<"Email: "<<aux[cnt].mail<<endl;

        cout<<"---------------------------------------------"<<endl;

    }
    cout<<"cant de usuaruis "<< cantU;
    getch();

    if(sec){
        compra compaux[1000];

        if (COMP = fopen("PROCESADOS.bin","rb")){
            fread(&shop[e],sizeof(compra),1,COMP);

            while (!feof(COMP)){
                e++;
                fread(&shop[e],sizeof(compra),1,COMP);

            }
            fclose(COMP);
        }

        ///EL ARCHIVO YA ESTA COPIADO EN EL VECTOR
        short posAencajar, primerPos=0, ultimaPos=0;
        for (int a=1/*acordate*/ ; a<cantU-1 ; a++){//PARA CADA USUARIO SE VA A GENERAR UNA CANTIDAD DE COMPRAS ALEATORIAS

            cnt_cpr =2;// rand()%5+1;
            for(int b = 0 ; b<cnt_cpr; b++){//SE GENERAN ENTRE 1 Y 5 COMPRAS X USUARIO

                CompraRand(aux[a], c, monto_x_c);//PRIMER PARAMETRO RECIBIMOS LA INFO DEL COMPRADOR(CLIENTE), SEGUNDO UN AUXILIAR PARA GENERAR EL PROCESADOS.BIN, Y TERCERO TOMAMOS EL MONTO DE C/COMPRA PARA ACTUALIZAR
                                                 //POSTERIORMENTE EL USUARIOS.BIN
                /*cout<<"------------- Compra reciente ----------------- \n\n";
                cout << "ID_COMPRA: " << c.id_compra  << endl;
                cout << "USER: " << c.usid  << endl;
                cout << "MONTO: " << c.monto  << endl;
                cout << "CANTIDAD: " << c.cantidad  << endl;
                cout << "FECHA Y HORA" << c.fechactucom  << endl;
                cout << "NRO DE ARTC." << c.narticulo  << endl;

                getch();

                cout<<"\n ---- Vector de compras antes de insertar la nueva compra ---- \n\n";
                for(int cnt=0;cnt<e;cnt++){
                    cout << "ID_COMPRA: " << shop[cnt].id_compra  << endl;
                    cout << "USER: " << shop[cnt].usid  << endl;
                    cout << "MONTO: " << shop[cnt].monto  << endl;
                    cout << "CANTIDAD: " << shop[cnt].cantidad  << endl;
                    cout << "FECHA Y HORA" << shop[cnt].fechactucom  << endl;
                    cout << "NRO DE ARTC." << shop[cnt].narticulo  << endl;
                }*/

                //getch();

                aux[a].totalcom += monto_x_c;

                while( shop[primerPos].usid != c.usid)primerPos++;
                while( shop[primerPos].usid == c.usid)primerPos++;
                ultimaPos = primerPos;

                for(int cnt = 0; cnt<e-(ultimaPos-1); cnt++ )compaux[cnt] = shop[ultimaPos+cnt];

                /*cout<<"\n ---- Vector auxiliar de compras despues de insertar la nueva compra ---- \n\n";
                for(int cnt=0;cnt<2;cnt++){
                    cout << "ID_COMPRA: " << compaux[cnt].id_compra  << endl;
                    cout << "USER: " << compaux[cnt].usid  << endl;
                    cout << "MONTO: " << compaux[cnt].monto  << endl;
                    cout << "CANTIDAD: " << compaux[cnt].cantidad  << endl;
                    cout << "FECHA Y HORA" << compaux[cnt].fechactucom  << endl;
                    cout << "NRO DE ARTC." << compaux[cnt].narticulo  << endl;
                }
                getch();*/
                shop[ultimaPos] = c;
                for(int cnt = 0; cnt<e-(ultimaPos-1); cnt++ )shop[ultimaPos+1+cnt] = compaux[cnt];
                e++;

                /*cout<<"\n ---- Vector de compras despues de insertar la nueva compra ---- \n\n";
                for(int cnt=0;cnt<e;cnt++){
                    cout << "ID_COMPRA: " << shop[cnt].id_compra  << endl;
                    cout << "USER: " << shop[cnt].usid  << endl;
                    cout << "MONTO: " << shop[cnt].monto  << endl;
                    cout << "CANTIDAD: " << shop[cnt].cantidad  << endl;
                    cout << "FECHA Y HORA" << shop[cnt].fechactucom  << endl;
                    cout << "NRO DE ARTC." << shop[cnt].narticulo  << endl;
                }
                getch();*/

            }
        }

        /*for(int cnt=0;cnt<e;cnt++){
            cout << "***************USUARIO******************" << endl;
                cout << "ID_COMPRA: " << shop[cnt].id_compra  << endl;
                cout << "USER: " << shop[cnt].usid  << endl;
                cout << "MONTO: " << shop[cnt].monto  << endl;
                cout << "CANTIDAD: " << shop[cnt].cantidad  << endl;
                cout << "FECHA Y HORA" << shop[cnt].fechactucom  << endl;
                cout << "NRO DE ARTC." << shop[cnt].narticulo  << endl;
        }*/

        if(COMP = fopen("PROCESADOS.bin","wb")){
                for(short cnt = 0 ; cnt < e ; cnt++){
                    fseek(COMP,0,SEEK_END);
                    fwrite(&shop[cnt], sizeof(compra),1, COMP);//SE ESCRIBE EL ARCHIVO PROC.BIN
                    //2fseek(COMP,0,SEEK_END);
                }
        }
        fclose(COMP);

    }
    else{

        COMP = fopen("PROCESADOS.bin","wb");

        for (int a=0 ; a<cantU-1 ; a++){//PARA CADA USUARIO SE VA A GENERAR UNA CANTIDAD DE COMPRAS ALEATORIAS

            cnt_cpr =2;// rand()%5+1;
            for(int b = 0 ; b<cnt_cpr; b++){//SE GENERAN ENTRE 1 Y 5 COMPRAS X USUARIO

                CompraRand(aux[a], c, monto_x_c);//PRIMER PARAMETRO RECIBIMOS LA INFO DEL COMPRADOR(CLIENTE), SEGUNDO UN AUXILIAR PARA GENERAR EL PROCESADOS.BIN, Y TERCERO TOMAMOS EL MONTO DE C/COMPRA PARA ACTUALIZAR
                                                 //POSTERIORMENTE EL USUARIOS.BIN
                aux[a].totalcom += monto_x_c;

                fseek(COMP,0,SEEK_END);
                fwrite(&c, sizeof(compra),1, COMP);//SE ESCRIBE EL ARCHIVO PROC.BIN
            }
        }
        fclose(COMP);
        /*cout<<"SE CARGO EL ARCHIVO PROCESADOS.bin";
        getch();
        system("cls");
        cout<<"SE LEERA ARCHIVO PROCESADOS.bin \n";

        if (COMP = fopen("PROCESADOS.bin","rb")){
            fread(&shop[e],sizeof(compra),1,COMP);

            while (!feof(COMP))
            {

                cout << "***************USUARIO******************" << endl;
                cout << "ID_COMPRA: " << shop[e].id_compra  << endl;
                cout << "USER: " << shop[e].usid  << endl;
                cout << "MONTO: " << shop[e].monto  << endl;
                cout << "CANTIDAD: " << shop[e].cantidad  << endl;
                cout << "FECHA Y HORA" << shop[e].fechactucom  << endl;
                cout << "NRO DE ARTC." << shop[e].narticulo  << endl;
                e++;
                fread(&shop[e],sizeof(compra),1,COMP);

            }

        //fclose(USERS);
        }*/
        //fclose(COMP);
        //getch();
    }
    /*cout<< "\n se leera el vector cliente de nuevo \n";
    for(short cnt = 0 ; cnt < cantU-1 ; cnt++){
        cout<<"\n"<<"id user "<<cnt+1<<": "<<aux[cnt].id_client<<endl;
        cout<<"Creacion: "<<aux[cnt].fechcrea<<endl;
        cout<<"Estado: "<<aux[cnt].estado<<endl;
        cout<<"Importe total de compras: "<<aux[cnt].totalcom<<endl;
        cout<<"Email: "<<aux[cnt].mail<<endl;

        cout<<"---------------------------------------------"<<endl;

    }
    getch();*/
    if (USERS = fopen("USUARIOS.bin","wb")){

        for(short cnt = 0 ; cnt < cantU-1 ; cnt++){
            fwrite(&aux[cnt], sizeof(cliente),1, USERS);
            fseek(USERS,0,SEEK_END);
        }
    }
    fclose(USERS);
    delete []aux;
    return;
}


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


bool AceptarODenegar( )
{
    bool acep;
    char opcion;

    cout<< "Ingrese Y para aceptar o N para denegar"<<endl;
    cin>>opcion;

    if (opcion=='Y' || opcion== 'y')
    {
        acep=true;
    }else{
        acep=false;
    }
    return acep;
}

void MostrarMenu (int prog)
{
    if (prog==0)
    {
        cout<<"GRACIAS POR UTILIZAR EL PROGRAMA"<<endl;
    }
    else
    {
        cout <<"Ingrese la opcion que desee efectuar"<<endl;
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

}


//***************************PUNTO 1************************************
void LevantarClientes()
{

    FILE* USERS;
    int i=0;
    cliente aux[11];

    //levanto todos los usuarios
    if (USERS = fopen("USUARIOS.bin","rb"))
    {
        cout<<"ok"<<endl;
        fread(&aux[i],sizeof(cliente),1,USERS);

        while (!feof(USERS))
        {
            //fread(&aux[i],sizeof(cliente),1,USERS);
            cout << "***************USUARIO******************" << endl;
            cout << "ID: " << aux[i].id_client  << endl;
            cout << "MAIL: " << aux[i].mail  << endl;
            cout << "IMPORTE: " << aux[i].totalcom  << endl;
            cout << "ESTADO: " << aux[i].estado  << endl;
            cout << "FECHA " << aux[i].fechcrea  << endl;
            i++;
            fread(&aux[i],sizeof(cliente),1,USERS);

        }
        //fclose(USERS);
    }else
        cout<<"error";

    fclose(USERS);
    getch();

}

//***************************PUNTO 2************************************

void ContarClientes(int &contador)
{
    contador=1;
    FILE *USERS;
    cliente cliloc;
    USERS=fopen("USUARIOS.bin", "rb");

    if (USERS==NULL)
        exit(1);

    fread(&cliloc, sizeof(cliente), 1, USERS);
    while(!feof(USERS))
    {
        contador++;
        fread(&cliloc, sizeof(cliente), 1, USERS);
    }
    return ;
}

void CargarCliente(int &b)
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
    //cout << "Ingrese el importe del usuario" << endl;
    //cin >> usuarios.totalcom;

    usuarios.totalcom = 0;

    usuarios.estado=true;
    printf("Ingrese su mail: ");
    scanf ("%79s",dirmail);

    strcpy(usuarios.mail,dirmail);

    fwrite(&usuarios, sizeof(cliente), 1, USERS);
    fclose(USERS);

}

void cargarCiente(void){

    FILE *USERS;
    cliente aux[1000], clien;
    int i=0;
    string email;

    if (USERS = fopen("USUARIOS.bin","rb")){

        fread(&aux[i],sizeof(cliente),1,USERS);
        while (!feof(USERS)){
            i++;
            fread(&aux[i],sizeof(cliente),1,USERS);
        }
    }
    else cout<<"error";

    fclose(USERS);

    aux[i].estado=1;
    aux[i].id_client=rand()%9999+1;
    aux[i].totalcom=0;
    strcpy(aux[i].fechcrea, "11/11/2021");

    cout<<"ingrese mail: ";
    cin>>email;

    strcpy(aux[i].mail, email.c_str());

     for(short cnt = 0 ; cnt < i+1 ; cnt++){
        cout<<"\n"<<"id user "<<cnt+1<<": "<<aux[cnt].id_client<<endl;
        cout<<"Creacion: "<<aux[cnt].fechcrea<<endl;
        cout<<"Estado: "<<aux[cnt].estado<<endl;
        cout<<"Importe total de compras: "<<aux[cnt].totalcom<<endl;
        cout<<"Email: "<<aux[cnt].mail<<endl;
        cout<<"---------------------------------------------"<<endl;
    }

     if (USERS = fopen("USUARIOS.bin","wb")){

        for(short cnt = 0 ; cnt < i+1 ; cnt++){
            fwrite(&aux[cnt], sizeof(cliente),1, USERS);
            fseek(USERS,0,SEEK_END);
        }
    }
    fclose(USERS);

    return;
}

//***************************PUNTO 3************************************
void DesactivarCliente()
{
    FILE *f;
    cliente clienteloc;
    char mailloc[150];
    int existe=0;

    f=fopen("USUARIOS.bin","rb+");
    if (f==NULL)
        exit(1);

    cout<<"Ingrese el mail del cliente a desactivar:   "<<endl;
    scanf ("%79s",mailloc);

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
void BuscarYMostrarCliente()
{
    char busquedamail[150];
    FILE* USERS;
    bool encontrado=false;
    cliente variable;
    int busquedaid=0;
    int opcion=0;

    if (USERS = fopen("USUARIOS.bin","rb"))
    {
        system("cls");
        cout<< "Cómo desea encontrar al usuario"<<endl;
        cout << "1: Por ID" <<endl;
        cout << "2: Por Mail" <<endl;
        cout<<"3: Salir";

        while (opcion!=1 && opcion != 2 && opcion != 3)
        {
        cin >> opcion;
        }

        switch (opcion) {

            case 1:
                system("cls");
                cout<< "Ingrese la ID del usuario que desea encontrar"<<endl;
                cin >> busquedaid;
                break;

            case 2:
                system("cls");
                cout<< "Ingrese el mail del usuario que desea encontrar"<<endl;
                scanf ("%79s",busquedamail);
                break;

            case 3:
                return;
            break;
        }

        fread(&variable,sizeof(cliente),1,USERS);

        while (!feof(USERS))
        {
            if (strcmp(variable.mail,busquedamail)==0 || variable.id_client == busquedaid)
            {
                system("cls");
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

    } else {
        system("cls");
        cout << "No hay ningun usuario aún" << endl;
    }

    if (encontrado==false){
        system("cls");
        cout << "No se encontro el usuario" << endl;
    }

    return;
}



//***************************PUNTO 5************************************
void ListarClientes()
{
    FILE* USERS;
    int count;
    ContarClientes(count);
    count--;

	int id_clientaux=0;
	char fechcreaaux[9];
	bool estadoaux=false;
	float totalcomaux;
	char mailaux[150];
	int j=0;


    cliente *p = new cliente[count];

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
    delete []p;
}

//********** PUNTO 7 (tiene que llegarle el vector con todas las compras) *************//
void EscribirReporteHTML(compra v[], int tam)
{
    FILE *f;
    char c1[17]="",c2[17]="";
    int i= 0;

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

//************ PUNTO 8 (tiene que llegarle un vector con todas las compras) **********//
void EscribirReporteCSV(compra v[], int tam)
{
    FILE *f;
    int i= 0;

    f = fopen("Reporte de lotes en excel.csv", "wt");
    fprintf(f,"Cliente;Fecha;Nro de Articulo;Monto;N Articulo;Cantidad;\n");

    while (strlen(v[i].fechactucom) != 0)
    {
        fprintf(f,"%d;%s;%d;%d;%d;%d\n",v[i].id_compra,v[i].fechactucom,v[i].monto,v[i].usid,v[i].narticulo,v[i].cantidad);
        i++;
    }
    fclose(f);
    return;
}
