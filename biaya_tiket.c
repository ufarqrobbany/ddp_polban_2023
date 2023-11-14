#include <stdio.h>
#include <windows.h>

int total;

int Tiket(int usia)
{
  int harga = 0;
  if ((usia >= 4) && (usia <= 12))
  {
    harga = 25000;
  }
  else if (usia > 12)
  {
    harga = 35000;
  }
  return harga;
}

void akumulasiBiaya(int jmlPengunjung, int usiaPengunjung[100], int *total)
{
  *total = 0;
  int i;
  i = 0;
  while (i < jmlPengunjung)
  {
    *total = *total + Tiket(usiaPengunjung[i]);
    i++;
  }
}

int main()
{
  system("cls");
  printf("\033[0m");

  int i, jmlPengunjung, usiaPengunjung[100];

  printf("Masukkan jumlah pengunjung (maksimal 100): \033[0;35m");
  scanf("%d", &jmlPengunjung);
  printf("\033[0m");

  if (jmlPengunjung > 0 && jmlPengunjung <= 100)
  {
    printf("Masukkan usia setiap pengunjung (dipisah dengan spasi): ");

    i = 0;
    while (i < jmlPengunjung)
    {
      printf("\033[0;35m");
      scanf("%d", &usiaPengunjung[i]);
      printf("\033[0m");
      i++;
    }
  }

  printf("\033[1;33m===============================================================\033[0m \n");
  printf("Jumlah pengunjung : \033[0;35m%d\033[0m \n", jmlPengunjung);
  if (jmlPengunjung > 0 && jmlPengunjung <= 100)
  {
    printf("Usia setiap pengunjung : ");
    i = 0;
    while (i < jmlPengunjung)
    {
      if (i != jmlPengunjung - 1)
      {
        printf("\033[0;35m%d\033[0m, ", usiaPengunjung[i]);
      }
      else
      {
        printf("\033[0;35m%d\033[0m", usiaPengunjung[i]);
      }
      i++;
    }
  }

  akumulasiBiaya(jmlPengunjung, usiaPengunjung, &total);
  printf("\nTotal Biaya: \033[1;35mRp%d\033[0m", total);
  return 0;
}