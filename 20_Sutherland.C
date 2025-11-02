// Implement Sutherland Hodgeman polygon clipping algorithm.
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define MAX_POINTS 20

typedef struct
{
    int x, y;
} Point;

Point clipWindow[4];

int inside(Point p, int edge)
{
    switch (edge)
    {
    case 0: return p.y >= clipWindow[0].y; // bottom
    case 1: return p.y <= clipWindow[2].y; // top
    case 2: return p.x <= clipWindow[2].x; // right
    case 3: return p.x >= clipWindow[0].x; // left
    }
    return 0;
}

Point intersect(Point p1, Point p2, int edge)
{
    Point p;
    float m;

    if (p1.x != p2.x)
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);
    else
        m = 1e5; // large slope for vertical line

    switch (edge)
    {
    case 0: // bottom
        p.x = p1.x + (clipWindow[0].y - p1.y) / m;
        p.y = clipWindow[0].y;
        break;
    case 1: // top
        p.x = p1.x + (clipWindow[2].y - p1.y) / m;
        p.y = clipWindow[2].y;
        break;
    case 2: // right
        p.y = p1.y + m * (clipWindow[2].x - p1.x);
        p.x = clipWindow[2].x;
        break;
    case 3: // left
        p.y = p1.y + m * (clipWindow[0].x - p1.x);
        p.x = clipWindow[0].x;
        break;
    }
    return p;
}

void clipPolygon(Point polyPoints[], int *polySize, int edge)
{
    Point newPoints[MAX_POINTS];
    int newCount = 0;
    int i; 

    for (i = 0; i < *polySize; i++)
    {
        Point curr = polyPoints[i];
        Point next = polyPoints[(i + 1) % *polySize];

        if (inside(curr, edge) && inside(next, edge))
        {
            newPoints[newCount++] = next;
        }
        else if (inside(curr, edge) && !inside(next, edge))
        {
            newPoints[newCount++] = intersect(curr, next, edge);
        }
        else if (!inside(curr, edge) && inside(next, edge))
        {
            newPoints[newCount++] = intersect(curr, next, edge);
            newPoints[newCount++] = next;
        }
    }

    *polySize = newCount;
    for (i = 0; i < newCount; i++)
        polyPoints[i] = newPoints[i];
}

void sutherlandHodgmanPolygonClip(Point polyPoints[], int *polySize)
{
    int edge;
    for (edge = 0; edge < 4; edge++)
        clipPolygon(polyPoints, polySize, edge);
}

int main()
{
    int gd = DETECT, gm;
    Point polyPoints[MAX_POINTS];
    int polySize;
    int i; 

    initgraph(&gd, &gm, "C://TURBOC3//BGI");

    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &polySize);

    for (i = 0; i < polySize; i++)
    {
        printf("Enter x%d and y%d: ", i, i);
        scanf("%d %d", &polyPoints[i].x, &polyPoints[i].y);
    }

    // Define rectangular clipping window
    clipWindow[0].x = 150; clipWindow[0].y = 150;
    clipWindow[1].x = 150; clipWindow[1].y = 300;
    clipWindow[2].x = 300; clipWindow[2].y = 300;
    clipWindow[3].x = 300; clipWindow[3].y = 150;

    // Draw original polygon
    for (i = 0; i < polySize - 1; i++)
        line(polyPoints[i].x, polyPoints[i].y, polyPoints[i + 1].x, polyPoints[i + 1].y);
    line(polyPoints[polySize - 1].x, polyPoints[polySize - 1].y, polyPoints[0].x, polyPoints[0].y);

    // Draw clipping window
    rectangle(clipWindow[0].x, clipWindow[0].y, clipWindow[2].x, clipWindow[2].y);
    getch();

    // Clip polygon
    sutherlandHodgmanPolygonClip(polyPoints, &polySize);

    cleardevice();

    // Draw clipped polygon
    rectangle(clipWindow[0].x, clipWindow[0].y, clipWindow[2].x, clipWindow[2].y);
    for (i = 0; i < polySize - 1; i++)
        line(polyPoints[i].x, polyPoints[i].y, polyPoints[i + 1].x, polyPoints[i + 1].y);
    line(polyPoints[polySize - 1].x, polyPoints[polySize - 1].y, polyPoints[0].x, polyPoints[0].y);

    getch();
    closegraph();
    return 0;
}
