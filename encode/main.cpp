#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <map>
#include <fstream>
#include <vector>
#include <experimental/filesystem>
#include <fstream>

using namespace std;

string var[255][0];
int var2[255][0];
string asciiGenerator(string isim) {
    map<short , char> ascii1;
    for(int i=0;i<255;i++) {
        ascii1.insert(pair<short, char>(i+100, (char)i));
    }
    string pk;
    for(int i=0;i<isim.length();i++) {
        pk=pk+to_string(ascii1.lower_bound(isim[i])->first);
    }
    return pk;
}


/*
 * Time Calculator
 */
void timeCalculate( const long int *begin, const long int *end) {
    double time_spent;
    time_spent = ((double) (*end - *begin)) / CLOCKS_PER_SEC;
    cout<<time_spent<<endl;
}

int main() {
    string total;
    clock_t begin = clock();
    string arr2[1000];
    string path = "./key";
    string pass = "";
    string messagess ="";
    string url = "/{path}/encode/messages.txt";
    ofstream myfile(url);
    myfile.open(url);
    cin >> messagess;
    myfile.close();

    for (const auto & file : directory_iterator(path)) {
        string data;
        ofstream myfile(file.path());
        if (myfile.is_open())
        {
            myfile.open(file.path());
            cin >> data;
            myfile.close();
            url = "/{path}/decode/key/key_" +
                    data.substr(0, 244) +".txt";
            ofstream file2(url);
            file2 << data + asciiGenerator(messagess);
        }else cout << "Unable to open file";
    }

    clock_t end = clock();
    timeCalculate(&begin,&end);
    return 0;
}