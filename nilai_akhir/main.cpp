/*
  Program : Menghitung nilai akhir matakuliah DDP dan predikatnya
  Author : 231524028 Umar Faruq Robbany
  Tanggal : 16 November 2023
  I.S. : Belum diketahui nilai akhir dan predikat
  F.S. : menghitung nilai total akhir mata kuliah DDP dari komponen penilaian (ets, eas dan quiz).
         Setiap komponen penilaian memiliki bobot:
         - bobot ets : 35%
         - bobot eas : 40%
         - bobot quiz : 25%
         Nilai total akhir adalah jumlah bobot dikali tiap komponen nilai
         Nilai total akhir akan dikonversikan kedalam sebuah huruf mutu atau disebut predikat.
         Aturan konversi nilai ke predikat adalah
           A  (80 - 100), AB (75 - 79,9), B  (70 - 74,9), BC (65 - 79,9), C (60 - 64,9),
       CD (55 - 59,9), D  (40 - 54,9), E (< 40)

  Goal Praktikum :
  1. Bisa mendeklarasikan variabel struct
  2. Bisa memberi nilai pada variabel struct
  3. Bisa mendefinisikan konstanta variabel global (bobot)
  4. Bisa membuat fungsi dgn paramater struct
  5. Bisa memanggil fungsi dgn passing paramater bertipe struct.
  6. Paham menggunakan struct
*/

#include <stdio.h>
#include "mahasiswa.h"

int main()
{
  // Deklarasi variabel mhs1 dan mhs2 bertipe Mahasiswa
  Mahasiswa mhs1, mhs2;

  // Mengisi data mahasiswa 1
  mhs1.nama = "Akhmad";
  mhs1.nim = "101010";
  mhs1.ets = 80;
  mhs1.eas = 90;
  mhs1.kuis = 85;

  // Tambahkan data mahasiswa 2
  mhs2.nama = "Umar Faruq Robbany";
  mhs2.nim = "231524028";
  mhs2.ets = 50;
  mhs2.eas = 70;
  mhs2.kuis = 65;

  // Panggil fungsi get_total kemudian simpan nilainya ke variabel total
  mhs1.total = get_total(mhs1.ets, mhs1.eas, mhs1.kuis);
  mhs2.total = get_total(mhs2.ets, mhs2.eas, mhs2.kuis);
  // Panggil fungsi get_predikat kemudian simpan nilainya ke variabel predikat
  mhs1.predikat = get_predicate(mhs1.total);
  mhs2.predikat = get_predicate(mhs2.total);
  // Panggil prosedur display data mahasiswa
  displayDataMhs(mhs1);
  displayDataMhs(mhs2);

  return 0;
}