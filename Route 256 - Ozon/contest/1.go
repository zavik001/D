package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	reader.Scan()
	t, _ := strconv.Atoi(reader.Text())

	for i := 0; i < t; i++ {
		reader.Scan()
		s := reader.Text()
		n := len(s)

		if n != 1 {
			maxNum := s[1:]
			for j := 1; j < len(s); j++ {
				cur := s[:j] + s[j+1:]
				if cur > maxNum {
					maxNum = cur
				}
			}

			fmt.Fprintln(writer, maxNum)
		} else {
			fmt.Fprintln(writer, 0)
		}
	}
}
