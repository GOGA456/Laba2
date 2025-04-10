using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static string Email(string email) {
        int at = email.IndexOf('@');
        if (at == -1) return email;
        
        string username = email.Substring(0, at);
        string domain = email.Substring(at);
        
        username = username.Replace(".", "");
        int plus = username.IndexOf('+');
        if (plus != -1) {
            username = username.Substring(0, plus);
        }
        
        return username + domain;
    }
    
    static int CountUniqueEmails(string[] emails) {
        return emails.Select(Email).Distinct().Count();
    }
    
    static void Main() {
        string[] emails1 = {
            "mar.pha+science@corp.nstu.ru",
            "marpha+scie.nce@corp.nstu.ru",
            "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
        };
        Console.WriteLine($"Пример 1: {CountUniqueEmails(emails1)}"); // 1
        
        string[] emails2 = {
            "mar.pha+science@co.rp.nstu.ru",
            "marpha+scie.nce@c.orp.nstu.ru",
            "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
        };
        Console.WriteLine($"Пример 2: {CountUniqueEmails(emails2)}"); // 2
    }
}