using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2nd_App
{
    class Program
    {
        /// <summary>
        /// 2. Write a program to convert a measurement in centimeters to feet and inches.  
        /// The number of centimeters should be read as input. 
        /// There are 2.54 centimeters in each inch and 12 inches in each foot.  
        /// Format your output to have two decimal places.
        /// </summary>

        static void Main()
        {
            double centimeterInput;
            double convertFeet;
            double convertInches;

            Console.WriteLine("<--Centimeters to Feet and Inches Converter-->");
            Console.Write("Enter Centimeters: ");
            centimeterInput = double.Parse(Console.ReadLine());
            convertInches = centimeterInput / 2.54;
            convertFeet = convertInches / 12;
            

            Console.WriteLine($"{centimeterInput} is {String.Format("{0:0.00}", convertFeet)}ft {String.Format("{0:0.00}", convertInches)}inches");

            Console.ReadKey();
        }
    }
}
