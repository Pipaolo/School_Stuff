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

namespace _15th_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            int userInput = 0;
            int reversed = 0;
            int remainder = 0;
            int compare = 0;
            string output = "";

            string user_Input = Interaction.InputBox("Enter Number", "8th_App", "---");

            userInput = Convert.ToInt32(user_Input);

            compare = userInput;

            while(userInput > 0)
            {
                remainder = userInput % 10;
                reversed = (reversed * 10) + remainder;
                userInput = userInput / 10;
            }
            if (compare == reversed)
            {
                output = $"{user_Input} is indeed a palindrome!";
            }
            else
            {
                output = $"{user_Input} is not a palindrome!";
            }
            MessageBox.Show(output);
            this.Close();
        }
    }
}
