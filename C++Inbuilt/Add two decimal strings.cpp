
string addDecimalStrings(string s1, string s2) {
    string res = "";

    int i = s1.size() - 1, j = s2.size() - 1;
    int carry = 0;
    while(i >= 0 || j >= 0 || carry > 0) {
        int digit1 = 0, digit2 = 0;
        if(i >= 0) {
            digit1 = s1[i] - '0';
        }
        if(j >= 0) {
            digit2 = s2[j] - '0';
        }

        int total = digit1 + digit2 + carry;
        res = char('0' + total % 10) + res;

        carry = total / 10;
        i--, j--;
    }

    return res;
}

void solve() {
    string a = "5346365464", b = "54645645";
    cout << addDecimalStrings(a, b);
}
