using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1st_App
{
    /// <summary>
    /// Convert a distance from miles to kilometers.  
    /// There are 5,280 feet per mile, 12 inches per foot, 2.54 centimeter per inch and 100,000 centimeters per kilometers.  
    /// Format your output to have two decimal places.
    /// </summary>
    class Program
    {
        static void Main()
        {
            double inputMiles;
            double convertKilometer;

            Console.WriteLine("<--Miles To Kilometers Converter-->");
            Console.Write("Enter Miles: ");
            inputMiles = double.Parse(Console.ReadLine());
            convertKilometer = (((inputMiles * 5280) * 12) * 2.54) / 100000;

            Console.WriteLine($"{inputMiles} Miles in Kilometer is {String.Format("{0:0.00}", convertKilometer)} KM.");
            Console.Read();

        }
    }
}
