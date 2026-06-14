package main

import (
	"fmt"
)

func main() {
	fmt.Println("Hello, World!")
	fmt.Println("This is a test program.")
	fmt.Printf("Checking custom analyzer: %d", 100)
	fmt.Printf("Checking comment ability: %d", 100)

	// Test LLM logic that it outputs nothing for no new issue
	// as it ignores ast issues and only outputs new issues

	// Test after model fix

	// Test for a bug
	// items := []int{10, 20, 30, 40, 50}
	// total := 0
	// for i := 0; i <= len(items); i++ {
	// 	total += items[i]
	// }
	// fmt.Printf("Total: %d", total)
	
}

// Issues:
// No comment chunking
// Writing comment on the code already commented
