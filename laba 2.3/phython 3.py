number = int(input("Введите число: "))
abs_number = abs(number)

# Сумма цифр
sum_digits = 0
temp = abs_number
while temp > 0:
    sum_digits += temp % 10
    temp = temp // 10

# Произведение цифр
product = 1
temp = abs_number
if temp == 0:
    product = 0
else:
    while temp > 0:
        product *= temp % 10
        temp = temp // 10

# Модуль разности
difference = abs(sum_digits - product)

print(f"Сумма цифр: {sum_digits}")
print(f"Произведение цифр: {product}")
print(f"Модуль разности: {difference}")