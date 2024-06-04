#include <iostream>
using namespace std;

int main(){
    int n = 10;
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari = 4;
    int jumlah_kemunculan = 0;

    // algoritma Sequential Search
    for (int i = 0; i < n; i++){
        if(data[i] == cari){
            jumlah_kemunculan++;
        }
    }

    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "Data: {9, 4, 1, 4, 7, 10, 5, 4, 12, 4.}" << endl;

    if (jumlah_kemunculan > 0){
        cout << "\nAngka "<< cari << " ditemukan sebanyak " << jumlah_kemunculan << " kali pada data." << endl;
    } else {
        cout << "\nAngka " << cari << " tidak dapat ditemukan pada data." << endl;
    }
    
    return 0;
}