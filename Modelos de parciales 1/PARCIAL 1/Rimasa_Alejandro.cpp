//Nombre:Rimasa Alejandro
//Tp: Parcial 1 - Programación 2


#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#include "parcial1l.h"

///Punto1
//Generar un archivo con los DOCENTE que participan de equipos de nivel inicial. Cada registro del archivo nuevo debe tener el siguiente formato:
//DNI, nombre, apellido y fecha de inscripción

class DocentesInicial{

private:
    int DNI;
    char nombre[25], apellido[30];
    Fecha fechaInscripcion;
    
    
public:
    void setDni(int d){DNI= d;}
    void setNombre (const char* n){strcpy(nombre,n);}
    void setApellido (const char* a){strcpy(apellido,a);}
    void setFechaInscripcion (Fecha fi){fechaInscripcion= fi;}  
    
    int getDni(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    Fecha getFechaInscripcion(){return fechaInscripcion;}
   
    void mostrar(){
    
    cout << "DNI: " << DNI << endl  ;
    cout << "NOMBRE: " << nombre << endl;
    cout << "APELLIDO: " << apellido << endl;
    cout << "FECHA INSCRIPCION: " ;
        fechaInscripcion.Mostrar()  ;
    
    }
};

class ArchivoDocentesInicial{

 private:
        char nombre[30];
        
    public:
        ArchivoDocentesInicial(const char* n){strcpy (nombre,n);}
        
        DocentesInicial leerRegistro(int pos){
        DocentesInicial reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p,sizeof(DocentesInicial)*pos,0);
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
        return tam/sizeof(DocentesInicial);
    }
    int agregarRegistros(DocentesInicial Docente){ 
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int valor=fwrite(&Docente, sizeof Docente,1,p);
        fclose(p);
        return valor;
    
    }
    int mostrarRegistros(){
        DocentesInicial read;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        while(fread(&read,sizeof read,1,p)== 1){
            read.mostrar();
            cout << endl;
        }
    }




};

void Punto1Parcial(){

ArchivoDocentesInicial archiDocentesIni("Punto1.dat");
DocentesInicial objDocentes;
ArchivoJugadores archiJugadores("jugadores.dat");
Jugador objJugador;    
ArchivoEquipos archiEquipos("equipos.dat");
Equipo objEquipo;


int cantRegistroJ=archiJugadores.contarRegistros();
int cantRegistroE=archiEquipos.contarRegistros();


for(int i=0; i<cantRegistroJ; i++){
        objJugador=archiJugadores.leerRegistro(i);
        
        for(int x=0; x<cantRegistroE; x++){
        objEquipo=archiEquipos.leerRegistro(x);
        
           if(objJugador.getIdEquipo() == objEquipo.getIdEquipo() && objJugador.getClaustro() == 1 && objJugador.getEstado() && objEquipo.getEstado()){ 
            objDocentes.setDni(objJugador.getDNI());
            objDocentes.setNombre(objJugador.getNombre());
            objDocentes.setApellido(objJugador.getApellido());
            objDocentes.setFechaInscripcion(objJugador.getFechaInscirpcion());
            
            archiDocentesIni.agregarRegistros(objDocentes);
            
        }
        
    }
        
    
}    
    archiDocentesIni.mostrarRegistros();
}


///Punto1Bis
//Generar un archivo con los JUGADORES que participan de equipos de nivel inicial. Cada registro del archivo nuevo debe tener el siguiente formato:
//DNI, nombre, apellido y fecha de inscripción

class JugadoresInicial{

private:
    int DNI;
    char nombre[25], apellido[30];
    Fecha fechaInscripcion;
    
    
public:
    void setDni(int d){DNI= d;}
    void setNombre (const char* n){strcpy(nombre,n);}
    void setApellido (const char* a){strcpy(apellido,a);}
    void setFechaInscripcion (Fecha fi){fechaInscripcion= fi;}  
    
    int getDni(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    Fecha getFechaInscripcion(){return fechaInscripcion;}
   
    void mostrar(){
    
    cout << "DNI: " << DNI << endl  ;
    cout << "NOMBRE: " << nombre << endl;
    cout << "APELLIDO: " << apellido << endl;
    cout << "FECHA INSCRIPCION: " ;
        fechaInscripcion.Mostrar()  ;
    
    }
};

class ArchivoJugadoresInicial{

 private:
        char nombre[30];
        
    public:
        ArchivoJugadoresInicial(const char* n){strcpy (nombre,n);}
        
        JugadoresInicial leerRegistro(int pos){
        JugadoresInicial reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p,sizeof(JugadoresInicial)*pos,0);
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
        return tam/sizeof(JugadoresInicial);
    }
    int agregarRegistros(JugadoresInicial Docente){ 
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int valor=fwrite(&Docente, sizeof Docente,1,p);
        fclose(p);
        return valor;
    
    }
    int mostrarRegistros(){
        JugadoresInicial read;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        while(fread(&read,sizeof read,1,p)== 1){
            read.mostrar();
            cout << endl;
        }
    }

};
    
