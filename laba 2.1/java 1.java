import java.util.ArrayList;
import java.util.List;

public class Main {
    public static List<String> Substrings(String s) {
        List<String> result = new ArrayList<>();
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != '1') continue;
            
            // Вариант 1: "11[0]1"
            if (i + 2 < n && s.charAt(i + 1) == '1') {
                int j = i + 2;
                while (j < n && s.charAt(j) == '0') j++;
                if (j < n && s.charAt(j) == '1' && j > i + 2) {
                    result.add(s.substring(i, j + 1));
                }
            }
            
            // Вариант 2: "1[0]1"
            if (i + 1 < n) {
                int j = i + 1;
                while (j < n && s.charAt(j) == '0') j++;
                if (j < n && s.charAt(j) == '1' && j > i + 1) {
                    result.add(s.substring(i, j + 1));
                }
            }
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        String s = "1101gdyY101tf11flb10001";
        List<String> substrings = Substrings(s);
        System.out.println("Результат: " + String.join(", ", substrings));
    }
}