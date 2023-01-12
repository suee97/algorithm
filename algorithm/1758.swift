import Foundation

let N = Int(readLine()!)!
var inputArr = [Int]()
var sum = 0
for _ in 1...N {
    let tmp = Int(readLine()!)!
    inputArr.append(tmp)
}
let priceArr = inputArr.sorted(by: >)

for i in 0...N-1 {
    let tmp = priceArr[i] - i
    if tmp >= 0 {
        sum += tmp
    }
}

print(sum)
