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
            List<int> listOutput = new List<int>();
            int userInput = 0;
            int result = 0;
            int temp = 0;
            string output = "";

            string user_Input = Interaction.InputBox("Enter Number", "14th_App", "---");

            userInput = Convert.ToInt32(user_Input);

            while (userInput > 0)
            {
                temp = userInput % 10;
                userInput /= 10;
                listOutput.Add(temp);
                result += temp;
            }

            for (int i = 1; i <= listOutput.Count; i++)
            {
                output += listOutput[listOutput.Count - i] + "+";
            }

            output = output.Remove(output.Length - 1);
            MessageBox.Show(output + " = " + result);
            this.Close();
        }
    }
}
