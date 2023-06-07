#include <iostream>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

struct Data {
    string nama;
    string nik;
    string alamat;
    int umur;
    string tgl_lahir;
};

void radix_sort(Data arr[], int n, int index) {
    int count[256] = {0};

    for (int i = 0; i < n; i++) {
        count[arr[i].tgl_lahir[index]]++;
    }

    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    Data output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i].tgl_lahir[index]] - 1] = arr[i];
        count[arr[i].tgl_lahir[index]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n = 0;
    Data arr[100];

    do {
        string nama, nik, alamat, tgl_lahir;
        int umur;
        cout << "==================== T U G A S B E B S  =================\n";
        cout << "Nama:Dayudpratam\n";
        cout << "MATKUL:ALPRO\n";
        cout << "=========================================================\n";
        cout << "MASUKAN DATA ANDA:\n";
        cout << "Nama: ";
        getline(cin, nama);

        cout << "NIK: ";
        getline(cin, nik);

        cout << "Alamat: ";
        getline(cin, alamat);

        cout << "Umur: ";
        cin >> umur;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Tanggal Lahir (dd/mm/yyyy): ";
        getline(cin, tgl_lahir);

        arr[n].nama = nama;
        arr[n].nik = nik;
        arr[n].alamat = alamat;
        arr[n].umur = umur;
        arr[n].tgl_lahir = tgl_lahir;

        n++;

        char jawaban;
        cout << "Tambahkan data lagi? (y/n): ";
        cin >> jawaban;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (jawaban == 'n') {
            break;
        }
    } while (true);

    // Sorting menggunakan Radix Sort
    for (int i = 9; i >= 0; i--) {
        radix_sort(arr, n, i);
    }

    // Menampilkan data yang sudah di-sorting
    for (int i = 0; i < n; i++) {
        cout << "Nama: " << arr[i].nama << endl;
        cout << "NIK: " << arr[i].nik << endl;
        cout << "Alamat: " << arr[i].alamat << endl;
        cout << "Umur: " << arr[i].umur << endl;
        cout << "Tanggal Lahir: " << arr[i].tgl_lahir << endl;
        cout << endl;
    }

    return 0;
}
