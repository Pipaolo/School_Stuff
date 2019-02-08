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

namespace _20th_App
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
            string user_Input = Interaction.InputBox("Enter a Sentence/Words", "20th_App", "---");
            string inputCopy = user_Input;
            int charCount = 0;
            int counter = 0;
            int[] inputCount = new int[user_Input.Length];
            foreach (char index in user_Input)
            {               
                charCount = 0;
                foreach (char index2 in inputCopy)
                {
                    if (index == index2)
                    {
                        charCount++;
                    }
                }
                inputCount[counter] = charCount;
                counter++;
            }

            counter = 0;
            foreach (char index in user_Input)
            {

                finalOutput += index.ToString() + "\t\t" + inputCount[counter].ToString() + "\n";
                counter++;
            }
            finalOutput = finalOutput.Replace(" ", "space");
            MessageBox.Show(finalOutput);
            this.Close();
        }
    }
}