void SolucionPunto1Bis(){


ArchivoJugadores archiJugadores("jugadores.dat");
Jugador objJugador;    
ArchivoEquipos archiEquipos("equipos.dat");
Equipo objEquipo;
ArchivoJugadoresInicial archiJugadoresIni("Punto1Bis.dat");
JugadoresInicial objJugadorIni;

int cantRegistroJ=archiJugadores.contarRegistros();
int cantRegistroE=archiEquipos.contarRegistros();


for(int i=0; i<cantRegistroJ; i++){
        objJugador=archiJugadores.leerRegistro(i);
        
        for(int x=0; x<cantRegistroE; x++){
        objEquipo=archiEquipos.leerRegistro(x);
        
           if(objJugador.getIdEquipo() == objEquipo.getIdEquipo() && objEquipo.getNivel() == 1 && objJugador.getEstado() && objEquipo.getEstado()){ 
            objJugadorIni.setDni(objJugador.getDNI());
            objJugadorIni.setNombre(objJugador.getNombre());
            objJugadorIni.setApellido(objJugador.getApellido());
            objJugadorIni.setFechaInscripcion(objJugador.getFechaInscirpcion());
            
            archiJugadoresIni.agregarRegistros(objJugadorIni);
            
        }
        
    }
        
    
}    
    archiJugadoresIni.mostrarRegistros();
}


///Punto2
//Generar un archivo con los NO DOCENTES de deportes pertenecientes a la categoria de deporte 5.
//Cada registro del archivo nuevo debe tener el siguiente formato.
//DNI, nombre, apellido y fecha de inscripción

class NoDocentesCat5{

private:
    int DNI;
    char nombre[25], apellido[30];
    Fecha fechaInscripcion;
    
    
public:
    void setDni(int d){DNI= d;}
    void setNombre (const char* n){strcpy(nombre,n);}
    void setApellido (const char* a){strcpy(apellido,a);}
    void setFechaInscripcion (Fecha fi){fechaInscripcion= fi;}  
    
    int getDni(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    Fecha getFechaInscripcion(){return fechaInscripcion;}
   
    void mostrar(){
    
    cout << "DNI: " << DNI << endl  ;
    cout << "NOMBRE: " << nombre << endl;
    cout << "APELLIDO: " << apellido << endl;
    cout << "FECHA INSCRIPCION: " ;
        fechaInscripcion.Mostrar()  ;
    
    }
};

class ArchivoNoDocentesCat5{

 private:
        char nombre[30];
        
    public:
        ArchivoNoDocentesCat5(const char* n){strcpy (nombre,n);}
        
        NoDocentesCat5 leerRegistro(int pos){
        NoDocentesCat5 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p,sizeof(NoDocentesCat5)*pos,0);
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
        return tam/sizeof(NoDocentesCat5);
    }
    int agregarRegistros(NoDocentesCat5 Docente){ 
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int valor=fwrite(&Docente, sizeof Docente,1,p);
        fclose(p);
        return valor;
    
    }
    int mostrarRegistros(){
        NoDocentesCat5 read;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        while(fread(&read,sizeof read,1,p)== 1){
            read.mostrar();
            cout << endl;
        }
    }

};

SolucionPunto2(){

ArchivoJugadores archiJugadores("jugadores.dat");
Jugador objJugador;    
ArchivoDeportes archiDepo("deportes.dat");
Deporte objDeporte;
ArchivoNoDocentesCat5 archiNoDocente("Punto2.dat");
NoDocentesCat5 objNoDocente;

int cantRegistroJ=archiJugadores.contarRegistros();
int cantRegistroD=archiDepo.contarRegistros();

for(int i=0; i<cantRegistroJ; i++){
    objJugador=archiJugadores.leerRegistro(i);
    
    int agrego;
    for(int x=0; x<cantRegistroD; x++){
    objDeporte=archiDepo.leerRegistro(x);
    
    if(objJugador.getIdDeporte() == objDeporte.getIdDeporte() && objJugador.getClaustro() == 3 && objDeporte.getIdCtegoria() == 5 && objJugador.getEstado() && objDeporte.getEstado()){
        
            objNoDocente.setDni(objJugador.getDNI());
            objNoDocente.setNombre(objJugador.getNombre());
            objNoDocente.setApellido(objJugador.getApellido());
            objNoDocente.setFechaInscripcion(objJugador.getFechaInscirpcion());
            
            agrego=archiNoDocente.agregarRegistros(objNoDocente);
            
            
           
      }
       

    }
           
        archiNoDocente.mostrarRegistros();
    }
}


  int menuConsignas()
{
    int opc;
    system("cls");
    while(true){
    cout<<"=== PARCIAL 2 - PROGRAMACION II ==="<<endl;
    cout<<"1. PUNTO1"<<endl;
    cout<<"2. PUNTO1BIS"<<endl;
    cout<<"3. PUNTO2 - (Este punto no tiene información en los .dat)"<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese la opcion:"<<endl;
    cout << "-----------------------------" << endl;
    cin>>opc;
    cout << "-----------------------------" << endl;
    switch(opc)
    {
    case 1:
        Punto1Parcial();
        system("pause");
        system("cls");
        
        break;
    case 2:
        SolucionPunto1Bis();
        system("pause");
        system("cls");
        break;
    case 3:
       SolucionPunto2();
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