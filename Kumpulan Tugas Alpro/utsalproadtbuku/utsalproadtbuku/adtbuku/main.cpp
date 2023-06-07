// ADT  : Book
// NAME : Dwi Yuda Pratama
// DATE : Saturday,20 mei 2023
#include <iostream>
#include <string>
using namespace std;

// Define a class for book object
class Book {
    public:
        // Constructors
        Book(); // Default constructor
        Book(string name, string author, int year); // Parameterized constructor

        // Getters and setters
        string getName() const; // Get the name of the book
        void setName(string name); // Set the name of the book
        string getAuthor() const; // Get the author of the book
        void setAuthor(string author); // Set the author of the book
        int getYear() const; // Get the year of publication of the book
        void setYear(int year); // Set the year of publication of the book

        // Display the book information
        void display() const;

    private:
        // Data members
        string name; // Name of the book
        string author; // Author of the book
        int year; // Year of publication of the book
};

// Default constructor
Book::Book() {
    name = "";
    author = "";
    year = 0;
}

// Parameterized constructor
Book::Book(string name, string author, int year) {
    this->name = name;
    this->author = author;
    this->year = year;
}

// Get the name of the book
string Book::getName() const {
    return name;
}

// Set the name of the book
void Book::setName(string name) {
    this->name = name;
}

// Get the author of the book
string Book::getAuthor() const {
    return author;
}

// Set the author of the book
void Book::setAuthor(string author) {
    this->author = author;
}

// Get the year of publication of the book
int Book::getYear() const {
    return year;
}

// Set the year of publication of the book
void Book::setYear(int year) {
    this->year = year;
}

// Display the book information
void Book::display() const {
    cout << "Name: " << name << endl;
    cout << "Author: " << author << endl;
    cout << "Year: " << year << endl;
}

// Define a function to search for a book by name in an array of books
int searchByName(Book books[], int size, string target) {
    for (int i = 0; i < size; i++) {
        if (books[i].getName() == target) {
            return i; // Return the index of the found book
        }
    }
    return -1; // Return -1 if not found
}

// Define a function to search for a book by author in an array of books
int searchByAuthor(Book books[], int size, string target) {
    for (int i = 0; i < size; i++) {
        if (books[i].getAuthor() == target) {
            return i; // Return the index of the found book
        }
    }
    return -1; // Return -1 if not found
}

// Define a function to search for a book by year in an array of books
int searchByYear(Book books[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (books[i].getYear() == target) {
            return i; // Return the index of the found book
        }
    }
    return -1; // Return -1 if not found
}

// Define a function to display all books in an array of books
void displayAllBooks(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        books[i].display(); // Display each book information
        cout << endl;
    }
}

// Main function
int main() {

    int n; // Number of books to input

    cout << "Berapa banyak buku yang ingin anda masukan? ";
    cin >> n;

    Book books[n]; // Declare an array of books

    // Input each book information from user
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

        books[i] = Book(name, author, year); // Create a new book object and assign it to the array

        cout << endl;

    }

    char choice; // Choice to continue or end program

    do {

        int option; // Option to choose search function

        cout << "Pilih salah satu pilihan yang ada:\n";
        cout << "1. Mencari data menggunakan Judul\n";
        cout << "2. Mencari data menggunakan Nama Pengarang\n";
        cout << "3. Mencari data  menggunakan Tahun Terbit\n";
        cout << "4. Menampilkan semua Data\n";

        cin >> option;

        switch(option) {

            case 1: { // Search by name

                string target; // Target name to search

                cout << "Masukan Judul Buku untuk mencari: ";
                cin.ignore();
                getline(cin, target);

                int result = searchByName(books, n, target); // Call search by name function

                if (result != -1) { // If found

                    cout << "Buku ditemukan:\n";
                    books[result].display(); // Display found book

                } else { // If not found

                    cout << "Buku tidak ditemukan.\n";

                }

                break;

            }

            case 2: { // Search by author

                string target; // Target author to search

                cout << "Masukan Nama Pengarang untuk mencari: ";
                cin.ignore();
                getline(cin, target);

                int result = searchByAuthor(books, n, target); // Call search by author function

                if (result != -1) { // If found

                    cout << "Buku ditemukan:\n";
                    books[result].display(); // Display found book

                } else { // If not found

                    cout << "Buku tidak ditemukan.\n";

                }

                break;

            }

            case 3: { // Search by year

                int target; // Target year to search

                cout << "Masukan Tahun untuk mencari: ";
                cin >> target;

                int result = searchByYear(books, n, target); // Call search by year function

                if (result != -1) { // If found

                    cout << "Buku ditemukan:\n";
                    books[result].display(); // Display found book

                } else { // If not found

                    cout << "Buku tidak ditemukan.\n";

                }

                break;

            }

            case 4: { // Display all data

                displayAllBooks(books, n); // memanggil display all books function

                break;

            }

            default: { // Invalid option

                cout << "Opsi tidak valid.\n";

            }

        }

        cout << "\nApakah  ingin bertanya lagi? Y/N ";

        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
