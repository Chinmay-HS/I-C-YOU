// 9. Implement Area area-filling algorithms on triangles and rectangles: Boundary Fill.
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void boundaryFill(int x, int y, int fillColor, int boundaryColor)
{
    int currentColor = getpixel(x, y);
    if (currentColor != boundaryColor && currentColor != fillColor)
    {
	putpixel(x, y, fillColor);
	boundaryFill(x + 1, y, fillColor, boundaryColor);
	boundaryFill(x - 1, y, fillColor, boundaryColor);
	boundaryFill(x, y + 1, fillColor, boundaryColor);
	boundaryFill(x, y - 1, fillColor, boundaryColor);
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
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    cleardevice();
    drawRectangle(100, 100, 150, 150);
    // floodfill(150, 150, WHITE);

    int x, y;
    int boundfill_x = 111, boundfill_y = 111;

    printf("Boundary Fill\n");

    boundaryFill(boundfill_x, boundfill_y, RED, WHITE);

    drawTriangle(200, 200, 150, 250, 250, 250);
    boundaryFill(200, 201, RED, WHITE);

    getch();
    closegraph();
    return 0;
}
