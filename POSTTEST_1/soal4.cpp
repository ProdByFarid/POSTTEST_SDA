#include <iostream>
using namespace std;

void tukar (int *ptrNilaiA, int *ptrNilaiB) {

    int temp = *ptrNilaiA;
    *ptrNilaiA = *ptrNilaiB;
    *ptrNilaiB = temp;

}

int main () {

    int nilaiA, nilaiB;

    system("cls");

    string judul = R"(
=====================================
|                                   |
|  Soal 4 (MENUKAR NILAI VARIABEL)  |
|                                   |
=====================================)";

    cout << judul << endl;
    cout << "\nMasukkan Nilai Pertama: ";
    cin >> nilaiA;
    cout << "Masukkan Nilai Kedua: ";
    cin >> nilaiB;

    cout << "\n--- Hasil Nilai Sebelum Ditukar ---" << endl;
    cout << "Nilai Pertama: " << nilaiA << endl;
    cout << "Nilai Kedua: " << nilaiB << endl;
    
    tukar(&nilaiA, &nilaiB);
    cout << "\n--- Hasil Nilai Sesudah Ditukar ---" << endl;
    cout << "Nilai Pertama: " << nilaiA << endl;
    cout << "Nilai Kedua: " << nilaiB << endl;
    cout << '\n';

    return 0;
}