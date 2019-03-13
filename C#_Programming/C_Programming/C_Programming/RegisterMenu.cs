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
    public partial class Register_Menu : Form
    {
        public Register_Menu()
        {
            InitializeComponent();
        }

        #region Register

        string fullName = string.Empty;
        string username = string.Empty;
        string password = string.Empty;
        string confirmPass = string.Empty;

        private void checkKeyPress(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                fullName = txtName.Text;
                username = txtUsername.Text;
                password = txtPass.Text;
                confirmPass = txtConPass.Text;

                if(password != confirmPass)
                {
                    MessageBox.Show("Password is not the same!!");
                }
                else
                {
                    MessageBox.Show("Register Success");
                    login(ref username, ref password, ref fullName);
                }
            }
        }

        private void btnCreateAccount (object sender, EventArgs e)
        {
            fullName = txtName.Text;
            username = txtUsername.Text;
            password = txtPass.Text;
            confirmPass = txtConPass.Text;

            if (password != confirmPass)
            {
                MessageBox.Show("Password is not the same!!");
            }
            else
            {
                MessageBox.Show("Register Success");
                login(ref username, ref password, ref fullName);      
            }
        }

        #endregion

        #region functions

        private void login(ref string username, ref string password, ref string fullName)
        {
            LoginMenu loginMenu = new LoginMenu(ref username, ref password, ref fullName);
            this.Hide();
            loginMenu.ShowDialog();
            this.Close();
        }

        private void txtUsername_onClicked(object sender, EventArgs e)
        {
            txtUsername.Text = string.Empty;

            if (txtName.Text.Length == 0)
            {
                txtName.Text = "Full Name";
            }
            if (txtPass.Text.Length == 0)
            {
                txtPass.UseSystemPasswordChar = false;
                txtPass.Text = "Password";
            }
            if (txtConPass.Text.Length == 0)
            {
                txtConPass.UseSystemPasswordChar = false;
                txtConPass.Text = "Confirm Password";
            }
        }

        private void txtPass_onClicked(object sender, EventArgs e)
        {
            txtPass.UseSystemPasswordChar = true;
            txtPass.Text = string.Empty;

            if (txtName.Text.Length == 0)
            {
                txtName.Text = "Full Name";
            }
            if (txtUsername.Text.Length == 0)
            {
                txtUsername.Text = "Username";
            }
            if (txtConPass.Text.Length == 0)
            {
                txtConPass.UseSystemPasswordChar = false;
                txtConPass.Text = "Confirm Password";
            }

        }

        private void txtConPass_onClicked(object sender, EventArgs e)
        {
            txtConPass.UseSystemPasswordChar = true;
            txtConPass.Text = string.Empty;
            if (txtName.Text.Length == 0)
            {
                txtName.Text = "Full Name";
            }
            if (txtUsername.Text.Length == 0)
            {
                txtUsername.Text = "Username";
            }
            if (txtPass.Text.Length == 0)
            {
                txtPass.UseSystemPasswordChar = false;
                txtPass.Text = "Password";
            }
        }

        private void txtName_onClicked(object sender, EventArgs e)
        {
            txtName.Text = string.Empty;
            if (txtUsername.Text.Length == 0)
            {
                txtUsername.Text = "Username";
            }
            if (txtConPass.Text.Length == 0)
            {
                txtConPass.UseSystemPasswordChar = false;
                txtConPass.Text = "Confirm Password";
            }
            if (txtPass.Text.Length == 0)
            {
                txtPass.UseSystemPasswordChar = false;
                txtPass.Text = "Password";
            }
        }

        #endregion

        private void Register_Menu_Load(object sender, EventArgs e)
        {
            txtUsername.Text = "Username";
            txtPass.Text = "Password";
            txtConPass.Text = "Confirm Password";
            txtName.Text = "Full Name";
        }

    }
}
