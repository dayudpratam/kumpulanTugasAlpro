#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Kelas Buku
class Buku {
public:
    string judul;
    string penulis;
    int harga;

    Buku(const string& judul, const string& penulis, int harga) {
        this->judul = judul;
        this->penulis = penulis;
        this->harga = harga;
    }
};

// Fungsi untuk mencari buku berdasarkan judul
vector<Buku> cariBukuJudul(const vector<Buku>& daftarBuku, const string& judul) {
    vector<Buku> hasilPencarian;

    for (const Buku& buku : daftarBuku) {
        if (buku.judul == judul) {
            hasilPencarian.push_back(buku);
        }
    }

    return hasilPencarian;
}

// Fungsi untuk mencari buku berdasarkan harga
vector<Buku> cariBukuHarga(const vector<Buku>& daftarBuku, int harga) {
    vector<Buku> hasilPencarian;

    for (const Buku& buku : daftarBuku) {
        if (buku.harga == harga) {
            hasilPencarian.push_back(buku);
        }
    }

    return hasilPencarian;
}

// Fungsi untuk mencari buku berdasarkan penulis
vector<Buku> cariBukuPenulis(const vector<Buku>& daftarBuku, const string& penulis) {
    vector<Buku> hasilPencarian;

    for (const Buku& buku : daftarBuku) {
        if (buku.penulis == penulis) {
            hasilPencarian.push_back(buku);
        }
    }

    return hasilPencarian;
}

// Fungsi untuk menampilkan daftar buku
void tampilkanDaftarBuku(const vector<Buku>& daftarBuku) {
    cout << "Daftar Buku:" << endl;

    for (int i = 0; i < daftarBuku.size(); i++) {
        cout << "Buku " << i + 1 << endl;
        cout << "Judul: " << daftarBuku[i].judul << endl;
        cout << "Penulis: " << daftarBuku[i].penulis << endl;
        cout << "Harga: " << daftarBuku[i].harga << endl;
        cout << "------------------------" << endl;
    }
}

int main() {
    int jumlahBuku;

    cout << "Masukkan jumlah buku: ";
    cin >> jumlahBuku;

    vector<Buku> daftarBuku;

    for (int i = 0; i < jumlahBuku; i++) {
        string judul;
        string penulis;
        int harga;

        cout << "Buku " << i + 1 << endl;
        cin.ignore();
        cout << "Masukkan judul buku: ";
        getline(cin, judul);
        cout << "Masukkan penulis buku: ";
        getline(cin, penulis);
        cout << "Masukkan harga buku: ";
        cin >> harga;

        Buku buku(judul, penulis, harga);
        daftarBuku.push_back(buku);
    }

    // Pilihan pencarian
    int pilihan;

    do {
        cout << "Pilihan Pencarian: " << endl;
        cout << "1. Cari berdasarkan judul" << endl;
        cout << "2. Cari berdasarkan harga" << endl;
        cout << "3. Cari berdasarkan penulis" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        vector<Buku> hasilPencarian;

        switch (pilihan) {
            case 1: {
                string judul;
                cout << "Masukkan judul buku: ";
                cin.ignore();
                getline(cin, judul);
                hasilPencarian = cariBukuJudul(daftarBuku, judul);
                break;
            }
            case 2: {
                int harga;
                cout << "Masukkan harga buku: ";
                cin >> harga;
                hasilPencarian = cariBukuHarga(daftarBuku, harga);
                break;
            }
            case 3: {
                string penulis;
                cout << "Masukkan penulis buku: ";
                cin.ignore();
                getline(cin, penulis);
                hasilPencarian = cariBukuPenulis(daftarBuku, penulis);
                break;
            }
            case 0:
                cout << "Terima kasih. Sampai jumpa!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
                continue;
        }

        if (hasilPencarian.empty()) {
            cout << "Buku tidak ditemukan." << endl;
        } else {
            tampilkanDaftarBuku(hasilPencarian);

            // Proses pembelian
            string pilihanBeli;
            cout << "Apakah Anda ingin membeli buku? (y/n): ";
            cin >> pilihanBeli;

            if (pilihanBeli == "y" || pilihanBeli == "Y") {
                int indeksBuku;
                int jumlahBeli;

                cout << "Masukkan indeks buku yang ingin dibeli: ";
                cin >> indeksBuku;

                if (indeksBuku >= 0 && indeksBuku < hasilPencarian.size()) {
                    cout << "Masukkan jumlah buku yang ingin dibeli: ";
                    cin >> jumlahBeli;

                    // Lakukan operasi pembelian

                    // Misalnya, menambahkan ke dalam keranjang belanja
                    // atau menghitung total harga
                    // ...

                    cout << "Buku berhasil dibeli." << endl;

                    // Meminta input apakah ingin membeli buku lagi
                    string pilihanLagi;
                    cout << "Apakah Anda ingin membeli buku lagi? (y/n): ";
                    cin >> pilihanLagi;

                    if (pilihanLagi == "n" || pilihanLagi == "N") {
                        cout << "Terima kasih. Sampai jumpa!" << endl;
                        return 0;
                    }
                } else {
                    cout << "Indeks buku tidak valid." << endl;
                }
            }
        }

    } while (pilihan != 0);

    // Simpan hasil pembelian ke file
    ofstream file("hasil_pembelian.txt");
    if (file.is_open()) {
        // Tulis informasi pembelian ke file

        // Misalnya, menuliskan jumlah dan perincian barang yang dibeli
        // ...

        file.close();
        cout << "Hasil pembelian berhasil disimpan." << endl;
    } else {
        cout << "Gagal menyimpan hasil pembelian." << endl;
    }

    return 0;
}
