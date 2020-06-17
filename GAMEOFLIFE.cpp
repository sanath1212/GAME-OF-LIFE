#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
    char iniplane[100][100];
    char fineplane[100][100];
    int bredth;
    int length;
    int c;

    bredth = 20;
    length = 25;

    srand(time(0));

    for (int i = 0; i < bredth; i++)
    {
        for (int j = 0; j < length; j++)
        {
            fineplane[i][j] = rand() % 2;
            if (fineplane[i][j] == 1)
            {
                fineplane[i][j] = '#';
            }
        }
    }

    do
    {
        system("cls");

        for (int i = 0; i < bredth; i++)
        {
            for (int j = 0; j < length; j++)
            {
                iniplane[i][j] = fineplane[i][j];
                if (iniplane[i][j] == '#')
                {
                    c = 0;
                    if (iniplane[i - 1][j - 1] == '#')
                        c = c + 1;
                    if (iniplane[i][j - 1] == '#')
                        c = c + 1;
                    if (iniplane[i + 1][j - 1] == '#')
                        c = c + 1;
                    if (iniplane[i - 1][j] == '#')
                        c = c + 1;
                    if (iniplane[i + 1][j] == '#')
                        c = c + 1;
                    if (iniplane[i - 1][j + 1] == '#')
                        c = c + 1;
                    if (iniplane[i][j + 1] == '#')
                        c = c + 1;
                    if (iniplane[i + 1][j + 1] == '#')
                        c = c + 1;

                    if (c > 3)
                        fineplane[i][j] = 0;
                    if (c < 2)
                        fineplane[i][j] = 0;
                    if (c == 3 || c == 2)
                        fineplane[i][j] = '#';
                }

                if (iniplane[i][j] == 0)
                {
                    c = 0;
                    if (iniplane[i - 1][j - 1] == '#')
                        c = c + 1;
                    if (iniplane[i][j - 1] == '#')
                        c = c + 1;
                    if (iniplane[i + 1][j - 1] == '#')
                        c = c + 1;
                    if (iniplane[i - 1][j] == '#')
                        c = c + 1;
                    if (iniplane[i + 1][j] == '#')
                        c = c + 1;
                    if (iniplane[i - 1][j + 1] == '#')
                        c = c + 1;
                    if (iniplane[i][j + 1] == '#')
                        c = c + 1;
                    if (iniplane[i + 1][j + 1] == '#')
                        c = c + 1;

                    if (c == 3)
                        fineplane[i][j] = '#';
                }
            }
        }

        for (int i = 0; i < bredth; i++)
        {
            for (int j = 0; j < length; j++)
            {
                cout << fineplane[i][j] << " ";
            }
            cout << endl;
        }

    } while (c != -1);

    getch();
    return 0;
}
