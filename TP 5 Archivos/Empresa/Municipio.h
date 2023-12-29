#ifndef MUNICIPIO_H_INCLUDED
#define MUNICIPIO_H_INCLUDED

class Municipio{

private: 
    int numeroMunicipio, seccion, cantHabitantes;
    char nombreMuni[30];
    bool estadoMuni;
    
public:
    
    void cargarMuni();
    void mostrarMuni();
    ///SETTER
    void setNumeroMunicipio(int nm){numeroMunicipio=nm;}
    void setSeccion(int s){seccion=s;}
    void setCantHabitantes(int ch){cantHabitantes=ch;}
    void setNombreMuni (char *nm){strcpy (nombreMuni,nm);}
    void setEstadoMuni(bool em){estadoMuni=em;}
    ///GETTER
    int getNumeroMunicipio(){return numeroMunicipio;}
    int getSeccion(){return seccion;}
    int getCantHabitantes(){return cantHabitantes;}
    const char *getNombreMuni(){return nombreMuni;}
    bool getEstadoMuni(){return estadoMuni;}
    

};

void Municipio::cargarMuni(){

    cout << "INGRESAR EL NUMERO DE MUNICIPIO(1 a 135): ";
    cin >> numeroMunicipio;
    cout << "INGRESAR EL NOMBRE DEL MUNICIPIO: ";
    cargarCadena(nombreMuni,29);
    cout << "INGRESAR LA SECCION A LA QUE PERTENECE (1 a 9): ";
    cin >> seccion;
    cout << "INGRESAR LA CANTIDAD DE HABITANTES DEL MUNICIPIO: ";
    cin >> cantHabitantes;
    
    estadoMuni= true;
}

void Municipio::mostrarMuni(){

    cout << "NUMERO DE MUNICIPIO: " << numeroMunicipio << endl;
    cout << "NOMBRE DEL MUNICIPIO: " << nombreMuni << endl;
    cout << "SECCION QUE PERTENECE: " << seccion << endl;
    cout << "CANTIDAD DE HABITANTES DEL MUNICIPIO: " << cantHabitantes << endl;  

}
#endif // MUNICIPIO_H_INCLUDED
