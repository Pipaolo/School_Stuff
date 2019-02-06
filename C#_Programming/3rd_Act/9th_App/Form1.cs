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

namespace _9th_App
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
            int result = 0;
            int counter = 0;
            string output = "";

            string user_Input = Interaction.InputBox("Enter Number", "9th_App", "---");

            userInput = Convert.ToInt32(user_Input);

            for (int i = 1; i <= userInput; i++)
            {

                output += (i * i).ToString() + " + ";
                result += (i * i);
            }
            output = output.Remove(output.Length - 2);
            MessageBox.Show(output + " = " + result);
            this.Close();
        }
    }
}
