// 18. Implement Bezier Curve to generate a crescent moon shape.
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void drawBezierCurve(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, int type)
{
    float t;
    for (t = 0; t <= 1; t += 0.001)
    {
        float x, y;
        if (type == 2)
        {
            x = (1 - t) * (1 - t) * x0 + 2 * (1 - t) * t * x1 + t * t * x2;
            y = (1 - t) * (1 - t) * y0 + 2 * (1 - t) * t * y1 + t * t * y2;
        }
        else
        {
            x = pow(1 - t, 3) * x0 + 3 * pow(1 - t, 2) * t * x1 + 3 * (1 - t) * t * t * x2 + t * t * t * x3;
            y = pow(1 - t, 3) * y0 + 3 * pow(1 - t, 2) * t * y1 + 3 * (1 - t) * t * t * y2 + t * t * t * y3;
        }
        putpixel((int)x, (int)y, WHITE);
    }
}

void drawScene()
{
    // Moon
    drawBezierCurve(470, 50, 550, 160, 400, 205, 370, 125, 3);
    drawBezierCurve(470, 50, 475, 105, 430, 145, 370, 125, 3);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    drawScene();
    getch();
    closegraph();
    return 0;
}