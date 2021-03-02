/* 
Tugas Ujian Tengah Semester
Nama			: Nikita Nabila
NIM				: 171511054
Kelas			: 3B
Program Studi	: D3 Teknik Informatika
Mata Kuliah		: Komputer Grafik
Tanggal			: 2 Desember 2019
Nama File		: main.cpp
*/

#include "GraphicsLib.h"

int main()
{
	//soal pertama = responsive
//		int diagonal = 30;
//		int degree = 0;
//		int jarak = 40;
//		
////		int a = getmaxx();
////		int b = getmaxy();
//		
//		int maxx, maxy;
//		
//		printf("masukan nilai x max= ");
//		scanf("%d", &maxx);
//		printf("masukan nilai y max=");
//		scanf("%d", &maxy);
//		
//		initwindow(maxx, maxy, "Nikita Nabila 171511054");
//
//				
//		Point p0;
//		p0.x = maxx / 2;
//		p0.y = maxy / 2;
//		
//		snowflakes(p0, diagonal, degree, jarak);
	
//		if(a != p0.x*2  || b != p0.y*2)
//		{
//			p0.x = a / 2;
//			p0.y = b / 2;
//		}


	int diagonal = 30;
	int degree = 0;
	int jarak = 40;

	Point p0;
	p0.x = 300;
	p0.y = 300;

	int a = getmaxx();
	int b = getmaxy();
	
	initwindow(a, b, "Nikita Nabila 171511054");
	
	bool _true = true;
    int page = 0;

	while(_true)
	{
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
		
		 a = getmaxx();
		 b = getmaxy();
	
		snowflakes(p0, diagonal, degree, jarak);

		if(a != p0.x*2  || b != p0.y*2)
		{
			p0.x = a / 2;
			p0.y = b / 2;
		}
		delay(150);
		
	  page = 1-page;
	}
	
	//soal kedua = input kite
//		int diagonal;
//		int degree = 0;
//		int jarak = 40;
//		
//		Point p0;
//		p0.x = 300; 
//		p0.y = 300;
//		
//		initwindow(600, 600, "Nikita Nabila 171511054");
//		
//		printf("input diagonal= ");
//		scanf("%d", &diagonal);
//	
//		snowflakes(p0, diagonal, degree, jarak);
	
	
/*************************************SALAH******************************************/
//	int diagonal;
//	int degree = 0;
//	int jarak = 40;
//	char array[100];
////	int getmaxx, getmaxy;
//	
//	Point p0;
//	p0.x = 300; 
//	p0.y = 300;
//	
////	int maxx = 600;
////	int maxy = 600;
////	
//	
////	initwindow(MAX_WIDTH_DISPLAY, MAX_HEIGHT_DISPLAY, "Nikita Nabila 171511054");
//
//	p0.x = getmaxx();
//	p0.y = getmaxy();
//
//	int gd = DETECT, gm;
//
//	initgraph(&gd, &gm, "niki");
//	
//	int maxx= getmaxx() / 2;
//	int maxy= getmaxy() / 2;
//	
//	initwindow(maxx, maxy, "Nikita Nabila 171511054");
//
//	
//	if(getmaxx() != p0.x *2 || getmaxy() != p0.y *2)
//	{
//		p0.x = getmaxx() / 2;
//		p0.y = getmaxy() / 2;
//	}
//	
//	int maxx= getmaxx();
//	int maxy= getmaxy();
 
//  	sprintf(array, "Max X:%d\nMax Y:%d",p0.x,p0.y);
//  	outtext(array);
//   
//   	snowflakes_banyak();
   
	
	
//	while(true)	{
//		
//		snowflakes_opening(p0, diagonal, degree, jarak);
	
//		snowflakes_kecil_berjalan();
//	
//		snowflakes_banyak();
//		
//		snowflakes_rotasi();	
//		
//		snowflakes_kecil (p0);
		
//		snowflakes_kecil_menyebar();
		
//	}

	
//	rotasi_snowflakes();
	
//	snowflakes(p0, diagonal, degree, jarak);
	
//	snowflakes_moving(p0, diagonal, degree);

/*************************************SALAH******************************************/

	getch();
    closegraph();
	
	return 0;

}

