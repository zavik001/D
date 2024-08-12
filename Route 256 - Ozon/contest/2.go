package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int
	fmt.Fscanf(reader, "%d\n", &t)

	for ; t > 0; t-- {
		var n int
		fmt.Fscanf(reader, "%d\n", &n)

		l := make([]int, n)
		r := make([]int, n)

		for i := 0; i < n; i++ {
			fmt.Fscanf(reader, "%d", &l[i])
		}
		fmt.Fscanf(reader, "\n")

		for i := 0; i < n; i++ {
			fmt.Fscanf(reader, "%d", &r[i])
		}
		fmt.Fscanf(reader, "\n")

		result := 1

		for i := 1; i <= n; i++ {
			minA := ((l[i-1] + i - 1) / i) * i
			maxA := (r[i-1] / i) * i

			if minA > maxA {
				result = 0
				break
			}

			count := (maxA/i - minA/i + 1) % MOD
			result = (result * count) % MOD
		}

		fmt.Fprintln(writer, result)
	}
}
