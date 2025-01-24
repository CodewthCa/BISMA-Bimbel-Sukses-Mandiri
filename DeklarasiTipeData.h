//Ascii tombol enter,tab,backspace,esc
#define ENTER 13
#define TAB 9
#define BCKSPC 8
#define ESC 27

//Ascii keyboard atas dan bawah
#define UP_KEY 72
#define DWN_KEY 80
#define RGHT_KEY 77
#define LEFT_KEY 75

int i;
int j;
int opsi;
int value;

//enum untuk status aktif dan tidak aktif
typedef enum{AKTIF = 1, TIDAKAKTIF = 0} Status;

typedef struct {
    int id;
    char nama[30];
    char nomor[14];
    char jabatan[10];
    float gaji;
    char username[10];
    char password[10];
    Status status;
}Karyawan;

char inputUsername[10];
char inputPassword[10];