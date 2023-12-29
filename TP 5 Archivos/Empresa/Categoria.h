#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

class Categoria{

private:
    int numero;
    char nombreCat[30];
    bool estadoCat;
public:
    void cargarCategoria();
    void mostrarCategoria();

///Setter
    void setNumero(int num){numero= num;}
    void setNombreCat(char *nom){strcpy(nombreCat,nom);}
    void setEstadoCat(bool ec){estadoCat= ec;}
///Getter
    int getNumero(){return numero;}
    const char *getNombreCat(){return nombreCat;}
    bool getEstadoCat(){return estadoCat;}
    
};

void Categoria::cargarCategoria(){

    cout << "INGRESE EL NUMERO DE LA CATEGORIA: ";
    cin >> numero;
    cout << "INGRESE EL NOMBRE DE LA CATEGORIA: ";
     cargarCadena (nombreCat,29);
    
    estadoCat= true;

}

void Categoria::mostrarCategoria(){

    cout << "NUMERO DE LA CATEGORIA: " << numero;
    cout << "NOMBRE DE LA CATEGORIA: " << nombreCat;
    
}


#endif // CATEGORIA_H_INCLUDED
