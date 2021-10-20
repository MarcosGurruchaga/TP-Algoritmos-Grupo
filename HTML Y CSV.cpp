#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
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

void inicializarVectorAlumnos(compra v[], int tam)
{
    for (int i = 0; i<tam; i++)
        strcpy(v[i].fechactucom, "");
    return;
}

void cargarDatosPrueba(compra v[], int tam)
{
    v[0].id_compra = 1000;
    strcpy(v[0].fechactucom, "09/03/2021");
    v[0].monto = 4312848.54354;
    v[0].usid = 2;
    v[0].narticulo = 20;
    v[0].cantidad = 20000;

    v[1].id_compra = 1000;
    strcpy(v[1].fechactucom, "10/03/2021");
    v[1].monto = 4312848.54354;
    v[1].usid = 2;
    v[1].narticulo = 20;
    v[1].cantidad = 20000;

    v[2].id_compra = 1000;
    strcpy(v[2].fechactucom, "11/03/2021");
    v[2].monto = 4312848.54354;
    v[2].usid = 2;
    v[2].narticulo = 20;
    v[2].cantidad = 20000;

    v[3].id_compra = 1000;
    strcpy(v[3].fechactucom, "12/03/2021");
    v[3].monto = 4312848.54354;
    v[3].usid = 3;
    v[3].narticulo = 20;
    v[3].cantidad = 20000;

    v[4].id_compra = 1000;
    strcpy(v[4].fechactucom, "14/03/2021");
    v[4].monto = 4312848.54354;
    v[4].usid = 2;
    v[4].narticulo = 20;
    v[4].cantidad = 20000;
     
}

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

int main()
{
    compra v[100];
    inicializarVectorAlumnos(v,100);
    cargarDatosPrueba(v,100);
    escribirReporteHTML(v,100);
    escribirReporteCSV(v,100);
    return 0;
}
