import Foundation

let input = readLine()!.split(separator: " ")
let n = Int(input[0])!
let m = Int(input[1])!

var dic = [String : String]()
for _ in 0..<n {
    let input = readLine()!.split(separator: " ")
    dic["\(input[0])"] = "\(input[1])"
}

for _ in 0..<m {
    let input = readLine()!
    print(dic[input]!)
}