#include <iostream>
#include <graphics.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	int cols, rows, x, y;
	int width = 500;
	int height = 500;
	int resolution;
	
	cout << "ENTER THE WIDTH AND HEIGHT: ";
	cin >> width >> height;
	cout << "ENTER THE resolution: ";
	cin >> resolution;
	
	initwindow(width + resolution, height + resolution);
	rows = height / resolution;
	cols = width / resolution;
	int fineplane[cols][rows];
	int iniplane[cols][rows];
	int c = 0;
	
	srand(time(0));

    for (int i = 0; i < cols; i++) {		
		for (int j = 0; j < rows; j++) {
            fineplane[i][j] = rand() % 2;
            if (fineplane[i][j] == 1)
            {	
            	x = i * resolution;
            	y = j * resolution;
                rectangle (x, y, x + resolution, y + resolution);
            }
        }
    }
    
   while(true) {
   		for (int i = 0; i < cols; i++)
	    {
	        for (int j = 0; j < rows; j++)
	        {
	        	iniplane[i][j] = fineplane[i][j];
	        }
	    }
	    
        for (int i = 0; i < cols; i++) {		
			for (int j = 0; j < rows; j++) {
				c = 0;
                if (iniplane[i][j] == 1)
                {
                    for (int k = -1; k <= 1; k++){
						for (int l = -1; l <= 1; l++) {
							if (iniplane[i + k][j + l] == 1)
				                c++;
						}
					}
					c--;
                    if (c > 3)
                        fineplane[i][j] = 0;
                    if (c < 2)
                        fineplane[i][j] = 0;
                    if (c == 3 || c == 2)
                        fineplane[i][j] = 1;
                }

                if (iniplane[i][j] == 0)
                {
                    for (int k = -1; k <= 1; k++){
						for (int l= -1; l <= 1; l++) {
							if (iniplane[i + k][j + l] == 1)
				                c++;
						}
					}

                    if (c == 3)
                        fineplane[i][j] = 1;
                }
            }
        }
 
        cleardevice();
        for (int i = 0; i < cols; i++) {		
			for (int j = 0; j < rows; j++) {
                if (fineplane[i][j] == 1) {
                	x = i * resolution;
            		y = j * resolution;
	                rectangle (x, y, x + resolution, y + resolution);
	            }
            }
		}
    }
	
return 0;
}
