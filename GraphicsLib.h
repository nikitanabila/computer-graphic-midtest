/* 
Tugas Ujian Tengah Semester
Nama			: Nikita Nabila
NIM				: 171511054
Kelas			: 3B
Program Studi	: D3 Teknik Informatika
Mata Kuliah		: Komputer Grafik
Tanggal			: 2 Desember 2019
Nama File		: GraphicsLib.h
*/

#ifndef GRAPHICS_LIB
#define GRAPHICS_LIB 

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

//#define MAX_WIDTH_DISPLAY 600
//#define MAX_HEIGHT_DISPLAY 600

#define SIN(x) sin(x * 3.141592653589/180)  //nilai sin = 0.01745
#define COS(x) cos(x * 3.141592653589/180) //nilai cos = 0.01745

/* Struktur Data */

typedef struct Point{
	int x;
	int y;
}Point;

typedef struct Layangan
{
	struct Point p1;
	struct Point p2;
	struct Point p3;
	struct Point p4;
}Layangan;



/* Prototype */

int abs (int n); //pendefisian nilai absolut
void draw_line_DDA(int x1, int y1, int x2, int y2); //menggambar garis menggunakan algoritma DDA
Point rotasi(Point p0, Point center, int degree); //merotasi point
void kite(Point center, int diagonal, int degree, int color); //menggambar bagian dari snowflakes berupa layang-layang dengan titik pusat layangan
void snowflakes(Point center, int diagonal, int degree, int jarak); //menggambar 4 layangan yang disebut snowflakes
void snowflakes_kecil (Point center); //menggambar snowflakes berukuran kecil (scaling)
void snowflakes_kecil_menyebar(); //menggambar snowflakes dengan ukuran kecil yang menyebar
void snowflakes_kecil_berjalan(); //menggambar snowflakes berjalan (translasi)
void snowflakes_moving(Point center, int diagonal, int degree); //menggambar snowflakes dengan titik pusat snowflakes
void snowflakes_rotasi(); //menggambar snowflakes agar bisa diputar (rotate)
void snowflakes_opening(Point center, int diagonal, int degree, int jarak); //menggambar snowflakes opening disertai delay
void snowflakes_banyak(); //menggambar snowflakes dengan jumlah banyak

#endif
