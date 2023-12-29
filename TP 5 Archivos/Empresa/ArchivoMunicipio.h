#ifndef ARCHIVOMUNICIPIO_H_INCLUDED
#define ARCHIVOMUNICIPIO_H_INCLUDED

class ArchivoMunicipio{

private:
    char nombre[30];
    
public:
    
    ArchivoMunicipio(const char *n){strcpy(nombre,n);} ///Constructor:Sirve para recibir el nombre del archivo y poder gestionarlo   

    
     ///Leer/listar registro
    Municipio leerRegistro(int pos){
    Municipio reg;    ///Instancia de objeto --> El objeto esta VACIO
    FILE *p;
    p= fopen(nombre,"rb"); ///Sin comillas nombre, xq es una variable que va a tener el nombre dentro de la variable.
        if(p==NULL) return reg;
    fseek (p,sizeof reg*pos,0);     ///File buscar !
    fread (&reg,sizeof reg, 1, p);
        fclose(p);
    return reg;
    }
    
    ///Agregar registro
    int agregarRegistro(Municipio reg){
    FILE *p;
    p= fopen(nombre,"ab");
        if(p==NULL) return -1;
    int escribio= fwrite(&reg,sizeof reg, 1,p);
        fclose(p);
    return escribio;
    }
    
    ///Mostrar registros   
    int mostrarRegistros(){
    Municipio reg;
    FILE *p;
    p= fopen(nombre,"rb");
        if(p==NULL) return -1;
    while(fread(&reg,sizeof reg, 1,p)== 1){///Encontro un registro y me muestra el registro
        reg.mostrarMuni();
      cout << endl;  
     }
    }
    ///Contar registros
    int contarRegistros(){
    
    FILE *p;
    p=fopen(nombre,"rb");
        if(p==NULL) return -1;
    fseek(p,0,2);
    int tam= ftell(p); ///Aca preguntamos al archivo que tamaño tenes. Devuelve la cantidad de bytes que tiene el archivo en total. .
    fclose(p);
    return tam/sizeof(Municipio); /// Nos devuelve la cantidad de registro del archivo, este es un entero (int).
    
    }
    
};
#endif // ARCHIVOMUNICIPIO_H_INCLUDED
