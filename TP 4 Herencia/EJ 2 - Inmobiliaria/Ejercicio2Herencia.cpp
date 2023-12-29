# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

#include "ClaseFecha.h"

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

///**************************************************************************************************************************************************

class Direccion{

protected:
    int  codigoPostal, numeroCalle, piso;
    char calle[30], localidad[30], partido[30], entreCalle1[30], entreCalle2[30], comentarios[100];
    
    public:

    void setCodPostal (int codPostal){codigoPostal= codPostal;}
    void setLocalidad (const char* l){strcpy(localidad,l);}
    void setCalle (const char* c){strcpy(calle,c);}
    void setNumCalle(int nc){numeroCalle=nc;}
    void setPiso (int p){piso=p;}
    void setEntrecalle1 (const char* ec1){strcpy(entreCalle1,ec1);}
    void setEntrecalle2 (const char* ec2){strcpy(entreCalle2,ec2);}
    void setComentarios(const char* c){strcpy(comentarios,c);}
    
    int getCodPostal(){return codigoPostal;}
    const char* getLocalidad(){return localidad;}
    const char* getCalle(){return calle;}
    int getNumCalle(){return numeroCalle;}
    int getPiso(){return piso;}
    const char* getEntreCalle1(){return entreCalle1;}
    const char* getEntreCalle2(){return entreCalle2;}
    const char* getComentarios(){return comentarios;}
    
    void CargarDireccion(){
        cout << "CALLE: " << endl;
        cargarCadena(calle,29);
        cout << "NUMERO DE CALLE: " << endl;
        cin >> numeroCalle;
        cout << "LOCALIDAD: " << endl;
        cargarCadena(localidad,29);
        cout << "PARTIDO: " << endl;
        cargarCadena(partido,29);
        cout << "CODIGO POSTAL: " << endl;
        cin >> codigoPostal;
        cout << "PISO: " << endl;
        cin >> piso ;
        cout << "ENTRE CALLE 1: " << endl;
        cargarCadena(entreCalle1,29);
        cout << "ENTRE CALLE 2: " << endl;
        cargarCadena(entreCalle2,29);
        cout << "COMENTARIOS: " << endl;
        cargarCadena(comentarios,99);
    
    }
    
    void MostarDireccion(){
        cout << "CALLE: " << calle << endl;
        cout << "NUMERO DE CALLE: " << numeroCalle<< endl;
        cout << "LOCALIDAD: " << localidad << endl;
        cout << "PARTIDO: " << partido << endl;
        cout << "CODIGO POSTAL: " << codigoPostal << endl;
        cout << "PISO: " << piso << endl;
        cout << "ENTRE CALLE 1: " << entreCalle1 << endl;
        cout << "ENTRE CALLE 2: " << entreCalle2 << endl;
        cout << "COMENTARIOS: " << comentarios << endl;
    }
}; 
///**************************************************************************************************************************************************
class Inmueble: public Direccion{

protected:
    Fecha fechaIngreso, fechaOperacion;
    float superficieTotal;
    int tipoOperacion; 
    
    
public:    

///Setters

    void setFechaIngreso (Fecha fi){ fechaIngreso=fi;}
    void setFechaOperacion (Fecha fo){ fechaOperacion=fo;}
    void setSuperficieTotal (float st){ superficieTotal=st;}
    void setTipoOperacion (int to){ tipoOperacion=to;}
    
///Getters
        
    Fecha getfechaIngreso(){return fechaIngreso;}
    Fecha getfechaOperacion(){return fechaOperacion;}
    float getsuperficieTotal(){return superficieTotal;}
    int gettipoOperacion(){return tipoOperacion;}
    
    void CargarInmueble(){
        Direccion::CargarDireccion();
        cout << "FECHA DE INGRESO: " << endl;
        fechaIngreso.Cargar();
        cout << "FECHA DE OPERACION: " << endl;
        fechaOperacion.Cargar();
        cout << "SUPERFICIE TOTAL: " << endl;
        cin >> superficieTotal ;
        cout << "TIPO DE OPERACION: (1: venta- 2:alquiler) " << endl;
        cin >> tipoOperacion;

    }
    
    void MostrarInmuebles(){
        Direccion::MostarDireccion();
        cout << "FECHA DE INGRESO: " << endl;
        fechaIngreso.mostrarEnLinea();
        cout << "FECHA DE OPERACION: " << endl;
        fechaOperacion.mostrarEnLinea();
        cout << "SUPERFICIE TOTAL: " << superficieTotal << endl;
        cout << "TIPO DE OPERACION: " << tipoOperacion << endl;
    
    }
};
///**************************************************************************************************************************************************
class Casa: public Inmueble{

private:
    int cantidadAmbientes;
    float superficieConstruida;

public: 
    
///setters

    void setCantidadAmbientes(int ca){cantidadAmbientes= ca;}
    void setSuperficieConstruida(float sc){superficieConstruida= sc;}
    
///Getters

    int getCantidadAmbientes(){return cantidadAmbientes;}
    float getSuperficieConstruida(){return superficieConstruida;}
    
    void CargarCasa(){
        cout << "CARGAMOS DATOS PARA EL INMUEBLE CASA: " << endl;
            Inmueble::CargarInmueble();
            cout << "CANTIDAD DE AMBIENTES: " << endl;
            cin >>cantidadAmbientes;
            cout << "SUPERFICIE CONSTRUIDA: " << endl;
            cin >> superficieConstruida;
    
    }
    
