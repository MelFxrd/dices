#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm> // Подключаем библиотеку алгоритмов

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL)); // Задаем зерно

	const int n = 2; // Указываем размер массива с костями

	int dicesBot[n]; // Массив костей бота
	int dicesPlayer[n]; // Массива костей игрока

	// Заполнение массива костей бота случайными числами
	cout << "Кидает бот: " << endl;
	for (int i = 0; i < n; i++) {
		dicesBot[i] = 1 + rand() % 6;
		cout << dicesBot[i] << " ";
	}
	cout << endl;


	cout << "Нажмите что-нибудь, чтобы бросить кости";
	cin.get();

	// Заполнение массива костей игрока случайными числами
	cout << "Бросаем кости..." << endl;
	for (int i = 0; i < n; i++) {
		dicesPlayer[i] = 1 + rand() % 6;
		cout << dicesPlayer[i] << " ";
	}
	cout << endl;

	// Сортируем массивы функцией sort из algorithm
	sort(dicesBot, dicesBot + n);
	sort(dicesPlayer, dicesPlayer + n);

	// Сравнение всех элементов в массиве на их одинаковость
	bool eq = true; // Заранее предпологаю что они все одинаковы
	int dEq = dicesBot[0]; // Беру первый элемент в качество эквивалента
	for (int d : dicesBot) {
		if (d != dEq) { // Если один из элементов не равент первому, то значит массив содержит разные элементы
			eq = false;
			break;
		}
	}

	if (eq) {
		cout << "Бот победил";
	}

	return 0;
}