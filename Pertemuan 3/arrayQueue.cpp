#include <iostream> 
using namespace std;

#define MAX 6 // sama int queue[6]
int queue[MAX]; 
int front = -1, // awalnya kosong
rear = -1;


// TODO : Enqueue
 void enqueue( int value ) { // nambah data
    if (rear == MAX - 1){
        cout << "Queue sudah penuh\n";
    } else{
        if(front == -1) front = 0; //kalau front nya masi sama dengan -1 maka dia jadi 0
        rear++; // front tetap 0 tapi rear bertambah
        queue[rear] = value; // cth : queue[0] = 1
        cout << value << " masuk ke dalam queue\n";
    }
 }


// TODO : Dequeue 
void dequeue() { // hapus data

    if (front == -1 || front > rear){ // front 0 > rear -1 berarti ksong
        cout << "Queue kosong\n";
    } else{
        cout << queue[front] << " keluar dari queue\n";
        front++; // pindah indeks ke yang satu lagi
    }
} 


// TODO : Nampilin isi queue 
void display() {
    if(front == -1 || front > rear){ // masi kosong
        cout << "Queue kosong\n";
    } else {
        cout << "Isi dari queue : ";
        for(int i = front; i <= rear; i++){ 
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}


int main () { 
    
    enqueue(1); 
    enqueue(2); 
    enqueue(3); 
    enqueue(4); 
    enqueue(5);



display();

enqueue(6);
display();

dequeue();
display();

return 0;
}