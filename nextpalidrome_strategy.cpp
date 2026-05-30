#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool is_palindrome (string number) {
    int number_size = number.size();
    for (int i = 0; i < number_size / 2; i++) {
        if (number[i] != number[number_size - i - 1]) {
            return false;
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
string find_next_palindrome (string number) {
    if (is_palindrome(number) == false) {
        if (number.size() % 2 == 0) {
            string temp1 = number.substr(0, number.size() / 2), temp2;
        	for (int i = number.size() / 2 - 1; i >= 0; i--) {
        		if (number[i] > number[number.size() - i - 1]) {
                    temp2 = temp1;
                    reverse(temp2.begin(), temp2.end());
                    return temp1 + temp2;
				}
                if (number[i] != number[number.size() - i - 1]) break;
			}
            temp1 = plus_one(temp1);
            temp2 = temp1;
            reverse(temp2.begin(), temp2.end());
            return temp1 + temp2;
        }
        else { // odd
            string temp1, temp2;
            for (int i = number.size() / 2 - 1; i >= 0; i--) {
                if (number[i] > number[number.size() - i - 1]) {
        			temp1 = number.substr(0, number.size() / 2);
                    temp2 = temp1;
                    reverse(temp2.begin(), temp2.end());
                    return (temp1 + number[number.size() / 2] + temp2);
				}
                if (number[i] != number[number.size() - i - 1]) break;
            }
            temp1 = number.substr(0, number.size() / 2 + 1); // include mid
            temp1 = plus_one(temp1);
            temp2 = temp1.substr(0, temp1.size() - 1);
            reverse(temp2.begin(), temp2.end());
            return (temp1 + temp2);
        }
    }
    return (number);
}
int main () {
    string number;
    cout << "start number:";
    while (cin >> number) {
        number = find_next_palindrome(number);
        cout << "next palindrome:" << number << "\n";
        cout << "start number:";
    }
}