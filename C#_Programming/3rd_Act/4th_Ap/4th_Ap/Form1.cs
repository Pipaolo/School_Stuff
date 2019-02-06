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

namespace _4th_Ap
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        /*
         * Write a program that will add all prime number by letting the user specify the range of number to process.
         * 
         */
        private void Form1_Load(object sender, EventArgs e)
        {
            bool primeChecker = true;
            int result = 0;

            string userInput = Interaction.InputBox("Enter Range", "4th_App", "---");

            for (int i = 2; i <= Convert.ToInt32(userInput); i++)
            {
                for (int j = 2; j <= Convert.ToInt32(userInput); j++)
                {
                    if (i != j && i % j == 0)
                    {
                        primeChecker = false;
                        break;
                    }
                }

                if (primeChecker)
                {
                    result += Convert.ToInt32(i);
                }
                primeChecker = true;
            }

            MessageBox.Show($"Output is: {result}");
            this.Close();


        }
    }
}
