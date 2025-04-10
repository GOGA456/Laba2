<?php
function Substrings($s) {
    $result = array();
    $n = strlen($s);
    
    for ($i = 0; $i < $n; $i++) {
        if ($s[$i] != '1') continue;
        
        // Вариант 1: "11[0]1"
        if ($i + 2 < $n && $s[$i + 1] == '1') {
            $j = $i + 2;
            while ($j < $n && $s[$j] == '0') $j++;
            if ($j < $n && $s[$j] == '1' && $j > $i + 2) {
                array_push($result, substr($s, $i, $j - $i + 1));
            }
        }
        // Вариант 2: "1[0]1"
        if ($i + 1 < $n) {
            $j = $i + 1;
            while ($j < $n && $s[$j] == '0') $j++;
            if ($j < $n && $s[$j] == '1' && $j > $i + 1) {
                array_push($result, substr($s, $i, $j - $i + 1));
            }
        }
    }
    
    return $result;
}

$s = "1101gdyY101tf11flb10001";
$substrings = Substrings($s);
echo "Результат: " . implode(", ", $substrings) . "\n";
?>
