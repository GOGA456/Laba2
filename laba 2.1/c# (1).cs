using System;
using System.Collections.Generic;

class Program {
    static List<string> Substrings(string s) {
        var result = new List<string>();
        int n = s.Length;
        
        for (int i = 0; i < n; i++) {
            if (s[i] != '1') continue;
            
            // Вариант 1: "11[0]1"
            if (i + 2 < n && s[i + 1] == '1') {
                int j = i + 2;
                while (j < n && s[j] == '0') j++;
                if (j < n && s[j] == '1' && j > i + 2) {
                    result.Add(s.Substring(i, j - i + 1));
                }
            }
            
            // Вариант 2: "1[0]1"
            if (i + 1 < n) {
                int j = i + 1;
                while (j < n && s[j] == '0') j++;
                if (j < n && s[j] == '1' && j > i + 1) {
                    result.Add(s.Substring(i, j - i + 1));
                }
            }
        }
        
        return result;
    }
    
    static void Main() {
        string s = "1101gdyY101tf11flb10001";
        var substrings = Substrings(s);
        Console.WriteLine("Результат: " + string.Join(", ", substrings));
    }
}