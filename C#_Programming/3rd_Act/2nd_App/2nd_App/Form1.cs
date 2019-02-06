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

namespace _2nd_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        /*
         * Modify exercise number 1 and allow positive and negative numbers as inputs to be multiplied.  
         * Hint:  Take absolute values first then use condition statements. 
         * 
         * 
         * 
         */

        private void Form1_Load(object sender, EventArgs e)
        {
            int firstInput = 0;
            int secondInput = 0;
            int result = 0;

            string first_Input = Interaction.InputBox("Enter 1st Number", "2nd_App", "---");
            string second_Input = Interaction.InputBox("Enter 2nd Number", "2nd_App", "---");

            firstInput = Convert.ToInt32(first_Input);
            secondInput = Convert.ToInt32(second_Input);
            
            if (firstInput < 0 && secondInput >= 0 || firstInput >= 0 && secondInput < 0)
            {
                for (int i = 0; i < secondInput; i++)
                {
                    result += firstInput;
                }
            }
            else
            {
                firstInput *= -1;
                secondInput *= -1;
                for (int i = 0; i < secondInput; i++)
                {
                    result += firstInput;
                }
            }

            MessageBox.Show($"Output is: {result}");
            this.Close();
        }
    }
}
