#include <stdio.h>
#include <windows.h>

typedef char string[255];

void gotoxy(int x, int y);
void gotoprintchar(int x, int y, int dec);
void gotoprinttext(int x, int y, string text);
void GoScanString(int x, int y,string text);
void GoScanInt(int x, int y,int input);
void GoScanFloat(int x, int y,float input);

void DrawFile(int x, int y, string filename);
void ClearArea(int x, int y, int width, int height);
void SetColorBlock(int foreground, int background);
void fullscreen();
void disableScrollBar();
void hideCursor();
void showcursor();
void setConsoleFont(int fontSizeX, int fontSizeY, const wchar_t* fontName);

void gotoxy(int x, int y) {
    COORD coord = {0,0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void gotoprintchar(int x, int y, int dec) {
    gotoxy(x, y);
    printf("%c", dec);
}

void gotoprinttext(int x, int y, string text) {
    gotoxy(x, y);
    printf("%s", text);
}
void GoScanString(int x, int y,char text[]){
    fflush(stdin);
    gotoxy(x,y);
    scanf("%[^\n]", text);

    getchar();
}
void GoScanInt(int x, int y,int input){
    fflush(stdin);
    gotoxy(x,y);
    scanf("%d", input);
}
void GoScanFloat(int x, int y,float input) {
    fflush(stdin);
    gotoxy(x,y);
    scanf("%f", input);
}
void DrawFile(int x, int y, string filename) {
    FILE *fp;
    char str[MAXCHAR];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Tidak Bisa Membuka File %s", filename);
    }
    i = 0;
    while (fgets(str, MAXCHAR, fp) != NULL) {
        gotoxy(x, y + i);
        printf("%s", str);
        i++;
    }
    fclose(fp);
}
void ClearArea(int x, int y, int width, int height) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topleft = {(SHORT)x,(SHORT)y};
    DWORD written;

    for (int row = 0; row < height; row++) {
        FillConsoleOutputCharacter(console, ' ', width, topleft, &written);
        topleft.Y++;
    }
}
void SetColorBlock(int foreground, int background) {
    int color = foreground + (background << 4);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void fullscreen() {
    keybd_event(VK_MENU,0x39,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x39,KEYEVENTF_KEYUP,0);

    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}
void disableScrollBar() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);

    csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;

    SetConsoleScreenBufferSize(hOut, csbi.dwSize);

    SetConsoleMode(hOut, ENABLE_EXTENDED_FLAGS);
}

void setConsoleFont(int fontSizeX, int fontSizeY, const wchar_t* fontName) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);

    // Mendapatkan informasi font saat ini
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    // Mengganti ukuran font
    fontInfo.dwFontSize.X = fontSizeX;
    fontInfo.dwFontSize.Y = fontSizeY;

    // Mengganti nama font
    wcscpy(fontInfo.FaceName, fontName);

    // Mengganti bentuk font
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}

void showcursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
