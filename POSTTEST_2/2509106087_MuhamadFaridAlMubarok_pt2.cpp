#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

#define MAKS_DATA 50
Hewan dataHewan[MAKS_DATA];
int jumlahData = 0;

struct Hewan {
    string namaHewan;
    string jenisHewan;
    string pemilikHewan;
    int idHewan;
    int hargaHewan;
};

void jeda() {
    cout << "\n[Tekan Enter Untuk Melanjutkan...]" << endl;
    getch();
}

void tambahHewan() {
    if (jumlahData >= MAKS_DATA) {
        cout << "\n(!) Kapasitas Data Penuh!" << endl;
        jeda();
    } else {

        Hewan *ptrHewan = &dataHewan[jumlahData];

        cout << "\n--- Tambah Data Hewan ---" << endl;
        cout << "ID Hewan (Angka): ";
        cin >> (*ptrHewan).idHewan;
        cin.ignore();
        cout << "Nama Hewan: ";
        getline(cin, (*ptrHewan).namaHewan);
        cout << "Jenis Hewan: ";
        getline(cin, (*ptrHewan).jenisHewan);
        cout << "Harga Hewan: Rp";
        cin >> (*ptrHewan).hargaHewan;  
        cin.ignore();
        cout << "Pemilik Hewan: ";
        getline(cin, (*ptrHewan).pemilikHewan);

        jumlahData++;
        cout << "\n(+) Data Berhasil Ditambahkan" << endl;
        jeda();
    }
}

void lihatData() {
    string header = "==========================================================================";

    if (jumlahData == 0) {
        cout << "\n (!) Belum Ada Data Yang Ditambhkan" << endl;
        return;
    } else {
        cout << "--- Lihat Data ---" << endl;

        cout << header << endl;
        cout << left << setw(5) << "ID" << setw(15) << "Nama" << setw(15) << "Jenis" 
             << setw(15) << "Harga" << setw(20) << "Pemilik"<< endl;
        cout << header << endl;

        for (Hewan *ptr = dataHewan; ptr < dataHewan + jumlahData; ptr++) {
            cout << left << setw(5) << (*ptr).idHewan 
            << setw(15) << (*ptr).namaHewan 
            << setw(15) << (*ptr).jenisHewan 
            << setw(15) << "Rp " << (*ptr).hargaHewan 
            << setw(20) << (*ptr).pemilikHewan << endl;
        }
        cout << header << endl;
    }
}

void tukarPointer(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    
    return 0;
}