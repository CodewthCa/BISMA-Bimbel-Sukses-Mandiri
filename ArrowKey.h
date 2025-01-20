void KeyLoginKeluar(int *value);

//--------------Key Dashboard Manajer---------------

void KeyMenuDashboardManajer(int x,int y,int *opsi);

void SwitchMenuDashboardManajer(int opsi);

//--------------------------------------------------

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

void KeyMenuDashboardManajer(int x,int y, int *opsi) {
    /* DECALRATION */
    char key;
    *opsi = 1;
    /* ALGORITHM */
    gotoxy(30,15); printf("%d",*opsi);
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
        gotoxy(30,15); printf("%d",*opsi);
    }
    SwitchMenuDashboardManajer(*opsi);
}

void SwitchMenuDashboardManajer(int opsi) {
    /*  DECALRATION */

    /* ALGORITHM */
    switch(opsi) {
        case 1:
            ClearArea(26,11,105,34);
        gotoprinttext(25,20,"Hello");
        break;
            default: printf("Menu Invalid");
}
}