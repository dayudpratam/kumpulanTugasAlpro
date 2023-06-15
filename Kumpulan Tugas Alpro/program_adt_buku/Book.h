// ADT  : Book
// NAME : Dwi Yuda Pratama
// DATE : Saturday,20 mei 2023
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// class book dengan method2nya
class Book {
    public:
        // method dalam class book
        Book(); //  fungsi Book
        Book(string name, string author, int year); // dengan parameter (name-string,author-string,year-integer)

        string getName() const; // prosedur mendapatkan nama bukunya
        void setName(string name); // fungsi berparameter Tetapkan nama buku
        string getAuthor() const; // prosedur Dapatkan penulis buku
        void setAuthor(string author); // fungsi berparameter Tetapkan penulis buku
        int getYear() const; // prosedur Dapatkan tahun penerbitan buku
        void setYear(int year); // fungsi berparameter Tetapkan tahun penerbitan buku

        // menampilkan informasi book
        void display() const; // fungsi menampilkan informasi book

    private:
        // Data anggota
        string name; // Nama buku
        string author; // penulis  buku
        int year; // Tahun penerbitan buku
};

// Konstruktor dalam class book
Book::Book() {//
    name = "";//variabel nama
    author = "";//variabel penerbit
    year = 0;//variabel tahun terbit
}

// Konstruktor berparameter
Book::Book(string name, string author, int year) {
    this->name = name;// digunakan untuk menginisialisasi variabel anggota name dari objek yang sedang dibuat dengan nilai name yang diterima sebagai argumen.
    this->author = author;// digunakan untuk menginisialisasi variabel anggota author dari objek yang sedang dibuat dengan nilai author yang diterima sebagai argumen.
    this->year = year;//digunakan untuk menginisialisasi variabel anggota year dengan nilai year yang diterima sebagai argumen.
}

// method mendapatkan nama bukunya
string Book::getName() const {//menandakan bahwa metode ini tidak akan mengubah status objek yang memanggil metode tersebut
    return name;//mengembalikan nilai dalam bentuk variabel name
}

// Tetapkan nama buku
void Book::setName(string name) {//metode (atau fungsi) dari kelas Book
                                 //yang bertujuan untuk mengubah nilai variabel anggota name dengan nilai baru yang diterima sebagai argumen.
    this->name = name;
}

// Dapatkan penulis buku
string Book::getAuthor() const {//sebuah metode (atau fungsi)
    return author;          //dari kelas Book yang mengembalikan nilai dari variabel anggota author dalam bentuk string.

}

// Tetapkan penulis buku
void Book::setAuthor(string author) {// metode (atau fungsi) dari kelas Book yang
    this->author = author;          //bertujuan untuk mengubah nilai variabel anggota author dengan nilai baru yang diterima sebagai argumen.

}

// Dapatkan tahun penerbitan buku
int Book::getYear() const {// metode (atau fungsi) dari kelas Book yang bertujuan untuk
    return year;          //mengubah nilai variabel anggota author dengan nilai baru yang diterima sebagai argumen.

}

// Tetapkan tahun penerbitan buku
void Book::setYear(int year) {//metode (atau fungsi) dari kelas Book yang
    this->year = year;       //bertujuan untuk mengubah nilai variabel anggota year dengan nilai baru yang diterima sebagai argumen.

}

// Menampilkan informasi buku
void Book::display() const {//metode (atau fungsi) dari kelas Book yang bertujuan

    cout << "Name: " << name << endl;//untuk menampilkan informasi buku seperti nama, penulis, dan tahun dalam konsol.
    cout << "Author: " << author << endl;
    cout << "Year: " << year << endl;
}

// Tentukan fungsi untuk mencari buku berdasarkan nama dalam larik buku
int searchByName(Book books[], int size, string target) {//sebuah fungsi yang mengambil array dari objek Book, ukuran array (size), dan sebuah string target sebagai argumen. Fungsi ini bertujuan untuk mencari dan mengembalikan indeks pertama dimana nama buku
   for (int i = 0; i < size; i++) { //dalam array sesuai dengan target yang diberikan. Jika tidak ditemukan, fungsi akan mengembalikan nilai -1.

        if (books[i].getName() == target) {
            return i; // Kembalikan indeks buku yang ditemukan
        }
    }
    return -1; // Kembalikan -1 jika tidak ditemukan
}

// Tentukan fungsi untuk mencari buku oleh penulis dalam larik buku
int searchByAuthor(Book books[], int size, string target) {
    for (int i = 0; i < size; i++) {
        if (books[i].getAuthor() == target) {
            return i; // Kembalikan indeks buku yang ditemukan
        }
    }
    return -1; // Return -1 if not found
}

// Tentukan fungsi untuk mencari buku berdasarkan tahun dalam larik buku
int searchByYear(Book books[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (books[i].getYear() == target) {
            return i; // Kembalikan indeks buku yang ditemukan
        }
    }
    return -1; // Kembalikan -1 jika tidak ditemukan
}

// Tentukan fungsi untuk menampilkan semua buku dalam larik buku
void displayAllBooks(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        books[i].display(); // Tampilkan setiap informasi buku
        cout << endl;
    }
}
