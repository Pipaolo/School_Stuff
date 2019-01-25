using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3rd_App
{
    class Program
    {
        /// <summary>
        /// Write a program that will read a weight in pounds and convert it to grams. 
        /// Print both the original weight and the converted value. 
        /// There are 454 grams in a pound.  
        /// Format your output to have two decimal places.
        /// </summary>
        static void Main()
        {
            double inputPounds;
            double convertGrams;
            Console.WriteLine("<-- Pounds to Grams Converter -->");
            Console.WriteLine("Enter Pounds: ");
            inputPounds = Convert.ToInt64(Console.ReadLine());
            Console.WriteLine($"Original Value: {inputPounds}lbs");
            convertGrams = inputPounds * 454;
            Console.WriteLine($"Converted Value: {String.Format("{0:0.00}", convertGrams)}");
            Console.Read();
        }
    }
}
