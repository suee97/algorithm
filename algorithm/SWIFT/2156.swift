// 못 풂
import Foundation

let n = Int(readLine()!)!
var podoju: [Int] = []
var dp = Array(repeating: 0, count: n+1)
podoju.append(0)

for _ in 1...n {
    podoju.append(Int(readLine()!)!)
}

dp[1] = podoju[1]

if n > 1 {
    dp[2] = podoju[2]+podoju[1]
}

if n > 2{
    for i in 3..<n+1 {
        dp[i] = max(dp[i-1], dp[i-3] + podoju[i-1] + podoju[i], dp[i-2] + podoju[i])
    }
}

print(dp[n])
