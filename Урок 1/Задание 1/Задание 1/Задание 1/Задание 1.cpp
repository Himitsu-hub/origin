#include <iostream>
using namespace std;

enum Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

string getMonth(int monthNumber) {
    switch (monthNumber) {
    case January:   return "Январь";
    case February:  return "Февраль";
    case March:     return "Март";
    case April:     return "Апрель";
    case May:       return "Май";
    case June:      return "Июнь";
    case July:      return "Июль";
    case August:    return "Август";
    case September: return "Сентябрь";
    case October:  return "Октябрь";
    case November:  return "Ноябрь";
    case December:  return "Декабрь";
    default:        return "";
    }
}

int main() {
    setlocale(0, "rus");
    int monthNumber;

    while (true) {
        cout << "Введите номер месяца: ";
        cin >> monthNumber;

        if (monthNumber == 0) {
            cout << "До свидания" << endl;
            break;
        }

        string monthName = getMonth(monthNumber);
        if (!monthName.empty()) {
            cout << monthName << endl;
        }
        else {
            cout << "Неправильный номер!" << endl;
        }
    }

    return 0;
}