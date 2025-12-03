#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
void clear_screen_fast() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(h, pos);
}

int main() {
	system("color 4F");
	PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC | SND_LOOP);
    srand(time(0));

    int x = 3;              
    int step = 1;           
    int obstaclePos = rand() % 3;   

    while (1) {
        if (_kbhit()) {
            char ch = getch();

            if (ch == 75 && x > 0)        
                x--;

            if (ch == 77 && x < 2)        
                x++;
        }
		clear_screen_fast();
        printf("|--- --- ---|\n");

        for (int i = 0; i < 10; i++) {
            if (i == step) {

                if (obstaclePos == 0)
                    printf("| %c        |\n", 1);

                else if (obstaclePos == 1)
                    printf("|     %c    |\n", 1);

                else if (obstaclePos == 2)
                    printf("|        %c |\n", 1);

            } else {
                printf("|           |\n");
            }
        }
        if (x == 0)
            printf("| %c         |\n", 6);
        else if (x == 1)
            printf("|     %c     |\n", 6);
        else if (x == 2)
            printf("|        %c  |\n", 6);

        if (step == 10 && x == obstaclePos) {
        	PlaySound(NULL, NULL, 0);  
			PlaySound(TEXT("impact.wav"), NULL, SND_ASYNC);
        	Sleep(2500);
            printf("\nGAME OVER!\n");
            break;
        }

        Sleep(120);
        step++
        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3;
        }
    }

    return 0;
}
