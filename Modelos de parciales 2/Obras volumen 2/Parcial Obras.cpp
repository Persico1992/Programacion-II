
#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;


#include "parcial2.h"

//const char *ArchivoObras=("Obras.dat");
//const char *ArchivoMaterialees=("Materiales.dat");
//const char *ArchivoCompras=("Compras.dat");
//const char *ArchivoProveedores=("Proveedores.dat");



//Punto 1       
/*Generar un archivo con los proveedores a los que no se les haya hecho compras el año actual. 
Por cada proveedor al que no se le hayan hecho compras este año se debe registrar el número de proveedor, 
el nombre del proveedor y la provincia del proveedor.*/
class Punto1{

private:
    int numProveedor;
    char nombreProv[30];
    int provinciaProveedor;
    
public:
    
    void setNumProveedor(int np){numProveedor=np;}
    void setNombreProv(const char* nomp){strcpy(nombreProv,nomp);}
    void setProvinciaProveedor(int pp){provinciaProveedor=pp;}
    
    int getNumProveedor(){return numProveedor;}
    const char* getNombreProv(){return nombreProv;}
    int getProvinciaProveedor(){return provinciaProveedor;}
    
    void Mostrar(){
        cout << "NUM PROVEEDOR: " << numProveedor << endl;
        cout << "NOMBRE PROVINCIA: " << nombreProv << endl;
        cout << "PROVINCIA PROVEEDOR: " << provinciaProveedor << endl;
    }
};

