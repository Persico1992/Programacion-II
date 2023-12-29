///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

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
class Persona{
protected:
    char nombre[30], apellido[30], direccion[30];
    char email[30], telefono[30];
    int DNI;
    Fecha fechaNacimiento;
public:
    void Cargar();
    void Mostrar();
    void setDNI(int d){DNI=d;}

    int getDNI(){return DNI;}

};

void Persona::Cargar(){
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 29);
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 29);
    cout<<"DIRECCION: ";
    cargarCadena(direccion, 29);
    cout<<"EMAIL: ";
    cargarCadena(email, 29);
    cout<<"TELEFONO: ";
    cargarCadena(telefono, 29);
    cout<<"DNI: ";
    cin>>DNI;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Cargar();
}

void Persona::Mostrar(){
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"DIRECCION: ";
    cout<<direccion<<endl;
    cout<<"EMAIL: ";
    cout<<email<<endl;
    cout<<"TELEFONO: ";
    cout<<telefono<<endl;
    cout<<"DNI: ";
    cout<<DNI<<endl;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Mostrar();
}

///**************************************************************************************************************************************************
class Docente:public Persona{
    private:
        int legajoDocente;
        Fecha fechaIngreso;
        char carrera[30];
        char cargo[15];
    public:
        void setLegajoDocente(int l){legajoDocente=l;}
        void setFecha(Fecha f){fechaIngreso=f;}
        void setCarrera(const char *c){strcpy(carrera, c);}
        void setCargo(const char *ca){strcpy(cargo, ca);}

        int getLegajoDocente(){return legajoDocente;}
        Fecha getFechaIngreso(){return fechaIngreso;}
        const char * getCarrera(){return carrera;}
        const char * getCargo(){return cargo;}

        void CargarDocente(){
            cout<<"Datos personales del docente: " <<endl;
            Persona::Cargar();
            cout<<"LEGAJO: ";
            cin>>legajoDocente;
            cout<<"FECHA DE INGRESO: ";
            fechaIngreso.Cargar();
            cout<<"CARRERA: ";
            cargarCadena(carrera,29);
            cout << "CARGO: ";
            cargarCadena(cargo,14);
        }
        void MostrarDocente(){
            Persona::Mostrar();
            cout<<"LEGAJO: ";
            cout<<legajoDocente<<endl;
            cout<<"FECHA DE INGRESO: ";
            fechaIngreso.Mostrar();
            cout<<"CARRERA: ";
            cout<<carrera<<endl;
            cout << "CARGO: " << cargo << endl;
        }
    
};
///**************************************************************************************************************************************************
class Alumno:public Persona{
private:
    int legajoAlumno;
    int codigoCarrera;
    char tituloSecundario[30];
    ///si se hereda de manera privada tanto las
    ///propiedades como los métodos se copian en la parte privada de la derivada

public:
    void setLegajoAlumno(int l){legajoAlumno=l; }
    void setCodigoCarrera(int cc){codigoCarrera=cc;}
    void setTituloSecundario(const char *titulo){strcpy(tituloSecundario, titulo);}

    int getLegajoAlumno(){return legajoAlumno; }
    int getCodigoCarrera(){return codigoCarrera;}
    const char *getTituloSecundario(){return tituloSecundario;}
    void CargarAlumno(){
        cout << "CARGAR DATOS DEL ALUMNO: " << endl;
        Persona::Cargar();
        cout<<"LEGAJO: ";
        cin>>legajoAlumno;
        cout<<"CARRERA: ";
        cin>>codigoCarrera;
        cout<<"TITULO: ";
        cargarCadena(tituloSecundario,29);
    }
    void MostrarAlumno(){
        Persona::Mostrar();
        cout<<"LEGAJO: ";
        cout<<legajoAlumno<<endl;
        cout<<"CARRERA: ";
        cout<<codigoCarrera<<endl;
        cout<<"TITULO: ";
        cout<<tituloSecundario<<endl;
    }
    
};
///**************************************************************************************************************************************************
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
    Fecha getFechaIngreso(){return fechaIngreso;}
    
    void CargarEmpleado(){
        cout << "DATOS DEL EMPLEADO: " << endl;
        Persona::Cargar();
        cout << "CATEGORIA: (1 a 5)" << endl;
        cin >> categoria ;
        cout << "SUELDO: " << endl;
        cin >> sueldo;
        cout << "FECHA: " << endl;
        fechaIngreso.Cargar();
    }
    
    void MostrarEmpleado(){
        cout << "DATOS DEL EMPLEADO: " << endl;
        Persona::Mostrar() ;
        cout << "CATEGORIA: " << categoria << endl;
        cout << "SUELDO: " << sueldo << endl;
        cout << "FECHA INGRESO: " << endl;
        fechaIngreso.mostrarEnLinea();
            }
    
};
///**************************************************************************************************************************************************
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
    const char *getcondicionPago(){return condicionPago;}              ///REVISAR

    void CargarProveedor(){
        cout << "DATOS DEL PROVEEDOR: " << endl;
        Persona::Cargar();
        cout << "CUIL: " << endl;
        cin >> cuil;
        cout << "TIPO DE PRODUCTO: (1 a 10) " << endl;
        cin >> tipoProducto ;
        cout << "CONDICION DE PAGO: ('a'-'b'-'c') " << endl;
        cargarCadena(condicionPago,1);
    }
    
    void MostrarProveedor(){
        Persona::Mostrar();
        cout << "CUIL: " << cuil << endl;
        cout << "TIPO DE PRODUCTO: " << tipoProducto << endl;
        cout << "CONDICION DE PAGO: " << condicionPago << endl;
    
    }
};
///**************************************************************************************************************************************************
int menuConsignas()
{
      Docente miDocente;
      Alumno miAlumno;
      Empleado miEmpleado;
      Proveedor miProveedor;
    int opc;
    system("cls");
    while(true){
    cout<<"=== TP HERENCIA - PROGRAMACION II ==="<<endl;
    cout<<"1. CARGAR DATOS PARA UN DOCENTE."<<endl;
    cout<<"2. CARGAR DATOS PARA UN ALUMNO. "<<endl;
    cout<<"3. CARGAR DATOS PARA UN EMPLEADO."<<endl;
    cout<<"4. CARGAR DATOS PARA UN PROVEEDOR."<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
    miDocente.CargarDocente();
        system("pause");
   
    cout << "***********************************" << endl;
     miDocente.MostrarDocente();
        system("pause");
        system("cls");
        break;
    case 2:
       miAlumno.CargarAlumno();
        system("pause");
	
	cout << "********************************************" << endl;
        miAlumno.MostrarAlumno();
        system("pause");
        system("cls");
        break;
    case 3:
        miEmpleado.CargarEmpleado();
        system("pause");
	
    cout << "********************************************" << endl;
        miEmpleado.MostrarEmpleado();
        system("pause");
        system("cls");
        break;
    case 4:
        miProveedor.CargarProveedor();
        system("pause");
	cout << "********************************************" << endl;
        miProveedor.MostrarProveedor();
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
