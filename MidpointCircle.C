#include <stdio.h>
#include <graphics.h>

void drawCircle( int x1, int y1, int r);

int main()
{
	int gd = DETECT, gm;
	int x, y, r;

	printf("Enter the midpoint & the radius: ");
	scanf("%d%d%d", &x, &y, &r);

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


	drawCircle(x,y,r);

	getch();
	closegraph();
	return 0;
}

void drawCircle ( int x1, int y1, int r)
{
	int x = 0, y=r;
	int p = 1 -r;

	void plotPoints( int, int, int, int);

	plotPoints(x1, y1, x, y);

	while ( x < y)
	{
		x++;
		if (p < 0)
			p += 2 * x + 1;
		else
		{
			y --;
			p += 2 * ( x - y) + 1;
		}
		plotPoints ( x1, y1, x, y);
	}
}

void plotPoints ( int xctr, int yctr, int x, int y)
{
	delay(100);
	putpixel(xctr + x, yctr + y, WHITE);
	putpixel(xctr - x, yctr + y, WHITE);
	putpixel(xctr + x, yctr - y, WHITE);
	putpixel(xctr - x, yctr - y, WHITE);
	putpixel(xctr + y, yctr + x, WHITE);
	putpixel(xctr - y, yctr + x, WHITE);
	putpixel(xctr + y, yctr - x, WHITE);
	putpixel(xctr - y, yctr - x, WHITE);
}
