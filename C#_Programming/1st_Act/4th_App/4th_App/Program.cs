using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4th_App
{
    class Program
    {
        /// <summary>
        /// Write a program that inputs a number of hours and output the equivalent number of weeks, days and hours.
        /// </summary>
        static void Main()
        {
            int inputHours;
            int convertWeeks;
            int convertDays;
            int convertRemHours;
            Console.WriteLine("<-- Hours to Weeks, Days, and Remaining Hours Converter -->");
            Console.WriteLine("Enter Hours: ");
            inputHours = Convert.ToInt32(Console.ReadLine());
            convertWeeks = inputHours / 168;
            convertDays = (inputHours % 168) / 24;
            convertRemHours = inputHours % 24;
            Console.WriteLine($"Weeks : {convertWeeks} \nDays : {convertDays} \nHours : {convertRemHours}");
            Console.Read();

        }
    }
}
