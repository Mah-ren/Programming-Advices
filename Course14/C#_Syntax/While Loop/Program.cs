
//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

using System;
using System.Linq;


namespace Main
{
    internal class Program
    {

        static void Main(string[] args)
        {

            int i = 1;
            do
            {
                Console.WriteLine("C# while Loop: Iteration {0}", i);
                i++;

            } while (i <= 5);

            Console.ReadKey();


            int j = 1;
            do
            {

                Console.WriteLine("C# while Loop: Iteration {0}", j);

                if (j == 3)
                    break;

                j++;

            } while (j <= 5);

            Console.ReadKey();



            for (int k = 1; k <= 5; ++k)
            {

                if (k == 3)
                {
                    continue;
                }

                Console.WriteLine(k);
            }

            Console.ReadKey();


            //this is the ForEachLoop Example1
            
            char[] myArray = { 'H', 'e', 'l', 'l', 'o' };

            foreach (char ch in myArray)
            {
                Console.WriteLine(ch);
            }

            Console.ReadKey();


            //this is the ForEachLoop Example2

            char[] gender = { 'm', 'f', 'm', 'm', 'm', 'f', 'f', 'm', 'm', 'f' };
            int male = 0, female = 0;
            foreach (char g in gender)
            {
                if (g == 'm')
                    male++;
                else if (g == 'f')
                    female++;
            }
            Console.WriteLine("Number of male = {0}", male);
            Console.WriteLine("Number of female = {0}", female);

            Console.ReadKey();

            // Note that we used System.Linq above.

            int[] numbers = { 51, -1, 2, 14, 18, 40, 178 };
            Console.WriteLine("i think that i don't need to write the library " + numbers.Min());
            // get the minimum element
            Console.WriteLine("Smallest  Element: " + numbers.Min());

            // Max() returns the largest number in array
            Console.WriteLine("Largest Element: " + numbers.Max());

            Console.ReadKey();

            // Note that we used System.Linq above.

            int[] numbers_ = { 20, 22, 19, 18, 1 };

            // compute Count
            Console.WriteLine("Count : " + numbers_.Count());

            // compute Sum
            Console.WriteLine("Sum : " + numbers_.Sum());

            // compute the average
            Console.WriteLine("Average: " + numbers_.Average());

            Console.ReadKey();


            Console.WriteLine("Max of 5, 10 is: {0}", Math.Max(5, 10));
            Console.WriteLine("Min of 5, 10 is: {0}", Math.Min(5, 10));
            Console.WriteLine("Squir Root of 64 is: {0}", Math.Sqrt(64));
            Console.WriteLine("Absolute (positive) value of  -4.7 is: {0}", Math.Abs(-4.7));
            Console.WriteLine("Round of 9.99 is: {0}", Math.Round(9.99));
            Console.WriteLine($"Math.Pow(2, 4) {Math.Pow(2, 4)}");

            Console.ReadKey();


        }
    }
}

