#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

 struct Usuario{

        int id;
        char FechaCreacion [11] = {'2', '0', '2', '1', '/','f','f','/','f','f','f'};
        bool Activo;
        float compras;
        char Email[30];

    };

void GeneraMail(char [], string[], string[], string[]);

int main(){
    system("cls");

    FILE *USERS;
    USERS = fopen("C:\\Users\\BrunoMakarenko\\Desktop\\Primer año ING\\ALGORITMOS\\Proyectos\\CODIGOFINAL\\USUARIOS.bin", "wb");

    string Fname[] = {"juan", "miguel", "luis", "lucas", "susana", "laura", "carlos","alberto",
                        "jose", "alvaro", "hector", "gerardo", "agustin", "manuel", "maria", "lourdes", "guadalupe"
                        "dylan", "fabian", "agustina", "ezequiel", "facundo", "rodrigo", "german", "mauricio", "talia", "melina"};

    string Lname[] = {"torres", "gonzales", "gomez", "espinosa", "muñoz", "garcia", "sanchez", "herrera", "gimenez", "lopez", "diaz"
                        "perez", "bemitez", "flores", "sosa"};

    string M[4] = {"@gmail.com", "@yahoo.com", "@hotmail.com", "@outlook.com"};
    char mail[20];

    int cantU;
    float ArmC = 0;
    Usuario aleatorio[100];
    Usuario aux[100];

    srand((long)time(NULL));

    cout<<"Seleccione cantidad de Usuario a crear: ";
    cin>>cantU;

    //GeneraMail(mail, Fname, Lname, M);

    for(short cnt = 0 ; cnt < cantU ; cnt++){
        int mes, dia;
        aleatorio[cnt].id = rand()%10000+0;

        //aleatorio[cnt].FechaCreacion[3] = (rand()%2+0) + '0';
        mes = rand()%12+1;
        aleatorio[cnt].FechaCreacion[5] = (mes/10) + '0';
        aleatorio[cnt].FechaCreacion[6] = (mes%10)+ '0';
        dia = rand()%31+1;
        aleatorio[cnt].FechaCreacion[8] = (dia/10) + '0';
        aleatorio[cnt].FechaCreacion[9] = (dia%10) + '0';
        aleatorio[cnt].FechaCreacion[10] = '\n';
        aleatorio[cnt].Activo = 1;

        /*ArmC = rand()%1000+1;
        short i;
        i = rand()%4+1;
        if(i == 2)ArmC += 0.25;
        if(i == 3)ArmC += 0.50;
        if(i == 4)ArmC += 0.75;*/
        aleatorio[cnt].compras = 0;

        GeneraMail(mail, Fname, Lname, M);
        strcpy(aleatorio[cnt].Email, mail);
/*
        cout<<"\n"<<"id user "<<cnt+1<<": "<<aleatorio[cnt].id<<endl;
        cout<<"Creacion: "<<aleatorio[cnt].FechaCreacion<<endl;
        cout<<"Estado: "<<aleatorio[cnt].Activo<<endl;
        cout<<"Importe total de compras: "<<aleatorio[cnt].compras<<endl;
        cout<<"Email: "<<aleatorio[cnt].Email<<endl;
*/
        //cout<<"---------------------------------------------"<<endl;

        //fwrite(&aleatorio[cnt], sizeof(Usuario),cantU, USERS);

        srand(rand()*rand());

    }

    for(short cnt = 0 ; cnt < cantU ; cnt++){
            fwrite(&aleatorio[cnt], sizeof(Usuario),1, USERS);
            fseek(USERS,0,SEEK_END);
    }

    for(short cnt = 0 ; cnt < cantU ; cnt++){
        cout<<"\n"<<"id user "<<cnt+1<<": "<<aleatorio[cnt].id<<endl;
        cout<<"Creacion: "<<aleatorio[cnt].FechaCreacion<<endl;
        cout<<"Estado: "<<aleatorio[cnt].Activo<<endl;
        cout<<"Importe total de compras: "<<aleatorio[cnt].compras<<endl;
        cout<<"Email: "<<aleatorio[cnt].Email<<endl;

        cout<<"---------------------------------------------"<<endl;

    }


    fclose(USERS);
    /*
    cout<<"\n\n"<<"------------------- TERMINO LA CARGA DE DATOS -------------------";
    cout<<"\n\n"<<"----------------------- LEEMOS EL ARCHIVO -----------------------"<<"\n\n";

    getch();
    //system("cls");
    int a = 0;
    USERS = fopen("C:\\Users\\BrunoMakarenko\\Desktop\\Primer año ING\\ALGORITMOS\\Proyectos\\TPanual\\USUARIOS.bin", "rb");
    if(USERS){
        while(fread(&aux[a], sizeof(Usuario), cantU, USERS)){

            cout<<"\n"<<"id user "<<a+1<<": "<<aux[a].id<<endl;
            cout<<"Creacion: "<<aux[a].FechaCreacion<<endl;
            cout<<"Estado: "<<aux[a].Activo<<endl;
            cout<<"Importe total de compras: "<<aux[a].compras<<endl;
            cout<<"Email: "<<aux[a].Email<<endl;
            a++;


        }


    }
    fclose(USERS);*/

    return 0;
}






void GeneraMail(char mail[], string Fname[], string Lname[], string M[]){

    bool aux;
    short a1, a2;
    char Num[3] = {'f','f','\0'};


    aux =  rand()%2+0;
    if(aux)
        strcpy(mail, Fname[rand()%15+0].c_str());
    else strcpy(mail, Lname[rand()%15+0].c_str());

    a1 = rand()%3+0;

    switch (a1){
        case 0:
        break;

        case 1:
            strcat(mail, ".");
        break;

        case 2:
            strcat(mail, "_");
        break;
}

    if(aux)
        strcat(mail, Lname[rand()%15+0].c_str());
    else strcat(mail, Fname[rand()%15+0].c_str());

    Num[0] = (rand()%9+0) + '0';
    Num[1] = (rand()%9+0) + '0';

    //if()
       strncat(mail,Num,sizeof(Num) );


    a2 = rand()%4+0;

    switch (a2){

        case 0:
            strcat(mail, M[0].c_str());
        break;

        case 1:
            strcat(mail, M[1].c_str());
        break;

        case 2:
            strcat(mail, M[2].c_str());
        break;

        case 3:
            strcat(mail, M[3].c_str());
        break;

    }

    //cout<< "su mail es: "<<mail<<"\n\n";
    srand(rand()*rand());

}

