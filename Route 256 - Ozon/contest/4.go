package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())

	for t > 0 {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())

		scanner.Scan()
		line := scanner.Text()
		parts := strings.Fields(line)
		A := make(map[int]int)

		for _, part := range parts {
			num, _ := strconv.Atoi(part)
			A[num]++
		}

		scanner.Scan()
		line = scanner.Text()
		tokens := strings.Fields(line)
		var parsedTokens []int
		flag := true

		for _, token := range tokens {
			x, err := strconv.Atoi(token)
			if err != nil {
				flag = false
				break
			}
			parsedTokens = append(parsedTokens, x)
		}

		if flag && len(parsedTokens) == n {
			sortedTokens := make([]int, len(parsedTokens))
			copy(sortedTokens, parsedTokens)
			sort.Ints(sortedTokens)

			if !equal(parsedTokens, sortedTokens) {
				flag = false
			}

			for _, num := range parsedTokens {
				if _, found := A[num]; !found {
					flag = false
					break
				}
			}
		} else {
			flag = false
		}

		if flag {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}

		t--
	}
}

func equal(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