    void MostrarCasa(){
        Inmueble::MostarDireccion();
        cout << "CANTIDAD DE AMBIENTES: " << cantidadAmbientes << endl;
        cout << "SUPERFICIE CONSTRUIDA: " << superficieConstruida << endl;

    }
};

///**************************************************************************************************************************************************
class Departamento: public Inmueble{

private:
    
    int cantAmbiente;
    char instalacionesComplementarias[50];
    bool tiene;
    
public:
    
    ///Setter
    void setCantAmbiente(int cAmb){cantAmbiente=cAmb;}
    void setInstalacionesComplementarias (const char* ic){strcpy(instalacionesComplementarias,ic);}
    void setTiene (bool t){tiene = t;}
    
    //Getters
    
    int getCantAmbiente(){return cantAmbiente;}
    const char* getInstalacionesComplementarias(){return instalacionesComplementarias;}
    bool getTiene(){return tiene;}
    
    void CargarDepartamento(){
        cout << "CARGAMOS LOS DATOS DE LOS DEPARTAMENTOS: " << endl;
        Inmueble::CargarInmueble();
        cout << "CANTIDAD DE AMBIENTES QUE TIENE: " << endl;
        cin >> cantAmbiente ;
        cout << "Ingrese si tiene las instalaciones Complementarias (1 para SI - 0 para NO): ";
        cin >> tiene;
           if(tiene == true){
               cout << "QUE INSTALACION EXTRA TIENE?: " << endl;
                cin >> instalacionesComplementarias ;
           }
           else{
            cout << "SIN INSTALACIONES EXTRA." << endl;
           }
    }
    
    void MostrarDepartamento(){
        Inmueble::MostrarInmuebles();
        cout << "CANTIDAD DE AMBIENTES: " << cantAmbiente << endl;
        cout << "INSTALACIONES COMPLEMENTARIAS: " << instalacionesComplementarias << endl;
            
    }

};

class Locales: public Inmueble{

private: 
    int zona;
    
public:
    
///setters

    void setZona(int z){zona= z;}
    
///Getters

    int getZona(){return zona;}
    
    void CargarLocal(){
        Inmueble::CargarInmueble();
         cout << "INGRESE LA ZONA QUE DESEE PARA: (1=COMERCIO, 2=MIXTA, 3=INDUSTRIAL "<< endl;
        cin >> zona;
    
    }
    void MostrarLocal(){
        Inmueble::MostrarInmuebles();
        cout << "LA ZONA ES: " << zona << endl;
    }
    
    };

class Terreno: public Inmueble{
    
private: 
    char mejoras[2];
    
public:
    
///Setters
    void setMejoras(const char* m){strcpy(mejoras, m);}
    
///Getters
    
    const char* getMejoras(){return mejoras;}
    
    void CargarTerreno(){
        Inmueble::CargarInmueble();
        cout << "TIPO DE MEJORAS: 'A' SIN MEJORAS - 'B' ASFALTO - 'C' TODOS LOS SERVICIOS:)" << endl;
        cin >> mejoras;
    }
    void MostrarTerreno(){
        Inmueble::MostrarInmuebles();
        cout << "TIPO DE MEJORAS: " << mejoras << endl;
    }
    
    };
    
int menuConsignas()
{
      Direccion objDire;
      Inmueble objInmueble;
      Casa objCasa;
      Departamento objDep;
      Locales objLocal;
      Terreno objTerreno;
    int opc;
    system("cls");
    while(true){
    cout<<"=== TP HERENCIA - PROGRAMACION II ==="<<endl;
    cout<<"1. CARGAR DATOS PARA UNA DIRECCION."<<endl;
    cout<<"2. CARGAR DATOS PARA UN INMUEBLE. "<<endl;
    cout<<"3. CARGAR DATOS PARA UNA CASA."<<endl;
    cout<<"4. CARGAR DATOS PARA UN DEPARTAMENTO."<<endl;
    cout<<"5. CARGAR DATOS PARA UN LOCAL."<<endl;
    cout<<"6. CARGAR DATOS PARA UN TERRENO."<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
        objDire.CargarDireccion();
        system("pause");
        
    cout << "***********************************" << endl;
        objDire.MostarDireccion();
        system("pause");
        system("cls");
        break;
    case 2:
        objInmueble.CargarInmueble();
        system("pause");
	
	cout << "********************************************" << endl;
        objInmueble.MostrarInmuebles();
        system("pause");
        system("cls");
        break;
    case 3:
        objCasa.CargarCasa();
        system("pause");
	
    cout << "********************************************" << endl;
        objCasa.MostrarCasa();
        system("pause");
        system("cls");
        break;
    case 4:
        objDep.CargarDepartamento();
        system("pause");
	cout << "********************************************" << endl;
        objDep.MostrarDepartamento();
        system("pause");
        system("cls");
        break;
    case 5:
        objLocal.CargarLocal();
        system("pause");
	cout << "********************************************" << endl;
         objLocal.MostrarLocal();
        system("pause");
        system("cls");
        break;
    case 6:
        objTerreno.CargarTerreno();
        system("pause");
	cout << "********************************************" << endl;
        objTerreno.MostrarTerreno();
        system("pause");
        system("cls");
        break;
    case 0:
        return 0;

    }

    }
}
int main(){
  
   menuConsignas();
   
    

	system("pause");
	return 0;
}
