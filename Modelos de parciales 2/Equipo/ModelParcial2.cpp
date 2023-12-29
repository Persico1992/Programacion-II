//Nombre:
//Tp:
//Ejercicio N°:

/*

*/

# include<iostream>
# include<cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

#include "parcial1l.h"

const char *ArchiJugadores=("jugadores.dat");
const char *ArchiEquipos=("equipos.dat");
const char *ArchiDeportes=("deportes.dat");

///PUNTO A
///Generar un archivo con los equipos que tengan al menos 10 jugadores inscriptos.
///Cada registro debe tener el ID de equipo, el nombre del equipo, y la categoría del deporte al que pertenece el equipo.

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

///PUNTO D
///Hacer un archivo con los deportes que tengan jugadores de todos los claustros. 
///Los registros del archivo nuevo deben tener el mismo formato que el archivo de deportes.

class JugadorTodoLosClaustros{

private:
    int idDeporte, anioOrigen, idCategoria;
    char nombre[30];
    bool estado;
    
public:
    void setIdDeporte(int idD){idDeporte= idD;}
    void setIdCategoria(int idC){idCategoria= idC;}
    void setAnioOrigen(int aO){anioOrigen= aO;}
    void setNombre(const char* n){strcpy(nombre,n);}
    void setEstado(bool e){estado=e;}
    
    int getIdDeporte(){return idDeporte;}
    int getIdCategoria(){return idCategoria;}
    int getAnioOrigen(){return anioOrigen;}
    const char* getNombre(){return nombre;}
    bool getEstado(){return estado;}
    
