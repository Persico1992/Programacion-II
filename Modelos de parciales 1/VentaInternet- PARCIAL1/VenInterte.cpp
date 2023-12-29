#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#include "internet.h"



//a) Generar un archivo con el código y el nombre de los vendedores inactivos (se consideran inactivos los vendedores que no hicieron ventas este año).

class Punto1{
private:
        char codVendedor[5], nombre[30];
public:
    void setCodVendedor(const char* cv){strcpy(codVendedor,cv);}
    void setNombre(const char* n){strcpy(nombre,n);}
        
    const char* getCodVendedor(){return codVendedor;}
    const char* getNombre(){return nombre;}
        
        void Mostrar(){
            cout << "CODIGO VENDEDOR: " << codVendedor << endl;
            cout << "NOMBRE VENDEDOR: " << nombre << endl;
        
        }
};

class ArchivoPunto1{

    private:
    char _nombre[20];
public:
    ArchivoPunto1(const char* nombre){
        strcpy(_nombre, nombre);
    }
    Punto1 leerRegistro(int pos){
        Punto1 reg;
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Punto1)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto1);
    }
 bool grabarRegistro(Punto1 reg){
        FILE *p;
        p=fopen(_nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }


     bool mostrarRegistros(){
        Punto1 read;
        FILE *p;
        p=fopen(_nombre,"rb");
        if(p==NULL) {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }
        while(fread(&read,sizeof read,1,p)== 1){
            read.Mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
        }




};

void SolucionPunto1(){

ArchivoVendedores archiVendedores("vendedores.dat");
Vendedores objVende;
int cantRegistrosVendedores=archiVendedores.contarRegistros();

ArchivoVentas archiVentas("ventas.dat");
Ventas objVentas;
int cantRegistrosVentas=archiVentas.contarRegistros();

ArchivoPunto1 archiP1("Punto1.dat");
Punto1 objP1;



 
            for(int i=0; i<cantRegistrosVendedores; i++){
        objVende=archiVendedores.leerRegistro(i);       
       bool sinVentas= false;

        for(int x=0; x<cantRegistrosVentas; x++){
            objVentas=archiVentas.leerRegistro(x);
            
            if(strcmp(objVende.getCodVendedor(),objVentas.getCodVendedor()) == 0 && objVentas.getFechaVenta().getAnio() == 2023){
               
                sinVentas=true;
            }
          
    }

            if(!sinVentas ){
                 objP1.setCodVendedor(objVende.getCodVendedor());
                objP1.setNombre(objVende.getNombre());  
                archiP1.grabarRegistro(objP1);
          }  
    
}
    archiP1.mostrarRegistros();
}

//Informar la cantidad de usuarios registrados por cada mes del año 2023
void SolucionPunto2(){

ArchivoUsuarios archiUsuario("usuario.dat");
Usuarios objUsuario;
int cantRegUsurio=archiUsuario.contarRegistros();

int vMes[12]={0};

for (int i=0; i<cantRegUsurio; i++){
        objUsuario=archiUsuario.leerRegistro(i);
       
        
        if(objUsuario.getFechaRegistracion().getAnio() == 2023){
       vMes[objUsuario.getFechaRegistracion().getMes()  -1]++;
        
        }
        
}

        int posMes=0;
        for(int x=0; x<12; x++){
            
            
                posMes= x;
         cout << "LA CANTIDAD DE USUARIOS REGISTRADOS EN CADA MES DEL AÑO FUE: MES " << x+1 << " CON " << vMes[x]  << endl;
            
       }
}

/// La cantidad de ventas realizadas por los vendedores de las provincias del Litoral (números de provincia 8, 9, y 10), el primer semestre de este año.

void SolucionPunto3(){
ArchivoVentas archiV("ventas.dat");
Ventas objVentas;
int cantRegVenta=archiV.contarRegistros();

ArchivoVendedores archiVend("vendedores.dat");
Vendedores objVendedores;
int cantRegVend=archiVend.contarRegistros();


    int cantVentas=0;
for(int x=0; x<cantRegVend; x++){
            objVendedores=archiVend.leerRegistro(x);

     
            for(int i=0; i<cantRegVenta; i++){
                objVentas=archiV.leerRegistro(i);
  
            if(objVentas.getFechaVenta().getMes() <= 6  && objVentas.getFechaVenta().getAnio() == 2022 && objVendedores.getProvincia() >= 8 && objVendedores.getProvincia() <= 10){
                
                cantVentas++;
                
                
            }
            
            
        }
     
}
      cout << "LA CANTIDAD DE VENTAS QUE TUVIERON LOS VENDEDORES DEL LITORAL:  "<< cantVentas << endl;
    
}

int menuConsignas()
{
    int opc;
    system("cls");
    while(true){
    cout<<"=== MODELO PARCIAL 1 - PROGRAMACION II ==="<<endl;
    cout<<"1. PUNTO1: Genera archivo con los vendedores inactivos del año 2023."<<endl;
    cout<<"2. PUNTO2: Informar la cantidad de usuarios registrados por cada mes del año 2023."<<endl;
    cout<<"3. PUNTO3: Cantidad de ventas realizadas por los vendedores de las provincias del Litoral (números de provincia 8, 9, y 10), el primer semestre de este año."<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
        SolucionPunto1();
    system("pause");
    system("cls");
        break;
    case 2:
        SolucionPunto2();
	system("pause");
    system("cls");
        break;
    case 3:
        SolucionPunto3();
	system("pause");
    system("cls");
        break;
    
    case 0:
        return 0;

    }

    }
}



int main(){
setlocale (LC_ALL, "Spanish");
/*
ArchivoUsuarios archiUsuario("usuario.dat");
Usuarios objUsu;

objUsu.cargar();

cout << "SE CARGO CORRECTAMENTE USUARIO." << endl << endl;

archiUsuario.grabarRegistro(objUsu);

    cout << "SE GRABO EN SISTEMA." << endl;
    
archiUsuario.mostrarRegistros();


ArchivoVendedores archiVend("vendedores.dat");
Vendedores objVende;

cout << "CARGA DE DATOS VENDEDORES." << endl;
objVende.Cargar();

archiVend.grabarRegistro(objVende);

cout << endl;

archiVend.mostrarRegistros();
system("pause");


ArchivoVentas archiVenta("ventas.dat");
Ventas objVenta;

cout << "DATOS DE LAS VENTAS." << endl;
objVenta.Cargar();

archiVenta.grabarRegistro(objVenta);

archiVenta.mostrarRegistros();
cout << endl;
system ("pause");
*/

menuConsignas();
	return 0;
}