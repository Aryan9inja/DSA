package main

import (
	"fmt"
)

func main() {
	fmt.Println("Hello, World!")

	// Test for a bug
	// Checking if pg vector works fine
	items := []int{10, 20, 30, 40, 50}
	total := 0
	for i := 0; i <= len(items); i++ {
		total += items[i]
	}
	fmt.Printf("Total: %d", total)
}
