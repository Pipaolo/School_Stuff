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

namespace _11th_Ap
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        /*
         * Write a program that reverses the input number.  
         * Formulate an equation to come up with the answer.  
         * (Apply the loop statements in your solutions).  
         * For example, an input of 1238 will produce 8321.
         * 
         * 
         * 
         */
        private void Form1_Load(object sender, EventArgs e)
        {
            int userInput = 0;
            int reversed = 0;
            int temp = 0;

            string user_Input = Interaction.InputBox("Enter Number", "11th_App", "---");

            userInput = Convert.ToInt32(user_Input);

            while(userInput > 0)
            {
                temp = userInput % 10;
                reversed = (reversed * 10) + temp;
                userInput /= 10;         
            }

            MessageBox.Show(reversed.ToString());
            this.Close();
        }
    }
}
