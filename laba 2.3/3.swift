import Foundation

print("Введите число: ", terminator: "")
guard let input = readLine(), let number = Int(input) else {
    fatalError("Введите целое число")
}
let absNumber = abs(number)

// Сумма цифр
var sum = 0
var temp = absNumber
while temp > 0 {
    sum += temp % 10
    temp /= 10
}

// Произведение цифр
var product = 1
temp = absNumber
if temp == 0 {
    product = 0
} else {
    while temp > 0 {
        product *= temp % 10
        temp /= 10
    }
}

// Модуль разности
let difference = abs(sum - product)

print("Сумма цифр: \(sum)")
print("Произведение цифр: \(product)")
print("Модуль разности: \(difference)")