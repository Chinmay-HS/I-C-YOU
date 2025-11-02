//Implement Cohen Sutherland Line Clipping Algorithm.
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

int computeOutCode(float x, float y, float xMin, float yMin, float xMax, float yMax)
{
    int code = INSIDE;

    if (x < xMin)
        code |= LEFT;
    else if (x > xMax)
        code |= RIGHT;

    if (y < yMin)
        code |= BOTTOM;
    else if (y > yMax)
        code |= TOP;

    return code;
}

void cohenSutherland(float x0, float y0, float x1, float y1, float xMin, float yMin, float xMax, float yMax)
{
    int outcode0 = computeOutCode(x0, y0, xMin, yMin, xMax, yMax);
    int outcode1 = computeOutCode(x1, y1, xMin, yMin, xMax, yMax);
    int accept = 0;

    while (1)
    {
        if (!(outcode0 | outcode1))
        {
            // Both endpoints inside
            accept = 1;
            break;
        }
        else if (outcode0 & outcode1)
        {
            // Both endpoints share an outside zone
            break;
        }
        else
        {
            // Some segment of line lies within the window
            int outcodeOut = outcode0 ? outcode0 : outcode1;
            float x, y;

            if (outcodeOut & TOP)
            {
                x = x0 + (x1 - x0) * (yMax - y0) / (y1 - y0);
                y = yMax;
            }
            else if (outcodeOut & BOTTOM)
            {
                x = x0 + (x1 - x0) * (yMin - y0) / (y1 - y0);
                y = yMin;
            }
            else if (outcodeOut & RIGHT)
            {
                y = y0 + (y1 - y0) * (xMax - x0) / (x1 - x0);
                x = xMax;
            }
            else if (outcodeOut & LEFT)
            {
                y = y0 + (y1 - y0) * (xMin - x0) / (x1 - x0);
                x = xMin;
            }

            if (outcodeOut == outcode0)
            {
                x0 = x;
                y0 = y;
                outcode0 = computeOutCode(x0, y0, xMin, yMin, xMax, yMax);
            }
            else
            {
                x1 = x;
                y1 = y;
                outcode1 = computeOutCode(x1, y1, xMin, yMin, xMax, yMax);
            }
        }
    }

    if (accept)
    {
        line((int)x0, (int)y0, (int)x1, (int)y1);
    }
}

int main()
{
    int gd = DETECT, gm;

    // ✅ Declare all variables at the top
    float xMin = 150, yMin = 150, xMax = 400, yMax = 400;
    float x0 = 100, y0 = 300, x1 = 500, y1 = 200;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw original line
    rectangle((int)xMin, (int)yMin, (int)xMax, (int)yMax);
    line((int)x0, (int)y0, (int)x1, (int)y1);
    outtextxy(10, 10, "Original Line (Before Clipping) - Press any key to continue");

    getch();
    cleardevice();

    // Draw clipped line
    rectangle((int)xMin, (int)yMin, (int)xMax, (int)yMax);
    cohenSutherland(x0, y0, x1, y1, xMin, yMin, xMax, yMax);
    outtextxy(10, 10, "Line After Clipping - Press any key to exit");

    getch();
    closegraph();
    return 0;
}
 