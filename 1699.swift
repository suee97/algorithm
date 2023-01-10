import Foundation

var n = Int(String(readLine()!))!
var dp : Array<Int> = Array(repeating: 999, count: n+1)

dp[0] = 0
dp[1] = 1

for i in 1...n {
    var a = 1
    for j in 1...i {
        if(j*j > i) {
            a = j - 1
            break
        }
        if(j*j == i) {
            a = j
            break
        }
    }
    for k in 1...a {
        let q = i/(k*k)
        let r = i%(k*k)
        if(q + dp[r] < dp[i]) {
            dp[i] = q + dp[r]
        }
    }
}

print(dp[n])
