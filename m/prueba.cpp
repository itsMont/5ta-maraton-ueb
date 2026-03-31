#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("entrada.txt");

    // Formato del problema [cite: 40, 41, 42]
    file << "1" << endl;             // T = 1 caso de prueba
    file << "100000 1" << endl;      // N = 10^5, M = 1

    for (int i = 0; i < 100000; i++) {
        cout<<1<<" "; // 100,000 unos separados por espacios
    }


    return 0;
}
