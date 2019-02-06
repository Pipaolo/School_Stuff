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

namespace _6th_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        /*
         * Write a program that will compute for the factorial of a supplied number.  
         * The factorial of the number if the product of those numbers starting from 1 to the supplied number.
         */
        private void Form1_Load(object sender, EventArgs e)
        {
            int userInput;
            int temp;
            string user_Input = Interaction.InputBox("Enter a number", "Factorial Generator", "---");

            userInput = Convert.ToInt32(user_Input);

            temp = userInput;

            for(int i = 1; i < userInput; i++)
            {
                temp = temp * i;
            }

            MessageBox.Show(temp.ToString());
            this.Close();

        }
    }
}
