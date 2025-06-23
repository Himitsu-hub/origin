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
    case static_cast<int>(January):   return "Январь";
    case static_cast<int>(February):  return "Февраль";
    case static_cast<int>(March):     return "Март";
    case static_cast<int>(April):     return "Апрель";
    case static_cast<int>(May):       return "Май";
    case static_cast<int>(June):      return "Июнь";
    case static_cast<int>(July):      return "Июль";
    case static_cast<int>(August):    return "Август";
    case static_cast<int>(September): return "Сентябрь";
    case static_cast<int>(October):   return "Октябрь";
    case static_cast<int>(November):  return "Ноябрь";
    case static_cast<int>(December):  return "Декабрь";
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
