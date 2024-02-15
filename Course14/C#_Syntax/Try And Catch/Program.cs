//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

using System;
using System.Runtime.Remoting.Messaging;


namespace Main
{
    internal class Program
    {

        static void Main(string[] args)
        {

            // Try and catch
            try
            {
                int[] myNumbers = { 1, 2, 3 };
                Console.WriteLine(myNumbers[10]);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            Console.ReadLine();

            // Random 
            Random rnd = new Random();

            for (int j = 0; j < 4; j++)
            {
                Console.WriteLine(rnd.Next(10, 20)); // returns random integers >= 10 and < 20
            }

            Console.ReadLine();

        }
    }
}

