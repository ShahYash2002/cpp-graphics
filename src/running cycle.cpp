#include "..\include\graphics.h"
#include <math.h>

int xCircle1 = 150, yCircle1 = 450, xCircle2 = xCircle1 + 450, yCircle2 = yCircle1, theta = 0;

void DrawCycle()
{

    circle(xCircle1, yCircle1, 90);
    circle(xCircle1, yCircle1, 100);
    fillellipse(xCircle1, yCircle1, 10, 10);

    circle(xCircle2, yCircle2, 90);
    circle(xCircle2, yCircle2, 100);
    fillellipse(xCircle2, yCircle2, 10, 10);

    circle(xCircle1 + 240, yCircle1, 30);
    fillellipse(xCircle1 + 240, yCircle1, 5, 5);

    arc(xCircle1, yCircle1, 30, 150, 120);
    arc(xCircle2, yCircle2, 45, 180, 120);

    int temp = theta;
    int count = 0;
    while (count != 6)
    {
        line(xCircle1, yCircle1, 90 * cos(theta * 3.14 / 180) + xCircle1, 90 * sin(theta * 3.14 / 180) + yCircle1);
        line(xCircle2, yCircle2, 90 * cos(theta * 3.14 / 180) + xCircle2, 90 * sin(theta * 3.14 / 180) + yCircle2);
        theta += 60;
        if (theta > 360)
            theta -= 360;
        count++;
    }
    theta = temp;
    temp += 360;
    temp--;
    if (temp == 0)
        temp = 360;
    line(30 * cos((temp + 360) * 3.14 / 180) + xCircle1 + 240, yCircle1 + 30 * sin((temp + 360) * 3.14 / 180), 60 * cos((temp + 360) * 3.14 / 180) + xCircle1 + 240, yCircle1 + 60 * sin((temp + 360) * 3.14 / 180));
    line(xCircle1 + 240, yCircle1, 60 * cos((temp + 180) * 3.14 / 180) + xCircle1 + 240, yCircle1 + 60 * sin((temp + 180) * 3.14 / 180));

    ellipse(60 * cos((theta + 180) * 3.14 / 180) + xCircle1 + 240, yCircle1 + 60 * sin((theta + 180) * 3.14 / 180), 0, 360, 10, 7);
    ellipse(60 * cos(theta * 3.14 / 180) + xCircle1 + 240, yCircle1 + 60 * sin(theta * 3.14 / 180), 0, 360, 10, 7);

    line(xCircle1, yCircle1 - 10, xCircle1 + 240, yCircle1 - 30);
    line(xCircle1, yCircle1 + 10, xCircle1 + 240, yCircle1 + 30);

    double height = 150;
    double xJoint1, yJoint1, xJoint2, yJoint2;
    double deg1 = 50 * 3.14 / 180, deg2 = 45 * 3.14 / 180;

    xJoint1 = xCircle1 + (height / sin(deg1)) * cos(deg1);
    yJoint1 = yCircle1 - height;

    xJoint2 = xCircle2 - (height / sin(deg2)) * cos(deg2);
    yJoint2 = yCircle1 - height;

    line(xCircle1, yCircle1, xJoint1, yJoint1);
    line(xCircle1 + 450, yCircle1, xJoint2, yJoint2);
    line(xJoint2, yJoint2, xCircle2 - 270 * cos(deg2), yCircle1 - 270 * sin(deg2));
    arc(xCircle2 - 300 * cos(deg2), yCircle1 - 300 * sin(deg2), 240, 30, 30);
    int x = xCircle2 - 300 * cos(deg2), y = yCircle1 - 300 * sin(deg2);
    line(x + 30 * cos(30 * 3.14 / 180), y - 30 * sin(3.14 * 30 / 180), x + 30 * cos(30 * 3.14 / 180) + 20, y - 30 * sin(3.14 * 30 / 180) - 10);
    line(x + 30 * cos(240 * 3.14 / 180), y - 30 * sin(3.14 * 240 / 180), x + 30 * cos(240 * 3.14 / 180) - 10, y - 30 * sin(3.14 * 240 / 180) + 20);

    line(xJoint1, yJoint1, xJoint2, yJoint2);
    line(xCircle1 + 240, yCircle1, xJoint1, yJoint1);
    line(xCircle1 + 240, yCircle1, xJoint2, yJoint2);
    line(xJoint1, yJoint1, xJoint1 - 150, yJoint1);
    line(xJoint1 - 150, yJoint1, xJoint1 - 150, yJoint1 - 20);
    line(xJoint1 - 150, yJoint1, xCircle1, yCircle1);
    line(xJoint1 - 180, yJoint1 - 20, xJoint1 - 110, yJoint1 - 20);
    arc(xJoint1 - 180, yJoint1 - 40, 180, 270, 20);

    line(xJoint2, yJoint2, xJoint2 + 20, yJoint2);
    ellipse(xJoint2 + 22, yJoint2, 0, 360, 2, 8);

    line(xJoint1, yJoint1, xJoint1, yJoint1 - 25);
    rectangle(xJoint1 - 40, yJoint1 - 45, xJoint1 + 40, yJoint1 - 25);

    fillellipse(xJoint1, yJoint1, 10, 10);
    fillellipse(xJoint2, yJoint2, 10, 10);

    return;
}
int main()
{
    initwindow(1300, 650);
    line(50, 550, 1250, 550);

    for (int i = 0; i < 300; i++)
    {
        setcolor(WHITE);
        DrawCycle();

        delay(5);
        setcolor(BLACK);
        DrawCycle();

        xCircle1++;
        xCircle2++;
        if (theta++ == 360)
            theta = 0;
    }
    setcolor(WHITE);
    DrawCycle();

    getch();
    return 0;
}
