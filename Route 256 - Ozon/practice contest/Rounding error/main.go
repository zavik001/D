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
		var n, p int
		fmt.Fscan(reader, &n, &p)

		totalLost := 0.0

		for j := 0; j < n; j++ {
			var a int
			fmt.Fscan(reader, &a)

			commission := float64(a) * float64(p) / 100.0
			lost := commission - float64(int(commission))
			totalLost += lost
		}

		fmt.Fprintf(writer, "%.2f\n", totalLost)
	}
}
