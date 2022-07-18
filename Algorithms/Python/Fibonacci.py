class CiagFibonacciego:
    
    def __init__(self, count):
        self.count = count

    def oblicz_iteracyjnie(self):
        if(self.count == 0):
            return 0
        if(self.count == 1):
            return 1

        value1 = 0 
        value2 = 1
        sum = value1 + value2

        for x in range(1, self.count):
            sum = value1 + value2
            value1 = value2
            value2 = sum

        return sum

    def rekurencja(self, x):
        if(x <= 0):
            return 0
        if(x == 1):
            return 1
        return (self.rekurencja(x-2) + self.rekurencja(x-1))

    def oblicz_rekurencyjnie(self):
        return self.rekurencja(self.count)

def main():
    fib = 10
    fun = CiagFibonacciego(fib)
    print("Fibonacci[{}] = {}".format(fib, fun.oblicz_iteracyjnie()))
    print("Fibonacci[{}] = {}".format(fib, fun.oblicz_rekurencyjnie()))


if(__name__ == "__main__"):
    main()
