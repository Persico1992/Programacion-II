#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

class Empresa{

private:
    int numeroEmpresa, cantEmpleado, categoria, numeroMunicipio;
    char nombre[30];
    bool estado;
public:

    void Cargar();
    void Mostrar();

///SETTERS
    
    void setNumeroEmpresa (int ne){numeroEmpresa=ne;}
    void setCantEmpleado (int ce){cantEmpleado=ce;}
    void setCategoria (int c){
            if(c>= 1 && c<=80) categoria=c;
            else categoria= -1;
        }
        
    void setNumMunicipio(int nm){
        if(nm>=1 && nm<=135) numeroMunicipio=nm;
            else numeroMunicipio= -1;
        }
        
    void setNombre (char *n){strcpy (nombre,n);}
    void setEstado (bool e){estado=e;}
///GETTERS
    
    int getNumeroEmpresa(){return numeroEmpresa;}
    int getCantEmpleado(){return cantEmpleado;}
    int getCategoria(){return categoria;}
    int getNumMunicipio(){return numeroMunicipio;}
    const char *getNombre(){return nombre;}
    bool getEstado(){return estado;}
};

void Empresa::Cargar(){
    cout << "NUMERO EMPRESA (Número entero. No se repite en el archivo. Es único para cada empresa): ";
    cin >> numeroEmpresa; 
    cout << "NOMBRE: ";
    cargarCadena (nombre, 29);
    cout << "CANTIDAD DE EMPLEADOS: ";
    cin >> cantEmpleado;
    cout << "CATEGORIA (1 a 80): ";
    cin >> categoria;
    cout << "NUMERO DE MUNICIPIO AL QUE PERTENECE (1 a 135): ";
    cin >>numeroMunicipio;
      
    
    estado= true;
    
}

void Empresa::Mostrar(){

    cout << "NUMERO EMPRESA: " << numeroEmpresa << endl;
    cout << "NOMBRE: " << nombre << endl;
    cout << "CANTIDAD DE EMPLEADOS: " << cantEmpleado << endl;
    cout << "CATEGORIA: " << categoria << endl;
    cout << "NUMERO DE MUNICIPIO AL QUE PERTENECE: " << numeroMunicipio << endl;
    
}


    
    
    




#endif // EMPRESA_H_INCLUDED
