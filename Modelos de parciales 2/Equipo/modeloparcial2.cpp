///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

#include "parcial1l.h"

const char *ArchiJugadores=("jugadores.dat");
const char *ArchiEquipos=("equipos.dat");
const char *ArchiDeportes=("deportes.dat");


///a) Generar un archivo con los equipos que tengan al menos 10 jugadores inscriptos.
///Cada registro debe tener el ID de equipo, el nombre y la categoría.



//Hacer un archivo con los deportes que tengan jugadores de todos los claustros. 
//Los registros del archivo nuevo deben tener el mismo formato que el archivo de deportes.
/// e)Crear un vector dinámico con los equipos de nivel inicial. Listar el vector.
///ASIGNACION DE MEMORIA NOS PERMITE AJUSTAR UN VECTOR AL TAMAÑO EXACTO DE LO QUE PIDE


///Para Punto A

int contarJugadores(int equipo){        ///FUNCION QUE CUENTA JUGADORES
ArchivoJugadores archiJ("jugadores.dat");
Jugador objJ;
int cantRegJ=archiJ.contarRegistros();
int cantJugadores=0;

for(int i=0; i<cantJugadores; i++){
        objJ=archiJ.leerRegistro(i);
        
        if(objJ.getIdEquipo() == equipo){
            cantJugadores++;
            }
    }
    return cantJugadores;
}

int buscarDeporte(int equipo){              ///Funcion que devuelve el ID DEL DEPORTE
ArchivoJugadores archiJ("jugadores.dat");
Jugador objJ;
int cantRegJ=archiJ.contarRegistros();

for (int i=0; i<cantRegJ; i++){
    objJ=archiJ.leerRegistro(i);
    
    if(objJ.getIdEquipo() == equipo){
        return objJ.getIdDeporte();
    }
}
return -1;
}

int buscarCategoria(int deporte){
ArchivoDeportes archiD("deportes.dat");
Deporte objD;
int cantRegD=archiD.contarRegistros();

for(int i=0; i<cantRegD; i++){
    objD=archiD.leerRegistro(i);
    
    if(objD.getIdDeporte() == deporte){
        return objD.getIdCtegoria();
    }
}    
    return -1;
}



void puntoA();
bool estanLosCuatro(int deporte);
void puntoB();
void PuntoC();
bool ObtenerID (int idDeporte);
void PuntoD();
void PuntoB1();
void PuntoA2();
void PuntoB2();



