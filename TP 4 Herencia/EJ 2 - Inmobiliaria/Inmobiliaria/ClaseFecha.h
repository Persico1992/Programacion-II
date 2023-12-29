#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

class Fecha
{
private:
    int dia,mes, anio;
public:
    Fecha (int _dia=1, int _mes=1, int _anio=1900)
    {
        dia=_dia;
        mes=_mes;
        anio=_anio;
    }
    void cargar()
    {
        cout<< "Ingresar de Ingreso: "<<endl;
        cout<< "Dia: ";
        cin>>dia;
        cout << "Mes: ";
        cin>>mes;
        cout<< "Anio: ";
        cin>>anio;
    }
    void mostrar()
    {
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }

    int getDia()
    {
        return dia;
    }
    int getMes()
    {
        return mes;
    }
    int getAnio()
    {
        return anio;
    }

    void setDia(int d)
    {
        dia=d;
    }
    void setMes(int m)
    {
        mes=m;
    }
    void setAnio(int a)
    {
        anio=a;
    }
};


class Direccion{

private:
    char calle[30], localidad[30], entreCalle[30], partido[30], pais[30];
    int numero, codigoPostal, piso;
public:
    
///setters
    void setCalle(const char* c){strcpy(calle,c);}
    void setlocalidad(const char* l){strcpy(localidad,l);}
    void setentreCalle(const char* ec){strcpy(entreCalle,ec);}
    void setPartido(const char* p){strcpy(partido,p);}
    void setPais(const char* pa){strcpy(pais,pa);}
    void setNumero(int n){numero=n;}
    void setcodigoPostal(int cp){codigoPostal=cp;}
    void setPiso(int p){piso=p;}
    
//Getters
    const char* getCalle(){return calle;}
    const char* getlocalidad(){return localidad;}
    const char* getentreCalle(){return entreCalle;}
    const char* getPartido(){return partido;}
    const char* getPais(){return pais;}
    int getNumero(){return numero;}
    int getcodigoPostal(){return codigoPostal;}
    int getPiso(){return piso;}
    
    void cargar();
    void mostrar();

};

    void Direccion::cargar(){
    
    cout << "Ingrese la calle: ";
    cargarCadena (calle,29);
    cout << "Ingrese la localidad: ";
    cargarCadena (localidad,29);
    cout << "Ingrese la entre calle: ";
    cargarCadena (entreCalle,29);
    cout << "Ingrese el partido: ";
    cargarCadena (partido,29);
    cout << "Ingrese el pais: ";
    cargarCadena (pais,29);
    cout << "Ingrese el numero: ";
    cin >> numero;
    cout << "Ingrese el cp: ";
    cin >> codigoPostal;
    cout << "Ingrese el piso: ";
    cin >> piso;
    
    }

    void Direccion::mostrar(){
    
    cout << calle << endl;
    cout << localidad << endl;
    cout << entreCalle << endl;
    cout << partido << endl;
    cout << pais << endl;
    cout << numero << endl;
    cout << codigoPostal << endl;
    cout << piso << endl;
    
    }
    
    

#endif // CLASEFECHA_H_INCLUDED
