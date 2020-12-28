#include <gint/display.h>
#include <gint/keyboard.h>

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
    draw_circle(100,100,15, C_WHITE);
	dupdate();
	getkey();
	return 1;
}
