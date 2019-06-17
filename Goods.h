#pragma once

#include <iostream>
#include <cstdlib>
#include<locale>
#include <list>
#include <vector>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;


struct GoodsInfo {
	string name;
	double price;

	
};

bool operator < (const GoodsInfo  a, const GoodsInfo b) {
	if (a.price < b.price)return true;
	else return false;
}

namespace MyLibrary {
	GoodsInfo getLines(string  strFromList);//выборка нужных данных из строки	
	bool cmp(const GoodsInfo & g1, const GoodsInfo & g2);
}