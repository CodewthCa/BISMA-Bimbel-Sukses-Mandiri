typedef enum{Pengajar = 3, Admin = 2, Manajer = 1, False = 0} Boolean;

void FirstLogin();

void login();

void FirstLogin() {
    InterfaceTampilanAwal();
    KeyLoginKeluar(&value);
    login();
}

void login() {
    char key;
    Boolean found;
    found = False;
    /* ALGORITHM */

    if (value == 1) {
        hideCursor();
        InterfaceInputUserPass();
        showcursor();
        ClearArea(10,22,43,1);  // Kosongin text box
        ClearArea(10,27,43,1);  // Kosongin text box
        strcpy(inputUsername, "\0");    // Kosongin inputUsername
        strcpy(inputPassword, "\0");    // Kosongin inputPassword

        gotoxy(10,22);
        inputUser(inputUsername);   // Input Username dari Procedur.h
        gotoxy(10,27);
        inputPass(inputPassword);   // Input Password dari Procedur.h
        if (strcmp(inputUsername,"b") == 0 && strcmp(inputPassword, "b") == 0) {
            found = Manajer;
        } else if (strcmp(inputUsername,"DummyAdmin") == 0 && strcmp(inputPassword, "DummyAdmin") == 0) {
            found = Manajer;
        }
        if (found == Manajer) {
            hideCursor();
            ClearArea(4,11,184,42);
            InterfaceDashboardMenuAwal();
            while (1){
                InterfaceMenuManajer();
                KeyMenuDashboardManajer(6,11,&value);
                switch (value) {
                    case 1:
                        ClearArea(164,11,23,41);
                        MenuKaryawan();
                        ClearArea(164,11,23,41);
                        SetColorBlock(15,10);
                        HiasanDashboardKanan();
                    break;
                    case 2: //CRUD Mata Pelajaran
                        break;
                    case 3: //CRUD Paket Bimbel
                        break;
                    case 4: // CRUD Buku
                        break;
                    case 5: // CRUD Diskon
                        break;
                    case 6: // Laporan Transaksi
                        break;
                    case 7: // Exit Menu
                        ClearArea(3,11,186,42);
                        system("color F5");
                        value = 1;
                        login();
                    default: system("cls"); break;
                }
            }
        } else {
            login();
        }
    } else if (value == 0) {
        exit(0);
    }
}