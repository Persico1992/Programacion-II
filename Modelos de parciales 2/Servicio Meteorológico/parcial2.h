///Ejercicio: Parcial  de Programación II
///Autor:DEK
///Fecha:
///Comentario:

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
    bool operator==(Fecha obj){
        if(dia != obj.dia) return false;
        if(mes != obj.mes) return false;
        if(anio != obj.anio) return false;
        return true;
    }
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

class Ciudades{
private:
    int _CodigoCiudad;
    char _Nombre[30];
    int _CodigoProvincia;

public:
    void Cargar(){
        int codigoCiudad, codigoProvincia;
        char nombre[29];

        cout<<"CODIGO DE LA CIUDAD: ";
        cin>>codigoCiudad;
        setCodigoCiudad(codigoCiudad);
        cin.ignore();
        cout<<"NOMBRE: ";
        cin.getline(nombre,29);
        setNombre(nombre);
        cout<<"CODIGO DE LA PROVINCIA: ";
        cin>>codigoProvincia;
        setCodigoProvincia(codigoProvincia);

    }
    
    void Mostrar(){
    
    cout << "CODIGO DE LA CIUDAD: " << _CodigoCiudad << endl;
    cout << "NOMBRE: " << _Nombre << endl;
    cout << "CODIGO DE LA PROVINCIA: " << _CodigoProvincia << endl;
    
    }

    void setCodigoCiudad(int ciudad){_CodigoCiudad = ciudad;}
    void setNombre(const char* nombre){strcpy(_Nombre,nombre);}
    void setCodigoProvincia(int provincia){_CodigoProvincia = provincia;}


    int getCodigoCiudad(){return _CodigoCiudad;}
    char* getNombre(){return _Nombre;}
    int getCodigoProvincia(){return _CodigoProvincia;}
};

class ArchivoCiudades{
private:
    char nombre[30];

public:
    ArchivoCiudades(){strcpy(nombre,"ciudades.dat");}

    int contarRegistros(){
    FILE* p;
    int tam;

    p = fopen ("ciudades.dat","rb");
    if(p == NULL){
        return -1;
    }
    fseek(p,0,SEEK_END);
    tam = ftell(p);
    fclose(p);

    return tam/sizeof(Ciudades);
    }

    Ciudades leerRegistro(int pos){
    FILE* p;
    Ciudades regCiudades;

    p = fopen(nombre,"rb");

    if(p == NULL){
        cout<<"Error en la apertura del archivo"<<endl;
        return regCiudades;
    }

    fseek(p,sizeof(Ciudades) * pos ,SEEK_SET);
    fread(&regCiudades,sizeof(Ciudades),1,p);
    fclose(p);
    return regCiudades;

    }
    
     bool grabarRegistro(Ciudades reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    
     bool mostrarRegistros(){
        Ciudades read;
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


class Mediciones{
private:
    int _CodigoCiudad;
    int _Visibilidad;
    char _Nombre[30];
    float _Temperatura;
    Fecha _Fecha;

public:
    void Cargar(){
        int codigoCiudad, visibilidad,dia;
        char nombre[29];
        float temperatura;

        cout<<"CODIGO DE LA CIUDAD: ";
        cin>>codigoCiudad;
        setCodigoCiudad(codigoCiudad);
        cin.ignore();
        cout<<"NOMBRE: ";
        cin.getline(nombre,29);
        setNombre(nombre);
        cout<<"VISIBILIDAD: ";
        cin>>visibilidad;
        setVisibilidad(visibilidad);
        cout<<"TEMPERATURA: ";
        cin>>temperatura;
        setTemperatura(temperatura);
        cout<<"FECHA";
        _Fecha.Cargar();

    }
    
    void Mostrar(){
        cout << "CODIGO DE LA CIUDAD: " << _CodigoCiudad << endl;
        cout << "NOMBRE: " << _Nombre << endl;
        cout << "VISIBILIDAD: " << _Visibilidad << endl;
        cout << "TEMPERATURA: " << _Temperatura << endl;
        cout << "FECHA: ";
         _Fecha.Mostrar();
    
    
    }
    void setCodigoCiudad(int ciudad){_CodigoCiudad = ciudad;}
    void setVisibilidad(int visibilidad){ _Visibilidad = visibilidad;}
    void setNombre(const char* nombre){strcpy(_Nombre,nombre);}
    void setTemperatura(float temperatura){_Temperatura = temperatura;}
    void setFecha(int dia, int mes, int anio){_Fecha.setDia(dia);_Fecha.setMes(mes);_Fecha.setAnio(anio);}

    int getCiudad(){return _CodigoCiudad;}
    int getVisibilidad(){return _Visibilidad;}
    char* getNombre(){return _Nombre;}
    float getTemperatura(){return _Temperatura;}
    Fecha getFecha(){return _Fecha;}
};

class ArchivoMediciones{
private:
    char nombre[30];

public:
    ArchivoMediciones(){strcpy(nombre,"mediciones.dat");}
    int contarRegistros(){
    FILE* p;
    int tam;

    p = fopen ("mediciones.dat","rb");
    if(p == NULL){
        return -1;
    }
    fseek(p,0,SEEK_END);
    tam = ftell(p);
    fclose(p);

    return tam/sizeof(Mediciones);

    }
    Mediciones leerRegistro(int pos){
    FILE* p;
    Mediciones regMediciones;

    p = fopen(nombre,"rb");

    if(p == NULL){
        cout<<"Error en la apertura del archivo"<<endl;
        return regMediciones;
    }

    fseek(p,sizeof(Mediciones) * pos ,SEEK_SET);
    fread(&regMediciones,sizeof(Mediciones),1,p);
    fclose(p);
    return regMediciones;
    }
    
        
     bool grabarRegistro(Mediciones reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    
     bool mostrarRegistros(){
        Mediciones read;
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



