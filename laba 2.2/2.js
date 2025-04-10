function Email(email) {
    const at = email.indexOf('@');
    if (at === -1) return email;
    
    let username = email.substring(0, at);
    const domain = email.substring(at);
    
    username = username.replace(/\./g, '');
    const plus = username.indexOf('+');
    if (plus !== -1) {
        username = username.substring(0, plus);
    }
    
    return username + domain;
}

function countUniqueEmails(emails) {
    return new Set(emails.map(Email)).size;
}

const emails1 = [
    "mar.pha+science@corp.nstu.ru",
    "marpha+scie.nce@corp.nstu.ru",
    "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
];
console.log(`Пример 1: ${countUniqueEmails(emails1)}`); // 1

const emails2 = [
    "mar.pha+science@co.rp.nstu.ru",
    "marpha+scie.nce@c.orp.nstu.ru",
    "marph.a+s.c.i.e.n.c.e+@corp.nstu.ru"
];
console.log(`Пример 2: ${countUniqueEmails(emails2)}`); // 2