
void TambahDataKaryawan(FILE *MyKaryawan,string FileName);
void LihatDataKaryawan(FILE *MyKaryawan, string FileName);
void UbahDataKaryawan(FILE *MyKaryawan, string FileName);
void HapusDataKaryawan(FILE *MyKaryawan, string FileName);

int PenggajianKaryawan(char jabatan[]);

void MenuKaryawan();

void MenuKaryawan(){
    /* DECLARATION */
    FILE *MyKaryawan;
    string FileName;
    int menu;
    /* ALGORITHM */
    strcpy(FileName,"dataCRUDKaryawan.dat");
    IconSwitchCRUD(166,28);
    do {
        SetColorBlock(10,15);
        DrawFile(54,13,"../AsciiArt/LogoMenuManajer.txt");
        SetColorBlock(15,10);
        InterfaceCRUD(168,25);
        SwitchMenuCRUD(166,28, &menu);
        switch (menu) {
            case 1: TambahDataKaryawan(MyKaryawan, FileName);
                ClearArea(30,11,133,42);
                SetColorBlock(10,15);
                break;
            case 2: LihatDataKaryawan(MyKaryawan, FileName);
                ClearArea(30,11,133,42);
                SetColorBlock(10,15);
                break;
            case 3: UbahDataKaryawan(MyKaryawan, FileName); break;
            case 4: HapusDataKaryawan(MyKaryawan, FileName); break;
            case 5: break;
            default: printf("\n Input Invalid"); break;
        }
    } while (menu != 5);
}

void TambahDataKaryawan(FILE *MyKaryawan, string FileName) {
    /* DECLARATION */
    Karyawan karyawan;
    int opsi;
    int pilihan;
    /* ALGORITHM */
    /*MyKaryawan = fopen(FileName, "wb");
    fclose(MyKaryawan);*/
    showcursor();
    BorderValidasiTambahData(68,40);
    SetColorBlock(6,15);
    gotoprinttext(76,42,"Apakah anda yakin ingin menambah data? (Y/N)");
    gotoprinttext(96, 45,"(   )");
    gotoxy(98,45); scanf("%d", &opsi); fflush(stdin);
    do{
        if (opsi == 1) {
            ClearArea(30,11,133,42);    // ClearTampilanTengah
            SetColorBlock(10,15);
            DrawFile(67,12,"../AsciiArt/TambahData.txt");
            MyKaryawan = fopen(FileName, "rb");
                karyawan.id = 1;
                while (fread(&karyawan, sizeof(karyawan), 1, MyKaryawan)==1) {
                    ++karyawan.id;
                }
                fclose(MyKaryawan);
                MyKaryawan = fopen(FileName, "ab");
                karyawan.status = AKTIF;
                do {
                    SetColorBlock(10,15);
                    gotoprinttext(70,20,"Nama\t\t : "); scanf("%[^\n]", &karyawan.nama); fflush(stdin);
                    gotoprinttext(70,22,"Nomor\t\t : "); scanf("%[^\n]", &karyawan.nomor); fflush(stdin);
                    gotoprinttext(70,24,"Jabatan\t\t : "); scanf("%[^\n]", &karyawan.jabatan); fflush(stdin);
                    if (karyawan.jabatan != NULL) {
                        switch (PenggajianKaryawan(karyawan.jabatan)) {
                            case 1:
                                karyawan.gaji = 9000000;
                            break;
                            case 2:
                                karyawan.gaji = 6000000;
                            break;
                            case 3:
                                karyawan.gaji = 5000000;
                            break;
                            default:
                                karyawan.gaji = 0;
                        }
                    } else {
                        karyawan.gaji = 0; // Jika jabatan tidak ada
                    }
                    gotoprinttext(70,26,"Gaji\t\t : "); gotoxy(91,26); printf("%.2f", karyawan.gaji);
                    gotoprinttext(70,28,"Username\t\t : "); scanf("%[^\n]", &karyawan.username); fflush(stdin);
                    gotoprinttext(70,30,"Password\t\t : "); scanf("%[^\n]", &karyawan.password); fflush(stdin);
                    BorderValidasiTambahData(68,40);
                    SetColorBlock(6,15);
                    gotoprinttext(76,42,"Apakah anda yakin ingin menyimpan data? (Y/N)");
                    gotoprinttext(96, 45,"(   )");
                    gotoxy(98,45); scanf("%d", &pilihan); fflush(stdin);
                    if (pilihan == 1) {
                        fwrite(&karyawan, sizeof(karyawan), 1, MyKaryawan);
                        break;
                    } else if (pilihan == 0) {
                        ClearArea(67,20,40,12);
                        continue;
                    }
                } while (1);
                fclose(MyKaryawan);
        } else {
            printf("Invalid Opsi\n");
        }
        break;
    } while (1);
}

