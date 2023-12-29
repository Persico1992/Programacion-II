
#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

#include "parcial2.h"


///a) Generar un archivo con el siguiente formato: Código de empresa, nombre, y cantidad de toneladas cosechadas.
class EmpresaNueva{

private:
   
    float toneladasCosechadas;
    char nombre[30],codEmpresa[6];
public:
    
    void setCodEmpresa(const char* ce){strcpy(codEmpresa,ce);}
    void setToneladasCosechadas(float tc){toneladasCosechadas=tc;}
    void setNombre(const char* n){strcpy(nombre,n);}
    
    const char* getCodEmpresa(){return codEmpresa;}
    float getToneladasCosechadas(){return toneladasCosechadas;}
    const char* getNombre(){return nombre;}
    
    void Mostrar(){
    cout << "COD EMPRESA: " << codEmpresa << endl;
    cout << "NOMBRE: " << nombre << endl;
    cout << "TONELADAS COSECHADAS: " << toneladasCosechadas << endl;
  
    
    }
        ///PUNTO E
        bool operator == (EmpresaNueva objEm){
        if(strcmp(codEmpresa , objEm.getCodEmpresa())== 0) return true;
        return false;
        }
};

class ArchivoNuevoPuntoA{

private:
        char nombre[30];
public:
       ArchivoNuevoPuntoA (const char* n){strcpy (nombre,n);}

    EmpresaNueva leerRegistro(int pos){
    EmpresaNueva objEmpresaNueva;   
    FILE *p;
    p= fopen(nombre,"rb"); 
        if(p==NULL) return objEmpresaNueva;
    fseek (p,sizeof objEmpresaNueva*pos,0);     
    fread (&objEmpresaNueva,sizeof objEmpresaNueva, 1, p);
        fclose(p);
    return objEmpresaNueva;
    }
    
     int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(EmpresaNueva);
    }
    
    int agregarRegistros(EmpresaNueva objEmpresaNueva){
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int valor=fwrite(&objEmpresaNueva, sizeof objEmpresaNueva,1,p);
        fclose(p);
        return valor;
    
    }
    
    int mostrarRegistros(){
        EmpresaNueva read;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        while(fread(&read,sizeof read,1,p)== 1){
            read.Mostrar();
            cout << endl;
        }
    }
};

void PuntoA(){

ArchivoNuevoPuntoA archiNuevoPuntoA("P1.dat");
EmpresaNueva objEmpresaNueva;

ArchivoEmpresa archiEmpresa;
Empresa objEmpresa;

ArchivoCosecha archiCosecha;
Cosecha objCosecha;

int cantRegistroE=archiEmpresa.contarRegistros();
int cantRegistroC=archiCosecha.contarRegistros();
 
    
for(int i=0; i<cantRegistroE; i++){
    objEmpresa=archiEmpresa.leerRegistro(i);
  float cantTone=0;
    for(int x=0; x<cantRegistroC; x++){
    objCosecha=archiCosecha.leerRegistro(x);
            
            
            if(strcmp(objCosecha.getCodigoEmpresa(),objEmpresa.getCodigoEmpresa())== 0){
                cantTone += objCosecha.getToneladasCosechadas();
    }
    
    
           
    }
            if(cantTone > 0){
            objEmpresaNueva.setCodEmpresa(objEmpresa.getCodigoEmpresa());   
            objEmpresaNueva.setNombre(objEmpresa.getNombre());   
            objEmpresaNueva.setToneladasCosechadas(cantTone);
            archiNuevoPuntoA.agregarRegistros(objEmpresaNueva); 
            }
            
}
 archiNuevoPuntoA.mostrarRegistros();
}

