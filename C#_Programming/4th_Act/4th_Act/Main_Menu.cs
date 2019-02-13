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

namespace _4th_Act
{
    public partial class Main_Menu : Form
    {
        string selectedNode = "";
        string inputQuantity = "";
        int[] burgerPrice = new int[4] { 120, 100, 85, 90 };
        int[] mealsPrice = new int[5] { 150, 135, 130, 120, 500 };
        int[] specialsPrice = new int[6] { 50, 80, 100, 30, 20, 170 };
        

        public Main_Menu()
        {
            InitializeComponent();
        }

        private void treeView1_AfterSelect_1(object sender, TreeViewEventArgs e)
        {
            start:
            selectedNode = e.Node.Text;
            string currentNode = Convert.ToString(e.Node.Parent);
            int quantity = 0;

            if (selectedNode == "Meals" || selectedNode == "Burgers" || selectedNode == "Specials")
            {

            }
            else
            {
                
                if(currentNode.Count() > 0)
                {
                    currentNode = currentNode.Remove(0, 10);
                }
                if (currentNode == "Burgers")
                {
                    MessageBox.Show("You have chosen " + selectedNode + $" it's price is {burgerPrice[e.Node.Index]}");
                    inputQuantity = Interaction.InputBox("Enter Quantitiy", "Quantity", "---");
                }
                else if (currentNode == "Meals")
                {
                    MessageBox.Show("You have chosen " + selectedNode + $" it's price is {mealsPrice[e.Node.Index]}");
                    inputQuantity = Interaction.InputBox("Enter Quantitiy", "Quantity", "---");

                }
                else if (currentNode == "Specials")
                {
                    MessageBox.Show("You have chosen " + selectedNode + $" it's price is {specialsPrice[e.Node.Index]}");
                    inputQuantity = Interaction.InputBox("Enter Quantitiy", "Quantity", "---");
                }
                try
                {
                    quantity = Convert.ToInt32(inputQuantity);
                }
                catch(System.FormatException)
                {
                    goto start;
                }

            }
        }
    }
}
