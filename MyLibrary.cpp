#include"Goods.h"

GoodsInfo MyLibrary::getLines(string  strFromList) {
 int pos1 = 0, pos2 = 0;
 GoodsInfo tempObj;

 pos1 = strFromList.find("model:") + 6;

 for (int i = 0; i < strFromList.length(); i++) {//����������� ������� ������ ��������
	 if (strFromList[i] == ' ') {
		 pos2 = i;
		 break;
	 }
 }
 tempObj.name = strFromList.substr(pos1, pos2 - pos1);//�������� ������������ 


 pos1 = strFromList.find("price:") + 6;

 for (int i = pos1; i < strFromList.length(); i++) {
	 if (strFromList[i] == ' ' || strFromList[i] == '\n') {
		 pos2 = i - 1;
		 break;
	 }
 }
 string priceStr = strFromList.substr(pos1, pos2); //�������� ���� � ������
 tempObj.price = atof(priceStr.c_str()); //������������ ������ � ����

 return tempObj;
}
bool MyLibrary::cmp(const GoodsInfo & g1, const GoodsInfo & g2) {
	if (g1 < g2)return true;
	else return false;
}