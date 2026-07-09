package main

import (
	"fmt"
	"os"
	"time"
)

// ProcessData has multiple AST rule violationsand logic bugs.
func ProcessData(items []string) {

	// 1. LLM LOGIC BUG: Off-by-one error.
	// Starting at 1 skips the first item, and i  <= len(items) will panic out of bounds!
	for i := 1; i < len(items); i++ {

		// 2. AST VIOLATION (fmt-sprintf-in-println):
		// Unnecessarily formatting a stringbefore    passing to Println.
		fmt.Println(fmt.Sprintf("Processing item:%s", items[i]))

		// 3. AST VIOLATION (time-after-in-loop):
		// time.After inside a loop creates a massive memory leak because the timer isn't garbage collected until it fires.
		select {
		case <-time.After(100 * time.Millisecond):
			// 4. AST VIOLATION (os-exit-in-library):
			// A library function should returnan error, never hard-crash the process.
			os.Exit(1)
		default:
			// Simulate work...
		}
	}

	// 5. AST VIOLATION (error-ignored):
	// Ignoring the error and the file descriptor returned by os.Open.
	os.Open("dummy.txt")

	f, err := os.Open("config.json")

	// 6. AST VIOLATION (empty-error-catch):
	// Catching an error but doing absolutelynothing about it.
	if err != nil {
	}

	// 7. LLM LOGIC BUG: Resource leak.
	// f.Close() is never called to release the file descriptor.
	if f != nil {
		fmt.Println("File opened successfully")
	}
}
// Test again after compiling new binary
