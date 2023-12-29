#ifndef PARCIAL1L_H_INCLUDED
#define PARCIAL1L_H_INCLUDED

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}


class Fecha{
private:
    int dia,mes, anio;
public:
    void Cargar(){
        cin>>dia;
        cin>>mes;
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

class Jugador{
private:
    int DNI, claustro, idDeporte, idEquipo;
    char nombre[25], apellido[30];
    char email[30];
    int telefono;
    Fecha inscripcion;
    float matricula;
    bool estado;
public:
    ///Getter me muestra
   int getDNI(){return DNI;}
   int getClaustro(){return claustro;}
   int getIdDeporte(){return idDeporte;}
   int getIdEquipo(){return idEquipo;}
   const char* getNombre(){return nombre;}
   const char* getApellido(){return apellido;}
   bool getEstado(){return estado;}
   Fecha getInscripcion(){return inscripcion;}
   float getMatricula(){return matricula;}
   
    ///Setter me guarda
   void setDNI(int d){DNI=d;}
   void setClaustro(int cl){claustro=cl;}
   void setIdDeporte(int idD){idDeporte=idD;}
   void setIdEquipo(int iQ){idEquipo=iQ;}
   void setNombre(const char* n){strcpy(nombre, n);}
   void setApellido(const char* a){strcpy(apellido, a);}
   void setEstado(bool e){estado=e;}
   Fecha setInscripcion(Fecha fi){inscripcion= fi;}
   void setMatricula(float ma){matricula=ma;}
    void Mostrar();
    void CargarJugador();
   
   ///PUNTO C
   bool operator == ( Jugador obj){
    if(idDeporte == obj.getIdDeporte()) return true;
    return false;
 }
 
 ///PUNTO F
 
   // bool operator == ( Jugador obj){
   // if(claustro == obj.getClaustro()) return true;
   // return false;
   // }
};
    void Jugador::CargarJugador(){
        cout << "DNI: " << endl;
        cin >>  DNI;
        cout << "CLAUSTRO: "<< endl;
        cin >> claustro;
        cout << "ID DEPORTE: " << endl;
        cin >> idDeporte;
        cout << "ID EQUIPO: "<< endl;
        cin >> idEquipo;
        cout << "NOMBRE: "<< endl;
        cin >> nombre;
        cout << "APELLIDO: "<< endl;
        cin >> apellido;
        cout << "FECHA: "<< endl;
         inscripcion.Cargar();
        cout << "MATRICULA: $" << endl;
        cin >> matricula;
            
         estado= true;
    }
    void Jugador::Mostrar(){
    
    cout << "DNI: " << DNI<< endl;
    cout << "CLAUSTRO: " << claustro<< endl;
    cout << "ID DEPORTE: " << idDeporte<< endl;
    cout << "ID EQUIPO: " << idEquipo<< endl;
    cout << "NOMBRE: " << nombre<< endl;
    cout << "APELLIDO: " << apellido<< endl;
    cout << "FECHA: " << endl;
    inscripcion.Mostrar();
    cout << "MATRICULA: " << matricula << endl;
    cout << "*****************" << endl << endl;
    }
    
class Deporte{
private:
    int idDeporte, anioOrigen, idCategoria;
    char nombre[30];
    bool estado;
public:
   int getIdDeporte(){return idDeporte;}
   int getIdCtegoria(){return idCategoria;}
   const char *getNombre(){return nombre;}
   bool getEstado(){return estado;}
   

   void setIdDeporte(int idD){idDeporte=idD;}
   void setAnioOrigen(int ao){anioOrigen=ao;}
   void setIdCategoria(int ic){idCategoria=ic;}
   void setNombre(const char * n){strcpy(nombre,n);}
   void setEstado(bool e){estado=e;}
   
   void Mostrar();
   void Cargar(); 
   

};

    void Deporte::Cargar(){
    cout << "NOMBRE: "<< endl;
    cin >> nombre;
    cout << "ID DEPORTE: "<< endl;
    cin >> idDeporte;
    cout << "ANIO ORIGEN: "<< endl;
    cin >> anioOrigen;
    cout << "ID CATEGORIA: "<< endl;
    cin >> idCategoria;
   
    estado = true;
    }

    void Deporte::Mostrar(){
    cout << "NOMBRE : " << nombre<< endl;
    cout << "ID DEPORTE: " << idDeporte<< endl;
    cout << "ANIO ORIGEN: " << anioOrigen<< endl;
    cout << "ID CATEGORIA: " << idCategoria<< endl;
    }
class Equipo{
private:
    int IdEquipo, nivel;
    char nombre[30];
    bool estado;
public:
    int getIdEquipo(){return IdEquipo;}
    int getNivel(){return nivel;}
    const char *getNombre(){return nombre;}
    bool getEstado(){return estado;}

    void setIdEquipo(int ie){IdEquipo=ie;}
    void setNivel(int n){nivel=n;}
    void setNombre(const char * n){strcpy(nombre,n);}
    void setEstado(bool e){estado=e;}
    
    void Mostrar();
    void Cargar();
};
    void Equipo::Cargar(){
    cout << "NOMBRE: "<< endl;
    cin >> nombre;
    cout << "ID EQUIPO: "<< endl;
    cin >> IdEquipo;
    cout << "NIVEL: "<< endl;
    cin >> nivel;
    
    estado = true;
    }

    void Equipo::Mostrar(){
    cout << "NOMBRE: " << nombre<< endl;
    cout << "ID EQUIPO: " << IdEquipo<< endl;
    cout << "NIVEL: " << nivel<< endl;
    }
    
class ArchivoJugadores{
private:
    char nombre[30];
public:
    ArchivoJugadores(const char *n){
        strcpy(nombre, n);
    }
    Jugador leerRegistro(int pos){
        Jugador reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Jugador);
    }
    bool grabarRegistro(Jugador reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    int mostrarRegistros(){
    Jugador objJugador;
    FILE *p;
    p= fopen(nombre,"rb");
        if(p==NULL) return -1;
    while(fread(&objJugador,sizeof objJugador, 1,p)== 1){///Encontro un registro y me muestra el registro
        objJugador.Mostrar();
      cout << endl;  
    }
    
    }
};


class ArchivoDeportes{
private:
    char nombre[30];
public:
    ArchivoDeportes(const char *n){
        strcpy(nombre, n);
    }
    Deporte leerRegistro(int pos){
        Deporte reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Deporte);
    }
    bool grabarRegistro(Deporte reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    int mostrarRegistros(){
    Deporte objDeporte;
    FILE *p;
    p= fopen(nombre,"rb");
        if(p==NULL) return -1;
    while(fread(&objDeporte,sizeof objDeporte, 1,p)== 1){///Encontro un registro y me muestra el registro
        objDeporte.Mostrar();
      cout << endl;  
    }
    
    }
};

class ArchivoEquipos{
private:
    char nombre[30];
public:
    ArchivoEquipos(const char *n){
        strcpy(nombre, n);
    }
    Equipo leerRegistro(int pos){
        Equipo reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Equipo);
    }
    bool grabarRegistro(Equipo reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    int mostrarRegistros(){
    Equipo objEquipo;
    FILE *p;
    p= fopen(nombre,"rb");
        if(p==NULL) return -1;
    while(fread(&objEquipo,sizeof objEquipo, 1,p)== 1){///Encontro un registro y me muestra el registro
        objEquipo.Mostrar();
      cout << endl;  
    }
    
    }
};

#endif // PARCIAL1L_H_INCLUDED
