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

namespace _10th_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        /*
         * Write a program that will output the sum of the powers from 1 to the supplied number.  
         * For example, an input of 4 will produce 288 (11 + 22 + 33 + 44 = 288).
         * 
         */
        private void Form1_Load(object sender, EventArgs e)
        {
            int userInput = 0;
            int result = 0;
            int raiseTo = 0;
            string output = "";


            string user_Input = Interaction.InputBox("Enter Number", "10th_App", "---");

            userInput = Convert.ToInt32(user_Input);

            for (int i = 1; i <= userInput; i++)
            {
                raiseTo = i;               
                for (int j = 1; j < i; j++)
                {
                    raiseTo = raiseTo * i;
                }
                output += raiseTo.ToString() + " + ";
                result += raiseTo;
            }
            output = output.Remove(output.Length - 2);
            MessageBox.Show(output + " = " + result);
            this.Close();
        }
    }
}
