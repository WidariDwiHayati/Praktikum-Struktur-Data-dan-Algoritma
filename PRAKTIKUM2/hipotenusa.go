package main
import "fmt"

func main() {
	var a, b, c float64
	var hipotenusa bool

	fmt.Scanln(&a, &b, &c)
	hipotenusa = (c*c) == (a*a + b*b)
	fmt.Println("Sisi c adalah hipotenusa segitiga a,b,c: ", hipotenusa)
}