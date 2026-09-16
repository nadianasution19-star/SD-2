#include <iostream>
using namespace std;

// Deklarasi struktur node
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Tambah node di awal
void insertFirst(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Tambah node di akhir
void insertLast(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Tambah node setelah node dengan nilai tertentu
void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "List kosong, silakan tambah node dulu.\n";
        return;
    }

    Node *p = head;
    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << " tidak ditemukan.\n";
        return;
    }

    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = p->next;
    p->next = newNode;

    if (p == tail) {
        tail = newNode;
    }
}

// Hapus node berdasarkan nilai (bisa di awal, tengah, atau akhir)
void deleteByValue(int value) {
    if (head == NULL) {
        cout << "List kosong, tidak ada yang bisa dihapus.\n";
        return;
    }

    // Kasus node yang dihapus ada di awal (head)
    if (head->value == value) {
        Node *temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
        return;
    }

    // Cari node sebelum node yang akan dihapus
    Node *p = head;
    while (p->next != NULL && p->next->value != value) {
        p = p->next;
    }

    if (p->next == NULL) {
        cout << "Node dengan nilai " << value << " tidak ditemukan.\n";
        return;
    }

    Node *temp = p->next;
    p->next = temp->next;
    if (temp == tail) {
        tail = p;
    }
    delete temp;
}

// Cetak isi linked list dari head sampai tail
void printList() {
    Node *temp = head;
    cout << "Isi Linked List: ";
    if (temp == NULL) {
        cout << "NULL\n";
        return;
    }
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int pilihan;

    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int nilai;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertFirst(nilai);
                printList();
                break;
            }
            case 2: {
                int nilai;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertLast(nilai);
                printList();
                break;
            }
            case 3: {
                int nilaiBaru, nilaiCari;
                cout << "Masukkan nilai baru: ";
                cin >> nilaiBaru;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilaiCari;
                insertAfter(nilaiBaru, nilaiCari);
                printList();
                break;
            }
            case 4: {
                int nilaiHapus;
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilaiHapus;
                deleteByValue(nilaiHapus);
                printList();
                break;
            }
            case 5:
                printList();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}