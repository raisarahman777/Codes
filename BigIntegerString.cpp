//Optimized produc
const int sp = 13;

string prod(string num1, int num2) {
    if (num1.size() <= sp) {
        return to_string(stoll(num1) * num2);
    }
    ll k = 1;
    for (int i = 1; i <= sp; i++) {
        k *= 10LL;
    }
    int sz1 = num1.size();
    int last;
    ll carry = 0;
    string ans = "";
    for (int i = sz1 - sp; i >= 0; i -= sp) {
        last = i;
        ll x = stoll(num1.substr(i, sp));
        x *= num2;
        x += carry;
        carry = x / k;
        string rem = to_string(x % k);
        int sz = rem.size();
        while ((i > 0 || (i == 0 && carry != 0)) && sz < sp) {
            rem = "0" + rem;
            sz++;
        }
        reverse(rem.begin(), rem.end());
        ans += rem;
    }
    if (last != 0) {
        ll x = stoll(num1.substr(0, last));
        x *= num2;
        x += carry;
        carry = x / k;
        string rem = to_string(x % k);
        int sz = rem.size();
        while (carry != 0 && sz < sp) {
            rem = "0" + rem;
            sz++;
        }
        reverse(rem.begin(), rem.end());
        ans += rem;
    }
    if (carry != 0) {
        string temp = to_string(carry);
        reverse(temp.begin(), temp.end());
        ans += temp;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
