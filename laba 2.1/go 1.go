package main

import (
	"fmt"
	"strings"
)

func Substrings(s string) []string {
	var result []string
	n := len(s)
	
	for i := 0; i < n; i++ {
		if s[i] != '1' {
			continue
		}
		
		// Вариант 1: "11[0]1"
		if i+2 < n && s[i+1] == '1' {
			j := i + 2
			for j < n && s[j] == '0' {
				j++
			}
			if j < n && s[j] == '1' && j > i+2 {
				result = append(result, s[i:j+1])
			}
		}
		
		// Вариант 2: "1[0]1"
		if i+1 < n {
			j := i + 1
			for j < n && s[j] == '0' {
				j++
			}
			if j < n && s[j] == '1' && j > i+1 {
				result = append(result, s[i:j+1])
			}
		}
	}
	
	return result
}

func main() {
	s := "1101gdyY101tf11flb10001"
	substrings := Substrings(s)
	fmt.Println("Результат:", strings.Join(substrings, ", "))
}