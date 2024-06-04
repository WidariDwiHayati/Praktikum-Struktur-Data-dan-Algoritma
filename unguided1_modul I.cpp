#include <iostream>
using namespace std;

int sisi, pilih;
float alas, tinggi, jari2;
char huruf;

int main()
{
    do
    {
        cout << "\n1. Menghitung Luas Persegi";
        cout << "\n2. Menghitung Luas Segitiga";
        cout << "\n3. Menghitung Luas Lingkaran";
        cout << "\nMasukkan pilihan (1,2,3): ";
        cin >> pilih;
        switch (pilih)
        {
            case 1:
                cout << "\nLuas Persegi" << endl;
                cout << "============" << endl;
                cout << "Masukkan sisi persegi: ";
                cin >> sisi;
                cout << "Luas Persegi: " << sisi*sisi << endl;
                cout << endl;
                break;
            case 2:
                cout << "\nLuas Segitiga" << endl;
                cout << "=============" << endl;
                cout << "Masukkan alas segitiga: ";
                cin >> alas;
                cout << "Masukkan tinggi segitiga: ";
                cin >> tinggi;
                cout << "Luas segitiga: " << alas*tinggi/2 << endl;
                cout << endl;
                break;
            case 3:
                cout << "\nLuas Lingkaran" << endl;
                cout << "==============" << endl;
                cout << "Masukkan jari-jari lingkaran: ";
                cin >> jari2;
                cout << "Luas lingkaran: " << 3.14*jari2*jari2 << endl;
                cout << endl;
                break;
            default:
                cout << "pilihan tidak valid";
        }
        cout << "Apakah Anda ingin mengulangi operasi (y,n): ";
        cin >> huruf;
    } while (huruf == 'y');
    
    if (huruf != 'y')
        {
            cout << "Terima Kasih";
        }
    
    return 0;
}