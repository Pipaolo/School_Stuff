using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _4th_Act
{

    public partial class Form1 : Form
    {
        string username = "";
        string password = "";
        string userInput = "";
        string passInput = "";
        string passCheck = "";

        public Form1()
        {
            InitializeComponent();
        }

        private void txtBoxUsername_Clicked(object sender, EventArgs e)
        {
            txtUsername.Text = "";
        }

        private void txtBoxInitialPass_Clicked(object sender, EventArgs e)
        {
            txtInitialPass.Text = "";
            txtInitialPass.UseSystemPasswordChar = true;
        }

        private void txtBoxFinalPass_Clicked(object sender, EventArgs e)
        {
            txtFinalPass.Text = "";
            txtFinalPass.UseSystemPasswordChar = true;
        }

        private void Check_KeyPress(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                userInput = txtUsername.Text;
                passInput = txtInitialPass.Text;
                passCheck = txtFinalPass.Text;
                if (passInput != passCheck)
                {
                    MessageBox.Show("Password is not the same!");
                }
                else
                {
                    MessageBox.Show("Registered Successfully!");
                    username = userInput;
                    password = passInput;
                    Login loginMenu = new Login();
                    loginMenu.username = username;
                    loginMenu.password = password;
                    this.Hide();
                    loginMenu.ShowDialog();
                    this.Show();
                }

            }
        }

        private void btnRegister_Click(object sender, EventArgs e)
        {
            userInput = txtUsername.Text;
            passInput = txtInitialPass.Text;
            passCheck = txtFinalPass.Text;
            if (passInput != passCheck)
            {
                MessageBox.Show("Password is not the same!");
            }
            else
            {
                MessageBox.Show("Registered Successfully!");
                username = userInput;
                password = passInput;
                Login loginMenu = new Login();
                loginMenu.username = username;
                loginMenu.password = password;
                this.Hide();
                loginMenu.ShowDialog();
                this.Show();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            txtUsername.Text = "Username";
            txtInitialPass.Text = "Password";
            txtFinalPass.Text = "Confirm Password";
            this.ActiveControl = txtUsername;
        }

        private void lnkSwitchMenu_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Login loginMenu = new Login();
            this.Hide();
            loginMenu.ShowDialog();
            this.Show();
        }
    }
}
