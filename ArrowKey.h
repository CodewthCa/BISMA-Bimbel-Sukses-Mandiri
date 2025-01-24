void KeyLoginKeluar(int *value);

void SwitchMenuCRUD(int x,int y, int *opsi);

//--------------Key Dashboard Manajer---------------

void KeyMenuDashboardManajer(int x,int y,int *opsi);

//--------------------------------------------------

void KeyLoginKeluar(int *value) {
    /* DECLARATION */
    char key;
    *value = 1;
    /* ALGORITHM */
    hideCursor();
    BorderKeyLoginKeluar(55,36);
    while(1) {
        key = getch();
        if(key == LEFT_KEY) {
            BorderKeyLoginKeluarClear(97, 36);
            BorderKeyLoginKeluar(55,36);
            *value = 1;
        } else if(key == RGHT_KEY) {
            BorderKeyLoginKeluarClear(55, 36);
            BorderKeyLoginKeluar(97,36);
            *value = 0;
        }
        if (key == ENTER) {
            ClearArea(3, 2, 186, 50);
            break;
        }
    }
}

void KeyMenuDashboardManajer(int x,int y, int *opsi) {
    /* DECALRATION */
    char key;
    *opsi = 1;
    /* ALGORITHM */
    hideCursor();
    BorderButtonMenu(x,y);
    while(1) {
        key = getch();
        if (key == UP_KEY) {
            *opsi-=1;
            if(*opsi < 1) {
                *opsi+=1;
                y = y + 3;
            }
            y = y - 3;
            BorderButtonMenuClear(x,y+3);
            BorderButtonMenu(x,y);
        } else if(key == DWN_KEY) {
            *opsi+=1;
            if(*opsi >  7) {
                *opsi-=1;
                y = y - 3;
            }
            y = y + 3;
            BorderButtonMenuClear(x,y-3);
            BorderButtonMenu(x,y);
        }
        if (key == ENTER) {
            break;
        }
    }
}

void SwitchMenuCRUD(int x, int y,int *opsi) {
    /* DECALRATION */
    char key;
    *opsi = 1;
    /* ALGORITHM */
    hideCursor();
    while(1) {
        IconSwitchCRUD(x,y);
        key = getch();
        if (key == UP_KEY) {
            *opsi-=1;
            if(*opsi < 1) {
                *opsi+=1;
                y = y + 2;
            }
            y = y - 2;
            IconSwitchCRUDClear(x,y+2);
            IconSwitchCRUD(x,y);
        } else if(key == DWN_KEY) {
            *opsi+=1;
            if(*opsi >  5) {
                *opsi-=1;
                y = y - 2;
            }
            y = y + 2;
            IconSwitchCRUDClear(x,y-2);
            IconSwitchCRUD(x,y);
        }
        if (key == ENTER) {
            IconSwitchCRUDClear(x,y);
            break;
        }
    }
}