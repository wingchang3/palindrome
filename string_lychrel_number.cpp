#include <iostream>
#include <string>
#include <algorithm> //reverse
using namespace std;
bool is_palindrome (string number) {
    for (int i = 0; i < number.size() / 2; i++) {
        if (number[i] != number[number.size() - i - 1]) {
            return false;
        }
    }
    return true;
}
string add_strings(string number, string rev) {
    int sum = 0, carry = 0;
    string after;
    for (int i = number.size() - 1; i >= 0; i--) {
        sum = (number[i] - '0') + (rev[i] - '0') + carry;
        after.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry) {
        after.push_back(carry + '0');
    }
    reverse(after.begin(), after.end());
    return after;
}
int main () {
    string number;
    cout << "input : ";
    while (cin >> number) {
        int count = 0;
        while (is_palindrome(number) == false) {
            count++;
            string rev = number;
            reverse(rev.begin(), rev.end());
            number = add_strings(number, rev);
            cout << number << "\n";
            cout << "times : " << count << "\n";
        }
        cout << "this isn't Lychrel candidate" << "\n";
        cout << "input : ";
    }
}