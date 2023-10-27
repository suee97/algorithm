import Foundation

let N = Int(readLine()!)!
let K = Int(readLine()!)!
let sensorArr = readLine()!.split(separator: " ").map{ Int(String($0))! }.sorted(by: <)
var intervalArr = [Int]()
var sum = 0

if N == 1 {
    sum = 0
} else if K == 1 {
    sum = sensorArr.max()! - sensorArr.min()!
} else {
    for i in 0...N-2 {
        intervalArr.append(sensorArr[i+1] - sensorArr[i])
    }
    intervalArr = intervalArr.sorted(by: >)

    for i in 0...N-2 {
        sum += intervalArr[i]
    }

    for i in 0...K-2 {
        sum -= intervalArr[i]
    }
}

print(sum)
