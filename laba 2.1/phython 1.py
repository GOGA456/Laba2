def substrings(s):
    result = []
    n = len(s)
    
    for i in range(n):
        if s[i] != '1':
            continue
        
        # Вариант 1: "11[0]1"
        if i + 2 < n and s[i + 1] == '1':
            j = i + 2
            while j < n and s[j] == '0':
                j += 1
            if j < n and s[j] == '1' and j > i + 2:
                result.append(s[i:j+1])
        
        # Вариант 2: "1[0]1"
        if i + 1 < n:
            j = i + 1
            while j < n and s[j] == '0':
                j += 1
            if j < n and s[j] == '1' and j > i + 1:
                result.append(s[i:j+1])
    
    return result

s = "1101gdyY101tf11flb10001"
substrings = substrings(s)
print("Результат:", ", ".join(substrings))