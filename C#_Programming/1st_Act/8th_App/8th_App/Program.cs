using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _8th_App
{
    class Program
    {
        /// <summary>
        /// Write a program that reads two integers. Get their halves, quarter, double and square.
        /// </summary>
        static void Main()
        {
            double inputNum;
            double inputNum2;

            Console.Write("Enter 1st number: ");
            inputNum = Convert.ToInt64(Console.ReadLine());
            Console.Write("Enter 2nd number: ");
            inputNum2 = Convert.ToInt64(Console.ReadLine());
            Console.Write($"Double of {inputNum}: {inputNum * 2}\nSquare of {inputNum}: {inputNum * inputNum}\nHalf of {inputNum}: {inputNum / 2}\n\n");
            Console.Write($"Double of {inputNum2}: {inputNum2 * 2}\nSquare of {inputNum2}: {inputNum2 * inputNum2}\nHalf of {inputNum2}: {inputNum2 / 2}");
            Console.Read();
        }
    }
}
