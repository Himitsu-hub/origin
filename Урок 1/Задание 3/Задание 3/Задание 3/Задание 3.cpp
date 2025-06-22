#include <iostream>
#include <string>
using namespace std;

struct Address {
    string city;        
    string street;      
    int houseNumber;    
    int apartmentNumber; 
    int index;     
};

void printAddress(const Address& addr) {
    cout << "Город: " << addr.city << endl;
    cout << "Улица: " << addr.street << endl;
    cout << "Номер дома: " << addr.houseNumber << endl;
    cout << "Номер квартиры: " << addr.apartmentNumber << endl;
    cout << "Индекс: " << addr.index << endl;
    cout << endl; 
}

int main() {
    setlocale(0, "Rus");

    Address address1 = {
        "Москва",
        "Арбат",
        12,
        8,
        123456
    };
    printAddress(address1);

    Address address2 = {
        "Ковров",
        "Солнечная",
        52,
        12345,
        601903
    };
    printAddress(address2);

    return 0;
}