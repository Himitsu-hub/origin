#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calculate_hash(const string& s, int start, int length) {
    int hash = 0;
    for (int i = 0; i < length; ++i) {
        hash += s[start + i];
    }
    return hash;
}

int find_substring_light_rabin_karp(const string& source, const string& substring) {
    int n = source.length();
    int m = substring.length();

    if (m == 0 || n < m) return -1;

    int substring_hash = calculate_hash(substring, 0, m);
    int window_hash = calculate_hash(source, 0, m);

    for (int i = 0; i <= n - m; ++i) {
        if (window_hash == substring_hash) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (source[i + j] != substring[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }

        if (i < n - m) {
            window_hash = window_hash - source[i] + source[i + m];
        }
    }

    return -1;
}

int main() {
    setlocale(0, "rus");
    string source;
    cout << "Введите строку, в которой будет осуществляться поиск: ";
    getline(cin, source);

    string substring;
    while (true) {
        cout << "Введите подстроку, которую нужно найти: ";
        getline(cin, substring);

        if (substring == "exit") {
            int index = find_substring_light_rabin_karp(source, substring);
            if (index != -1) {
                cout << "Подстрока " << substring << " найдена по индексу " << index << endl;
            }
            else {
                cout << "Подстрока " << substring << " не найдена" << endl;
            }
            break;
        }

        int index = find_substring_light_rabin_karp(source, substring);
        if (index != -1) {
            cout << "Подстрока " << substring << " найдена по индексу " << index << endl;
        }
        else {
            cout << "Подстрока " << substring << " не найдена" << endl;
        }
    }

    return 0;
}