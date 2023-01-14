import Foundation

let tmp = readLine()!.split(separator: " ").map{ Int(String($0))! }
let N = tmp[0]
var K = tmp[1]
var count = 0
var arr = [Int]()
for _ in 1...N {
    let tmp = Int(readLine()!)!
    arr.append(tmp)
}

while true {
    var max = 0
    for i in 0...N-1 {
        if arr[i] <= K && arr[i] > max {
            max = arr[i]
        }
    }
    K -= max
    count += 1
    if K <= 0 {
        break
    }
}

print(count)
