// ADT  : Book
// NAME : Dwi Yuda Pratama
// DATE : Saturday,20 mei 2023
#include <iostream>
#include <string>
#include <string.h>
#include "Book.h"
using namespace std;


// Main function
int main() {

    int n; // Jumlah buku yang akan dimasukkan
    cout << "Berapa banyak buku yang ingin anda masukan? ";
    cin >> n;

    Book books[n]; // Mendeklarasikan array buku

    // Masukkan setiap informasi buku dari pengguna
    for (int i = 0; i < n; i++) {

        string name, author;
        int year;

        cout << "Masukan Judul Buku " << i+1 << ": ";
        cin.ignore();
        getline(cin, name);

        cout << "Masukan Nama Pengarang Buku " << i+1 << ": ";
        getline(cin, author);

        cout << "Masukan Tahun Terbit Buku " << i+1 << ": ";
        cin >> year;

        books[i] = Book(name, author, year); // Buat objek buku baru dan tetapkan ke array

        cout << endl;

    }

    char choice; // Pilihan untuk melanjutkan atau mengakhiri program

    do {

        int option; // Pilihan untuk memilih fungsi pencarian

        cout << "Pilih salah satu pilihan yang ada:\n";
        cout << "1. Mencari data menggunakan Judul\n";
        cout << "2. Mencari data menggunakan Nama Pengarang\n";
        cout << "3. Mencari data  menggunakan Tahun Terbit\n";
        cout << "4. Menampilkan semua Data\n";

        cin >> option;

        switch(option) {

            case 1: { // Cari berdasarkan nama

                string target; // Nama target untuk dicari

                cout << "Masukan Judul Buku untuk mencari: ";
                cin.ignore();
                getline(cin, target);

                int result = searchByName(books, n, target); // Panggil pencarian berdasarkan fungsi nama

                if (result != -1) { // Jika ketemu

                    cout << "Buku ditemukan:\n";
                    books[result].display(); // Tampilkan buku yang ditemukan

                } else { // Jika tidak ditemukan

                    cout << "Buku tidak ditemukan.\n";

                }

                break;

            }

            case 2: { // Cari berdasarkan penulis

                string target; // Target penulis untuk mencari

                cout << "Masukan Nama Pengarang untuk mencari: ";
                cin.ignore();
                getline(cin, target);

                int result = searchByAuthor(books, n, target); // Call search by author function

                if (result != -1) { // Jika ketemu

                    cout << "Buku ditemukan:\n";
                    books[result].display(); // Tampilkan buku yang ditemukan

                } else { // Jika tidak ditemukan

                    cout << "Buku tidak ditemukan.\n";

                }

                break;

            }

            case 3: { // Cari berdasarkan tahun

                int target; // Tahun target untuk mencari

                cout << "Masukan Tahun untuk mencari: ";
                cin >> target;

                int result = searchByYear(books, n, target); // Pencarian panggilan berdasarkan fungsi tahun

                if (result != -1) { // Jika ketemu

                    cout << "Buku ditemukan:\n";
                    books[result].display(); // Tampilkan buku yang ditemukan

                } else { // Jika tidak ditemukan

                    cout << "Buku tidak ditemukan.\n";

                }

                break;

            }

            case 4: { // Menampilkan semua data

                displayAllBooks(books, n); // memanggil menampilkan semua fungsi buku

                break;

            }

            default: { // Opsi tidak valid

                cout << "Opsi tidak valid.\n";

            }

        }

        cout << "\nApakah  ingin bertanya lagi? Y/N ";

        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
