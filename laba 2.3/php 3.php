<?php
echo "Введите число: ";
$number = (int)trim(fgets(STDIN));
$absNumber = abs($number);

// Сумма цифр
$sum = 0;
$temp = $absNumber;
while ($temp > 0) {
    $sum += $temp % 10;
    $temp = (int)($temp / 10);
}

// Произведение цифр
$product = 1;
$temp = $absNumber;
if ($temp == 0) {
    $product = 0;
} else {
    while ($temp > 0) {
        $product *= $temp % 10;
        $temp = (int)($temp / 10);
    }
}

// Модуль разности
$difference = abs($sum - $product);

echo "Сумма цифр: $sum\n";
echo "Произведение цифр: $product\n";
echo "Модуль разности: $difference\n";
?>