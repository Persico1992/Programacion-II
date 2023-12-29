#include <iostream>
#include <cstring>
using namespace std;

#include "FuncionesGlobales.h"
#include "ClaseFecha.h"
#include "Inmueble.h"



int main()
{
    
    Inmueble inmueble;
    Casa casa;
    Departamento dpto;
    Locales porZona;
    Terreno mejora;
    
       int opc=0;
    while(true){
        system("cls");
        cout << "************MENU**************" << endl;
        cout << "1. CARGAR INMUEBLE" << endl;
        cout << "2. MOSTRAR INMBUELE" << endl;
        cout << "3. CARGAR CASA" << endl;
        cout << "4. MOSTRAR CASA" << endl;
        cout << "5. CARGAR DEPARTAMENTO" << endl;
        cout << "6. MOSTRAR DEPARTAMENTO" << endl;
        cout << "7. CARGAR LOCAL" << endl;
        cout << "8. MOSTRAR LOCAL" << endl;
        cout << "9. CARGAR TERRENO" << endl;
        cout << "10. MOSTRAR TERRENO" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "*****************************" << endl;
        cout << "INGRESE OPCION" << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                cout << "Ahora cargamos un objeto INMUEBLE: " << endl;
                inmueble.cargar();
                
                break;
            case 2:
                 cout << "Esta es un objeto INMUEBLE: " << endl;
                inmueble.mostrar();
                
                cout << endl;
                
                    system("pause");
                    
                    break;
            case 3:
                
                cout << "Ahora cargamos un objeto con CASA: " << endl;
                casa.cargar();
                
                    break;
            case 4:
                cout << "Esta es un objeto CASA: " << endl;
                    casa.mostrar();
                 system("pause");
                cout << endl;
                
                system("pause");
                    break;
            case 5:
                cout << "Ahora cargamos un objeto con DEPARTAMENTO: " << endl;
                    dpto.cargar();
            
                    break;      
             
            case 6: 
                cout << "Esta es un objeto DEPARTAMENTO: " << endl;
                    dpto.mostrar();
                    system("pause");
                        break;
            case 7:
                cout << "Ahora cargamos un objeto con LOCALES: " << endl;
                    porZona.cargar();
                break;
            case 8:
                cout << "Esta es un objeto de LOCALES: " << endl;
                    porZona.mostrar();
                    system("pause");
                    break;
            case 9:
                 cout << "Ahora cargamos un objeto con TERRENO: " << endl;
                    mejora.cargar();
    
                 break;   
             
            case 10:
                cout << "Esta es un objeto de TERRENO: " << endl;
                mejora.mostrar(); 
                system("pause");
                break;   
            case 0: return 0;
                    break;
            default:cout<<"OPCION INCORRECTA. VUELVA A INGRESAR";
                    break;
        }
    }
        
    return 0;
}
