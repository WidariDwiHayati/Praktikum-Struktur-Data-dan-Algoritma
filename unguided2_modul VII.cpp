#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* front = nullptr; // Penanda antrian
Node* back = nullptr; // Penanda
int maksimalQueue = 5; // Maksimal antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count == maksimalQueue;
}

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty() {
    return front == nullptr;
}

// Fungsi untuk menambahkan elemen ke antrian
void enqueueAntrian(string nama, string nim) {
    if (isFull()) {
        cout << " Antrian penuh" << endl;
    } else {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        if (front == nullptr) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }
}

//Fungsi untuk menghapus elemen dari antrian
void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            back = nullptr;
        }
    }
}

//Fungsi untuk menghitung jumlah elemen dalam antrian
int countQueue() {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

//Fungsi untuk mengosongkan semua elemen dalam antrian
void clearQueue() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
}

//Fungsi untuk menampilkan semua elemen dalam antrian
void viewQueue() {
    cout << "__________________________________________________" << endl;
    cout << "| No.| Nama Mahasiswa \t\t | NIM Mahasiswa |" << endl;
    cout << "__________________________________________________" << endl;
    Node* temp = front;
    int i = 1;
    while (temp != nullptr) {
        cout << "| " << i << ". | " << temp->nama << "\t | " << temp->nim  << "\t |" << endl;
        cout << "__________________________________________________" << endl;
        temp = temp->next;
        i++;
    }
}

int main() {
    string nama, nim;
    while(true) {
        int pilih;
        cout << "==============ANTRIAN MAHASISWA==============" << endl;
        cout << "\n1. Menambahkan data antrian mahasiswa.";
        cout << "\n2. Menghapus data antrian mahasiswa.";
        cout << "\n3. Melihat jumlah data antrian mahasiswa.";
        cout << "\n4. Menghapus seluruh data antrian mahasiswa.";
        cout << "\n5. Menampilkan data antrian mahasiswa.";
        cout << "\n6. Exit.";
        cout << "\n\nMasukkan pilihan : ";
        cin >> pilih;
        cin.ignore();
        switch (pilih)
        {
        case 1:
            cout << "Masukkan nama mahasiswa : ";
            getline(cin, nama);
            cout << "Masukkan NIM mahasiswa : ";
            getline(cin, nim);
            enqueueAntrian(nama, nim);
            cout << endl;
            break;
        case 2:
            dequeueAntrian();
            cout << endl;
            break;
        case 3:
            cout << "Jumlah antrian = " << countQueue() << endl;
            break;
        case 4:
            clearQueue();
            cout << endl;
            break;
        case 5:
            viewQueue();
            cout << endl;
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "Pilihan Anda tidak valid";
            break;
        }

    }

    return 0;
}