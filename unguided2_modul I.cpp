#include <iostream>
using namespace std;

class lampu
{
    public:
    string task;
    double jam;
};

struct
{
    string tempat;
    double watt;
}lampu1, lampu2;

int main()
{
    lampu tugas;
    tugas.task = "Ganti lampu";
    tugas.jam = 15.15;
    lampu1.tempat = "Dapur";
    lampu1.watt = 15;
    lampu2.tempat = "Ruang TV";
    lampu2.watt = 20;

    cout << tugas.task << " " <<  "di jam " << tugas.jam << endl;
    cout << lampu1.tempat << "\n" << lampu1.watt  << " watt" << endl;
    cout << lampu2.tempat << "\n" << lampu2.watt << " watt";

    return 0;
}