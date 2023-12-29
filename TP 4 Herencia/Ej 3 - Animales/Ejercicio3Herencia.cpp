//Nombre:
//Tp:
//Ejercicio N°:

/*
Peces, anfibios, reptiles, aves y mamíferos. Para los mamíferos se plantea la división entre terrestres y marinos.
Para todos los animales desea registrar lo siguiente: denominación, tiempo de vida promedio, dimensión, peso, zona de hábitat principal, tipo de
alimentación y población estimada.
La denominación incluye: nombre científico, nombre común, nombre dado por pueblos originarios
La dimensión establece valores de: largo, ancho, alto
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