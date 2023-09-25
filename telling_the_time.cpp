#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

map<int, string> cuatro = {{0, "o' clock"}, {15, "quarter"}, {30, "half"}};
vector<string> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty"};
vector<string> teens = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

string translate(int m, vector<int> cuatro_k) {

    if (find(cuatro_k.begin(), cuatro_k.end(), m) != cuatro_k.end()) {
        return cuatro[m];
    } else if (m > 0 && m < 10) {
        return ones[m];
    } else if (m >= 10 && m < 20) {
        return teens[m%10];
    } else {
        string s = "";
        s += tens[floor(m/10)];
        if (m%10) {
            s += " " + ones[m % 10];
        }
        return s;
    }

}

string timeInWords(int h, int m) {

    vector<int> cuatro_k;
    for (auto const& imap: cuatro) {
        cuatro_k.push_back(imap.first);
    }

    
    vector<string> hours = ones;
    hours.push_back("ten");
    hours.push_back("eleven");
    hours.push_back("twelve");

    string minutes = "";
    if (m == 1) {
        minutes += "minute";
    } else {
        minutes += "minutes";
    }

    map<char, string> times;
    times['h'] = "";
    times['m'] = "";

    if (m == 0) {
        times['h'] += hours[h];
        times['m'] += translate(m, cuatro_k);
        return times['h'] + " " + times['m'];
    } else if (m <= 30) {
        times['h'] += hours[h];
        times['m'] += translate(m, cuatro_k);
        if (find(cuatro_k.begin(), cuatro_k.end(), m) != cuatro_k.end()) {
            times['m'] += " past";
        } else {
            times['m'] += " " + minutes + " past";
        }
    } else {
        m = 60 - m;
        times['h'] += hours[h+1];
        times['m'] += translate(m, cuatro_k);
        if (find(cuatro_k.begin(), cuatro_k.end(), m) != cuatro_k.end()) {
            times['m'] += " to";
        } else {
            times['m'] += " minutes to";
        }
    }
    return times['m'] + " " + times['h'];
}

int main() {

    int h, m;
    cout << "Input hour: "; cin >> h;
    cout << "Input minute: "; cin >> m;

    const char* s = timeInWords(h, m).c_str();
    
    printf("%s \n", s);

}