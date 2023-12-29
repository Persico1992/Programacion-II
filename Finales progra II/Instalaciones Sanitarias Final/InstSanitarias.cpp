
#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;



class Fecha{
    private:
        int dia, mes, anio;
    public:
        void Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;
        }
        void Mostrar(){
            cout<<"DIA: "<<dia<<endl;
            cout<<"MES: "<<mes<<endl;
            cout<<"ANIO: "<<anio<<endl;
        }
        void mostrarEnLinea(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }

        void setDia(int d){
            if(d>=1 && d<=31) dia=d;
            else dia=-1;
        }
        void setMes (int m){
            if (m>=1 && m<=12) mes=m;
            else mes= -1;
        }
        
        void setAnio(int a){
            anio= a;
        }
        
        
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
       
};

void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}
///En el final el profe pide hacer todo en un .cpp, sin .h

class Tecnicos{

private:
    int DNI, puesto;
    char nombre[50], apellido[50];
    float sueldo;
    Fecha fechaIngreso;
    
public:
    
    void Cargar();
    void Mostrar();
    
    void setDNI(int d){DNI=d;}
    void setPuesto(int p){puesto=p;}
    void setNombre(const char* n){strcpy(nombre,n);}
    void setApellido(const char* ap){strcpy(apellido,ap);}
    void setSueldo(float s){sueldo=s;}
    void setFechaIngreso(Fecha fi){fechaIngreso=fi;}
    
    int getDNI(){return DNI;}
    int getPuesto(){return puesto;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    float getSueldo (){return sueldo;}
    Fecha getFechaIngreso(){return fechaIngreso;}
};

void Tecnicos::Cargar(){

cout << "INGRESE LOS DATOS DE LOS TÉCNICOS: " << endl;
cout << "*********************************" << endl;

cout << "DNI: " << endl;
cin >> DNI;
cout << "NOMBRE: " << endl;
cargarCadena(nombre,49);
cout << "APELLIDO: " << endl;
cargarCadena(apellido,49);
cout << "PUESTO: (1 a 10) " << endl;
cin >> puesto;
cout << "SUELDO: $" << endl;
cin >> sueldo;
cout << "FECHA DE INGRESO: " << endl;
fechaIngreso.Cargar();
}

void Tecnicos::Mostrar(){

cout << "DNI: " << DNI << endl;
cout << "NOMBRE: " << nombre << endl;
cout << "APELLIDO: " << apellido << endl;
cout << "PUESTO: " << puesto << endl;
cout << "SUELDO: $" << sueldo << endl;
cout << "FECHA DE INGRESO: " << endl;
fechaIngreso.mostrarEnLinea();
}

class ArchivoTecnicos{

private:                    
    char nombre[30];
public:
        ArchivoTecnicos(const char* n){strcpy (nombre,n);}    

         bool grabarRegistro(Tecnicos reg){        
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
        bool mostrarRegistros(){
        Tecnicos read;
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
        return tam/sizeof(Tecnicos);
    }
    
    Tecnicos leerRegistro(int pos){
        Tecnicos reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Tecnicos)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

};

class TecnicosObras{

private:
    int numObra, dniTecnico, tipo;
    Fecha fechaInicio;
    
public:
    
    void Cargar();
    void Mostrar();
    
    void setNumObra(int no){numObra=no;}
    void setDniTecnico(int dt){dniTecnico= dt;}
    void setTipo(int t){tipo=t;}
    void setFechaInicio(Fecha ini){fechaInicio=ini;}
    
    int getNumObra(){return numObra;}
    int getDniTecnico(){return dniTecnico;}
    int getTipo(){return tipo;}
    Fecha getFechaInicio(){return fechaInicio;}

};

void TecnicosObras::Cargar(){

cout << "INGRESE LOS DATOS DE TECNICOS OBRAS: " << endl;
cout << "************************************ " << endl;

cout << "NUMERO OBRA: " << endl;
cin >> numObra;
cout << "DNI DEL TÉCNICO: " << endl;
cin >> dniTecnico;
cout << "TIPO: (1 a 5) " << endl;
cin >> tipo;
cout << "FECHA DE INICIO: " << endl;
fechaInicio.Cargar();

}

void TecnicosObras::Mostrar(){

cout << "********************************** "  << endl;

cout << "NUMERO OBRA: " << numObra << endl;
cout << "DNI DEL TECNICO: " << dniTecnico << endl;
cout << "TIPO: " << tipo << endl;
cout << "FECHA DE INICIO: " << endl;
fechaInicio.mostrarEnLinea();
}

class ArchivoTecnicosObra{

private:                    
    char nombre[30];
public:
        ArchivoTecnicosObra(const char* n){strcpy (nombre,n);}    

