#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#include "parcial2.h"



class Punto1{

private:
    int numeroPasajero;
    char nombre[30];
    char telefono[30];
    char direccion[30];
    int provincia;
    bool activo;
public:
   
    void Mostrar(){
    
            cout <<"NUMERO DE PASAJERO: "<< numeroPasajero << endl;
            cout <<"NOMBRE: " << nombre << endl;
            cout <<"TELEFONO: " << telefono << endl;
            cout <<"DIRECCION: " << direccion << endl;
            cout <<"PROVINCIA: "<< provincia << endl;
    }

    int getNumeroPasajero(){return numeroPasajero;}
    int getProvincia(){return provincia;}
    const char *getNombre(){return nombre;}
    const char *getTelefono(){return telefono;}
    const char *getDireccion(){return direccion;}
    bool getActivo(){return activo;}

    void setNumeroPasajero(int np){numeroPasajero=np;}
    void setProvincia(int np){provincia=np;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTelefono(const char *n){strcpy(telefono,n);}
    void setDireccion(const char *n){strcpy(direccion,n);}
    void setActivo(bool a){activo=a;}




};

class ArchivoPunto1{

private:
    char nombre[30];
public:
   /* ArchivoPunto1 (const char* n){strcpy (nombre,n);}*/
    
    ArchivoPunto1(){
        strcpy(nombre,"Punto1.dat");
    }
    bool grabarRegistro(Punto1 reg){        ///Esto escribe un registro en el archivo que esta guardado en la propiedad nombre
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
     ///Si compilamos varias veces algo, debemos borrar/vaciar el archivo cada vez que lo creo.. Vamos a agregar el metodo este   
        void vaciar(){
            FILE *p = fopen(nombre,"wb");
            if(p==NULL){return;}
            fclose(p);
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

class Punto5{

private:
    private:
    int numeroPasajero;
    char nombre[30];
    char telefono[30];
    char direccion[30];
    int provincia;
    bool activo;
    int cantPasajes;
public:
   
    void Mostrar(){
            cout <<"NUMERO DE PASAJERO: "<< numeroPasajero << endl;
            cout <<"NOMBRE: " << nombre << endl;
            cout <<"TELEFONO: " << telefono << endl;
            cout <<"DIRECCION: " << direccion << endl;
            cout <<"PROVINCIA: "<< provincia << endl;
    }

    int getNumeroPasajero(){return numeroPasajero;}
    int getProvincia(){return provincia;}
    const char *getNombre(){return nombre;}
    const char *getTelefono(){return telefono;}
    const char *getDireccion(){return direccion;}
    bool getActivo(){return activo;}
    int getCantPasajes(){return cantPasajes;}

    void setNumeroPasajero(int np){numeroPasajero=np;}
    void setProvincia(int np){provincia=np;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTelefono(const char *n){strcpy(telefono,n);}
    void setDireccion(const char *n){strcpy(direccion,n);}
    void setActivo(bool a){activo=a;}
    void setCantPasajes(int cp){cantPasajes=cp;}

};

class ArchivoPunto5{

private:
    char nombre[30];
public:
    
    ArchivoPunto5(){
        strcpy(nombre,"Punto5.dat");
    }
    bool grabarRegistro(Punto5 reg){        ///Esto escribe un registro en el archivo que esta guardado en la propiedad nombre
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
     ///Si compilamos varias veces algo, debemos borrar/vaciar el archivo cada vez que lo creo.. Vamos a agregar el metodo este   
        void vaciar(){
            FILE *p = fopen(nombre,"wb");
            if(p==NULL){return;}
            fclose(p);
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

class Punto6{

private:
    int codigoAvion;
    char nombre[30];
    int cantVuelos;
    
public:
    
    int getCodigoAvion(){return codigoAvion;}
    const char* getNombre(){return nombre;}
    int getCantidadVuelos(){return cantVuelos;}
    
    void setCodigoAvion(int ca){codigoAvion=ca;}
    void setNombre(const char* n){strcpy(nombre,n);}
    void setCantVuelos(int cv){cantVuelos=cv;}
    
    void Mostrar(){
    
        cout <<"CODIGO DE AVION: " << codigoAvion << endl;
        cout <<"NOMBRE: " << nombre << endl;
        cout <<"CANTIDAD DE VUELOS: " << cantVuelos << endl;
    }

};

class ArchivoPunto6{

private:
    char nombre[30];
public:
    
    ArchivoPunto6(){
        strcpy(nombre,"Punto6.dat");
    }
    bool grabarRegistro(Punto6 reg){        ///Esto escribe un registro en el archivo que esta guardado en la propiedad nombre
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
     ///Si compilamos varias veces algo, debemos borrar/vaciar el archivo cada vez que lo creo.. Vamos a agregar el metodo este   
        void vaciar(){
            FILE *p = fopen(nombre,"wb");
            if(p==NULL){return;}
            fclose(p);
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

void Punto7(){
ArchivoPunto6 archiP6;
Punto6 *vP6, objPunto6;
int cantRegP6= archiP6.contarRegistros();
        
    if(cantRegP6 == 0){
           cout << "NO HAY REGISTRO EN EL ARCHIVO" << endl;
        }
        
        vP6= new Punto6[cantRegP6];
            if(vP6 == NULL) {
            cout << "ERROR AL CREAR EL VECTOR.";
            } 
        
for (int i=0; i<cantRegP6; i++){
    objPunto6=archiP6.leerRegistro(i);      
        vP6[i]=objPunto6;
    
        }
    for (int x=0; x<cantRegP6; x++){
        vP6[x].Mostrar() ;
       cout  << endl ;
    }

}
///PUNTO 3
void Punto3(){
ArchivoAvion archiAvion;
Avion objAvion, *vAvion;
int cantRegAvion=archiAvion.contarRegistros();
int cantAvionesPropios=0;

    for(int i=0; i<cantRegAvion; i++){
        objAvion=archiAvion.leerRegistro(i);
        
            if(objAvion.getTipo()== 1){
            cantAvionesPropios++;
        }
    }
    
    cout << "La cantidad de aviones propios que hay son: " << cantAvionesPropios << " *aprete enter para proseguir*. " << endl;
    system("pause");
            
            if(cantRegAvion == 0){
                cout << "NO HAY REGISTRO EN EL ARCHIVO." << endl;
            }
            
   vAvion=new Avion[cantAvionesPropios];
    if(vAvion == NULL) {
        
        cout << "ERROR AL CREAR EL VECTOR.";
    } 
       
       int muestraPedidoDatos=0;                                                                                 //HACIENDO ESTO MUESTRO TODO EL CONJUNTO DE DATOS
   for(int x=0; x<cantRegAvion; x++ ){                                                                              // for(int x=0; x<cantAvionesPropios; x++){
        objAvion=archiAvion.leerRegistro(x);                                                                        //   vAvion[x]=archiAvion.leerRegistro(x); 
                                                                                                                     //      vAvion[x].Mostrar();
           if(objAvion.getTipo() == 1){                                                                             
            vAvion[muestraPedidoDatos].setCodigoAvion(objAvion.getCodigoAvion());
            vAvion[muestraPedidoDatos].setNombre(objAvion.getNombre());
            vAvion[muestraPedidoDatos].setMarca(objAvion.getMarca());
            muestraPedidoDatos++;
           }                                                                                                    
   }                                                                                                            
                                                                                                                               
        for(int y=0; y<cantAvionesPropios; y++){
            cout << "Cod avion: " << vAvion[y].getCodigoAvion() << endl;
            cout << "Nombre: " << vAvion[y].getNombre() << endl;
            cout << "Marca: " <<vAvion[y].getMarca() << endl;
            cout << endl << endl;
        }                                                                                                          
            
                delete vAvion;
        }   



///PUNTO 4
/*
 bool operator == (Pasaje objPasaje  ){
        if(codigoAvion == objPasaje.getCodigoAvion()) return true;
        return false;
    }*/

    ///PUNTO 2
    bool modificarRegistro(Avion obj, int nroReg) {
    FILE* p = fopen("aviones.dat", "rb+");
    if (p == NULL) {
        return false;
    }
    fseek(p, nroReg * sizeof(Avion), SEEK_SET);
    bool ok = fwrite(&obj, sizeof(Avion), 1, p);
    fclose(p);
    return ok;
}

void SolucionPunto1();
void SolucionPunto2();
void SolucionPunto5();
void SolucionPunto6();


int menuConsignas()
{
    int opc;
    system("cls");
    while(true){
    cout<<"=== MODELO PARCIAL 2 - PROGRAMACION II ==="<<endl;
    cout<<"1. Genera archivo con pasajeros que NO compraron pasajes en el presente año. Formato del archivo igual al de pasajeros."<<endl;
    cout<<"2. Modificar el archivo de aviones. Marca Boeing debe reducirse un 5%"<<endl;
    cout<<"3. Generar Vector dinamico con los aviones de tipo Propio y mostrarlos."<<endl;
    cout<<" PUNTO4 Sobrecarga de operadores (SE ENCUENTRA EN LA CLASE pasajes.h )."<<endl;
    cout<<"5. Generar archivo con pasajeros que HAYAN comprado pasajes en el presente año."<<endl;
    cout<<"6. Generar archivo con la cantidad de vuelos realizados por los aviones. Cada registro debe tener cod avion, nombre y cant vuelos."<<endl;
    cout<<"7. Generar Vec dinamico para copiar y luego mostrar el archivo del punto anterior."<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
        cout << "PUNTO 1: " << endl << endl;
            SolucionPunto1();
        system("pause");
        system("cls");
        break;
    case 2:
        cout << "PUNTO 2: " << endl << endl;
            SolucionPunto2();
        system("pause");
        system("cls");
        break;
    case 3:
        cout << "PUNTO 3: " << endl << endl;
            Punto3();
        system("pause");
        system("cls");
        break;

    case 5:
        cout << "PUNTO 5: " << endl << endl;
            SolucionPunto5();
        system("pause");
        system("cls");
        break;
    case 6:
        cout << "PUNTO 6: " << endl << endl;
        SolucionPunto6();
        system("pause");
        system("cls");
        break;
    case 7:
        cout << "PUNTO 7: " << endl << endl;
        Punto7();
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


cout << endl;
system ("pause");

	return 0;
}



void SolucionPunto1(){
ArchivoPasajeros archiPasajeros;
Pasajero objPasajero;
int cantRegPasajero=archiPasajeros.contarRegistros();

ArchivoPasajes archiPasaje;
Pasaje objPasaje;
int cantRegPasaje= archiPasaje.contarRegistros();

ArchivoPunto1 archiPunto1;
Punto1 objPunto1;

for(int i=0; i<cantRegPasajero; i++){
    objPasajero=archiPasajeros.leerRegistro(i);
    
    bool comproPasaje= false; ///No compro.
        for (int x=0; x<cantRegPasaje; x++){
            objPasaje=archiPasaje.leerRegistro(x);

            if(objPasajero.getNumeroPasajero() == objPasaje.getNumeroPasajero() && objPasaje.getFechaCompra().getAnio() == 2022){
                comproPasaje = true;
            }
            
            
        }
        
        if(!comproPasaje){ //si, NO compro
            
            objPunto1.setNumeroPasajero(objPasajero.getNumeroPasajero());
            objPunto1.setNombre(objPasajero.getNombre());
            objPunto1.setTelefono(objPasajero.getTelefono());
            objPunto1.setDireccion(objPasajero.getDireccion());
            objPunto1.setProvincia(objPasajero.getProvincia());
            objPunto1.setActivo(objPasajero.getActivo());
            
            archiPunto1.grabarRegistro(objPunto1);
            
        } 
        
        
    }
        archiPunto1.mostrarRegistros();

}

void SolucionPunto2(){

ArchivoAvion archiAvion;
Avion objAvion;
int cantRegAvion=archiAvion.contarRegistros();

archiAvion.listarArchivo(); ///Revision de archivo
cout << endl << endl;
cout << "-----------------------" << endl;

for(int i=0; i<cantRegAvion; i++){
    objAvion=archiAvion.leerRegistro(i);
        
        if(strcmp(objAvion.getMarca(), "Boeing")== 0){
            objAvion.setCantidadAsientos(objAvion.getCantidadAsientos()*0.95);
            modificarRegistro(objAvion,i);
        }
}

    archiAvion.listarArchivo();

}


void SolucionPunto5(){

ArchivoPasajeros archiPasajeros;
Pasajero objPasajero;
int cantRegistroPasajeros=archiPasajeros.contarRegistros();

ArchivoPasajes archiPasajes;
Pasaje objPasaje;
int cantRegistroPasaje=archiPasajes.contarRegistros();

ArchivoPunto5 archiPunto5;
Punto5 objPunto5;

    for (int i=0; i<cantRegistroPasajeros; i++){
        objPasajero=archiPasajeros.leerRegistro(i);
        
        bool comproPasaje= false; //NO COMPRO
        for(int x=0; x<cantRegistroPasaje; x++){
            objPasaje=archiPasajes.leerRegistro(x);
            
            if(objPasajero.getNumeroPasajero() == objPasaje.getNumeroPasajero() && objPasaje.getFechaCompra().getAnio() == 2022 && objPasaje.getActivo() && objPasajero.getActivo()){
                comproPasaje= true; ///SI COMPRO EN ESE AÑO
                
            }
            
        }
        
            if(comproPasaje){   ///GENERA EL ARCHIVO EN LOS VERDADEROS QUE ME COMPRARON.
                
            objPunto5.setNumeroPasajero(objPasajero.getNumeroPasajero());
            objPunto5.setNombre(objPasajero.getNombre());
            objPunto5.setTelefono(objPasajero.getTelefono());
            objPunto5.setDireccion(objPasajero.getDireccion());
            objPunto5.setProvincia(objPasajero.getProvincia());
            objPunto5.setActivo(objPasajero.getActivo());
            
            archiPunto5.grabarRegistro(objPunto5);
                
                
            }
    }
        archiPunto5.mostrarRegistros();
}

void SolucionPunto6(){

ArchivoVuelo archiVuelo;
Vuelo objVuelo;
int cantRegistrosVuelo=archiVuelo.contarRegistros();

ArchivoAvion archiAvion;
Avion objAvion;
int cantRegistrosAvion=archiAvion.contarRegistros();

ArchivoPasajes archiPasajes;
Pasaje objPasaje;
int cantRegistrosPasajes=archiPasajes.contarRegistros();

ArchivoPunto6 archiPunto6;
Punto6 objPunto6;
int cantVuelos=0;

for (int i=0; i<cantRegistrosAvion; i++){
    objAvion=archiAvion.leerRegistro(i);
    
    int contadorVuelosPorAvion=0;
        for(int x=0; x<cantRegistrosPasajes; x++){
            objPasaje=archiPasajes.leerRegistro(x);
        bool hayMatch= false;    ///No hay match
            
            for(int k=0; k<cantRegistrosVuelo; k++){
                objVuelo=archiVuelo.leerRegistro(k);
                
                if(objAvion.getCodigoAvion() == objPasaje.getCodigoAvion() && strcmp(objPasaje.getCodigoVuelo(),objVuelo.getCodigoVuelo()) == 0){
                    
                hayMatch=true;  ///Hay match
                }
            }
            if(hayMatch){
                contadorVuelosPorAvion++;
            }
            
        }
            if(contadorVuelosPorAvion > 0){
                objPunto6.setCodigoAvion(objAvion.getCodigoAvion());
                objPunto6.setNombre(objAvion.getNombre());
                objPunto6.setCantVuelos(contadorVuelosPorAvion);
                archiPunto6.grabarRegistro(objPunto6);
                }
            }
    archiPunto6.mostrarRegistros();
}




