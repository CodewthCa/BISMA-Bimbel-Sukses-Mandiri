//------------------Login--------------------

void InterfaceTampilanAwal();

void BorderScreen(); //BorderLayar

void BorderFirstLogin(int x,int y);

void BorderKeyLoginKeluar(int x,int y);

void BorderKeyLoginKeluarClear(int x,int y);

//----------Input Username & Password--------

void InterfaceInputUserPass();

void BorderTema();

void BorderInput();

//----------Dashboard Menu Awal---------

void InterfaceDashboardMenuAwal();

void DashboardMenuKiridanKanan();

void HiasanDashboardKanan();

void BorderButtonMenu(int x, int y);

void BorderButtonMenuClear(int x, int y);

void InterfaceCRUD(int x, int y);

void IconSwitchCRUD(int x,int y);

void IconSwitchCRUDClear(int x,int y);

void BorderValidasiTambahData(int x, int y);

//----------Menu Data Manajer-------------

void InterfaceMenuManajer();

void MenuPilihanManajer();

//----------------------------------------

void InterfaceTampilanAwal() {
    hideCursor();
    BorderScreen();
    DrawFile(74,5,"../AsciiArt/Fleurdelis.txt");
    BorderFirstLogin(48,34);
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
    SetColorBlock(10,15);
    DrawFile(54,13,"../AsciiArt/LogoMenuManajer.txt");
}

void BorderScreen() {
    SetColorBlock(2,15);
    //Border Atas
    gotoprintchar(2,1,201);
    for (i = 3;i < 190;i++) {
        gotoprintchar(i,1,205);
    }
    //Border Kiri
    for (i = 2;i < 53;i++) {
        gotoprintchar(2,i,186);
    }
    gotoprintchar(2,53,200);
    //Border Bawah
    for (i = 3; i < 190; i++) {
        gotoprintchar(i,53,205);
    }
    gotoprintchar(190,53,188);
    //Border Kanan
    for (i = 2; i < 53; i++) {
        gotoprintchar(190,i,186);
    }
    gotoprintchar(190,1,187);
}

void BorderTema() {
    SetColorBlock(10,15);
    // Border Atas
    for (i = 4;i < 188;i++) {
        gotoprintchar(i,2,178);
    }
    // Border Kiri
    for (i= 2; i < 10;i++) {
        gotoprintchar(4,i,178);
    }
    // Border Bawah
    for (i = 4; i < 189; i++) {
        gotoprintchar(i, 10, 178);
    }
    // Border Kanan
    for (i = 2; i < 10;i++) {
        gotoprintchar(188,i,178);
    }
    DrawFile(5,3,"../AsciiArt/DekorasiKiriBorderTema.txt");
    DrawFile(145,3,"../AsciiArt/DekorasiKananBorderTema.txt");
    SetColorBlock(2,15);
    DrawFile(78,4,"../AsciiArt/LogoBisma.txt");
}

void BorderInput() {
    //Border Atas & Bawah
    SetColorBlock(10,15);
    for (i = 4;i < 60;i++) {
        gotoprintchar(i,12,178);    // border atas
        gotoprintchar(i,44,178);    // border bawah
    }
    //Border Kiri & Kanan
    for (i = 13;i < 44;i++) {
        gotoprintchar(5,i,178);     // border kiri
        gotoprintchar(58, i, 178);  // border kanan
    }
    /*  Border Input Username dan Password */
    gotoprinttext(28,20, "USERNAME");
    for (i = 8;i < 54;i++) {
        gotoprintchar(8,21,218);    // Kiri Atas
        gotoprintchar(8,22,179);    // Tengah Kiri
        gotoprintchar(8,23,192);    // Kiri Bawah
        gotoprintchar(i,21,196);    // Atas
        gotoprintchar(i,23,196);    // Bawah
        gotoprintchar(54,21,191);   // Kanan Atas
        gotoprintchar(54,22,179);   // Tengah Kanan
        gotoprintchar(54,23,217);   // Kanan Bawah
    }
    // Border Password
    gotoprinttext(28,25, "PASSWORD");
    for(i = 8; i < 54; i++) {
        gotoprintchar(i, 26, 196);      //border atas
        gotoprintchar(i, 28, 196);      //border bawah
        gotoprintchar(8, 27, 179);      //border kiri
        gotoprintchar(54, 27, 179);     //border kanan
        gotoprintchar(8, 26, 218);      //pojok kiri atas
        gotoprintchar(8, 28, 192);      //pojok kiri bawah
        gotoprintchar(54, 26, 191);     //pojok kanan atas
        gotoprintchar(54, 28, 217);     //pojok kanan bawah
    }
}

