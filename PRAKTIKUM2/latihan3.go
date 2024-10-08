package main

import (
    "fmt"
)

func main() {
    var jariJari int
    fmt.Print("Jejari: ")
    fmt.Scan(&jariJari)
    
    // Konstanta π
    const pi = 3.1415926535

    // Volume bola
    volumeBola := (4.0 / 3.0) * pi * float64(jariJari * jariJari * jariJari)
    
    // Luas kulit bola
    luasBola := 4 * pi * float64(jariJari * jariJari)

    // Menampilkan hasil
    fmt.Printf("Bola dengan jejari %d memiliki volume %.4f dan luas kulit %.4f\n", jariJari, volumeBola, luasBola)
}
