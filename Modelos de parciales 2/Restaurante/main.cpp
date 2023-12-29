#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "parcial2.h"


///Puntos a resolver:
///Punto1


class Punto1{

private:
	int codRestaurante;
	char nombreRestaurante[30];
	int cantVentas;

public:
    Punto1(){}; //Constructor por Omision.
    Punto1(int codigo){ ///Constructor por parámetros para prueba del punto3
        codRestaurante=codigo;
    }
	void setCodRestaurante (int cr){codRestaurante= cr;}
	void setNombreRestaurante(const char* nr ){strcpy(nombreRestaurante,nr);}
	void setCantVentas(int cv){cantVentas=cv;}

	int getCodRestaurante(){return codRestaurante;}
	const char* getNombreRestaurante(){return nombreRestaurante;}
	int getCantVentas(){return cantVentas;}

	void Mostrar(){
		cout << "CODIGO RESTAURANTE: " << codRestaurante << endl;
		cout << "NOMBRE RESTAURANTE: " << nombreRestaurante << endl;
		cout << "CANTIDAD DE VENTAS: " << cantVentas << endl;

	}
//Punto 3 
/*Agregar una sobrecarga para el operador == de la clase nueva del punto 1, que reciba 
como parámetro un objeto de la misma clase*/

    bool operator == (Punto1 objP1){
        if(codRestaurante == objP1.getCodRestaurante()) return true;
            return false;
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

class Punto1Bis{
    private:
	int codRestaurante;
	char nombreRestaurante[30];
	int cantReservas;

public:
    /*Punto1(){}; //Constructor por Omision.
    Punto1(int codigo){ ///Constructor por parámetros para prueba del punto3
        codRestaurante=codigo;
    }*/
	void setCodRestaurante (int cr){codRestaurante= cr;}
	void setNombreRestaurante(const char* nr ){strcpy(nombreRestaurante,nr);}
	void setCantReservas(int cr){cantReservas=cr;}

	int getCodRestaurante(){return codRestaurante;}
	const char* getNombreRestaurante(){return nombreRestaurante;}
	int getCantReservas(){return cantReservas;}

	void Mostrar(){
		cout << "CODIGO RESTAURANTE: " << codRestaurante << endl;
		cout << "NOMBRE RESTAURANTE: " << nombreRestaurante << endl;
		cout << "CANTIDAD DE RESERVAS: " << cantReservas << endl;

	}


};
class ArchivoPunto1Bis{

private:                    
    char nombre[30];
public:
        ArchivoPunto1Bis(const char* n){strcpy (nombre,n);}    

    bool grabarRegistro(Punto1Bis reg){        
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
        bool mostrarRegistros(){
        Punto1Bis read;
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
        return tam/sizeof(Punto1Bis);
    }
    
    Punto1Bis leerRegistro(int pos){
        Punto1Bis reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Punto1Bis)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }


};


void SolucionPunto1();
void SolucionPunto2();
void SolucionPunto4();

int menuConsignas()
{
    int opc;
    system("cls");
    while(true){
    cout<<"=== PARCIAL 2 - PROGRAMACION II ==="<<endl;
    cout<<"1. PUNTO 1"<<endl;
    cout<<"2. PUNTO 2"<<endl;
    cout<<"3. PUNTO 4"<<endl;
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
        SolucionPunto4();
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


//PUNTO 3 verificacion:

/*Punto1 obj1(1), obj2(1);

if(obj1 == obj2){
    cout << "SON LOS MISMOS CODIGOS DE RESTAURANTE." << endl;
}
else{
    cout << "SON DISTINTOS CODIGOS." << endl;
}*/

cout << endl;
system ("pause");

	return 0;
}

//Punto 1: 
void SolucionPunto1(){

ArchivoVentas archiVentas("ventas.dat");
Venta objVenta;
int cantRegVentas=archiVentas.contarRegistros();

ArchivoRestaurantes archiRestau("restaurantes.dat");
Restaurante objRest;
int cantRegRes=archiRestau.contarRegistros();

ArchivoPunto1 archiP1("Punto1.dat");
Punto1 objP1;


for(int i=0; i<cantRegRes; i++){
	objRest=archiRestau.leerRegistro(i);
	int cantVentas=0;

			for(int x=0; x<cantRegVentas; x++){
						objVenta=archiVentas.leerRegistro(x);
																													//hay que cargar la fecha de la venta.
			if(objVenta.getCodigoRestaurante() == objRest.getCodigoRestaurante() && objRest.getCategoria() == 2 ) {	//&& objVenta.getFechaReserva().getAnio() == 2023//&& objVenta.getFechaReserva().getAnio() == 2023
			cantVentas++;

			}
				
		}				
            if(cantVentas > 0){
				objP1.setCodRestaurante(objRest.getCodigoRestaurante());
				objP1.setNombreRestaurante(objRest.getNombre());
				objP1.setCantVentas(cantVentas);
			    archiP1.grabarRegistro(objP1);
            }
            
		}
			
        archiP1.mostrarRegistros();
}
//Punto2
void SolucionPunto2(){

ArchivoRestaurantes archiRestau("restaurantes.dat");
Restaurante objRest;
int cantRegRest=archiRestau.contarRegistros();

int Provincia[24]={0};
for(int i=0; i<cantRegRest; i++){
    objRest=archiRestau.leerRegistro(i);

        if(objRest.getCategoria() == 1){
            Provincia[objRest.getProvincia() -1]++;
        }

}
int minimaProv= Provincia[0];
int pos=0;
for (int x=0; x<24; x++){
    if(Provincia[x] < minimaProv){
        minimaProv= Provincia[x];
        pos=x;
    }

}
cout << "LA PROVINCIA CON MENOS CANTIDAD DE RESTAURANTE DE CATEGORIA 1, ES LA NUMERO: " << pos << endl;


}

//PUNTO4
//Crear un vector dinámico para copiar y mostrar el archivo creado en el punto 1
void SolucionPunto4(){
    ArchivoPunto1 archiP1("Punto1.dat");
    Punto1 objP1, *vP1;
int cantRegP1=archiP1.contarRegistros();

    if(cantRegP1 == 0){
        cout << "NO HAY REGISTROS EN EL ARCHIVO." << endl;
        return;
    }

    vP1=new Punto1[cantRegP1];
    if(vP1 == NULL){
        cout << "ERROR AL CREAR EL VECTOR." << endl;
    }
    for (int i=0; i<cantRegP1; i++){
       
        vP1[i]=archiP1.leerRegistro(i);
    }
    for (int x=0; x<cantRegP1; x++){
        vP1[x].Mostrar();
    }
    delete vP1;
}
