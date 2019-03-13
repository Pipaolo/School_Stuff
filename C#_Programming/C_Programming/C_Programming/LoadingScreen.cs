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
    public partial class LoadingScreen : Form
    {
        string username = string.Empty;
        public LoadingScreen(ref string name)
        {
            username = name;
            InitializeComponent();
            timer1.Enabled = true;
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            pbLoad.Increment(15);
            if(pbLoad.Value == 100)
            {
                timer1.Stop();
                loadMenu();
            }
        }

        private void loadMenu()
        {
            MainMenu mainMenu = new MainMenu(ref username);
            this.Hide();
            mainMenu.ShowDialog();
            this.Close();
        }
    }
}
