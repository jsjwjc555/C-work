#include <iostream>
#include <queue> //queue类
#include <sstream>//stringsteam类
#include <cmath>
#include<string>
#include <stdio.h>//printf
using namespace std;
int main() {

    string map = "_abcdefghijklmnopqrstuvwxyz.";

    int k;
    cin >> k;
    while (k) {
        string cipherText;
        cin >> cipherText;
        int l;
        l = cipherText.length();
        int cipherCode[90];
        int plainCode[90];
        for (int i = 0; i<cipherText.length(); i++) {
            for (int j = 0; j<map.length(); j++) {
                if (map.at(j) == cipherText.at(i)) {
                    cipherCode[i] = j;
                }
            }
        }
        for (int i = 0; i<cipherText.length(); i++) {
            int pos = (k*i) % cipherText.length();
            plainCode[pos] = ((cipherCode[i] + 28) % 28 + i) % 28;
        }
        string ans = "";
        for (int i = 0; i<cipherText.length(); i++) {
            ans += map.at(plainCode[i]);
        }
        cout << ans << endl;
        cin >> k;
    }

    return 0;
}
