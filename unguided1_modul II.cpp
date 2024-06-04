#include <iostream>
using namespace std;
int main()
{
    int a, i;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    cout << "Data Array \t: ";
    for (i = 0; i < array[i]; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Nomor Genap \t: ";
    for (i = 0; i < array[i]; i++)
    {
        if (array[i] % 2 == 0)
        {
            cout << array[i] << ", ";
        }
    }
    cout << endl;
    cout << "Nomor Ganjil \t: ";
    for (i = 0; i < array[i]; i++)
    {
        if (array[i] % 2 != 0)
        {
            cout << array[i] << ", ";
        }
    }
}