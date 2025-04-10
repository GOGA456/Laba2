function calculateDigits(number: number) {
    const absNumber = Math.abs(number);
    let sum = 0;
    let product = 1;
    let temp = absNumber;

    if (temp === 0) {
        return { sum: 0, product: 0, difference: 0 };
    }

    while (temp > 0) {
        const digit = temp % 10;
        sum += digit;
        product *= digit;
        temp = Math.floor(temp / 10);
    }

    return {
        sum,
        product,
        difference: Math.abs(sum - product)
    };
}

const input = prompt("Введите целое число:") || "0";
const number = parseInt(input);

if (isNaN(number)) {
    alert("Ошибка: Введите корректное число");
} else {
    const { sum, product, difference } = calculateDigits(number);
    alert(`
        Результаты:
        Сумма цифр: ${sum}
        Произведение цифр: ${product}
        Модуль разности: ${difference}
    `);
}