int main(){
    
    ArchivoJugadores archiJugadores(ArchiJugadores);
    Jugador objJugador;
    ArchivoEquipos archiEquipos(ArchiEquipos);
    Equipo objEquipos;
    ArchivoDeportes archiDeportes(ArchiDeportes);
    Deporte objDeportes;
    
      int opc=0, agrego;
    while(true){
        system("cls");
        cout << "************MENU**************" << endl;
        cout << "1. CARGAR JUGADORES Y A LA VEZ AGREGA" << endl;
        cout << "2. MOSTRAR JUGADORES" << endl;
        cout << "3. CARGAR EQUIPOS Y A LA VEZ AGREGA" << endl;
        cout << "4. MOSTRAR EQUIPOS" << endl;
        cout << "5. CARGAR DEPORTE Y A LA VEZ AGREGA" << endl;
        cout << "6. MOSTRAR DEPORTE" << endl;
        cout << "7. PUNTO A" << endl;
        cout << "8. PUNTO B" << endl;
        cout << "9. PUNTO C. SObrecarga" << endl;
        cout << "10. PUNTO D" << endl;
        cout << "11. PUNTO B1" << endl;
        cout << "12. PUNTO C1. Sobrecarga" << endl;
        cout << "13. PUNTO A2" << endl;
        cout << "*****************************" << endl;
        cout << "INGRESE OPCION" << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                cout << "CARGAR JUGADORES- " << endl;
                    objJugador.CargarJugador();
                cout << "AGREGAMOS EL ARCHIVO .DAT" << endl;
                        agrego=archiJugadores.grabarRegistro(objJugador);
                        break;
                        
                if (agrego == 1){
                    cout << "SE AGREGO CORRECTAMENTE." << endl;
                }
                else {
                    cout << "REALIZA LA CARGA DE NUEVO." ;
                }
                system("pause");
                
            case 2:
                cout << "MOSTRAR JUGADORES DEL .DAT-" << endl;
                   archiJugadores.mostrarRegistros();
                    system("pause");
                        break;
             case 3:
                cout << "CARGAR EQUIPOS- " << endl;
                    objEquipos.Cargar();
                cout << "AGREGAMOS EL ARCHIVO .DAT" << endl;
                        agrego=archiEquipos.grabarRegistro(objEquipos);
                        
                if (agrego == 1){
                    cout << "SE AGREGO CORRECTAMENTE." << endl;
                }
                else {
                    cout << "REALIZA LA CARGA DE NUEVO." ;
                }
                system("pause");
                        break;
             case 4:
                cout << "MOSTRAR EQUIPO DEL .DAT-" << endl;
                   archiEquipos.mostrarRegistros();   
                    system("pause");
                        break;
                        
             case 5:
                cout << "CARGAR DEPORTE- " << endl;
                    objDeportes.Cargar();
                cout << "AGREGAMOS EL ARCHIVO .DAT" << endl;
                        agrego=archiDeportes.grabarRegistro(objDeportes);
                        
                if (agrego == 1){
                    cout << "SE AGREGO CORRECTAMENTE." << endl;
                }
                else {
                    cout << "REALIZA LA CARGA DE NUEVO." ;
                }
                system("pause");
                        break;
              case 6:
                cout << "MOSTRAR DEPORTES DEL .DAT-" << endl;
                   archiDeportes.mostrarRegistros();
                    system("pause");
                        break;       
              case 7:
                cout << "PUNTO A- " << endl;
                        puntoA();
                        system("pause");
                        break;       
            case 8:
                cout << "PUNTO B-" << endl;
                    puntoB();
                        break; 
            case 9:
                cout << "PUNTO C-" << endl;
                 //   PuntoC();     LA FUNCION ESTA IRÍA EN LA CLASE DEL JUGADOR
                        break;
            case 10:
                cout << "PUNTO D-" << endl;
               //     PuntoD();     ///REVISAR
                        break;
            case 11:
                cout << "PUNTO B1-" << endl;
                        PuntoB1();
               
                system("pause");
                break;
            case 12:
                cout << "PUNTO C1-" << endl;
                 //       puntoC1();        LA FUNCION ESTA IRÍA EN LA CLASE DEL JUGADOR
                system("pause");
                break;
            case 13:
                cout << "PUNTO A2-" << endl;
                PuntoA2();
                system("pause");
                break;
            case 14:
                cout << "PUNTO B2-" << endl;
               // PuntoB2();
                system("pause");
                break;
            case 15:
                cout << "PUNTO C2-" << endl;
            //    PuntoC2();            LA FUNCION ESTA IRÍA EN LA CLASE DE JUGADOR.
                system("pause");
                break;
            cout << "****************************************" << endl;

	cout<<endl;
	system("pause");
	return 0;
        }
    }
}


class Equipo10Jugadores{

private:
    int idEquipo, categoria;
    char nombre[25];
    bool estado;
public:
    
    void setIdEqupo(int idE){idEquipo= idE;}
    void setCategoria(int c){categoria= c;}
    void setNombre(const char* n){strcpy(nombre,n);}
    void setEstado(bool e){estado=e;}
    
    int getIdEquipo(){return idEquipo;}
    int getCategoria(){return categoria;}
    const char* getNombre(){return nombre;}
    
    void mostrar(){
    
        cout << "ID EQUIPO:" << idEquipo << endl;
        cout << "NOMBRE:" << nombre << endl;
        cout << "CATEGORIA:" << categoria << endl;
    }


};

class Archivo10Jugadores{

private:
        char nombre[30];
public:
       Archivo10Jugadores (const char* n){strcpy (nombre,n);}

    Equipo10Jugadores leerRegistro(int pos){
    Equipo10Jugadores obj10Jugadores;   
    FILE *p;
    p= fopen(nombre,"rb"); 
        if(p==NULL) return obj10Jugadores;
    fseek (p,sizeof obj10Jugadores*pos,0);     
    fread (&obj10Jugadores,sizeof obj10Jugadores, 1, p);
        fclose(p);
    return obj10Jugadores;
    }
    
