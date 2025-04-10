print "Введите число: "
number = gets.chomp.to_i
abs_number = number.abs

# Сумма цифр
sum = 0
temp = abs_number
while temp > 0
  sum += temp % 10
  temp /= 10
end

# Произведение цифр
product = 1
temp = abs_number
if temp == 0
  product = 0
else
  while temp > 0
    product *= temp % 10
    temp /= 10
  end
end

# Модуль разности
difference = (sum - product).abs

puts "Сумма цифр: #{sum}"
puts "Произведение цифр: #{product}"
puts "Модуль разности: #{difference}"