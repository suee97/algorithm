import Foundation

let n: Int = Int(readLine()!)!
var inputArr: [Int] = Array(repeating: 0, count: n)
for i in 0...n-1 {
    let tmp: Int = Int(readLine()!)!
    inputArr[i] = tmp
}

inputArr.sort()

var max: Int = 0
for i in 0...n-1 {
    let curValue = inputArr[i] * (inputArr.count - i)
    if max < curValue {
        max = curValue
    }
}

print(max)
