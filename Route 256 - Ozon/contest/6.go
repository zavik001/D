package main

import (
	"bufio"
	"fmt"
	"os"
)

func canWin(board [][]byte, k, n, m int) bool {
	for i := 0; i < n; i++ {
		for j := 0; j <= m-k; j++ {
			countX, countDot := 0, 0
			for l := 0; l < k; l++ {
				if board[i][j+l] == 'X' {
					countX++
				} else if board[i][j+l] == '.' {
					countDot++
				} else {
					break
				}
			}
			if countX == k-1 && countDot == 1 {
				return true
			}
		}
	}

	for j := 0; j < m; j++ {
		for i := 0; i <= n-k; i++ {
			countX, countDot := 0, 0
			for l := 0; l < k; l++ {
				if board[i+l][j] == 'X' {
					countX++
				} else if board[i+l][j] == '.' {
					countDot++
				} else {
					break
				}
			}
			if countX == k-1 && countDot == 1 {
				return true
			}
		}
	}

	for i := 0; i <= n-k; i++ {
		for j := 0; j <= m-k; j++ {
			countX, countDot := 0, 0
			for l := 0; l < k; l++ {
				if board[i+l][j+l] == 'X' {
					countX++
				} else if board[i+l][j+l] == '.' {
					countDot++
				} else {
					break
				}
			}
			if countX == k-1 && countDot == 1 {
				return true
			}
		}
	}

	for i := 0; i <= n-k; i++ {
		for j := k - 1; j < m; j++ {
			countX, countDot := 0, 0
			for l := 0; l < k; l++ {
				if board[i+l][j-l] == 'X' {
					countX++
				} else if board[i+l][j-l] == '.' {
					countDot++
				} else {
					break
				}
			}
			if countX == k-1 && countDot == 1 {
				return true
			}
		}
	}

	return false
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var t int
	fmt.Fscan(reader, &t)

	for t > 0 {
		t--

		var k, n, m int
		fmt.Fscan(reader, &k, &n, &m)

		board := make([][]byte, n)
		for i := 0; i < n; i++ {
			board[i] = make([]byte, m)
			fmt.Fscan(reader, &board[i])
		}

		if canWin(board, k, n, m) {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
