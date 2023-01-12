// 못 풂
import Foundation

let num = Int(readLine()!)!
let numArray = readLine()!.split(separator: " ").map { Int(String($0))! }

var dp = Array(repeating: 1, count: num + 1)

for i in 1..<numArray.count {
    for j in 0..<i {
        if numArray[j] < numArray[i] {
            dp[i] = max(dp[i], dp[j] + 1)
        }
    }
}

print(dp.max()!)
