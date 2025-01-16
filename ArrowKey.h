
void KeyLoginKeluar(int *value);

void KeyLoginKeluar(int *value) {
    /* DECLARATION */
    char key;
    /* ALGORITHM */
    hideCursor();
    while(1) {
        key = getch();
        if(key == UP_KEY) {
            BorderKeyLoginKeluarClear(55,23);
            BorderKeyLoginKeluar(55,14);
            key = getch();
            if(key == ENTER) {
                ClearArea(2,2,152,43);
                *value = 1;
                break;
            }
        } else if(key == DWN_KEY) {
            BorderKeyLoginKeluarClear(55,14);
            BorderKeyLoginKeluar(55,23);
            key = getch();
            if(key == ENTER) {
                *value = 0;
                break;
            }
        }
    }
}