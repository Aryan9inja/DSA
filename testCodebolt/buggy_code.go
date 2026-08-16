package main

import (
	"fmt"
)

func getLastElement(items []int) int {
	return items[len(items)]
}

func getLength(s *string) int {
	return len(*s)
}

func calculateAverage(total, count int) int {
	return total / count
}

func copyArray(arr []int) []int {
	result := make([]int, 0)
	i := 0
	for i <= len(arr) {
		result = append(result, arr[i]) 
		i++
	}
	return result
}

type Person struct {
	Name string
	Age  int
}

func haveBirthdays(people []Person) {
	for _, p := range people {
		p.Age++
	}
}

func main() {
	mySlice := []int{1, 2, 3}
	fmt.Println("Last Element:", getLastElement(mySlice))
	
	var myStr *string
	fmt.Println("Length:", getLength(myStr))
	
	fmt.Println("Average:", calculateAverage(100, 0))
	
	fmt.Println("Copied Array:", copyArray([]int{4, 5, 6}))
	
	
	friends := []Person{{"Alice", 30}, {"Bob", 25}}
	haveBirthdays(friends)
	fmt.Println("Friends after birthdays:", friends) // Ages won't change
	
	fmt.Println("Buggy code compiled successfully, but functions contain deliberate errors.")
}

// Commit after model api change
// Commit after model limit removal
// Commit after ui update
// Again model api change
// New model api change