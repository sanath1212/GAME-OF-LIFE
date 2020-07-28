#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	int plane = 400;
	initwindow(plane, plane);
	int resolution = 60;
	int width = 10, n, m;
	int height = 10;
	n = resolution / height;
	m = resolution / width;
	int fineplane[plane][plane];
	int iniplane[plane][plane];
	int c = 0;
	
	srand(time(0));

    for (int i = 0; i < plane; i += n) {		
		for (int j = 0; j < plane; j += m) {
            fineplane[i][j] = rand() % 2;
            if (fineplane[i][j] == 1)
            {
                rectangle (i, j, i + n, j + m);
            }
        }
    }
    
   while(true) {
   	    
        for (int i = 0; i < plane; i += n) {		
			for (int j = 0; j < plane; j += m) {
                iniplane[i][j] = fineplane[i][j];
                if (iniplane[i][j] == 1)
                {
                    c = 0;
                    if (iniplane[i-n][j-m] == 1)
                        c = c + 1;
                    if (iniplane[i][j-m] == 1)
                        c = c + 1;
                    if (iniplane[i+n][j-m] == 1)
                        c = c + 1;
                    if (iniplane[i-n][j] == 1)
                        c = c + 1;
                    if (iniplane[i+n][j] == 1)
                        c = c + 1;
                    if (iniplane[i-n][j+m] == 1)
                        c = c + 1;
                    if (iniplane[i][j+m] == 1)
                        c = c + 1;
                    if (iniplane[i+n][j+m] == 1)
                        c = c + 1;

                    if (c > 3)
                        fineplane[i][j] = 0;
                    if (c < 2)
                        fineplane[i][j] = 0;
                    if (c == 3 || c == 2)
                        fineplane[i][j] = 1;
                }

                if (iniplane[i][j] == 0)
                {
                    c = 0;
                    if (iniplane[i-n][j-m] == 1)
                        c = c + 1;
                    if (iniplane[i][j-m] == 1)
                        c = c + 1;
                    if (iniplane[i+n][j-m] == 1)
                        c = c + 1;
                    if (iniplane[i-n][j] == 1)
                        c = c + 1;
                    if (iniplane[i+n][j] == 1)
                        c = c + 1;
                    if (iniplane[i-n][j+m] == 1)
                        c = c + 1;
                    if (iniplane[i][j+m] == 1)
                        c = c + 1;
                    if (iniplane[i+n][j+m] == 1)
                        c = c + 1;

                    if (c == 3)
                        fineplane[i][j] = 1;
                }
            }
        }
        delay(10);
        cleardevice();
        for (int i = 0; i < plane; i += n) {		
			for (int j = 0; j < plane; j += m) {
                if (fineplane[i][j] == 1) {
	                rectangle (i, j, i + n, j + m);
	            }
            }
		}
    }
	
getch();
return 0;
}
