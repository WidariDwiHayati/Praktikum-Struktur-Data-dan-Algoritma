#include <iostream>
using namespace std;

class Node {
public:
    string nama, harga;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(string nama, string harga) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }

        head = newNode;
    }

    void push_back(string nama, string harga) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int index, string newName, string newPrice) {
        if (index < 0 || index >= getLength()) {
            cout << "Invalid index" << endl;
            return false;
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        current->nama = newName;
        current->harga = newPrice;

        return true;
    }

    void insert(int index, string nama, string harga) {
        if (index < 0 || index > getLength()) {
            return;
        }

        if (index == 0) {
            push(nama, harga);
            return;
        }

        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;

        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void remove(int index) {
        if (index < 0 || index >= getLength()) {
            return;
        }

        if (index == 0) {
            pop();
            return;
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        delete current;
    }

    int getLength() {
        Node* current = head;
        int length = 0;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
            cout << "_________________________________________________\n";
            cout << "| Nama Produk " << "\t\t| Harga " << "\t\t|\n";
            cout << "_________________________________________________\n";
        while (current != nullptr) {
            cout << "| " << current->nama << "\t\t| " << current->harga  << "\t\t|" << endl;
            current = current->next;
            cout << "_________________________________________________\n";
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.push("Originote", "60.000");
    list.push_back("Somethinc", "150.000");
    list.push_back("Skintific", "100.000");
    list.push_back("Wardah", "50.000");
    list.push_back("Hanasui", "30.000");
    list.display();
    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << " 1. Tambah Data" << endl;
        cout << " 2. Hapus Data" << endl;
        cout << " 3. Update Data" << endl;
        cout << " 4. Tambah Data Urutan Tertentu" << endl;
        cout << " 5. Hapus Data Urutan Tertentu" << endl;
        cout << " 6. Hapus Seluruh Data" << endl;
        cout << " 7. Tampilkan Data" << endl;
        cout << " 8. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        string nama, harga;

        switch (choice) {
            case 1: {
                cout << "Enter nama: ";
                cin >> nama;
                cout << "Enter harga: ";
                cin >> harga;
                list.push(nama, harga);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int index;
                string newName, newPrice;
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter new nama: ";
                cin >> newName;
                cout << "Enter new harga: ";
                cin >> newPrice;
                bool updated = list.update(index, newName, newPrice);
                if (!updated) {
                    cout << "Index not found" << endl;
                }
                break;
            }
            case 4: {
                string nama, harga;
                cout << "Enter nama: ";
                cin >> nama;
                cout << "Enter harga: ";
                cin >> harga;
                cout << "Enter index: ";
                int index;
                cin >> index;
                list.insert(index, nama, harga);
                break;
            }
            case 5: {
                cout << "Enter index: ";
                int index;
                cin >> index;
                list.remove(index);
                break;
            }
            case 6: {
                list.deleteAll();
                break;
            }
            case 7: {
                list.display();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}