#include "..\include\graphics.h"
#include <math.h>

int globalwindow = initwindow(1350, 680, "MiniPaint");
char maintext[][15] = {" Line ", " Circle ", " Polygon ", " Freehand ", " Erase ", " Fill ", " Save & Quit "};

void normalvideo(int x, int y, char *c);
void reversevideo(int x, int y, char *c);
void showColorPallette(int Pane, int current);
int colorPane();
void showlines(int window, int current);
int setline();
void menu();
void call(int i);

void drawline();
void drawcircle();
void drawPolygon();
void freehand();
void erase();
void fill();

int main()
{
    int i = 0;
    while (!kbhit())
    {
        try
        {
            menu();
        }
        catch (int i)
        {
            writeimagefile();
            break;
        }
    }
    getch();
    return 0;
}

void normalvideo(int x, int y, char *c)
{
    setbkcolor(BLUE);
    setcolor(WHITE);
    outtextxy(x + 5, y, c);
}

void reversevideo(int x, int y, char *c)
{
    setbkcolor(WHITE);
    setcolor(BLUE);
    outtextxy(x + 5, y, c);
    setcolor(WHITE);
}

void menu()
{
    int i = 0;
    settextstyle(3, 0, 3);
    setcolor(15);

    int width = getmaxx() - 20;
    int height = 30;

    rectangle(10, 10, getmaxx() - 10, 40);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(15, 15, 15);

    int tabs = 7;
    for (int i = 1; i < tabs; i++)
    {
        line(10 + i * width * 1.0 / tabs, 10, 10 + i * width * 1.0 / tabs, 10 + height);
        normalvideo(10 + width * i * 1.0 / tabs + 5, 15, maintext[i]);
    }
    reversevideo(15, 15, maintext[0]);
    int done = 0;
    do
    {
        switch (getch())
        {
        case 00:
            switch (getch())
            {
            case 75:
                normalvideo(10 + width * i * 1.0 / tabs + 5, 15, maintext[i]);
                --i;
                if (i == -1)
                {
                    i = tabs - 1;
                }
                reversevideo(10 + width * i * 1.0 / tabs + 5, 15, maintext[i]);
                break;
            case 77:
                normalvideo(10 + width * i * 1.0 / tabs + 5, 15, maintext[i]);
                ++i;
                if (i == tabs)
                {
                    i = 0;
                }
                reversevideo(10 + width * i * 1.0 / tabs + 5, 15, maintext[i]);
                break;
            }
            done = 0;
            break;
        case 13:
            done = 1;
        }
    } while (done != 1);
    call(i);
}

void call(int i)
{
    if (i == 0)
        drawline();
    else if (i == 1)
        drawcircle();
    else if (i == 2)
        drawPolygon();
    else if (i == 3)
        freehand();
    else if (i == 4)
        erase();
    else if (i == 5)
        fill();
    else if (i == 6)
        throw -1;
    else
        return;
}

void showlines(int window, int current)
{
    setcurrentwindow(window);
    clearviewport();
    int a = 100, b = 20;
    int i = 0;
    for (i = 0; i <= 6; i++)
    {
        setlinestyle(SOLID_LINE, SOLID_FILL, i);
        if (i == current)
            line(a - 10, b, a + 110, b);
        else
            line(a, b, a + 100, b);
        b += 20;
    }
}

int setline()
{
    int linewindow = initwindow(400, 200, "Lines");
    showlines(linewindow, 0);
    int i = 0, done = 0;
    do
    {
        switch (getch())
        {
        case 00:
            switch (getch())
            {
            case 72:
                i--;
                if (i == -1)
                    i = 6;
                break;
            case 80:
                i++;
                if (i == 7)
                    i = 0;
                break;
            }
            showlines(linewindow, i);
            done = 0;
            break;
        case 13:
            done = 1;
        }
    } while (done != 1);
    setcurrentwindow(globalwindow);
    closegraph(linewindow);
    return i;
}

void showColorPallette(int Pane, int current)
{
    setcurrentwindow(Pane);
    clearviewport();
    int a = getmaxx() / 2;
    int b = getmaxy() / 2;
    double deg1, deg2 = 0;
    for (int i = 0; i <= 15; i++)
    {
        setfillstyle(SOLID_FILL, i);
        deg1 = deg2;
        deg2 += 22.5;
        if (i == current)
            sector(a, b, deg1, deg2, 120, 120);
        else
            sector(a, b, deg1, deg2, 100, 100);

        setcolor(0);
        setfillstyle(SOLID_FILL, 0);
        fillellipse(a, b, 75, 75);

        setcolor(15);
        circle(a, b, 75);
    }
    setfillstyle(SOLID_FILL, current);
    fillellipse(a, b, 25, 25);
}

