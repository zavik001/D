package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int
	fmt.Fscan(reader, &t)

	for i := 0; i < t; i++ {
		var n int
		fmt.Fscan(reader, &n)

		a := make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Fscan(reader, &a[j])
		}

		if n <= 2 {
			fmt.Fprintln(writer, n)
		} else {
			prev1 := a[0]
			prev2 := a[1]
			maxLenght := 2
			answer := 0

			for j := 2; j < n; j++ {
				if a[j] == prev1 || a[j] == prev2 {
					maxLenght++
				} else {
					prev1 = prev2
					prev2 = a[j]
					maxLenght = 2
				}

				answer = max(maxLenght, answer)
			}

			fmt.Fprintln(writer, answer)
		}
	}
}
