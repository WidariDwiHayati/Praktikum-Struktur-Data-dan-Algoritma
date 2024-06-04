#include <iostream>
using namespace std;
#include <conio.h>
#include <iomanip>
#include <string>

char datas[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int cari;

void selection_sort()
{
    char temp;
    int min, i, j;
    for(i = 0; i < 26; i++)
    {
        min = i;
        for(j = i + 1; j < 26; j++)
        {
            if(datas[j] < datas[min])
            {
                min=j;
            }
        } 
        temp = datas[i];
        datas[i] = datas[min];
        datas[min] = temp;
    }
}

void binarysearch(char x)
{
    //searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 26;
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if(datas[tengah] == x)
        {
            b_flag = 1;
            break;
        } 
        else if(datas[tengah] < x)
            awal = tengah + 1;
        else
            akhir = tengah -1;
    }

    if(b_flag != 1)
        cout<<"\n Huruf tidak ditemukan\n";
}

int main()
{
    string kalimat;
    int jumlah_vokal = 0;

    cout << "\t PROGRAM MENGHITUNG JUMLAH HURUF VOKAL" << endl;
    cout << "\n Masukkan kalimat : ";
    getline(cin, kalimat);

    selection_sort();

    for(int i = 0; i < kalimat.length(); i++)
    {
        if(kalimat[i] >= 'a' && kalimat[i] <= 'z')
        {
            binarysearch(kalimat[i]);
            if(kalimat[i] == 'a' || kalimat[i] == 'i' || kalimat[i] == 'u' || kalimat[i] == 'e' || kalimat[i] == 'o')
            {
                jumlah_vokal++;
            }
        }
        else if(kalimat[i] >= 'A' && kalimat[i] <= 'Z')
        {
            binarysearch(kalimat[i] + 32);
            if(kalimat[i] == 'A' || kalimat[i] == 'I' || kalimat[i] == 'U' || kalimat[i] == 'E' || kalimat[i] == 'O')
            {
                jumlah_vokal++;
            }
        }
    }

    cout << "\n Jumlah huruf vokal pada kalimat tersebut adalah " << jumlah_vokal << endl;
    _getche();
    return EXIT_SUCCESS;
}