     int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Equipo10Jugadores);
    }
    
    int agregarRegistros(Equipo10Jugadores obj10Jugadores){
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int valor=fwrite(&obj10Jugadores, sizeof obj10Jugadores,1,p);
        fclose(p);
        return valor;
    
    }
    
    int mostrarRegistros(){
        Equipo10Jugadores read;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        while(fread(&read,sizeof read,1,p)== 1){
            read.mostrar();
            cout << endl;
        }
    }
};
void puntoA(){
    
Archivo10Jugadores archi10Jugadores("10Jugadores.dat");
Equipo10Jugadores objEquipo10jugadores;
ArchivoEquipos archiEquipo("equipos.dat");
Equipo objEquipo;
ArchivoJugadores archiJugadores("jugadores.dat");
Jugador objJugador;
ArchivoDeportes archiD("deportes.dat");
Deporte objDep;

int cantRegistroEqui=archiEquipo.contarRegistros();
int cantRegistroJuga=archiJugadores.contarRegistros();
int cantRegDep=archiD.contarRegistros();
int cantJugadores=0;
 
    for(int i=0; i<cantRegistroEqui; i++){
        objEquipo=archiEquipo.leerRegistro(i);          ///LEO EQUIPO
 
 
        for(int x=0; x<cantRegistroJuga; x++){
            objJugador=archiJugadores.leerRegistro(x);  ///LEO JUGADOR
           
           for(int y=0; y<cantRegDep; y++){
                 if(objJugador.getIdEquipo() == objEquipo.getIdEquipo() && objJugador.getIdDeporte() == objDep.getIdDeporte()){               ///COMPARO LA VINCULACION ENTRE ATRIBUTOS 
                    cantJugadores++;
                 }
                  if (cantJugadores >=2)
                   objEquipo10jugadores.setIdEqupo(objEquipo.getIdEquipo());
                   objEquipo10jugadores.setNombre(objEquipo.getNombre());
                   objEquipo10jugadores.setCategoria(objDep.getIdCtegoria());
                
                
                    archi10Jugadores.agregarRegistros(objEquipo10jugadores);
                }
                
          }       
              
                
                /*if(agrego == 1){
                    cout << "SE AGREGO CORRECTAMENTE." << endl;
                }
                else{
                    cout << "FALLA AL AGREGAR." << endl;
                }*/
            
            
   
   //cout << cantJugadores << endl;
   //system("pause");
   
          // if(cantJugadores >2){
                
            /*for(int y=0; y<cantRegistroDep; y++){
                objDeporte=archiDeportes.leerRegistro(y);
              
                 
                   objEquipo10jugadores.setIdEqupo(objEquipo.getIdEquipo());
                   objEquipo10jugadores.setNombre(objEquipo.getNombre());
                   objEquipo10jugadores.setCategoria(objDeporte.getIdCtegoria());
                
                
                    archi10Jugadores.agregarRegistros(objEquipo10jugadores);
                if(agrego == 1){
                    cout << "SE AGREGO CORRECTAMENTE." << endl;
                }
                else{
                    cout << "FALLA AL AGREGAR." << endl;
                }
            
            }*/
     
       
            
   
        }
                archi10Jugadores.mostrarRegistros();
    }
       


void puntoB(){
            ///PASOS
    Archivo10Jugadores archi10Jugadores("10Jugadores.dat");
    Equipo10Jugadores  *v;           ///DECLARO PUNTERO EQUIPO
    int cantReg;
    cantReg=archi10Jugadores.contarRegistros();
    if(cantReg==0){
        cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        return;
    }
    //out << cantReg;
    //system("pause");
    v=new Equipo10Jugadores[cantReg];       ///PIDO MEMORIA
    if(v==NULL) return;                     ///ChEQUEO MEMORIA
    for(int i=0;i<cantReg;i++){
            v[i]=archi10Jugadores.leerRegistro(i);      ///LEO REGISTROS Y LSO COPIO AL VECTOR
    }
    for(int i=0;i<cantReg;i++){
        v[i].mostrar();         ///MUESTRO VECTOR
    }
    delete v;           ///DEVUELVO MEMORIA
}

