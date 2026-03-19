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
        jeda();
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

void tukarNilai(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort() {
    if (jumlahData == 0) {
        cout << "(!) Tidak Ada Data Untuk Diurutkan!" << endl;
        jeda();
    } else {
        for (int i = 0; i < jumlahData - 1; i++) {
            for (int j = 0; jumlahData - i - 1; j++) {
                Hewan *ptrBS1 = dataHewan[j];
                Hewan *ptrBS2 = dataHewan[j + 1];

                if ((*ptrBS1).namaHewan > (*ptrBS2).namaHewan) {
                    tukarNilai(ptrBS1, ptrBS2);
                }
            }
        } 
        cout << "(+) Data Berhasil Diurutkan Berdasarkan Nama (A-Z)"
    }
}

void menuUtama() {
    char pilihan;
    string header = "========================================";
    do {
        system("cls");

        cout << header << endl;
        cout << "     Pawcare Petshop & Dokter Hewan     " << endl;
        cout << header << endl;
        cout << "|  [1]. Tambah Data Hewan Baru         |" << endl;
        cout << "|  [2]. Tampilkan Semua Data Hewan     |" << endl;
        cout << "|  [1]. Tambah Data Hewan Baru     |"
        cout << "|  [1]. Tambah Data Hewan Baru     |"
        cout << "|  [1]. Tambah Data Hewan Baru     |"
        cout << "|  [1]. Tambah Data Hewan Baru     |"
    } while (pilihan != '7');
    
}

int main() {


    return 0;
}