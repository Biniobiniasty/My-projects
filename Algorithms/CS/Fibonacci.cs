namespace CiagFibonacciego
{
    class Fibonacci
    {
        static void Main(String[] args)
        {
            string info = "Fibonacci{rekurencyjnie}{iteracyjnie}";

            for (int x = 0; x <= 20; x++)
                Console.WriteLine(info + "[" + x + "] = {" + Oblicz_rekurencyjnie(x) + "}{" + Oblicz_iteracyjnie(x) + "}");

        }
        static int Oblicz_rekurencyjnie(int x)
        {
            if (x <= 0)
                return 0;
            if (x == 1)
                return 1;
            return (Oblicz_rekurencyjnie(x - 1) + Oblicz_rekurencyjnie(x - 2));
        }

        static int Oblicz_iteracyjnie(int x)
        {
            if (x == 0)
                return 0;
            if (x == 1)
                return 1;
            if (x == 2)
                return 1;

            int wart1 = 1;
            int wart2 = 1;
            int sum = 2;

            for(int i=2;i<x;i++)
            {
                sum = wart1 + wart2;
                wart1 = wart2;
                wart2 = sum;
            }

            return sum;
        }
    }
}
