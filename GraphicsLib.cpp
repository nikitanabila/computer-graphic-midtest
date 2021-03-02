/* 
Tugas Ujian Tengah Semester
Nama			: Nikita Nabila
NIM				: 171511054
Kelas			: 3B
Program Studi	: D3 Teknik Informatika
Mata Kuliah		: Komputer Grafik
Tanggal			: 2 Desember 2019
Nama File		: GraphicsLib.cpp
*/

#include "GraphicsLib.h"

int abs(int n){
	return ((n>0) ? n : (n*(-1)));
}

void draw_line_DDA(int x1, int y1, int x2, int y2)
{ 
    // calculate dx & dy 
    int dx = x2 - x1; 
    int dy = y2 - y1; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    // Put pixel for each step 
    float X = x1; 
    float Y = y1; 
    for (int i = 0; i <= steps; i++) 
    { 
//       delay(10);

//int setcolor=rand()%15+1;
        putpixel (X,Y,15);  // put pixel at (X,Y) 
        X += Xinc;           // increment in x at each step 
        Y += Yinc;           // increment in y at each step 
    } 
} 

Point rotasi(Point p0, Point center, int degree)
{
	int x_shifted, y_shifted;
	
	x_shifted = p0.x - center.x; //center 0,0
	y_shifted = p0.y - center.y;

	p0.x = center.x + (x_shifted*COS(degree) - y_shifted*SIN(degree));
	p0.y = center.y + (x_shifted*SIN(degree) + y_shifted*COS(degree));
	
	return p0;
}

void kite(Point center, int diagonal, int degree, int  color)
{
	Layangan layang;
	
	layang.p1.x = center.x - diagonal;
	layang.p1.y = center.y;
	
	layang.p2.x = center.x;
	layang.p2.y = center.y - diagonal;
	
	layang.p3.x = center.x;
	layang.p3.y = center.y + diagonal;
	
	layang.p4.x = center.x + (2*diagonal);
	layang.p4.y = center.y;
	
//	printf ("p1 = %d %d\n p2 =%d %d\n p3=  %d %d\n p4 = %d %d\n", layang.p1.x, layang.p1.y, layang.p2.x, layang.p2.y, layang.p3.x, layang.p3.y, layang.p4.x, layang.p4.y);
	
//	delay(50);
	layang.p1 = rotasi(layang.p1, center, degree);
	layang.p2 = rotasi(layang.p2, center, degree);
	layang.p3 = rotasi(layang.p3, center, degree);
	layang.p4 = rotasi(layang.p4, center, degree);
	
	
//	setfillstyle(SOLID_FILL,color);
	
	draw_line_DDA(layang.p1.x, layang.p1.y, layang.p2.x, layang.p2.y);
	draw_line_DDA(layang.p2.x, layang.p2.y, layang.p4.x, layang.p4.y);
	draw_line_DDA(layang.p4.x, layang.p4.y, layang.p3.x, layang.p3.y);
	draw_line_DDA(layang.p3.x, layang.p3.y, layang.p1.x, layang.p1.y);
	
	
//	floodfill(center.x,center.y,15);
}

void snowflakes(Point center, int diagonal, int degree, int jarak)
{
	Point centersnowflakes;
	int color;
	color= rand()%15+1;
	
//	delay(150);
	centersnowflakes.x = center.x + jarak;
	centersnowflakes.y = center.y;
	kite(centersnowflakes, diagonal, degree, color); // kanan
	
//	delay(150);
	centersnowflakes.x = center.x;
	centersnowflakes.y = center.y + jarak;
	degree+=90;
	kite(centersnowflakes, diagonal, degree, color); // bawah	
	
//	delay(150);
	centersnowflakes.x = center.x - jarak;
	centersnowflakes.y = center.y;
	degree+=90;
	kite(centersnowflakes, diagonal, degree, color); // kiri
	
//	delay(150);
	centersnowflakes.x = center.x;
	centersnowflakes.y = center.y - jarak;
	degree+=90;
	kite(centersnowflakes, diagonal, degree, color); // atas
	
}


void snowflakes_kecil(Point center)
{	
	int diagonal, color, degree=0,jarak = 40;
	for (diagonal=30; diagonal>=5; diagonal--)
	{
		delay(500);
		cleardevice();
		snowflakes(center, diagonal, degree,jarak);
		diagonal--;
		jarak-=3;
	}	
}

void snowflakes_kecil_menyebar()
{
	int i, diagonal, degree=0, color;
	Point center;
	
	for(i=1; i<=30; i++){
		delay(200);
//		cleardevice();
		center.x = rand()%600+1;
		center.y = rand()%600+1;
		diagonal = rand()%15+1;
//		color = rand()%15+1;
		snowflakes(center, diagonal, degree, 5);
		printf ("%d, %d", &center.x, &center.y);
	}
	
	cleardevice();
}

void snowflakes_kecil_berjalan(){
	Point p1, p2, p3, p4;
	
	p1.x = 450;
	p1.y = 300; //kanan
	
	p2.x = 300;
	p2.y = 450; //bawah
	
	p3.x = 150;
	p3.y = 300; //kiri
	
	
	p4.x = 300;
	p4.y = 150; //atas
	
	while(p1.x<=600)
	{
		snowflakes(p1, 10, 0, 10); //kanan
		snowflakes(p2, 10, 0, 10); //bawah
		snowflakes(p3, 10, 0, 10); //kiri
		snowflakes(p4, 10, 0, 10); //atas
		
		p1.x+=5;
		p3.x-=5;
		p2.y+=5;
		p4.y-=5;
		delay(50);
		cleardevice();
		Point p0;
		p0.x = 300; 
		p0.y = 300;
		snowflakes(p0, 30, 0, 40);
	}

}

