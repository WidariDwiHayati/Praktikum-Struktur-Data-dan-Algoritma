#include <iostream>
using namespace std;

const int maksimal = 100;
string stackKalimat[maksimal];
int top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void push (string data) {
    if (isFull()) {
        cout << "Stack telah penuh" << endl;
    } else {
        stackKalimat[top] = data;
        top++;
    }
}

void pop () {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        top--;
    }
}

bool isPalindrome(string s) {
    for (int i = 0; i < s.length(); i++) {
        push(string(1, s[i]));
    }
    for (int i = 0; i < s.length(); i++) {
        if (stackKalimat[top - 1] != string(1, s[i])) {
            return false;
        }
        pop();
    }
    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom" << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom" << endl;
    }

    return 0;
}