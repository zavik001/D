package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func processYAML(input []string) []string {
	var result []string
	stack := []string{}
	var prevPath string

	for _, line := range input {
		level := 0
		for j := 0; j < len(line); j++ {
			if line[j] == ' ' {
				level++
			} else {
				break
			}
		}
		level /= 4
		line = strings.TrimSpace(line)

		if strings.HasSuffix(line, ":") {
			section := line[:len(line)-1]
			if level < len(stack) {
				stack = stack[:level]
			}
			stack = append(stack, section)
		} else {
			if level < len(stack) {
				stack = stack[:level]
			}
			parts := strings.SplitN(line, ": ", 2)
			key, value := parts[0], parts[1]
			path := strings.Join(stack, ".")
			if path != prevPath {
				if prevPath != "" {
					result = append(result, "")
				}
				if path != "" {
					result = append(result, fmt.Sprintf("[%s]", path))
				}
				prevPath = path
			}
			result = append(result, fmt.Sprintf("%s = %s", key, value))
		}
	}
	return result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	t := 0
	fmt.Sscanf(scanner.Text(), "%d", &t)

	var results [][]string
	for i := 0; i < t; i++ {
		scanner.Scan()
		n := 0
		fmt.Sscanf(scanner.Text(), "%d", &n)
		var input []string
		for j := 0; j < n; j++ {
			scanner.Scan()
			input = append(input, scanner.Text())
		}
		results = append(results, processYAML(input))
	}

	// Выводим результаты
	for idx, result := range results {
		for _, line := range result {
			fmt.Println(line)
		}
		// Добавляем пустую строку после каждого INI-файла, кроме последнего
		if idx < len(results)-1 {
			fmt.Println()
		}
	}
}
