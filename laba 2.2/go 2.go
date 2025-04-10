package main

import (
	"fmt"
	"strings"
)

func Email(email string) string {
	at := strings.Index(email, "@")
	if at == -1 {
		return email
	}
	
	username := email[:at]
	domain := email[at:]
	
	username = strings.Replace(username, ".", "", -1)
	if plus := strings.Index(username, "+"); plus != -1 {
		username = username[:plus]
	}
	
	return username + domain
}

func countUniqueEmails(emails []string) int {
	unique := make(map[string]bool)
	for _, email := range emails {
		unique[Email(email)] = true
	}
	return len(unique)
}

func main() {
	emails1 := []string{
		"mar.pha+science@corp.nstu.ru",
		"marpha+scie.nce@corp.nstu.ru",
		"marph.a+s.c.i.e.n.c.e+@corp.nstu.ru",
	}
	fmt.Printf("Пример 1: %d\n", countUniqueEmails(emails1)) // 1
	
	emails2 := []string{
		"mar.pha+science@co.rp.nstu.ru",
		"marpha+scie.nce@c.orp.nstu.ru",
		"marph.a+s.c.i.e.n.c.e+@corp.nstu.ru",
	}
	fmt.Printf("Пример 2: %d\n", countUniqueEmails(emails2)) // 2
}