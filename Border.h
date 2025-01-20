//------------------Login--------------------

void InterfaceTampilanAwal();

void BorderScreen(); //BorderLayar

void BorderFirstLogin();

void BorderKeyLoginKeluar(int x,int y);

void BorderKeyLoginKeluarClear(int x,int y);

//----------Input Username & Password--------

void InterfaceInputUserPass();

void BorderTema();

void BorderInput();

//----------Dashboard Menu   Awal---------

void InterfaceDashboardMenuAwal();

void DashboardMenuKiridanKanan();

void BorderButtonMenu(int x, int y);

void BorderButtonMenuClear(int x, int y);

//----------Menu Data Manajer-------------

void InterfaceMenuManajer();

void MenuPilihanManajer();

//----------------------------------------

void InterfaceTampilanAwal() {
    hideCursor();
    BorderScreen();
    BorderFirstLogin();
}

void InterfaceInputUserPass() {
    BorderTema();
    BorderInput();
    DrawFile(75,15,"../AsciiArt/LogoBuku.txt");
}

void InterfaceDashboardMenuAwal() {
    DashboardMenuKiridanKanan();
}

void InterfaceMenuManajer() {
    MenuPilihanManajer();
}

void BorderScreen() {
    SetColorBlock(2,15);
    //Border Atas
    gotoprintchar(1,1,201);
    for (i = 2;i < 154;i++) {
        gotoprintchar(i,1,205);
    }
    //Border Kiri
    for (i = 2;i < 45;i++) {
        gotoprintchar(1,i,186);
    }
    gotoprintchar(1,45,200);
    //Border Bawah
    for (i = 2; i < 154; i++) {
        gotoprintchar(i,45,205);
    }
    gotoprintchar(154,45,188);
    //Border Kanan
    for (i = 2; i < 45; i++) {
        gotoprintchar(154,i,186);
    }
    gotoprintchar(154,1,187);
}

void BorderTema() {
    SetColorBlock(10,15);
    // Border Atas
    for (i = 3;i < 153;i++) {
        gotoprintchar(i,2,178);
    }
    // Border Kiri
    for (i= 2; i < 10;i++) {
        gotoprintchar(3,i,178);
    }
    // Border Bawah
    for (i = 3; i < 153; i++) {
        gotoprintchar(i, 10, 178);
    }
    // Border Kanan
    for (i = 2; i < 10;i++) {
        gotoprintchar(152,i,178);
    }
    DrawFile(4,3,"../AsciiArt/DekorasiKiriBorderTema.txt");
    DrawFile(110,3,"../AsciiArt/DekorasiKananBorderTema.txt");
    DrawFile(60,4,"../AsciiArt/LogoBisma.txt");
}

void BorderInput() {
    //Border Atas & Bawah
    for (i = 3;i < 59;i++) {
        gotoprintchar(i,12,178);    // border atas
        gotoprintchar(i,44,178);    // border bawah
    }
    //Border Kiri & Kanan
    for (i = 13;i < 44;i++) {
        gotoprintchar(3,i,178);     // border kiri
        gotoprintchar(58, i, 178);  // border kanan
    }
    /*  Border Input Username dan Password */
    gotoprinttext(27,20, "USERNAME");
    for (i = 8;i < 53;i++) {
        gotoprintchar(7,21,218);    // Kiri Atas
        gotoprintchar(7,22,179);    // Tengah Kiri
        gotoprintchar(7,23,192);    // Kiri Bawah
        gotoprintchar(i,21,196);    // Atas
        gotoprintchar(i,23,196);    // Bawah
        gotoprintchar(53,21,191);   // Kanan Atas
        gotoprintchar(53,22,179);   // Tengah Kanan
        gotoprintchar(53,23,217);   // Kanan Bawah
    }
    // Border Password
    gotoprinttext(27,25, "PASSWORD");
    for(i = 8; i < 53; i++) {
        gotoprintchar(i, 26, 196);      //border atas
        gotoprintchar(i, 28, 196);      //border bawah
        gotoprintchar(7, 27, 179);      //border kiri
        gotoprintchar(53, 27, 179);     //border kanan
        gotoprintchar(7, 26, 218);      //pojok kiri atas
        gotoprintchar(7, 28, 192);      //pojok kiri bawah
        gotoprintchar(53, 26, 191);     //pojok kanan atas
        gotoprintchar(53, 28, 217);     //pojok kanan bawah
    }
}

void BorderFirstLogin() {
    //Border Atas & Bawah
    for (i = 49;i < 103;i++) {
        gotoprintchar(i,8,178);
        gotoprintchar(i,36,178);
    }
    //Border Kiri & Kanan
    for (i = 9;i < 36;i++) {
        gotoprintchar(50,i,178);
        gotoprintchar(101,i,178);
    }
    //Interface dan Dekorasi
    DrawFile(62,15,"../AsciiArt/LogoLogin.txt");
    DrawFile(58,24,"../AsciiArt/LogoKeluar.txt");
    DrawFile(12,5,"../AsciiArt/LogoPensil.txt");
}

