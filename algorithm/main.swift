import Foundation

var inputString = readLine()!
inputString.append(".")
var tmpArr = [Character]()
var resultArr = [Character]()

for ch in inputString {
    if ch != "." {
        tmpArr.append(ch)
    } else {
        editAndAppend(tmpArr)
        resultArr.append(".")
        tmpArr.removeAll()
    }
}

func editAndAppend(_ arr: [Character]) {
    if arr.count % 2 == 0 && arr.count != 0 {
        let count4 = arr.count / 4
        let count2 = arr.count % 4
        if count4 >= 1 {
            for _ in 1...count4*4 {
                resultArr.append("A")
            }
        }
        if count2 >= 1 {
            for _ in 1...count2 {
                resultArr.append("B")
            }
        }
    } else if arr.count == 0 {

    } else {
        resultArr.append("E")
    }
}

resultArr.remove(at: resultArr.count-1)

func getRes() -> String {
    var resString: String = ""
    for i in 0...resultArr.count-1 {
        if resultArr[i] == "E" {
            return "-1"
        } else {
            resString.append(resultArr[i])
        }
    }
    return resString
}

print(getRes())
