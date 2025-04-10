#include <iostream>
#include <cmath> // Для abs()

using namespace std;

int main() {
    int number;
    
    // Ввод одного числа
    cout << "Введите число: ";
    cin >> number;
    
    // Вычисление суммы цифр
    int sum = 0;
    int temp = abs(number); // Работаем с модулем числа
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    
    // Вычисление произведения цифр
    int product = 1;
    temp = abs(number); // Снова берем модуль
    if (temp == 0) {
        product = 0; // Особый случай для 0
    } else {
        while (temp > 0) {
            product *= temp % 10;
            temp /= 10;
        }
    }
    
    // Вычисление модуля разности
    int difference = abs(sum - product);
    
    // Вывод результатов
    cout << "Сумма цифр: " << sum << endl;
    cout << "Произведение цифр: " << product << endl;
    cout << "Модуль разности: " << difference << endl;
    
    return 0;
}