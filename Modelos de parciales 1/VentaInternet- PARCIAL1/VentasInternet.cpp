
#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;


#include "internet.h"


/*
void PuntoBUsuarios(){  // Informar la cantidad de usuarios registrados por cada mes del año 2015.

ArchivoUsuarios archiUsuario("usuario.dat");
Usuarios objUsuario;
int pos=0;
int cantRegistros=archiUsuario.contarRegistros();
int vContUsuarios[12]={};

while(pos<cantRegistros){
    objUsuario=archiUsuario.leerRegistro(pos);
    
        if(objUsuario.getFechaRegistracion() == 2015){
            vContUsuarios[objUsuario.getCodUsuario() -1]++;
        }
        pos++;
}
    for(int i=0; i<12; i++){
        
        cout << "PARA EL MES: " << i+1 << " LA CANTIDAD DE USUARIOS FUERON: " << vContUsuarios[i] << endl;
        
    }

}

*/
int menuConsignas()
{
    int opc, agrego;
    system("cls");
    while(true){
    cout<<"=== PARCIAL 2 - PROGRAMACION II ==="<<endl;
    cout<<"1. "<<endl;
    cout<<"2. "<<endl;
    cout<<"3. "<<endl;
    cout<<"0. SALIR"<<endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
        cout << "INGRESE UN USUARIO PARA LA CARGA EN EL SISTEMA." << endl;
        
        /*
        if(agrego == 1){
            cout << "AGREGO CORRECTAMENTE." <<endl;
            
            ArchiUsuario.grabarRegistro(objUsuario);
        }
        else{
            cout << "FALLA AL AGREGAR USUARIO." << endl;
        }*/
        system("pause");
        system("cls");
        break;
        
   case 2:
 /*
       cout << "INGRESE UN USUARIO PARA LA CARGA EN EL SISTEMA.";
       ArchivoVendedores archiVendedores("vendedores.dat");
       Vendedores objVendedores;
       objVendedores.Cargar();
        /*
        if(agrego == 1){
            cout << "AGREGO CORRECTAMENTE." <<endl;
            
            archiVendedores.grabarRegistro(objVendedores);
        }
        else{
            cout << "FALLA AL AGREGAR USUARIO." << endl;
        }*/
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

//menuConsignas();

ArchivoUsuarios ArchiUsuario("usuario.dat");
        Usuarios objUsuario;
        objUsuario.cargar();
        
        ArchiUsuario.grabarRegistro(objUsuario);
        
        ArchiUsuario.mostrarRegistros();
//PuntoBUsuarios();




cout << endl;
system ("pause");

	return 0;
}

/*
clase Fecha{
privado:
	int dia, mes, anio;
público:
	int getDia(){return dia;}
	int getMes(){devolver mes;}
	int getAnio(){return anio;}
};

clase Vendedor{
	privado:
		char codigoVendedor[5];
		char nombre[30];
		int provincia,calificacion;
	público:
		const char *getCodigoVendedor(){return codigoVendedor;}
		const char *getNombreVendedor(){return nombre;}
		int getProvincia(){regresar provincia;}
		bool leerDeDisco(int);
};

bool Vendedor::leerDeDisco(int pos){
	ARCHIVO *p;
	p=fopen("vendedores.dat", "rb");
	si(p==NULL)salir(1);
	fseek(p, tamañode(Vendedor)*pos,0);
	bool leyo=fread(this, sizeof *this,1,p);
	cerrar(p);
	volver leyo;
}


clase Usuario{
privado:
	char códigoUsuario[5];
	char nombre[30];
	DNI internacional;
	fecha registro;
público:
	bool leerDeDisco(int);
	Fecha getFechaRegistro(){return registro;}
};

bool Usuario::leerDeDisco(int pos){
	ARCHIVO *p;
	p=fopen("usuarios.dat", "rb");
	si(p==NULL)salir(1);
	fseek(p, tamaño de *esta*pos,0);
	bool leyo=fread(this, sizeof *this,1,p);
	cerrar(p);
	volver leyo;
}

clase Venta{
privado:
	int numeroCompra;
	char codigoVendedor[5];
	char códigoUsuario[5];
	importación flotante;
	Fecha fechaVenta;
	inttipoPago;
público:
	const char *getCodigoVendedor(){return codigoVendedor;}
	Fecha getFechaVenta(){return fechaVenta;}
	bool leerDeDisco(int);
};

bool Venta::leerDeDisco(int pos){
	ARCHIVO *p;
	p=fopen("ventas.dat", "rb");
	si(p==NULL)salir(1);
	fseek(p, tamaño de *esta*pos,0);
	bool leyo=fread(this, sizeof *this,1,p);
	cerrar(p);
	volver leyo;
}
*/
class Inactivo{
private:
	char codigoVendedor[5];
	char nombre[30];
public:
	void setCodigoVendedor(const char *cv){strcpy(codigoVendedor,cv);}
	void setNombreVendedor(const char *n){strcpy(nombre,n);}

};

/*
bool buscarVentas(const char *cv, int año){
	Venta reg;
	int pos=0;
	while(reg.leerDeDisco(pos++)){
		if(reg.getFechaVenta().getAnio()==anio)
			if(strcmp(reg.getCodigoVendedor(),cv)==0)
				return true;
 	}
	return false;
}
/*
void puntoA(){
	Auxiliar inactivo;
	Vendedor reg;
	int pos=0;
	/**while(reg.leerDeDisco(pos++)){
		if(buscarVentas(reg.getCodigoVendedor(),2020)==false){
			aux.setCodigoVendedor(reg.getCodigoVendedor());
			aux.setNombreVendedor(reg.getNombreVendedor());
			aux.grabarEnDisco();
		}
	}
	ARCHIVO *p;
	p=fopen("ventas.dat", "rb");
	si(p==NULL)salir(1);
	while(fread(reg, tamaño de reg,1,p)==1){
     	if(buscarVentas(reg.getCodigoVendedor(),2020)==false){
			aux.setCodigoVendedor(reg.getCodigoVendedor());
			aux.setNombreVendedor(reg.getNombreVendedor());
			aux.grabarEnDisco();
    }
	return(p);
}
*/
/*
void puntoB(){
	Usuarios reg;
	int pos=0;
	int v2015[12]={0};
	while(reg.leerDeDisco(pos++)){
		si(reg.getFechaRegistro().getAnio()==2015)
			v2015[reg.getFechaRegistro().getMes()-1]++;

        /*if(reg.getAnio()==2015) si se decide usar 3 propiedades para la fecha
			v2015[reg.getMes()-1]++;
	}
	mostrarVector(v2015);
}

int buscarProvincia(const char *cv){

}

anular puntoC(){
	Venta reg;
	int pos=0, no puedo=0, prov;


 	while(reg.leerDeDisco(pos++)){
		if(reg.getFechaVenta().getAnio()==2020 &&
           reg.getFechaVenta().getMes()<7 ){
                prov=buscarProvincia(reg.getCodigoVendedor());
                si(prov>=7 &&prov<=9)
                    no puedo ++;
           }
	}
	cout<<"LA CANTIDAD DE VENTAS DE LOS VENDEDORES DE LITORAL FUE: "<<cant<<endl;
}
*/