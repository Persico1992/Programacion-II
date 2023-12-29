#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "Final.h"

class Punto1{

private:
    int DNI, cantMisiones;
    char nombre[50], apellido[50];
    
public:
        
    void setDNI (int d){DNI=d;}
    void setNombre (const char* n){strcpy(nombre,n);}
    void setApellido(const char* a){strcpy(apellido,a);}
    void setCantMisiones(int cm){cantMisiones=cm;}
    
    int getDNI(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    int getCantMisiones(){return cantMisiones;}

    void Mostrar(){
        cout << "DNI: " << DNI << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "APELLIDO: " << apellido << endl;
        cout << "CANTIDAD DE MISIONES: " << cantMisiones << endl;
    }
};

class ArchivoPunto1{

    private:
    char nombre[30];
public:
    ArchivoPunto1(const char *n){
        strcpy(nombre, n);
    }
    Punto1 leerRegistro(int pos){
        Punto1 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
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
    bool grabarRegistro(Punto1 reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
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


};


void SolucionPunto1();
void SolucionPunto2();

int main()
{

SolucionPunto1();
SolucionPunto2();


/*
///PUNTO 3
ArchivoAstronauta archiAst("astronauta.dat");
ClasePunto2 objP2;
Astronauta objAstro(objP2);

cout << "muestro el constructor del Astronauta: " << endl;
cout << objAstro.getDNI() << endl;
cout << "*************************" << endl;
objAstro.Mostrar();
cout << "Muestro el constructor del objp2: " << endl;
cout << objP2.getDNI() << endl;
*/


    return 0;
}


void SolucionPunto1(){

ArchivoAstronauta archiAstro("astronauta.dat");
Astronauta objAstro;
int cantRegAstro=archiAstro.contarRegistros();

ArchivoMisiones archiMisiones("misiones.dat");
Misiones objMisiones;
int cantRegMisio= archiMisiones.contarRegistros();

ArchivoPunto1 archiP1("Punto1.dat");
Punto1 objP1;

int cantMisiones;
for (int i=0; i<cantRegAstro; i++){
    objAstro=archiAstro.leerRegistro(i);
    
    cantMisiones=0;
    
    for(int x=0; x<cantRegMisio; x++){
        objMisiones=archiMisiones.leerRegistro(x);
        
            if(objAstro.getDNI() == objMisiones.getDNI() && objAstro.getPais() >=1 && objAstro.getPais() <=10){
                cantMisiones++;
            }
    }
        if(cantMisiones > 0){
            objP1.setDNI(objAstro.getDNI());
            objP1.setNombre(objAstro.getNombre());
            objP1.setApellido(objAstro.getApellido());
            objP1.setCantMisiones(cantMisiones);
            archiP1.grabarRegistro(objP1);
        }
        
    
}

    archiP1.mostrarRegistros();
}

void SolucionPunto2(){  ///La categoria con más Astronautas

ArchivoAstronauta archiAstro("astronauta.dat");
Astronauta objastro;
int cantRegAstro=archiAstro.contarRegistros();

int Categoria[15]={};

for(int i=0; i<cantRegAstro; i++){
    objastro=archiAstro.leerRegistro(i);
    
  Categoria[objastro.getCategoria() -1]++;
}

int mayorCategoria= Categoria[0];
int posMayor=0;
        for(int x=0; x<15; x++){
        
        if(Categoria[x] > mayorCategoria){      ///Error encontrado: mayorCategoria > Categoria[x];
            mayorCategoria=Categoria[x];
            posMayor=x;
        }
        
    }
        cout << "LA MAYOR CATEGORIA ES: " << posMayor + 1;
}