void BorderKeyLoginKeluar(int x,int y) {
    for (i = 1;i < 41;i++) {
        gotoprintchar(x,y,201);
        gotoprintchar(x,y+7,200);
        gotoprintchar(x+i,y,205);
        gotoprintchar(x+i,y+7,205);
        gotoprintchar(x+41,y,187);
        gotoprintchar(x+41,y+7,188);
    }
    for (i = 1; i < 7;i++) {
        gotoprintchar(x,y+i,186);
        gotoprintchar(x+41,y+i,186);
    }
}

void BorderKeyLoginKeluarClear(int x,int y) {
    for (i = 1;i < 41;i++) {
        gotoprintchar(x,y,' ');
        gotoprintchar(x,y+7,' ');
        gotoprintchar(x+i,y,' ');
        gotoprintchar(x+i,y+7,' ');
        gotoprintchar(x+41,y,' ');
        gotoprintchar(x+41,y+7,' ');
    }
    for (i = 1; i < 7;i++) {
        gotoprintchar(x,y+i,' ');
        gotoprintchar(x+41,y+i,' ');
    }
}

void DashboardMenuKiridanKanan() {
    //Dashboard Kiri
    for (i = 11;i < 45;i++) {
        gotoprintchar(3,i,178); //Batas Kiri
        gotoprintchar(25,i,178);      //Batas Kanan
    }
    for (i = 4;i < 25;i++) {
        gotoprintchar(i,44,178); //Batas Atas
    }
    SetColorBlock(2,10);
    for (i = 11;i < 44;i++) {
        for (j = 4;j < 25;j++) {
            gotoprintchar(j,i,' '); //Fill Warna Dashboard
        }
    }
    //Dashboard Kanan
    SetColorBlock(10,15);
    for (i = 11;i < 45;i++) {
        gotoprintchar(131,i,178);    //Batas Kiri
        gotoprintchar(152,i,178);    //Batas Kanan
    }
    for (i = 132;i < 152;i++) {
        gotoprintchar(i,44,178);    //Batas Atas
    }
    SetColorBlock(2,10);
    for (i = 11;i < 44;i++) {
        for (j = 132;j < 152;j++) {
            gotoprintchar(j,i,' '); //Fill Warna Dashboard
        }
    }
    SetColorBlock(10,15);
    DrawFile(38,15,"../AsciiArt/LogoMenuManajer.txt");
}

void BorderButtonMenu(int x, int y) {
    SetColorBlock(15,10);
    for (i = 1;i < 20;i++) {
        gotoprintchar(x,y,201);
        gotoprintchar(x,y+1,186);
        gotoprintchar(x,y+2,186);
        gotoprintchar(x,y+3,200);
        gotoprintchar(x+i,y,205);
        gotoprintchar(x+i,y+3,205);
        gotoprintchar(x+20,y,187);
        gotoprintchar(x+20,y+1,186);
        gotoprintchar(x+20,y+2,186);
        gotoprintchar(x+20,y+3,188);
    }
}

void BorderButtonMenuClear(int x,int y    ) {
    SetColorBlock(15,10);
    for (i = 1;i < 20;i++) {
        gotoprintchar(x,y,' ');
        gotoprintchar(x,y+1,' ');
        gotoprintchar(x,y+2,' ');
        gotoprintchar(x,y+3,' ');
        gotoprintchar(x+i,y,' ');
        gotoprintchar(x+i,y+3,' ');
        gotoprintchar(x+20,y,' ');
        gotoprintchar(x+20,y+1,' ');
        gotoprintchar(x+20,y+2,' ');
        gotoprintchar(x+20,y+3,' ');
    }
}

void MenuPilihanManajer() {
    SetColorBlock(15,10);
    gotoprinttext(11,12,"D A T A");
    gotoprinttext(7,13,"K A R Y A W A N");

    gotoprinttext(7,15,"D A T A M A T A");
    gotoprinttext(6,16,"P E L A J A R A N");

    gotoprinttext(11,18,"D A T A");
    gotoprinttext(10,19,"P A K E T");

    gotoprinttext(11,21,"D A T A");
    gotoprinttext(11,22,"B U K U");

    gotoprinttext(11,24,"D A T A");
    gotoprinttext(9,25,"D I S K O N");

    gotoprinttext(8,27,"L A P O R A N");
    gotoprinttext(6,28,"T R A N S A K S I");

    gotoprinttext(11,30,"E X I T");
    gotoprinttext(11,31 ,"M E N U");
}