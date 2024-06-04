#include <iostream>
using namespace std;
int main()
{
    char y;
    float nilai, sum = 0;
    int maks, min,  a, i = 1, pilih, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    cout << endl;
    cout << "1. Nilai Maksimum";
    cout << "\n2. Nilai Minimum";
    cout << "\n3. Nilai Rata-Rata";
    cout << "\nMasukkan pilihan : ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        maks = array[0];
        for (i = 0; i < a; i++)
        {
            if (array[i] > maks)
            {
                maks = array[i];
                lokasi = i;
            }
        }
        cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
        break;
    case 2:
        min = array[0];
        for (i = 0; i < a; i++)
        {
            if (array[i] < min)
            {
                min = array[i];
                lokasi = i;
            }
        }
        cout << "Nilai minimum adalah " << min << " berada di Array ke " << lokasi << endl;
        break;
    case 3:
        for (int i = 0; i < array[i]; i++) {
            sum += array[i];
        }
        nilai = sum/a;
        cout << "Nilai rata-rata adalah " << nilai << endl;
        break;
    
    default: cout << "Pilihan tidak valid";
        break;
    }
    cout << "\nIngin mengulangi operasi? (y/n) :";
    cin >> y;
    
    do
    {
        cout << endl;
        cout << "1. Nilai Maksimum";
        cout << "\n2. Nilai Minimum";
        cout << "\n3. Nilai Rata-Rata";
        cout << "\nMasukkan pilihan : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            maks = array[0];
            for (i = 0; i < a; i++)
            {
                if (array[i] > maks)
                {
                    maks = array[i];
                    lokasi = i;
                }
            }
            cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
            break;
        case 2:
            min = array[0];
            for (i = 0; i < a; i++)
            {
                if (array[i] < min)
                {
                    min = array[i];
                    lokasi = i;
                }
            }
            cout << "Nilai minimum adalah " << min << " berada di Array ke " << lokasi << endl;
            break;
        case 3:
            for (int i = 0; i < array[i]; i++) {
                sum += array[i];
            }
            nilai = sum/a;
            cout << "Nilai rata-rata adalah " << nilai << endl;
            break;
        
        default: cout << "Pilihan tidak valid";
            break;
        }
        cout << "\nIngin mengulangi operasi? (y/n) :";
        cin >> y;
    } while (y == 'y');
    if (y != 'y')
    {
        cout << "Terima Kasih"; 
    }
    
}