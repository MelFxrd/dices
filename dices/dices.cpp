#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int n = 5;

bool allSame(const int arr[]) {
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));

    int dicesBot[n];
    int dicesPlayer[n];

    cout << "Кидает бот: " << endl;
    for (int i = 0; i < n; i++) {
        dicesBot[i] = 1 + rand() % 6;
        cout << dicesBot[i] << " ";
    }
    cout << endl;

    cout << "Нажмите что-нибудь, чтобы бросить кости";
    cin.get();

    cout << "Бросаем кости..." << endl;
    for (int i = 0; i < n; i++) {
        dicesPlayer[i] = 1 + rand() % 6;
        cout << dicesPlayer[i] << " ";
    }
    cout << endl;

    int sumBot = 0, sumPlayer = 0;

    for (int i = 0; i < n; i++) {
        sumBot += dicesBot[i];
        sumPlayer += dicesPlayer[i];
    }

    if (allSame(dicesBot)) {
        cout << "Бот победил";
    }
    else if (allSame(dicesPlayer)) {
        cout << "Игрок победил";
    }
    else if (sumBot > sumPlayer) {
        cout << "Бот победил с большей суммой: " << sumBot;
    }
    else if (sumPlayer > sumBot) {
        cout << "Игрок победил с большей суммой: " << sumPlayer;
    }
    else {
        cout << "Ничья!";
    }

    return 0;
}
