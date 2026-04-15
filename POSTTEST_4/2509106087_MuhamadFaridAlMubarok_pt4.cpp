#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

struct Hewan {
    int idHewan;
    string namaHewan;
    string jenisHewan;
    int hargaHewan;
};

#define MAKS_DATA 50
int jumlahData = 0;
Hewan dataHewan[MAKS_DATA];
int nomorAntrianGlobal = 0;

struct Node {
    int indexHewan;
    Node* next;
};

Node* frontQueue = nullptr;
Node* rearQueue = nullptr;

Node* topStack = nullptr;

void tukarDataHewan(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void jeda() {
    cout << "\n[Tekan Enter Untuk Melanjutkan...]" << endl;
    getch();
}

bool isEmptyQueue() {
    return frontQueue == nullptr;
}

void enqueue(int indexHewan) {
    Node* newNode = new Node();
    newNode->indexHewan = indexHewan;
    newNode->next = nullptr;

    if (isEmptyQueue()) {
        frontQueue = newNode;
        rearQueue = newNode;
    } else {
        rearQueue->next = newNode;
        rearQueue = newNode;
    }
    
    cout << dataHewan[indexHewan].namaHewan << " berhasil masuk antrian." << endl;
}

int dequeue() {
    if (isEmptyQueue()) {
        cout << "Antrian Kosong! (Underflow)" << endl;
        return -1;
    }

    Node* temp = frontQueue;
    int indexHewan = temp->indexHewan;

    frontQueue = frontQueue->next;

    if (frontQueue == nullptr) {
        rearQueue = nullptr;
    }

    delete temp;
    
    cout << "\n--- Memanggil Pasien ---" << endl;
    cout << "ID   : " << dataHewan[indexHewan].idHewan << endl;
    cout << "Nama : " << dataHewan[indexHewan].namaHewan << endl;
    cout << "------------------------" << endl;

    pushRiwayat(indexHewan);

    return indexHewan;
}

void peekQueue() {
    if (isEmptyQueue()) {
        cout << "Antrian Kosong." << endl;
        return;
    }
    int idx = frontQueue->indexHewan;
    cout << "\nPasien Terdepan (Peek Queue):" << endl;
    cout << "Nama: " << dataHewan[idx].namaHewan << " (ID: " << dataHewan[idx].idHewan << ")" << endl;
}

void tampilAntrian() {
    if (isEmptyQueue()) {
        cout << "Antrian Kosong." << endl;
        return;
    }

    cout << "\n--- Daftar Antrian ---" << endl;
    Node* current = frontQueue;
    int no = 1;
    while (current != nullptr) {
        int idx = current->indexHewan;
        cout << no << ". " << dataHewan[idx].namaHewan << " (ID: " << dataHewan[idx].idHewan << ")" << endl;
        current = current->next;
        no++;
    }
    cout << "--------------------" << endl;
}

bool isEmptyStack() {
    return topStack == nullptr;
}

void pushRiwayat(int indexHewan) {
    Node* newNode = new Node();
    newNode->indexHewan = indexHewan;
    newNode->next = topStack;
    topStack = newNode;
}

int popRiwayat() {
    if (isEmptyStack()) {
        cout << "Riwayat Kosong! (Underflow)" << endl;
        return -1;
    }

    Node* temp = topStack;
    int indexHewan = temp->indexHewan;

    topStack = topStack->next;

    delete temp;

    cout << "\n--- Membatalkan Tindakan Terakhir ---" << endl;
    cout << "Hewan: " << dataHewan[indexHewan].namaHewan << " (ID: " << dataHewan[indexHewan].idHewan << ")" << endl;
    cout << "Status: Dihapus dari riwayat." << endl;
    cout << "-------------------------------------" << endl;

    return indexHewan;
}

void peekStack() {
    if (isEmptyStack()) {
        cout << "Riwayat Kosong." << endl;
        return;
    }
    int idx = topStack->indexHewan;
    cout << "\nTindakan Terakhir (Peek Stack):" << endl;
    cout << "Nama: " << dataHewan[idx].namaHewan << " (ID: " << dataHewan[idx].idHewan << ")" << endl;
}

void tampilRiwayat() {
    if (isEmptyStack()) {
        cout << "Riwayat Kosong." << endl;
        return;
    }

    cout << "\n--- Riwayat Tindakan ---" << endl;
    Node* current = topStack;
    int no = 1;
    while (current != nullptr) {
        int idx = current->indexHewan;
        cout << no << ". " << dataHewan[idx].namaHewan << " (ID: " << dataHewan[idx].idHewan << ")" << endl;
        current = current->next;
        no++;
    }
    cout << "----------------------" << endl;
}

void tambahHewan() {
    if (jumlahData >= MAKS_DATA) {
        cout << "\n(!) Kapasitas Data Penuh!" << endl;
        jeda();
    } else {
        while (true) {
            bool cekId = false;
            system("cls");
            cout << "\n--- Tambah Data Hewan ---" << endl;
            
            Hewan* ptr = &dataHewan[jumlahData];
            cout << "ID Hewan: ";
            cin >> ptr->idHewan;

            for (int i = 0; i < jumlahData; i++) {
                if (ptr->idHewan == dataHewan[i].idHewan) {
                    cekId = true;
                    break;
                }
            }

            if (cekId) {
                cout << "(!) ID Sudah Ada!" << endl;
                jeda();
                continue;
            }

            cin.ignore();
            cout << "Nama Hewan: ";
            getline(cin, ptr->namaHewan);
            cout << "Jenis Hewan: ";
            getline(cin, ptr->jenisHewan);
            cout << "Harga: Rp";
            cin >> ptr->hargaHewan;

            jumlahData++;
            cout << "(+) Data Berhasil Ditambahkan" << endl;
            jeda();
            break;
        }
    }
}

void lihatData() {
    if (jumlahData == 0) {
        cout << "Belum ada data." << endl;
        jeda();
        return;
    }
    system("cls");
    cout << "\n--- Data Hewan ---" << endl;
    cout << setw(5) << "ID" << setw(15) << "Nama" << setw(20) << "Jenis" << setw(15) << "Harga" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < jumlahData; i++) {
        Hewan* p = &dataHewan[i];
        cout << setw(5) << p->idHewan 
             << setw(15) << p->namaHewan 
             << setw(20) << p->jenisHewan 
             << setw(15) << "Rp" << p->hargaHewan << endl;
    }
    jeda();
}

