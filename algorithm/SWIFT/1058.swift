import Foundation

let n = Int(readLine()!)!
var ans = 0

var board = Array(repeating: Array(repeating: "", count: n), count: n)

for i in 0..<n {
    let line = readLine()!
    let tmp = Array(line)
    for j in 0..<n {
        board[i][j] = "\(tmp[j])"
    }
}

for st in 0..<n {
    var dist = Array(repeating: 2000000000, count: n)
    dist[st] = 0

    var q = [Int]()
    var size = 0
    q.append(st)
    size += 1

    while (size != 0) {
        let cur = q.first!
        q.removeFirst()
        size -= 1
        
        for i in 0..<n {
            if (board[cur][i] == "N" || dist[i] != 2000000000) {
                continue
            }
            q.append(i)
            size += 1
            
            dist[i] = dist[cur] + 1
        }
    }

    var cnt = 0
    for e in dist {
        if (e != 0 && e <= 2) {
            cnt += 1
        }
    }

    ans = max(ans, cnt)
}

print(ans)