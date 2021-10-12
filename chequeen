#include <iostream>
using namespace std;
#include <stdio.h>
#include <ctime>
#include <cstring>
#include <iostream>
using namespace std;


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

void cargar(int b,char feac[9])
{
    FILE *USERS;
    USERS = fopen("c:/users/Lucas/Desktop/USUARIOS.bin", "ab+");

    cliente usuarios;
    usuarios.id_client=b;
    fflush(stdin);
    usuarios.fechcrea[9] =feac[9];
    usuarios.totalcom=0;
    usuarios.estado=1;
        printf("Ingrese su mail:    ");
    std::cin>>(usuarios.mail);
    fwrite(&usuarios, sizeof(cliente), 1, USERS);
    fclose(USERS);
    return;
};



char *fechyho( char *fecha [17])
{   char *fec=fecha[17];
     std::time_t rawtime;
    std::tm* timeinfo;
    std::time(&rawtime);
   timeinfo = std::localtime(&rawtime);

    std::strftime(fec,17,"%Y%m%d%H%M%S",timeinfo);
    return fec;
};

void menu (int prog)
{
    if (prog==0)
    {
        	std::cout<<"GRACIAS POR UTILIZAR EL PROGRAMA"<<std::endl;
    }
    else
    {
        std::cout << "Ingrese la opcion que desee efectuar"<<std::endl;
        std::cout << "1-Crear un nuevo cliente"<<std::endl;
        std::cout << "2-Desactivar un cliente"<<std::endl;
        std::cout <<"3-Procesar un lote"<<std::endl;
        std::cout <<"4-Buscar cliente por ID o mail"<<std::endl;
        std::cout <<"5-Listar los clientes"<<std::endl;
        std::cout <<"6-Procesar lote"<<std::endl;
        std::cout <<"7-Mostrar todas las compras de un cliente"<<std::endl;
        std::cout <<"8-Mostrar todas las compras de un cliente entre dos fechas (HTML)"<<std::endl;
        std::cout <<"9-Mostrar todas las compras de un cliente entre dos fechas (CSV)"<<std::endl;
        std::cout <<"10-Finalizar jornada y guardar datos"<<std::endl;
    };

};
void contacli(int contador)
{   contador=1;
    FILE *USERS;
    USERS=fopen("c:/users/Lucas/Desktop/USUARIOS.bin", "rb");
    if (USERS==NULL)
        exit(1);
    cliente cliloc;
    fread(&cliloc, sizeof(cliente), 1, USERS);
    while(!feof(USERS))
    {
        contador=contador++;
        fread(&cliloc, sizeof(cliente), 1, USERS);
    }
    return ;
}
void cargarcli(int b)
{
                     FILE* USERS;
                     char ff[9], dirmail[150];
                     time_t rawtime=time(0);
                     struct  tm timeinfo;
                     timeinfo =*localtime(&rawtime);
                     strftime(ff,80,"%Y-%m-%d",   &timeinfo);
                     USERS = fopen("c:/users/Lucas/Desktop/USUARIOS.bin", "ab+");
                     fflush(stdin);
                     cliente usuarios;
                     usuarios.id_client=b;
                     strcpy(usuarios.fechcrea,ff);
                     usuarios.totalcom=0.1;
                     usuarios.estado=true;
                     printf("Ingrese su mail:    ");
                     std::cin>>dirmail;
                     strcpy(usuarios.mail,dirmail);
                     fwrite(&usuarios, sizeof(cliente), 1, USERS);
                     fclose(USERS);
}

int busCli(FILE* f,cliente c, bool opcion)
{       f=fopen("c:/users/Lucas/Desktop/USUARIOS.bin", "rb");
        cliente cli;
        int  posicion=-1;
        char busqueda[150];
        if(f!=NULL)
        {
            std::cout<< "Ingrese el mail del usuario que desea desactivar"<<endl;
            std::cin>>busqueda;
            while(!feof(f))
            {
                fread( &cli,sizeof(cliente),1,f);
                if(&cli.mail== &busqueda)
                {
                    posicion=ftell(f)/sizeof(cliente);
                    c = cli;
                }
            }
        }
        return posicion;

}

void modificacion()
{
    FILE *f;
    f=fopen("c:/users/Lucas/Desktop/USUARIOS.bin","rb+");
    if (f==NULL)
        exit(1);
    std::cout<<"Ingrese el mail del cliente a desactivar:   "<<endl;
    char mailloc[150];
    std::cin>> mailloc;
    cliente  clienteloc;
    int existe=0;
    fread(&clienteloc, sizeof(cliente), 1, f);
    while(!feof(f))
    {
        if (mailloc==clienteloc.mail)
        {  bool condition;
           std::cout<< "Se procedera a desactivar al usuario:   "<< clienteloc.mail<< " con un total de compra de "<< clienteloc.totalcom<< "$"<<endl;

           clienteloc.estado=false;
           int pos=ftell(f)-sizeof(cliente);
           fseek(f,pos,SEEK_SET);
           fwrite(&clienteloc, sizeof(cliente), 1, f);
           std:: cout<< "Se ha desactivado el usuario"<<endl;
           existe=1;
           break;
        }
        fread(&clienteloc,  sizeof(cliente), 1, f);
    }
    if (existe==0)
        std::cout<<"No existe un usuario con dicho mail"<<endl ;
    fclose(f);
    return;
}

bool aceptar( )
{
    bool acep;
    char opcion;
    std::cout<< "Ingrese Y para aceptar o N para denegar"<<endl;
    std::cin>>opcion;
    if (opcion=='Y' || opcion== 'y')
    {
        acep=true;
    }else {acep=false;};
    return acep;
}

int main ()
{
	int me=700, art=0, cantart=0, mont=0, totcom=0, montlot=0, cantlot=0, preart=0, montotxart=0, stop=1,comen=1, opcion,  a=0 ;
	char  ffch[100];
	bool option=false;
	cliente aux;

    FILE *USERS;
    USERS = fopen("c:/users/Lucas/Desktop/USUARIOS.bin", "ab");

    FILE *COMPRAS;
    USERS = fopen("c:/users/Lucas/Desktop/COMPRAS.bin", "wb");
    std::cout<<" Ingrese 1 para comenzar y 0 para finalizar";
    	std::cin>>comen;

    if (comen==1)
    {   menu(comen);
         while (comen==1)
        {
           std::cin>>opcion;
            switch (opcion)
            {
                case 0:
                {
                    comen=0;
                    break;
                }
                case 1:
                    {
                     int   b;
                     contacli(b);
                     cargarcli(b);
                     break;
                    };
                case 2:
                {
                    std:: cout<<"¿Se procederaa modificar el estado de un usuario, esta seguro ?";
                    option=aceptar();
                    modificacion();
                    break;
                }

            }
            cout<< "ingrese otra opcion"<<endl;
        }

    }

    return 0;
}
