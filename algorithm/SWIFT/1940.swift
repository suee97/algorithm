import Foundation

let n = Int(readLine()!)!
let m = Int(readLine()!)!

var arr = readLine()!.split(separator: " ").map {
    Int($0)!
}

arr.sort(by: <)

var st = 0
var end = arr.count-1

var ans = 0
while (st < end) {
    let tmp = arr[st] + arr[end]
    if tmp == m {
        st += 1
        end -= 1
        ans += 1
    } else if (tmp < m) {
        st += 1
    } else {
        end -= 1
    }
}

print(ans)