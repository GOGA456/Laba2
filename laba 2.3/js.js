const number = parseInt(prompt("Введите число:"));
const absNumber = Math.abs(number);

// Сумма цифр
let sum = 0;
let temp = absNumber;
while (temp > 0) {
    sum += temp % 10;
    temp = Math.floor(temp / 10);
}

// Произведение цифр
let product = 1;
temp = absNumber;
if (temp === 0) {
    product = 0;
} else {
    while (temp > 0) {
        product *= temp % 10;
        temp = Math.floor(temp / 10);
    }
}

// Модуль разности
const difference = Math.abs(sum - product);

console.log(`Сумма цифр: ${sum}`);
console.log(`Произведение цифр: ${product}`);
console.log(`Модуль разности: ${difference}`);