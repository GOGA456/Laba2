#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> Substrings(const string &s) {
    vector<string> result;
    int n = s.size();
    
    for (int i = 0; i < n; ++i) {
        if (s[i] != '1') continue;
        
        // Вариант 1: начинается с '1', затем ещё '1', потом один или более '0', и заканчивается '1' (шаблон "11[0]1")
        if (i + 2 < n && s[i + 1] == '1') {
            int j = i + 2;
            while (j < n && s[j] == '0') {
                ++j;
            }
            if (j < n && s[j] == '1' && j > i + 2) { // Проверяем, что был хотя бы один '0'
                result.push_back(s.substr(i, j - i + 1));
            }
        }
        
        // Вариант 2: начинается с '1', затем один или более '0', и заканчивается '1' (шаблон "1[0]1")
        if (i + 1 < n) {
            int j = i + 1;
            while (j < n && s[j] == '0') {
                ++j;
            }
            if (j < n && s[j] == '1' && j > i + 1) { // Проверяем, что был хотя бы один '0'
                result.push_back(s.substr(i, j - i + 1));
            }
        }
    }
    
    return result;
}

int main() {
    string s = "1101gdyY101tf11flb10001";
    vector<string> substrings = Substrings(s);
    
    cout << "Результат: ";
    for (size_t i = 0; i < substrings.size(); ++i) {
        if (i != 0) cout << ", ";
        cout << substrings[i];
    }
    cout << endl;
    
    return 0;
}