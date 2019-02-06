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

namespace _5th_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        /*
         * Write a program that gets the Fibonacci of a number read from the user.  
         * The Fibonacci number sequence begins with 1, 1 then each succeeding number in the sequence is the sum of the previous ones.  
         * For example, an input of 5 will produce 1, 1, 2, 3, 5 and an input of 8 will produce 1, 1, 2, 3, 5, 8, 13, 21 and  an input of 2 will produce 1, 1.
         */

        private void Form1_Load(object sender, EventArgs e)
        {
            int userInput = 0;
            int firstNum = 0;
            int secondNum = 1;
            int storeNum = 0;
            string result = "";

            string user_Input = Interaction.InputBox("Enter 1st Number", "2nd_App", "---");

            userInput = Convert.ToInt32(user_Input);

            int[] output = new int[userInput];

            output[0] = firstNum + 1;

            for(int i = 1; i < userInput; i++)
            {
                storeNum = firstNum + secondNum;           
                output[i] = storeNum;
                firstNum = secondNum;
                secondNum = storeNum;
            }
        
            foreach(int index in output)
            {
                result += Convert.ToString(index) + ",";
            }

            result = result.Remove(result.Length - 1);
            MessageBox.Show($"Output is: {result}");
            this.Close();
        }
    }
}
