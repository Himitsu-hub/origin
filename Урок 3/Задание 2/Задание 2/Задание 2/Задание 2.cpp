#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class Address {
private:
    string city;
    string street;
    int house;
    int apartment;

public:
    Address(string city, string street, int house, int apartment)
        : city(city), street(street), house(house), apartment(apartment) {
    }

    string get_output_address() const {
        return city + ", " + street + ", " + to_string(house) + ", " + to_string(apartment);
    }

    string get_city() const {
        return city;
    }
};

bool compare_addresses(const Address* a, const Address* b) {
    return a->get_city() < b->get_city();
}

void sort_addresses(Address** addresses, int size) {
    sort(addresses, addresses + size, compare_addresses);
}

int main() {
    setlocale(0, "rus");

    ifstream input("in.txt");
    ofstream output("out.txt");

    if (!input.is_open()) {
        cerr << "Не удалось открыть файл in.txt" << endl;
        return 1;
    }

    if (!output.is_open()) {
        cerr << "Не удалось создать файл out.txt" << endl;
        return 1;
    }

    int N;
    input >> N;
    output << N << endl;
    input.ignore(numeric_limits<streamsize>::max(), '\n');

    Address** addresses = new Address * [N];

    for (int i = 0; i < N; ++i) {
        string city, street;
        int house, apartment;

        getline(input, city);
        getline(input, street);
        input >> house;
        input >> apartment;
        input.ignore(numeric_limits<streamsize>::max(), '\n');

        addresses[i] = new Address(city, street, house, apartment);
    }

    sort_addresses(addresses, N);
    for (int i = 0; i < N; ++i) {
        output << addresses[i]->get_output_address() << endl;
    }

    for (int i = 0; i < N; ++i) {
        delete addresses[i];
    }
    delete[] addresses;

    input.close();
    output.close();

    return 0;
}