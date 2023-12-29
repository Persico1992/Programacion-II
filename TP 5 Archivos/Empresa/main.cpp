#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const char *ArchiEmpresas= "Empresas.dat";    ///
const char *ArchiMunicipios= "Municipios.dat";
#include "FuncionesGlobales.h"
#include "Empresa.h"
#include "ArchivoEmpresa.h"
#include "Municipio.h"
#include "ArchivoMunicipio.h"
#include "Categoria.h"
#include "reportes.h"
#include "reportesMunicipio.h"
#include "reportesCategoria.h"
#include "Menu.h"


int main()
{
    setlocale (LC_ALL, "Spanish");
    
    Empresa empresa, vEmpresa[3];
    
    ArchivoEmpresa aEmpresa(ArchiEmpresas);
    
    Municipio muni;
    
    ArchivoMunicipio aMunicipio(ArchiMunicipios);
    
    menuPrincipal(empresa, aEmpresa, muni, aMunicipio);
    
    
    
    return 0;
}
