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

namespace _18th_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            int count = 0;
            string initialOutput = "";
            string user_Input = Interaction.InputBox("Enter A Noun", "18th_App", "---");
            initialOutput = user_Input;
            if (user_Input.EndsWith("y"))
            {
                user_Input = user_Input.Substring(0, user_Input.Length - 1);
                user_Input = user_Input.Insert(user_Input.Length, "ies");
            }
            else if (user_Input.EndsWith("s") || user_Input.EndsWith("ch") || user_Input.EndsWith("sh"))
            {
                user_Input += "es";
            }
            else
            {
                user_Input += "s";
            }
            MessageBox.Show($"The plural of {initialOutput} is {user_Input}");
            this.Close();
        }
    }
}
