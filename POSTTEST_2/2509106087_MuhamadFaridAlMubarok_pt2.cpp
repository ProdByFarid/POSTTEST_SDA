#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

#define MAKS_DATA 50

struct Hewan {
    int idHewan;
    string namaHewan;
    string jenisHewan;
    int hargaHewan;
};

int jumlahData = 0;
Hewan dataHewan[MAKS_DATA];

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
    string header = "=================================================================================";

    if (jumlahData == 0) {
        cout << "\n (!) Belum Ada Data Yang Ditambahkan" << endl;
        jeda();
    } else {
        cout << "\n--- Lihat Data ---" << endl;

        cout << header << endl;
        cout << "| " << setw(4) << left << "ID"
            << "| " << setw(25) << left << "Nama"
            << "| " << setw(30) << left << "Jenis"
            << "| " << setw(12) << left << "Harga" << " |" << endl;

        cout << header << endl;

        for (Hewan *ptr = dataHewan; ptr < dataHewan + jumlahData; ptr++) {
            cout << "| " << left << setw(4) << (*ptr).idHewan 
            << "| " << setw(25) << (*ptr).namaHewan 
            << "| " << setw(30) << (*ptr).jenisHewan 
            << "| Rp" << setw(10) << (*ptr).hargaHewan << " |" << endl;
        }
        cout << header << endl;
        jeda();
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
            for (int j = 0; j < jumlahData - i - 1; j++) {
                Hewan *ptr1 = &dataHewan[j];
                Hewan *ptr2 = &dataHewan[j + 1];

                if ((*ptr1).namaHewan > (*ptr2).namaHewan) {
                    tukar(ptr1, ptr2);
                }
            }
        } 
        cout << "\n(+) Data Berhasil Diurutkan Berdasarkan Nama (A-Z)" << endl;
        cout << "(+) Silahkan Cek Di Pilihan Nomor 2" << endl;
        jeda();
    }
}

void bubbleSortId() {
    if (jumlahData == 0) {
        cout << "(!) Tidak Ada Data Untuk Diurutkan!" << endl;
        jeda();
    } else {
        for (int i = 0; i < jumlahData - 1; i++) {
            for (int j = 0; j < jumlahData - i - 1; j++) {
                Hewan *ptr1 = &dataHewan[j];
                Hewan *ptr2 = &dataHewan[j + 1];

                if ((*ptr1).idHewan > (*ptr2).idHewan) {
                    tukar(ptr1, ptr2);
                }
            }
        } 
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
                Hewan *ptr1 = &dataHewan[indeksMin];
                Hewan *ptr2 = &dataHewan[j];
                
                if ((*ptr2).hargaHewan < (*ptr1).hargaHewan) {
                    indeksMin = j;
                }
            }
            tukar(&dataHewan[indeksMin], &dataHewan[i]);
        }
        cout << "\n(+) Data Berhasil Diurutkan Berdasarkan Harga" << endl;
        cout << "(+) Silahkan Cek Di Pilihan Nomor 2" << endl;
        jeda();
    }
}

void linearSearchNama() {
    string target;
    cout << "\nCari Nama Hewan: ";
    cin.ignore();
    getline(cin, target);

    bool ada = false;
    Hewan *ptr1 = dataHewan;
    Hewan *ptr2 = dataHewan + jumlahData;

    while (ptr1 < ptr2) {
        if (target == (*ptr1).namaHewan) {
            cout << "\n(+) Data Ditemukan!" << endl;
            cout << "\nID Hewan    : " << (*ptr1).idHewan << endl;
            cout << "Nama Hewan  : " << (*ptr1).namaHewan << endl;
            cout << "Jenis Hewan : " << (*ptr1).jenisHewan << endl;
            cout << "Harga Hewan : Rp" << (*ptr1).hargaHewan << endl;
            ada = true;
            break;
        }
        ptr1++;
    }

    if (!ada) {
        cout << "\n(-) Data Tidak Ditemukan!" << endl;
    }
    jeda();
}

void fibbonaciSearchId() {
    int target;

    if (jumlahData == 0) {
        cout << "(!) Tidak Ada Data Untuk Dicari!" << endl;
        jeda();
        return;
    }
    
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
        int i = offset + fib2;
        if (i > jumlahData - 1) {
            i = jumlahData - 1;
        }

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
            cout << "\nID Hewan    : " << (*ptr).idHewan << endl;
            cout << "Nama Hewan  : " << (*ptr).namaHewan << endl;
            cout << "Jenis Hewan : " << (*ptr).jenisHewan << endl;
            cout << "Harga Hewan : Rp" << (*ptr).hargaHewan << endl;
            ada = true;
            break;
        }
    }

    if (!ada && fib1 && offset < jumlahData - 1) {
        ptr = &dataHewan[offset + 1];
        if ((*ptr).idHewan == target) {
            cout << "\n(+) Data Ditemukan!" << endl;
            cout << "\nID Hewan    : " << (*ptr).idHewan << endl;
            cout << "Nama Hewan  : " << (*ptr).namaHewan << endl;
            cout << "Jenis Hewan : " << (*ptr).jenisHewan << endl;
            cout << "Harga Hewan : Rp" << (*ptr).hargaHewan << endl;
            ada = true;
        }
    }

    if (!ada) {
        cout << "\n(-) Data Tidak Ditemukan!" << endl;
    }
    jeda();
}

void menuUtama() {
    char pilihan;
    string header = "========================================";
    do {
        system("cls");

        cout << header << endl;
        cout << "|    Pawcare Petshop & Dokter Hewan    |" << endl;
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
            tambahHewan();
        } else if (pilihan == '2') {
            lihatData();
        } else if (pilihan == '3') {
            linearSearchNama();
        } else if (pilihan == '4') {
            fibbonaciSearchId();
        } else if (pilihan == '5') {
            bubbleSortNama();
        } else if (pilihan == '6') {
            selectionSortHarga();
        } else if (pilihan == '7') {
            cout << "\nTerima Kasih Telah Menggunakan Program Ini!" << endl;
            jeda();
            break;
        } else {
            cout << "\n(!) Pilihan Tidak Valid!" << endl;
            jeda();
        }
    } while (pilihan != '7');
}

int main() {
    dataHewan[0] = {74, "Beef", "Chihuahua", 850000};
    dataHewan[1] = {13, "Ciko", "Ikan Badut", 800000};
    dataHewan[2] = {22, "Fluxx", "Ginger Cat", 650000};
    dataHewan[3] = {31, "Gary", "Siput Laut", 600000};
    dataHewan[4] = {26, "Kuma The Destoyer", "Beruang Grizly", 450000};
    dataHewan[5] = {2, "Heli", "Russian Grayish-Blue", 550000};
    dataHewan[6] = {7, "Emily", "Tikus", 700000};
    dataHewan[7] = {16, "Dune", "Japanese Macaque", 750000};
    dataHewan[8] = {45, "Judy", "Kelinci", 500000};
    dataHewan[9] = {67, "Astra", "Rubah", 900000};
    jumlahData = 10;

    menuUtama();

    return 0;
}