#include"Goods.h"

int main() {
	setlocale(LC_ALL, "ru");

	ifstream fin;
	ofstream fout;

	list <string> filesValue;
	//list<string>::iterator iterList = filesValue.begin();//создаём итератор на первый элемент списка
	vector <GoodsInfo> goodsStorage;
	string Path = "goods.txt";

	fin.open(Path); //открытие файла

	if (!fin) {//проверка открытия файла
		cerr << "Ошибка открытия файла." << endl;
		return 1;
	}	

	while (!fin.eof()) { //считывание в список по строчно
		string tmpStr = "1";
		getline(fin, tmpStr, '\n');
		cout << tmpStr << endl;
		filesValue.push_back(tmpStr);
	} 

	fin.close();
	
	cout << "\n" << filesValue.size()<<"\n" << endl;

	list<string>::iterator iterList = filesValue.begin();//создаём итератор на первый элемент списка

	while (iterList != filesValue.end()) {// конвертируем строки из листа в структуру
		goodsStorage.push_back(MyLibrary::getLines(*iterList));// и добавляем в вектор структур
		iterList++;
	}
	cout << "size of vector = " << goodsStorage.size();

	sort(goodsStorage.begin(), goodsStorage.end(),MyLibrary::cmp);

	{
		//взаимодействие с пользователем
		cout << "\n" << "Добрый день уважаемый клиент!" << endl;
		cout<< "На данный момент в нашем списке " << goodsStorage.size() << " товаров" << endl;
		cout << "Какое количество наиболее дорогих товаров, вы хотели-бы увидеть?" << endl;
		cout << "Пожалуйста введите значение   ";
		int valFromUser=0;
		do {//проверка корректности ввода
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