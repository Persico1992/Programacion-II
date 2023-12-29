//Nombre:RIMASA ALEJANDRO
//Tp: PARCIAL II PROGRAMACIÓN

#include <iostream>
#include <locale.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "parcial2.h"

///Generar un archivo con los clientes que hayan realizado alguna compra de algún viaje con el guía que tiene el ID personal 225. 
//Cada registro debe tener el código de cliente, el nombre del cliente y importe de las compras a los viajes con ese guía.

class Punto1{

private: 
    char codigoCliente[5];
    char nombre [30];
    float importeCompras;

public:
        Punto1(){};
        Punto1(const char *codCli ){
           strcpy(codigoCliente,codCli);
        }
        
    
    void setCodigoCliente(const char *cc){strcpy(codigoCliente,cc);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setImporteCompras(float ic){importeCompras=ic;}
    
    const char* getCodigoCliente(){return codigoCliente;}
    const char* getNombre(){return nombre;}
    float getImporteCompras(){return importeCompras;}
    
    void Mostrar(){
    
        cout << "CODIGO CLIENTE: " << codigoCliente << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "IMPORTE DE COMPRAS: " << importeCompras << endl;
    
    }
    
    ///PUNTO 3:  Hacer una sobrecarga de operador para la clase nueva del punto 1 que sea útil para la resolución de alguno de los puntos.
                ///SE REALIZA SOBRECARGA DE OPERADOR ==
            bool operator == (Punto1 objPunto1){
            if(strcmp(codigoCliente , objPunto1.getCodigoCliente())== 0) {
                    return true;
                    }
                
            return false;
    
    }
  /*  /// OTRAS SOBRECARGAS = 
    void operator = (Cliente objCliente){
        strcpy(nombre, objCliente.getNombre());
    }
    
    void operator = (Venta objVenta){
        numVenta = objVenta.getNumVenta();
    }*/
    
};

class ArchivoPunto1{
private:                    
    char nombre[30];
public:
        ArchivoPunto1(const char* n){strcpy (nombre,n);}    
                                                                
                                                                                            
    bool grabarRegistro(Punto1 reg){        
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
        bool mostrarRegistros(){
        Punto1 read;
        FILE *p;
        p=fopen(nombre,"rb");
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
        
        
   
    
        int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto1);
    }
    
    Punto1 leerRegistro(int pos){
        Punto1 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Punto1)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }


};

//Generar un archivo con los clientes que hayan realizado alguna compra de algún viaje con el guía que tiene el ID personal 225. 
//Cada registro debe tener el código de cliente, el nombre del cliente y importe de las compras a los viajes con ese guía.
void SoluPunto1(){

ArchivoVentas archiVentas("ventas.dat");
Venta objVenta;
int cantRegVentas=archiVentas.contarRegistros();

ArchivoClientes archiCliente("clientes.dat");
Cliente objCliente;
int cantRegClientes=archiCliente.contarRegistros();

ArchivoPunto1 archiPunto1("Punto1.dat"); 
Punto1 objPunto1;

 
for (int i=0; i<cantRegClientes; i++){
        objCliente=archiCliente.leerRegistro(i);
    bool banderaPunto1=false;
    
   
float ImporteVentas=0;    
    for(int x=0; x<cantRegVentas; x++){
        objVenta=archiVentas.leerRegistro(x);
        
            if(strcmp(objCliente.getCodigoCliente(),objVenta.getNumeroDeCliente()) == 0 && objVenta.getIDpersonal() == 225 &&  objCliente.getEstado() == true ){
                ImporteVentas+=objVenta.getImporte();
                banderaPunto1=true;
            }
        
    }
    
    if(banderaPunto1 == true){
        
            objPunto1.setCodigoCliente(objCliente.getCodigoCliente());  
            objPunto1.setNombre(objCliente.getNombre());     
            objPunto1.setImporteCompras(ImporteVentas);  
            archiPunto1.grabarRegistro(objPunto1);
        
    }
        
}
            archiPunto1.mostrarRegistros();
        
}

