namespace SitoErastotenesa
{
    class Erastotenes
    {
        static void Main(String[] args)
        {
            Console.WriteLine("Sito Erastotenesa: ");
            Erastotenes fun = new Erastotenes();
            fun.Oblicz(200);
        }

        public void Oblicz(int x)
        {
            int[] tab = new int[x];

            for (int i = 0; i < x; i++)
                tab[i] = 0;

            for(int i=2;i<= (int)Math.Sqrt(x);i++)
            {
                int index = i * 2;
                while(index < x)
                {
                    tab[index] = 1;
                    index += i;
                }
            }

            for (int i = 2; i < x; i++)
                if (tab[i] == 0)
                    Console.Write(i + ", ");
        }
    }
}
