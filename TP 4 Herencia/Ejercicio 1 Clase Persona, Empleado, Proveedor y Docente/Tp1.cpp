//Nombre:
//Tp:TP 1 
//Ejercicio N°: 1

/*

*/

#include <iostream>
#include <locale.h>
#include <cstdlib>
using namespace std;

void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }

    }
     palabra[i]='\0';
     fflush(stdin);
  }

class Persona{

protected:  ///Permite el acceso a las herencias
    char nombre[30], apellido[30], direccion [30], email[30], telefono[30];
    int DNI;
    Fecha fechaNacimiento;

public:
    void cargarPersona();
    void mostrarPersona();
    
///Setters
    void setNombre(char *n){strcpy(nombre,n);}
    void setApellido (char *ap){strcpy(apellido,ap);}
    void setDireccion (char *dir){strcpy(direccion,dir);}
    void setEmail (char *em){strcpy(email,em);}
    void setTelefono (char *tel){strcpy(telefono,tel);}
    void setDNI (int d){DNI= d;} 
    void setFechaNacimiento (Fecha f){fechaNacimiento= f;}
///Getters
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getDireccion(){return direccion;}
    const char *getEmail(){return email;}
    const char *getTelefono(){return telefono;}
    int getDNI(){return DNI;}
    void getFechaNacimiento(){return fechaNacimiento.mostrarEnLinea();}
};


void Persona::cargarPersona(){

    char nombreIngresado[30], apellidoIngresado[30], direccionIngresado[30], emailIngresado[30], telefonoIngresado[30];
    int dniIngresado;
    Fecha fechaNacimientoIngresada;
    
    cout << "Ingrese el apellido de la Persona: " << endl;
    cargarCadena(nombreIngresado,29);
    this-> setNombre (nombreIngresado);
    
    cout << "Ingrese la dirección de la Persona: " << endl;
    cargarCadena(apellidoIngresado,29);
    this-> setApellido (apellidoIngresado);
    
    cout << "Ingrese el email de la Persona: " << endl;
    cargarCadena(emailIngresado,29);
    this-> setEmail (emailIngresado);
    
    cout << "Ingrese el telefono de la Persona: " << endl;
    cargarCadena(telefonoIngresado,29);
    this-> setTelefono (telefonoIngresado);
    
    cout << "Ingrese el DNI de la Persona: " << endl;
    cin >> dniIngresado;
    this-> setDNI(dniIngresado);
    
    cout << "Ingrese la fecha de nacimiento: " << endl;
    fechaNacimientoIngresada.Cargar();
    this->setFechaNacimiento(fechaNacimientoIngresada);

        system("pause");
        system("cls");
    
}

void Persona::mostrarPersona(){

    cout << "El nombre de la persona: " << this-> getNombre()<<endl;
    cout << "El apellido de la persona: " << this-> getApellido()<<endl;
    cout << "El direccion de la persona: " << this-> getDireccion()<<endl;
    cout << "El email de la persona: " << this-> getEmail()<<endl;
    cout << "El telefono de la persona: " << this-> getTelefono()<<endl;
    cout << "El DNI de la persona: " << this-> getDNI()<<endl;
    cout << "La fecha de nacimiento es: " << endl;
    this-> getFechaNacimiento();

}

class Empleado:public Persona{

private: 
        int categoria;
        float sueldo;
        Fecha fechaIngreso;
    
public:
    
    Empleado(){}
    
    void setCategoria (int c){categoria= c;}
    void setSueldo (float s){sueldo= s;}
    void setFecha (Fecha f){fechaIngreso= f;}
    
    int getCategoria(){return categoria;}
    float getSueldo(){return sueldo;}
    Fecha getFechaIngreso(){return fechaIngreso.mostrarEnLinea;}
    
    void CargarEmpleado(){
        cout << "DATOS DEL EMPLEADO: " << endl;
        Persona::Cargar();
        cout << "CATEGORIA: " << endl;
        cin >> categoria ;
        cout << "SUELDO: " << endl;
        cin >> sueldo;
        cout << "FECHA: " << endl;
        fechaIngreso.Cargar();
    }
    
};

class Proveedor:public Persona{

private:
        int cuil, tipoProducto;
        char condicionPago[2];

public:
        
  Proveedor(){}

    void setCuil(int c){cuil= c;}
    void setTipoProducto (int tp){tipoProducto= tp;}
    void setCondicionPago (char *cp){strcpy(condicionPago,cp);}     ///REVISAR
    
    int getCuil(){return cuil;}
    int getTipoProducto(){return tipoProducto;}
    const char *condicionPago(){return condicionPago;}              ///REVISAR


};

class Docente:public Persona{

private: 
        int legajoDocente;
        char cargo[15];
        Fecha fechaIngreso;

public:

    Docente(){}
    
    
    void setLegajoDocente(int ld){legajoDocente=ld;}
    void setCargo(char *c){strcpy(cargo,c);}
    void setFechaIngreso (Fecha f){fechaIngreso=f;}
    
    int getLegajoDocente(){return legajoDocente;}
    const char *cargo(){return cargo;}
    void getFechaIngreso(){return fechaIngreso.mostrarEnLinea;}
};
int main(){
setlocale (LC_ALL, "Spanish");

Empleado objEmpleado;
int menuConsignas()
{
    int opc;
    system("cls");
    while(true){
    cout<<"=== TP HERENCIA - PROGRAMACION II ==="<<endl;
    cout<<"1. CARGAR DATOS PARA UN EMPLEADO."<<endl;
    cout<<"2. MOSTRAR DATOS DEL EMPLEADO."<<endl;
    cout<<"3. "<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
        objEmpleado.CargarEmpleado();
	system("pause");
        system("cls");
        break;
    case 2:
	system("pause");
        system("cls");
        break;
    case 3:
	system("pause");
        system("cls");
        break;
    case 4:
	system("pause");
        system("cls");
        break;
    case 0:
        return 0;

    }

    }
}




cout << endl;
system ("pause");

	return 0;
}