//Hacer una función que cree un vector dinámico para cargar los registros del archivo generado en el punto 1.
//Mostrar los registros del vector.
void SoluPunto2(){

ArchivoPunto1 archiPunto1("Punto1.dat");
Punto1 *vPunto1, objPunto1;

int cantRegPunto1=archiPunto1.contarRegistros();

    if(cantRegPunto1 == 0){                          /// SI LA CANTIDAD DE REGISTRO ES 0 NO HAY REGISTROS.
        cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        return;
    }

    vPunto1= new Punto1[cantRegPunto1];
     if(vPunto1==NULL) return; 
     
    for(int i=0; i<cantRegPunto1; i++){
        
         vPunto1[i]=archiPunto1.leerRegistro(i);
         
            }
            
        for(int x=0; x<cantRegPunto1; x++){
            
            vPunto1[x].Mostrar();
        }
        
        delete vPunto1;
    }


///Generar un archivo con las ventas realizadas para el código de tour 15.
//Cada registro debe tener el número de venta, el número de cliente y el nombre del cliente.

class Punto3{

private:
    int numVenta;
    char nombreCliente[30], codCliente[5];
    
public:
    
    void setCodigoCliente(const char *cc){strcpy(codCliente,cc);}
    void setNombre(const char *n){strcpy(nombreCliente,n);}
    void setNumVenta(int nv){numVenta=nv;}
    
    int getNumVenta(){return numVenta;}
    const char* getCodigoCliente(){return codCliente;}
    const char* getNombre(){return nombreCliente;}

        void Mostrar(){
        cout << "CODIGO CLIENTE: " << codCliente << endl;
        cout << "NOMBRE: " << nombreCliente << endl;
        cout << "NUM VENTA: " << numVenta << endl;
            
        }
};


class ArchivoPunto3{

private:                    
    char nombre[30];
public:
        ArchivoPunto3(const char* n){strcpy (nombre,n);}
       
                              
    bool grabarRegistro(Punto3 reg){        
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
        bool mostrarRegistros(){
        Punto3 read;
        FILE *p;
        p=fopen(nombre,"rb");
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
        
        
   
    
        int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto3);
    }
    
    Punto3 leerRegistro(int pos){
        Punto3 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Punto3)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

};


void SolucionPunto3(){

ArchivoClientes archiCliente("clientes.dat");
Cliente objCliente;
int cantRegCliente=archiCliente.contarRegistros();

ArchivoVentas archiVentas("ventas.dat");
Venta objVenta;
int cantRegVenta=archiVentas.contarRegistros();

ArchivoPunto3 archiPunto3("Punto3.dat"); 
Punto3 objPunto3;

  
for(int i=0; i<cantRegVenta; i++){
    objVenta=archiVentas.leerRegistro(i);
            bool huboVentas= false;
        
        
        for(int x=0; x<cantRegCliente; x++){
            objCliente=archiCliente.leerRegistro(x);
                
                if(objVenta.getCodigoTour() == 15 && strcmp(objVenta.getNumeroDeCliente(),objCliente.getCodigoCliente())==0 && objCliente.getEstado() == true){
                    
                      
                    objPunto3.setCodigoCliente(objCliente.getCodigoCliente());
                    objPunto3.setNombre(objCliente.getNombre());
                    objPunto3.setNumVenta(objVenta.getNumeroVenta());
                    archiPunto3.grabarRegistro(objPunto3);
                    huboVentas=true;
                }
                  
            }
    
    
        
    }
                archiPunto3.mostrarRegistros();
}


///Generar un archivo con los clientes que hayan realizado una compra por un importe superior a 15000.
// Cada registro debe tener el codigo de cliente, el nombre de cliente y el importe total de las compras de ese cliente.

class Punto4{

private:
    char codigoCliente[5];
    char nombre [30];
    float importeCompras;

public:
    void setCodigoCliente(const char *cc){strcpy(codigoCliente,cc);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setImporteCompras(float ic){importeCompras=ic;}
    
    const char* getCodigoCliente(){return codigoCliente;}
    const char* getNombre(){return nombre;}
    float getImporteCompras(){return importeCompras;}
    
    void Mostrar(){
    
        cout << "CODIGO CLIENTE: " << codigoCliente << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "IMPORTE DE COMPRAS : " << importeCompras << endl;
    
    }
};

class ArchivoPunto4{
private:                    
    char nombre[30];
public:
        ArchivoPunto4(const char* n){strcpy (nombre,n);}    
                                                               