int colorPane()
{
    int colorpane = initwindow(300, 300, "Colors");
    showColorPallette(colorpane, 0);
    int i = 0, done = 0;
    do
    {
        switch (getch())
        {
        case 00:
            switch (getch())
            {
            case 75:
                i--;
                if (i == -1)
                    i = 15;
                showColorPallette(colorpane, i);
                break;
            case 77:
                i++;
                if (i == 16)
                    i = 0;
                showColorPallette(colorpane, i);
            }
            done = 0;
            break;
        case 13:
            done = 1;
        }
    } while (done != 1);
    setcurrentwindow(globalwindow);
    closegraph(colorpane);
    return i;
}

void drawline()
{
    setlinestyle(SOLID_LINE, SOLID_FILL, setline());
    double x[2];
    double y[2];
    int i = 0;
    do
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int a1, a2;
            getmouseclick(WM_LBUTTONDOWN, a1, a2);
            circle(a1, a2, 1);
            x[i] = a1;
            y[i] = a2;
            i++;
        }
    } while (i != 2);
    line(x[0], y[0], x[1], y[1]);
    setlinestyle(SOLID_LINE, SOLID_FILL, 1);
}

void drawcircle()
{
    double x1, y1;
    double r;
    int a1, a2;

    while (!ismouseclick(WM_LBUTTONDOWN))
    {
    }
    getmouseclick(WM_LBUTTONDOWN, a1, a2);

    circle(a1, a2, 1);
    x1 = a1;
    y1 = a2;

    while (!ismouseclick(WM_LBUTTONDOWN))
    {
    }
    getmouseclick(WM_LBUTTONDOWN, a1, a2);
    r = ((x1 - a1) * (x1 - a1)) + ((y1 - a2) * (y1 - a2));

    r = sqrt(r);
    circle(x1, y1, r);
}

void drawPolygon()
{
    int n = 30, i = 0;
    int *x, *y;
    x = new int[n + 1];
    y = new int[n + 1];
    do
    {
        while (ismouseclick(WM_LBUTTONDOWN))
        {
            int a1, a2;
            getmouseclick(WM_LBUTTONDOWN, a1, a2);
            x[i] = a1;
            y[i] = a2;
            circle(a1, a2, 1);
            i++;
            if (i == n)
            {
                break;
            }
        }
    } while (!ismouseclick(WM_RBUTTONDOWN));
    clearmouseclick(WM_RBUTTONDOWN);
    n = i;
    x[n] = x[0];
    y[n] = y[0];
    for (int i = 0; i < n; i++)
    {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    delete[] x;
    delete[] y;
    return;
}
void freehand()
{
    do
    {
        do
        {
            if (ismouseclick(WM_LBUTTONDOWN))
                circle(mousex(), mousey(), 5);
            if (ismouseclick(WM_RBUTTONDOWN))
                break;
        } while (!ismouseclick(WM_LBUTTONUP));
        clearmouseclick(WM_LBUTTONUP);
        clearmouseclick(WM_LBUTTONDOWN);
    } while (!ismouseclick(WM_RBUTTONDOWN));

    clearmouseclick(WM_RBUTTONDOWN);
    clearmouseclick(WM_LBUTTONUP);
    return;
}

void erase()
{
    int r = 10;
    while (true)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))
        {
            if (kbhit())
            {
                int m = getch();
                if (m == 43)
                    r += 3;
                else if (m == 45)
                    r -= 3;
                else if (m == 27)
                    return;
            }
        }
        int a1, a2;
        getmouseclick(WM_LBUTTONDOWN, a1, a2);
        setcolor(0);
        setfillstyle(SOLID_FILL, 0);
        fillellipse(a1, a2, r, r);
        setcolor(15);
    }
}

void fill()
{
    int color = colorPane();
    while (!ismouseclick(WM_LBUTTONDOWN))
    {
    }
    int a1, a2;
    getmouseclick(WM_LBUTTONDOWN, a1, a2);
    setfillstyle(SOLID_FILL, color);
    floodfill(a1, a2, 15);
}
