
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
        if (strcmp(inputUsername,"DummyManajer") == 0 && strcmp(inputPassword, "DummyManajer") == 0) {
            found = True;
        } else if (strcmp(inputUsername,"DummyAdmin") == 0 && strcmp(inputPassword, "DummyAdmin") == 0) {
            found = True;
        }
        if (found == True) {
            system("cls");
            InterfaceTampilanAwal();
        }
    }
}