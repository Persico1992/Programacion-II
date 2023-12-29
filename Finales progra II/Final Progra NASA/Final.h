#ifndef FINAL_H_INCLUDED
#define FINAL_H_INCLUDED

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

class ClasePunto2{
    
private:
    int DNI;
public:
    void setDNI(int d){DNI=d;}
    
    int getDNI(){return DNI;}
    
    
   
};

class Astronauta{
    private:
    int DNI;
    char nombre[50], apellido[50];
    int pais; //entre 1 y 50
    int categoria; //entre 1 y 15

public:
    Astronauta(){};
    Astronauta(ClasePunto2 objP2){
        DNI= objP2.getDNI();    ///ACA NO ESTOY INICIALIZANDO la propiedad del objP2, lo que hago aca es obtener lo que tiene el objP2 para inicializar
        DNI= 0;
        objP2.setDNI(1010);     ///El set metodo me permite setear el dni
    }
    
    ///Los setters se hacen para la carga, en el final poner unicamente los get para no perder tiempo.
    void setDNI(int d){DNI=d;}
    void setNombre(const char* n){strcpy(nombre,n);}
    void setApellido(const char* ap){strcpy(apellido,ap);}
    void setPais(int p){pais=p;}
    void setCategoria(int c){categoria=c;}
    
    int getDNI(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    int getPais(){return pais;}
    int getCategoria(){return categoria;}
    
    void Cargar();
    void Mostrar();
    //Me falta inicializar en la otra clase la propiedad... Al otro como accedo ? atravez del setter y le tengo que pasar un valor 
};

void Astronauta::Cargar(){

    cout << "DNI: " << endl;
    cin >> DNI;
    cout << "NOMBRE: " << endl;
    cargarCadena(nombre,49);
    cout << "APELLIDO: " << endl;
    cargarCadena(apellido,49);
    cout << "PAIS: " << endl;
    cin >> pais;
    cout << "CATEGORIA: " << endl;
    cin >> categoria;

}

void Astronauta::Mostrar(){
    cout << "DNI: " << DNI << endl;
    cout << "NOMBRE: " << nombre << endl;
    cout << "APELLIDO: " << apellido << endl;
    cout << "PAIS: " << pais << endl;
    cout << "CATEGORIA: " << categoria << endl;

}

class Misiones{

private:
    int numMision, DNI;
    Fecha fechaInicio;
    int cargo;
    
public:
   
    void setNumMision(int nm){numMision=nm;}
    void setDNI(int d){DNI=d;}
    void setCargo(int c){cargo=c;}
    void setFechaInicio(Fecha fi){fechaInicio=fi;}
    
    int getNumMision(){return numMision;}
    int getDNI(){return DNI;}
    int getCargo(){return cargo;}
    Fecha getFechaInicio(){return fechaInicio;}
    
    void Cargar();
    void Mostrar();
};
    void Misiones::Cargar(){
        
        cout << "NUMERO DE MISION: " << endl;
        cin >> numMision;
        cout << "DNI DEL ASTRONAUTA: " << endl;
        cin >> DNI;
        cout << "CARGO: " << endl;
        cin >> cargo;
        cout << "FECHA DE INICIO: " << endl;
        fechaInicio.Cargar();
    }
    
    void Misiones::Mostrar(){
        
        cout << "NUMERO DE MISION: " << numMision << endl;
        cout << "DNI DEL ASTRONAUTA: " << DNI << endl;
        cout << "CARGO: " << cargo << endl;
        cout << "FECHA DE INICIO: " << endl;
        fechaInicio.Mostrar();
        
    }
    
    class ArchivoAstronauta{
    private:
    char nombre[30];
public:
    ArchivoAstronauta(const char *n){
        strcpy(nombre, n);
    }
    Astronauta leerRegistro(int pos){
        Astronauta reg;
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
        return tam/sizeof(Astronauta);
    }
    bool grabarRegistro(Astronauta reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    
     bool mostrarRegistros(){
        Astronauta read;
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
    
    };
    
    class ArchivoMisiones{
    private:
    char nombre[30];
public:
    ArchivoMisiones(const char *n){
        strcpy(nombre, n);
    }
    Misiones leerRegistro(int pos){
        Misiones reg;
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
        return tam/sizeof(Misiones);
    }
    bool grabarRegistro(Misiones reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    
     bool mostrarRegistros(){
        Misiones read;
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
    
    };
    

    
#endif // PARCIAL2_H_INCLUDED