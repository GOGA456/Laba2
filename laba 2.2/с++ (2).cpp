
#include <iostream>   
#include <vector>     
#include <string>     
#include <unordered_set> 
#include <algorithm>  /

using namespace std; 

// Функция для нормализации email-адреса
string Email(const string& email) {
    size_t at = email.find('@');
    
    // Если @ не найден, возвращаем исходную строку (некорректный email)
    if (at == string::npos) return email;
    
    // Разделяем email на имя пользователя (до @) и домен (после @)
    string username = email.substr(0, at); // Часть до @
    string domain = email.substr(at);      // Часть после @ (включая сам @)
    
    // Удаляем все точки из имени пользователя
    username.erase(remove(username.begin(), username.end(), '.'), username.end());
    
    // Находим позицию символа + в имени пользователя
    size_t plus = username.find('+');
    
    // Если + найден, обрезаем имя пользователя до этого символа
    if (plus != string::npos) {
        username = username.substr(0, plus);
    }
    
    // Возвращаем нормализованный email (обработанное имя + домен)
    return username + domain;
}

// Функция для подсчета уникальных email-адресов
int count(const vector<string>& emails) {
    unordered_set<string> unique_emails;
    
    // Перебираем все email-адреса в переданном векторе
    for (const string& email : emails) {
        string d = Email(email);
        
        unique_emails.insert(d);
    }
    
    return unique_emails.size();
}

int main() {
    vector<string> emails1 = {
        "mar.pha+science@corp.nstu.ru",
        "marpha+scie.nce@corp.nstu.ru",
        "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
    };
    cout << "Пример 1: " << count(emails1) << endl;
    

    vector<string> emails2 = {
        "mar.pha+science@co.rp.nstu.ru",
        "marpha+scie.nce@c.orp.nstu.ru",
        "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
    };

    cout << "Пример 2: " << count(emails2) << endl;
    
    return 0;
}