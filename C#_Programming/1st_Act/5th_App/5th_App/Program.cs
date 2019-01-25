using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5th_App
{
    class Program
    {
        /// <summary>
        /// Write a program that will convert the read-in time in seconds to number of hours, minutes and seconds.
        /// </summary>
        static void Main()
        {
            int inputSeconds;
            int convertHours;
            int convertMinutes;
            int convertRemSeconds;

            Console.WriteLine("<-- Seconds to Hours, Minutes, and Seconds Converter -->");
            Console.WriteLine("Enter Seconds: ");
            inputSeconds = Convert.ToInt32(Console.ReadLine());
            convertHours = inputSeconds / 3600;
            convertMinutes = (inputSeconds % 3600) / 60;
            convertRemSeconds = (inputSeconds % 3600) % 60;

            Console.WriteLine($"Hours: {convertHours}\nMinutes: {convertMinutes}\nSeconds: {convertRemSeconds}");
            Console.Read();



        }
    }
}
