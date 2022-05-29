#include "..\include\graphics.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int x = 100, y = 100;
void drawline(char c)
{
    switch (c)
    {
    case 'a':
        line(x - 5, y + 5, x - 5, y + 25); // a
        break;
    case 'b':
        line(x, y, x + 20, y); // b
        break;
    case 'c':
        line(x + 25, y + 5, x + 25, y + 25); // c
        break;
    case 'd':
        line(x + 25, y + 35, x + 25, y + 55); // d
        break;
    case 'e':
        line(x, y + 60, x + 20, y + 60); // e
        break;
    case 'f':
        line(x - 5, y + 35, x - 5, y + 55); // f
        break;
    case 'g':
        line(x, y + 30, x + 20, y + 30); // g
        break;
    default:
        break;
    }
}

void setColArr(int *arr, int num)
{
    int i;
    switch (num)
    {
    case 0:
        for (i = 0; i < 7; i++)
        {
            if (i == 6)
                arr[i] = 0;
            else
                arr[i] = 15;
        }
        break;
    case 1:
        for (i = 0; i < 7; i++)
        {
            if (i == 3 || i == 2)
                arr[i] = 15;
            else
                arr[i] = 0;
        }
        break;
    case 2:
        for (i = 0; i < 7; i++)
        {
            if (i == 0 || i == 3)
                arr[i] = 0;
            else
                arr[i] = 15;
        }
        break;
    case 3:
        for (i = 0; i < 7; i++)
        {
            if (i == 0 || i == 5)
                arr[i] = 0;
            else
                arr[i] = 15;
        }
        break;
    case 4:
        for (i = 0; i < 7; i++)
        {
            if (i == 1 || i == 4 || i == 5)
                arr[i] = 0;
            else
                arr[i] = 15;
        }
        break;
    case 5:
        for (i = 0; i < 7; i++)
        {
            if (i == 2 || i == 5)
                arr[i] = 0;
            else
                arr[i] = 15;
        }
        break;
    case 6:
        for (i = 0; i < 7; i++)
        {
            if (i == 2)
                arr[i] = 0;
            else
                arr[i] = 15;
        }
        break;
    case 7:
        for (i = 0; i < 7; i++)
        {
            if (i == 1 || i == 2 || i == 3)
                arr[i] = 15;
            else
                arr[i] = 0;
        }
        break;
    case 8:
        for (i = 0; i < 7; i++)
            arr[i] = 15;
        break;
    case 9:
        for (i = 0; i < 7; i++)
        {
            if (i == 5)
                arr[i] = 0;
            else
                arr[i] = 15;
        }
        break;
    default:
        break;
    }
}
int main()
{
    int *colArr = new int[7];
    initwindow(400, 400);
    int c = 'a';
    int digit[4] = {1, 2, 3, 4};
    for (int j = 0; j < 4; j++)
    {
        // int temp = 3;
        for (int i = 0; i < 7; i++)
        {
            setColArr(colArr, digit[j]);
            setcolor(colArr[i]);
            drawline(c++);
        }
        setcolor(15);
        x += 50;
        c = 'a';
    }
    getch();
}