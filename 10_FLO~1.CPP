#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void floodFill(int x, int y, int fillColor, int backgroundColor)
{
    int currentColor = getpixel(x, y);
    if (currentColor == backgroundColor)
    {
	putpixel(x, y, fillColor);
	floodFill(x + 1, y, fillColor, backgroundColor);
	floodFill(x - 1, y, fillColor, backgroundColor);
	floodFill(x, y + 1, fillColor, backgroundColor);
	floodFill(x, y - 1, fillColor, backgroundColor);
    }
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void drawRectangle(int x1, int y1, int x2, int y2)
{
    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    cleardevice();

    drawTriangle(200, 200, 150, 250, 250, 250);
    delay(1000);
    floodFill(200, 201, RED, BLACK);

    drawRectangle(100, 100, 150, 150);
    delay(1000);
    floodFill(111, 111, RED, BLACK);

    getch();
    closegraph();
    return 0;
}
