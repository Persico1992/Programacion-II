#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
void menuReportes();  
void menuPrincipal(Empresa empresa, ArchivoEmpresa aEmpresa, Municipio muni, ArchivoMunicipio aMunicipio){
 
 bool baja, modifico; 

 int opc=0;
    while(true){
        system("cls");
        cout << "************MENU**************" << endl;
        cout << "1. CARGAR EMPRESA" << endl;
        cout << "2. CARGAR MUNICIPIO" << endl;
        cout << "3. CARGAR VECTOR" << endl;
        cout << "4. BAJA EMPRESA" << endl;
        cout << "5. MODIFICAR CATEGORIA DE LA EMPRESA" << endl;
        cout << "6. MOSTRAR REGISTRO DE LAS EMPRESAS" << endl;
        cout << "7. MOSTRAR REGISTRO DE LOS MUNICIPIOS" << endl;
        cout << "8. MENU REPORTES" << endl;
        cout << "*****************************" << endl;
        cout << "INGRESE OPCION" << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                cout << "CARGAR EMPRESA: " << endl;
                empresa.Cargar();
                cout << "AHORA GUARDO/AGREGO LA EMPRESA." << endl;
                aEmpresa.agregarRegistro(empresa);
                cout << "AHORA MUESTRO MI ARCHIVO: " << endl;
                aEmpresa.mostrarRegistros();
                system("pause");
                break;
            case 2:
                cout << "CARGAR MUNICIPIO: " << endl<< endl;
                muni.cargarMuni();
                cout << "AHORA GUARDO/AGREGO EL MUNICIPIO." << endl << endl;
                aMunicipio.agregarRegistro(muni);
                cout << "AHORA MUESTRO MI ARCHIVO: " << endl << endl;
                aMunicipio.mostrarRegistros();
                system("pause");
                
                break;
                
                
            case 3:
                cout << "CARGAR VECTOR: " << endl;
              //  cargarVector(vEmpresa, 3);
                cout << "AHORA GUARDO LAS EMPRESAS" << endl;
               // guardarVector(vEmpresa,3);
                cout << "MOSTRAMOS LOS ARCHIVOS:" << endl;
                aEmpresa.mostrarRegistros();
                system("pause");
                  break;
            case 4:
                baja= aEmpresa.bajaLogicaRegistro();
                if(baja){cout << "Se a realizado correctamente la BAJA del registro.";}
                else {cout << "No se pudo realizar la BAJA";}
                break;
                
            case 5:
                 modifico= aEmpresa.modificarCategoria(); 
                 if (modifico){
                    cout << "SE REALIZO CORRECTAMENTE LA MODIFICACION." << endl;
                 }    
                else {cout << "NO SE REALIZO LA MODIFICACION." << endl;}
                  system("pause");
                break;
            case 6:
                aEmpresa.mostrarRegistros()  ;
               
                   system("pause");
                    
                    break;
            case 7:
                aMunicipio.mostrarRegistros();
                system("pause");
                break;
                    
                    
            case 8:
                menuReportes();
                
                break;
        }

    }
}

void menuReportes()
{
    
int opc=0;
    while(true){
        system("cls");
        cout << "************MENU**************" << endl;
        cout << "EJERCICIO 1" << endl;
        cout << "1. PUNTO A" << endl;
        cout << "2. PUNTO B" << endl;
        cout << "3. PUNTO C" << endl;
        cout << "EJERCICIO 2" << endl;
        cout << "4. PUNTO D" << endl;
        cout << "5. PUNTO E" << endl;
        cout << "6. PUNTO F" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << "*****************************" << endl;
        cout << "INGRESE OPCION" << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                puntoA();
                system("pause");
                break;
            case 2:
                puntoB();
                system("pause");
                  break;
            case 3:
                puntoC();
                system("pause");
                break;
            case 4:
                puntoD();
                system("pause");
                break;
            case 5:
                puntoE();
                system("pause");
                break;
            case 6:
//                puntoF();
                system("pause");
            case 0:
                
                return;




        }
    }

}
#endif // MENU_H_INCLUDED