/*
///Sobrecargar el operador == para comparar un objeto Jugador con un objeto Deporte. Debe devolver verdadero cuando coinciden los Id de deporte
///en la clase Jugador iría el código
void PuntoC(){


bool operator==(const Deporte &obj){
    if(idDeporte==obj.getIDdeporte()) return true;
    return false;
 }
}
*/


///Hacer un archivo con los deportes que tengan jugadores de todos los claustros. Los
///registros del archivo nuevo deben tener el mismo formato que el archivo de deportes.
class JugadorTodoLosClaustros{

private:
    int idDeporte, anioOrigen, idCategoria;
    char nombre[30];
    bool estado;
    
public:
    void setIdDeporte(int idD){idDeporte= idD;}
    void setAnioOrigen(int aO){anioOrigen= aO;}
    void setNombre(const char* n){strcpy(nombre,n);}
    void setEstado(bool e){estado=e;}
    
    int getIdDeporte(){return idDeporte;}
    int getAnioOrigen(){return anioOrigen;}
    const char* getNombre(){return nombre;}
    
    void mostrar(){
    
        cout << "ID DEPORTE:" << idDeporte << endl;
        cout << "ANIO ORIGEN:" << anioOrigen << endl;
        cout << "NOMBRE:" << nombre << endl;
       
    }
};


class ArchivoTodosLosClaustros{
    
private:
        char nombre[30];
public:
       ArchivoTodosLosClaustros (const char* n){strcpy (nombre,n);}

    JugadorTodoLosClaustros leerRegistro(int pos){
    JugadorTodoLosClaustros objTodoLosClaus;   
    FILE *p;
    p= fopen(nombre,"rb"); 
        if(p==NULL) return objTodoLosClaus;
    fseek (p,sizeof objTodoLosClaus*pos,0);     
    fread (&objTodoLosClaus,sizeof objTodoLosClaus, 1, p);
        fclose(p);
    return objTodoLosClaus;
    }
    
     int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(JugadorTodoLosClaustros);
    }
    
    int agregarRegistros(Deporte objDeporte){
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int valor=fwrite(&objDeporte, sizeof objDeporte,1,p);
        fclose(p);
        return valor;
    
    }
    
    int mostrarRegistros(){
        JugadorTodoLosClaustros read;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        while(fread(&read,sizeof read,1,p)== 1){
            read.mostrar();
            cout << endl;
        }
    }





};

bool ObtenerID (int idDeporte){
ArchivoJugadores archiJugadores("jugadores.dat");
Jugador objJugador;

int cantRegistrosJugadores=archiJugadores.contarRegistros();
int posJug=0;
bool misClaustros[4]={0};

while(posJug<cantRegistrosJugadores){
    objJugador=archiJugadores.leerRegistro(posJug);
    
    if(objJugador.getIdDeporte() == idDeporte){
        
        misClaustros[objJugador.getClaustro() -1] = true;
    }
    posJug++;
}
    
for(int i=0; i<4; i++){
        
            if(misClaustros[i] == false){
                return false;
            }
            else{
                return true;
            }
        }

    }
 
 
 /*
void puntoD(){

ArchivoDeportes archiDeportes("deportes.dat");
Deporte objDeporte;
ArchivoTodosLosClaustros archiTodosLosClaustros("TodosClaustros");
JugadorTodoLosClaustros objTodoLosClaus;

int cantRegistrosDepo= archiDeportes.contarRegistros();
bool cuatroClaustros;
int pos=0;
    while(pos<cantRegistrosDepo){
        objDeporte=archiDeportes.leerRegistro(pos);
         
        cuatroClaustros= ObtenerID(objDeporte.getIdDeporte());
                
                if(cuatroClaustros ){
                    cout << "ID DEPORTE: " << objDeporte.getIdDeporte() << endl;
                  archiTodosLosClaustros.agregarRegistros(objDeporte);
            }
        
        }

}
    */
    
