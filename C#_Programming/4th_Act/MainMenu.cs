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
    public partial class MainMenu : Form
    {
        //Declare Menu Items
        string[] Meals = new string[5] {"Chicken Ala King", "Siomai with Rice",
                                        "Chicken Fillet", "Chicken Salpicao", "Burger Steak"};
        string[] Burgers = new string[5] {"Cheese Burger","Upsized Burger","Quarter Pounder",
                                          "Chicken Sandwich","Double Chicken Sandwich"};
        string[] Specials = new string[5] {"Caesar Salad","Carbonara","Double Quarter Pounder Burger",
                                          "XXX Spicy Chicken","Honey Garlic Chicken Wings"};
        string[] Fries = new string[5] {"Small Fries","Medium Fries","Large Fries",
                                          "BigAss Fries","OmegaLul Fries"};
        string[] Desserts = new string[5] {"Chocolate Sundae","Strawberry Crepe","Matcha MilkShake",
                                          "Apple Pie","Tikoy"};
        string[] Drinks = new string[5] {"Coke Zero","Coke Regular","Sarsi",
                                          "Papsi","Fancha"};
        //End

        //Declare Menu Prices
        int[] mealPrices = new int[5] { 100, 50, 65, 80, 70 };
        int[] burgerPrices = new int[5] { 50, 70, 200, 90, 180 };
        int[] specialPrices = new int[5] { 50, 50, 290, 125, 100 };
        int[] friesPrices = new int[5] { 35, 55, 75, 95, 115 };
        int[] dessertPrices = new int[5] { 40, 80, 180, 30, 200 };
        int[] drinksPrices = new int[5] { 20, 20, 20, 20, 20 };
        //End

        //Iterator
        int counter = 0;
        //End

        //String Comparator
        string tempString = "";
        //End

        string currentSelected = "";
        int totalBill = 0;

        public MainMenu()
        {
            InitializeComponent();
        }

        private void generateMenu(string item, int price)
        {
            if (counter != 0)
            {
                while (item.Length < tempString.Length)
                {
                    item += "-";
                }
            }
            else
            {
                while (item.Length != 70)
                {
                    item += "-";
                }
                tempString = item;
            }
          
            item += $"P{price}";
            listBoxMenu.Items.Add(item);
            counter++;
        }

        private void comboBoxMenu_SelectedIndexChanged(object sender, EventArgs e)
        {
            chkDrinkSize.Enabled = false;
            counter = 0;
            listBoxMenu.Items.Clear();
            switch (comboBoxMenu.SelectedItem.ToString())
            {
                case "Meals":
                    currentSelected = "Meals";
                    for (int i = 0; i < Meals.Length; i++)
                    {
                        generateMenu(Meals[i], mealPrices[i]);
                    }
                    break;
                case "Burgers":
                    currentSelected = "Burgers";
                    for (int i = 0; i < Burgers.Length; i++)
                    {
                        generateMenu(Burgers[i], burgerPrices[i]);
                    }
                    break;
                case "Specials":
                    currentSelected = "Specials";
                    for (int i = 0; i < Specials.Length; i++)
                    {
                        generateMenu(Specials[i], specialPrices[i]);
                    }
                    break;
                case "Fries":
                    currentSelected = "Fries";
                    for (int i = 0; i < Fries.Length; i++)
                    {
                        generateMenu(Fries[i], friesPrices[i]);
                    }
                    break;
                case "Desserts":
                    currentSelected = "Desserts";
                    for (int i = 0; i < Desserts.Length; i++)
                    {
                        generateMenu(Desserts[i], dessertPrices[i]);
                    }
                    break;
                case "Drinks":
                    chkDrinkSize.Enabled = true;
                    currentSelected = "Drinks";
                    for (int i = 0; i < Drinks.Length; i++)
                    {
                        generateMenu(Drinks[i], drinksPrices[i]);
                    }
                    break;
            }

        }

        private void listBoxClicked(object sender, EventArgs e)
        {
            string quantityInput = "";
            string addCart = "";
            int addItemPrice = 0;
            switch (currentSelected)
            {
                case "Meals":
                    quantityInput = Interaction.InputBox($"How many? {Meals[listBoxMenu.SelectedIndex]}", "Quantity", "1");
                    if (quantityInput.Count() != 0)
                    {
                        addItemPrice = mealPrices[listBoxMenu.SelectedIndex];
                        addCart += Meals[listBoxMenu.SelectedIndex] + " x" + quantityInput + " P" + addItemPrice * Convert.ToInt32(quantityInput);
                        totalBill += addItemPrice;
                        listBoxCart.Items.Add(addCart);
                    }
                    else
                    {

                    }
                    break;
                case "Burgers":
                    quantityInput = Interaction.InputBox($"How many? {Burgers[listBoxMenu.SelectedIndex]}", "Quantity", "1");
                    if (quantityInput.Count() != 0)
                    {
                        addItemPrice = burgerPrices[listBoxMenu.SelectedIndex];
                        addCart += Burgers[listBoxMenu.SelectedIndex] + " x" + quantityInput + " P" + addItemPrice * Convert.ToInt32(quantityInput);
                        totalBill += addItemPrice;
                        listBoxCart.Items.Add(addCart);
                    }
                    else
                    {

                    }
                    break;
                case "Specials":
                    quantityInput = Interaction.InputBox($"How many? {Specials[listBoxMenu.SelectedIndex]}", "Quantity", "1");
                    if (quantityInput.Count() != 0)
                    {
                        addItemPrice = specialPrices[listBoxMenu.SelectedIndex];
                        addCart += Specials[listBoxMenu.SelectedIndex] + " x" + quantityInput + " P" + addItemPrice * Convert.ToInt32(quantityInput);
                        totalBill += addItemPrice;
                        listBoxCart.Items.Add(addCart);
                    }
                    else
                    {

                    }
                    break;
                case "Fries":
                    quantityInput = Interaction.InputBox($"How many? {Fries[listBoxMenu.SelectedIndex]}", "Quantity", "1");
                    if(quantityInput.Count() != 0)
                    {
                        addItemPrice = friesPrices[listBoxMenu.SelectedIndex];
                        addCart += Fries[listBoxMenu.SelectedIndex] + " x" + quantityInput + " P" + addItemPrice * Convert.ToInt32(quantityInput);
                        totalBill += addItemPrice;
                        listBoxCart.Items.Add(addCart);
                    }
                    else
                    {

                    }
                    break;
                case "Desserts":
                    quantityInput = Interaction.InputBox($"How many? {Desserts[listBoxMenu.SelectedIndex]}", "Quantity", "1");
                    if (quantityInput.Count() != 0)
                    {
                        addItemPrice = dessertPrices[listBoxMenu.SelectedIndex];
                        addCart += Desserts[listBoxMenu.SelectedIndex] + " x" + quantityInput + " P" + addItemPrice * Convert.ToInt32(quantityInput);
                        totalBill += addItemPrice;
                        listBoxCart.Items.Add(addCart);                   
                    }
                    else
                    {

                    }
                    break;
                case "Drinks":
                    try
                    {
                        if(chkDrinkSize.SelectedItem.ToString() == null)
                        {
                            MessageBox.Show("Please Choose a Drink Size!");
                        }
                        else
                        {
                            if (chkDrinkSize.SelectedItem.ToString() == "Small")
                            {
                                addCart += "S";
                                addItemPrice = drinksPrices[listBoxMenu.SelectedIndex];
                            }
                            else if (chkDrinkSize.SelectedItem.ToString() == "Medium")
                            {
                                addCart += "M";
                                addItemPrice = drinksPrices[listBoxMenu.SelectedIndex] + 10;
                            }
                            else if (chkDrinkSize.SelectedItem.ToString() == "Large")
                            {
                                addCart += "L";
                                addItemPrice = drinksPrices[listBoxMenu.SelectedIndex] + 20;
                            }
                         
                            quantityInput = Interaction.InputBox($"How many? {Drinks[listBoxMenu.SelectedIndex]}", "Quantity", "1");
                            if (quantityInput.Count() != 0)
                            {
                                addCart += Drinks[listBoxMenu.SelectedIndex] + " x" + quantityInput + " P" + addItemPrice * Convert.ToInt32(quantityInput);
                                totalBill += addItemPrice;
                                listBoxCart.Items.Add(addCart);
                            }
                            else
                            {

                            }
                        }
                    }
                    catch(System.NullReferenceException)
                    {
                        MessageBox.Show("Please Choose a Drink Size!");
                    }
                    break;
            }

        }

        private void MainMenu_Load(object sender, EventArgs e)
        {
            comboBoxMenu.SelectedItem = comboBoxMenu.Items[0];
        }

        private void chkDrinkSize_Checked(object sender, ItemCheckEventArgs e)
        {
            for (int i = 0; i < chkDrinkSize.Items.Count; ++i)
            {
                if(i != e.Index)
                {
                    chkDrinkSize.SetItemChecked(i, false);
                }
            }
        }

        private void btnCheckout_Click(object sender, EventArgs e)
        {
            if(listBoxCart.Items.Count == 0)
            {
                MessageBox.Show("Cart Empty!");
            }
            else
            {
                CheckOutMenu checkOut = new CheckOutMenu();
                foreach(string index in listBoxCart.Items)
                {
                    checkOut.listBoxCheckOut.Items.Add(index);
                }
                checkOut.totalBill = totalBill;
                this.Hide();
                checkOut.ShowDialog();
                this.Close();
            }
        }
    }
}
