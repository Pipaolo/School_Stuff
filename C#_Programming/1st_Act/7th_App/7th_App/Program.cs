using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7th_App
{
    class Program
    {
        /// <summary>
        /// Write a program that will get the double, square and half of a number supplied.
        /// </summary>
        static void Main()
        {
            double inputNum;

            Console.Write("Enter a number: ");
            inputNum = Convert.ToInt64(Console.ReadLine());
            Console.Write($"Double of {inputNum}: {inputNum * 2}\nSquare of {inputNum}: {inputNum * inputNum}\nHalf of {inputNum}: {inputNum / 2}");
            Console.Read();


        }
    }
}
