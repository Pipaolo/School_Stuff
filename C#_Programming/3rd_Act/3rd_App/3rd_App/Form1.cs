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

namespace _3rd_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        /*
         * Write a program that will compute the quotient (including the remainder) of two positive integers (firstno divided by secondno) by subtracting them repeatedly.  
         * This means subtracting firstno to secondno repeatedly until the difference is less than secondno.
         * 
         * 
         */


        private void Form1_Load(object sender, EventArgs e)
        {
            int firstInput = 0;
            int secondInput = 0;
            int quotient = 0;
            int result = 0;

            string first_Input = Interaction.InputBox("Enter 1st Number", "3rd_App", "---");
            string second_Input = Interaction.InputBox("Enter 2nd Number", "3rd_App", "---");

            firstInput = Convert.ToInt32(first_Input);
            secondInput = Convert.ToInt32(second_Input);

            while (firstInput != 0 && firstInput > 0)
            {
                result = firstInput - secondInput;
                firstInput -= secondInput;            
                quotient++;
            }
            
            MessageBox.Show($"Quotient is: {quotient}, Remainder: {result}");
            this.Close();
        }
    }
}
