///Ejercicio: Parcial 2 de Programación II
///Autor:DEK
///Fecha:13/07/2022
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

class Obra{
private:
    char codigoObra[5];
    char direccion[30];
    int provincia;
    float superficie;
    int estadoEjecucion;
    bool activo;
public:
        Obra(){}; ///PRUEBA PARA SOBRECARGA. EL VACIO SE HACE PARA QUE NO TENGA PROBLEMAS DE LO DECLARADO
        Obra( int superf){         ///ESTE RECIBE PARAMETROS        (const char * codObra)
            superficie= superf;                                     ///strcpy(codigoObra,codObra);  ///ASI SERIA PARA LOS char
        }
        
        void Cargar();
        void Mostrar();

    const char* getCodigoObra(){return codigoObra;}
    const char* getDireccion(){return direccion;}
    int getProvincia(){return provincia;}
    int getEstadoEjecucion(){return estadoEjecucion;}
    float getSuperficie(){return superficie;}
    bool getActivo(){return activo;}

    void setCodigoObra(const char *co){strcpy(codigoObra, co);}
    void setDireccion(const char *d){strcpy(direccion,d);}
    void setProvincia(int p){provincia=p;}
    void setEstadoEjecucion(int e){estadoEjecucion=e;}
    void setSuperficie(float s){superficie=s;}
    void setActivo(bool a){activo=a;}
    
    /*Sobrecargar el operador > para la clase Obra de manera tal que sea verdadero cuando el objeto 
que llama al método tenga una superficie mayor al objeto
Obra que se recibe como parámetro.
     bool operator > (Obra objObra ){
        if(superficie > objObra.getSuperficie()) return true;
        return false;
    }    
*/
    
    };
            
 void Obra::Cargar(){
        cout << "COD OBRA: " <<endl;
        cargarCadena(codigoObra,4);
        cout << "DIRECCION: " <<endl;
        cargarCadena(direccion,29);
        cout << "PROVINCIA: " <<endl;
        cin>>provincia;
        cout << "SUPERFICIE: " <<endl;
        cin>>superficie;
        cout << "ESTADO EN EJECUCION: (1: en proyecto; 2: proyecto aprobado en espera;3: en ejecución; 4: terminada; 5: suspendida:)" << endl;
        cin>>estadoEjecucion;
        activo=true;
    }

    void Obra::Mostrar(){
        cout << "COD OBRA: " ;
        cout<<codigoObra<<endl;
        cout << "DIRECCION: " ;
        cout<<direccion<<endl;
        cout << "PROVINCIA: " ;
        cout<<provincia<<endl;
        cout << "SUPERFICIE: " ;
        cout<<superficie<<endl;
        cout << "ESTADO EJECUCION: " ;
        cout<<estadoEjecucion<<endl;
    }
   
