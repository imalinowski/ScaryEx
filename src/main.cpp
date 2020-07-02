#include <iostream>
#include <fstream>
#include <cstring>

#include "Storage.h" 
#include "Box.h"
#include "Level.h"
 
using namespace std;


/*
13. Для удобной организации хранения вещей компания использует
штабелируемые
прямоугольные ящики одинаковой высоты трех типоразмеров. При этом на
самый большой ящик можно поставить либо такой же ящик, либо два ящика
среднего размера, либо один ящик среднего размера и два малых ящика,
либо четыре малых ящика. И наоборот, большой ящик можно поставить либо
на такой же ящик, либо на два средних ящика, либо на один средний и
два малых, либо на четыре малых. Один средний ящик можно поставить на
такой же ящик или на два малых ящика. Реализовать программу,
позволяющую укладывать ящики в штабели заданной высоты и заданной
площади. Каждый ярус при этом должен быть заполнен полностью.
*/

bool test1() {
	int w = 4;//!!!размер нижнего ящика
	int h = 2;
	BigBox bigBox(w);
	MediumBox mediumBox(w/2);
	SmallBox smallBox(w/4);

	Storage <Level> levels;
	int _w = w; 
	for (int i = 0; i < h; i++) {
		Level* level = new Level;
		int b = w / bigBox.w;
		int m = (w%4) / mediumBox.w;
		int s = (w % smallBox.w);
		level->set(b,m,s);
		levels.add(*level);
	}
	if ((levels[0].b != 1 || levels[0].m != 0 || levels[0].m != 0) &&
		levels[1].b != 1 || levels[1].m != 0 || levels[1].s != 0)
		return false;
	return true;
}

bool test2() {
	int w = 8;//!!!размер нижнего ящика
	int h = 2;
	BigBox bigBox(w);
	MediumBox mediumBox(w / 2);
	SmallBox smallBox(w / 4);

	Storage <Level> levels;
	int _w = w;
	for (int i = 0; i < h; i++) {
		Level* level = new Level;
		int b = w / bigBox.w;
		int m = (w % 4) / mediumBox.w;
		int s = (w % smallBox.w);
		level->set(b, m, s);
		levels.add(*level);
	}
	if ((levels[0].b != 1 || levels[0].m != 0 || levels[0].m != 0) &&
		levels[1].b != 1 || levels[1].m != 0 || levels[1].s != 0)
		return false;
	return true;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL,"Russian");
	int w, h;
	/*cout << "Width is: "; cin >> w;
	cout << "Width is: "; cin >> h;*/

	cout << ((test1()) ? "Pass" : "Fail") << endl;
	cout << ((test2()) ? "Pass" : "Fail") << endl;
	//cout << ((test3()) ? "Pass" : "Fail") << endl;
	/*if (argc > 1) {
		fstream fa(argv[1], ios::in);
		fstream fb(argv[2], ios::in);
		fstream fc(argv[3], ios::in);
		char line[255];
		fa.getline(line, 255, '\n');
		cout << line << endl;
		fb.getline(line, 255, '\n');
		cout << line << endl;
		fc.getline(line, 255, '\n');
		cout << line << endl;
	}*/

	
	/*fstream file("text.txt", ios::in);
	char *line = new char [255];
	while (strcmp(line, "")) {
		file.getline(line, 255, '\n');
		cout << line;
	}*/

	
	return 0;
}