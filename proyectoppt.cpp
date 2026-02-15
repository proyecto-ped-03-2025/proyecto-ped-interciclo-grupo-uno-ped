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


int main(){
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
        } while(op !=7) ; 
    return 0; 
}