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

FILE *MyKaryawan;

int i;
int value;

//enum untuk status aktif dan tidak aktif
typedef enum{AKTIF = 1, TIDAKAKTIF = 0} Status;

typedef struct Karyawan{
    int id;
    char nama[30];
    char nomor[14];
    char jabatan[10];
    char username[10];
    char password[10];
    Status status;
};

struct Karyawan karyawan;

char inputUsername[10];
char inputPassword[10];