import Foundation

let n : Int = Int(readLine()!)!
var memo : Array<Int> = Array(repeating: 0, count: 12)
memo[1] = 1
memo[2] = 2
memo[3] = 4

for _ in 1...n {
    let getNum : Int = Int(readLine()!)!
    let res : Int = getCount(num: getNum)
    print(res)
}

func getCount(num : Int) -> Int {
    if(num < 4 || memo[num] != 0) {
        return memo[num]
    }
    memo[num] = getCount(num: num-1) + getCount(num: num-2) + getCount(num: num-3)
    return memo[num]
}