void PuntoB1(){
ArchivoEquipos archiEquipo("equipos.dat");  ///ABRO MI ARCHIVO EQUIPO
Equipo *vEquipo, objEquipo;     ///DECLARO PUNTERO

int cantEquiposNivel1=0;                           ///INICIALIZO MI CONTADOR
int cantRegistro=archiEquipo.contarRegistros();  ///CUENTO LA CANTIDAD DE REGISTROS
int pos=0;                                       ///INICIALIZO LA POSICION PARA EL WHILE
    while(pos<cantRegistro){            ///SI POS ES MENOR A LA CANTTIDAD DE REGISTROS, ----> QUE ENTRE
        objEquipo=archiEquipo.leerRegistro(pos);
            if (objEquipo.getNivel()== 1){      ///PREGUNTO EN MI OBJETO DE EQUIPO AL GET SI EL NIVEL QUE ME INGRESAN ES EL 1 ( NIVEL INICIAL)
                cantEquiposNivel1++;            ///SI ES 1 QUE ME CUENTE LA CANTIDAD DE EQUIPOS QUE HAY CON EL NIVEL 1
            }
    pos++;                                      ///POS++= PARA QUE SIGA GIRANDO EL WHILE
}
  
 
 cout << cantEquiposNivel1 << endl;             ///PRUEBA POR PANTALLA PARA VER CUANTOS HAY (ME MUESTRA 0, SABIENDO QUE TENGO 1 CARGADO)
    system("pause");
    
    if(cantRegistro == 0){                          /// SI LA CANTIDAD DE REGISTRO ES 0 NO HAY REGISTROS.
        cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        return;
    }
    
vEquipo=new Equipo[cantEquiposNivel1];       ///PIDO MEMORIA CON EL PUNTERO CREADO. CON LA CLASE Y ENTRE [] PARA CREAR EL VECTOR CON LAS CANTIDADES DE LSO EQUIPOS DEL NIVEL 1
if(vEquipo==NULL)return;    ///CHEQUEO DE MEMORIA
for(int i=0; i<cantEquiposNivel1; i++){     ///CREO EL FOR 
    
    vEquipo[i]=archiEquipo.leerRegistro(i); /// LEO REGISTRO Y LOS COPIO AL VECTOR
}
for(int i=0; i<cantEquiposNivel1; i++){
    vEquipo[i].Mostrar();   ///MUESTRO VECTOR
}
    delete vEquipo; ///DEVUELVO MEMORIA
    
}

/*Sobrecargar el operador == para la clase Jugador, que reciba un valor entero y lo compare con el Id de claustro

///IRIA EN LA CLASE JUGADOR
void PuntoC1(){
bool operator == (const Jugador &obj){
    if(idClaustro==obj.getClaustro()) return true;
    return false;
}
}
*/

///PUNTO A2******************************

class JugadorMatricula{

private:
    int DNI, claustro;
    char nombre[30], apellido[30], nombreDepo[20];
    
public:
    
    void setDni(int Dni){DNI=Dni;}
    void setClaustro(int cl){claustro=cl;}
    void setNombre(const char * n){strcpy(nombre,n);}
    void setApellido(const char* a){strcpy(apellido, a);}
    void setNombreDepo(const char* np){strcpy(nombreDepo,np);}
    
    int getDNI(){return DNI;}
    int getClaustro(){return claustro;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getNombreDepo(){return nombreDepo;}
    
    void Mostrar(){
        cout << "DNI: " << DNI << endl;
        cout << "CLAUSTRO: " << claustro << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "APELLIDO: " << apellido << endl;
        cout << "NOMBRE DEPORTE: " << nombreDepo << endl;
    }
    
};

class ArchivoJugadoresMatricula{

private:
        char nombre[30];
public:
       ArchivoJugadoresMatricula (const char* n){strcpy (nombre,n);}

    JugadorMatricula leerRegistro(int pos){
    JugadorMatricula objJugaMatri;   
    FILE *p;
    p= fopen(nombre,"rb"); 
        if(p==NULL) return objJugaMatri;
    fseek (p,sizeof objJugaMatri*pos,0);     
    fread (&objJugaMatri,sizeof objJugaMatri, 1, p);
        fclose(p);
    return objJugaMatri;
    }
    
     int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(JugadorMatricula);
    }
    
    int agregarRegistros(JugadorMatricula objJugaMatri){
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int valor=fwrite(&objJugaMatri, sizeof objJugaMatri,1,p);
        fclose(p);
        return valor;
    
    }
    
