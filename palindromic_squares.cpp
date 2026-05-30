#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string string_add (string a, string b) {
    string sum;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 or j >= 0 or carry != 0) {
        int n1, n2;
        if (i >= 0) n1 = a[i] - '0';
        else n1 = 0;
        if (j >= 0) n2 = b[j] - '0';
        else n2 = 0;
        int total = n1 + n2 + carry;
        carry = total / 10;
        sum += total % 10 + '0';
        i--;
        j--;
    }
    reverse(sum.begin(), sum.end());
    return sum;
}
string string_square (string number) {
    int carry = 0;
    string sum, temp;
    for (int i = number.size() - 1; i >= 0; i--) {
        for (int j = number.size() - 1; j >= 0; j--) {
            int n1, n2;
            n1 = number[i] - '0';
            n2 = number[j] - '0';
            int total = n1 * n2 + carry;
            carry = total / 10;
            sum += total % 10 + '0';
        }
        if (carry != 0) sum += carry + '0';
        carry = 0;
        reverse(sum.begin(), sum.end());
        for (int k = 0; k < number.size() - i - 1; k++) sum += "0";
        temp = string_add(temp, sum);
        sum = "";
    }
    return(temp);
}
int main () {
    string input;
    cout << "input:";
    while (cin >> input) {
        string square_number = string_square (input);
        bool is_palindrome = true;
        for (int i = 0; i < square_number.size() / 2; i++) {
            if (square_number[i] != square_number[square_number.size() - i - 1]) {
                is_palindrome = false;
                break;
            }
        }
        cout << "the square of the input value:" << square_number << "\n";
        if (is_palindrome == true) {
            cout << "the square of the input value is palindrome.\n";
        }
        else {
            cout << "the square of the input value is not palindrome.\n";
        }
        cout << "input:";
    }
}