class ArchivoPunto1{

private:
    char nombre[30];
public:
    ArchivoPunto1(){
        strcpy(nombre,"Punto1.dat");
    }
    bool grabarRegistro(Punto1 reg){        ///Esto escribe un registro en el archivo que esta guardado en la propiedad nombre
            FILE *p;                    
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
     ///Si compilamos varias veces algo, debemos borrar/vaciar el archivo cada vez que lo creo.. Vamos a agregar el metodo este   
        void vaciar(){
            FILE *p = fopen(nombre,"wb");
            if(p==NULL){return;}
            fclose(p);
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


SolucionPunto1(){
ArchivoProveedores archiProveedores("Proveedores.dat");
Proveedor objProveedor;
int cantRegProveedores=archiProveedores.contarRegistros();

ArchivoCompras archiCompras("Compras.dat");
Compra objCompra;
int cantRegCompras=archiCompras.contarRegistros();

ArchivoPunto1 archiPunto1;
Punto1 objPunto1;

for(int i=0; i<cantRegProveedores; i++){
    objProveedor=archiProveedores.leerRegistro(i);
    
    bool noLeCompraron= false;      
    
    for(int x=0; x<cantRegCompras; x++){
        objCompra=archiCompras.leerRegistro(x);
        
        if(objProveedor.getNumeroProveedor() == objCompra.getNumeroproveedor() && objCompra.getFechaCompra().getAnio() == 2022){
            noLeCompraron=true; ///SI COMPRARON
        }
        
        
    }
    
        if(!noLeCompraron){ ///SI, NO LE COMPRARON NO MUESTRES.
            
            objPunto1.setNumProveedor(objProveedor.getNumeroProveedor());
            objPunto1.setNombreProv(objProveedor.getNombre());
            objPunto1.setProvinciaProveedor(objProveedor.getProvincia());
            archiPunto1.grabarRegistro(objPunto1);
             
            
        }
}
        
    archiPunto1.mostrarRegistros();
  // archiPunto1.vaciar();    ///Este archivo nos vacia el .dat
}



//Punto2           
/*El tipo de material con menos cantidad de materiales (ignorando los tipos sin materiales).*/
SolucionPunto2(){
ArchivoMateriales archiMaterial("Materiales.dat");
Material objMaterial;
int cantRegMaterial=archiMaterial.contarRegistros();

ArchivoCompras archiCompra("Compras.dat");
Compra objCompra;
int cantRegCompra=archiCompra.contarRegistros();

bool sinMaterial=false; ///Se ignora
float vAcuCantidad[6]={};
    
for (int j=0; j<cantRegMaterial; j++){
    objMaterial=archiMaterial.leerRegistro(j);
    
    for (int x=0; x<cantRegCompra; x++){
         objCompra=archiCompra.leerRegistro(x);
        
        if(objCompra.getCodigoMaterial() == objMaterial.getCodigoMaterial()){
            vAcuCantidad[objMaterial.getTipo() - 1] += objCompra.getCantidad();
        }
        
    }
    
    }
    int posMenor;
    float menorMaterial= vAcuCantidad[0];
    for(int i=0; i<6; i++){
       if(vAcuCantidad[i] > 0){
            
            if(!sinMaterial){
                menorMaterial=vAcuCantidad[i];
                sinMaterial=true;
                posMenor= i+1;
            }
            else{
                if(vAcuCantidad[i] < menorMaterial){
                    
                    menorMaterial= vAcuCantidad[i];
                    posMenor= i+1;
                }
            }
        
       }
        
         
        
    }
   cout << "LA ACUMULACION MENOR DEL MATERIAL ES DE: " << menorMaterial << " Y ES DEL TIPO " << posMenor << endl;
}

///Punto3
/*Generar un vector dinámico con todos los materiales y listar luego los materiales del vector que pertenezcan a un tipo que se ingresa por teclado.*/
void SolucionPunto3(){
ArchivoMateriales archiMaterial("Materiales.dat");
Material *vMat, objMaterial;
int ingresoMat;

        int cantRegMateriales=archiMaterial.contarRegistros();      ///CUENTO LA CANTIDAD DE REGISTRO QUE EXISTEN DE TODOS LOS MATERIALES
        if(cantRegMateriales == 0){     
            cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        return;
        }
        
        vMat= new Material[cantRegMateriales]; ///PIDO MEMORIA CON EL PUNTERO CREADO. CON LA CLASE Y ENTRE [] PARA CREAR EL VECTOR CON LAS CANTIDADES DE LOS TIPOS
        if(vMat==NULL) {
            cout << "ERROR AL CREAR EL VECTOR.";
        }      ///CHEQUEO DE MEMORIA
        
        
        
cout << "INGRESE TIPO DE MATERIAL:(1: obra gruesa; 2: techos; 3: aberturas; 4: revestimientos; 5: sanitarios; 6: electricidad) " << endl;
cin >> ingresoMat;              ///REALIZO INGRESO DEL PEDIDO
    
       for(int i=0; i<cantRegMateriales; i++){
            
            vMat[i]=archiMaterial.leerRegistro(i);  ///LEO EN MI ARCHIVO INICIALIZADO CON MI VECTOR DIN COPIANDOLOS
            }
            
    bool pertenece; 
 for (int x=0; x<cantRegMateriales; x++){
       
       if(vMat[x].getTipo() == ingresoMat){        ///PREGUNTO SI EN MI OBJETO DEL VECTOR DIN DEL TIPO ES == AL QUE ME INGRESARON
                     vMat[x].Mostrar();         ///SI ES IGUAL QUE ME LOS MUESTRE
                     pertenece=true;                               
       }
       
}
        if(pertenece ==false){cout << "NO EXISTE MATERIAL. " << endl;}
        
    delete vMat;                ///DEVUELVO MEMORIA
}

///Punto3bis
/*Generar un vector dinámico con todas las compras y listar luego las compras del vector que pertenezcan a un código de material que se ingresa por teclado.*/
void SolucionPunto3bis(){
ArchivoCompras archiCompras("Compras.dat");
Compra *vCompra, objCompra;
int cantRegCompra=archiCompras.contarRegistros();
 int ingresoCodMaterial;  
if(cantRegCompra == 0){
        cout << "NO HAY REGISTROS AL ABRIR EL ARCHIVO.";
        
}
 
    vCompra=new Compra[cantRegCompra];
     if(vCompra==NULL) {
            cout << "ERROR AL CREAR EL VECTOR.";
        } 
        
cout << "INGRESE CODIGO DE MATERIAL: " << endl;
cin  >> ingresoCodMaterial;

    for (int i=0; i<cantRegCompra; i++){
        
        vCompra[i]=archiCompras.leerRegistro(i);
        
    }
        bool bandera;
        
    for (int x=0; x<cantRegCompra; x++){
        
        if(vCompra[x].getCodigoMaterial() == ingresoCodMaterial){
                vCompra[x].Mostrar();
                bandera=true;
        }
    }
        if(bandera == false){
            cout << "NO EXISTE COD DE MATERIAL." << endl;
        }
        
        delete vCompra;
} 
    
///Punto3bis2
/*Generar un vector dinámico con todos los proveedores y listar luego los proveedores del vector que pertenezcan a una dirección que se ingresa por teclado*/

///Punto3bis3
/*///Generar un vector dinámico con todas las compras y listar luego las compras del vector con un importe menor a un valor que se ingresa por teclado.*/
void SolucionPunto3bis3(){
ArchivoCompras archiCompras("Compras.dat");
Compra *vCompra, objCompra;
float ingreseImporte;


        int cantRegCompra=archiCompras.contarRegistros();      ///CUENTO LA CANTIDAD DE REGISTRO QUE EXISTEN DE TODOS LOS MATERIALES
        if(cantRegCompra == 0){     
            cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        return;
        }
        
        vCompra= new Compra[cantRegCompra]; ///PIDO MEMORIA CON EL PUNTERO CREADO. CON LA CLASE Y ENTRE [] PARA CREAR EL VECTOR CON LAS CANTIDADES DE LAS COMPRAS
        if(vCompra==NULL) {
            cout << "ERROR AL CREAR EL VECTOR.";
        }      ///CHEQUEO DE MEMORIA
        
        
        
cout << "INGRESE EL IMPORTE: " << endl;
cin >> ingreseImporte;              ///REALIZO INGRESO DEL IMPORTE
    
       
       for(int i=0; i<cantRegCompra; i++){
            
            vCompra[i]=archiCompras.leerRegistro(i);  ///LEO EN MI ARCHIVO INICIALIZADO CON MI VECTOR DIN COPIANDOLOS
            }
            
    bool esMenorImporte; 
 for (int x=0; x<cantRegCompra; x++){
       
       if(vCompra[x].getImporte() < ingreseImporte){        ///PREGUNTO SI EN MI OBJETO DEL VECTOR DIN DEL TIPO ES IGUAL AL QUE ME INGRESARON
                     vCompra[x].Mostrar();         ///SI ES IGUAL QUE ME LOS MUESTRE
                     esMenorImporte=true;                               
       }
       
}
        if(esMenorImporte ==false){cout << "NO EXISTE IMPORTE MENOR. " << endl;}
        
    delete vCompra;                ///DEVUELVO MEMORIA
}

///Punto4
/*Sobrecargar el operador == para la clase Obra de manera tal que sea verdadero cuando el objeto que llama al método tenga un valor de
 superficie igual a un valor de tipo float que se recibe como parámetro.*/
 
///Punto 5
/*Sobrecargar el operador > para la clase Obra de manera tal que sea verdadero cuando el objeto 
que llama al método tenga una superficie mayor al objeto
Obra que se recibe como parámetro.*/


///PUNTO 6
///La provincia con más proveedores.

void ProvinciaConMasProveedores(){
ArchivoObras archiObras("Obras.dat");
Obra objObra;
ArchivoProveedores archiProveedor("Proveedores.dat");
Proveedor objProveedor;

int cantRegistroObras=archiObras.contarRegistros();
int cantRegistroProve=archiProveedor.contarRegistros();
int pos=0, pos1;
int vCantProvPorProvincia[24]={0};

while(pos<cantRegistroProve){
        objProveedor=archiProveedor.leerRegistro(pos);
        
    vCantProvPorProvincia[objProveedor.getProvincia() -1]++;
    
    pos++;
}
 int mayorProv= vCantProvPorProvincia[0];
 int posProv;
      
      for(int i=0; i<23; i++){
        
        if(vCantProvPorProvincia[i] > mayorProv){
            
            mayorProv=vCantProvPorProvincia[i];
            
        }
        
      }
    cout << "LA MAYOR PROVINCIA CON PROVEEDORES ES LA NUMERO: " << mayorProv << endl;
}


///PUNTO 7
///Generar un archivo con los materiales que se hayan comprado en el año actual. 
///Por cada material comprado este año se debe registrar el código de material, el tipo, y la marca.

class MaterialComprado{

private: 
    int codMaterial, tipo;
    char marca[30];
public:
    
    void setCodMaterial(int cm){codMaterial=cm;}
    void setTipo(int t){tipo=t;}
    void setMarca(const char* m){strcpy(marca,m);}
    
    int getCodMaterial(){return codMaterial;}
    int getTipo(){return tipo;}
    const char * getMarca(){return marca;}
    
    void MostrarMaterial(){
        cout << "COD MATERIAL: " << codMaterial<< endl;
        cout << "TIPO: " << tipo<< endl;
        cout << "MARCA: " << marca<< endl;
         
    }
};

class ArchivoMaterialComprado{

 private:
        char nombre[30];
        
    public:
        ArchivoMaterialComprado(const char* n){strcpy (nombre,n);}
        
        MaterialComprado leerRegistro(int pos){
        MaterialComprado reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p,sizeof(MaterialComprado)*pos,0);
        fread(&reg, sizeof reg,1,p);
        fclose(p);
        return reg;
        }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(MaterialComprado);
    }
    int agregarRegistros(MaterialComprado mat){
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int valor=fwrite(&mat, sizeof mat,1,p);
        fclose(p);
        return valor;
    
    }
    int mostrarRegistros(){
        MaterialComprado read;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        while(fread(&read,sizeof read,1,p)== 1){
            read.MostrarMaterial();
            cout << endl;
        }
        fclose(p);
        return true;
    }



};
   
   
void PuntoAB(){
ArchivoMaterialComprado archiMatComprado("mateComprado.dat");
MaterialComprado objMatComprado;
ArchivoMateriales archiMaterial("Materiales.dat");
Material objMaterial;
ArchivoCompras archiCom("Compras.dat");
Compra objCompra;
int cantRegCompra=archiCom.contarRegistros();
int cantRegistroMaterial=archiMaterial.contarRegistros();

for(int i=0; i<cantRegistroMaterial; i++){
    objMaterial=archiMaterial.leerRegistro(i);
    bool compro=false;
    for(int x=0; x<cantRegCompra; x++){
        objCompra=archiCom.leerRegistro(x);
        
        
    
    
        if( objMaterial.getFechaCompra().getAnio() == 2023 && objMaterial.getActivo() == true){  ///objCompra.getCodigoMaterial() && objMaterial.getCodigoMaterial() &&
                compro= true;
        }
        
           
    }
            if(compro){
                objMatComprado.setCodMaterial(objMaterial.getCodigoMaterial());
                objMatComprado.setTipo(objMaterial.getTipo());
                objMatComprado.setMarca(objMaterial.getMarca());
                archiMatComprado.agregarRegistros(objMatComprado);
            }

    
   }
       archiMatComprado.mostrarRegistros();
}
int main(){
setlocale (LC_ALL, "Spanish");


    ArchivoObras archiObras("Obras.dat");
    Obra objObra;
    ArchivoMateriales archiMateriales("Materiales.dat");
    Material objMaterial;
    ArchivoProveedores archiProve("Proveedores.dat");
    Proveedor objProveedor;
    ArchivoCompras archiCompras("Compras.dat");
    Compra objCompra;

 int opc=0, agrego;
    while(true){
        system("cls");
        cout << "************MENU**************" << endl;
        cout << "1. CARGAR OBRA Y A LA VEZ AGREGA" << endl;
        cout << "2. CARGAR MATERIALES Y A LA VEZ AGREGA" << endl;
        cout << "3. CARGAR COMPRAS Y A LA VEZ AGREGA" << endl;
        cout << "4. CARGAR PROVEEDORES Y A LA VEZ AGREGA" << endl;
        cout << "5. Generacion de archivos con proveedores a los que no se le compraron en el año actual. Registrando num Proveedor. nombre y la provincia del prov." << endl;
        cout << "6. Tipo de material con menos cantidad de materiales." << endl;
        cout << "7. Genera Vec dinamico con los materiales y listarlo segun el material que se ingresa por teclado." << endl;
        cout << "8. Genera Vec dinamico con las compras y listar las compras del vector que pertenezcan a un cod de material ingresado por teclado." << endl;
        cout << "9. Generar Vec dinamico con todas las compras y listar luego las compras del vector con un importe menor a un valor que se ingrese por teclado." << endl;
        cout << "PUNTO 5 SE ENCUENTRA EN EL .h EN LA CLASE OBRA." << endl;
        cout << "10.  La provincia con más proveedores" << endl;
        cout << "11. Genera archivo con los materiales que se haya comprado en el año actual. Registrando el cod de material, tipo y marca" << endl;
        cout << "12. MOSTRAR .DAT DE LOS MATERIALES." << endl;
        cout << "13. MOSTRAR .DAT DE LAS OBRAS." << endl;
        cout << "14. MOSTRAR .DAT DE LAS COMPRAS." << endl;
        cout << "15. MOSTRAR .DAT DE LOS PROVEEDORES." << endl;
       
        cout << "*****************************" << endl;
        cout << "INGRESE OPCION" << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                cout << "CARGAR OBRA- " << endl;
                  objObra.Cargar();
                cout << "AGREGAMOS EL ARCHIVO .DAT" << endl;
                        archiObras.grabarRegistro(objObra);
                        break;
                        
                if (agrego == 1){
                    cout << "SE AGREGO CORRECTAMENTE EL .DAT." << endl;
                }
                else {
                    cout << "REALIZA LA CARGA DE NUEVO." ;
                }
                system("pause");
                
         
             case 2:
                cout << "CARGAR MATERIAL- " << endl;
                   objMaterial.Cargar();
                cout << "AGREGAMOS EL ARCHIVO .DAT" << endl;
                        agrego=archiMateriales.grabarRegistro(objMaterial);
                    
                if (agrego == 1){
                    cout << "SE AGREGO CORRECTAMENTE EL .DAT." << endl;
                }
                else {
                    cout << "REALIZA LA CARGA DE NUEVO." ;
                }
                system("pause");
                        break;
            
             case 3:
                cout << "CARGAR COMPRAS- " << endl;
             objCompra.Cargar();
                cout << "AGREGAMOS EL ARCHIVO .DAT" << endl;
                   agrego=archiCompras.grabarRegistro(objCompra);
                        
                if (agrego == 1){
                    cout << "SE AGREGO CORRECTAMENTE." << endl;
                }
                else {
                    cout << "REALIZA LA CARGA DE NUEVO." ;
                }
                system("pause");
                        break;
            
              case 4:
                cout << "CARGAR PROVEEDORES- " << endl;
                objProveedor.Cargar();
                cout << "AGREGAMOS EL ARCHIVO .DAT" << endl;
                        agrego=archiProve.grabarRegistro(objProveedor);
                        
                if (agrego == 1){
                    cout << "SE AGREGO CORRECTAMENTE el .DAT." << endl;
                }
                else {
                    cout << "REALIZA LA CARGA DE NUEVO." ;
                }
                system("pause");
                        break;   
              case 5:
                  cout << "PUNTO A: " << endl;
                    SolucionPunto1();
                    system("pause");
                break;
              case 6:
                cout << "PUNTO B: " << endl;
                SolucionPunto2();
                system("pause");
                break;
              case 7:
                cout << "PUNTO C: " << endl;
                SolucionPunto3();
                system("pause");
                break;
            case 8: 
                cout << "PUNTO Bbis: " << endl;
                    SolucionPunto3bis();
                    system("pause");
                    break;
            case 9: cout << "PUNTO Bbis3: " << endl;
            SolucionPunto3bis3();
            system("pause");
            break;
            case 10: cout << "PUNTO 6: " << endl;
            ProvinciaConMasProveedores();
            system("pause");
            break;
            case 11: cout << "PUNTO 7: " << endl;
            PuntoAB();
            system("pause");
            break;
            case 12: cout << "**MATERIALES** " << endl << endl;
            archiMateriales.mostrarRegistros();
            system("pause");
            break;
            case 13: cout << "**OBRAS** " << endl << endl; 
            archiObras.mostrarRegistros();
            system("pause");
            break;
            case 14: cout << "**COMPRAS** " << endl << endl;
            archiCompras.mostrarRegistros();
            system("pause");
            break;
            case 15: cout << "**PROVEEDORES** " << endl << endl;
            archiProve.mostrarRegistros();
            system("pause");
            break;
            
            
        }
    }
/*

///PUNTO 3, Declaramos 2 objetos con los valores que va a recibir mi constructor.
    Obra obj(5), objObra2(10);
    
        if(obj > objObra2){
                                                    ///SI ponemos en el codigoRestaurante (1er parametro) 10 en obj y otro 10 en obj2 muestra por pantalla son iguales;
            cout << "El objeto uno es menor" << endl;
        }
        else {
            cout << "el objeto 2 es mayor" << endl;
        }
*/
cout << endl;
system ("pause");

	return 0;
}