class ArchivoObras{
    private:
        char nombre[30];
    public:
        ArchivoObras(const char *n){
            strcpy(nombre,n);
        }
        Obra leerRegistro(int pos){
            Obra reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Obra);
            fclose(p);
            return cant;
        }
        bool grabarRegistro(Obra reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
     bool mostrarRegistros(){
        Obra read;
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

class Material{
private:
    int codigoMaterial;
    char nombre[30];
    char marca[30];
    int tipo;
    float pu;
    bool activo;
    Fecha fechaCompra;
public:
    void Cargar();
    void Mostrar();
    int getCodigoMaterial(){return codigoMaterial;}
    int getTipo(){return tipo;}
    const char *getNombre(){return nombre;}
    const char *getMarca(){return marca;}
    float getPU(){return pu;}
    Fecha getFechaCompra(){return fechaCompra;}
    bool getActivo(){return activo;}

    void setCodigoMaterial(int cm){codigoMaterial=cm;}
    void setTipo(int t){tipo=t;}
    void setNombre(const char *m){strcpy(nombre,m);}
    void setMarca(const char *m){strcpy(marca,m);}
    void setPU(float p){pu=p;}
    void setFechaCompra(Fecha f){fechaCompra=f;}
    void setActivo(bool a){activo=a;}
};
        void Material::Cargar(){
        cout << "COD MATERIAL: " <<endl;
        cin>>codigoMaterial;
        cout << "NOMBRE: " <<endl;
        cargarCadena(nombre,29);
        cout << "MARCA: " <<endl;
        cargarCadena(marca,29);
        cout << "TIPO: " <<endl;
        cin>>tipo;
        cout << "PRECIO: " <<endl;
        cin>>pu;
        cout << "FECHA COMPRA: " <<endl;
        fechaCompra.Cargar();
        activo=true;
    }
        void Material::Mostrar(){
        cout << "COD MATERIAL: ";
        cout<<codigoMaterial<<endl;
        cout << "NOMBRE: " ;
        cout<<nombre<<endl;
        cout << "MARCA: " ;
        cout<<marca<<endl;
        cout << "TIPO: " ;
        cout<<tipo<<endl;
        cout << "PRECIO: " ;
        cout<<pu<<endl;
         cout << "FECHA COMPRA: " ;
        fechaCompra.Mostrar();
    }
class ArchivoMateriales{
    private:
        char nombre[30];
    public:
        ArchivoMateriales(const char *n){
            strcpy(nombre, n);
        }
        Material leerRegistro(int pos){
            Material reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Material);
            fclose(p);
            return cant;
        }
        bool grabarRegistro(Material reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
         bool mostrarRegistros(){
        Material read;
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

class Compra{
private:
    int numeroCompra, numeroProveedor, codigoMaterial;
    char codigoObra[5];
    int cantidad;
    float importe;
    Fecha fechaCompra;
    bool activo;
public:
    void Cargar();
    void Mostrar();
   

   
    int getNumeroCompra(){return numeroCompra;}
    int getNumeroproveedor(){return numeroProveedor;}
    int getCodigoMaterial(){return codigoMaterial;}
    int getCantidad(){return cantidad;}
    float getImporte(){return importe;}
    Fecha getFechaCompra(){return fechaCompra;}
    const char *getCodigoObra(){return codigoObra;}
    bool getActivo(){return activo;}

    void setNumeroCompra(int nc){numeroCompra=nc;}
    void setNumeroproveedor(int np){numeroProveedor=np;}
    void setCodigoMaterial(int cm){codigoMaterial=cm;}
    void setCantidad(int c){cantidad=c;}
    void setImporte(float i){importe=i;}
    void setFechaCompra(Fecha f){fechaCompra=f;}
    void setCodigoObra(const char *co){strcpy(codigoObra,co);}
    void setActivo(bool a){activo=a;}
};

    void Compra::Cargar(){
        cout << "NUM COMPRA: " << endl;
        cin>>numeroCompra;
        cout << "NUM PROVEEDOR: " << endl;
        cin>>numeroProveedor;
        cout << "COD MATERIAL: " << endl;
        cin>>codigoMaterial;
        cout << "COD OBRA: " << endl;
        cargarCadena(codigoObra,4);
        cout << "CANTIDAD: " << endl;
        cin>>cantidad;
        cout << "IMPORTE: " << endl;
        cin>>importe;
        cout << "FECHA COMPRA: " << endl;
        fechaCompra.Cargar();
        activo=true;
    }
    
     void Compra::Mostrar(){
         cout << "NUM COMPRA: " ;
        cout<<numeroCompra<<endl;
        cout << "NUM PROVEEDOR: " ;
        cout<<numeroProveedor<<endl;
        cout << "COD MATERIAL: ";
        cout<<codigoMaterial<<endl;
        cout << "COD OBRA: " ;
        cout<<codigoObra<<endl;
        cout << "CANTIDAD: " ;
        cout<<cantidad<<endl;
        cout << "IMPORTE: " ;
        cout<<importe<<endl;
        cout << "FECHA COMPRA: " ;
        fechaCompra.Mostrar();
        cout<<endl;
    }
class ArchivoCompras{
    private:
        char nombre[30];
    public:
        ArchivoCompras(const char *n){
            strcpy(nombre, n);
        }
        Compra leerRegistro(int pos){
            Compra reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Compra);
            fclose(p);
            return cant;
        }
        bool grabarRegistro(Compra reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
        bool mostrarRegistros(){
        Compra read;
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

class Proveedor{
private:
    int numeroProveedor;
    char nombre[30];
    char telefono[30];
    char direccion[30];
    int provincia;
    bool activo;
public:
    void Cargar();
    void Mostrar();
    
    
    

    int getNumeroProveedor(){return numeroProveedor;}
    int getProvincia(){return provincia;}
    const char *getNombre(){return nombre;}
    const char *getTelefono(){return telefono;}
    const char *getDireccion(){return direccion;}
    bool getActivo(){return activo;}

    void setNumeroProveedor(int np){numeroProveedor=np;}
    void setProvincia(int np){provincia=np;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTelefono(const char *n){strcpy(telefono,n);}
    void setDireccion(const char *n){strcpy(direccion,n);}
    void setActivo(bool a){activo=a;}
};
    void Proveedor::Cargar(){
        cout << "NUM PROVEEDOR: " << endl;
        cin>>numeroProveedor;
        cout << "NOMBRE PROV: " << endl;
        cargarCadena(nombre,29);
        cout << "TELEFONO: " << endl;
        cargarCadena(telefono,29);
        cout << "DIRECCION: " <<endl;
        cargarCadena(direccion,29);
        cout << "PROVINCIA: " <<endl;
        cin>>provincia;
        activo=true;
    }
    
    void Proveedor::Mostrar(){
        cout << "NUM PROVEEDOR: " ;
        cout<<numeroProveedor<<endl;
        cout << "NOMBRE PROV: " ;
        cout<<nombre<<endl;
        cout << "TELEFONO: " ;
        cout<<telefono<<endl;
        cout << "DIRECCION: " ;
        cout<<direccion<<endl;
        cout << "PROVINCIA: " ;
        cout<<provincia<<endl;
    }
    
class ArchivoProveedores{
    private:
        char nombre[30];
    public:
        ArchivoProveedores(const char *n){
            strcpy(nombre, n);
        }
        Proveedor leerRegistro(int pos){
            Proveedor reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Proveedor);
            fclose(p);
            return cant;
        }
        bool grabarRegistro(Proveedor reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        
        bool mostrarRegistros(){
        Proveedor read;
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

