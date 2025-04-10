fun findPatternSubstrings(s: String): List<String> {
    val result = mutableListOf<String>()
    val n = s.length
    
    for (i in 0 until n) {
        if (s[i] != '1') continue
        
        // Вариант 1: "11[0]1"
        if (i + 2 < n && s[i + 1] == '1') {
            var j = i + 2
            while (j < n && s[j] == '0') j++
            if (j < n && s[j] == '1' && j > i + 2) {
                result.add(s.substring(i, j + 1))
            }
        }
        
        // Вариант 2: "1[0]1"
        if (i + 1 < n) {
            var j = i + 1
            while (j < n && s[j] == '0') j++
            if (j < n && s[j] == '1' && j > i + 1) {
                result.add(s.substring(i, j + 1))
            }
        }
    }
    
    return result
}

fun main() {
    val s = "1101gdyY101tf11flb10001"
    val substrings = findPatternSubstrings(s)
    println("Результат: ${substrings.joinToString(", ")}")
}