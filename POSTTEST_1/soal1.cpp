#include <iostream>
using namespace std;

int findMin(int A[], int n) {
    int indeks = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] < A[indeks]) {
            indeks = i;
        }
    }
    return indeks;
}

int main() {

    int arrayFibonacci[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;

    int minIndeks = findMin(arrayFibonacci, n);
    int minNilai = arrayFibonacci[minIndeks];

    system("cls");

    cout << "Array Fibonacci: ";
    for (int i = 0; i < n; i++) {
        cout << arrayFibonacci[i] << " ";
    }
    cout << endl;

    cout << "\nNilai Minimum: " << minNilai << endl;
    cout << "Indeks Minimum: " << minIndeks << endl;
    cout << '\n';

    return 0;
}

/*
ANALISIS KOMPLEKSITAS: Analisis Algoritma

procedure FindMin(A : array of n elements)
* min ← A[0]
* for i ← 1 to n - 1 do
*   if A[i] < min then
*     min ← A[i]
*   end if
* end for
* return min
end procedure

==============================================
|      Pseudocode       | Cost | Tmin | Tmax |
==============================================
| procedure FindMin     |  C1  |   1  |   1  |
| min <- A[o]           |  C2  |   1  |   1  |
| for i <- to n - 1     |  C3  |   n  |   n  |
| if A[i] < min         |  C4  |  n-1 |  n-1 |
| min <- A[i]           |  C5  |   0  |  n-1 |
| end if                |  C6  |  n-1 |  n-1 |
| end for               |  C7  |   n  |   n  |
| return min            |  C8  |   1  |   1  |
| end procedure         |  C9  |   1  |   1  |
==============================================

Best Case :

Tmin(n) = C1 + C2 + C3n + C4(n-1 ) + 0 + C6(n-1) + C7n + C8 + C9
    C4(n-1) => C4n - C4;  C6(n-1) => C6n - C6
*     Maka T(n) = C1 + C2 + C3n + C4n - C4 + 0 + C6n - C6 + C7n + C8 + C9
                = (C3 + C4 + C6 + C7)n + (C1 + C2 + C8 + C9 - C4 - C6)
                = (1+1+1+1)n + (1+1+1+1-1-1)
                = 4n + 2, yang mana membentuk fungsi linear. 
 *                Karena fungsi linear maka Big-O => O(n)

Worst case :
Tmax(n) = C1 + C2 + C3n + C4(n-1) + C5(n-1) + C6(n-1) + C7n + C8 + C9
    C4(n-1) => C4n - C4;  C5(n-1) => C5n - C5;  C6(n-1) => C6n - C6
 *    Maka T(n) = C1 + C2 + C3n + C4n - C4 + C5n - C5 + C6n - C6 + C7n + C8 + C9
                = (C3 + C4 + C5 + C6 + C7)n + (C1 + C2 + C8 + C9 - C4 - C5 - C6)
                = (1+1+1+1+1)n + (1+1+1+1-1-1-1)
                = 5n + 1, sama-sama membentuk fungsi linear, maka Big-O => O(n)

Kesimpulan : Best dan Worst Case sama sama fungsi linear, maka Big-O => O(n).
 */