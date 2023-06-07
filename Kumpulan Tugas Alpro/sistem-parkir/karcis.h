#include <iostream>
#include <string>
// #include <unistd.h>
// #include <ctime>
// #include <stdio.h>
// include file .h
#include "waktu.h"
using namespace std;

// Kamus
void kendaraanMasuk();
void kendaraanKeluar();
void rekapPendapatan();
// string currentTime();
// string currentHours();
// string currentMinutes();
// string currentSeconds();
// string gen_random(const int len);

class Karcis
{
public:
    string idKarcis;
    int jjM, mmM, ddM;     // jam Masuk
    int jjK, mmK, ddK;     // jam Keluar
    string noPol;          // Nomor kendaraan
    string jenisKendaraan; // mobil / motor
    int tarif;             // Tarif perJam

    // default constructor
    Karcis()
    {
        this->idKarcis = "-";
        this->jjM = 0;
        this->mmM = 0;
        this->ddM = 0;
        this->jjK = 0;
        this->mmK = 0;
        this->ddK = 0;
        this->noPol = "-";
        this->jenisKendaraan = "-";
        this->tarif = 0;
    }
};

Karcis krcs[30];

void kendaraanMasuk()
{
    // baca file untuk menemukan lastrecord
    ifstream fileRekap("rekapSistemParkir.dat");
    fileRekap.read((char *)&krcs, sizeof(krcs));
    for (int i = 0; i < sizeof(krcs); i++)
    {
        if (krcs[i].idKarcis == "-")
        {
            ofstream fileDataParkir("rekapSistemParkir.dat");
            cout << "===== Input Kendaraan Masuk =====" << endl;
            string randomString = gen_random(3);
            string curntHours = currentHours();
            string curntMinutes = currentMinutes();
            string currntSeconds = currentSeconds();
            cout << "Kode Parkir \t: " << randomString << endl;
            krcs[i].idKarcis = randomString;
            cout << "Jam Masuk \t: " << curntHours << ":" << curntMinutes << ":" << currntSeconds << endl;
            // int iJamMasuk = stoi(curntHours);
            krcs[i].jjM = stoi(currentHours());
            krcs[i].mmM = stoi(currentMinutes());
            krcs[i].ddM = stoi(currentSeconds());
            krcs[i].jjK = 0;
            krcs[i].mmK = 0;
            krcs[i].ddK = 0;
            cin.ignore();
            string sNoPol;
            cout << "Nomor Polisi Kendaraan \t: ";
            getline(cin, sNoPol);
            krcs[i].noPol = sNoPol;
        ulangJenisKendaraan:
            cout
                << "Jenis Kendaraan (mobil / motor) \t:";
            string sjenisKendaraan;
            cin >> sjenisKendaraan;
            if (sjenisKendaraan == "mobil" || sjenisKendaraan == "motor")
            {
                krcs[i].jenisKendaraan = sjenisKendaraan;
                krcs[i].tarif = 0;
                fileDataParkir.write((char *)&krcs, sizeof(krcs));
                fileDataParkir.close();
                fileRekap.close();

                headerMenu();
            }
            else
            {
                cout << "Pilihan tidak tersedia, silahkan coba lagi\n";
                goto ulangJenisKendaraan;
            }
        }
    }
}

