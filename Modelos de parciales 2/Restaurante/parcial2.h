#ifndef PARCIAL2_H_INCLUDED
#define PARCIAL2_H_INCLUDED


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

class Restaurante{
private:
    int codigoRestaurante;
    char nombre[30];
    int provincia;
    char gerente[30];
    int categoria;
    bool estado;
public:
    int getCodigoRestaurante(){return codigoRestaurante;}
    const char *getNombre(){return nombre;}
    int getProvincia(){return provincia;};
    const char* getGerente(){return gerente;};
    int getCategoria(){return categoria;};
    bool getEstado(){return estado;};


    void Mostrar(){

        cout << "COD RESTAURANTE: " << codigoRestaurante << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "PROVINCIA: " << provincia << endl;
        cout << "GERENTE: " << gerente << endl;
        cout << "CATEGORIA: " << categoria << endl;
 
    }

};

class Cliente{
private:
    int DNI;
    char nombre[30];
    int medioPago;
    int tipoCliente;
    int edad;
    bool estado;
public:
    int getDNI(){return DNI;}
    const char *getNombre(){return nombre;}
    int getMedioPago(){return medioPago;}
    int getTipoCliente(){return tipoCliente;}
    int getEdad(){return edad;};
    bool getEstado(){return estado;}

    void Mostrar(){

        cout << "DNI: " << DNI << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "MEDIO PAGO: " << medioPago << endl;
        cout << "TIPO CLIENTE: " << tipoCliente << endl;
        cout << "EDAD: " << edad << endl;
 
    }
};

class Venta{
private:
    int codigoRestaurante;
    int DNI;
    Fecha fechaReserva;
    int tipoVenta;
    float importe;
    bool estado;
public:
    int getCodigoRestaurante(){return codigoRestaurante;}
    int getDNI(){return DNI;}
    Fecha getFechaReserva(){return fechaReserva;}
    int getTipoVenta(){return tipoVenta;}
    float getImporte(){return importe;}
    bool getEstado(){return estado;}

    void Mostrar(){

        cout << "COD RESTAURANTE: " << codigoRestaurante << endl;
        cout << "DNI: " << DNI << endl;
        cout << "FECHA RESERVA: " << endl;
          fechaReserva ;
        cout << "TIPO VENTA: " << tipoVenta << endl;
        cout << "IMPORTE: " << importe << endl;

    }
    
};

class Reservas{
    private:
    int codigoRestaurante, DNI, hora;
    Fecha fechaReserva;
    bool estado;
    
    public:
    
    void setCodigoRestaurante(int cr){codigoRestaurante=cr;}
    void setDNI(int d){DNI= d;}
    void setHora(int h){hora=h;}
    void setFechaReserva (Fecha fr){fechaReserva=fr;}
    void setEstado(bool e){estado=e;}

    int getCodigoRestaurante(){return codigoRestaurante;}
    int getDNI(){return DNI;}
    int getHora(){return hora;}
    Fecha getFechaReserva(){return fechaReserva;}
    bool getEstado(){return estado;}

    void CargarReserva(){
        cout << "CODIGO RESTAURANTE: " << endl;
        cin >> codigoRestaurante;
        cout << "DNI: " << endl;
        cin >> DNI;
        cout << "HORA: " << endl;
        cin >> hora;
        cout << "FECHA RESERVA: " << endl;
        fechaReserva.Cargar();
    }
    void Mostrar(){
        cout << "CODIGO RESTAURANTE: " << codigoRestaurante << endl;
        cout << "DNI: " << DNI << endl;
        cout << "HORA: " << hora << endl;
        cout << "FECHA RESERVA: " << endl;
        fechaReserva.Mostrar();


    }
};



class ArchivoRestaurantes{
private:
    char nombre[30];
public:
    ArchivoRestaurantes(const char *n){
        strcpy(nombre, n);
    }
    Restaurante leerRegistro(int pos){
        Restaurante reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Restaurante)*pos,0);
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
        return tam/sizeof(Restaurante);
    }
     bool listarArchivo() {
        Restaurante reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.Mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
    }

};

class ArchivoClientes{
private:
    char nombre[30];
public:
    ArchivoClientes(const char *n){
        strcpy(nombre, n);
    }
    Cliente leerRegistro(int pos){
        Cliente reg;
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
        return tam/sizeof(Cliente);
    }
    bool listarArchivo() {
        Cliente reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.Mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
    }

};

class ArchivoVentas{
private:
    char nombre[30];
public:
    ArchivoVentas(const char *n){
        strcpy(nombre, n);
    }
    Venta leerRegistro(int pos){
        Venta reg;
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
        return tam/sizeof(Venta);
    }

    bool listarArchivo() {
        Venta reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.Mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
    }
};

class ArchivoReservas{
private:
    char nombre[30];
public:
    ArchivoReservas(const char *n){
        strcpy(nombre, n);
    }
    Reservas leerRegistro(int pos){
        Reservas reg;
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
        return tam/sizeof(Reservas);
    }

    bool listarArchivo() {
        Reservas reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.Mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
    }
     bool escribirRegistro(Reservas reg) {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL) return false;
        bool escribio = fwrite(&reg, sizeof(reg), 1, p);
        fclose(p);
        return escribio;
    }
};

#endif // PARCIAL2_H_INCLUDED
