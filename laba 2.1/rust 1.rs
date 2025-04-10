fn substrings(s: &str) -> Vec<String> {
    let mut result = Vec::new();
    let chars: Vec<char> = s.chars().collect();
    let n = chars.len();
    
    for i in 0..n {
        if chars[i] != '1' { continue; }
        
        // Вариант 1: "11[0]1"
        if i + 2 < n && chars[i + 1] == '1' {
            let mut j = i + 2;
            while j < n && chars[j] == '0' { j += 1; }
            if j < n && chars[j] == '1' && j > i + 2 {
                result.push(s[i..=j].to_string());
            }
        }
        
        // Вариант 2: "1[0]1"
        if i + 1 < n {
            let mut j = i + 1;
            while j < n && chars[j] == '0' { j += 1; }
            if j < n && chars[j] == '1' && j > i + 1 {
                result.push(s[i..=j].to_string());
            }
        }
    }
    
    result
}

fn main() {
    let s = "1101gdyY101tf11flb10001";
    let substrings = substrings(s);
    println!("Результат: {}", substrings.join(", "));
}