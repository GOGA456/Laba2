package main

import (
	"fmt"
	"math"
)

func main() {
	var number int
	fmt.Print("Введите число: ")
	fmt.Scan(&number)
	absNumber := int(math.Abs(float64(number)))

	// Сумма цифр
	sum := 0
	temp := absNumber
	for temp > 0 {
		sum += temp % 10
		temp /= 10
	}

	// Произведение цифр
	product := 1
	temp = absNumber
	if temp == 0 {
		product = 0
	} else {
		for temp > 0 {
			product *= temp % 10
			temp /= 10
		}
	}

	// Модуль разности
	difference := int(math.Abs(float64(sum - product)))

	fmt.Printf("Сумма цифр: %d\n", sum)
	fmt.Printf("Произведение цифр: %d\n", product)
	fmt.Printf("Модуль разности: %d\n", difference)
}