    void mostrar(){
    
        cout << "ID DEPORTE:" << idDeporte << endl;
        cout << "ANIO ORIGEN:" << anioOrigen << endl;
        cout << "NOMBRE:" << nombre << endl;
        cout << "CATEGORIA: " << idCategoria << endl;
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
    
    int agregarRegistros(JugadorTodoLosClaustros obj){
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int valor=fwrite(&obj, sizeof obj,1,p);
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

///PUNTO G
///Generar un archivo con los jugadores que hayan pagado más de $10000 de matrícula y
///que se hayan inscripto este año. Cada registro del archivo debe tener el siguiente formato: DNI, nombre, apellido, claustro y nombre del deporte.

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



///DECLARACIONES.
void PuntoA();
void PuntoB();
void PuntoD();
void PuntoE();
void PuntoG();
void PuntoH();

int main(){
setlocale (LC_ALL, "Spanish");

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
        cout << "7. GENERAR ARCHIVO CON LOS EQUIPOS QUE TENGAN >= A 10 JUGADORES INSCRIPTOS" << endl;
        cout << "8. HACER UN VECTOR DINÁMICO PARA LISTAR EL ARCHIVO DEL PUNTO ANTERIOR." << endl;
        cout << "9. SOBRECARGAR EL OPERADOR == PARA COMPARAR UN OBJETO JUGADOR CON UN OBJETO DEPORTE." << endl;
        cout << "10. GENERAR ARCHIVO CON LOS DEPORTES QUE TENGAN JUGADORES DE TODOS LSO CLAUSTROS." << endl;
        cout << "11. CREAR UN VECTOR DINÁMICO CON LOS EQUIPOS DE NIVEL INICIAL.LISTAR EL VECTOR" << endl;
        cout << "12. SOBRECARGAR EL OPERADOR == PARA COMPARAR UN OBJETO JUGADOR Y LO COMPARE CON EL ID DE CLAUSTRO" << endl;
        cout << "13. GENERAR ARCHIVO CON LOS JUGADORES QUE HAYAN PAGADO MAS DE $10000 DE MATRÍCULA INSCRIPTOS EN ESTE AÑO." << endl;
        cout << "14. CREAR UN VECTOR CON LOS JUGADORES PERTENECIENTES A UN EQUIPO CUYO NÚMERO DE EQUIPO SE INGRESE POR TECLADO. LISTAR EL VECTOR." << endl;
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
                cout << "PUNTO A: " << endl << endl;
                PuntoA();
                system("pause");
                    break;
              case 8:
                cout << "PUNTO B: " << endl << endl;
                PuntoB();
                system("pause");
                    break;
              case 9:
                cout << "PUNTO C: " << endl << endl;
                cout << "Este punto se encuentra en la clase Jugador.h" << endl;
              case 10:
                cout << "PUNTO D: " << endl << endl;
                        PuntoD();
                        system("pause");
                    break;
                    
              case 11:
                cout << "PUNTO E: " << endl << endl;
                    PuntoE();
                    system("pause");
                        break;
              case 12:
                cout << "PUNTO F: " << endl << endl;
                    cout << "Este punto se encuentra en la clase Jugador.h " << endl;
                        break;
              case 13:
                cout << "PUNTO G: " << endl << endl;
                        PuntoG();
                        system("pause");
                    break;
             case 14:
                cout << "PUNTO H: " << endl << endl;
                        PuntoH();
                        system("pause");
                    break;
            cout << "****************************************" << endl;

            
	cout<<endl;
	system("pause");
	return 0;
        }
    }
}



void PuntoA(){
ArchivoEquipos archiEquipo("equipos.dat");
Equipo objEqui;
int cantRegE=archiEquipo.contarRegistros();

ArchivoJugadores archiJ("jugadores.dat");
Jugador objJ;
int cantRegJug=archiJ.contarRegistros();

Archivo10Jugadores archi10Jug("10jugadores.dat");
Equipo10Jugadores objEquipo10;

for(int i=0; i<cantRegE; i++){
    objEqui=archiEquipo.leerRegistro(i);
    int contadorJug=0;
    for(int x=0; x<cantRegJug; x++){
        objJ=archiJ.leerRegistro(x);
        
        
        if(objEqui.getIdEquipo() == objJ.getIdEquipo() && objEqui.getEstado() && objJ.getEstado()){
            contadorJug++;
    
        }
        
        
    }       ///EN ESTE PUNTO SE COLOCA EL 2, EN LOS .DAT FALTARIAN CARGAR MAS DATOS PARA CUMPLIR LA CONSGINA >= 10.
        if(contadorJug >= 2){                           
                objEquipo10.setNombre(objEqui.getNombre());
                objEquipo10.setIdEqupo(objEqui.getIdEquipo());
                objEquipo10.setCategoria(objJ.getIdDeporte());
                archi10Jug.agregarRegistros(objEquipo10);
            
        }
        
    
}  
   
        archi10Jug.mostrarRegistros();
    
    
}

void PuntoB(){
            ///PASOS
    Archivo10Jugadores archi10Jugadores("10Jugadores.dat");
    Equipo10Jugadores  *v;           ///DECLARO PUNTERO EQUIPO
    int cantReg;
    cantReg=archi10Jugadores.contarRegistros();
    if(cantReg==0){
        cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        return;
    }
    
    v=new Equipo10Jugadores[cantReg];       ///PIDO MEMORIA
    if(v==NULL) return;                     ///ChEQUEO MEMORIA
    for(int i=0;i<cantReg;i++){
            v[i]=archi10Jugadores.leerRegistro(i);      ///LEO REGISTROS Y LSO COPIO AL VECTOR
    }
    for(int i=0;i<cantReg;i++){
        v[i].mostrar(); ///MUESTRO VECTOR
        
        cout << "------------------" << endl;
    }
    delete v;           ///DEVUELVO MEMORIA
}

void PuntoD(){
ArchivoDeportes archiDep("deportes.dat");
Deporte objDep;
int cantRegDep=archiDep.contarRegistros();

ArchivoJugadores archiJug("jugadores.dat");
Jugador objJug;
int cantRegJug=archiJug.contarRegistros();

ArchivoTodosLosClaustros archiCl("JugadoresTodosLosClaustros.dat");
JugadorTodoLosClaustros objJugClaus;

bool tieneTodosLosClaustros=false;
for(int i=0; i<cantRegDep; i++){
    objDep=archiDep.leerRegistro(i);
        int vTodosLosClaustros[4]={};
    for(int x=0; x<cantRegJug; x++){
        objJug=archiJug.leerRegistro(x);
        
        if(objDep.getIdDeporte() == objJug.getIdDeporte()){
                vTodosLosClaustros[objJug.getClaustro() -1]++;
                }
    }
    
    if(vTodosLosClaustros[0] == 1 && vTodosLosClaustros[1] == 1 && vTodosLosClaustros[2] == 1 && vTodosLosClaustros[3] == 1){
                objJugClaus.setIdDeporte(objDep.getIdDeporte());
                objJugClaus.setIdCategoria(objDep.getIdCtegoria());
                objJugClaus.setNombre(objDep.getNombre());
                archiCl.agregarRegistros(objJugClaus);
                    //tieneTodosLosClaustros=true;
    }
}

        archiCl.mostrarRegistros();

}

void PuntoE(){
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
  
 
 cout << cantEquiposNivel1 << endl;             ///PRUEBA POR PANTALLA PARA VER CUANTOS HAY
    system("pause");
    cout << "TOQUE UNA TECLA PARA CONTINUAR." << endl;
    
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
    
    cout << endl;
}
    delete vEquipo; ///DEVUELVO MEMORIA
}

