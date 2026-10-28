#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // TODO : Algoritma Bubble Sort dari terkecil hingga terbesar
    for(int i = 0; i < n - 1; i++){ // untuk iterasi
        for(int j = 0; j < n - 1; j++){ // kayak batas nya
            if(data[j] > data[j + 1]){
                int temp = data[j]; // tempat sementara utk bertukar
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}