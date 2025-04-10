using System;

class Program {
    static void Main() {
        Console.Write("Введите число: ");
        int number = int.Parse(Console.ReadLine());
        int absNumber = Math.Abs(number);

        // Сумма цифр
        int sum = 0;
        int temp = absNumber;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        // Произведение цифр
        int product = 1;
        temp = absNumber;
        if (temp == 0) {
            product = 0;
        } else {
            while (temp > 0) {
                product *= temp % 10;
                temp /= 10;
            }
        }

        // Модуль разности
        int difference = Math.Abs(sum - product);

        Console.WriteLine($"Сумма цифр: {sum}");
        Console.WriteLine($"Произведение цифр: {product}");
        Console.WriteLine($"Модуль разности: {difference}");
    }
}