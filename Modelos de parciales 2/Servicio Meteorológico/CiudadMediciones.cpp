///NOMBRE: 
///FECHA: 9/11/2022
///PARCIAL PROGRAMACION II

#include <iostream>
#include <iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#include "parcial2.h"

///PUNTO1 Generar un archivo con el siguiente formato: Código de ciudad, nombre, promedio de visibilidad.

class Punto1{

private:
    int codigoCiudad;
    char nombre[30];
    float promedioVisibilidad;
    
public:

    void Mostrar(){
        cout << "CODIGO DE CIUDAD: " << codigoCiudad << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "PROMEDIO DE VISIBILIDAD: " << promedioVisibilidad << endl;
    }

    
    void setCodigoCiudad(int codigo){codigoCiudad=codigo;}
    void setNombre(const char* n){strcpy(nombre, n);}
    void setPromedioVisibilidad(int pv){promedioVisibilidad= pv;}
};

class ArchivoPunto1{

private:
    char nombre[30];
public:
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

void SolucionPunto1(){

ArchivoCiudades archC;
Ciudades objCiudad;
int cantRegC=archC.contarRegistros();

ArchivoMediciones archM;
Mediciones objMedi;
int cantRegM=archM.contarRegistros();

ArchivoPunto1 archP1;
Punto1 objP1;

for(int i=0; i<cantRegC; i++){
    objCiudad=archC.leerRegistro(i);
    
    int cont=0;
    float acuPromVisibilidad=0;
    bool guardo= false;
    
    for(int x=0; x<cantRegM; x++){
        objMedi=archM.leerRegistro(x);
        
        if(objCiudad.getCodigoCiudad() == objMedi.getCiudad()){
            acuPromVisibilidad+=objMedi.getVisibilidad();
            cont++;
        guardo=true;
            
        }
        
    }
        if(guardo){
            objP1.setCodigoCiudad(objCiudad.getCodigoCiudad());
            objP1.setNombre(objCiudad.getNombre());
            objP1.setPromedioVisibilidad(acuPromVisibilidad/cont);
            archP1.grabarRegistro(objP1);
        }
    
        
}
archP1.mostrarRegistros();


}

///La cantidad de mediciones de cada grado de visibilidad por cada día del mes de mayo.
void SolucionPunto2(){

ArchivoMediciones archM;
Mediciones objMedi;
int cantRegMed=archM.contarRegistros();
int cantMediciones=0;
int mGradoVisibilidad[6][31]={};

for(int i=0; i<cantRegMed; i++){
    objMedi=archM.leerRegistro(i);
    
    if(objMedi.getFecha().getMes() == 5){
        
        mGradoVisibilidad[objMedi.getVisibilidad() -1][objMedi.getFecha().getDia() -1]++;
    }
}

for(int j=0; j<6; j++){
    
     //cout << "GRADO DE VISIBILIDAD: " << j  << endl;
    
    for(int x=0; x<31; x++){
        
        if(mGradoVisibilidad[j][x] > 0){
            
            cout << "PARA EL GRADO DE VISIBILIDAD " << j << " TIENE UNA CANTIDAD DE MEDICIONES DE: " << mGradoVisibilidad[j][x] << " PARA EL DIA " << x+1 << " DE MAYO."<< endl;
          }
          
          
      
        
        }
    }

}


int menuConsignas()
{
    int opc;
    system("cls");
    while(true){
    cout<<"=== MODELO PARCIAL 2 - PROGRAMACION II ==="<<endl;
    cout<<"1. PUNTO A: "<<endl;
    cout<<"2. PUNTO B:"<<endl;
    cout<<"3. "<<endl;
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
        
        system("pause");
        system("cls");
        break;
    case 4:
        
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

///Muestra de archivos Ciudades.
/*
ArchivoCiudades archC;
archC.mostrarRegistros();
///Muestra de archivos Mediciones.
ArchivoMediciones archm;
archm.mostrarRegistros();
*/

return 0;
}
