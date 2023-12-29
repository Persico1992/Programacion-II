#ifndef ARCHIVOEMPRESA_H_INCLUDED
#define ARCHIVOEMPRESA_H_INCLUDED

int buscarEmpresa(int numeroEmpresa);

class ArchivoEmpresa{

private:
    char nombre[30];
    
public:
    
    ArchivoEmpresa(const char *n){strcpy(nombre,n);} ///Constructor:Sirve para recibir el nombre del archivo y poder gestionarlo   
    int buscarEmpresa(int numeroEmpresa);
    
    ///Leer/listar registro
    Empresa leerRegistro(int pos){
    Empresa empresa;    ///Instancia de objeto --> El objeto esta VACIO
    FILE *p;
    p= fopen(nombre,"rb"); ///Sin comillas nombre, xq es una variable que va a tener el nombre dentro de la variable.
        if(p==NULL) return empresa;
    fseek (p,sizeof empresa*pos,0);     ///File buscar !
    fread (&empresa,sizeof empresa, 1, p);
        fclose(p);
    return empresa;
    }
///Agregar registro
    int agregarRegistro(Empresa empresa){
    FILE *p;
    p= fopen(nombre,"ab");
        if(p==NULL) return -1;
    int escribio= fwrite(&empresa,sizeof empresa, 1,p);
        fclose(p);
    return escribio;
    }
///Mostrar registros   
    int mostrarRegistros(){
    Empresa empresa;
    FILE *p;
    p= fopen(nombre,"rb");
        if(p==NULL) return -1;
    while(fread(&empresa,sizeof empresa, 1,p)== 1){///Encontro un registro y me muestra el registro
        empresa.Mostrar();
      cout << endl;  
    }
    
    }
///Contar registros
    int contarRegistros(){
    
    FILE *p;
    p=fopen(nombre,"rb");
        if(p==NULL) return -1;
    fseek(p,0,2);
    int tam= ftell(p); ///Aca preguntamos al archivo que tama�o tenes. Devuelve la cantidad de bytes que tiene el archivo en total. .
    fclose(p);
    return tam/sizeof(Empresa); /// Nos devuelve la cantidad de registro del archivo, este es un entero (int).
    
    }
    
    
    bool bajaLogicaRegistro(){
    int numEmpresa, pos;
    Empresa empresa;
   // ArchivoEmpresa ae;
    char opc;
    cout << "Ingresar el numero de empresa a dar de baja: ";
    cin >> numEmpresa;
    ///Buscar si la empresa existe en el archivo
    pos= buscarEmpresa(numEmpresa);///Recibo la posici�n de la empresa si existe.
        if(pos == -1){
        cout << "No existe esa EMPRESA." << endl;
        return false;
        }
        empresa= leerRegistro(pos);  ///me devuelve el OBJETO completo de empresa enviandole la posici�n.
        cout << "EL registro a borrar: " << endl;
        empresa.Mostrar();
        cout<< endl;
        cout << "Esta seguro de borrar el registro?(S/N)";
        cin >> opc;
        if(opc == 'S' || opc== 's'){
            empresa.setEstado(true);
    bool escribio= sobreEscribirRegistro(empresa, pos);
        return escribio;
        }
        return false;
    }
    