void snowflakes_moving(Point center, int diagonal, int degree)
{
	Layangan layang;
	int jarak=40;
//	int degree=30;
	
	layang.p1.x = (center.x + 40) - diagonal;
	layang.p1.y = center.y;
	
	layang.p2.x = (center.x + 40);
	layang.p2.y = center.y - diagonal;
	
	layang.p3.x = (center.x + 40);
	layang.p3.y = center.y + diagonal;
	
	layang.p4.x = (center.x + 40) + (2*diagonal);
	layang.p4.y = center.y;

//	delay(50);
//	layang.p1 = rotasi(layang.p1, center, degree);
//	layang.p2 = rotasi(layang.p2, center, degree);
//	layang.p3 = rotasi(layang.p3, center, degree);
//	layang.p4 = rotasi(layang.p4, center, degree);	

	center.x = 300;
	center.y = 300;
	
	layang.p1 = rotasi(layang.p1, center, degree);
	layang.p2 = rotasi(layang.p2, center, degree);
	layang.p3 = rotasi(layang.p3, center, degree);
	layang.p4 = rotasi(layang.p4, center, degree);
	
	draw_line_DDA(layang.p1.x, layang.p1.y, layang.p2.x, layang.p2.y);
	draw_line_DDA(layang.p2.x, layang.p2.y, layang.p4.x, layang.p4.y);
	draw_line_DDA(layang.p4.x, layang.p4.y, layang.p3.x, layang.p3.y);
	draw_line_DDA(layang.p3.x, layang.p3.y, layang.p1.x, layang.p1.y);
}

void snowflakes_rotasi()
{
	
	Point centersnowflakes;
	centersnowflakes.x = 300;
	centersnowflakes.y = 300;
	
	int diagonal = 30;
	int degree = 0;
	
	int loop;
	for (loop=0; loop<360;loop+=5)
	{
		
		snowflakes_moving(centersnowflakes, diagonal, loop);
		snowflakes_moving(centersnowflakes, diagonal, loop+90);
		snowflakes_moving(centersnowflakes, diagonal, loop+180);
		snowflakes_moving(centersnowflakes, diagonal, loop+270);
			
		delay(25);
		cleardevice();	
	}
}

void snowflakes_opening(Point center, int diagonal, int degree, int jarak)
{
	Point centersnowflakes;
	
	delay(200);
	centersnowflakes.x = center.x + jarak;
	centersnowflakes.y = center.y;
	kite(centersnowflakes, diagonal, degree, 15); // kanan
	
	delay(200);
	centersnowflakes.x = center.x;
	centersnowflakes.y = center.y + jarak;
	degree+=90;
	kite(centersnowflakes, diagonal, degree, 15); // bawah	
	
	delay(200);
	centersnowflakes.x = center.x - jarak;
	centersnowflakes.y = center.y;
	degree+=90;
	kite(centersnowflakes, diagonal, degree, 15); // kiri
	
	delay(200);
	centersnowflakes.x = center.x;
	centersnowflakes.y = center.y - jarak;
	degree+=90;
	kite(centersnowflakes, diagonal, degree, 15); // atas
}

void snowflakes_banyak()
{
	Point p1, p2, p3, p4, p5, p6, p7, p8, p9;
	p1.x = 300;
	p1.y = 300; //tengah

	p2.x = 100;
	p2.y = 300; //kiri
	
	p3.x = 500;
	p3.y = 300; //kanan
	
	p4.x = 300;
	p4.y = 100; //atas
	
	p5.x = 300;
	p5.y = 500; //bawah
	
	p6.x = 100;
	p6.y = 100; //atas kiri
	
	p7.x = 500;
	p7.y = 100; //atas bawah
	
	p8.x = 100;
	p8.y = 500; // bawah kiri
	
	p9.x = 500;
	p9.y = 500; //bawah kanan
	
	
	int diagonal = 30;
	int degree = 0;
	
	snowflakes(p1, diagonal, degree, 40);
	
	snowflakes(p2, diagonal, degree, 40);
	
	snowflakes(p3, diagonal, degree, 40);
	
	snowflakes(p4, diagonal, degree, 40);
	
	snowflakes(p5, diagonal, degree, 40);
	
	snowflakes(p6, diagonal, degree, 40);
	
	snowflakes(p7, diagonal, degree, 40);
	
	snowflakes(p8, diagonal, degree, 40);
	
	snowflakes(p9, diagonal, degree, 40);
	
	delay(300);
	
//	int loop;
//	for (loop=0; loop<360;loop+=5)
//	{
//		
//		snowflakes_rotasi(p1);
//		snowflakes_rotasi(p2);
//		snowflakes_rotasi(p3);
//		snowflakes_rotasi(p4);
//		snowflakes_rotasi(p5);
//		snowflakes_rotasi(p6);
//		snowflakes_rotasi(p7);
//		snowflakes_rotasi(p8);
//		snowflakes_rotasi(p9);
////		snowflakes_moving(p2, diagonal, loop);
////		snowflakes_moving(p3, diagonal, loop);
////		snowflakes_moving(p4, diagonal, loop);
////		snowflakes_moving(p5, diagonal, loop);
////		snowflakes_moving(p6, diagonal, loop);
////		snowflakes_moving(p7, diagonal, loop);
////		snowflakes_moving(p8, diagonal, loop);
////		snowflakes_moving(p9, diagonal, loop);
//		
//		delay(100);
//		cleardevice();	
//	}
}

