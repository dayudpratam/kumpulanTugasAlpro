#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Mahasiswa {
    string nama;
    int usia;
    string jurusan;
};

bool compareUsia(const Mahasiswa& mhs1, const Mahasiswa& mhs2) {
    return mhs1.usia < mhs2.usia;
}

void tulisDataMahasiswa(const Mahasiswa& mhs, ofstream& file) {
    file << mhs.nama << endl;
    file << mhs.usia << endl;
    file << mhs.jurusan << endl;
}

void bacaDataMahasiswa(Mahasiswa& mhs, ifstream& file) {
    getline(file, mhs.nama);
    file >> mhs.usia;
    file.ignore();
    getline(file, mhs.jurusan);
}

int main() {
    ofstream fileTulis;
    ifstream fileBaca;
    ofstream fileSorting;

    // Menulis data mahasiswa ke file
    fileTulis.open("data_mahasiswa.txt");
    if (fileTulis.is_open()) {
        vector<Mahasiswa> dataMahasiswa;
        Mahasiswa mhs;

        cout << "Masukkan data mahasiswa: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Nama: ";
            getline(cin, mhs.nama);
            cout << "Usia: ";
            cin >> mhs.usia;
            cin.ignore();
            cout << "Jurusan: ";
            getline(cin, mhs.jurusan);

            dataMahasiswa.push_back(mhs);
        }

        // Menulis data mahasiswa ke file
        for (const Mahasiswa& mhs : dataMahasiswa) {
            tulisDataMahasiswa(mhs, fileTulis);
        }

        fileTulis.close();
    } else {
        cout << "Gagal membuka file untuk penulisan!" << endl;
        return 1;
    }

    // Membaca dan menyorting data mahasiswa dari file
    fileBaca.open("data_mahasiswa.txt");
    if (fileBaca.is_open()) {
        vector<Mahasiswa> dataMahasiswa;
        Mahasiswa mhs;

        while (!fileBaca.eof()) {
            bacaDataMahasiswa(mhs, fileBaca);
            dataMahasiswa.push_back(mhs);
        }

        // Sorting data mahasiswa berdasarkan usia
        sort(dataMahasiswa.begin(), dataMahasiswa.end(), compareUsia);

        cout << "Data mahasiswa setelah sorting berdasarkan usia:" << endl;
        for (const Mahasiswa& mhs : dataMahasiswa) {
            cout << "Nama: " << mhs.nama << endl;
            cout << "Usia: " << mhs.usia << endl;
            cout << "Jurusan: " << mhs.jurusan << endl;
            cout << endl;
        }

        // Menulis hasil sorting ke file
        fileSorting.open("data_mahasiswa_sorting.txt");
        if (fileSorting.is_open()) {
            for (const Mahasiswa& mhs : dataMahasiswa) {
                tulisDataMahasiswa(mhs, fileSorting);
            }
            fileSorting.close();
        } else {
            cout << "Gagal membuka file untuk penulisan hasil sorting!" << endl;
            return 1;
        }

        fileBaca.close();
    } else {
        cout << "Gagal membuka file untuk pembacaan!" << endl;
        return 1;
    }

    return 0;
}
