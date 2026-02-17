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
    void mostrarParticipantes();
    void jugar();
    void enfrentamiento(Participante* a, Participante* b);
    void reportarGanador();
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


    // 3) Funcion para mostrar lista de jugadores
    void JuegoCircular::mostrarParticipantes() {
        if (!lista) { cout << "No hay jugadores inscritos.\n"; return; }
        Participante* aux = lista;
        cout << "Lista de Competidores\n";
        do {
            cout << "ID: " << aux->id << " | Nombre: " << aux->nombre << endl;
            aux = aux->siguiente;
        } while (aux != lista);
    };

    // 4) Realización del juego: Todos contra todos 
    void JuegoCircular::jugar() {
        if (total < 2) { cout << "Se necesitan al menos 2 jugadores.\n"; return; }
        
        Participante* actual = lista;
        for (int i = 0; i < total; i++) {
            Participante* oponente = actual->siguiente;
            for (int j = i + 1; j < total; j++) {
                enfrentamiento(actual, oponente);
                oponente = oponente->siguiente;
            }
            actual = actual->siguiente;
        }
        cout << "\nRonda terminada\n";
            cout << "Pulse (3) para otra ronda" << endl;
            cout << "O pulse (4) para ver al ganador" << endl;
    }

void JuegoCircular::enfrentamiento(Participante* a, Participante* b) {
    int eleccionA, eleccionB;
    
    cout << "\nTURNO DE COMBATE" << endl;
    cout << "Combaten: " << a->nombre << " vs " << b->nombre << endl;

    // Entrada para el Jugador 1
    do {
        cout << a->nombre << ", elige (0: Piedra, 1: Papel, 2: Tijera): ";
        cin >> eleccionA;
    } while (eleccionA < 0 || eleccionA > 2);

    // Entrada para el Jugador 2
    do {
        cout << b->nombre << ", elige (0: Piedra, 1: Papel, 2: Tijera): ";
        cin >> eleccionB;
    } while (eleccionB < 0 || eleccionB > 2);

    string opciones[] = {"Piedra", "Papel", "Tijera"};
    cout << "\nResultado: " << a->nombre << " [" << opciones[eleccionA] << "] vs " 
         << b->nombre << " [" << opciones[eleccionB] << "]" << endl;

    // Lógica de asignación de puntos segun ganen, pierdan o empaten 
    if (eleccionA == eleccionB) {
        cout << "Empate, 1 punto para cada uno." << endl;
        a->puntos += 1;
        b->puntos += 1;
    } else if ((eleccionA == 0 && eleccionB == 2) || 
               (eleccionA == 1 && eleccionB == 0) || 
               (eleccionA == 2 && eleccionB == 1)) {
        cout << "Ganador: " << a->nombre << " Recibe 3 puntos." << endl;
        a->puntos += 3;
    } else {
        cout << "Ganador: " << b->nombre << " Recibe 3 puntos." << endl;
        b->puntos += 3;
    }
    cout << "-------------------------" << endl;
}
//FUncion para reportar el ganador, recorre la lista comparando cual es el jugador con mas puntos.
void JuegoCircular::reportarGanador() {
        if (!lista) return;
        Participante* aux = lista;
        Participante* ganador = lista;
        do {
            if (aux->puntos > ganador->puntos) ganador = aux;
            aux = aux->siguiente;
        } while (aux != lista);

        cout << "\nEL GANADOR ES: " << ganador->nombre << " con " << ganador->puntos << " puntos!\n";
    };

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

        case 2:
            juego.mostrarParticipantes();
            break;
        
         case 3:
            juego.jugar();
            break;
        
        case 4:
            juego.reportarGanador();
            break;

        default:  cout << "Seleccione una opcion valida." << endl;   
            break;
        }
        } while(op !=7) ; 
    return 0; 
}