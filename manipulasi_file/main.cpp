#include <stdio.h>

void writeData(char (*nama)[100], int *umur) {
    printf("WRITE DATA\n");
    printf("Masukkan nama: ");
    scanf("%[^\n]", &(*nama));
    fflush(stdin);
    printf("Masukkan umur: ");
    scanf("%d", &(*umur));
    fflush(stdin);

    FILE *data = fopen("data.txt", "w");
    fprintf(data, "%s#%d\n", *nama, *umur);
    fclose(data);
    getchar();
}

void readData(char (*nama)[100], int *umur) {
    printf("READ DATA\n");
    FILE *data = fopen("data.txt", "r");
    if (!data) {
        printf("Tidak ada file\n");
    } else {
        while (!feof(data)) {
            fscanf(data, "%[^#]#%d\n", &(*nama), &(*umur));
            fflush(stdin);
            printf("%s %d \n", (*nama), *umur);
        }
        fclose(data);
    }
    getchar();
}

void appendData(char (*nama)[100], int *umur) {
    printf("APPEND DATA\n");
    printf("Masukkan nama: ");
    scanf("%[^\n]", &(*nama));
    fflush(stdin);
    printf("Masukkan umur: ");
    scanf("%d", &(*umur));
    fflush(stdin);

    FILE *data = fopen("data.txt", "a");
    fprintf(data, "%s#%d\n", *nama, *umur);
    fclose(data);
    getchar();
}

int main() {
    char nama[100];
    int umur;

    writeData(&nama, &umur);
    readData(&nama, &umur);

    do {
        appendData(&nama, &umur);
        readData(&nama, &umur);
    } while (true);

    return 0;
}