       bool grabarRegistro(Punto4 reg){        
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
        bool mostrarRegistros(){
        Punto4 read;
        FILE *p;
        p=fopen(nombre,"rb");
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
        
        
   
    
        int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto4);
    }
    
    Punto4 leerRegistro(int pos){
        Punto4 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Punto4)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

};                       

void SolucionPunto4(){
ArchivoClientes archiClientes("clientes.dat");
Cliente objCliente;
int cantRegCliente=archiClientes.contarRegistros();

ArchivoVentas archiVenta("ventas.dat");
Venta objVenta;
int cantRegVentas=archiVenta.contarRegistros();

ArchivoPunto4 archiP4("Punto4.dat");
Punto4 objP4;

bool ventaPorCliente=false;
float importeTotal=0;
for(int x=0; x<cantRegCliente; x++){
        objCliente=archiClientes.leerRegistro(x);

           if(!ventaPorCliente){
            for (int i=0; i<cantRegVentas; i++){
                objVenta=archiVenta.leerRegistro(i);
                
        
            if(objVenta.getImporte() > 15000 && strcmp(objVenta.getNumeroDeCliente(),objCliente.getCodigoCliente()) == 0  && objCliente.getEstado() == true){
                    ventaPorCliente=true;
                    importeTotal+=objVenta.getImporte();
            
                    }
        
                }    
                    objP4.setCodigoCliente(objCliente.getCodigoCliente());  
                    objP4.setNombre(objCliente.getNombre());  
                    objP4.setImporteCompras(importeTotal);  
                    archiP4.grabarRegistro(objP4);
        }

    }
    archiP4.mostrarRegistros();
}



///Generar un archivo con los clientes que hayan realizado compras en el año 2021. Cada registro debe tener el código de cliente, el nombre del cliente y la fecha de tour,
//En caso de que haya más de una compra se debe registrar la fecha de la primera       
   
class Punto5{

private:
    char codigoCliente[5];
    char nombre [30];
    Fecha fechaTour;
public:
    
    void setCodigoCliente(const char *cc){strcpy(codigoCliente,cc);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setFechaTour(Fecha ft){fechaTour=ft;}
    
    const char* getCodigoCliente(){return codigoCliente;}
    const char* getNombre(){return nombre;}
    Fecha getFechaTour(){return fechaTour;}
    
    void Mostrar(){
    
        cout << "CODIGO CLIENTE: " << codigoCliente << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "FECHA DE TOUR: " ;
            fechaTour.Mostrar() ;
        
    }


};


class ArchivoPunto5{

private:                    
    char nombre[30];
public:
        ArchivoPunto5(const char* n){strcpy (nombre,n);}    
                                                                
                                                                                      
    bool grabarRegistro(Punto5 reg){        
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
        bool mostrarRegistros(){
        Punto5 read;
        FILE *p;
        p=fopen(nombre,"rb");
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
        
        
   
    
        int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto5);
    }
    
