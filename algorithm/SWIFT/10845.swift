import Foundation

let n = Int(readLine()!)!

var q = [Int]()
var size = 0

for _ in 1...n {
    let str = readLine()!.split(separator: " ")
    switch str[0] {
    case "push":
        q.append(Int(str[1])!)
        size += 1
    case "pop":
        if (size == 0) {
            print(-1)
        } else {
            let res = q.removeFirst()
            size -= 1
            print(res)
        }
    case "size":
        print(size)
    case "empty":
        size == 0 ? print(1) : print(0)
    case "front":
        let res = q.first ?? -1
        print(res)
    default: // "back"
        let res = q.last ?? -1
        print(res)
    }
}