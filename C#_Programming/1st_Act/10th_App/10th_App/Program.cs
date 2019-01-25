using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10th_App
{
    class Program
    {
        /// <summary>
        /// Make an application that will get a radius of a circle and will compute the diameter, circumference and area of the circle.  
        /// Format your output to have two decimal places.
        /// </summary>
        static void Main()
        {
            double inputRadius;
            double convertDiameter;
            double convertCircumference;
            double convertArea;

            Console.WriteLine("<-- Diameter, Circumference, and Area of The Circle Calculator -->");
            Console.Write("Enter Radius: ");

            inputRadius = Convert.ToInt64(Console.ReadLine());

            convertDiameter = inputRadius * 2;
            convertCircumference = convertDiameter * Math.PI;
            convertArea = (inputRadius * inputRadius) * Math.PI;

            Console.WriteLine($"Diameter:{String.Format("{0:0.00}", convertDiameter)}\nCircumference: {String.Format("{0:0.00}", convertCircumference)}\nArea: {String.Format("{0:0.00}", convertArea)}");

            Console.Read();
        }
    }
}
