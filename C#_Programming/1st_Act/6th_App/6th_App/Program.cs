using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _6th_App
{
    class Program
    {
        /// <summary>
        /// Write a program that will derive the number of years, months and days from an input in days.  
        /// Use 365 as the total number of days a year.
        /// </summary>
        static void Main()
        {
            int inputDays;
            int convertYears;
            int convertMonths;
            int convertRemDays;

            Console.WriteLine("<-- Days to Years, Months, and Days Converter -->");
            Console.Write("Enter Days: ");
            inputDays = Convert.ToInt32(Console.ReadLine());
            convertYears = inputDays / 365;
            convertMonths = (inputDays % 365) / 12;
            convertRemDays = (inputDays % 365) % 12;
            Console.WriteLine($"Years: {convertYears}\nMonths: {convertMonths}\nDays: {convertRemDays}");
            Console.Read();
        }
    }
}
