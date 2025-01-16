#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <mmsystem.h>
#include <unistd.h>

#include "DeklarasiTipeData.h"
#include "Procedur.h"
#include "Border.h"
#include "ArrowKey.h"
#include "Login.h"

int main(void) {
    fullscreen();
    system("color F5");
    login();
    getch();
}
