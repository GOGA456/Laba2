def normalize_email(email):
    at_pos = email.find('@')
    if at_pos == -1:
        return email
    
    username = email[:at_pos]
    domain = email[at_pos:]
    
    # Удаляем точки из имени пользователя
    username = username.replace('.', '')
    
    # Удаляем всё после плюса, если он есть
    plus_pos = username.find('+')
    if plus_pos != -1:
        username = username[:plus_pos]
    
    return username + domain

def count_unique_emails(emails):
    normalized_emails = {normalize_email(email) for email in emails}
    return len(normalized_emails)

emails1 = [
    "mar.pha+science@corp.nstu.ru",
    "marpha+scie.nce@corp.nstu.ru",
    "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
]
print(f"Пример 1: {count_unique_emails(emails1)}")  # Должно быть 1

emails2 = [
    "mar.pha+science@co.rp.nstu.ru",
    "marpha+scie.nce@c.orp.nstu.ru",
    "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
]
print(f"Пример 2: {count_unique_emails(emails2)}")  # Должно быть 3