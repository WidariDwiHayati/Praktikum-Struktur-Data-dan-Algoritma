#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int TABLE_SIZE = 11;
string nim;
int nilai;
class HashNode
{
public:
    string nim;
    int nilai;
    HashNode(string nim, int nilai)
    {
        this->nim = nim;
        this->nilai = nilai;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string nim, int nilai)
    {
        int hash_val = hashFunc(nim);
        for (auto node : table[hash_val])
        {
            if (node->nim == nim)
            {
                node->nilai = nilai;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(nim, nilai));
    }
    void remove(string nim)
    {
        int hash_val = hashFunc(nim);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->nim == nim)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    int searchByNIM(string nim)
    {
        int hash_val = hashFunc(nim);
        for (auto node : table[hash_val])
        {
            if (node->nim == nim)
            {
                return node->nilai;
            }
        }
        return -1; // return -1 if NIM is not found
    }
    void searchByNilai(int nilaiMin, int nilaiMax)
    {
        bool found = false;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            for (auto pair : table[i])
            {
                if (pair != nullptr && pair->nilai >= nilaiMin && pair->nilai <= nilaiMax)
                {
                    cout << pair->nim << " memiliki nilai " << pair->nilai << endl;
                    found = true;
                }
            }
        }
        if (!found)
        {
            cout << "Tidak ada mahasiswa yang memiliki nilai antara " << nilaiMin << " and " << nilaiMax << endl;
        }
    }
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->nim << ", " << pair->nilai << "]";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap data;
    string NIM;
    int nilai_mhs;
    while (true)
    {
        int menu;
        cout << "\nMenu" << endl;
        cout << "1. Tambah data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Mencari data berdasarkan NIM" << endl;
        cout << "4. Mencari data berdasarkan nilai" << endl;
        cout << "5. Cetak data" << endl;
        cout << "6. Exit" << endl;
        cout << "Masukkkan pilihan : ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "Masukkan NIM : ";
            cin >> NIM;
            cout << "Masukkan nilai : ";
            cin >> nilai_mhs;
            data.insert(NIM, nilai_mhs);
            break;
        case 2:
            cout << "Masukkan NIM yang akan dihapus : ";
            cin >> NIM;
            data.remove(NIM);
            cout << "Data berhasil dihapus" << endl;
            break;
        case 3:
            cout << "Masukkan NIM yang akan dicari : ";
            cin >> NIM;
            cout << "NIM " << NIM << " memiliki nilai " << data.searchByNIM(NIM) << endl;
            break;
        case 4:
            int x, z;
            cout << "Masukkan rentang nilai min : ";
            cin >> x;
            cout << "Masukkan rentang nilai max : ";
            cin >> z;
            data.searchByNilai(x, z);
            break;
        case 5:
            data.print();
            break;
        case 6:
            return 0;
        default:
            cout << "Menu tidak tersedia!" << endl;
            break;
        }
    }
return 0;
}