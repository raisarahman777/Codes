bool isSmaller(string str1, string str2) { 
    int n1 = str1.length(), n2 = str2.length(); 
    if (n1 < n2) return true; 
    if (n2 < n1) return false; 
    for (int i = 0; i < n1; i++) { 
        if (str1[i] < str2[i]) return true; 
        else if (str1[i] > str2[i]) return false; 
    } 
    return false; 
} 

string findDiff(string str1, string str2) { 
    if (isSmaller(str1, str2)) swap(str1, str2); 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n1 - n2; 
    int carry = 0;  
    for (int i = n2 - 1; i >= 0; i--) {  
        int sub = ((str1[i + diff] - '0') - (str2[i] - '0') - carry); 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else carry = 0; 
        str.push_back(sub + '0'); 
    }  
    for (int i = n1 - n2 - 1; i >= 0; i--) { 
        if (str1[i] == '0' && carry) { 
            str.push_back('9'); 
            continue; 
        } 
        int sub = ((str1[i] - '0') - carry); 
        if (i > 0 || sub > 0) str.push_back(sub + '0'); 
        carry = 0; 
    }  
    reverse(str.begin(), str.end()); 
    return str; 
}

string findSum(string str1, string str2) {
    str1.erase(0, min(str1.find_first_not_of('0'), str1.size()-1));
    str2.erase(0, min(str2.find_first_not_of('0'), str2.size()-1));
    if (str1.empty() && str2.empty()) return "0"; 
    if (str1.length() > str2.length()) swap(str1, str2); 
    string str = "";  
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1; 
    int carry = 0;  
    for (int i=n1-1; i>=0; i--) { 
        int sum = ((str1[i]-'0') + (str2[i+diff]-'0') + carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    }
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    }
    if (carry) str.push_back(carry+'0');  
    reverse(str.begin(), str.end()); 
    return str; 
}

string findProduct(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0) return "0";
    vector<int> result(len1 + len2, 0); 
    int i_n1 = 0; 
    int i_n2 = 0; 
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;             
        for (int j=len2-1; j>=0; j--) {
            int n2 = num2[j] - '0'; 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }
        if (carry > 0) result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0) i--;
    if (i == -1) return "0";
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
    return s;
}

string findQuotient(string number, int divisor) {
    string ans = "";
    int idx = 0;
    int temp = number[idx] - '0';
    while (idx < (number.size() - 1) && temp < divisor) {
        temp = temp * 10 + (number[++idx] - '0');
    }
    while ((number.size() - 1) > idx) {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    ans += (temp / divisor) + '0';
    if (ans.length() == 0) return "0";
    return ans;
}

int findMod(const string& largeNum, int mod) {
    int result = 0; 
    for (char digit : largeNum) { 
        result = (result * 10 + (digit - '0')) % mod; 
    } 
    return result;
}
