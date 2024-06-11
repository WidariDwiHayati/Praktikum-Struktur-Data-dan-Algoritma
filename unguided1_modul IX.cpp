#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

vector<string> simpul;
vector<vector<int>> busur;

void tampilGraph()
{
    for (int baris = 0; baris < simpul.size(); baris++)
    {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < simpul.size(); kolom++)
        {
            if (busur[baris][kolom]!= 0)
            {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n, i, j;
    string nama_2311102060;

    cout << "Silakan masukan jumlah simpul : ";
    cin >> n;

    // Input nama simpul
    for (i = 0; i < n; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> nama_2311102060;
        simpul.push_back(nama_2311102060);
    }

    // Inisialisasi matriks bobot
    busur.resize(n, vector<int>(n, 0));

    // Input bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> busur[i][j];
        }
    }

    // Tampilkan matriks bobot
    tampilGraph();

    // Hitung jarak antar simpul
    string asal, tujuan;
    cout << "Masukkan kota asal : ";
    cin >> asal;
    cout << "Masukkan kota tujuan : ";
    cin >> tujuan;

    int origin, destination;
    for (i = 0; i < n; i++) {
        if (simpul[i] == asal) {
            origin = i;
            break;
        }
    }
    for (i = 0; i < n; i++) {
        if (simpul[i] == tujuan) {
            destination = i;
            break;
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (busur[i][k] + busur[k][j] < busur[i][j]) {
                    busur[i][j] = busur[i][k] + busur[k][j];
                }
            }
        }
    }

    // Tampilkan jarak
    cout << "Jarak dari " << asal << " ke " << tujuan << " : " << busur[origin][destination] << endl;

    return 0;
}