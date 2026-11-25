#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTableChaining { //bungkus fungsi
private: 
    int size; // bkln nyimpan jumlah slot/ ukuran hash tabel
    vector<list<int>> table; // utk bikin array dinamis nya

    // TODO 1: Buat hash function
    int hashFunction(int key) { 
        // return rumus hashing
        return key % size; // bagi hasil biar ada di range 0 - size-1
    }
public:
    HashTableChaining(int s) { // untuk buat hash tabel
        size = s;
        table.resize(size); // ngatur jlh slot
    }

    // TODO 2: Buat fungsi insert untuk menyimpan key ke hash table
    void insert(int key) {
        // 1. Hitung index pakai hashFunction
        int index = hashFunction(key); // masuk dari hitung index dari hash function buat nentuin bangku mana yg bakal ditempati key nya
        // 2. Tambahkan angka ke list pada index tersebut
        table[index].push_back(key); // bakaln tambahin ke list plg belakang 
    }

    /// TODO 3: Tampilkan isi hash table
    void display() { // ngecetak hash table
        for (int i = 0; i < size; i++) { // pengulangan
            cout << i << ": ";
            // tampilkan semua elemen di slot ini
            for (int val : table[i]) { // bakal ngebaca setiap elemn di dalam list
                cout << val << " -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int size, n, value;

    cout << "Masukkan ukuran hash table: ";
    cin >> size;

    HashTableChaining ht(size);

    cout << "Berapa banyak angka yang ingin dimasukkan? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Input angka ke-" << i + 1 << ": ";
        cin >> value;
        ht.insert(value);
    }

    cout << "\n=== HASH TABLE (CHAINING) ===\n";
    ht.display();

    return 0;
}