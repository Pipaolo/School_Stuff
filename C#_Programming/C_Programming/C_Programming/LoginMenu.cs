using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace C_Programming
{
    public partial class LoginMenu : Form
    {
        string username = string.Empty;
        string password = string.Empty;
        string fullName = string.Empty;

        public LoginMenu(ref string user, ref string pass, ref string name)
        {
            InitializeComponent();
            username = user;
            password = pass;
            fullName = name;
        }

        #region Register
        string usernameInput = string.Empty;
        string passwordInput = string.Empty;

        private void checkKeyPress(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                usernameInput = txtUsername.Text;
                passwordInput = txtPass.Text;

                if (username == usernameInput && password == passwordInput)
                {
                    MessageBox.Show($"Welcome {fullName}!");
                    loadingScreen();
                }
                else
                {
                    MessageBox.Show("Invalid Username/Password!");
                }
            }
        }

        private void btnLogin_Clicked(object sender, EventArgs e)
        {
            usernameInput = txtUsername.Text;
            passwordInput = txtPass.Text;

            if (username != usernameInput && password != passwordInput)
            {
                MessageBox.Show("Invalid Username/Password!");
            }
            else
            {
                MessageBox.Show($"Welcome {fullName}!");
                loadingScreen();
            }
        }
        #endregion

        #region functions

        private void loadingScreen()
        {
            LoadingScreen loading_Screen = new LoadingScreen(ref fullName);
            loading_Screen.ShowDialog();
            this.Close();
        }

        private void txtUsername_onClicked(object sender, EventArgs e)
        {
            txtUsername.Text = string.Empty;
            if (txtPass.Text.Length == 0)
            {
                txtPass.UseSystemPasswordChar = false;
                txtPass.Text = "Password";
            }
        }

        private void txtPass_onClicked(object sender, EventArgs e)
        {
            txtPass.UseSystemPasswordChar = true;
            txtPass.Text = string.Empty;
            if (txtUsername.Text.Length == 0)
            {
                txtUsername.Text = "Username";
            }
        }

        private void LoginMenu_Load(object sender, EventArgs e)
        {
            txtUsername.Text = "Username";
            txtPass.Text = "Password";
        }

        #endregion

    }
}
