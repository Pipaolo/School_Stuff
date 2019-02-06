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

namespace _16th_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        /*
         * Write the program that will accepts a string and output the word per line.  For example an input of

            The World is beautiful.

            will produce

            The
            World 
            is 
            beautiful.

         * 
         * 
         */

        private void Form1_Load(object sender, EventArgs e)
        {
            string finalOutput = "";
            string user_Input = Interaction.InputBox("Enter Number", "16th_App", "---");

            string[] output = user_Input.Split(' ');

            foreach (string index in output)
            {
                finalOutput += index + "\n";
            }
            MessageBox.Show(finalOutput);
            this.Close();
        }
    }
}
