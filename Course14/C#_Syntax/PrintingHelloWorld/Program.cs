using System;
using System.Collections.Specialized;
using System.Runtime.InteropServices;

namespace Main
{
    internal class Program
    {

        struct stStudent
        {
            public string FirstName;
            public string LastName;
        }



        enum enWeekDays
        {
            Monday,     // 0
            Tuesday,    // 1
            Wednesday,  // 2
            Thursday,   // 3
            Friday,     // 4
            Saturday,   // 5
            Sunday      // 6
        }

        enum WeekDays
        {
            Monday,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday,
            Sunday
        }


        //if you set a value , it will auto number everything after it.
        enum enCategories
        {
            Electronics,    // 0
            Food,           // 1
            Automotive = 6, // 6
            Arts,           // 7
            BeautyCare,     // 8
            Fashion         // 9
        }


        //Enum can have any numarical data type byte, sbyte, short, ushort, int, uint, long, or ulong
        //but not string

        enum enCategories2 : byte
        {
            Electronics = 1,
            Food = 5,
            Automotive = 6,
            Arts = 10,
            BeautyCare = 11,
            Fashion = 15
        }

        static void Main(string[] args)
        {
            

            // this is the first program "WriteLine"
            Console.WriteLine("hello world\nThis is Mahmoud\nAnd this is my first Program.");
            Console.WriteLine("hello world");

            // this is the second program "Write"
            Console.Write("2+4=" + (2 + 4));

            // this is the third program "string formatted"
            Console.WriteLine("\nWhat's Your Name? ");
            string name = Console.ReadLine();

            Console.WriteLine("\nWhere do you live ? ");
            string city = Console.ReadLine();

            Console.WriteLine("Hi My Name is {0} and i live in {1} ", name, city);
            Console.ReadLine();


            // this is the escape squences
            Console.WriteLine("this is the tab \t tab");
            Console.WriteLine("this is the alert\a");
            Console.WriteLine("this is the backslash\\");
            Console.WriteLine("this is the single quote\'");
            Console.WriteLine("this is the double quote\"");
            Console.WriteLine("this is the backspace Mahmoud \bAhmed");
            Console.ReadLine();


            //ProgrammingAdvices.com
            //Mohammed Abu-Hadhoud
            /* Implicitly typed variables
                Alternatively in C#, we can declare a variable without knowing 
                its type using var keyword. 
                Such variables are called implicitly typed local variables.

                Variables declared using var keyword must be initialized at the time of declaration.
            */

            var x = 10;
            var y = 10.5;
            var z = "Mohammed";

            Console.WriteLine("x={0}, y={1}, z={2}", x, y, z);

            Console.ReadKey();



            // i don't understand this lesson 
            //get default value using default(type)
            //int i = default(int); // 0
            //float f = default(float);// 0
            //decimal d = default(decimal);// 0
            //bool b = default(bool);// false
            //char c = default(char);// '\0'

            //// C# 7.1 onwards
            ////get default value using default
            //int i2 = default; // 0
            //float f2 = default;// 0
            //decimal d2 = default;// 0
            //bool b2 = default;// false
            //char c2 = default;// '\0'

            Console.ReadKey();


            // enum lesson
            enWeekDays WeekDay;
            WeekDay = enWeekDays.Friday;
            Console.WriteLine("today is {0}", WeekDay);
            Console.ReadLine();

            //  Nullable<int> can be assigned any value
            //  from -2147483648 to 2147483647, or a null value.

            Nullable<int> i = null;
            Console.WriteLine(i);


            Console.ReadKey();

            //you dont specify any type here , automatically will be specified
            var student = new
            {
                Id = 20,
                FirstName = "Mohammed",
                LastName = "Abu-Hadhoud"
            };

            Console.WriteLine("\nExample1:\n");
            Console.WriteLine(student.Id); //output: 20
            Console.WriteLine(student.FirstName); //output: Mohammed
            Console.WriteLine(student.LastName); //output: Abu-Hadhoud

            //You can print like this:
            Console.WriteLine(student);


            //anonymous types are read-only
            //you cannot change the values of properties as they are read-only.

            // student.Id = 2;//Error: cannot chage value
            // student.FirstName = "Ali";//Error: cannot chage value


            //An anonymous type's property can include another anonymous type.
            var student2 = new
            {
                Id = 20,
                FirstName = "Mohammed",
                LastName = "Abu-Hadhoud",

                Address = new
                {
                    Id = 1,
                    City = "Amman",
                    Country = "Jordan"
                }
            };

            Console.WriteLine("\nExample2:\n");
            Console.WriteLine(student2.Id);
            Console.WriteLine(student2.FirstName);
            Console.WriteLine(student2.LastName);

            Console.WriteLine(student2.Address.Id);
            Console.WriteLine(student2.Address.City);
            Console.WriteLine(student2.Address.Country);
            Console.WriteLine(student2.Address);
            Console.ReadKey();

            //A struct object can be created with or without the new operator,
            //same as primitive type variables.

            stStudent Student;
            stStudent Student2 = new stStudent();


            Student.FirstName = "Mohammed";
            Student.LastName = "Abu-Hadhoud";


            Console.WriteLine(Student.FirstName);
            Console.WriteLine(Student.LastName);


            Student2.FirstName = "Ali";
            Student2.LastName = "Ahmed";


            Console.WriteLine(Student2.FirstName);
            Console.WriteLine(Student2.LastName);



            dynamic MyDynamicVar = 100;
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            MyDynamicVar = "Hello World!!";
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            MyDynamicVar = true;
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            MyDynamicVar = DateTime.Now;
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            Console.ReadKey();

            //assigns default value 01/01/0001 00:00:00
            DateTime dt1 = new DateTime();

            //assigns year, month, day
            DateTime dt2 = new DateTime(2023, 12, 31);

            //assigns year, month, day, hour, min, seconds
            DateTime dt3 = new DateTime(2023, 12, 31, 5, 10, 20);

            //assigns year, month, day, hour, min, seconds, UTC timezone
            DateTime dt4 = new DateTime(2023, 12, 31, 5, 10, 20, DateTimeKind.Utc);

            Console.WriteLine(dt1);
            Console.WriteLine(dt2);
            Console.WriteLine(dt3);
            Console.WriteLine(dt4);


            Console.ReadKey();

            //assigns default value 01/01/0001 00:00:00
            DateTime dt6 = new DateTime();

            dt6 = DateTime.Now;
            Console.WriteLine(dt6);


            Console.ReadKey();



            //number of 100-nanosecond intervals that have elapsed
            //since January 1, 0001, at 00:00:00.000 in the Gregorian calendar. 
            Console.WriteLine("this is the ticks:");
            Console.WriteLine(DateTime.MinValue.Ticks);  //min value of ticks
            Console.WriteLine(DateTime.MaxValue.Ticks); // max value of ticks
            Console.ReadKey();


            Console.ReadLine();

            DateTime currentDateTime = DateTime.Now;  //returns current date and time
            DateTime todaysDate = DateTime.Today; // returns today's date
            DateTime currentDateTimeUTC = DateTime.UtcNow;// returns current UTC date and time
            DateTime maxDateTimeValue = DateTime.MaxValue; // returns max value of DateTime
            DateTime minDateTimeValue = DateTime.MinValue; // returns min value of DateTime

            Console.WriteLine("currentDateTime: " + currentDateTime);
            Console.WriteLine("Today: " + todaysDate);
            Console.WriteLine("currentDateTimeUTC: " + currentDateTimeUTC);
            Console.WriteLine("minDateTimeValue: " + minDateTimeValue);
            Console.WriteLine("maxDateTimeValue: " + maxDateTimeValue);


            Console.ReadKey();


            Console.WriteLine("add this date 2023, 2, 21 \nto this time \n49, 25, 34\n");

            // years, months, days
            DateTime dt = new DateTime(2023, 2, 21);
            Console.WriteLine("this is the dt : " + dt);
            // Hours, Minutes, Seconds
            TimeSpan ts = new TimeSpan(49, 25, 34);

            Console.WriteLine("this is the ts time spent: ");
            Console.WriteLine(ts);

            Console.WriteLine("this is the ts.Days: ");
            Console.WriteLine(ts.Days);

            Console.WriteLine("this is the ts.hours: ");
            Console.WriteLine(ts.Hours);

            Console.WriteLine("this is the ts.minutes: ");
            Console.WriteLine(ts.Minutes);

            Console.WriteLine("this is the ts.seconds: ");
            Console.WriteLine(ts.Seconds);


            //this will add time span to the date.
            DateTime newDate = dt.Add(ts);
            Console.WriteLine("this is the newDate after adding the ts to dt: " + newDate);


            Console.ReadKey();

            Console.WriteLine("this is the TimeSpan i want to know the Subtraction of \n2023, 2, 21 \nand\n2023, 2, 25 ");
            DateTime dt7 = new DateTime(2023, 2, 21);
            DateTime dt9 = new DateTime(2023, 2, 25);
            TimeSpan result = dt9.Subtract(dt7);

            Console.WriteLine(result.Days);

            Console.ReadKey();

            Console.WriteLine("let's try to imitate what we've learnt : ");
            // years months days hours minutes seconds 
            DateTime MyBirthDay = new DateTime(2003, 11, 29, 11, 51, 30);

            Console.WriteLine("this is the long date of MyBirthDay: " + MyBirthDay.ToLongDateString());
            Console.WriteLine("this is the long time of MyBirthDay: " + MyBirthDay.ToLongTimeString());


            // Operators


            DateTime date1 = new DateTime(2015, 12, 20);
            DateTime date2 = new DateTime(2016, 12, 31, 5, 10, 20);
            TimeSpan time = new TimeSpan(10, 5, 25, 50);

            Console.WriteLine(date2 + time); // 1/10/2017 10:36:10 AM
            Console.WriteLine(date2 - date1); //377.05:10:20
            Console.WriteLine(date1 == date2); //False
            Console.WriteLine(date1 != date2); //True
            Console.WriteLine(date1 > date2); //False
            Console.WriteLine(date1 < date2); //True
            Console.WriteLine(date1 >= date2); //False
            Console.WriteLine(date1 <= date2);//True

            Console.ReadKey();

            // Convert String to DateTime

            string numString = "1234";

            int num = 1;

            if (int.TryParse(numString, out num))
                Console.WriteLine("Converting succesed " + num);
            else
                Console.WriteLine("Converting Failed" + num);

            Console.ReadLine();



            var str = "6/12/2023";
            DateTime date_time;

            var isValidDate = DateTime.TryParse(str, out date_time);


            if (isValidDate)
                Console.WriteLine(date_time);
            else
                Console.WriteLine($"{str} is not a valid date string");

            //invalid string date
            var str2 = "6/65/2023";
            DateTime date_time2;

            var isValidDate2 = DateTime.TryParse(str2, out date_time2);

            if (isValidDate2)
                Console.WriteLine(date_time2);
            else
                Console.WriteLine($"{str2} is not a valid date string");



            Console.ReadKey();
            
            
            
            // Strings

            string S1 = "Mohammed Abu-Hadhoud";

            Console.WriteLine(S1.Length);

            //this will take 5 characters staring position 2
            Console.WriteLine(S1.Substring(2, 5));
            Console.WriteLine(S1.ToLower());
            Console.WriteLine(S1.ToUpper());
            Console.WriteLine(S1[2]);
            Console.WriteLine(S1.Insert(3, "KKKK"));
            Console.WriteLine(S1.Replace("m", "*"));
            Console.WriteLine(S1.IndexOf("m"));
            Console.WriteLine(S1.Contains("m"));
            Console.WriteLine(S1.Contains("x"));
            Console.WriteLine(S1.LastIndexOf("m"));

            string S2 = "Ali,Ahmed,Khalid";

            string[] NamesList = S2.Split(',');

            Console.WriteLine(NamesList[0]);
            Console.WriteLine(NamesList[1]);
            Console.WriteLine(NamesList[2]);

            string S3 = "  Abu-Hadhoud  ";
            Console.WriteLine(S3.Trim());
            Console.WriteLine(S3.TrimStart());
            Console.WriteLine(S3.TrimEnd());

            Console.ReadKey();


            // String Interpolation

            string firstName = "Mohammed";
            string lastName = "Abu-Hadhoud";
            string code = "107";

            //You shold use $ to $ to identify an interpolated string 
            string fullName = $"Mr. {firstName} {lastName}, Code: {code}";

            Console.WriteLine(fullName);

            Console.ReadKey();



            string name_ = "Mahmoud";
            sbyte age = 20;
            Console.WriteLine($"Hello {name_} and i'm {age} years old");

            Console.WriteLine("hello {0} and i'm {1} years old", name_, age);
            //the Implicit Casting(automatically) - converting a smaller type to a larger type size
            //char -> int -> long -> float -> double
            //C i l f double سيلف دبل

            //the Explicit Casting(manually) - converting a larger type to a smaller size type
            //double -> float -> long -> int -> char

            //Implict Casting
            
            int myInt = 17;
            double myDouble = myInt;       // Automatic casting: int to double
            
            Console.WriteLine(myInt);      // Outputs 17
            Console.WriteLine(myDouble);   // Outputs 17


            Console.ReadKey();

            double MyDouble = 17.58;
            int MyInt = (int)myDouble;    // Manual casting: double to int

            Console.WriteLine(MyDouble);   // Outputs 17.58
            Console.WriteLine(MyInt);      // Outputs 17


            Console.ReadKey();

            int MyInteger = 20;
            double My_Double = 7.25;
            bool Bool_ = true;

            Console.WriteLine(Convert.ToString(MyInteger));    // convert int to string
            Console.WriteLine(Convert.ToDouble(MyInteger));    // convert int to double
            Console.WriteLine(Convert.ToInt32(My_Double));  // convert double to int
            Console.WriteLine(Convert.ToString(Bool_));   // convert bool to string
                                  

            Console.ReadKey();

            Console.WriteLine(WeekDays.Friday); //output: Friday 
            int day = (int)WeekDays.Friday; // enum to int conversion
            Console.WriteLine(day); //output: 4 

            var wd = (WeekDays)5; // int to enum conversion
            Console.WriteLine(wd);//output: Saturday 

            Console.ReadKey();



            Console.WriteLine(WeekDays.Friday); //output: Friday 
            int day_ = (int)WeekDays.Friday; // enum to int conversion
            Console.WriteLine(day_); //output: 4 

            var weekDay= (WeekDays)5; // int to enum conversion
            Console.WriteLine(weekDay);//output: Saturday 

            Console.ReadKey();

            // Type your username and press enter
            Console.WriteLine("Enter username?");

            string userName = Console.ReadLine();
            Console.WriteLine("Username is: " + userName);
    
            Console.ReadKey();

            Console.WriteLine("Enter your age?");
            //if you dont convert you will get error, and if you enter string you will get error
            int AGE = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Your age is: " + AGE);


            Console.ReadKey();
            
            
            int number_ = 12;
            string result_ = " ";

            result_ = (number_ % 2 == 0) ? "Even Number" : "Odd Number";
            Console.WriteLine("{0} is {1}", number_, result_);

            Console.ReadKey();



        }
    }
}


