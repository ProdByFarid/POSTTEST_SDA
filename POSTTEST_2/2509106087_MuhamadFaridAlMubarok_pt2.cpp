#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

#define MAKS_DATA 50
Hewan dataHewan[MAKS_DATA];
int jumlahData = 0;

struct Hewan {
    int idHewan;
    string namaHewan;
    string jenisHewan;
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
             << setw(15) << "Harga" << endl;
        cout << header << endl;

        for (Hewan *ptr = dataHewan; ptr < dataHewan + jumlahData; ptr++) {
            cout << left << setw(5) << (*ptr).idHewan 
            << setw(15) << (*ptr).namaHewan 
            << setw(15) << (*ptr).jenisHewan 
            << setw(15) << "Rp " << (*ptr).hargaHewan << endl;
        }
        cout << header << endl;
    }
}

void tukar(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSortNama() {
    if (jumlahData == 0) {
        cout << "(!) Tidak Ada Data Untuk Diurutkan!" << endl;
        jeda();
    } else {
        for (int i = 0; i < jumlahData - 1; i++) {
            for (int j = 0; jumlahData - i - 1; j++) {
                Hewan *ptr1 = dataHewan[j];
                Hewan *ptr2 = dataHewan[j + 1];

                if ((*ptr1).namaHewan > (*ptr2).namaHewan) {
                    tukar(ptr1, ptr2);
                }
            }
        } 
        cout << "(+) Data Berhasil Diurutkan Berdasarkan Nama (A-Z)" << endl;
        jeda();
    }
}

void bubbleSortId() {
    if (jumlahData == 0) {
        cout << "(!) Tidak Ada Data Untuk Diurutkan!" << endl;
        jeda();
    } else {
        for (int i = 0; i < jumlahData - 1; i++) {
            for (int j = 0; jumlahData - i - 1; j++) {
                Hewan *ptr1 = dataHewan[j];
                Hewan *ptr2 = dataHewan[j + 1];

                if ((*ptr1).idHewan > (*ptr2).idHewan) {
                    tukar(ptr1, ptr2);
                }
            }
        } 
        cout << "(+) Data Berhasil Diurutkan Berdasarkan ID" << endl;
    }
}


void selectionSortHarga() {
    if (jumlahData == 0) {
        cout << "(!) Tidak Ada Data Untuk Diurutkan!" << endl;
        jeda();
    } else {
        for (int i = 0; i < jumlahData - 1; i++) {
            int indeksMin = i;
            
            for (int j = i + 1; j < jumlahData; j++) {
                Hewan *ptr1 = dataHewan[indeksMin];
                Hewan *ptr2 = dataHewan[j];
                
                if ((*ptr2).hargaHewan < (*ptr1).hargaHewan) {
                    indeksMin = j;
                }
            }
            tukar(&dataHewan[indeksMin], &dataHewan[i]);
        }
        cout << "(+) Data Berhasil Diurutkan Berdasarkan Harga" << endl;
        jeda();
    }
}

void linearSearchNama() {
    string target;
    cout << "\nCari Nama Hewan: ";
    cin.ignore();
    getline(cin, target);

    bool ada = false;
    Hewan *ptr1 = &dataHewan;
    Hewan *ptr2 = dataHewan + jumlahData;

    while (ptr1 < ptr2) {
        if (target == (*ptr1).namaHewan) {
            cout << "\n(+) Data Ditemukan!" << endl;
            cout << "\nID Hewan: " << (*ptr1).idHewan << endl;
            cout << "\nNama Hewan  : " << (*ptr1).namaHewan << endl;
            cout << "\nJenis Hewan : " << (*ptr1).jenisHewan << endl;
            cout << "\nHarga Hewan : " << (*ptr1).hargaHewan << endl;

            ada = true;
            break;
        }
    }

    if (!ada) {
        cout << "(-) Data Tidak Ditemukan!" << endl;
    }
}

void fibbonaciSearchId() {
    int target;

    if (jumlahData == 0) {
        cout << "(!) Tidak Ada Data Untuk Dicari!" << endl;
        jeda();
    } else {
        bubbleSortId();

        cout << "\nCari ID Hewan: ";
        cin >> target;

        int fib2 = 0;
        int fib1 = 1;
        int fib = fib2 + fib1;

        while (fib < jumlahData) {
            fib2 = fib1;
            fib1 = fib;
            fib = fib2 + fib1;
        }

        int offset = -1;
        bool ada = false;
        Hewan *ptr;

        while (fib > 1) {

            int i = min(offset + fib2, jumlahData - 1);

            ptr = &dataHewan[i]; 

            if ((*ptr).idHewan < target) {
                fib = fib1;
                fib1 = fib2;
                fib2 = fib - fib1;
                offset = i;
            } else if ((*ptr).idHewan > target) {
                fib = fib2;
                fib1 = fib1 - fib2;
                fib2 = fib - fib1;
            } else {
                cout << "\n(+) Data Ditemukan!" << endl;
                cout << "\nID Hewan: " << (*ptr).idHewan << endl;
                cout << "\nNama Hewan  : " << (*ptr).namaHewan << endl;
                cout << "\nJenis Hewan : " << (*ptr).jenisHewan << endl;
                cout << "\nHarga Hewan : " << (*ptr).hargaHewan << endl;

                ada = true;
                break;
            }

                return;
            
        }
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
        cout << "|  [3]. Cari Nama Hewan                |" << endl;
        cout << "|  [4]. Cari ID Hewan                  |" << endl;
        cout << "|  [5]. Urutkan Data Hewan (Nama)      |" << endl;
        cout << "|  [6]. Urutkan Data Hewan (Harga)     |" << endl;
        cout << "|  [7]. Keluar                         |" << endl;
        cout << header << endl;
        cout << "Masukkan Opsi: ";
        cin >> pilihan;

        if (pilihan == '1') {

        }
    } while (pilihan != '7');
    
}

int main() {

    dataHewan[0] = {74, "Beef", "Chihuahua", 450000};
    dataHewan[1] = {13, "Nemo", "Ikan Badut", 1300000};
    dataHewan[2] = {22, "Little One", "Ginger Cat", 300000};
    dataHewan[3] = {31, "Gary", "Siput Laut", 580000};
    dataHewan[4] = {26, "Kuma The Destoyer", "Beruang Grizly", 7600000};
    dataHewan[5] = {2, "Thomas", "Russian Grayish-Blue.", 9000000};
    dataHewan[6] = {7, "Jerry", "Tikus", 1500000};
    dataHewan[7] = {16, "Punch", "Japanese Macqque", 3300000};
    dataHewan[8] = {45, "Judy", "Kelinci", 500000};
    dataHewan[9] = {67, "Nick", "Rubah", 1550000};
    jumlahData = 10;

    menuUtama();

    return 0;
}