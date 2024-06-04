#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node *next;
};

Node *head;
Node *tail;

void init() {
    head = NULL;
    tail = NULL;
}

bool isEmpty() {
    return head == NULL;
}

void insertDepan(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

void insertTengah(string nama, string nim, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->nama = nama;
        baru->nim = nim;
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void hapusDepan() {
    if (!isEmpty()) {
        string namaLama = head->nama;
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
        cout << "Data (" << namaLama << ") berhasil dihapus" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
    cout << endl;
}

void hapusBelakang() {
    if (!isEmpty()) {
        string namaLama = tail->nama;
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
        cout << "Data (" << namaLama << ") berhasil dihapus" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
    cout << endl;
}

void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *bantu = head;
        Node *hapus;
        Node *sebelum = NULL;
        int nomor = 1;
        while (nomor < posisi) {
            sebelum = bantu;
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu;
        if (sebelum != NULL) {
            sebelum->next = bantu->next;
        } else {
            head = bantu->next;
        }
        string namaLama = bantu->nama;
        delete hapus;
        cout << "Data (" << namaLama << ") berhasil dihapus" << endl;
    }
    cout << endl;
}

void ubahDepan(string nama, string nim) {
    if (!isEmpty()) {
        string namaLama = head->nama;
        head->nama = nama;
        head->nim = nim;
        cout << "\nData (" << namaLama << ") telah diganti dengan data (" << head->nama << ")" << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
    cout << endl;
}

void ubahTengah(string nama, string nim, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            int nomor = 1;
            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }
            string namaLama = bantu->nama;
            bantu->nama = nama;
            bantu->nim = nim;
            cout << "\nData (" << namaLama << ") telah diganti dengan data (" << bantu->nama << ")" << endl;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
    cout << endl;
}

void ubahBelakang(string nama, string nim) {
    if (!isEmpty()) {
        string namaLama = tail->nama;
        tail->nama = nama;
        tail->nim = nim;
        cout << "\nData (" << namaLama << ") telah diganti dengan data (" << tail->nama << ")" << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
    cout << endl;
}


void clearList() {
    Node *bantu = head;
    Node *hapus;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

void tampil() {
    Node *bantu = head;
    cout << "___________________________\n";
    cout <<"| " << setw(10) << "Nama " << " | " << setw(10) << "NIM " << " |\n";
     cout << "___________________________\n";
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << "| " << setw(10) << bantu->nama << " | " << setw(10) << bantu->nim << " |" << endl;
            bantu = bantu->next;
             cout << "___________________________\n";
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    string nama, nim;
    int posisi;
    insertDepan("Jawad", "23300001");
    cout << "Masukkan Nama : ";
    cin >> nama;
    cout << "Masukkan NIM : ";
    cin >> nim;
    insertBelakang(nama, nim);
    insertBelakang("Farrel", "23300003");
    insertBelakang("Denis", "23300005");
    insertBelakang("Anis", "23300008");
    insertBelakang("Gahar", "23300040");
    insertBelakang("Udin", "23300048");
    insertBelakang("Ucok", "23300050");
    insertBelakang("Budi", "23300099");
    insertTengah("Bowo", "23300015", 6);
    tampil();
    int pilih;
    cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
    cout << "\n1. Tambah Depan";
    cout << "\n2. Tambah Belakang";
    cout << "\n3. Tambah Tengah";
    cout << "\n4. Ubah Depan";
    cout << "\n5. Ubah Belakang";
    cout << "\n6. Ubah Tengah";
    cout << "\n7. Hapus Depan";
    cout << "\n8. Hapus Belakang";
    cout << "\n9. Hapus Tengah";
    cout << "\n10. Hapus List";
    cout << "\n11. TAMPILKAN";
    cout << "\n0. KELUAR" << endl;
    cout << "\nPilih Operasi : ";
    cin >> pilih;
    switch (pilih)
    {
        case 1:
            cout << "==Tambah Depan==" << endl;
            cout << "\nMasukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            insertDepan(nama, nim);
            cout << "\nData telah ditambahkan\n" << endl;
            break;
        case 2:
            cout << "==Tambah Belakang==" << endl;
            cout << "\nMasukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            insertBelakang(nama, nim);
            cout << "\nData telah ditambahkan\n" << endl;
            break;
        case 3:
            cout << "==Tambah Tengah==" << endl;
            cout << "\nMasukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> posisi;
            insertTengah(nama, nim, posisi);
            cout << "\nData telah ditambahkan\n" << endl;
            break;
        case 4:
            cout << "==Ubah Depan==" << endl;
            cout << "\nMasukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            ubahDepan(nama, nim);
            break;
        case 5:
            cout << "==Ubah Belakang==" << endl;
            cout << "\nMasukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            ubahBelakang(nama, nim);
            break;
        case 6:
            cout << "==Ubah Tengah==" << endl;
            cout << "\nMasukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            cout << "Masukkan posisi : ";
            cin >> posisi;
            ubahTengah(nama, nim, posisi);
            break;
        case 7:
            cout << "==Hapus Depan==" << endl;
            hapusDepan();
            break;
        case 8:
            cout << "==Hapus Belakang==" << endl;
            hapusBelakang();
            break;
        case 9:
            cout << "==Hapus Tengah==" << endl;
            cout << "\nMasukkan posisi : ";
            cin >> posisi;
            hapusTengah(posisi);
            break;
        case 10:
            cout << "==Hapus List==" << endl;
            clearList();
            cout << "Semua data berhasil dihapus" << endl;
            break;
        case 11:
            tampil();
            break;
        case 0:
            return 0;
            break;
        default:
            cout << "Pilihan Tidak Valid" << endl;
            break;
    }

    while (pilih != 0)
    {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "\n1. Tambah Depan";
        cout << "\n2. Tambah Belakang";
        cout << "\n3. Tambah Tengah";
        cout << "\n4. Ubah Depan";
        cout << "\n5. Ubah Belakang";
        cout << "\n6. Ubah Tengah";
        cout << "\n7. Hapus Depan";
        cout << "\n8. Hapus Belakang";
        cout << "\n9. Hapus Tengah";
        cout << "\n10. Hapus List";
        cout << "\n11. TAMPILKAN";
        cout << "\n0. KELUAR" << endl;
        cout << "\nPilih Operasi : ";
        cin >> pilih;
        switch (pilih)
        {
            case 1:
                cout << "==Tambah Depan==" << endl;
                cout << "\nMasukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                insertDepan(nama, nim);
                cout << "\nData telah ditambahkan" << endl;
                break;
            case 2:
                cout << "==Tambah Belakang==" << endl;
                cout << "\nMasukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                insertBelakang(nama, nim);
                cout << "\nData telah ditambahkan" << endl;
                break;
            case 3:
                cout << "==Tambah Tengah==" << endl;
                cout << "\nMasukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                insertTengah(nama, nim, posisi);
                cout << "\nData telah ditambahkan" << endl;
                break;
            case 4:
                cout << "==Ubah Depan==" << endl;
                cout << "\nMasukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahDepan(nama, nim);
                break;
            case 5:
                cout << "==Ubah Belakang==" << endl;
                cout << "\nMasukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahBelakang(nama, nim);
                break;
            case 6:
                cout << "==Ubah Tengah==" << endl;
                cout << "\nMasukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan posisi : ";
                cin >> posisi;
                ubahTengah(nama, nim, posisi);
                break;
            case 7:
                cout << "==Hapus Depan==" << endl;
                hapusDepan();
                break;
            case 8:
                cout << "==Hapus Belakang==" << endl;
                hapusBelakang();
                break;
            case 9:
                cout << "==Hapus Tengah==" << endl;
                cout << "\nMasukkan posisi : ";
                cin >> posisi;
                hapusTengah(posisi);
                break;
            case 10:
                cout << "==Hapus List==" << endl;
                clearList();
                cout << "Semua data berhasil dihapus" << endl;
                break;
            case 11:
                tampil();
                break;
            case 0:
                return 0;
                break;
            default:
                cout << "Pilihan Tidak Valid" << endl;
                break;
        }

    }
    return 0;
}