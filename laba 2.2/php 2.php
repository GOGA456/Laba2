<?php
function Email($email) {
    $at = strpos($email, '@');
    if ($at === false) return $email;
    
    $username = substr($email, 0, $at);
    $domain = substr($email, $at); // включая '@'
    
    $username = str_replace('.', '', $username);
    $plus = strpos($username, '+');
    if ($plus !== false) {
        $username = substr($username, 0, $plus);
    }
    
    return $username . $domain;
}

function countUniqueEmails($emails) {
    $d = array_map('Email', $emails);
    return count(array_unique($d));
}

$emails1 = [
    "mar.pha+science@corp.nstu.ru",
    "marpha+scie.nce@corp.nstu.ru",
    "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
];
echo "Пример 1: " . countUniqueEmails($emails1) . "\n"; 

$emails2 = [
    "mar.pha+science@co.rp.nstu.ru",
    "marpha+scie.nce@c.orp.nstu.ru",
    "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
];
echo "Пример 2: " . countUniqueEmails($emails2) . "\n"; 
?>