#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

typedef struct
{
  int Tgl;
  int Bln;
  int Thn;
} Date;

Date D;

void BacaDate(Date(*D))
{
  printf("Masukkan tanggal: \033[0;34m");
  scanf("%d", &(*D).Tgl);
  printf("\033[0mMasukkan bulan: \033[0;34m");
  scanf("%d", &(*D).Bln);
  printf("\033[0mMasukkan tahun: \033[0;34m");
  scanf("%d", &(*D).Thn);
  printf("\033[0m");
}

bool isKabisat(Date D)
{
  bool kabisat = false;

  if (((D.Thn % 4 == 0) && (D.Thn % 100 != 0)) || (D.Thn % 400 == 0))
  {
    kabisat = true;
  }

  return kabisat;
}

int TglAkhir(Date D)
{
  int tanggalAkhir = 28;

  if (((D.Bln % 2 == 0) && (D.Bln <= 7) && (D.Bln != 2)) || ((D.Bln % 2 == 1) && (D.Bln > 7)))
  {
    tanggalAkhir = 30;
  }
  else
  {
    tanggalAkhir = 31;
  }

  if ((D.Bln == 2) && isKabisat(D))
  {
    tanggalAkhir = 29;
  }

  return tanggalAkhir;
}

bool isValid(Date D)
{
  bool valid = false;

  if ((D.Tgl >= 1) && (D.Tgl <= TglAkhir(D)) && (D.Bln >= 1) && (D.Bln <= 12) && (D.Thn >= 1))
  {
    valid = true;
  }

  return valid;
}

void DateBefore(Date(*D))
{
  if (((*D).Tgl == 1) && ((*D).Bln == 1))
  {
    (*D).Thn -= 1;
    (*D).Bln = 12;
    (*D).Tgl = 31;
  }
  else if (((*D).Tgl == 1) && ((*D).Bln > 1))
  {
    (*D).Bln -= 1;
    (*D).Tgl = TglAkhir((*D));
  }
  else
  {
    (*D).Tgl -= 1;
  }
}

void NextDate(Date(*D))
{
  if (((*D).Tgl == TglAkhir((*D))) && ((*D).Bln == 12))
  {
    (*D).Thn += 1;
    (*D).Bln = 1;
    (*D).Tgl = 1;
  }
  else if (((*D).Tgl == TglAkhir((*D))) && ((*D).Bln < 12))
  {
    (*D).Bln += 1;
    (*D).Tgl = 1;
  }
  else
  {
    (*D).Tgl += 1;
  }
}

void PrintTgl(Date D)
{
  printf("\033[0;34m%02d\033[0m/\033[0;34m%02d\033[0m/\033[0;34m%04d\033[0m \n", D.Tgl, D.Bln, D.Thn);
}

int main()
{
  system("cls");
  printf("\033[0m");

  BacaDate(&D);
  printf("\033[0;33m===================================\033[0m \n");

  switch (isValid(D))
  {
  case true:
    printf("Tanggal \033[0;36mvalid\033[0m \n");
    break;
  default:
    printf("Tanggal \033[0;31mtidak valid\033[0m \n");
  }

  if (D.Thn >= 1)
  {
    switch (isKabisat(D))
    {
    case true:
      printf("Tahun kabisat: \033[0;36miya\033[0m\n");
      break;
    default:
      printf("Tahun kabisat: \033[0;31mbukan\033[0m \n");
    }

    if (D.Bln >= 1 && D.Bln <= 12)
    {
      printf("Tanggal akhir: \033[0;34m%d\033[0m \n", TglAkhir(D));
    }
  }

  if (isValid(D))
  {
    printf("\033[0;33m===================================\033[0m \n");
    printf("Tanggal: ");
    PrintTgl(D);

    DateBefore(&D);
    printf("Tanggal sebelumnya: ");
    PrintTgl(D);

    NextDate(&D);
    NextDate(&D);
    printf("Tanggal selanjutnya: ");
    PrintTgl(D);
  }

  printf("\n");

  return 0;
}