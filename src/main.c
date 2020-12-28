#include <gint/display.h>
#include <gint/keyboard.h>
#include <openlibm.h>

#define PI 3.14159265359

void draw_circle(int x_centre, int y_centre, int rayon, int color) {
	//bresenham
    int x, y, m;
    x = 0;
    y = rayon;
    m = 5 - 4*rayon;
    while(x<=y) {
    	dpixel(x+x_centre, y+y_centre, color);
    	dpixel(y+x_centre, x+y_centre, color);
    	dpixel(-x+x_centre, y+y_centre, color);
    	dpixel(-y+x_centre, x+y_centre, color);
    	dpixel(x+x_centre, -y+y_centre, color);
    	dpixel(y+x_centre, -x+y_centre, color);
    	dpixel(-x+x_centre, -y+y_centre, color);
    	dpixel(-y+x_centre, -x+y_centre, color);
    	if(m>0) {
    		y--;
    		m=m-8*y;
    	}
    	x++;
    	m=m+8*x+4;
    }
}

int main(void)
{
	dclear(C_BLACK);

	int nbPoint = 10;
	int rayon = 40;

	int width = DWIDTH/2;
	int height = DHEIGHT/2;

	int facteur = 2;
	draw_circle(width,height,rayon, C_WHITE);

	for(int i = 0; i < nbPoint; i++) {
		double angle = 2 * PI * i / nbPoint;
		int x = rayon * cos(angle);
		int y = rayon * sin(angle);
		dpixel(x+width, y+height, C_RED);
	}

	for(int i = 0; i < nbPoint; i++) {
		int link = (i*facteur)%nbPoint;
		dprint(10, i*15, C_RED, "%d : %d", i, link);
	}
	
	dupdate();
	getkey();
	return 1;
}
