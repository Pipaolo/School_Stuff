using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.VisualBasic;

namespace _14th_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        /*
         * Write a program to sum the digits in a number and print it.  
         * For example, the sum of the digits in 347 is 14.
         */

        private void Form1_Load(object sender, EventArgs e)
        {
            int[] arrOutput;
            int userInput = 0;
            int result = 0;
            int countDigits = 0;
            int iterator = 0;
            int temp = 0;
            string output = "";

            string user_Input = Interaction.InputBox("Enter Number", "14th_App", "---");

            userInput = Convert.ToInt32(user_Input);

            temp = userInput;

            while(temp > 0)
            {
                temp /= 10;
                countDigits++;
            }

            arrOutput = new int[countDigits];

            while (userInput > 0)
            {
                temp = userInput % 10;
                userInput /= 10;
                arrOutput[iterator] = temp;
                result += temp;
                iterator++;
            }

            for (int i = 0; i < countDigits; i++)
            {
                output += arrOutput[(countDigits - 1 ) - i] + "+";
            }

            output = output.Remove(output.Length - 1);
            MessageBox.Show(output + " = " + result);
            this.Close();
        }
    }
}
