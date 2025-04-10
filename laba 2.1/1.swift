func Substrings(_ s: String) -> [String] {
    var result = [String]()
    let chars = Array(s)
    let n = chars.count
    
    for i in 0..<n {
        if chars[i] != "1" { continue }
        
        // Вариант 1: "11[0]1"
        if i + 2 < n && chars[i + 1] == "1" {
            var j = i + 2
            while j < n && chars[j] == "0" { j += 1 }
            if j < n && chars[j] == "1" && j > i + 2 {
                result.append(String(chars[i...j]))
            }
        }
        
        // Вариант 2: "1[0]1"
        if i + 1 < n {
            var j = i + 1
            while j < n && chars[j] == "0" { j += 1 }
            if j < n && chars[j] == "1" && j > i + 1 {
                result.append(String(chars[i...j]))
            }
        }
    }
    
    return result
}

let s = "1101gdyY101tf11flb10001"
let substrings = Substrings(s)
print("Результат:", substrings.joined(separator: ", "))