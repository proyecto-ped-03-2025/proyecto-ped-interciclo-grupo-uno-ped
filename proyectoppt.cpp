#include <iostream>
#include <string>

using namespace std;

// Estructura para los Jugadores
struct Participante {
    string nombre;
    char id;
    int puntos;
    Participante* siguiente;
};

// Clase para gestionar la lista circular 
class JuegoCircular {
private:
    Participante* lista;
    int total;

public:
    JuegoCircular() : lista(nullptr), total(0) {}
    void inscribir(string nom, char identificador);

};
//Funcion que nos permite registrar un participante en nuestra lista circular
void JuegoCircular::inscribir(string nom, char identificador) {
        //valida si lista es != nullptr, en caso no, recorre la lista para validar que no hayan nombres o id repetidos :D
         if (lista!= nullptr) {

            Participante* aux = lista;

            do {
                if (aux->nombre == nom) {
                    cout << "Error: Ya existe un jugador con ese nombre.\n";
                    return;
                    }

                if (aux->id == identificador) {
                    cout << "Error: Ya existe un jugador con ese identificador.\n";
                    return;
                    }

            aux = aux->siguiente;

        } while (aux != lista);
        
        }
        Participante* nuevo = new Participante{nom, identificador, 0, nullptr};
        
        if (!lista) {
            lista = nuevo;
            nuevo->siguiente = lista;
        } else {
            Participante* aux = lista;
            while (aux->siguiente != lista) aux = aux->siguiente;
        
            aux->siguiente = nuevo;
            nuevo->siguiente = lista;
        }
        total++;
        cout << "El Jugador se inscribio.\n";
    }

int main(){
JuegoCircular juego;
string n; 
char id;
int op;
    do { 
        cout << "\nMENU PIEDRA, PAPEL O TIJERA\n";
        cout << "1) Inscribir Participante "<< endl;
        cout << "2) Listar Participantes " << endl; 
        cout << "3) Jugar Ronda " << endl;
        cout << "4) Reportar Ganador " << endl;
        cout << "5) Ayuda " << endl;
        cout << "6) Integrantes" << endl;
        cout << "7) Salir " << endl;
        cout << "Opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Nombre: "; cin >> n;
            cout << "ID (caracter): "; cin >> id;
                juego.inscribir(n, id);
        break;
        
        default:  cout << "Seleccione una opcion valida." << endl;   
            break;
        }
        } while(op !=7) ; 
    return 0; 
}