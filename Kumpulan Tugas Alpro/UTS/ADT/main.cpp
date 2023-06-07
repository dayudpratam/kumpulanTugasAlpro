#include <iostream>
#include <string>
using namespace std;

struct Data {
    string nama;
    string NIK;
    string alamat;
    int umur;
    string tgl_lahir;
};

void radixSort(Data arr[], int n, int exp);
void printData(Data arr[], int n);

int main() {
    const int MAX_DATA = 100;
    Data data[MAX_DATA];
    int n = 0;

    do {
        cout << "Input data ke-" << n+1 << endl;
        cout << "Nama: ";
        cin >> data[n].nama;
        cout << "NIK: ";
        cin >> data[n].NIK;
        cout << "Alamat: ";
        cin >> data[n].alamat;
        cout << "Umur: ";
        cin >> data[n].umur;
        cout << "Tanggal Lahir (dd-mm-yyyy): ";
        cin >> data[n].tgl_lahir;

        n++;

        char repeat;
        cout << "Input lagi? (y/n) ";
        cin >> repeat;

        if (repeat != 'y' && repeat != 'Y') {
            break;
        }

        // reset cin flags and ignore buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (n < MAX_DATA);

    // radix sort by tgl_lahir
    for (int exp = 2; exp >= 0; exp--) {
        radixSort(data, n, exp);
    }

    // print sorted data
    printData(data, n);

    return 0;
}

void radixSort(Data arr[], int n, int exp) {
    const int MAX_DIGITS = 10;
    Data output[n];
    int count[MAX_DIGITS] = {0};

    // count occurrences
    for (int i = 0; i < n; i++) {
        int digit = arr[i].tgl_lahir[exp] - '0';
        count[digit]++;
    }

    // accumulate count
    for (int i = 1; i < MAX_DIGITS; i++) {
        count[i] += count[i-1];
    }

    // build output array
    for (int i = n-1; i >= 0; i--) {
        int digit = arr[i].tgl_lahir[exp] - '0';
        output[count[digit]-1] = arr[i];
        count[digit]--;
    }

    // copy output to input array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void printData(Data arr[], int n) {
    cout << endl << "Data yang diurutkan:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i].nama << "\t" << arr[i].NIK << "\t" << arr[i].alamat << "\t" << arr[i].umur << "\t" << arr[i].tgl_lahir << endl;
    }
}
