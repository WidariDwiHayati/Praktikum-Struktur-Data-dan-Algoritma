package main

import (
    "fmt"
)

func main() {
    var celcius float64
    fmt.Print("Temperatur Celcius: ")
    fmt.Scan(&celcius)
    
    fahrenheit := (celcius * 9 / 5) + 32
    reamur := celcius * 4 / 5
    kelvin := celcius + 273.15
    
    fmt.Printf("Derajat Fahrenheit: %.2f\n", fahrenheit)
    fmt.Printf("Derajat Reamur: %.2f\n", reamur)
    fmt.Printf("Derajat Kelvin: %.2f\n", kelvin)
}
