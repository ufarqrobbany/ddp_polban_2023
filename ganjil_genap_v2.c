/*
    Nama                : Umar Faruq Robbany
    NIM                 : 231524028
    Nama Program        : Statistik Ganjil dan Genap V2
    Deskripsi           : Menghitung Statistik Ganjil dan Genap pada Matriks
    Tanggal             : 9 November 2023
*/

#include <stdio.h>
#include <windows.h>

int matriks[20][20], baris, kolom;

typedef struct
{
  int Angka;
  int Jumlah_Kemunculan;
} Bilangan;

Bilangan Rekap_Bil_Genap[400], Rekap_Bil_Ganjil[400];

int indeks, genap, ganjil;

void bagi(int a, int b, int *hasil, int *sisa)
{
  int x = 1, y = 1;
  if (a < 0)
  {
    a = -a;
    x = -1;
  }
  if (b < 0)
  {
    b = -b;
    y = -1;
  }
  int c = 0;
  while (a >= b)
  {
    a -= b;
    c += 1;
  }
  if (x != y)
  {
    c = -c;
  }
  *hasil = c;
  *sisa = a;
}

void assignMatrix(int (*matriks)[20][20], int *baris, int *kolom)
{
  int i, j;
  char spasi;

  printf("Masukkan jumlah baris matriks: \033[0;34m");
  scanf("%d", &(*baris));
  printf("\033[0m");

  printf("Masukkan jumlah kolom matriks: \033[0;34m");
  scanf("%d", &(*kolom));
  printf("\033[0m");

  printf("Masukkan elemen-elemen matriks maksimal \033[0;34m%d\033[0m elemen (pisahkan dengan spasi): \n", (*baris) * (*kolom));

  i = 0;
  while (i < (*baris))
  {
    j = 0;
    while (j < (*kolom))
    {
      printf("\033[0;35m");
      scanf("%d", &(*matriks)[i][j]);
      printf("\033[0m");
      j++;
    }
    i++;
  }
}

void printMatrix(int (*matriks)[20][20], int baris, int kolom)
{
  int i, j;
  i = 0;
  while (i < baris)
  {
    j = 0;
    while (j < kolom)
    {
      printf("\033[0;35m%d\033[0m \t", (*matriks)[i][j]);
      j++;
    }
    printf("\n \n");
    i++;
  }
}

void printRekap(Bilangan rekap[400], int total)
{
  int i = 0;
  while (i < 25)
  {
    if ((rekap[i].Angka != 0) &&
        (rekap[i].Jumlah_Kemunculan != 0))
    {
      printf("Bilangan: \033[0;35m%d\033[0m \t", rekap[i].Angka);
      printf("Jumlah kemunculan: \033[0;34m%d\033[0m \n", rekap[i].Jumlah_Kemunculan);
    }
    i++;
  }
  printf("Total: \033[0;34m%d\033[0m \n", total);
}

void assignBil(int angka, Bilangan (*rekap)[400], int *indeks)
{
  if ((angka != (*rekap)[*indeks].Angka) &&
      ((*rekap)[*indeks].Angka == 0))
  {
    (*rekap)[*indeks].Angka = angka;
    (*rekap)[*indeks].Jumlah_Kemunculan++;
    *indeks = 26;
  }
  else if (angka == (*rekap)[*indeks].Angka)
  {
    (*rekap)[*indeks].Jumlah_Kemunculan++;
    *indeks = 26;
  }
  (*indeks)++;
}

void rekapBil(int matriks[20][20], int baris, int kolom, Bilangan (*rekapGanjil)[400], Bilangan (*rekapGenap)[400], int *ganjil, int *genap, int *indeks)
{
  int i, j, hasil, sisa;
  *genap = 0;
  *ganjil = 0;

  i = 0;
  while (i < 25)
  {
    (*rekapGenap)[i].Angka = 0;
    (*rekapGenap)[i].Jumlah_Kemunculan = 0;
    (*rekapGanjil)[i].Angka = 0;
    (*rekapGanjil)[i].Jumlah_Kemunculan = 0;
    i++;
  }

  i = 0;
  while (i < baris)
  {
    j = 0;
    while (j < kolom)
    {
      *indeks = 0;
      bagi(matriks[i][j], 2, &hasil, &sisa);
      if (sisa == 0)
      {
        while ((*indeks) < 25)
        {
          assignBil(matriks[i][j], &(*rekapGenap), &(*indeks));
        }
        (*genap)++;
      }
      else
      {
        while ((*indeks) < 25)
        {
          assignBil(matriks[i][j], &(*rekapGanjil), &(*indeks));
        }
        (*ganjil)++;
      }
      j++;
    }
    i++;
  }
}

int main()
{
  system("cls");

  assignMatrix(&matriks, &baris, &kolom);
  printf("\n\033[1;33m============== MATRIKS =============\033[0m \n \n");
  printMatrix(&matriks, baris, kolom);
  rekapBil(matriks, baris, kolom, &Rekap_Bil_Ganjil, &Rekap_Bil_Genap, &ganjil, &genap, &indeks);
  printf("\033[1;33m======= REKAP BILANGAN GENAP =======\033[0m \n \n");
  printRekap(Rekap_Bil_Genap, genap);
  printf("\n\033[1;33m======= REKAP BILANGAN GANJIL =======\033[0m \n \n");
  printRekap(Rekap_Bil_Ganjil, ganjil);
  printf("\n");

  return 0;
}