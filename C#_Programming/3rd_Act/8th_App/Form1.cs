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

namespace _8th_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        /*
         * Write a program that will derive the sum of series of a number.  
         * For example, an input of 5 will produce (1 + 2 + 3 + 4 + 5 = 15).
         */

        private void Form1_Load(object sender, EventArgs e)
        {
            int userInput = 0;
            int result = 0;
            int counter = 0;
            string output = "";

            string user_Input = Interaction.InputBox("Enter Number", "8th_App", "---");

            userInput = Convert.ToInt32(user_Input);

            for (int i = 1; i <= userInput; i++)
            {

                output += i.ToString() + " + ";
                result += i;
            }
            output = output.Remove(output.Length - 2);
            MessageBox.Show(output + " = " + result);
            this.Close();
        }
    }
}
