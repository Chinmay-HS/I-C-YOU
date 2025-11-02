#include <stdio.h>
#include <math.h>
#include <graphics.h>
#define round(val) ((int)(val+0.5))

void line_dda(int xa, int ya, int xb, int yb) {
	int Dx = xb - xa, Dy = yb - ya, steps, k;
	float xin, yin, X = xa, Y = ya;
	steps = (abs(Dx) > abs (Dy)) ? abs(Dx) : abs(Dy);

	xin = Dx / (float) steps;
	yin = Dy / (float) steps;

	for ( k = 0; k < steps; k++) {
		putpixel(round(X), round(Y), 13);
		X = X + xin;
		Y = Y + yin;
	}
}
int main(){
	int gd = DETECT, gm;
	int xa, xb, ya, yb;
	printf("Enter two values: ");
	scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
	initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");
	cleardevice();
	line_dda(xa, ya, xb, yb);
	getch();
	closegraph();
	return 0;
}
