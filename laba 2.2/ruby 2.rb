def email(email)
    at = email.index('@')
    return email if at.nil?
    
    username = email[0...at]
    domain = email[at..-1]
    
    username = username.gsub('.', '')
    plus = username.index('+')
    username = username[0...plus] if plus
    
    username + domain
end

def count_unique_emails(emails)
    emails.map { |email| email(email) }.uniq.size
end

emails1 = [
    "mar.pha+science@corp.nstu.ru",
    "marpha+scie.nce@corp.nstu.ru",
    "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
]
puts "Пример 1: #{count_unique_emails(emails1)}" # 1

emails2 = [
    "mar.pha+science@co.rp.nstu.ru",
    "marpha+scie.nce@c.orp.nstu.ru",
    "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
]
puts "Пример 2: #{count_unique_emails(emails2)}" # 2