    Punto5 leerRegistro(int pos){
        Punto5 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Punto5)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }


};

void SolucionPunto5(){

ArchivoClientes archiClientes("clientes.dat");
Cliente objCliente;
int cantRegCliente=archiClientes.contarRegistros();

ArchivoVentas archiVenta("ventas.dat");
Venta objVenta;
int cantRegVentas=archiVenta.contarRegistros();

ArchivoPunto5 archiP5("Punto5.dat");
Punto5 objPunto5;

bool primerVenta=false; 

for(int i=0; i<cantRegCliente; i++){
    objCliente=archiClientes.leerRegistro(i);
          
         if(!primerVenta){  
       
        for(int x=0; x<cantRegVentas; x++){
            objVenta=archiVenta.leerRegistro(x);
            
            if(strcmp(objCliente.getCodigoCliente(),objVenta.getNumeroDeCliente())== 0 && objVenta.getFechaVenta().getAnio() == 2021 && objCliente.getEstado()){
           
                primerVenta=true;
                objPunto5.setCodigoCliente(objCliente.getCodigoCliente());
                objPunto5.setNombre(objCliente.getNombre());
                objPunto5.setFechaTour(objVenta.getFechaVenta());
                archiP5.grabarRegistro(objPunto5);   
                
            }
                
        }       
            
                
    }
                
}
        archiP5.mostrarRegistros();
}

///generar un archivo con los Clientes que hayan tenido  un tour por un importe inferior a 15000.
//cada registro debe tener el codigo Cliente, el nombre del Cliente y la fecha del tour.
//En caso de que haya mas de un turno de esas caracteristicas se debe registrar la fecha del primero. */

class Punto6{
private:
    char codigoCliente[5];
    char nombre [30];
    Fecha fechaTour;
public:
    
    void setCodigoCliente(const char *cc){strcpy(codigoCliente,cc);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setFechaTour(Fecha ft){fechaTour=ft;}
    
    const char* getCodigoCliente(){return codigoCliente;}
    const char* getNombre(){return nombre;}
    Fecha getFechaTour(){return fechaTour;}
    
    void Mostrar(){
    
        cout << "CODIGO CLIENTE: " << codigoCliente << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "FECHA DE TOUR: " ;
            fechaTour.Mostrar() ;
        
    }
    

};

class ArchivoPunto6{
private:                    
    char nombre[30];
public:
        ArchivoPunto6(const char* n){strcpy (nombre,n);}    
                                                               
    bool grabarRegistro(Punto6 reg){        
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
        bool mostrarRegistros(){
        Punto6 read;
        FILE *p;
        p=fopen(nombre,"rb");
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
        
        
   
    
        int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto6);
    }
    
    Punto6 leerRegistro(int pos){
        Punto6 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Punto6)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
};

void SolucionPunto6(){
ArchivoClientes archiClientes("clientes.dat");
Cliente objCliente;
int cantRegCliente=archiClientes.contarRegistros();

ArchivoVentas archiVenta("ventas.dat");
Venta objVenta;
int cantRegVentas=archiVenta.contarRegistros();

ArchivoPunto6 archiP6("Punto6.dat");
Punto6 objPunto6;

bool primerTour=false;

for(int i=0; i<cantRegCliente; i++){
    objCliente=archiClientes.leerRegistro(i);
            
            if(!primerTour){
        for(int x=0; x<cantRegVentas; x++){
            objVenta=archiVenta.leerRegistro(x);
            
            
            if(objVenta.getImporte() < 15000 && strcmp(objCliente.getCodigoCliente(),objVenta.getNumeroDeCliente())== 0 && objCliente.getEstado() == true){
                
                            objPunto6.setCodigoCliente(objCliente.getCodigoCliente());
                            objPunto6.setNombre(objCliente.getNombre());
                            objPunto6.setFechaTour(objVenta.getFechaVenta());
                            archiP6.grabarRegistro(objPunto6);
                            primerTour=true;
            }
            
        }
            
    }
                
            
            
    }
    
        archiP6.mostrarRegistros();
}

//Generar un archivo con las ventas realizdas el año pasado (EN LOS DAT HAY FECHAS del 2020 y 2021). Cada registro debe tener el numero de venta, el numero de cliente y el nombre del cliente.

class Punto7{

private: 
    char codigoCliente[5];
    char nombre [30];
    int numeroVenta;

public:
    
    void setCodigoCliente(const char *cc){strcpy(codigoCliente,cc);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setNumVenta(int nv){numeroVenta=nv;}
    
    const char* getCodigoCliente(){return codigoCliente;}
    const char* getNombre(){return nombre;}
    int getNumVenta(){return numeroVenta;}
    
    void Mostrar(){
    
        cout << "CODIGO CLIENTE: " << codigoCliente << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "NUMERO VENTA: " << numeroVenta << endl;
    
    }
};
class ArchivoPunto7{

private:                    
    char nombre[30];
public:
        ArchivoPunto7(const char* n){strcpy (nombre,n);}    
                                                                
                                                                                           
    bool grabarRegistro(Punto7 reg){        
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
        bool mostrarRegistros(){
        Punto7 read;
        FILE *p;
        p=fopen(nombre,"rb");
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
        
        
   
    
        int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto7);
    }
    
