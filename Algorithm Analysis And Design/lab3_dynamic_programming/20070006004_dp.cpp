/*Görkem Ertaþ 20070006004*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const unordered_map<char, string> T9 = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
    {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
    {'8', "tuv"}, {'9', "wxyz"}
};

bool containsWord(const string& number, const string& word) {
    int i = 0;
    for (char c : number) {
        if (T9.at(c).find(word[i]) != string::npos) {
            i++;
            if (i == word.size()) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string number = "3662277";
    string words[] = {"foo", "bar", "baz", "foobar", "emo", "cap", "car", "cat"};
    int n = sizeof(words) / sizeof(words[0]);
    bool dp[n + 1][number.size() + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= number.size(); j++) {
            dp[i][j] = false;
        }
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int j = 1; j <= number.size(); j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[i - 1][j];
            if (!dp[i][j] && containsWord(number.substr(0, j), words[i - 1])) {
                dp[i][j] = true;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        if (dp[i][number.size()]) {
            cout << words[i - 1] << " ";
        }
    }
    cout << endl;
    return 0;
}