void LihatDataKaryawan(FILE *MyKaryawan,string FileName) {
    /* DECLARATION */
    Karyawan karyawan;
    int baris = 21;
    char key;
    /* ALGORITHM */
    MyKaryawan = fopen(FileName, "rb");
    ClearArea(30,11,133,42);
    SetColorBlock(15,2);
    gotoxy(40,18); printf("+-------+------------------------------------+---------------------+---------------------------+-----------------+");
    gotoxy(40, 19);printf("|   ID  |          NAMA KARYAWAN             |       NO KONTAK     |          JABATAN          |        GAJI     |");
    gotoxy(40, 20);printf("+-------+------------------------------------+---------------------+---------------------------+-----------------+");
    do {
        SetColorBlock(10,15);
        DrawFile(67,12,"../AsciiArt/LihatData.txt");
        SetColorBlock(15,2);
        while (fread(&karyawan, sizeof(Karyawan), 1, MyKaryawan) == 1) {
            if (karyawan.status == AKTIF) { // Hanya tampilkan karyawan aktif
                gotoxy(40, baris++);
                printf("| %5d | %-28s       | %-8s        | %-18s        | %9.2f      |",
                       karyawan.id,
                       karyawan.nama,
                       karyawan.nomor,
                       karyawan.jabatan,
                       karyawan.gaji);
            }
        }
        key = getch();
        if (key == ENTER) { //Sementara hanya seperti ini
            break;
        }
    } while (1);
    fclose(MyKaryawan);
}

