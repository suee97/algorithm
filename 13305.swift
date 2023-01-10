import Foundation

let n = Int(String(readLine()!))!
let distanceArr = readLine()!.split(separator: " ").map{ Int(String($0))! }
let priceArr = readLine()!.split(separator: " ").map{ Int(String($0))! }
var breakPointArr = Array(repeating: 0, count: n)
breakPointArr[0] = 1
var curPointNum = priceArr[0]

var totalPrice = distanceArr[0] * priceArr[0]
var curOperand = priceArr[0]

for i in 1...n-1 {
    if curPointNum > priceArr[i] {
        breakPointArr[i] = 1
        curPointNum = priceArr[i]
    }
}

for i in 1...n-2 {
    if breakPointArr[i] == 0 {
        totalPrice = totalPrice + (curOperand * distanceArr[i])
    } else {
        curOperand = priceArr[i]
        totalPrice = totalPrice + (curOperand * distanceArr[i])
    }
}

print(totalPrice)
