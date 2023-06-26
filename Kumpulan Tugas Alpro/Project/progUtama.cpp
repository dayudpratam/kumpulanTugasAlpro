
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include"header.h"
using namespace std;


int main() {
    vector<Buku> daftarBuku;
    int pilihan;

    while (true) {
        cout << "Menu Utama" << endl;
        cout << "1. Menu Penjual" << endl;
        cout << "2. Menu Pembeli" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tampilkanMenuPenjual(daftarBuku);
        }
        else if (pilihan == 2) {
            tampilkanMenuPembeli(daftarBuku);
        }
        else if (pilihan == 3) {
            break;
        }
        else {
            cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
