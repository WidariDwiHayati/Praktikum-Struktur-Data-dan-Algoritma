package main

import "fmt"

func main() {
    var a, b, c, d, e int
    var char1, char2, char3 byte

    fmt.Scanf("%d %d %d %d %d\n", &a, &b, &c, &d, &e)
    
    fmt.Printf("%c%c%c%c%c\n", a, b, c, d, e)

    fmt.Scanf("%c%c%c\n", &char1, &char2, &char3)
    
    fmt.Printf("%c%c%c\n", char1+1, char2+1, char3+1)
}