import Foundation

var sum : Int = 0

while(true) {
    let line = readLine()
    let array : Array<String> = line!.components(separatedBy: " ")
    if(Int(array[0])! == 0 && Int(array[1])! == 0) {
        break
    }
    sum += Int(array[0])! + Int(array[1])!
    print(sum)
    sum = 0
}