    Punto7 leerRegistro(int pos){
        Punto7 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Punto7)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }


};

void SolucionPunto7(){

ArchivoVentas archiVentas("ventas.dat");
Venta objVenta;
int cantRegV=archiVentas.contarRegistros();

ArchivoClientes archiCl("clientes.dat");
Cliente objCl;
int cantRegCl=archiCl.contarRegistros();

ArchivoPunto7 archiP7("Punto7.dat");
Punto7 objP7;
int agrego;
for (int i=0; i<cantRegV; i++){
    objVenta=archiVentas.leerRegistro(i);
    
        for(int x=0; x<cantRegCl; x++){
            objCl=archiCl.leerRegistro(x);
            
            if(objVenta.getFechaVenta().getAnio() == 2021 && strcmp(objVenta.getNumeroDeCliente(),objCl.getCodigoCliente())== 0 && objCl.getEstado()){
                
                    objP7.setCodigoCliente(objCl.getCodigoCliente());
                    objP7.setNombre(objCl.getNombre());
                    objP7.setNumVenta(objVenta.getNumeroVenta());
                    archiP7.grabarRegistro(objP7);
                    
                       
            }
    
        }
    
    
}
       
        archiP7.mostrarRegistros();


}


int menuConsignas()
{
    int opc;
    system("cls");
    while(true){
    cout<<"=== PARCIAL 2 - PROGRAMACION II ==="<<endl;
    cout<<"1.PUNTO 1"<<endl;
    cout<<"2.PUNTO 2"<<endl;
    cout<<"3.PUNTO 3"<<endl;
    cout<<"4.PUNTO 4"<<endl;
    cout<<"5.PUNTO 5"<<endl;
    cout<<"6.PUNTO 6"<<endl;
    cout<<"7.PUNTO 7"<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
        SoluPunto1();
        system("pause");
        system("cls");
        break;
    case 2:
        SoluPunto2();
        system("pause");
        system("cls");
        break;
    case 3:
        SolucionPunto3();
        system("pause");
        system("cls");
        break;
    case 4:
        SolucionPunto4();
        system("pause");
        system("cls");
        break;
         case 5:
       SolucionPunto5();
        system("pause");
        system("cls");
        break;
         case 6:
      SolucionPunto6();
        system("pause");
        system("cls");
        break;
         case 7:
        SolucionPunto7();
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

menuConsignas();
/*
ArchivoVentas archiVentas("ventas.dat");
Venta objVenta;
int agrego;

cout << "CARGUE VENTA: " << endl;
//objVenta.Cargar();

cout << "SE GUARDA VENTA: " << endl;
//agrego=archiVentas.grabarRegistro(objVenta);

cout << "-------------------------" <<endl;

    if(agrego == 1){
        cout << "VENTA AGREGADA CORRECTAMENTE. "  << endl;
        
    }
    else{
        cout << "REINGRESE NUEVAMENTE." << endl;
    }

    cout << "-----------------------------------" << endl;
    cout << "AHORA MUESTRA EL AGREGADO." << endl;
    archiVentas.mostrarRegistros();
  */
  //ArchivoClientes archiCl("clientes.dat");
  //archiCl.mostrarRegistros();
  
   
    
//SoluPunto1(); OK

//SoluPunto2();  OK

//SolucionPunto2();

//SolucionPunto3();

//SolucionPunto4();

//SolucionPunto5();

//SolucionPunto6();

/*
///PRUEBA Punto 3
Punto1 obj("a"), obj2("c");

if(obj == obj2){
    
    cout << "SON IGUALES.";
    
}
else {
    cout << "SON DISTINTOS.";
}

*/


cout << endl;
system ("pause");

	return 0;
}