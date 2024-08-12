package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Record struct {
	name string
	id   int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	tStr, _ := reader.ReadString('\n')
	t, _ := strconv.Atoi(strings.TrimSpace(tStr))

	for ; t > 0; t-- {
		nStr, _ := reader.ReadString('\n')
		n, _ := strconv.Atoi(strings.TrimSpace(nStr))

		records := make([]Record, n+1)

		for i := 1; i <= n; i++ {
			line, _ := reader.ReadString('\n')
			parts := strings.Fields(line)

			if parts[0] == "CHANGE" {
				name := parts[1]
				id, _ := strconv.Atoi(parts[2])
				records[i] = Record{name: name, id: id}
			} else if parts[0] == "GET" {
				id, _ := strconv.Atoi(parts[1])
				time, _ := strconv.Atoi(parts[2])

				if records[time].id == id {
					fmt.Fprintln(writer, records[time].name)
				} else {
					fmt.Fprintln(writer, "404")
				}
				records[i] = Record{name: "404", id: -1}
			}
		}
	}
}
