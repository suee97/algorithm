// 못 풂
import Foundation

let maxNum : Int = 1100000
var arr : Array<Int> = Array(repeating: 0, count: maxNum+1)
arr[1] = 1
arr[2] = 1
arr[3] = 1
let inputN = Int(readLine()!)!

func getMinCal(N : Int) -> Int {
    if (arr[N] != 0) {
        return arr[N]
    }

    arr[N] = min((N%3 == 0) ? getMinCal(N: N/3) : maxNum, (N%2 == 0) ? getMinCal(N: N/2) : maxNum, getMinCal(N: N-1)) + 1
    return arr[N]
}

print(getMinCal(N: inputN))
