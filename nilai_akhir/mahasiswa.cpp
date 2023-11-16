#include <stdio.h>
#include "header.h"

void displayDataMhs(Mahasiswa mhs)
{
  printf("Data Mahasiswa:\n");
  printf("Nama: %s\n", mhs.nama);
  printf("Nim: %s\n", mhs.nim);
  printf("ETS: %2.f\n", mhs.ets);
  printf("EAS: %2.f\n", mhs.eas);
  printf("Kuis: %2.f\n", mhs.kuis);
  printf("Total: %2.f\n", mhs.total);
  printf("Predikat: %s\n \n", mhs.predikat);
}

float get_total(float nilaiEts, float nilaiEas, float nilaiKuis)
{
  float ets, eas, kuis, total;
  ets = nilaiEts * BOBOT_ETS;
  eas = nilaiEas * BOBOT_EAS;
  kuis = nilaiKuis * BOBOT_KUIS;
  total = ets + eas + kuis;
  return total;
}

const char *get_predicate(float total)
{
  const char *predikat;

  if (total >= 80 && total <= 100)
  {
    predikat = "A";
  }
  else if (total >= 75)
  {
    predikat = "AB";
  }
  else if (total >= 70)
  {
    predikat = "B";
  }
  else if (total >= 65)
  {
    predikat = "BC";
  }
  else if (total >= 60)
  {
    predikat = "C";
  }
  else if (total >= 55)
  {
    predikat = "CD";
  }
  else if (total >= 40)
  {
    predikat = "D";
  }
  else
  {
    predikat = "E";
  }

  return predikat;
}
