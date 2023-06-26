#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

class Buku {
private:
    string judul;
    string pengarang;
    double harga;

public:
    Buku() {
        judul = "";
        pengarang = "";
        harga = 0.0;
    }

    Buku(string jdl, string pgr, double hrg) {
        judul = jdl;
        pengarang = pgr;
        harga = hrg;
    }

    string getJudul() {
        return judul;
    }

    string getPengarang() {
        return pengarang;
    }

    double getHarga() {
        return harga;
    }
};

void tampilkanMenuPenjual(vector<Buku>& daftarBuku) {
    //kamus lokal
    int pilihan;
    char pilihanLagi;
    int nomor;
    //algorimat
    while (true) {
        cout << "\n======================================================" << endl;
        cout << "\n================ Menu Penjual ========================" << endl;
        cout << "== 1. Tambah Buku yang ingin dijual                  =" << endl;
        cout << "== 2. Edit data buku                                 =" << endl;
        cout << "== 3. Hapus buku                                     =" << endl;
        cout << "== 4. Tampilkan data buku                            =" << endl;
        cout << "== 5. Kembali ke menu awal                           =" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "\n======================================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string judul, pengarang;
            double harga;
            pilihanLagi='y';
        while(pilihanLagi=='y'){
            cout << "\nMasukkan judul buku: ";
            cin.ignore();
            getline(cin, judul);

            cout << "Masukkan nama pengarang: ";
            getline(cin, pengarang);

            cout << "Masukkan harga buku: ";
            cin >> harga;

            daftarBuku.push_back(Buku(judul, pengarang, harga));


            cout << "Apakah ingin menambah buku lagi? (Y/N): ";
            cin >> pilihanLagi;


                }
        }
        else if (pilihan == 2) {
            cout << "\nMasukkan nomor buku yang ingin diedit: ";
            cin >> nomor;

            if (nomor >= 1 && nomor <= daftarBuku.size()) {
                string judul, pengarang;
                double harga;

                cout << "Masukkan judul buku: ";
                cin.ignore();
                getline(cin, judul);

                cout << "Masukkan nama pengarang: ";
                getline(cin, pengarang);

                cout << "Masukkan harga buku: ";
                cin >> harga;

                daftarBuku[nomor - 1] = Buku(judul, pengarang, harga);
                cout << "Data buku berhasil diubah." << endl;
            }
            else {
                cout << "Nomor buku tidak valid." << endl;
            }
        }
        else if (pilihan == 3) {
            cout << "\nMasukkan nomor buku yang ingin dihapus: ";
            cin >> nomor;

            if (nomor >= 1 && nomor <= daftarBuku.size()) {
                daftarBuku.erase(daftarBuku.begin() + nomor - 1);
                cout << "Buku berhasil dihapus." << endl;
            }
            else {
                cout << "Nomor buku tidak valid." << endl;
            }
        }
        else if (pilihan == 4) {
            if (daftarBuku.empty()) {
                cout << "Tidak ada buku yang tersedia." << endl;
            }
            else {
                cout << "\nDaftar buku yang tersedia:" << endl;
                for (int i = 0; i < daftarBuku.size(); i++) {
                    cout << "\nNomor: " << i + 1 << endl;
                    cout << "\nJudul: " << daftarBuku[i].getJudul() << endl;
                    cout << "Pengarang: " << daftarBuku[i].getPengarang() << endl;
                    cout << "Harga: Rp." << daftarBuku[i].getHarga() << endl;
                    cout << endl;
                }
            }
        }
        else if (pilihan == 5) {
            break;
        }
        else {
            cout << "Pilihan tidak valid." << endl;
        }
    }
}

void tampilkanMenuPembeli(vector<Buku>& daftarBuku) {
    vector<int> bukuDibeli;
    vector<int> jumlahBuku;
    int pilihan;
    int nomor, jumlah;
    while (true) {
        cout << "\nMenu Pembeli" << endl;
        cout << "1. Tampilkan buku yang tersedia" << endl;
        cout << "2. Beli buku" << endl;
        cout << "3. Cari Buku " << endl;
        cout << "4. Kembali ke menu awal" << endl;
        cout << "Pilih menu: ";


        cin >> pilihan;

        if (pilihan == 1) {
            if (daftarBuku.empty()) {
                cout << "Tidak ada buku yang tersedia." << endl;
            }
            else {
                cout << "\nDaftar buku yang tersedia:" << endl;
                for (int i = 0; i < daftarBuku.size(); i++) {
                    cout << "Nomor: " << i + 1 << endl;
                    cout << "Judul: " << daftarBuku[i].getJudul() << endl;
                    cout << "Pengarang: " << daftarBuku[i].getPengarang() << endl;
                    cout << "Harga: $" << daftarBuku[i].getHarga() << endl;
                    cout << endl;
                }
            }

        }
        else if (pilihan == 2) {
            if (daftarBuku.empty()) {
                cout << "Tidak ada buku yang tersedia." << endl;
                continue;
            }


            cout << "\nMasukkan nomor buku yang ingin dibeli: ";
            cin >> nomor;

            if (nomor >= 1 && nomor <= daftarBuku.size()) {
                cout << "Masukkan jumlah buku yang ingin dibeli: ";
                cin >> jumlah;

                if (jumlah >= 1) {
                    bukuDibeli.push_back(nomor - 1);
                    jumlahBuku.push_back(jumlah);

                    char pilihanLagi;
                    cout << "Apakah ingin membeli buku lagi? (Y/N): ";
                    cin >> pilihanLagi;

                    if (pilihanLagi == 'Y' || pilihanLagi == 'y')
                        continue;
                    else
                        break;
                }
                else {
                    cout << "Jumlah buku tidak valid." << endl;
                }
            }
            else {
                cout << "Nomor buku tidak valid." << endl;
            }
        }
        else if (pilihan == 3) {
//squintal search
            int i=0;
            string target;

            cout << "Masukan Judul Buku : ";
            cin >>target;

            while(i<daftarBuku.size()){
                if(target == daftarBuku[i].getJudul()){
                    cout << "\nBuku Telah Di Temukan" << endl;
                    cout << "Nomor: " << i + 1 << endl;
                    cout << "Judul: " << daftarBuku[i].getJudul() << endl;
                    cout << "Pengarang: " << daftarBuku[i].getPengarang() << endl;
                    cout << "Harga: $" << daftarBuku[i].getHarga() << endl;
                    cout << endl;

                }
                i++;

            }
        }
        else if (pilihan == 4) {
            break;
        }
        else {
            cout << "Pilihan tidak valid." << endl;
        }
    }

    if (!bukuDibeli.empty()) {
        cout << "\nRincian Pembelian:" << endl;
        double totalHarga = 0.0;

        for (int i = 0; i < bukuDibeli.size(); i++) {
            int nomorBuku = bukuDibeli[i];
            int jumlah = jumlahBuku[i];

            cout << "Nomor: " << nomorBuku + 1 << endl;
            cout << "Judul: " << daftarBuku[nomorBuku].getJudul() << endl;
            cout << "Pengarang: " << daftarBuku[nomorBuku].getPengarang() << endl;
            cout << "Harga per buku: $" << daftarBuku[nomorBuku].getHarga() << endl;
            cout << "Jumlah buku: " << jumlah << endl;
            cout << "Subtotal: $" << daftarBuku[nomorBuku].getHarga() * jumlah << endl;
            cout << endl;

            totalHarga += daftarBuku[nomorBuku].getHarga() * jumlah;
        }

        cout << "Total harga: $" << totalHarga << endl;
    }
}