         bool grabarRegistro(TecnicosObras reg){        
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
        bool mostrarRegistros(){
        TecnicosObras read;
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
        return tam/sizeof(TecnicosObras);
    }
    
    TecnicosObras leerRegistro(int pos){
        TecnicosObras reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(TecnicosObras)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

};
/***********************************************************************************************************/
///PUNTOS A DESARROLLAR.
///a) Generar un archivo nuevo con el siguiente formato de registro: DNI, nombre y apellido de los técnicos y cantidad de obras de tipo 1 en las que haya participado. (3 puntos).

class Punto1{

private:
    int DNI;
    char nombre[50];
    char apellido[50];
    int cantObras;
    
public:
    void setDNI(int d){DNI=d;}
    void setNombre(const char* n){strcpy(nombre,n);}
    void setApellido(const char* ap){strcpy(apellido,ap);}
    void setCantObras(int co){cantObras=co;}
    
    int getDNI(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    int getCantObras(){return cantObras;}
    
    void Mostrar(){
        cout << "DNI: " << DNI << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "APELLIDO: " << apellido << endl;
        cout << "CANTIDAD OBRAS TIPO 1: " << cantObras << endl;
    }
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

void SolucionPunto1(){

ArchivoTecnicos archiTec("tecnicos.dat");
Tecnicos objTec;
int cantRegTec=archiTec.contarRegistros();

ArchivoTecnicosObra archiTecObra("tecnicosObra.dat");
TecnicosObras objTecObra;
int cantRegTecObra=archiTecObra.contarRegistros();

ArchivoPunto1 archiP1("p1.dat");
Punto1 objP1;
int contTipo1;

for (int i=0; i<cantRegTec; i++){
    objTec=archiTec.leerRegistro(i);
    contTipo1=0;
    
    for(int x=0; x<cantRegTecObra; x++){
        objTecObra=archiTecObra.leerRegistro(x);
        
        
        if(objTec.getDNI() == objTecObra.getDniTecnico() && objTecObra.getTipo() == 1){
                contTipo1++;
            
        }
               
        
    }
                    if(contTipo1 >0){
                    objP1.setDNI(objTec.getDNI());
                    objP1.setNombre(objTec.getNombre());
                    objP1.setApellido(objTec.getApellido());
                    objP1.setCantObras(contTipo1);
                    archiP1.grabarRegistro(objP1);
                    
                    
                    
                }
    
}

archiP1.mostrarRegistros();

}

//b) La cantidad de técnicos en cada puesto (3 puntos).
void SolucionPunto2(){
ArchivoTecnicos archiTec("tecnicos.dat");
Tecnicos objTec;
int cantRegTec=archiTec.contarRegistros();

int cantTecnicosPorPuesto[10]={0};

for (int x=0; x<cantRegTec; x++){
    objTec=archiTec.leerRegistro(x);
    
    if(objTec.getPuesto() >= 1 && objTec.getPuesto() <= 10){
    cantTecnicosPorPuesto[objTec.getPuesto() -1]++;
    }
    
}
int posPuesto=0;
cout << "LA CANTIDAD DE TÉCNICOS PARA LOS PUESTOS: " << endl;
for (int i=0; i<10; i++){
      
        
        cout <<  "Puesto " << i+1 << ": " << cantTecnicosPorPuesto[i] << endl;
    
}
   
}

//c) Generar un archivo nuevo con el siguiente formato de registro: DNI, nombre y apellido de los técnicos que hayan participado de alguna obra este año. (3 puntos).
class Punto3{

private:
    int DNI;
    char nombre[50];
    char apellido[50];
    
    
public:
    void setDNI(int d){DNI=d;}
    void setNombre(const char* n){strcpy(nombre,n);}
    void setApellido(const char* ap){strcpy(apellido,ap);}
   
    
    int getDNI(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    
    
    void Mostrar(){
        cout << "DNI: " << DNI << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "APELLIDO: " << apellido << endl;
        
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
ArchivoTecnicos archiTec("tecnicos.dat");
Tecnicos objTec;
int cantRegTec=archiTec.contarRegistros();

ArchivoTecnicosObra archiTecObra("tecnicosObra.dat");
TecnicosObras objTecObra;
int cantRegTecObra=archiTecObra.contarRegistros();

ArchivoPunto3 archiP3("p3.dat");
Punto3 objP3;


for (int i=0; i<cantRegTec; i++){
        objTec=archiTec.leerRegistro(i);
    bool participo=false;
    
    for(int x=0; x<cantRegTecObra; x++){
        objTecObra=archiTecObra.leerRegistro(x);
        
        if(objTec.getDNI() == objTecObra.getDniTecnico() && objTecObra.getFechaInicio().getAnio() == 2023){
                    objP3.setDNI(objTec.getDNI());
                    objP3.setNombre(objTec.getNombre());
                    objP3.setApellido(objTec.getApellido());
                    participo=true;
        }
                
    }              
                    if(participo){
                    objP3.setDNI(objTec.getDNI());
                    objP3.setNombre(objTec.getNombre());
                    objP3.setApellido(objTec.getApellido());
                    archiP3.grabarRegistro(objP3);
                }
}
        archiP3.mostrarRegistros();
}

///d) El mes del 2022 en el que se registraron más ingresos de técnicos (3 puntos).
void SolucionPunto4(){
ArchivoTecnicos archiTec("tecnicos.dat");
Tecnicos objTec;
int cantRegTec=archiTec.contarRegistros();

int vMes[12]={0};
    
    for(int i=0; i<cantRegTec; i++){
        objTec=archiTec.leerRegistro(i);
        
        if(objTec.getFechaIngreso().getAnio() == 2022){
            vMes[objTec.getFechaIngreso().getMes() -1]++;
        
        }
            
    }
    
    int MayorMes= vMes[0];
    int posMes=0;
    for(int x=0; x<12; x++){
        
        if(vMes[x] > MayorMes){
            MayorMes=vMes[x];
            posMes=x;
        }
    }
        cout << "EL MAYOR MES CON MAS INGRESOS DE TÉCNICOS ES EL : " << posMes+1 << endl;
}
int menuConsignas()
{
    ArchivoTecnicos archiTec("tecnicos.dat");
    Tecnicos objTec;
    ArchivoTecnicosObra archiTecObra("tecnicosObra.dat");
    TecnicosObras objTecObra;
    
    int agrego;
    int opc;
    system("cls");
    while(true){
    cout<<"=== FINAL - PROGRAMACION II ==="<<endl;
    cout<<"1. CARGA DE TÉCNICOS + AGREGAR AL .DAT "<<endl;
    cout<<"2. LISTAR TÉCNICOS "<<endl;
    cout<<"3. CARGA DE TÉCNICOS EN OBRAS + AGREGAR AL .DAT"<<endl;
    cout<<"4. LISTAR TÉCNICOS EN OBRAS."<<endl;
    cout<<"5. SOLUCIÓN PUNTO A."<<endl;
    cout<<"6. SOLUCIÓN PUNTO B."<<endl;
    cout<<"7. SOLUCIÓN PUNTO C."<<endl;
    cout<<"8. SOLUCION PUNTO D."<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
        
        objTec.Cargar();
        archiTec.grabarRegistro(objTec);
        if(agrego == 1){
            cout << "SE AGREGO CORRECTAMENTE." << endl;
              system("pause");
        }
        else{
            cout << "FALLA AL AGREGAR REGISTRO." << endl;
              system("pause");
        }
        system("cls");
        break;
    case 2:
        
        archiTec.mostrarRegistros();
        
        system("pause");
        system("cls");
       
        break;
    case 3:
        objTecObra.Cargar();
       agrego= archiTecObra.grabarRegistro(objTecObra);
        if(agrego == 1){
            cout << "SE AGREGO CORRECTAMENTE." << endl;
              system("pause");
        }
        else{
            cout << "FALLA AL AGREGAR REGISTRO." << endl;
              system("pause");
        }
        system("cls");
       
        break;
    case 4:
        cout << "MUESTRA DE DATOS DE TECNICOS OBRAS: " << endl;
        archiTecObra.mostrarRegistros();
        system("pause");
        system("cls");
        break;
    
    case 5:
        cout << "PUNTO A." << endl;
        SolucionPunto1();       ///OK
        system("pause");
        system("cls");
        break;
    case 6:
        cout << "PUNTO B." << endl;
        SolucionPunto2();       ///OK
        system("pause");
        system("cls");
        break;
    case 7:
        cout << "PUNTO C." << endl;
        SolucionPunto3();       ///OK
        system("pause");
        system("cls");
        break;
    case 8:
        cout << "PUNTO D." << endl;
        SolucionPunto4();       ///OK
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