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

namespace _17th_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string finalOutput = "";
            string user_Input = Interaction.InputBox("Enter Number", "16th_App", "---");
            user_Input = user_Input.Replace(" ", "");

            foreach (char index in user_Input)
            {
                finalOutput += index + "\n";
            }
            MessageBox.Show(finalOutput);
            this.Close();
        }
    }
}
