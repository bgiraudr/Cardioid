#include <gint/display.h>
#include <gint/keyboard.h>
#include <openlibm.h>

#define PI 3.14159265359

void draw_circle(int x_centre, int y_centre, int rayon, int color) {
	//Cercle avec Bresenham
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
	int nbPoint = 100;
	int rayon = 90;

	float facteur = 2;

	int width = DWIDTH/2;
	int height = DHEIGHT/2;

	int boucle = 1;

	char diapo = 0;
	char mode = 0;
	while(boucle) {
		dclear(C_BLACK);
		draw_circle(width,height,rayon, C_WHITE);
		for(int i = 0; i < nbPoint; i++) {
			double angle = 2 * PI * i / nbPoint;
			//affiche les points du cercle 
			/*int x = rayon * cos(angle);
			int y = rayon * sin(angle);
			draw_circle(x+width, y+height, 3, C_RED);*/
			double link = i*facteur;
			while(link >= nbPoint) link-=nbPoint;
			double anglelink = 2 * PI * link / nbPoint;
			dline(rayon * cos(angle)+width, rayon * sin(angle)+height, rayon * cos(anglelink)+width, rayon * sin(anglelink)+height, C_WHITE);
		}
		if(!mode) dprint(1,1,C_WHITE,"Table : %.1j", (int)(facteur*10));
		else dprint(1,1,C_WHITE,"nbPoint : %d",nbPoint);
		dupdate();

		clearevents();
		if(keydown(KEY_SHIFT)) {
			diapo = 1;
		}
		if(keydown(KEY_ALPHA)) {
			diapo = 0;
		}
		if(keydown(KEY_F1)) {
			mode = 0;
		}
		if(keydown(KEY_F2)) {
			mode = 1;
		}
		if(keydown(KEY_EXIT)) {
				boucle = 0;
		}
		if(!diapo) {
			if(keydown(KEY_RIGHT)) {
				if(!mode) facteur+=0.1;
				else nbPoint++;
			} else if(keydown(KEY_LEFT)) {
				if(!mode) facteur-=0.1;
				else if(nbPoint > 10) nbPoint--;
			}
		} else {
			facteur+=0.1;
		}
	}

	return 1;
}
