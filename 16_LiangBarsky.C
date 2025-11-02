#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void drawLine(int x1, int y1, int x2, int y2, int color)
{
    setcolor(color);
    line(x1, y1, x2, y2);
}

void liangBarsky(int x0, int y0, int x1, int y1, int xMin, int yMin, int xMax, int yMax)
{
    float p[4], q[4];
    float r1 = 0.0, r2 = 1.0;
    int i;  //  declare loop variable here
    int xClipped0, yClipped0, xClipped1, yClipped1;
    float r;

    p[0] = -(x1 - x0);
    p[1] = x1 - x0;
    p[2] = -(y1 - y0);
    p[3] = y1 - y0;

    q[0] = x0 - xMin;
    q[1] = xMax - x0;
    q[2] = y0 - yMin;
    q[3] = yMax - y0;

    for (i = 0; i < 4; i++)   //  now valid
    {
        if (p[i] == 0)
        {
            if (q[i] < 0)
            {
                return;
            }
        }
        else
        {
            r = q[i] / p[i];   //  already declared at top
            if (p[i] < 0)
            {
                if (r > r2)
                {
                    return;
                }
                else if (r > r1)
                {
                    r1 = r;
                }
            }
            else
            {
                if (r < r1)
                {
                    return;
                }
                else if (r < r2)
                {
                    r2 = r;
                }
            }
        }
    }

    xClipped0 = (int)(x0 + r1 * (x1 - x0));
    yClipped0 = (int)(y0 + r1 * (y1 - y0));
    xClipped1 = (int)(x0 + r2 * (x1 - x0));
    yClipped1 = (int)(y0 + r2 * (y1 - y0));
    drawLine(xClipped0, yClipped0, xClipped1, yClipped1, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    int xMin, yMin, xMax, yMax;
    int x0, y0, x1, y1;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    xMin = 100;
    yMin = 100;
    xMax = 400;
    yMax = 300;

    // Draw the clipping window
    drawLine(xMin, yMin, xMax, yMin, GREEN);
    drawLine(xMax, yMin, xMax, yMax, GREEN);
    drawLine(xMax, yMax, xMin, yMax, GREEN);
    drawLine(xMin, yMax, xMin, yMin, GREEN);

    printf("Enter the coordinates of the line (x0 y0 x1 y1): ");
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);

    // Draw the original line
    drawLine(x0, y0, x1, y1, RED);

    outtextxy(50, 50, "Before Clipping");
    getch();
    cleardevice();

    outtextxy(50, 50, "After Clipping");

    drawLine(xMin, yMin, xMax, yMin, GREEN);
    drawLine(xMax, yMin, xMax, yMax, GREEN);
    drawLine(xMax, yMax, xMin, yMax, GREEN);
    drawLine(xMin, yMax, xMin, yMin, GREEN);

    liangBarsky(x0, y0, x1, y1, xMin, yMin, xMax, yMax);

    getch();
    closegraph();
    return 0;
}
