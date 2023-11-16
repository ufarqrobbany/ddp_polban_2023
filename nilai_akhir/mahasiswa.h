// Deklarasi tipe data bentukan bernama Mahasiswa
typedef struct
{
  const char *nama;
  const char *nim;
  float ets;
  float eas;
  float kuis;
  float total;
  const char *predikat;
} Mahasiswa;

// Deklarasi prosedur dan fungsi
void displayDataMhs(Mahasiswa mhs);
float get_total(float nilaiEts, float nilaiEas, float nilaiKuis);
const char *get_predicate(float total);

// Deklarasi konstanta global: bobot ets, eas, dan kuis
const float BOBOT_ETS = 0.35;
const float BOBOT_EAS = 0.40;
const float BOBOT_KUIS = 0.25;