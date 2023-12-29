#ifndef INMUEBLE_H_INCLUDED
#define INMUEBLE_H_INCLUDED

class Inmueble{

protected:
    Direccion direccion;
    Fecha fechaIngreso, fechaOperacion;
    float superficieTotal;
    int tipoOperacion; 
    
    
public:    

///Setters

    void setDireccion (Direccion d){ direccion=d;}
    void setFechaIngreso (Fecha fi){ fechaIngreso=fi;}
    void setFechaOperacion (Fecha fo){ fechaOperacion=fo;}
    void setSuperficieTotal (float st){ superficieTotal=st;}
    void setTipoOperacion (int to){ tipoOperacion=to;}
    
///Getters
        
    Direccion getdireccion(){return direccion;}
    Fecha getfechaIngreso(){return fechaIngreso;}
    Fecha getfechaOperacion(){return fechaOperacion;}
    float getsuperficieTotal(){return superficieTotal;}
    int gettipoOperacion(){return tipoOperacion;}
    
    
    void cargar();
    void mostrar();
    

};

void Inmueble::cargar(){

    
    cout << endl;
    cout << "Ingrese la fecha de ingreso: " << endl << endl;
    fechaIngreso.cargar() ;
    cout << endl;
    cout << "Ingrese la fecha de operacion: " << endl<< endl;
    fechaOperacion.cargar(); 
    cout << "Ingrese la superficie total: " ;
    cin >> superficieTotal ;
    cout << "Ingrese el tipo de operacion (1 para VENTA - 2 para alquiler): " << endl;
    cin >> tipoOperacion ;
    cout << endl;

}

void Inmueble::mostrar(){

    cout << "Direccion: " << endl ;
    direccion.mostrar();
    cout << endl;
    cout << "Fecha de Ingreso: " << endl ;
    fechaIngreso.mostrar();
    cout << endl;
    cout << "Fecha de operacion: " << endl ;
    fechaOperacion.mostrar();
    cout << endl;
    cout << "Superficie total: " << superficieTotal;
    cout << endl;
    cout << "Tipo de operacion: " << tipoOperacion;
    cout << endl;
}


class Casa: public Inmueble{

private:
    int cantidadAmbientes;
    float superficieConstruida;

public: 
    
///setters

    void setCantidadAmbientes(int ca){cantidadAmbientes= ca;}
    void setSuperficieConstruida(float sc){superficieConstruida= sc;}
    
///Getters

    int getCantidadAmbientes(){return cantidadAmbientes;}
    float getSuperficieConstruida(){return superficieConstruida;}
    
    void cargar();
    void mostrar();
};

    
    void Casa::cargar(){
    
    Inmueble::cargar();
    
    cout << "Ingrese la cantidad de ambientes: ";
    cin >> cantidadAmbientes;
    cout << "Ingrese la superficie construida: ";
    cin >> superficieConstruida;
    }


    void Casa::mostrar(){
    
    Inmueble::mostrar();
    
    cout << "La cantidad de ambientes: " << cantidadAmbientes << endl;
    cout << "La superficie de construccion es: " << superficieConstruida;

    }
    
    
    class Departamento: public Inmueble{
    
private:
    
    int cantAmbiente;
    bool instalacionesComplementarias;
    
public:
    
    ///Setter
    void setCantAmbiente(int cAmb){cantAmbiente=cAmb;}
    void setInstalacionesComplementarias (bool ic){instalacionesComplementarias = ic;}
    
    //Getters
    
    int getCantAmbiente(){return cantAmbiente;}
    bool getInstalacionesComplementarias(){return instalacionesComplementarias;}
    
    void cargar();
    void mostrar();
    
    };
    

    void Departamento::cargar(){
    
    Inmueble::cargar();
    
    cout << "Ingrese la cantidad de ambientes: ";
    cin >> cantAmbiente;
    cout << "Ingrese si tiene las instalaciones Complementarias (1 para SI - 0 para NO): ";
    cin >> instalacionesComplementarias;
    
    }

    void Departamento::mostrar(){
    
    Inmueble::mostrar();
    
    cout << "La cantidad de ambientes son: " << endl;
     cantAmbiente;
    
    cout << "Tiene instalaciones complementarias: " << endl;
    instalacionesComplementarias;
    
    }
    
    class Locales: public Inmueble{
    
    
private: 
    int zona;
    
public:
    
///setters

    void setZona(int z){zona= z;}
    
///Getters

    int getZona(){return zona;}
    
    void cargar();
    void mostrar();
    
    };
    
    void Locales::cargar(){
    
    Inmueble::cargar();
    
    cout << "Ingrese la zona que desee, para COMERCIAL 1, para MIXTA 2, para INDUSTRIAL 3: " << endl;
    cin >> zona;
    
    }
    
    void Locales::mostrar(){
    
    Inmueble::mostrar();
    
    cout << "La zona elegida es: " << zona << endl;
    
    }
    
    
    class Terreno: public Inmueble{
    
private: 
    int mejoras;
    
public:
    
///Setters
    void setMejoras(int m){mejoras= m;}
    
///Getters
    
    int getMejoras(){return mejoras;}
    
    void cargar();
    void mostrar();
    
    };
    
void Terreno::cargar(){

    Inmueble::cargar();
    
    cout << "Ingrese el tipo de mejora ('A' SIN MEJORAS - 'B' ASFALTO - 'C' TODOS LOS SERVICIOS: " << endl;
    cin >> mejoras;
}

void Terreno::mostrar(){

    Inmueble::mostrar();
    
    cout << "Ingrese el tipo de mejora : " << endl;
        mejoras;
}
#endif // INMUEBLE_H_INCLUDED
