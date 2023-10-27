import Foundation

let line1 = readLine()!.split(separator: " ")
let n = Int(line1[0])!
let m = Int(line1[1])!

var board = Array(repeating: Array(repeating: -1, count: m), count: n)

for i in 0..<n {
    let tmp = readLine()!.split(separator: " ").map { Int($0)! }
    for j in 0..<m {
        board[i][j] = tmp[j]
    }
}

var ansTable = Array(repeating: Array(repeating: 0, count: m), count: n)
ansTable[0][0] = board[0][0]

let dx = [0, -1, -1]
let dy = [-1, -1, 0]

for i in 0..<n {
    for j in 0..<m {
        for dir in 0..<3 {
            let nx = i + dx[dir]
            let ny = j + dy[dir]
            if (nx < 0 || ny < 0) {
                continue
            }
            ansTable[i][j] = max(ansTable[i][j], ansTable[nx][ny] + board[i][j])
        }
    }
}

print(ansTable[n-1][m-1])