#include <iostream>
#include <random>

using namespace std;

float getRandomNumber(int min, int max)
{
	
	
	return 0;
}

int main()
{
	
	//Использование более современного алгоритма псевдорандома
	random_device rd;
	mt19937 gen(rd());

	//координаты выстрела
	float x, y = 0;
	//сумма очков попаданий
	unsigned short SUM = 0;
	//очки текущего выстрела
	short at = 0;

	for (int i = 0; i < 5; i++) {
		//Ввод координат для выстрела
		cout << "Enter coordinates of the shot [-5; 5]" << endl << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;

		//симуляция разброса выстрела
		x += (gen() % 1000) / 100.0 - 5;
		y += (gen() % 1000) / 100.0 - 5;
		
		//очки текущего выстрела
		at = 5 - floor(sqrt(x * x + y * y));
		at < 0 ? at = 0 : 0;

		//Суммирование очков попадания
		SUM += at;

		//вы попали в (x; y) и заработали at очков
		cout << "You hit (" << x << "; " << y << ") and earned " << at << " points\n\n";
		
	}

	cout << "for 5 shots you earned " << SUM << " points\n";
	if (SUM < 10)
		cout << "LUZER\n";
	else
		cout << "You win!\n";

	return 0;
}	