#include <iostream>
using namespace std;

int arr[7] = {2, 3, 5, 7, 11, 13, 17};

void reverseArray(int *ptrArr, int n) {

    int *ptrAwal = arr;
    int *ptrAkhir = arr + n - 1;

    while (ptrAwal < ptrAkhir) {
        int temp = *ptrAwal;
        *ptrAwal = *ptrAkhir;
        *ptrAkhir = temp;

        ptrAwal++;
        ptrAkhir--;
    }

}

int main () {
    string judul = R"(
====================================
|                                  |
|  Soal 3 (MEMBALIK URUTAN ARRAY)  |
|                                  |
====================================)";

    system("cls");
    cout << judul << endl;
    cout << "\nArray Sebelum Dibalik: ";
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }

    reverseArray(arr, 7);
    cout << "\nArray Sesudah Dibalik: ";
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    
    return 0;
}