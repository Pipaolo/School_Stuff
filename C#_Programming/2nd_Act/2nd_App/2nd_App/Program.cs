using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2nd_App
{
    class Program
    {
        /*
         * 
         * 
         */
        static void Main(string[] args)
        {
            char userInput;
            Console.WriteLine("Telephone Letter to Number Converter");
            Console.WriteLine("Enter a Letter: ");
            userInput = Convert.ToChar(Console.ReadLine());

            switch (userInput)
            {
                case 'A':
                    case 'a':
                    Console.WriteLine($"{userInput} has the value of 2");
                    break;
                case 'B':
                    case 'b':
                    Console.WriteLine($"{userInput} has the value of 2");
                    break;
                case 'C':
                    case 'c':
                    Console.WriteLine($"{userInput} has the value of 2");
                    break;
                case 'D':
                    case 'd':
                    Console.WriteLine($"{userInput} has the value of 3");
                    break;
                case 'E':
                    case 'e':
                    Console.WriteLine($"{userInput} has the value of 3");
                    break;
                case 'F':
                    case 'f':
                    Console.WriteLine($"{userInput} has the value of 3");
                    break;
                case 'G':
                    case 'g':
                    Console.WriteLine($"{userInput} has the value of 4");
                    break;
                case 'H':
                    case 'h':
                    Console.WriteLine($"{userInput} has the value of 4");
                    break;
                case 'I':
                    case 'i':
                    Console.WriteLine($"{userInput} has the value of 4");
                    break;
                case 'J':
                    case 'j':
                    Console.WriteLine($"{userInput} has the value of 5");
                    break;
                case 'K':
                    case 'k':
                    Console.WriteLine($"{userInput} has the value of 5");
                    break;
                case 'L':
                    case 'l':
                    Console.WriteLine($"{userInput} has the value of 5");
                    break;
                case 'M':
                    case 'm':
                    Console.WriteLine($"{userInput} has the value of 6");
                    break;
                case 'N':
                    case 'n':
                    Console.WriteLine($"{userInput} has the value of 6");
                    break;
                case 'O':
                    case 'o':
                    Console.WriteLine($"{userInput} has the value of 6");
                    break;
                case 'P':
                    case 'p':
                    Console.WriteLine($"{userInput} has the value of 7");
                    break;
                case 'Q':
                    case 'q':
                    Console.WriteLine($"{userInput} has the value of 7");
                    break;
                case 'R':
                    case 'r':
                    Console.WriteLine($"{userInput} has the value of 7");
                    break;
                case 'S':
                    case 's':
                    Console.WriteLine($"{userInput} has the value of 7");
                    break;
                case 'T':
                    case 't':
                    Console.WriteLine($"{userInput} has the value of 8");
                    break;
                case 'U':
                    case 'u':
                    Console.WriteLine($"{userInput} has the value of 8");
                    break;
                case 'V':
                    case 'v':
                    Console.WriteLine($"{userInput} has the value of 8");
                    break;
                case 'W':
                    case 'w':
                    Console.WriteLine($"{userInput} has the value of 9");
                    break;
                case 'X':
                    case 'x':
                    Console.WriteLine($"{userInput} has the value of 9");
                    break;
                case 'Y':
                    case 'y':
                    Console.WriteLine($"{userInput} has the value of 9");
                    break;
                case 'Z':
                    case 'z':
                    Console.WriteLine($"{userInput} has no value in the Telephone!");
                    break;

            }

            Console.Read();


        }
    }
}
