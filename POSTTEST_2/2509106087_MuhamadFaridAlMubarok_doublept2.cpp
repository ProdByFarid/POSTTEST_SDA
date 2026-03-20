#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

#define MAKS_DATA 50
#define ALFABET 256

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

void tukar(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tambahHewan() {
    if (jumlahData >= MAKS_DATA) {
        cout << "\n(!) Kapasitas Data Penuh!" << endl;
        jeda();
    } else {
        while (true) {
            bool cekId = false;
            Hewan *ptrHewan = &dataHewan[jumlahData];
            system("cls");

            cout << "\n--- Tambah Data Hewan ---" << endl;
            cout << "\nID Hewan (Angka): ";
            cin >> (*ptrHewan).idHewan;

            for (int i = 0; i < jumlahData; i++) {
                if ((*ptrHewan).idHewan == dataHewan[i].idHewan) {
                    cekId = true;
                    break;
                }
            }

            if (cekId) {
                cout << "\n(!) ID Sudah Dipakai. Silahkan Gunakan ID Lain!" << endl;
                jeda();
                system("cls");
                continue;
            }

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
            break;
        }
    }
}

void lihatData() {
    string header = "=================================================================================";

    if (jumlahData == 0) {
        cout << "\n (!) Belum Ada Data Yang Ditambahkan" << endl;
        jeda();
    } else {
        system("cls");
        cout << "\n--- Lihat Data ---" << endl;
        cout << endl;
        cout << header << endl;
        cout << "| " << setw(4) << left << "ID"
            << "| " << setw(25) << left << "Nama"
            << "| " << setw(30) << left << "Jenis"
            << "| " << setw(12) << left << "Harga" << " |" << endl;

        cout << header << endl;

        for (int i = 0; i < jumlahData; i++) {
            cout << "| " << left << setw(4) << (dataHewan + i)->idHewan 
                << "| " << setw(25) << (dataHewan + i)->namaHewan 
                << "| " << setw(30) << (dataHewan + i)->jenisHewan 
                << "| Rp" << setw(10) << (dataHewan + i)->hargaHewan << " |" << endl;
        }
        cout << header << endl;
        jeda();
    }
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

int partition(int low, int high) {
    int pivot = dataHewan[high].idHewan;
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (dataHewan[j].idHewan < pivot) {
            i++;
            tukar(&dataHewan[i], &dataHewan[j]);
        }
    }
    tukar(&dataHewan[i + 1], &dataHewan[high]);
    return (i + 1);
}

void quickSortId(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);

        quickSortId(low, pi - 1);
        quickSortId(pi + 1, high);
    }
}

void tampilkanPesan() {
    cout << "\n(+) Data Berhasil Diurutkan Berdasarkan ID" << endl;
    cout << "(+) Silahkan Cek Di Pilihan Nomor 2" << endl;
    jeda();
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
    cout << endl;

    bool ada = false;
    int iterasi = 0;
    
    for (int i = 0; i < jumlahData; i++) {
        cout << "Iterasi " << iterasi + 1 << ": Dengan Indeks Ke-" << i << " Adalah " << (dataHewan + i)->namaHewan << endl; 
        if (target == (dataHewan + i)->namaHewan) {
            cout << "\n(+) Data Ditemukan!" << endl;
            cout << "\nID Hewan    : " << (dataHewan + i)->idHewan << endl;
            cout << "Nama Hewan  : " << (dataHewan + i)->namaHewan << endl;
            cout << "Jenis Hewan : " << (dataHewan + i)->jenisHewan << endl;
            cout << "Harga Hewan : Rp" << (dataHewan + i)->hargaHewan << endl;
            ada = true;
            break;
        }
        iterasi++;
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
    
    quickSortId(0, jumlahData - 1);

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

void buatTabelBadChar(string& pattern, int m, int tabel[]) {
    for (int i = 0; i < ALFABET; i++)
        tabel[i] = -1;
    
    for (int i = 0; i < m; i++)
        tabel[(int)pattern[i]] = i;
}

void boyerMoore() {
    string target;
    cout << "\nCari Jenis Hewan: ";
    cin.ignore();
    getline(cin, target);

    int ditemukan = 0;

    for (int i = 0; i < jumlahData; i++) {
        string text = (dataHewan + i)->jenisHewan;

        int n = (int)text.size();
        int m = (int)target.size();
        
        int badChar[ALFABET];
        buatTabelBadChar(target, m, badChar);
        
        int s = 0; 
        bool ada = false;
        
        while(s <= n - m) {
            int j = m - 1; 
            
            while(j >= 0 && target[j] == text[s + j])
                j--;
            
            if(j < 0) { 
                ada = true;
                if(s + m < n)
                    s += m - badChar[(int)text[s + m]];
                else
                    s++;
                break; 
            } else {
                int geser = j - badChar[(int)text[s + j]];
                if(geser < 1) geser = 1;
                s += geser;
            }
        }
        
        if (ada) {
            cout << "(+) Data Ditemukan" << endl;
            cout << "\nID Hewan    : " << (dataHewan + i)->idHewan << endl;
            cout << "Nama Hewan  : " << (dataHewan + i)->namaHewan << endl;
            cout << "Jenis Hewan : " << (dataHewan + i)->jenisHewan << endl;
            cout << "Harga Hewan : Rp" << (dataHewan + i)->hargaHewan << endl;
            ditemukan++;
        }  
    }

    cout << "\n========================================" << endl;
    cout << "Total Data Ditemukan: " << ditemukan << endl;
    if (ditemukan == 0) {
        cout << "(-) Tidak Ada Data Yang Cocok!" << endl;
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
        cout << "|  [5]. Cari Jenis Hewan               |" << endl;
        cout << "|  [6]. Urutkan Data Hewan (ID)        |" << endl;
        cout << "|  [7]. Urutkan Data Hewan (Nama)      |" << endl;
        cout << "|  [8]. Urutkan Data Hewan (Harga)     |" << endl;
        cout << "|  [9]. Keluar                         |" << endl;
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
            boyerMoore();
        } else if (pilihan == '6') {
            quickSortId(0, jumlahData - 1);
            tampilkanPesan();
        } else if (pilihan == '7') {
            bubbleSortNama();
        } else if (pilihan == '8') {
            selectionSortHarga();
        } else if (pilihan == '9') {
            cout << "\nTerima Kasih Telah Menggunakan Program Ini!" << endl;
            cout << endl;
            break;
        } else {
            cout << "\n(!) Pilihan Tidak Valid!" << endl;
            jeda();
        }
    } while (pilihan != '9');
}

int main() {
    dataHewan[0] = {74, "beef", "chihuahua", 850000};
    dataHewan[1] = {13, "ciko", "ikan badut", 800000};
    dataHewan[2] = {22, "fluxx", "ginger cat", 650000};
    dataHewan[3] = {31, "gary", "siput laut", 600000};
    dataHewan[4] = {26, "kuma", "beruang grizly", 450000};
    dataHewan[5] = {2, "heli", "russian grayish-blue", 550000};
    dataHewan[6] = {7, "emily", "tikus", 700000};
    dataHewan[7] = {16, "dune", "japanese macaque", 750000};
    dataHewan[8] = {45, "judy", "kelinci", 500000};
    dataHewan[9] = {67, "astra", "rubah", 900000};
    jumlahData = 10;

    menuUtama();

    return 0;
}