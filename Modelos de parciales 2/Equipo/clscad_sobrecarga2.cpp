/// Ejercicio:
/// Autor:DEK
/// Fecha:
/// Comentario:

#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class Cadena {
private:
    char *p;
    int tam;

public:
    Cadena(const char *ini = "nada") {
        tam = strlen(ini) + 1;
        p = new char[tam];
        if (p == NULL) {
            cout << "ERROR DE ASIGNACION DE MEMORIA" << endl;
            exit(1);
        }
        strcpy(p, ini);
        p[tam - 1] = '\0';
    }
    void Mostrar() { cout << p << endl; }
    int getTam() { return tam; }
    const char *getP() { return p; }
    ~Cadena() { delete p; }
    /// SOBRECARGAS
    bool operator==(const Cadena &obj) {
        if (strcmp(this->p, obj.p) == 0) return true;
        return false;
    }
    bool operator==(const char *obj) {
        if (strcmp(this->p, obj) == 0) return true;
        return false;
    }
    bool operator>(const Cadena &obj) {
        if (strcmp(this->p, obj.p) > 0) return true;
        return false;
    }
    // es igual a esta pero al reves jaja
    bool operator>(int tamanio) {
        if (tam > tamanio) return true;
        return false;
    }

    bool operator!=(const Cadena &obj) {
        if (strcmp(this->p, obj.p) != 0) return true;
        return false;
    }
    bool operator!=(const char *obj) {
        if (strcmp(this->p, obj) != 0) return true;
        return false;
    }

    bool operator<=(const Cadena &obj) {
        if (strcmp(this->p, obj.p) == 0 || strcmp(this->p, obj.p) == -1)
            return true;
        return false;
    }

    // para strlen hay que pasarle un int
    bool operator<=(int tamanio) {
        if (this->tam <= tamanio) return true;
        return false;
    }

    Cadena &operator=(const Cadena &obj) {
        delete p;
        tam = obj.tam;
        p = new char[tam];
        if (p == NULL) exit(1);
        strcpy(p, obj.p);
        return *this;
    }

    Cadena &operator=(const char *obj) {
        delete p;
        tam = strlen(obj) + 1;
        p = new char[tam];
        if (p == NULL) exit(1);
        strcpy(p, obj);
        p[tam - 1] = '\0';
        return *this;
    }

    void operator+=(const Cadena &obj) {
        tam += strlen(obj.p) + 1;
        strcat(p, obj.p);
    }

    void operator+=(const char *obj) {
        tam += strlen(obj) + 1;
        strcat(p, obj);
    }
};

/// SOBRECARGA DE OPERADORES: ES UN MECANISMO QUE NOS PERMITE AGREGAR
/// FUNCIONALIDAD A LOS OPERADORES EXISTENTES. SE CONSIGUE ESCRIBIENDO UN C�DIGO
/// SUJETO A CIERTAS REGLAS DENTRO DE LA CLASE.
int main() {
    Cadena palabra("zorro "), aux("zorrin"), otra("pepito");

    palabra += aux;
    palabra.Mostrar();

    if (palabra != aux) cout << "son distintos.\n";

    if (palabra <= aux) cout << "palabra es menor o igual\n";

    // otra.getTam() devuelve 7
    // strlen(otra.getP()) devuelve 6
    if (aux <= otra.getTam()) {
        cout << aux.getP() << " es menor o igual que " << otra.getP();
    }

    system("pause");
    return 0;
}

/// Sobrecargar el operador != de manera tal que sea verdadero cuando los dos
/// objetos a comparar sean distintos Sobrecargar el operador <= para dos casos:
/// para comparar las cadenas de caracteres y para comparar el largo de la
/// cadenas Sobrecargar el operador += de manera tal que se concatenen las dos
/// cadenas
