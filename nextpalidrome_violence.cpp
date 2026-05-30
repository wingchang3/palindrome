#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool is_palidrome (string number) {
    int number_size = number.size();
    for (int i = 0; i < number_size / 2; i++) {
        if (number[i] != number[number_size - i - 1]) {
            return false;
            break;
        }
    }
    return true;
}
string plus_one (string number) {
    string after;
    bool carry;
    int number_size = number.size(), i;
    for (i = number_size - 1; i >= 0; i--) {
        carry = false;
        if (number[i] - '0' + 1 > 9) {
            after.push_back('0');
            carry = true;
        }
        if (carry == false) {
            after.push_back(number[i] + 1);
            i--;
            break;
        }
    }
    if (i == -1 and carry == true) after.push_back('1');
    for (i; i >= 0; i--) {
        after.push_back(number[i]);
    }
    reverse (after.begin(), after.end());
    return after;
}
string find_next_palidrome (string number) {
    while (is_palidrome(number) == false) {
        number = plus_one(number);
    }
    return number;
}
int main () {
    string number;
    cout << "start number:";
    while (cin >> number) {
        number = find_next_palidrome(number);
        cout << "next palidrome:" << number << "\n";
        cout << "start number:";
    }
}