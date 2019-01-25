using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _9th_Ap
{
    class Program
    {
        /// <summary>
        /// Using the conversion below, create an application that will ask for a pint value and will display its equivalence in gill, quarts and gallon.  
        /// Format your output to have two decimal places.
        ///1 pint = 4 gills
        ///= ½ quarts
        ///= 1/8 gallon
        /// </summary>
        static void Main()
        {
            double inputPint;
            double convertGill;
            double convertQuarts;
            double convertGallon;

            Console.WriteLine("<-- Pint to Gill, Quarts, and Gallon -->");
            Console.WriteLine("Enter Pint: ");
            inputPint = Convert.ToInt64(Console.ReadLine());
            convertGill = inputPint * 4;
            convertQuarts = inputPint / 2;
            convertGallon = inputPint / 8;

            Console.WriteLine($"{inputPint} pint in Gills, Quarts, and Gallon:");
            Console.WriteLine($"Gill:{String.Format("{0:0.00}", convertGill)}");
            Console.WriteLine($"Quarts:{String.Format("{0:0.00}", convertQuarts)}");
            Console.WriteLine($"Gallon:{String.Format("{0:0.00}", convertGallon)}");
            Console.Read();
        }
    }
}
