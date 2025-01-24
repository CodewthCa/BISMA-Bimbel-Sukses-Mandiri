
typedef enum{True = 1, False = 0} Boolean;

void login();

void login() {
    char key;
    Boolean found;
    found = False;
    /* ALGORITHM */
    InterfaceTampilanAwal();
    KeyLoginKeluar(&value);
    if (value == 1) {
        InterfaceInputUserPass();
        showcursor();
        GoScanString(10,22,inputUsername);
        GoScanString(10,27,inputPassword);
        if (strcmp(inputUsername,"b") == 0 && strcmp(inputPassword, "b") == 0) {
            found = True;
        } else if (strcmp(inputUsername,"DummyAdmin") == 0 && strcmp(inputPassword, "DummyAdmin") == 0) {
            found = True;
        }
        if (found == True) {
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
                    default: system("cls"); break;
                }
            }
        }
    }
}