    int mostrarRegistros(){
        JugadorMatricula read;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        while(fread(&read,sizeof read,1,p)== 1){
            read.Mostrar();
            cout << endl;
        }
    }

};

void PuntoA2(){
ArchivoJugadoresMatricula archiJugMatri("jugMatri.dat");
JugadorMatricula objJugadorMatri;
ArchivoJugadores archiJugadores("jugadores.dat");
Jugador objJugador;
ArchivoDeportes archiDeportes("deportes.dat");
Deporte objDeporte;
int pos=0,pos1=0;
int cantRegistroJ= archiJugadores.contarRegistros();
int cantRegistroD= archiDeportes.contarRegistros();

while(pos<cantRegistroJ){
    objJugador=archiJugadores.leerRegistro(pos);
    
        
    pos1=0;
    while(pos1<cantRegistroD){
        objDeporte=archiDeportes.leerRegistro(pos1);
        
       if(objJugador.getMatricula() > 10000 && objJugador.getInscripcion().getAnio() == 2023){
            
            objJugadorMatri.setNombre(objJugador.getNombre());
            objJugadorMatri.setApellido(objJugador.getApellido());
            objJugadorMatri.setClaustro(objJugador.getClaustro());
            objJugadorMatri.setNombreDepo(objDeporte.getNombre());
            
            
            archiJugMatri.agregarRegistros(objJugadorMatri);
               
            
        }
            
            
        
        
        pos1++;
    }
    
    pos++;
 }
    archiJugMatri.mostrarRegistros();
}
/*
void PuntoB2(){

}
ArchivoJugadores archiJugadores("jugadores.dat");  ///ABRO MI ARCHIVO JUGADOR
Jugador *vJugador, objJugador;     ///DECLARO PUNTERO
int equipoJugador;
cout << "INGRESE NUMERO DE EQUIPO: " << endl;
cin >> equipoJugador;

    int cantRegistroJugador=archiJugadores.contarRegistros();  ///CUENTO LA CANTIDAD DE REGISTROS
        if(cantRegistroJugador == 0){                          /// SI LA CANTIDAD DE REGISTRO ES 0 NO HAY REGISTROS.
            cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        return;
    }
    
    for(int i=0; i<cantRegistroJugador; i++){            ///SI POS ES MENOR A LA CANTTIDAD DE REGISTROS, ----> QUE ENTRE
        
            if (objEquipo.getNivel()== 1){      ///PREGUNTO EN MI OBJETO DE EQUIPO AL GET SI EL NIVEL QUE ME INGRESAN ES EL 1 ( NIVEL INICIAL)
                cantEquiposNivel1++;            ///SI ES 1 QUE ME CUENTE LA CANTIDAD DE EQUIPOS QUE HAY CON EL NIVEL 1
            }
                                        ///POS++= PARA QUE SIGA GIRANDO EL WHILE
}
  
 
 cout << cantEquiposNivel1 << endl;             ///PRUEBA POR PANTALLA PARA VER CUANTOS HAY (ME MUESTRA 0, SABIENDO QUE TENGO 1 CARGADO)
    system("pause");
    
    
    
vEquipo=new Equipo[cantEquiposNivel1];       ///PIDO MEMORIA CON EL PUNTERO CREADO. CON LA CLASE Y ENTRE [] PARA CREAR EL VECTOR CON LAS CANTIDADES DE LSO EQUIPOS DEL NIVEL 1
if(vEquipo==NULL)return;    ///CHEQUEO DE MEMORIA
for(int i=0; i<cantEquiposNivel1; i++){     ///CREO EL FOR 
    
    vEquipo[i]=archiEquipo.leerRegistro(i); /// LEO REGISTRO Y LOS COPIO AL VECTOR
}
for(int i=0; i<cantEquiposNivel1; i++){
    vEquipo[i].Mostrar();   ///MUESTRO VECTOR
}
    delete vEquipo; ///DEVUELVO MEMORIA
    
*/
///Agregar una sobrecarga para el operador > de la clase Jugador de manera tal que sea verdadero cuando el año de inscripción 
//sea mayor a un valor de año que se recibe cmo parámetro.
/*
void PuntoC2(){

bool operator > (const Jugador &objJugador){
    if(objJugador.getInscripcion() > fechaIns) return true;
    return false;

    }


    }
    */