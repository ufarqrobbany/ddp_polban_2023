/*
    Nama                : Umar Faruq Robbany
    NIM                 : 231524028
    Nama Program        : Statistik Ganjil dan Genap V1
    Deskripsi           : Menghitung Statistik Ganjil dan Genap pada Matriks
    Tanggal             : 26 Oktober 2023
*/

#include <stdio.h>

int main()
{
    int matriks[5][5] = {{6, 7, 12, 18, 21}, {90, 1, 25, 40, 37}, {2, 7, 5, 10, 80}, {9, 7, 5, 3, 2}, {15, 20, 73, 55, 6}};

    typedef struct
    {
        int Angka;
        int Jumlah_Kemunculan;
    } Bilangan;

    Bilangan Rekap_Bil_Genap[25], Rekap_Bil_Ganjil[25];

    int i, baris, kolom;
    int genap = 0, ganjil = 0;

    i = 0;
    while (i < 25)
    {
        Rekap_Bil_Genap[i].Angka = 0;
        Rekap_Bil_Genap[i].Jumlah_Kemunculan = 0;
        Rekap_Bil_Ganjil[i].Angka = 0;
        Rekap_Bil_Ganjil[i].Jumlah_Kemunculan = 0;
        i++;
    }

    baris = 0;
    while (baris < 5)
    {
        kolom = 0;
        while (kolom < 5)
        {
            i = 0;
            if (matriks[baris][kolom] % 2 == 0)
            {
                while (i < 25)
                {
                    if ((matriks[baris][kolom] != Rekap_Bil_Genap[i].Angka) && (Rekap_Bil_Genap[i].Angka == 0))
                    {
                        Rekap_Bil_Genap[i].Angka = matriks[baris][kolom];
                        Rekap_Bil_Genap[i].Jumlah_Kemunculan++;
                        i = 26;
                    }
                    else if (matriks[baris][kolom] == Rekap_Bil_Genap[i].Angka)
                    {
                        Rekap_Bil_Genap[i].Jumlah_Kemunculan++;
                        i = 26;
                    }
                    i++;
                }
                genap++;
            }
            else
            {
                while (i < 25)
                {
                    if ((matriks[baris][kolom] != Rekap_Bil_Ganjil[i].Angka) && (Rekap_Bil_Ganjil[i].Angka == 0))
                    {
                        Rekap_Bil_Ganjil[i].Angka = matriks[baris][kolom];
                        Rekap_Bil_Ganjil[i].Jumlah_Kemunculan++;
                        i = 26;
                    }
                    else if (matriks[baris][kolom] == Rekap_Bil_Ganjil[i].Angka)
                    {
                        Rekap_Bil_Ganjil[i].Jumlah_Kemunculan++;
                        i = 26;
                    }
                    i++;
                }
                ganjil++;
            }
            kolom++;
        }
        baris++;
    }

    i = 0;
    printf("======= REKAP BILANGAN GENAP ======= \n");
    while (i < 25)
    {
        if ((Rekap_Bil_Genap[i].Angka != 0) && (Rekap_Bil_Genap[i].Jumlah_Kemunculan != 0))
        {
            printf("Bilangan: %d, ", Rekap_Bil_Genap[i].Angka);
            printf("Jumlah kemunculan: %d\n", Rekap_Bil_Genap[i].Jumlah_Kemunculan);
        }
        i++;
    }

    i = 0;
    printf("======= REKAP BILANGAN GANJIL ======= \n");
    while (i < 25)
    {
        if ((Rekap_Bil_Ganjil[i].Angka != 0) && (Rekap_Bil_Ganjil[i].Jumlah_Kemunculan != 0))
        {
            printf("Bilangan: %d, ", Rekap_Bil_Ganjil[i].Angka);
            printf("Jumlah kemunculan: %d\n", Rekap_Bil_Ganjil[i].Jumlah_Kemunculan);
        }
        i++;
    }

    printf("============== TOTAL ==============\n");
    printf("Bilangan Genap: %d \n", genap);
    printf("Bilangan Ganjil: %d", ganjil);

    return 0;
}