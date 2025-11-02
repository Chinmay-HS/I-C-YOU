// C program for 2D transformation (Reflection and Shearing) - WORKING VERSION
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void refx(int x1,int x2,int x3,int y1,int y2,int y3);
void refy(int x1,int x2,int x3,int y1,int y2,int y3);
void shearx(int x,int x1,int x2,int x3,int y,int y1,int y2,int y3,float shear_f);
void sheary(int x,int x1,int x2,int x3,int y,int y1,int y2,int y3,float shear_f);
void showMenu();

void showMenu()
{
    printf("\n=== 2D TRANSFORMATION MENU ===\n");
    printf("1. Reflection (Triangle)\n");
    printf("2. Shearing (Quadrilateral)\n");
    printf("3. Exit\n");
    printf("================================\n");
    printf("Enter your choice (1-3): ");
}

void refx(int x1,int x2,int x3,int y1,int y2,int y3)
{
    outtextxy(400,25,"Reflection along X-axis");
    x1=(320-x1)+320;
    x2=(320-x2)+320;
    x3=(320-x3)+320;
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
}

void refy(int x1,int x2,int x3,int y1,int y2,int y3)
{
    outtextxy(25,450,"Reflection along Y-axis");
    y1=(240-y1)+240;
    y2=(240-y2)+240;
    y3=(240-y3)+240;
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
}

void shearx(int x,int x1,int x2,int x3,int y,int y1,int y2,int y3,float shear_f)
{
    int nx, nx1, nx2, nx3;
    
    nx = x + (int)(y * shear_f);
    nx1 = x1 + (int)(y1 * shear_f);
    nx2 = x2 + (int)(y2 * shear_f);
    nx3 = x3 + (int)(y3 * shear_f);
    
    cleardevice();
    outtextxy(25,25,"Shearing along X-axis");
    line(nx,y,nx1,y1);
    line(nx1,y1,nx2,y2);
    line(nx2,y2,nx3,y3);
    line(nx3,y3,nx,y);
}

void sheary(int x,int x1,int x2,int x3,int y,int y1,int y2,int y3,float shear_f)
{
    int ny, ny1, ny2, ny3;
    
    ny = y + (int)(x * shear_f);
    ny1 = y1 + (int)(x1 * shear_f);
    ny2 = y2 + (int)(x2 * shear_f);
    ny3 = y3 + (int)(x3 * shear_f);
    
    cleardevice();
    outtextxy(25,25,"Shearing along Y-axis");
    line(x,ny,x1,ny1);
    line(x1,ny1,x2,ny2);
    line(x2,ny2,x3,ny3);
    line(x3,ny3,x,ny);
}

int main()
{

    int gd=DETECT, gm;

    int x,y,x1,y1,x2,y2,x3,y3,choice;
    float shear_x, shear_y;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    while(1)
    {
        showMenu();
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                printf("\nEnter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
                scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
                
                // Initialize graphics for reflection
                initgraph(&gd,&gm,"");
                
                // Draw coordinate axes
                line(320,0,320,480);  // Y-axis
                line(0,240,640,240);  // X-axis
                outtextxy(25,25,"Original Triangle");
                
                // Draw original triangle
                line(x1,y1,x2,y2);
                line(x2,y2,x3,y3);
                line(x3,y3,x1,y1);
                
                getch();
                refx(x1,x2,x3,y1,y2,y3);
                
                getch();
                refy(x1,x2,x3,y1,y2,y3);
                
                getch();
                closegraph();
                break;
                
            case 2:
                printf("\nEnter first coordinate (x y): ");
                scanf("%d %d",&x,&y);
                printf("Enter second coordinate (x y): ");
                scanf("%d %d",&x1,&y1);
                printf("Enter third coordinate (x y): ");
                scanf("%d %d",&x2,&y2);
                printf("Enter fourth coordinate (x y): ");
                scanf("%d %d",&x3,&y3);
                
                printf("Enter X-axis shearing factor: ");
                scanf("%f",&shear_x);
                printf("Enter Y-axis shearing factor: ");
                scanf("%f",&shear_y);
                
                // Initialize graphics for shearing
                initgraph(&gd,&gm,"");
                
                outtextxy(25,25,"Original Quadrilateral");
                
                // Draw original quadrilateral
                line(x,y,x1,y1);
                line(x1,y1,x2,y2);
                line(x2,y2,x3,y3);
                line(x3,y3,x,y);
                
                getch();
                
                shearx(x,x1,x2,x3,y,y1,y2,y3,shear_x);
                
                getch();
                sheary(x,x1,x2,x3,y,y1,y2,y3,shear_y);
                
                getch();
                closegraph();
                break;
                
            case 3:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
                break;
                
            default:
                printf("\nInvalid choice! Please enter 1, 2, or 3.\n");
                getch();
        }
        
        // Clear screen before showing menu again (optional)
        // system("cls");  // Uncomment for Windows
        printf("\n\nPress any key to continue...");
        getch();
    }
    
    return 0;
}