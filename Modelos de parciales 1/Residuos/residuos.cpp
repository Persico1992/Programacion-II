
#///NOMBRE: Alejandro Rimasa
///FECHA: 02/10/2023
///PARCIAL PROGRAMACION II

#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "recoleccion.h"
///a) La zona en la que se recolectó mayor cantidad de kilos en el año 2011.
void PuntoA1(){

ArchivoResiduos archiResiduos("residuoss.dat");
Residuo objResiduo;

int cantRegistros=archiResiduos.contarRegistros();
float codZonas[20]={};

for(int i=0; i<cantRegistros; i++){
    objResiduo=archiResiduos.leerRegistro(i);
    
            if( objResiduo.getFecha().getAnio() == 2011){
                codZonas[objResiduo.getCodigoZona() -1] += objResiduo.getCantidadKilos();
        }
    }
    
    int mayorZona = 0;
    float mayorKilosResiduos= 0;
    
    for(int x=0; x<20; x++){
        
        if(codZonas[x] > mayorKilosResiduos ){
            mayorKilosResiduos=codZonas[x];
            mayorZona=x;
        }
    }
    cout << "LA ZONA CON MAYOR KILOS EN EL ANIO 2011 FUE: " << mayorZona +1<< endl;
}

///b) Para cada camión, la cantidad de viajes que realizó por cada zona, cada mes del año 2011.

void PuntoB1(){
ArchivoResiduos archiResiduos("residuoss.dat");
Residuo objResiduo;
ArchivoCamiones archiCamiones("camiones.dat");
Camion objCamion;
int cantRegistrosR=archiResiduos.contarRegistros();
int cantRegistrosC=archiCamiones.contarRegistros();
//int vCodZona[20]={};
//int vMeses[12]={};
int mContZonaMes[20][12]={};

for(int i=0; i<cantRegistrosC; i++){
        objCamion=archiCamiones.leerRegistro(i);
        

        for(int x=0; x<cantRegistrosR; x++){
            objResiduo=archiResiduos.leerRegistro(x);
    
            if(strcmp(objCamion.getCodigoCamion(),objResiduo.getCodigoCamion())== 0 && objResiduo.getFecha().getAnio() == 2011){
                mContZonaMes[objResiduo.getCodigoZona()-1][objResiduo.getFecha().getMes()-1]++;
                    
            }
        
        
    }
        
}
        
        for(int i=0; i<20; i++){
                        
                for(int j=0; j<12; j++){
                
                        if(mContZonaMes[i][j] > 0){
            
                        cout << "EN LA ZONA: " << i+1 << " PARA EL MES " << j+1 << " TIENE UN TOTAL DE VIAJES: " << mContZonaMes[i][j] << endl;
                    }
            
                }
            }
            
        }
        
///c) Generar un archivo con el código de centro, el nombre, la localidad y la cantidad de viajes de los camiones que hicieron a cada centro en el año 2011
//(cada registro debe tener los datos del centro y la cantidad de viajes que hicieron los camiones a ese centro).

class CantViajesCentro{
private:
    
    int codigoCentro;
    int cantViajes;
    char nombre[20];
    char localidad[20];
public:

    Mostrar(){
        cout << "Codigo de centro de recepcion: " << codigoCentro << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Localidad: " << localidad << endl;
        cout << "Cantidad de viajes: " << cantViajes << endl;
        cout << endl;
    }

    void setCodigoCentro(int c) { codigoCentro = c; }
    void setNombre(const char* n) { strcpy(nombre, n); }
    void setLocalidad(const char* l) { strcpy(localidad, l); }
    void setCantidadViajes(int cV) {cantViajes = cV; }

};

class ArchivoCantViajesCamiones{

private:
    char nombre[30];
public:
    ArchivoCantViajesCamiones(const char* n){strcpy (nombre,n);}

        CantViajesCentro leerRegistro(int pos){
        CantViajesCentro reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p,sizeof(CantViajesCentro)*pos,0);
        fread(&reg, sizeof reg,1,p);
        fclose(p);
        return reg;
        }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(CantViajesCentro);
    }
    int agregarRegistros(CantViajesCentro reg){
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int valor=fwrite(&reg, sizeof reg,1,p);
        fclose(p);
        return valor;
    
    }
    int mostrarRegistros(){
        CantViajesCentro read;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        while(fread(&read,sizeof read,1,p)== 1){
            read.Mostrar();
            cout << endl;
        }
    }

};

void PuntoC(){
ArchivoCantViajesCamiones archiCantV("viajesCamiones.dat");
CantViajesCentro objCantViajes;
ArchivoCentro archiCentro("centro.dat");
Centro objCentro;
ArchivoResiduos archiResiduos("residuoss.dat");
Residuo objResiduo;

int cantRegistrosR=archiResiduos.contarRegistros(); 
int cantRegistrosC=archiCentro.contarRegistros();
int cantViajes;
for(int i=0; i<cantRegistrosC; i++){
    objCentro=archiCentro.leerRegistro(i);
    
    cantViajes=0;
    
    for(int x=0; x<cantRegistrosR; x++){
        objResiduo=archiResiduos.leerRegistro(x);
        
        
        if(objCentro.getCodigoCentro() == objResiduo.getCodigoCentroRecepcion() && objResiduo.getFecha().getAnio() == 2011){
            
            cantViajes++;
        }
        
        
    }
            if(cantViajes > 0){
            objCantViajes.setNombre(objCentro.getNombre());
            objCantViajes.setCodigoCentro(objCentro.getCodigoCentro());
            objCantViajes.setLocalidad(objCentro.getLocalidad());
            objCantViajes.setCantidadViajes(cantViajes);
            archiCantV.agregarRegistros(objCantViajes);
        }
}
            archiCantV.mostrarRegistros();
}


int menuConsignas()
{
    int opc;
    system("cls");
    while(true){
    cout<<"=== MODELO PARCIAL 1 - PROGRAMACION II ==="<<endl;
    cout<<"1. PUNTO A"<<endl;
    cout<<"2. PUNTO B"<<endl;
    cout<<"3. PUNTO C"<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
        PuntoA1();
        system("pause");
        system("cls");
        break;
    case 2:
        PuntoB1();
        system("pause");
        system("cls");
        break;
    case 3:
        PuntoC();
        system("pause");
        system("cls");
        break;

    case 0:
        return 0;

    }

    }
}


int main () {


menuConsignas();

/* 
ArchivoCamiones archiCam("camiones.dat");
archiCam.listarArchivo();

ArchivoResiduos archiResi("residuoss.dat");
archiResi.listarArchivo();

ArchivoCentro archiCentro("centro.dat");
Centro objCentro;
objCentro.Cargar();
archiCentro.grabarRegistro(objCentro);
archiCentro.mostrarRegistros();
*/


return 0;
}
