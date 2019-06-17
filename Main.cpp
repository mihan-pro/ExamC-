#include"Goods.h"

int main() {
	setlocale(LC_ALL, "ru");

	ifstream fin;
	ofstream fout;

	list <string> filesValue;
	//list<string>::iterator iterList = filesValue.begin();//������ �������� �� ������ ������� ������
	vector <GoodsInfo> goodsStorage;
	string Path = "goods.txt";

	fin.open(Path); //�������� �����

	if (!fin) {//�������� �������� �����
		cerr << "������ �������� �����." << endl;
		return 1;
	}	

	while (!fin.eof()) { //���������� � ������ �� �������
		string tmpStr = "1";
		getline(fin, tmpStr, '\n');
		cout << tmpStr << endl;
		filesValue.push_back(tmpStr);
	} 

	fin.close();
	
	cout << "\n" << filesValue.size()<<"\n" << endl;

	list<string>::iterator iterList = filesValue.begin();//������ �������� �� ������ ������� ������

	while (iterList != filesValue.end()) {// ������������ ������ �� ����� � ���������
		goodsStorage.push_back(MyLibrary::getLines(*iterList));// � ��������� � ������ ��������
		iterList++;
	}
	cout << "size of vector = " << goodsStorage.size();

	sort(goodsStorage.begin(), goodsStorage.end(),MyLibrary::cmp);

	{
		//�������������� � �������������
		cout << "\n" << "������ ���� ��������� ������!" << endl;
		cout<< "�� ������ ������ � ����� ������ " << goodsStorage.size() << " �������" << endl;
		cout << "����� ���������� �������� ������� �������, �� ������-�� �������?" << endl;
		cout << "���������� ������� ��������   ";
		int valFromUser=0;
		do {//�������� ������������ �����
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> valFromUser;			
		} while (!cin);
		if (valFromUser < 0)valFromUser = 0;
		else if (valFromUser > goodsStorage.size())valFromUser = goodsStorage.size();
		
	}

	for (int i = 0; i < goodsStorage.size(); i++) {
		cout << goodsStorage[i].name << "    " << goodsStorage[i].price << endl;
	}


	system ("pause");
	return 0;
}