#include <stdio.h>
#include <graphics.h>
#include <dos.h>

void drawline( int x0, int y0, int x1, int y1)
{
	int dx, dy, p, x, y;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;

	p = 2 * dy - dx;

	while (x <= x1)
	{
		putpixel(x,y, WHITE);
		delay(30);

		if ( p >= 0)
		{
			y = y + 1;
			p = p + 2 * dy - 2 * dy;
		}
		else
		{
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}

int main()
{
	int gdriver = DETECT, gmode;
	int x0, y0, x1, y1;

	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	printf("Enter the coordinates of the first point: ");
	scanf("%d%d", &x0, &y0);

	printf("Enter coordinates of second point: ");
	scanf("%d%d", &x1, &y1);

	drawline(x0, y0, x1, y1);

	getch();
	closegraph();

	return 0;
}