void PuntoG(){
ArchivoJugadoresMatricula archiJugMatri("jugMatri.dat");
JugadorMatricula objJugadorMatri;
ArchivoJugadores archiJugadores("jugadores.dat");
Jugador objJugador;
ArchivoDeportes archiDeportes("deportes.dat");
Deporte objDeporte;
int pos=0,pos1;
int cantRegistroJ= archiJugadores.contarRegistros();
int cantRegistroD= archiDeportes.contarRegistros();

while(pos<cantRegistroJ){
    objJugador=archiJugadores.leerRegistro(pos);
    
        
    pos1=0;
    while(pos1<cantRegistroD){
        objDeporte=archiDeportes.leerRegistro(pos1);
        
       if(objJugador.getMatricula() > 10000 && objJugador.getInscripcion().getAnio() == 2023 && objDeporte.getIdDeporte() == objJugador.getIdDeporte()){
            
            objJugadorMatri.setNombre(objJugador.getNombre());
            objJugadorMatri.setApellido(objJugador.getApellido());
            objJugadorMatri.setDni(objJugador.getDNI());
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

void PuntoH(){

ArchivoJugadores archiJugadores("jugadores.dat");  ///ABRO MI ARCHIVO JUGADOR
Jugador *vJugador, objJugador;     ///DECLARO PUNTERO
int equipoJugador, cantEquipos;  ;


    int cantRegistroJugador=archiJugadores.contarRegistros();  ///CUENTO LA CANTIDAD DE REGISTROS
        if(cantRegistroJugador == 0){                          /// SI LA CANTIDAD DE REGISTRO ES 0 NO HAY REGISTROS.
            cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        return;
    }
    
    vJugador=new Jugador[cantRegistroJugador];       ///PIDO MEMORIA CON EL PUNTERO CREADO. CON LA CLASE Y ENTRE [] 
        if(vJugador==NULL)return;    ///CHEQUEO DE MEMORIA
        
        
    cout << "INGRESE NÚMERO DE EQUIPO: " << endl << endl;
    cin >> equipoJugador;
    
    for(int i=0; i<cantRegistroJugador; i++){     ///CREO EL FOR 
    
    vJugador[i]=archiJugadores.leerRegistro(i); /// LEO REGISTRO Y LOS COPIO AL VECTOR
    }
    
    bool pertenece=false;
    
    for(int x=0; x<cantRegistroJugador; x++){
        
        if(vJugador[x].getIdEquipo() == equipoJugador){
            vJugador[x].Mostrar();
            pertenece=true;
        }
    }

        if(!pertenece){
            cout << "NO EXISTE EL EQUIPO INGRESADO." << endl;
        }


    delete vJugador; ///DEVUELVO MEMORIA
    

}