void sortNama() {
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = 0; j < jumlahData - i - 1; j++) {
            if (dataHewan[j].namaHewan > dataHewan[j+1].namaHewan) {
                tukarDataHewan(&dataHewan[j], &dataHewan[j+1]);
            }
        }
    }
    cout << "Data diurutkan berdasarkan Nama." << endl;
    jeda();
}

void menuUtama() {
    string pilihan;
    do {
        system("cls");
        cout << "========================================" << endl;
        cout << "|    Pawcare (Linked List Version)     |" << endl;
        cout << "========================================" << endl;
        cout << "|  [0]. Keluar                         |" << endl;
        cout << "|  [1]. Tambah Data Hewan              |" << endl;
        cout << "|  [2]. Lihat Semua Data               |" << endl;
        cout << "|  [3]. Urutkan Nama (Swap Pointer)    |" << endl;
        cout << "|--------------------------------------|" << endl;
        cout << "|  [4]. Enqueue (Masuk Antrian)        |" << endl;
        cout << "|  [5]. Dequeue (Panggil Pasien)       |" << endl;
        cout << "|  [6]. Peek Antrian                   |" << endl;
        cout << "|  [7]. Tampil Antrian                 |" << endl;
        cout << "|--------------------------------------|" << endl;
        cout << "|  [8]. Pop Riwayat (Batalkan)         |" << endl;
        cout << "|  [9]. Peek Riwayat                   |" << endl;
        cout << "|  [10]. Tampil Riwayat                |" << endl;
        cout << "========================================" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == "0") {
            cout << "Keluar..." << endl;
        } else if (pilihan == "1") {
            tambahHewan();
        } else if (pilihan == "2") {
            lihatData();
        } else if (pilihan == "3") {
            sortNama();
        } else if (pilihan == "4") {
            if (nomorAntrianGlobal >= jumlahData) {
                cout << "Semua data hewan sudah masuk antrian atau data kosong." << endl;
            } else {
                enqueue(nomorAntrianGlobal);
                nomorAntrianGlobal++;
            }
            jeda();
        } else if (pilihan == "5") {
            dequeue();
            jeda();
        } else if (pilihan == "6") {
            peekQueue();
            jeda();
        } else if (pilihan == "7") {
            tampilAntrian();
            jeda();
        } else if (pilihan == "8") {
            popRiwayat();
            jeda();
        } else if (pilihan == "9") {
            peekStack();
            jeda();
        } else if (pilihan == "10") {
            tampilRiwayat();
            jeda();
        } else {
            cout << "Pilihan tidak valid!" << endl;
            jeda();
        }
    } while (pilihan != "0");
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