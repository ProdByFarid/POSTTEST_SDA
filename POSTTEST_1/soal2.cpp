#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama, nim;
    float ipk;
};

int main () {

    string judul = R"(
====================================
|                                  |
|  Soal 2 (MENCARI IPK TERTINGGI)  |
|                                  |
====================================)";

    system("cls");
    cout << judul << endl;
    
    Mahasiswa mhs[5];
    int i = 0;

    do
    {
        cout << "\nData Mahasiswa Ke-" << i + 1 << endl;
        cout << "\nMasukkan Nama Mahasiswa: ";
        cin >> mhs[i].nama;
        cout << "Masukkan NIM Mahasiswa: ";
        cin >> mhs[i].nim;
        cout << "Masukkan IPK Mahasiswa: ";
        cin >> mhs[i].ipk;

        i++;
    } while (i < 5);

    int ipkTertinggi = 0;
    for (int i = 0; i < 5; i++) {
        if (mhs[i].ipk > mhs[ipkTertinggi].ipk) {
            ipkTertinggi = i;
        }
    }
    
    cout << "\n--- Data Mahasiswa Dengan IPK Tertinggi ---" << endl;
    cout << "\nNama: " << mhs[ipkTertinggi].nama;
    cout << "\nNIM: " << mhs[ipkTertinggi].nim;
    cout << "\nIPK: " << mhs[ipkTertinggi].ipk;
    
    return 0;
}