#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void abrirArchivo(string x){
    ifstream txt(x);
    if (!txt.is_open()) {
        cout << "El archivo no se encuentra en el sistema" << endl;
        return;
    }
    int cantNodos;
    txt >> cantNodos;
    txt.ignore(); 

    vector<vector<int>> matriz(cantNodos, vector<int>(cantNodos));
    string linea;

    for (int i = 0; i < cantNodos; ++i) {
        getline(txt, linea);
        stringstream ss(linea);
        string valor;
        int j = 0;
        while (getline(ss, valor, ',')) {
            matriz[i][j] = stoi(valor);
            ++j;
        }
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
    return;

}



int main(){
    abrirArchivo("/workspaces/TareaEstructura/matriz.txt");
    
    cout <<"ola"<<endl;
    


    return 0;

}