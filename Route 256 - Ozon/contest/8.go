package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func dfs(node int, adj [][]int, visited []bool, component *[]int) {
	visited[node] = true
	*component = append(*component, node)
	for _, neighbor := range adj[node] {
		if !visited[neighbor] {
			dfs(neighbor, adj, visited, component)
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int
	fmt.Fscanf(reader, "%d\n", &t)

	for ; t > 0; t-- {
		var n, m int
		fmt.Fscanf(reader, "%d %d\n", &n, &m)

		adj := make([][]int, n)
		edges := make([][2]int, m)

		for i := 0; i < m; i++ {
			var a, b int
			fmt.Fscanf(reader, "%d %d\n", &a, &b)
			a--
			b--
			adj[a] = append(adj[a], b)
			adj[b] = append(adj[b], a)
			edges[i] = [2]int{a, b}
		}

		visited := make([]bool, n)
		maxOnComputers := 0
		var switches []int

		for i := 0; i < n; i++ {
			if !visited[i] {
				var component []int
				dfs(i, adj, visited, &component)

				maxOnComputers += len(component)

				var componentEdges []int
				for j := 0; j < m; j++ {
					a, b := edges[j][0], edges[j][1]
					if contains(component, a) && contains(component, b) {
						componentEdges = append(componentEdges, j+1)
					}
				}

				switches = append(switches, componentEdges[:len(component)-1]...)
			}
		}

		fmt.Fprintf(writer, "%d\n", maxOnComputers)
		fmt.Fprintf(writer, "%d\n", len(switches))
		switchStrings := make([]string, len(switches))
		for i, s := range switches {
			switchStrings[i] = strconv.Itoa(s)
		}
		fmt.Fprintf(writer, "%s\n", strings.Join(switchStrings, " "))
	}
}

func contains(slice []int, value int) bool {
	for _, v := range slice {
		if v == value {
			return true
		}
	}
	return false
}
