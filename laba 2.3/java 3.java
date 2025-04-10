import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Введите число: ");
        int number = scanner.nextInt();
        int absNumber = Math.abs(number);

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
        int difference = Math.abs(sum - product);

        System.out.println("Сумма цифр: " + sum);
        System.out.println("Произведение цифр: " + product);
        System.out.println("Модуль разности: " + difference);
    }
}