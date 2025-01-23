#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Nodo {
public:
    int id;
    int distancia;

    Nodo(int _id, int _distancia) {
        id=_id;
        distancia=_distancia;
    }
};

bool abrirArchivo(string& ruta, vector<vector<int>>& matriz, int& cantNodos) {
    ifstream txt(ruta);
    if (!txt.is_open()) {
        cout << "No se encuentra el archivo" << endl;
        return false;
    }

    string primeraLinea;
    if (!getline(txt, primeraLinea) || primeraLinea.empty()) {
        cout << "El archivo esta vacio" << endl;
        return false;
    }
    try {
        cantNodos = stoi(primeraLinea);
    } catch (invalid_argument&) {
        cout << "la primera linea no es un numero valido" << endl;
        return false;
    }
    if (cantNodos <= 0) {
        cout << "Error - El numero de nodos debe ser mayor a 0" << endl;
        return false;
    }

    matriz.resize(cantNodos, vector<int>(cantNodos, 0));

    string linea;
    int i = 0;

    while (getline(txt, linea)) {
        if (i >= cantNodos) {
            cout << "Error - mas filas de las esperadas" << endl;
            return false;
        }

        stringstream ss(linea);
        string valor;
        int j = 0;

        while (getline(ss, valor, ',')) {
            if (j >= cantNodos) {
                cout << "Error - mas columnas de las esperadas en la fila " << i + 1 << endl;
                return false;
            }

            int peso;
            try {
                peso = stoi(valor);
            } catch (invalid_argument&) {
                cout << "Error - '" << valor << "' no es un numero valido" << endl;
                return false;
            }

            if (peso < 0) {
                cout << "Error - Hay un valor/coste negativo" << endl;
                return false;
            }

            matriz[i][j] = peso;
            ++j;
        }

        if (j != cantNodos) {
            cout << "Error - la fila " << i + 1 << " no tiene el numero correcto de columnas" << endl;
            return false;
        }

        ++i;
    }

    if (i != cantNodos) {
        cout << "Error - El numero de filas no coincide con el numero de nodos" << endl;
        return false;
    }

    txt.close();
    for (int i=0;i<cantNodos;i++) {
        for (int j=0;j<cantNodos;j++) {
            cout << matriz[i][j]<< " ";
        }
        cout << endl;
    }
    for (int i = 0; i < cantNodos; ++i) {
        cout << (char)('A' + i) << " ";
    }
    cout << endl;

    return true;
}

char pedirLetra(int cantNodos) {
    char letra;
    cout << "Ingrese el nodo Destino: ";
    cin >> letra;

    while (letra < 'A' || letra >= 'A' + cantNodos) {
        cout << "Error - Ingrese una letra valida entre A y " << (char)('A' + cantNodos - 1) << ": ";
        cin >> letra;
    }
    return letra;
}

void dijkstra(const vector<vector<int>>& matriz, int nodoInicio, int nodoFinal, int cantNodos) {

    cout <<"ola"<<endl;

}

int main() {
    vector<vector<int>> matriz;
    int cantNodos;

    string ubiTxt = "/workspaces/TareaEstructura/matriz.txt";

    if (abrirArchivo(ubiTxt, matriz, cantNodos)) {
        char letraFinal = pedirLetra(cantNodos);
        cout << "Nodo destino: " << letraFinal << endl;

        int nodoInicio = 0;
        int nodoFinal = letraFinal - 'A';
        dijkstra(matriz, nodoInicio, nodoFinal, cantNodos);
        
    }
    
    


    return 0;

}