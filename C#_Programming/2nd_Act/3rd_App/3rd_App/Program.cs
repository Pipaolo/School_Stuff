using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3rd_App
{
    class Program
    {
        /*
         * Write a program that prompts the user to input the x-y coordinate of a point in a Cartesian plane.  
         * The program should then output a message indicating whether the point is the origin point, is located on the x (or y) axis, or appears in a particular quadrant.
         */
        static void Main(string[] args)
        {
            int userInputX = 0;
            int userInputY = 0;
            Console.WriteLine("Cartesian Place Coordinate Checker");
            Console.WriteLine("Welcome!");
            Console.Write("Enter X Coordinate: ");
            userInputX = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter Y Coordinate: ");
            userInputY = Convert.ToInt32(Console.ReadLine());

            if (userInputX > 0 && userInputY > 0)
            {
                Console.WriteLine("The entered coordinates is in Quadrant I");
            }
            else if (userInputX < 0 && userInputY > 0)
            {
                Console.WriteLine("The entered coordinates is in Quadrant II");

            }
            else if (userInputX < 0 && userInputY < 0)
            {
                Console.WriteLine("The entered coordinates is in Quadrant III");

            }
            else if (userInputX > 0 && userInputY < 0)
            {
                Console.WriteLine("The entered coordinates is in Quadrant IV");
            }
            else
            {
                Console.WriteLine("The entered coordinates is in the origin");
            }
            Console.Read();
        }
    }
}
