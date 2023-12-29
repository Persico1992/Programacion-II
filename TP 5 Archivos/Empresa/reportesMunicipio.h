#ifndef REPORTESMUNICIPIO_H_INCLUDED
#define REPORTESMUNICIPIO_H_INCLUDED

void puntoD(){
 
    ArchivoMunicipio aMunicipio(ArchiMunicipios);
    Municipio muni;
    int pos=0, cantMunicipios=0;
    int cantRegistros= aMunicipio.contarRegistros();
    
    while(pos<cantRegistros){
        muni= aMunicipio.leerRegistro(pos);
        if(muni.getCantHabitantes() < 200000 ){
            cantMunicipios++;
            
        }
        pos++;
    }
    
    cout << "LA CANTIDAD DE MUNICIPIOS QUE TIENEN MENOS DE DOSCIENTOS MIL HABITANTES SON: " << cantMunicipios << endl;
}


void puntoE(){

ArchivoMunicipio aMunicipio (ArchiMunicipios);
Municipio muni;
int pos=0, maxCantidadHab, maxSeccion;

int cantRegistros= aMunicipio.contarRegistros();
while(pos<cantRegistros){
    muni=aMunicipio.leerRegistro(pos);
    if(pos==0){
        maxCantidadHab= muni.getCantHabitantes();
        maxSeccion= muni.getSeccion();
    }
    else{
        if
            (muni.getCantHabitantes() > maxCantidadHab){
            maxCantidadHab=muni.getCantHabitantes();
            maxSeccion=muni.getSeccion();
        }
        
    }
    pos++;
}
    cout << "LA SECCION CON LA MAYOR CANTIDAD DE HABITANTES ES LA NUMERO: " << maxSeccion << endl;
}

#endif // REPORTESMUNICIPIO_H_INCLUDED
