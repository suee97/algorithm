let N = Int(readLine()!)!
var inputArr = readLine()!.split(separator: " ").map{ Int(String($0))! }
var minCount = 0

while(true) {
    for i in 0...N-1 {
        if inputArr[i] % 2 == 1 {
            inputArr[i] -= 1
            minCount += 1
        }
    }
    if isFinish() { break }
    divideByTwo()
}

func divideByTwo() {
    inputArr = inputArr.map { $0 / 2 }
    minCount += 1
}

func isFinish() -> Bool {
    var sum = 0
    for i in 0...N-1 {
        sum += inputArr[i]
    }
    if sum == 0 {
        return true
    }
    return false
}

print(minCount)