///b) El dia con mayor cantidad de toneladas cosechadas de cereal de tipo 10. (SE CAMBIA MES POR DIA)
void PuntoB(){
ArchivoCosecha archiCose;
Cosecha objCosecha;
int cantRegCoseche=archiCose.contarRegistros();
float vDia[31]={};

for(int i=0; i<cantRegCoseche; i++){
        objCosecha=archiCose.leerRegistro(i);
        
        if(objCosecha.getCodigoCereal() == 10){
            vDia[objCosecha.getFecha().getDia() -1] += objCosecha.getToneladasCosechadas();
        }
    
    
    }
    
    float maxTone=0;
    int posMax=0;
    
    for(int i=0; i<31; i++){
        
        if(vDia[i] > maxTone){
            maxTone=vDia[i];
            posMax=i;
        }
        
    }
    
    cout << "La mayor cantidad de toneladas cosechadas de cereal de tipo 10 es el dia: " << posMax +1 << endl;
}

///c) Utilizar asignación dinámica de memoria en la resolución del punto a
void PuntoC(){

ArchivoNuevoPuntoA archiPa("P1.dat");
EmpresaNueva *vP1, objEmp;

int cantRegP1=archiPa.contarRegistros();

    if(cantRegP1 == 0){
        cout << "NO HAY REGISTROS EN EL ARCHIVO." << endl;
        return;
    }
    
    vP1= new EmpresaNueva[cantRegP1];
        if(vP1 == NULL) return;
        
for(int i=0; i<cantRegP1; i++){
    vP1[i]=archiPa.leerRegistro(i);
    
}

for(int x=0; x<cantRegP1; x++){
            vP1[x].Mostrar();
            cout << endl;
}
    delete vP1;

}


///************************************************************
///d) Modificar el archivo cosecha.dat, pasando el valor actual del campo cantidad de toneladas a su equivalente en kilos.
 
 ///ESTA FUNCION LA AGREGUE AL .h
  /*  bool modificarRegistro(Cosecha obj, int pos) {
    FILE* p = fopen("cosecha.dat", "rb+");
    if (p == NULL) {
        return false;
    }
    fseek(p, pos * sizeof(Cosecha), SEEK_SET);
    bool pudoEscribir = fwrite(&obj, sizeof(Cosecha), 1, p);
    fclose(p);
    return pudoEscribir;
  }
    */     


void PuntoD(){
ArchivoCosecha archiC;
Cosecha objCosecha;
int cantRegCosecha=archiC.contarRegistros();

archiC.listarArchivo(); ///Vemos los datos como están, antes de pasarlos a kilos.
system("pause");
cout << endl;
cout << "TOQUE UNA TECLA NUEVAMENTE PARA PASAR LOS DATOS A TONELADAS." << endl;
for(int i=0; i<cantRegCosecha; i++){
    objCosecha=archiC.leerRegistro(i);
    
    float toneladas= objCosecha.getToneladasCosechadas();
    objCosecha.setToneladasCosechadas(toneladas*1000);
    archiC.modificarRegistro(objCosecha,i);
    
    cout <<"***********************" << endl;
    archiC.mostrarRegistros();  ///Mostramos los archivos actualizados con los kilos ya
    }

}


int menuConsignas()
{
    int opc;
    system("cls");
    while(true){
    cout<<"=== MODELO PARCIAL 2 - PROGRAMACION II ==="<<endl;
    cout<<"1. PUNTO A"<<endl;
    cout<<"2. PUNTO B"<<endl;
    cout<<"3. PUNTO C"<<endl;
    cout<<"4. PUNTO D"<<endl;
    cout<<"5. PUNTO E: Se realizo el punto en la clase del punto a"<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
        PuntoA();
        system("pause");
        system("cls");
        break;
    case 2:
        PuntoB();
        system("pause");
        system("cls");
        break;
    case 3:
        PuntoC();
        system("pause");
        system("cls");
        break;
    case 4:
        PuntoD();
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
ArchivoEmpresa archiEmpresa;
Empresa objEmpresa;
int agrego;
for(int  i=0; i<10; i++){
objEmpresa.Cargar();

agrego=archiEmpresa.escribirRegistro(objEmpresa);
system("pause");
if (agrego == 1){
                    cout << "SE AGREGO CORRECTAMENTE." << endl;
                }
                else {
                    cout << "REALIZA LA CARGA DE NUEVO." ;
                }
                system("pause");
       }         
                
                archiEmpresa.mostrarRegistros();

*/
 
	





cout << endl;
system ("pause");

	return 0;
}