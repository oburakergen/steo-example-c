#include <iostream>
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";
    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');

        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());

    return str;
}

string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j=len2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
        i--;
    if (i == -1)
        return "0";
    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}

string random_string(size_t length)
{
    const string CHARACTERS = "0123456789";

    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}
string findW() {
    vector<string> liste;
    for(int i=0;i<5;i++) {
        liste.push_back(random_string(1000));
        liste[i] =multiply(liste[i],liste[i]);
    }
    return findSum(findSum(findSum(liste[0],
                                   liste[1]) ,
                           findSum(liste[2],
                                   liste[3])),
                   liste[4]);
}
void timeCalculate( const long int *begin, const long int *end) {
    double time_spent;
    time_spent = ((double) (*end - *begin)) / CLOCKS_PER_SEC;
    cout<<time_spent<<endl;
}


int main() {
    string total;
    clock_t begin = clock();
    cout<<total.length()<<endl;
    string key = findW();
    string url = "/home/burak/Workstation/my-apps/FinalProjectV2.0.0/encode/key/key_" +
            key.substr(0, 244) +".txt";
    ofstream file(url);
    file << findW();
    clock_t end = clock();
    timeCalculate(&begin,&end);
    return 0;
}
