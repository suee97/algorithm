mport Foundation

var tmpArr1 = [Int](repeating: -99999999, count: 51)
var tmpArr2 = [[Int]](repeating: tmpArr1, count: 51)
var arr = [[[Int]]](repeating: tmpArr2, count: 51)

while(true) {
    let inputStr = readLine()!
    let inputArr = inputStr.split(separator: " ").map{Int(String($0))!}
    let a = inputArr[0], b = inputArr[1], c = inputArr[2]
    if(a == -1 && b == -1 && c == -1) {
        break
    }
    let ans = w(a: a, b: b, c: c)
    print("w(\(a), \(b), \(c)) = \(ans)")
}

func w(a: Int, b: Int, c: Int) -> Int {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1
    }
    if(arr[a][b][c] != -99999999) {
        return arr[a][b][c]
    }
    if (a > 20 || b > 20 || c > 20) {
        let tmp1 = w(a: 20, b: 20, c: 20)
        arr[20][20][20] = tmp1
        return tmp1
    }
    if (a < b && b < c) {
        let tmp1 = w(a: a, b: b, c: c-1)
        let tmp2 = w(a: a, b: b-1, c: c-1)
        let tmp3 = w(a: a, b: b-1, c: c)
        arr[a][b][c-1] = tmp1
        arr[a][b-1][c-1] = tmp2
        arr[a][b-1][c] = tmp3
        return tmp1 + tmp2 - tmp3
    }
    let tmp1 = w(a: a-1, b: b, c: c)
    let tmp2 = w(a: a-1, b: b-1, c: c)
    let tmp3 = w(a: a-1, b: b, c: c-1)
    let tmp4 = w(a: a-1, b: b-1, c: c-1)
    arr[a-1][b][c] = tmp1
    arr[a-1][b-1][c] = tmp2
    arr[a-1][b][c-1] = tmp3
    arr[a-1][b-1][c-1] = tmp4
    return tmp1 + tmp2 + tmp3 - tmp4
}
