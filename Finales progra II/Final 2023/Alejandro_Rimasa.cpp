//Nombre:Rimasa Alejandro
//Tp: Final Programación II


/*

*/

#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
Astronautas.dat: DNI (int), nombre y apellido (char[50]), país (entero entre 1 y 50), y categoría (1 a 15).
Misiones.dat: Número de misión, DNI del astronauta (int), fecha de inicio(día, mes y año), cargo (1 a 10).
*/


void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

class Fecha{
private:
    int dia,mes, anio;
public:
    void Cargar(){
        cin>>dia;
        cin>>mes;
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

///CLASES
class Astronauta{
    private:
    int DNI;
    char nombre[50], apellido[50];
    int pais; //entre 1 y 50
    int categoria; //entre 1 y 15

public:
    ///PUNTO3
    Astronauta();
    Astronauta( const char* n, const char* ap){
    strcpy(nombre,n);
    strcpy(apellido,ap);
    
    }
 
    ///setters 
    void setDNI(int d){DNI=d;}
    void setNombre(const char* n){strcpy(nombre,n);}
    void setApellido(const char* ap){strcpy(apellido,ap);}
    void setPais(int p){pais=p;}
    void setCategoria(int c){categoria=c;}
    
    int getDNI(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    int getPais(){return pais;}
    int getCategoria(){return categoria;}
    
    void Cargar();
    void Mostrar();

};

class Misiones{

private:
    int numMision, DNI;
    Fecha fechaInicio;
    int cargo;
    
public:
   
    void setNumMision(int nm){numMision=nm;}
    void setDNI(int d){DNI=d;}
    void setCargo(int c){cargo=c;}
    void setFechaInicio(Fecha fi){fechaInicio=fi;}
    
    int getNumMision(){return numMision;}
    int getDNI(){return DNI;}
    int getCargo(){return cargo;}
    Fecha getFechaInicio(){return fechaInicio;}
    
    void Cargar();
    void Mostrar();
};




///ARCHIVOS
class ArchivoAstronauta{
    private:
    char nombre[30];
public:
    ArchivoAstronauta(const char *n){
        strcpy(nombre, n);
    }
    Astronauta leerRegistro(int pos){
        Astronauta reg;
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
        return tam/sizeof(Astronauta);
    }
    bool grabarRegistro(Astronauta reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    
     bool mostrarRegistros(){
        Astronauta read;
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
       
class ArchivoMisiones{
    private:
    char nombre[30];
public:
    ArchivoMisiones(const char *n){
        strcpy(nombre, n);
    }
    Misiones leerRegistro(int pos){
        Misiones reg;
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
        return tam/sizeof(Misiones);
    }
    bool grabarRegistro(Misiones reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    
     bool mostrarRegistros(){
        Misiones read;
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

class Punto1{

private:
    int DNI;
    char nombre[50], apellido[50];
    
public:
        
        
    void setDNI (int d){DNI=d;}
    void setNombre (const char* n){strcpy(nombre,n);}
    void setApellido(const char* a){strcpy(apellido,a);}
    
    int getDNI(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}

    void Mostrar(){
        cout << "DNI: " << DNI << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "APELLIDO: " << apellido << endl;
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

///SOLUCIONES
void SolucionPunto1(){
ArchivoAstronauta archiAstro("astronauta.dat");
Astronauta objAstro;
int cantRegAstro=archiAstro.contarRegistros();

ArchivoMisiones archiMisiones("misiones.dat");
Misiones objMisiones;
int cantRegMisio= archiMisiones.contarRegistros();

ArchivoPunto1 archiP1("Punto1.dat");
Punto1 objP1;

for (int i=0; i<cantRegAstro; i++){
    objAstro=archiAstro.leerRegistro(i);
    bool participo=false;
    
    for(int x=0; x<cantRegMisio; x++){
        objMisiones=archiMisiones.leerRegistro(x);

        if(objAstro.getDNI() == objMisiones.getDNI() && objAstro.getPais() == 1){
                      participo=true;
        }
                        

        }               
                    
                       if(participo){
                objP1.setDNI(objAstro.getDNI());
                objP1.setNombre(objAstro.getNombre());
                objP1.setApellido(objAstro.getApellido());
                archiP1.grabarRegistro(objP1);
                        
                       }
                       
                    
                            
                        
    }
        archiAstro.mostrarRegistros();
}

///b) La categoría con menos astronautas (3 puntos).
void SolucionPunto2(){

ArchivoAstronauta archiAstro("astronauta.dat");
Astronauta objastro;
int cantRegAstro=archiAstro.contarRegistros();

int Categoria[15]={};

for(int i=0; i<cantRegAstro; i++){
    objastro=archiAstro.leerRegistro(i);
    
  Categoria[objastro.getCategoria() -1]++;
}

int menorCategoria= Categoria[0];
int posMenor=0;

for(int x=0; x<15; x++){
        
        if( menorCategoria < Categoria[x] ){      
            menorCategoria=Categoria[x];
            posMenor=x;
        }
    }
    cout << "LA CATEGORIA CON MENOS ASTRONAUTAS ES LA NUMERO: " << posMenor + 1;
}

int menuConsignas()
{
    int opc;
    system("cls");
    while(true){
    cout<<"=== FINAL - PROGRAMACION II ==="<<endl;
    cout<<"1.PUNTO1 "<<endl;
    cout<<"2.PUNTO2"<<endl;
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