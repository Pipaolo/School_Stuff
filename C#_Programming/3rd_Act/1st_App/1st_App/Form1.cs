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

namespace _1st_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        /*
         * Write a program that will compute the product of two positive integers (firstno and secondno) by adding them repeatedly.  
         * This means adding firstno to itself secondno times.
         * 
         * 
         */

        private void Form1_Load(object sender, EventArgs e)
        {
            int firstInput = 0;
            int secondInput = 0;
            int result = 0;

            string first_Input = Interaction.InputBox("Enter 1st Number", "1st_App", "---");
            string second_Input = Interaction.InputBox("Enter 2nd Number", "1st_App", "---");

            firstInput = Convert.ToInt32(first_Input);
            secondInput = Convert.ToInt32(second_Input);

            for (int i = 0; i < secondInput; i++)
            {
                result += firstInput;
            }

            MessageBox.Show($"Output is: {result}");
            this.Close();

        }
    }
}
