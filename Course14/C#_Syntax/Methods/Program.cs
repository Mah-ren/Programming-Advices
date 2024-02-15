using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Methods
{
    internal class Program
    {
        // methods overloading 
        static int Sum(int Num1, int Num2)

        {
            return Num1 + Num2;
        }

        static int Sum(int Num1, int Num2, int Num3)

        {
            return Num1 + Num2 + Num3;
        }
        static int Sum(int Num1, int Num2, int Num3, int Num4)

        {
            return Num1 + Num2 + Num3 + Num4;
        }


        static string DisplayArea(string shape, double width = 1, double height = 1)
        {
            shape = shape.ToUpper();
            
            if (width == height && shape == "RECTANGLE")
                shape = "Square";

            return ($"the area of {shape} is {width * height}");
        }

        static void PrintMyName()
        {
            Console.WriteLine("Mohammed Abu-Hadhoud");
        }
        static void Main(string[] args)
        {
            PrintMyName();
            PrintHelloWorld();
            Console.ReadKey();


            Console.WriteLine("this is the default parameter value");
            PrintMyInfo();
            //First we did not provide the address it's optional
            PrintMyInfo("Mohammed-AbuHadhoud", 45);
            
            //second we provided the address
            PrintMyInfo("Mohammed-AbuHadhoud", 45, "Amman-Jordan");

            Console.ReadKey();

            Console.WriteLine($"\nthis function returns my name {GetMyName()}");
            Console.ReadKey();

            //see the order of sending parameters is not important.

            MyMethod(child3: "Omar", child1: "Saqer", child2: "Hamza");

            Console.ReadKey();
             
            // Named Arguments
            Console.WriteLine(DisplayArea(width : 2, shape: "rectangle", height : 3));

            Console.ReadLine();




        }

        static void PrintHelloWorld()
        {
            Console.WriteLine("hello World");
        }

        // default Parameter value
        static void PrintMyInfo(string Name = "Mahmoud Ahmed Abdel aal Ahmed", byte Age = 20, string Address = "KaferBarakat - Ayat - giza")
        {
            Console.WriteLine($"Name= {Name} \nAge= {Age} \nAddress= {Address}");
        }


        // this method doesn't return void 
        static string GetMyName()
        {
            return "Mohammed-AbuHadhoud";

        }

        static void MyMethod(string child3, string child1, string child2)
        {
            Console.WriteLine("The youngest child is: " + child3);
        }

        
    }
}
