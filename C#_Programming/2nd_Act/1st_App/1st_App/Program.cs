using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1st_App
{
    class Program
    {
        /*
         * Write a program that mimics a calculator.  
         * The program should take as input two integers and the operation to be performed.  
         * It should then output the number, the operator and the result. (For division, if the denominator is zero, output an appropriate message).
         */
        static void Main(string[] args)
        {
            string equation = " ";
            double firstInput = 0D;
            double secondInput = 0D;
            double finalOutput = 0D;
            char operation;

            Console.WriteLine("Calculator");
            Console.WriteLine("Powered by: Pipaolo");
            Console.WriteLine("Enter an equation (e.g 1 + 1, 2 - 2, 3 / 3, 4 * 4) : ");
            equation = Console.ReadLine();
            firstInput = Convert.ToDouble(equation.Split(' ')[0]);
            operation = Convert.ToChar(equation.Split(' ')[1]);
            secondInput = Convert.ToDouble(equation.Split(' ')[2]);

            if (operation == '+')
            {
                finalOutput = firstInput + secondInput;          
            }
            else if (operation == '-')
            {
                finalOutput = firstInput - secondInput;
            }
            else if (operation == '*')
            {
                finalOutput = firstInput * secondInput;
            }
            else if (operation == '/')
            {
                if (secondInput == 0)
                {
                    Console.WriteLine("Denominator cannot be zero!");
                }
                else
                {
                    finalOutput = firstInput / secondInput;
                }
            }
            Console.WriteLine($"{firstInput} {operation} {secondInput} = {finalOutput}");
            Console.ReadKey();
        }
    }
}
