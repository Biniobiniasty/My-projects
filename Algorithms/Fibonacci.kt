

fun main(args: Array<String>)
{
    var Fib = Fibonacci()

    var x=0
    while(x <= 20)
    {
        println("Fibonacci{it}{rek}["+x+"] = {"+Fib.Iteracyjnie(x) + "}{" + Fib.Rekurencyjnie(x) + "}")
        x++
    }

}

class Fibonacci
{
    fun Rekurencyjnie(x :Int) : Int
    {
        if(x <= 0)
            return 0
        if(x == 1)
            return 1
        return (Iteracyjnie(x-2) + Iteracyjnie(x-1))
    }

    fun Iteracyjnie(x :Int): Int
    {
        if(x <= 0)
            return 0
        if(x == 1)
            return 1

        var val1 = 0
        var val2 = 1
        var sum = val1 + val2

        var i = 2
        while(i <= x)
        {
            sum = val1 + val2
            val1 = val2
            val2 = sum
            i++
        }
        return sum
    }
}
