using MaterialSkin.Controls;
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
    public partial class Register : Form
    {
        public Register()
        {
            InitializeComponent();
        }

        string username = "";
        string password = "";

        string userInput = "";
        string passInput = "";
        string passInputCheck = "";

        private void txtUsername_Clicked(object sender, EventArgs e)
        {
            txtUsername.Text = "";
        }

        private void txtPassword_Clicked(object sender, EventArgs e)
        {
            txtPassword.Text = "";
            txtPassword.UseSystemPasswordChar = true;
        }

        private void txtConfirmPassword_Clicked(object sender, EventArgs e)
        {
            txtConfirmPassword.Text = "";
            txtConfirmPassword.UseSystemPasswordChar = true;
        }

        private void checkKeyPress(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                try
                {
                    userInput = txtUsername.Text;
                    passInput = txtPassword.Text;
                    passInputCheck = txtConfirmPassword.Text;
                    if (passInput == passInputCheck)
                    {
                        MessageBox.Show("Registered Successfully!");

                        Login loginMenu = new Login();
                        username = userInput;
                        password = passInput;
                        loginMenu.username = username;
                        loginMenu.password = password;
                        Hide();
                        loginMenu.ShowDialog();
                        Close();
                    }
                    else
                    {
                        MessageBox.Show("Passwords does not match!");
                    }
                }
                catch(System.FormatException)
                {

                }
            }
        }

        private void Register_Load(object sender, EventArgs e)
        {
            txtUsername.Text = "Username";
            txtPassword.Text = "Password";
            txtConfirmPassword.Text = "Confirm Password";
            ActiveControl = txtUsername;
        }

        private void btnSubmit_Click(object sender, EventArgs e)
        {
            try
            {
                userInput = txtUsername.Text;
                passInput = txtPassword.Text;
                passInputCheck = txtConfirmPassword.Text;
                if (passInput == passInputCheck)
                {
                    MessageBox.Show("Registered Successfully!");

                    Login loginMenu = new Login();
                    username = userInput;
                    password = passInput;
                    loginMenu.username = username;
                    loginMenu.password = password;
                    Hide();
                    loginMenu.ShowDialog();
                    Close();
                }
                else
                {
                    MessageBox.Show("Passwords does not match!");
                }
            }
            catch (System.FormatException)
            {

            }
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Login loginMenu = new Login();
            Hide();
            loginMenu.ShowDialog();
            Close();
        }

    }
}