void kendaraanKeluar()
{
    // baca file untuk menemukan lastrecord
    ifstream fileRekap("rekapSistemParkir.dat");
    fileRekap.read((char *)&krcs, sizeof(krcs));

// local variable
ulangKodeParkir:
    string sInputKodeParkir;
    int i, flag = 0, ijjK, immK, iddK;
    cout << "===== Input Kendaraan Keluar =====" << endl;
    cout << "Kode Parkir : ";
    cin >> sInputKodeParkir;

    // cari dengan metode sequential search()
    for (i = 0; i < sizeof(krcs); i++)
    {
        if (krcs[i].idKarcis == sInputKodeParkir)
        {
            flag = 1;
            break;
        }
    }
    // cetak hasil
    if (flag == 1)
    {
        // cout << "Data ditemukan pada indek ke-" << i << endl;
        cout << "---------------------------------------------\n";
        cout << "Input Jam Keluar \t: ";
        cin >> ijjK;
        krcs[i].jjK = ijjK;
        cout << "Input Menit Keluar \t: ";
        cin >> immK;
        krcs[i].mmK = immK;
        cout << "Input Detik Keluar \t: ";
        cin >> iddK;
        krcs[i].ddK = iddK;
        // Kalkulasi Jam dan Tarif
        Waktu wktMasuk = Waktu(krcs[i].jjM, krcs[i].mmM, krcs[i].ddM);
        Waktu wktKeluar(krcs[i].jjK, krcs[i].mmK, krcs[i].ddK);
        Waktu totaljam = wktKeluar - wktMasuk;
        /*
            Kalkulasi Pembayaran
            1 Jam pertama --> Mobil = 4K, Motor = 3K
            Jam setelahnya --> Mobil = 3K, Motor = 2K
            Toleransi waktu selama 15 menit per jam
        */
        int iTarifAkhir = 0;
        if (totaljam.valueJam() > 1 && totaljam.valueMenit() >= 15)
        {
            if (krcs[i].jenisKendaraan == "Mobil" || krcs[i].jenisKendaraan == "mobil")
            {
                iTarifAkhir = 4000 + (3000 * (totaljam.valueJam() - 1));
            }
            else if (krcs[i].jenisKendaraan == "Motor" || krcs[i].jenisKendaraan == "motor")
            {
                iTarifAkhir = 3000 + (2000 * (totaljam.valueJam() - 1));
            }
        }
        else if (totaljam.valueJam() > 0 && totaljam.valueMenit() > 0)
        {
            if (krcs[i].jenisKendaraan == "Mobil" || krcs[i].jenisKendaraan == "mobil")
            {
                iTarifAkhir = 4000;
            }
            else if (krcs[i].jenisKendaraan == "Motor" || krcs[i].jenisKendaraan == "motor")
            {
                iTarifAkhir = 3000;
            }
        }
        krcs[i].tarif = iTarifAkhir;

        // Simpan data, dan view detail parkir
        ofstream saveDataKarcis("rekapSistemParkir.dat");
        saveDataKarcis.write((char *)&krcs, sizeof(krcs));
        cout << "\n\n========== Detail Parkir Kendaraan ==========\n";
        cout << "Kode Parkir \t\t: " << krcs[i].idKarcis << "\n";
        cout << "Plat Nomor \t\t: " << krcs[i].noPol << "\n";
        cout << "Jenis Kendaraan \t: " << krcs[i].jenisKendaraan << "\n";
        cout << "Jam Masuk \t\t: " << krcs[i].jjM << ":" << krcs[i].mmM << ":" << krcs[i].ddM << "\n";
        cout << "Jam Keluar \t\t: " << krcs[i].jjK << ":" << krcs[i].mmK << ":" << krcs[i].ddK << "\n";
        cout << "Durasi Parkir \t\t: " << totaljam.valueJam() << " Jam, " << totaljam.valueMenit() << " Menit, " << totaljam.valueDetik() << "\n";
        cout << "Total Tarif \t\t: " << iTarifAkhir << "\n";
        cout << "=============================================\n";
        cout << "Nb \t:\n";
        cout << "1 Jam pertama-- > Mobil = 4K, Motor = 3K /Jam\n";
        cout << "Jam setelahnya-- > Mobil = 3K, Motor = 2K /Jam\n";
        cout << "Toleransi waktu selama 15 menit per jam\n";
        cout << "=============================================\n\n\n";

        fileRekap.close();
        saveDataKarcis.close();
        headerMenu();
    }
    else
    {
        cout << "Mohon maaf data kendaraan tidak terdeteksi, silahkan teliti kembali !\n"
             << endl;
        goto ulangKodeParkir;
    }
}

void rekapPendapatan()
{
    cout << "=============== Rekapitulasi Pendapatan ===============\n";
    // baca file untuk menemukan lastrecord
    ifstream fileRekap("rekapSistemParkir.dat");
    fileRekap.read((char *)&krcs, sizeof(krcs));

    cout << "Per Hari / Tanggal \t\t: " << currentDateTime() << endl;
    int iTotalPendapatann = 0;
    for (int a = 0; a < sizeof(krcs); a++)
    {
        if (krcs[a].idKarcis != "-" && krcs[a].idKarcis != "")
        {
            iTotalPendapatann += krcs[a].tarif;
        }
    }
    cout << "Total Pendapatan \t\t: " << iTotalPendapatann << endl;
    cout << "Daftar Kendaraan \t\t: \n";
    cout << "| Kode Parkir \t\t| Plat Nomor \t\t| Jenis Kendaraan \t\t| Jam Masuk \t\t| Jam Keluar \t\t| Durasi Parkir \t\t\t\t| Jumlah Tarif \t\t|\n";
    for (int i = 0; i < sizeof(krcs); i++)
    {
        if (krcs[i].idKarcis != "-" && krcs[i].idKarcis != "")
        {
            // Kalkulasi Jam dan Tarif
            Waktu wktMasuk = Waktu(krcs[i].jjM, krcs[i].mmM, krcs[i].ddM);
            Waktu wktKeluar(krcs[i].jjK, krcs[i].mmK, krcs[i].ddK);
            Waktu totaljam = wktKeluar - wktMasuk;
            if (totaljam.valueJam() < 0)
            {
                cout << "| " << krcs[i].idKarcis << " \t\t| " << krcs[i].noPol << " \t\t| " << krcs[i].jenisKendaraan << " \t\t\t| " << krcs[i].jjM << ":" << krcs[i].mmM << ":" << krcs[i].ddM << " \t\t| " << krcs[i].jjK << ":" << krcs[i].mmK << ":" << krcs[i].ddK << " \t\t| 0 Jam, 0 Menit, 0 Detik \t\t\t| " << krcs[i].tarif << " \t\t|\n";
            }
            else
            {
                cout << "| " << krcs[i].idKarcis << " \t\t| " << krcs[i].noPol << " \t\t| " << krcs[i].jenisKendaraan << " \t\t\t| " << krcs[i].jjM << ":" << krcs[i].mmM << ":" << krcs[i].ddM << " \t\t| " << krcs[i].jjK << ":" << krcs[i].mmK << ":" << krcs[i].ddK << " \t\t| " << totaljam.valueJam() << " Jam, " << totaljam.valueMenit() << " Menit, " << totaljam.valueDetik() << " Detik"
                     << " \t\t\t| " << krcs[i].tarif << " \t\t|\n";
            }
        }
    }
}