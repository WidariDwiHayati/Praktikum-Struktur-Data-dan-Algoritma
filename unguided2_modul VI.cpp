#include <iostream>
#include <string>
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

string atas() {
    if (isEmpty()) {
        cout << "Stack kosong" << endl;
        return "";
    } else {
        return stackKalimat[top-1];
    }
}

string reverseLetters(string input) {
    for (int i = 0; i < input.length(); i++) {
        string temp(1, input[i]);
        push(temp);
    }

    string output = " ";
    while (!isEmpty()) {
        output += atas();
        pop();
    }

    return output;
}

string reverseWords(string input) {
    string word = "";
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            push(reverseLetters(word));
            word = "";
        } else {
            word += input[i];
        }
    }
    push(reverseLetters(word));

    string output = "";
    while (!isEmpty()) {
        output += atas();
        pop();
        if (!isEmpty()) {
            output += ' ';
        }
    }

    return output;
}

int main() {
    string input;
    cout << "Masukkan kalimat : ";
    getline(cin, input);

    string result = reverseWords(input);

    cout << "Hasil :" << result << endl;

    return 0;
}