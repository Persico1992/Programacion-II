#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#include "ModeloParcial.h"


class Punto1{

private:
    int codSorteo, numGanador, mes, codProvincia;
    
public:
    void setCodSorteo(int cs){codSorteo=cs;}
    void setNumGanador(int ng){numGanador=ng;}
    void setMes(int m){mes=m;}
    void setCodProv(int cp){codProvincia=cp;}
    
    int getCodSorte(){return codSorteo;}
    int getNumGanador(){return numGanador;}
    int getMes(){return mes;}
    int getCodProv(){return codProvincia;}
    
    void Mostrar(){
        cout << "CODIGO DE SORTEO: " << codSorteo <<endl;
        cout << "NUMERO GANADOR: " << numGanador <<endl;
        cout << "MES: " << mes <<endl;
        cout << "CODIGO PROVINCIA: " << codProvincia <<endl;
    
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

ArchivoSorteo archiSorteo("sorteo.dat");
Sorteo objSorteo;
int cantRegSorteo= archiSorteo.contarRegistros();

ArchivoBillete archiBillete("billete.dat");
Billete objBillete;
int cantRegBillete= archiBillete.contarRegistros();

ArchivoPunto1 archiP1("Punto1.dat");
Punto1 objP1;
    
    for (int i=0; i<cantRegSorteo; i++){
        objSorteo=archiSorteo.leerRegistro(i);
    bool noHuboGanadores=false;
    
    for(int x=0; x<cantRegBillete; x++){
        objBillete=archiBillete.leerRegistro(x);
        
                    if(objSorteo.getCodigoSorteo() == objBillete.getCodigoSorteo() && objSorteo.getNumGanador() == objBillete.getNumero()){
                            objP1.setCodSorteo(objSorteo.getCodigoSorteo());
                            objP1.setNumGanador(objSorteo.getNumGanador());
                            objP1.setMes(objSorteo.getMesSorteo());
                            objP1.setCodProv(objBillete.getCodProvincia());
                            noHuboGanadores=true;
                    }
                     
        }        
                        if(noHuboGanadores){
                        archiP1.grabarRegistro(objP1);
                    }
                   
    }
        archiP1.mostrarRegistros();
}


void PuntoBSorteo(){
ArchivoBillete archiBillete("billete.dat");
Billete objBillete;
int mMesesYProvincia[12][24]={};
int cantRegistrosB=archiBillete.contarRegistros();
int pos=0;

while(pos<cantRegistrosB){
    objBillete=archiBillete.leerRegistro(pos);
    
        mMesesYProvincia[objBillete.getMes() -1][objBillete.getCodProvincia() -1]++; 
    
   pos++;
    }
        for(int i=0; i<12; i++){
            for(int j=0; j<24; j++){
                
              if(mMesesYProvincia > 0)
                
                cout << "MES " << i+1 << " EN LAS PROVINCIAS " << j+1 << " CON VENTAS : " << mMesesYProvincia[i][j] << endl ;
            }
    }
}


/*
c) Calcular e informar la ganancia/pérdida obtenida por la lotería por
cada sorteo (la ganancia o pérdida surge de suma de los precios
de los billetes-importe premio).*/
void PuntoCSorteo(){

ArchivoSorteo archiSorteo("sorteo.dat");
Sorteo objSorteo;
int cantRegSorteo=archiSorteo.contarRegistros();

ArchivoBillete archiBillete("billete.dat");
Billete objBillete;
int cantRegBillete=archiBillete.contarRegistros();

float premioSorteo=0;
float precioBillete=0;
float gananciaPerdida=0;

for(int i=0; i<cantRegSorteo; i++){
     objSorteo=archiSorteo.leerRegistro(i);
    
     premioSorteo+= objSorteo.getImporte();
     
        for(int x=0; x<cantRegBillete; x++){
             objBillete=archiBillete.leerRegistro(x);
            
            if(objBillete.getCodigoSorteo() == objSorteo.getCodigoSorteo())
                precioBillete+=objBillete.getPrecio();
                
                
        }
        
            
            
}              
        gananciaPerdida=precioBillete-premioSorteo;
        
        if(gananciaPerdida > 0){
            
            cout << "Hubo una ganancia de: " << gananciaPerdida << endl;
        }
        
        else{
            cout << "Hubo perdida en la agencia: " << gananciaPerdida << endl;
        }

}




int menuConsignas()
{
    
        ArchivoBillete archibi("billete.dat");
    int opc;
    system("cls");
    while(true){
    cout<<"=== MODELO PARCIAL 1 - PROGRAMACION II ==="<<endl;
    cout<<"1. PUNTO1"<<endl;
    cout<<"2. PUNTO2"<<endl;
    cout<<"3. PUNTO3"<<endl;
    cout<<"4. PUNTO3"<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
        cout << "--REGISTRO DE LOS GANADORES DEL SORTEO.--" << endl << endl;
        SolucionPunto1();
        system("pause");
        system("cls");
        
        break;
    case 2:
        PuntoBSorteo();
        system("pause");
        system("cls");
        break;
    case 3:
        PuntoCSorteo();
        system("pause");
        system("cls");
        break;
    case 4:
        archibi.listarArchivo();
        
    case 0:
        return 0;

    }

    }
}


int main(){
setlocale (LC_ALL, "Spanish");

menuConsignas();



/*
 ArchivoBillete archiBillete("billete.dat");
        archiBillete.listarArchivo();
system("pause");*/


cout << endl;
system ("pause");

	return 0;
}