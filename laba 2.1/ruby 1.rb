def substrings(s)
  result = []
  n = s.length
  
  (0...n).each do |i|
    next if s[i] != '1'
    
    # Вариант 1: "11[0]1"
    if i + 2 < n && s[i + 1] == '1'
      j = i + 2
      j += 1 while j < n && s[j] == '0'
      if j < n && s[j] == '1' && j > i + 2
        result << s[i..j]
      end
    end
    
    # Вариант 2: "1[0]1"
    if i + 1 < n
      j = i + 1
      j += 1 while j < n && s[j] == '0'
      if j < n && s[j] == '1' && j > i + 1
        result << s[i..j]
      end
    end
  end
  
  result
end

s = "1101gdyY101tf11flb10001"
substrings = substrings(s)
puts "Результат: #{substrings.join(', ')}"