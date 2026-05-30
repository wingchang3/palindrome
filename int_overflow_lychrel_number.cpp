#include <iostream>
#include <string>
using namespace std;
bool is_palindrome (string number) {
    for (int i = 0; i < number.size() / 2; i++) {
        if (number[i] != number[number.size() - i - 1]) {
            return false;
        }
    }
    return true;
}
int string_to_int (string number) {
    int num = 0;
    for (int i = number.size() - 1; i >= 0; i--) {
        int tmp = 1;
        for (int j = 0; j < i; j++) tmp *= 10;
        num += (number[i] - '0') * tmp;
    }
    return num;
}
int main () {
    string number;
    cout << "input : ";
    while (cin >> number) {
        int count = 0;
        while (is_palindrome(number) == false) {
            count++;
            string reversed = number;
            for (int i = 0; i < reversed.size() / 2; i++) {
                char tmp = reversed[i];
                reversed[i] = reversed[reversed.size() - i - 1];
                reversed[reversed.size() - i - 1] = tmp;
            }
            int now = string_to_int(reversed) + string_to_int(number);
            cout << now << "\n";
            cout << "times : " << count << "\n";
            number = to_string(now);
        }
        cout << "this isn't lychrel_number" << "\n";
        cout << "input : ";
    }
}