#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>
using namespace std;

// Kamus
void menu();
void headerMenu();
void konfirmUlangMenu();
string gen_random();
void kendaraanMasuk();
void kendaraanKeluar();
void rekapPendapatan();

void menu()
{
    char menuPilihan;
    cout << "| Masukkan Pilihan :                                         |\n";
    cin >> menuPilihan;
    switch (menuPilihan)
    {
    case '1':
    {
        // ke menu 1
        // cout << "Menu 1";
        system("cls");
        kendaraanMasuk();
    }
    break;
    case '2':
    {
        // ke menu 2
        // cout << "Menu 2";
        system("cls");
        kendaraanKeluar();
    }
    break;
    case '3':
    {
        // ke menu 3
        // cout << "Menu 3";
        system("cls");
        rekapPendapatan();
    }
    break;
    default:
        cout << "Pilihan anda tidak tersedia. ulangi pilihan ? (y/n)";
        konfirmUlangMenu();
    }
}

void headerMenu()
{
    cout << "==================== Sistem Karcis Parkir ====================\n";
    cout << "|                   ( Opsi Pilihan Menu )                    |\n";
    cout << "|                  1. Input Kendaraan Masuk                  |\n";
    cout << "|                  2. Input Kendaraan Keluar                 |\n";
    cout << "|                  3. Rekapitulasi Pendapatan                |\n";
    cout << "==============================================================\n";
    menu();
}

void konfirmUlangMenu()
{
    char konfirmMenu;
    cin >> konfirmMenu;
    if (konfirmMenu == 'y' || konfirmMenu == 'Y')
    {
        menu();
    }
    else
    {
        cout << "Terimakasih :)";
    }
}