void UbahDataKaryawan(FILE *MyKaryawan, string FileName) {
    /* DECLARATION */
    Karyawan karyawan;
    FILE *tempfile;
    int found;          //boolean
    int idTarget;
    int opsi;
    /* ALGORITHM */
    MyKaryawan = fopen(FileName, "rb");
    tempfile = fopen("tempFile.dat", "wb");
    printf("Id data yang ingin diubah : "); scanf("%d", &idTarget); fflush(stdin);
    found = 0; //False
    while (!found && !feof(MyKaryawan)) {
        fread(&karyawan, sizeof(karyawan), 1, MyKaryawan);
        if (karyawan.id == idTarget) {
            found = 1;  //True
        } else if (feof(MyKaryawan)) {
            printf("Id yang dicari tidak ada di Database!!\n");
        } else {
            fwrite(&karyawan, sizeof(karyawan), 1, tempfile);
        }
    }
    if (found) {
        do{
            printf("\nData yang ingin diubah\n");
            printf("[1] Nama\n");
            printf("[2] Nomor\n");
            printf("[3] Jabatan\n");
            printf("[4] Username\n");
            printf("[5] Password\n");
            printf("[0] Keluar\n");
            printf("Pilih Menu :"); scanf("%d", &opsi); fflush(stdin);
            switch (opsi) {
                case 1:
                    printf("\nMasukan nama baru : ");
                scanf("%[^\n]", &karyawan.nama); fflush(stdin);
                printf("Nama berhasil diperbaharui!\n"); break;

                case 2:
                    printf("\nMasukan Nomor Baru : ");
                scanf("%[^\n]", &karyawan.nomor); fflush(stdin);
                printf("Nomor Berhasil diperbaharui!\n"); break;

                case 3:
                    printf("\nMasukan Jabatan Baru : ");
                scanf("%[^\n]", &karyawan.jabatan); fflush(stdin);
                if (karyawan.jabatan != NULL) {
                    switch (PenggajianKaryawan(karyawan.jabatan)) {
                        case 1:
                            karyawan.gaji = 1000000;
                        break;
                        case 2:
                            karyawan.gaji = 750000;
                        break;
                        case 3:
                            karyawan.gaji = 500000;
                        break;
                        default:
                            karyawan.gaji = 0;
                    }
                } else {
                    karyawan.gaji = 0; // Jika jabatan tidak ada
                }
                printf("Stok berhasil diperbaharui!\n"); break;

                case 4:
                    printf("\nMasukan Username Baru : ");
                scanf("%[^\n]", &karyawan.username); fflush(stdin);
                printf("Username berhasil diperbaharui!\n"); break;
                case 5:
                    printf("\nMasukan Password Baru : ");
                scanf("%[^\n]", &karyawan.password); fflush(stdin);
                printf("Password berhasil diperbaharui!\n"); break;
                case 0:
                    printf("\nUbah Data Selesai");
                default: printf("Pilih Menu Invalid\n");
            }
        } while (opsi != 0);
        fwrite(&karyawan, sizeof(karyawan), 1, tempfile);
        printf("Data berhasil diperbaharui1\n");
        while (fread(&karyawan, sizeof(karyawan), 1, MyKaryawan) == 1) {
            fwrite(&karyawan, sizeof(karyawan), 1, tempfile);
        }
    }
    fclose(tempfile);
    fclose(MyKaryawan);
    tempfile = fopen("tempFile.dat", "rb");
    MyKaryawan = fopen(FileName, "wb");
    while (fread(&karyawan, sizeof(karyawan), 1, tempfile) == 1) {
        fwrite(&karyawan, sizeof(karyawan), 1, MyKaryawan);
    }
    fclose(tempfile);
    fclose(MyKaryawan);
}

void HapusDataKaryawan(FILE *MyKaryawan, string FileName) {
    Karyawan karyawan;
    FILE *tempfile;
    int found;
    int idTarget;

    int opsi;
    /* ALGORITHM */
    MyKaryawan = fopen(FileName, "rb");
    tempfile = fopen("tempFile.dat", "wb");
    printf("Id data yang ingin dihapus : "); scanf("%d", &idTarget); fflush(stdin);
    found = 0;
    while (!found && !feof(MyKaryawan)) {
        fread(&karyawan, sizeof(karyawan), 1, MyKaryawan);
        if (karyawan.id == idTarget) {
            found = 1;
        } else if (feof(MyKaryawan)) {
            printf("Id yang dicari tidak ada di Database!!\n");
        } else {
            fwrite(&karyawan, sizeof(karyawan), 1, tempfile);
        }
    }
    if (found) {
        karyawan.status = TIDAKAKTIF;
        fwrite(&karyawan, sizeof(karyawan), 1, tempfile);
    }
    while (fread(&karyawan, sizeof(karyawan), 1, MyKaryawan) == 1) {
        fwrite(&karyawan, sizeof(karyawan), 1, tempfile);
    }
    fclose(tempfile);
    fclose(MyKaryawan);
    tempfile = fopen("tempFile.dat", "rb");
    MyKaryawan = fopen(FileName, "wb");
    while (fread(&karyawan, sizeof(karyawan), 1, tempfile) == 1) {
        fwrite(&karyawan, sizeof(karyawan), 1, MyKaryawan);
    }
    fclose(tempfile);
    fclose(MyKaryawan);
}

int PenggajianKaryawan(char jabatan[]) {
    if (strcmp(jabatan, "Manajer") == 0) return 1;
    if (strcmp(jabatan, "Admin") == 0) return 2;
    if (strcmp(jabatan, "Pengajar") == 0) return 3;
    return 0; // Default jika tidak cocok
}