void BorderFirstLogin(int x, int y) {
    //Border Atas & Bawah
    for (i = 1;i < 101;i++) {
        gotoprintchar(x+i,y,205);
        gotoprintchar(x+i,y+12,205);
        gotoprintchar(x,y,206);
        gotoprintchar(x,y+12,206);
    }
    //Border Kiri & Kanan
    for (i = 1;i < 12;i++) {
        gotoprintchar(x,y+i,186);
        gotoprintchar(x+101,y+i,186);
        gotoprintchar(x+101,y,206);
        gotoprintchar(x+101,y+12,206);
    }
    //Interface dan Dekorasi
    DrawFile(x+14,y+3,"../AsciiArt/LogoLogin.txt");
    DrawFile(x+52,y+3,"../AsciiArt/LogoKeluar.txt");
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
    for (i = 11;i < 53;i++) {
        gotoprintchar(4,i,178);     //Batas Kiri
        gotoprintchar(28,i,178);    //Batas Kanan
    }
    for (i = 4;i < 28;i++) {
        gotoprintchar(i,52,178);    //Batas Bawah
    }
    SetColorBlock(2,10);
    for (i = 11;i < 52;i++) {
        for (j = 5;j < 28;j++) {
            gotoprintchar(j,i,' '); //Fill Warna Dashboard
        }
    }
    //Dashboard Kanan
    SetColorBlock(10,15);
    for (i = 11;i < 53;i++) {
        gotoprintchar(163,i,178);     //Batas Kiri
        gotoprintchar(188,i,178);    //Batas Kanan
    }
    for (i = 164;i < 188;i++) {
        gotoprintchar(i,52,178);    //Batas Bawah
    }
    SetColorBlock(2,10);
    for (i = 11;i < 52;i++) {
        for (j = 164;j < 188;j++) {
            gotoprintchar(j,i,' '); //Fill Warna Dashboard
        }
    }
    HiasanDashboardKanan();
    SetColorBlock(10,15);
}

void HiasanDashboardKanan() {
    SetColorBlock(15,10);
    DrawFile(167,12,"../AsciiArt/Celtic.txt");
    DrawFile(167,34,"../AsciiArt/Celtic.txt");
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

void InterfaceCRUD(int x , int y) {
    gotoprinttext(x,y,"C R U D  M E N U");
    gotoprinttext(x,y+3,"[1] TAMBAH DATA");
    gotoprinttext(x,y+5,"[2] LIHAT DATA");
    gotoprinttext(x,y+7,"[3] UBAH DATA");
    gotoprinttext(x,y+9,"[4] HAPUS DATA");
    gotoprinttext(x,y+11,"[5] KEMBALI");
}

void IconSwitchCRUD(int x, int y) {
    SetColorBlock(0,10);
    gotoprintchar(x,y,175);
    gotoprintchar(x+19,y,174);
}

void IconSwitchCRUDClear(int x, int y) {
    SetColorBlock(15,10);
    gotoprintchar(x,y,' ');
    gotoprintchar(x+19,y,' ');
}

void BorderValidasiTambahData(int x, int y) {
    SetColorBlock(10,15);
    for (i = 1;i < 60;i++) {
        gotoprintchar(x,y,206);
        gotoprintchar(x+i,y,205);
        gotoprintchar(x+59,y,206);
        gotoprintchar(x,y+7,206);
        gotoprintchar(x+i,y+7,205);
        gotoprintchar(x+59,y+7,206);
    }
    for (i = 1;i < 7;i++) {
        gotoprintchar(x,y+i,186);
        gotoprintchar(x+59,y+i,186);
    }
}

void MenuPilihanManajer(){
    SetColorBlock(15,10);
    gotoprinttext(13,12,"D A T A");
    gotoprinttext(9,13,"K A R Y A W A N");

    gotoprinttext(9,15,"D A T A M A T A");
    gotoprinttext(8,16,"P E L A J A R A N");

    gotoprinttext(13,18,"D A T A");
    gotoprinttext(12,19,"P A K E T");

    gotoprinttext(13,21,"D A T A");
    gotoprinttext(13,22,"B U K U");

    gotoprinttext(13,24,"D A T A");
    gotoprinttext(11,25,"D I S K O N");

    gotoprinttext(10,27,"L A P O R A N");
    gotoprinttext(8,28,"T R A N S A K S I");

    gotoprinttext(13,30,"E X I T");
    gotoprinttext(13,31 ,"M E N U");
}
