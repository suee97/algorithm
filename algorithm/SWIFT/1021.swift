import Foundation

let input = readLine()!.split(separator: " ")
let n = Int(input[0])!
let m = Int(input[1])!

var ans = 0
var q = Array(1...n)

let nums = readLine()!.split(separator: " ").map {
    Int($0)!
}

for e in nums {
    if e == q.first! {
        pop()
        continue
    }

    var index: Int = -1
    for i in 0..<n {
        if q[i] == e {
            index = i
            break;
        }
    }
    
    if index > q.count/2 {
        while (true) {
            if third() == e {
                break
            }
        }
    } else {
        while (true) {
            if second() == e {
                break
            }
        }
    }

    pop()
}

func pop() {
    q.removeFirst()
}

func second() -> Int {
    let tmp = q.removeFirst()
    q.append(tmp)
    ans += 1
    return q.first!
}

func third() -> Int {
    let tmp = q.removeLast()
    q.insert(tmp, at: 0)
    ans += 1
    return q.first!
}

print(ans)