 bool sobreEscribirRegistro(Empresa empresa, int pos){//Registro que ya esta en el archivo, escribe de nuevo en la posicion que le manda por parametro
 
 FILE *p;
    p=fopen(ArchiEmpresas,"rb+");
    if(p==NULL){
        return false;
        }
    fseek(p,sizeof empresa*pos,0);
    bool escribio=fwrite(&empresa,sizeof empresa,1,p);
    fclose(p);
    return escribio;
 }   
    
bool modificarCategoria(){

ArchivoEmpresa archiEmpresa (ArchiEmpresas);
Empresa modificarEmpresa;
int numEmpresa, posicionEmpresa=0;

cout << "INGRESE EL NUMERO DE LA EMPRESA A MODIFICAR: " << endl;
cin >> numEmpresa;

posicionEmpresa= archiEmpresa.buscarEmpresa(numEmpresa);
   if(posicionEmpresa==-1){
    cout << "NO EXISTE ESTE NUMERO DE EMPRESA" << endl;
   }
   
   modificarEmpresa= archiEmpresa.leerRegistro(posicionEmpresa);
   cout << "EL REGISTRO A MODIFICAR ES: " << endl;
   modificarEmpresa.Mostrar();
   cout << endl;
    char opc;
    int categoria;
    cout << "DESEA MODIFICARLO (S/N)" << endl;
    cin >> opc;
    if(opc== 'S' || opc== 's'){
    cout << "INGRESE NUEVA CATEGORIA: " << endl;
    cin >> categoria;
    modificarEmpresa.setCategoria(categoria);
   bool modifico= archiEmpresa.sobreEscribirRegistro(modificarEmpresa, posicionEmpresa);
        
        return modifico;
       }
    return false;
}
    
    
};

void cargarVector (Empresa *v, int tam){
    
    for (int i=0; i<tam; i++){
        
        v[i].Cargar();
        cout << endl;
    }

}

void mostrarVector(Empresa *v, int tam){
    for (int i=0; i<tam; i++){
        
        v[i].Mostrar();
        cout << endl;
    }

}

void guardarVector (Empresa *v, int tam){
    ArchivoEmpresa aEmpresa(ArchiEmpresas);
    
    for (int i=0; i<tam; i++){
        
       aEmpresa.agregarRegistro(v[i]);
        cout << endl;
    }
    

} 

int ArchivoEmpresa::buscarEmpresa(int numeroEmpresa){
Empresa empresa;
int pos=0;
FILE *p;
    p= fopen(nombre, "rb");
    if(p==NULL){
        return -2;
        }
  int cantRegistros= contarRegistros();
  while(pos < cantRegistros){
      empresa= leerRegistro(pos);
    if(numeroEmpresa == empresa.getNumeroEmpresa()){
        fclose(p);
        return pos;
    }
    pos++;
  }  
    fclose(p);
    return -1;
}


#endif // ARCHIVOEMPRESA_H_INCLUDED
bool PuntoM(){  ///Baja Lógica a las tarjetas que tengan un saldo negativo menor a -15000
ArchivoTarjetas archiTarjeta("tarjetas.dat");

    ///INGRESAR EL VALOR QUE IDENTIFICA EL REGISTRO A BORRAR
    int numeroTarjeta, pos;
    cout<<"INGRESAR LA TARJETA A DAR DE BAJA ";
    cin>>numeroTarjeta;
    ///BUSCAR SI LA TARJETA EXISTE EN EL ARCHIVO.
    ///LA FUNCION DEVUELVE LA POSICIÓN DEL REGISTRO EN EL ARCHIVO. SI NO ENCUENTRA LA TARJETA DEVUELVE -1/false
    pos=archiTarjeta.buscarNumTarjeta(numeroTarjeta);
    if(pos==-1){
        cout<<"NO EXISTE ESA TARJETA"<<endl;
        return false;
    }
    ///LEER EL REGISTRO DEL ARCHIVO Y PONERLO EN UNA VARIABLE DE MEMORIA
    Tarjeta reg;
    reg=archiTarjeta.leerRegistro(pos);
    
    if(reg.getSaldo() < (-15000) && reg.getBajaLogica() == false){
        ///CAMBIAR EL CAMPO estado
    cout<<"REGISTRO A BORRAR "<<endl;
    reg.mostrarTarjeta();
    cout<<endl;
    char opc;
    cout<<"DESEA BORRARLO? (S/N) ";
    cin>>opc;
    if(opc=='s'|| opc=='S'){
        reg.setBajaLogica(true);
        ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO EN LA MISMA POSICION QUE TENÍA
        bool quePaso=archiTarjeta.sobreEscribirRegistro(reg, pos);
        return quePaso;
    }
    
        
    }
    return false;
}