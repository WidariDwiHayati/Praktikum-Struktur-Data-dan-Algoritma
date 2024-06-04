#include <iostream>
#include <map>
using namespace std;

int main()
{
    map <int, string> mahasiswa;

    mahasiswa.insert(make_pair(1, "Joko"));
    mahasiswa.insert(make_pair(2, "Budi"));
    mahasiswa.insert(make_pair(3, "Heri"));

    cout << "Nama Mahasiswa" << endl;
    cout << "==============" << endl;

    for (map <int, string>::iterator it = mahasiswa.begin(); it != mahasiswa.end(); ++it)
    {
        cout << it->first << ". " << it->second << endl;
    }

    return 0;
}