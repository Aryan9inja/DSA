package main

import (
	"fmt"
)

func main() {
	fmt.Println("Hello, World!")
	fmt.Println("This is a test program.")
	// TODO
	// Check custom analyzer
	// Testing again after go update
	fmt.Print(fmt.Sprintf("Checking custom analyzer: %d", 100))
	fmt.Print(fmt.Sprintf("Checking comment ability: %d", 100))
}

// Issues:
// No comment chunking
// Writing comment on the code already commented