#include <iostream> 
using namespace std;


#define MAX 5 
int stack[MAX];  // sama int stack[5]
int top = -1; // awalnya kosong


// TODO : Operasi Push 
void push (int value) {

    if(top == MAX-1){ // pengondisian kalau udah penuh
        cout << "Stack Penuh \n";
    } else{ // kalau blm penuh
        top++; // bertambah 1
        stack[top] = value; // cth : stack[0] = 50
        cout << value << " ditambhkan dalam stack\n";
    }
}
    

// TODO : Operasi Pop 

void pop (){

    if(top == -1){ // stack nya masih kosong
        cout << "Stack kosong\n";
    } else{
        cout << "\n" << stack[top] << " dihapus dari stack\n";
        top--;
    }
}


// TODO : Nampilin Stack 
void display() {

    if(top == -1){ // stack nya masih kosong
        cout << "Stack kosong\n";
     } else {
        cout << "\nIsi stack : \n";
        for(int i = top; i >= 0; i--){ // bakal nampilin sama dengan 0
            cout << stack[i] << " ";
        }
     }
}
    
    int main (){ 
        push(50); 
        push(40); 
        push(30); 
        push(20); 
        push(10);



display();
pop();
display;

return 0;
}