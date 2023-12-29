#ifndef INTERNET_H_INCLUDED
#define INTERNET_H_INCLUDED

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


class Vendedores{
private:
    char codVendedor[5], nombre[30];
    int provincia, calificacion;
    bool estado;
public:
    void Cargar(){
    cout << "CODIGO VENDEDORES: " << endl;
    cargarCadena(codVendedor,4);
    cout << "NOMBRE: " << endl;
    cargarCadena(nombre,29);
    cout << "PROVINCIA: " << endl;
    cin >> provincia;
    cout << "CALIFICACION: " << endl;
    cin >> calificacion;
    estado=true;
}
    void Mostrar(){
    cout << "CODIGO VENDEDOR: " << codVendedor<< endl;
    cout << "NOMBRE: " << nombre <<endl;
    cout << "PROVINCIA: " << provincia <<endl;
    cout << "Calificación: " << calificacion << endl;
    
    }

    void setCodVendedor(const char* cv){strcpy(codVendedor,cv);}
    void setNombre(const char* n){strcpy(nombre,n);}
    void setProvincia (int p){provincia=p;}
    void setCalificacion(int c){calificacion=c;}
    void setEstado(bool e){estado=e;}
    
    const char* getCodVendedor(){return codVendedor;}
    const char* getNombre(){return nombre;}
    int getProvincia(){return provincia;}
    int getCalificacion(){return calificacion;}
    bool getEstado(){return estado;}
};

class ArchivoVendedores{

private:
    char nombre[30];
public:
    ArchivoVendedores(const char *n){
        strcpy(nombre, n);
    }

Vendedores leerRegistro(int pos){
        Vendedores reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Vendedores)*pos,0);
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
        return tam/sizeof(Vendedores);
    }
     bool grabarRegistro(Vendedores reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    
      int mostrarRegistros(){
        Vendedores read;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        while(fread(&read,sizeof read,1,p)== 1){
            read.Mostrar();
            cout << endl;
        }
    }


};


class Usuarios{

private:
    char codUsuario[5], nombre[30];
    int dni;
    Fecha fechaRegistracion;
public:
    void cargar(){
    cout << "CODIGO USUARIO." << endl;
    cargarCadena(codUsuario,4);
    cout << "NOMBRE: " << endl;
    cargarCadena(nombre,29);
    cout << "DNI:" << endl;
    cin >> dni;
    cout << "FECHA REGISTRACION: " << endl;
    fechaRegistracion.Cargar();
}
    
void Mostrar(){
    cout << "CODIGO USUARIO: " << codUsuario << endl; 
    cout << "NOMBRE: " << nombre << endl;
    cout << "DNI: " << dni << endl;
    cout << "FECHA REGISTRACIÓN: " << endl;
    fechaRegistracion.Mostrar();
    
    }

    void setCodUsuario(const char* cu){strcpy(codUsuario,cu);}
    void setNombre(const char* n){strcpy(nombre,n);}
    void setdni (int d){dni=d;}
    void setFechaRegistracion(Fecha fr){fechaRegistracion=fr;}
    
    const char* getCodUsuario(){return codUsuario;}
    const char* getNombre(){return nombre;}
    int getDni(){return dni;}
    Fecha getFechaRegistracion(){return fechaRegistracion;}
};

class ArchivoUsuarios{

private:
    char nombre[30];
public:
    ArchivoUsuarios(const char *n){
        strcpy(nombre, n);
    }

Usuarios leerRegistro(int pos){
        Usuarios reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Usuarios)*pos,0);
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
        return tam/sizeof(Usuarios);
    }
    
     bool grabarRegistro(Usuarios reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    
      int mostrarRegistros(){
        Usuarios read;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        while(fread(&read,sizeof read,1,p)== 1){
            read.Mostrar();
            cout << endl;
        }
    }
};


class Ventas{
private:
    int numCompra;
    char codUsuario[5], codVendedor[5];
    float importe;
    int tipoPago;
    Fecha fechaVenta;

public:
    void Cargar(){
    cout << "NUMERO COMPRA: " << endl;
    cin >> numCompra;
    cout << "CODIGO VENDEDOR: " << endl;
    cin >> codVendedor;
    cout << "CODIGO USUARIO: " << endl;
    cin >> codUsuario;
    cout << "IMPORTE: $" << endl;
    cin >> importe;
   cout << "FECHA DE VENTA: " << endl;
   fechaVenta.Cargar();
   cout << "TIPO: " << endl;
   cin >> tipoPago;
    }
void Mostrar(){
    cout << "NUMERO DE COMPRA: " << numCompra << endl;
    cout << "CODIGO DE VENDEDOR: " << codVendedor << endl;;
    cout << "CODIGO DE USUARIO: " << codUsuario << endl;
    cout << "IMPORTE: $" << importe << endl;
    cout << "FECHA DE VENTA: " << endl;
    fechaVenta.Mostrar();
    cout << "TIPO DE PAGO: " << tipoPago << endl;
   
    }

    void setNumCompra(int nc){numCompra= nc;}
    void setCodVendedor(const char* cv){strcpy(codVendedor,cv);}
    void setCodUsuario (const char* cu){strcpy(codUsuario,cu);}
    void setImporte(float i){importe=i;}
    void setTipoPago(float tp){tipoPago=tp;}
    void setFechaVenta(Fecha f){fechaVenta=f;}
    
    int getNumCompra(){return numCompra;}
    const char* getCodVendedor(){return codVendedor;}
    const char* getCodUsuario(){return codUsuario;}
    float getImporte(){return importe;}
    int getTipoPago(){return tipoPago;}
    Fecha getFechaVenta(){return fechaVenta;}    
};

class ArchivoVentas{

private:
    char nombre[30];
public:
    ArchivoVentas(const char *n){
        strcpy(nombre, n);
    }

Ventas leerRegistro(int pos){
        Ventas reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Ventas)*pos,0);
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
        return tam/sizeof(Ventas);
    }

     bool grabarRegistro(Ventas reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    
    int mostrarRegistros(){
        Ventas read;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        while(fread(&read,sizeof read,1,p)== 1){
            read.Mostrar();
            cout << endl;
        }
    }

};


#endif // INTERNET_H_INCLUDED
