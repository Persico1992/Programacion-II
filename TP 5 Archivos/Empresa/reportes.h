#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void puntoA()
{

    ArchivoEmpresa aEmpresa(ArchiEmpresas);
    Empresa empresa;
    int vMunicipios[135]={}, pos=0;

    int cantRegistros=aEmpresa.contarRegistros();

    while(pos<cantRegistros)
    {
        empresa= aEmpresa.leerRegistro(pos);
        vMunicipios[empresa.getNumMunicipio() -1]++;
        pos++;
    }
    for (int i=0; i<135; i++){
        if(vMunicipios[i] == 0){
            cout << "El municipio " << i+1 << " no tiene empresas." << endl;
        }
        else{
            cout << "El municipio " << i+1 << " tiene " << vMunicipios[i] << " empresa." << endl;
        }
    }
}

void puntoB(){

ArchivoEmpresa aEmpresa(ArchiEmpresas);
Empresa empresa;
int pos=0;
char nombre[30];
int cantRegistros= aEmpresa.contarRegistros();
cout << "ESTAS EMPRESAS TIENEN MAS DE 200 EMPLEADOS: " << endl;

while(pos<cantRegistros){
    empresa=aEmpresa.leerRegistro(pos);
        strcpy(nombre,empresa.getNombre());
        if(empresa.getCantEmpleado() > 200) cout <<  nombre << endl;
    pos++;
    }
}
///	Calcular e informar la categoría de empresa con más empleados
void puntoC(){

ArchivoEmpresa aEmpresa(ArchiEmpresas);
Empresa empresa, empleado;
int pos=0, maxEmpleado, maxCategoria;

int cantRegistros= aEmpresa.contarRegistros();
while(pos<cantRegistros){
    empresa=aEmpresa.leerRegistro(pos);
    if(pos==0){
        maxEmpleado=empresa.getCantEmpleado();
        maxCategoria=empresa.getCategoria();
        
    }
    else{
        if(empresa.getCantEmpleado() > maxEmpleado){
            maxEmpleado=empresa.getCantEmpleado();
            maxCategoria=empresa.getCategoria();
           
        }
    }
 pos++;
}
 cout << " LA CATEGORIA " << maxCategoria << " ES LA QUE MÁS EMPLEADO TIENE." << endl;
}

#endif // REPORTES_H_INCLUDED
