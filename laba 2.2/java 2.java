import java.util.*;

public class Main {
    public static String Email(String email) {
        int at = email.indexOf('@');
        if (at == -1) return email;
        
        String username = email.substring(0, at);
        String domain = email.substring(at);
        
        username = username.replace(".", "");
        int plus = username.indexOf('+');
        if (plus != -1) {
            username = username.substring(0, plus);
        }
        
        return username + domain;
    }
    
    public static int countUniqueEmails(String[] emails) {
        Set<String> uniqueEmails = new HashSet<>();
        for (String email : emails) {
            uniqueEmails.add(Email(email));
        }
        return uniqueEmails.size();
    }
    
    public static void main(String[] args) {
        String[] emails1 = {
            "mar.pha+science@corp.nstu.ru",
            "marpha+scie.nce@corp.nstu.ru",
            "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
        };
        System.out.println("Пример 1: " + countUniqueEmails(emails1)); // 1
        
        String[] emails2 = {
            "mar.pha+science@co.rp.nstu.ru",
            "marpha+scie.nce@c.orp.nstu.ru",
            "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
        };
        System.out.println("Пример 2: " + countUniqueEmails(emails2)); // 2
    }
}