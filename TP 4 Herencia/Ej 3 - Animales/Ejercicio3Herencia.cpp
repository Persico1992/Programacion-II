//Nombre:
//Tp:
//Ejercicio N�:

/*
Peces, anfibios, reptiles, aves y mam�feros. Para los mam�feros se plantea la divisi�n entre terrestres y marinos.
Para todos los animales desea registrar lo siguiente: denominaci�n, tiempo de vida promedio, dimensi�n, peso, zona de h�bitat principal, tipo de
alimentaci�n y poblaci�n estimada.
La denominaci�n incluye: nombre cient�fico, nombre com�n, nombre dado por pueblos originarios
La dimensi�n establece valores de: largo, ancho, alto
*/

#include <iostream>
#include <locale.h>
#include <cstdlib>
using namespace std;

class Denominacion{

protected:
char nombreCientifico[50], nombreComun[30], nombrePorPueblosOriginarios[50];

public:
    void setNombreCientifico(const char* nc){strcpy(nombreCientifico,nc);}
    void setNombreComun(const char* nco){strcpy(nombreComun,nco);}
    void setNombrePorPueblosOriginarios(const char* nppo){strcpy(nombrePorPueblosOriginarios,nppo);}
    
    const char* getNombreCientifico(){return nombreCientifico;}
    const char* getNombreComun(){return nombreComun;}
    const char* getNombrePorPueblosOriginarios(){return nombrePorPueblosOriginarios;}
    
    void CargarDenominacion(){
        cout << "CARGAMOS LA DENOMINACION DEL ANIMAL: " << endl;
        cout << "NOMBRE CIENTIFICO: " << endl;
        cin >> nombreCientifico;
        cout << "NOMBRE COMUN: " << endl;
        cin >> nombreComun ;
        cout << "NOMBRE SEGUN PUEBLO ORIGINARIO: " << endl;
        cin >> nombrePorPueblosOriginarios ;
    }
    void MostrarDenominacion(){
        cout << "NOMBRE CIENTIFICO: " << nombreCientifico << endl;
        cout << "NOMBRE COMUN: " << nombreComun << endl;
        cout << "NOMBRE SEGUN PUEBLO ORIGINARIO: " << nombrePorPueblosOriginarios << endl;
    }
};



int main(){
setlocale (LC_ALL, "Spanish");








cout << endl;
system ("pause");

	return 0;
}