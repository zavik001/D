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
		var m int
		fmt.Fscan(reader, &m)

		a := make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Fscan(reader, &a[j])
		}

		childCount := make(map[int]int)

		for j := 0; j < m; {
			children := a[j+1]

			for k := 0; k < children; k++ {
				childVertex := a[j+2+k]
				childCount[childVertex]++
			}

			j += 2 + children
		}

		var root int
		for j := 0; j < m; {
			vertex := a[j]
			if _, isChild := childCount[vertex]; !isChild {
				root = vertex
				break
			}
			children := a[j+1]
			j += 2 + children
		}

		fmt.Fprintln(writer, root)
	}
}
