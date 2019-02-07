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

namespace _7th_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        /*
         * An integer is perfect if it is the sum of its proper divisors.  
         * For example 
            6   = 1 + 2 + 3 
            28 = 1 + 2 + 4 + 7 + 14.
         * 
         */
        private void Form1_Load(object sender, EventArgs e)
        {
            int userInput = 0;
            int temp = 0;

            string user_Input = Interaction.InputBox("Enter Number", "7th_App", "---");

            userInput = Convert.ToInt32(user_Input);

            for(int i = 1; i < userInput; i++)
            {
                if(userInput % i == 0)
                {
                    temp += i;
                }

            }
            if (temp == userInput)
            {

                MessageBox.Show($"{user_Input} is perfect number");
            }
            else
            {
                MessageBox.Show($"{user_Input} is not perfect number");
            }
            this.Close();
        }
    }
}
