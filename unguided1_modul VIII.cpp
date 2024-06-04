#include <iostream>
using namespace std;
#include <conio.h>
#include <iomanip>
#include <string>

string kalimat;
char cari;

void binarysearch()
{
    //searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = kalimat.length() - 1;
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if(kalimat[tengah] == cari)
        {
            b_flag = 1;
            break;
        } 
        else if(kalimat[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah -1;
    }

    if(b_flag == 1)
        cout<<"\n Huruf ditemukan pada index ke- " << tengah << endl;
    else
        cout<<"\n Huruf tidak ditemukan\n";
}

int main()
{
    cout<<"\t BINARY SEARCH "<< endl;
    cout<<"\n Masukkan kalimat : ";
    getline(cin, kalimat);
    cout << "\n Masukkan huruf yang ingin Anda cari :";
    cin >> cari;
    cout << "\n Kalimat diurutkan : ";
    //urutkan kalimat dengan selection sort
    for(int i = 0; i < kalimat.length(); i++)
    {
        for(int j = i + 1; j < kalimat.length(); j++)
        {
            if(kalimat[j] < kalimat[i])
            {
                char temp = kalimat[i];
                kalimat[i] = kalimat[j];
                kalimat[j] = temp;
            }
        }
    }
    //tampilkan kalimat setelah diurutkan
    for(int x = 0; x < kalimat.length(); x++)
        cout << kalimat[x];
    cout << endl;
    binarysearch();
    _getche();
    return EXIT_SUCCESS;
}