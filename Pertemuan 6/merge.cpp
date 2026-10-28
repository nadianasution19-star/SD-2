#include <iostream>
#include <vector>
using namespace std;

// Fungsi Bergabung Kembali
// Menggabungkan dua bagian terurut: arr[left..mid] dan arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;   // ukuran bagian kiri
    int n2 = right - mid;      // ukuran bagian kanan

    // Salin data ke array sementara
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Bandingkan elemen kiri dan kanan, ambil yang lebih kecil
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen kiri (jika ada)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen kanan (jika ada)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Memecah Barisan
// Membagi array menjadi dua bagian secara rekursif, lalu menggabungkannya
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // hindari overflow

        mergeSort(arr, left, mid);       // urutkan bagian kiri
        mergeSort(arr, mid + 1, right);  // urutkan bagian kanan
        merge(arr, left, mid, right);    // gabungkan keduanya
    }
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;
   
    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
   
    cout << "Array sebelum diurutkan: ";
    printArray(data);
   
    mergeSort(data, 0, n - 1);
   
    cout << "Array setelah diurutkan: ";
    printArray(data);
   
    return 0;
}