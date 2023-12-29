///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

class Cadena{
private:
    char *p;
    int tam;
public:
     Cadena(const char *ini="nada"){ ///valor por defecto, nos permite declarar objetos sin necesidad de mandale parámetros
        tam=strlen(ini)+1;
        p=new char[tam];
        if(p==NULL){
            cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
            exit(1);
        }
        strcpy(p,ini);
        p[tam-1]='\0';
     }
    void Mostrar(){
        cout<<p<<endl;
     }
    int getTam(){return tam;}
    const char *getP(){return p;}
    ///Destructor
     ~Cadena(){
        delete p;
     }
    ///SOBRECARGAS
     bool operator==(const Cadena &obj){
        if(strcmp(this->p,obj.p)==0)return true;
        return false;
     }
     bool operator==(const char *obj){
        if(strcmp(this->p,obj)==0)return true;
        return false;
     }
     bool operator>(const Cadena &obj){
        if(strcmp(this->p,obj.p)>0)return true;
        return false;
     }

     Cadena & operator=(const Cadena &obj){
        delete p;
        tam=obj.tam;
        p=new char[tam];
        if(p==NULL) exit(1);
        strcpy(p,obj.p);
        return *this;
     }
     
     Cadena & operator=(const char *obj){
        delete p;
        tam=strlen(obj)+1;
        p=new char[tam];
        if(p==NULL) exit(1);
        strcpy(p,obj);
        p[tam-1]='\0';
        return *this;
     }
     ///Función para comparar largo de cadena
     bool operator >(int tamanio){    
     if (tam > tamanio) return true;
     return false;
        
     }
     ///Sobrecargar el operador != de manera tal que sea verdadero cuando los dos objetos a comparar sean distintos
     bool operator !=(const Cadena &obj){
        if(strcmp(this-> p,obj.p) >0 || strcmp(this-> p,obj.p) < 0) return true;
        return false;
     }
     ///Sobrecargar el operador <= para dos casos: para comparar las cadenas de caracteres y para comparar el largo de la cadenas
        bool operator<=(const Cadena &obj){ 
        if(strcmp(this->p,obj.p)<=0) return true;
        return false;
     }
        
     // para strlen hay que pasarle un int
        bool operator<=(int tamanio) {
        if (this->tam <= tamanio) return true;
        return false;
    }
     ///Sobrecargar el operador += de manera tal que se concatenen las dos cadenas
     
  /*   void operator += ( Cadena &obj){       ///DISTINTO A LO QUE HICIMOS CON EL PROFE
        tam+= obj.getTam() -1;
        char * aux= new char [tam];
        if(aux == NULL){
            cout << "ERROR DE ASIGNACIÓN DE MEMORIA." << endl;
            exit(1);
        }
        strcpy(aux,p);
        delete p;
        strcat(aux,obj.p);
        p=new char [tam];
        if(p==NULL){
            cout << "ERROR DE ASIGNACION DE MEMORIA." << endl;
            exit(1);
        }
        strcpy(p,aux);
        delete aux;
     }*/
     
      void operator+=(const Cadena &obj) {
        tam += strlen(obj.p) + 1;
        strcat(p, obj.p);
    }

    void operator+=(const char *obj) {
        tam += strlen(obj) + 1;
        strcat(p, obj);
    }
     
};

///SOBRECARGA DE OPERADORES: ES UN MECANISMO QUE NOS PERMITE AGREGAR FUNCIONALIDAD A LOS OPERADORES EXISTENTES.
///SE CONSIGUE ESCRIBIENDO UN CÓDIGO SUJETO A CIERTAS REGLAS DENTRO DE LA CLASE.
int main(){
    Cadena palabra("zorro"), aux("zorrino"), otra;
    ////
    ///if(strcmp(palabra.getP(), aux.getP())==0){ Comparamos CADENAS, SIN SOBRECARGA

    ///Prueba con el operador +=
    cout << "Prueba de operador += " << endl;
    palabra+=aux;
    palabra.Mostrar();
    
    
   
  /* //Prueba para el operador <=
   cout << "Comparamos entre cadenas cual viene antes para operador <=: " << endl;
    if(palabra <= aux){
        cout <<" La primera palabra esta más cerca de la letra A" << endl ;
    }
    else{
        cout << "La segunda palabra esta más cerca de la letra A " << endl;
    }
    cout << endl;
    cout << "Comparamos las longitudes " << endl << endl;
    
    if (aux <= palabra.getTam()){
        cout << "Tienen misma longitud." << endl;
    }
    else{
        cout << "Tienen distintas longitud." << endl;
    }

/*   Prueba para el operador !=
    if(palabra != aux){
        cout << "Son distintos";
    }
    else{
        cout << "Son iguales";
    }
*/   
    
    //otra=palabra=aux="UNA ASIGNACION NUEVA";
   // palabra.Mostrar();
    //otra.Mostrar();
    //if(palabra=="zorro")cout<<"SON IGUALES";
    //else cout<<"SON DISTINTOS";
    /*if(aux>palabra.getTam()){
        cout<<"LA PRIMERA TIENE MAS CARACTERES";
    }
    else{
        cout<<"LA PRIMERA NO TIENE MAS CARACTERES";
    } */
	cout<<endl;
	system("pause");
	return 0;
}

///Sobrecargar el operador != de manera tal que sea verdadero cuando los dos objetos a comparar sean distintos
///Sobrecargar el operador <= para dos casos: para comparar las cadenas de caracteres y para comparar el largo de la cadenas
///Sobrecargar el operador += de manera tal que se concatenen las dos cadenas
