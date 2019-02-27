using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MaterialSkin;
using MaterialSkin.Controls;

namespace _5th_Act
{
    public partial class InfoMenu : MaterialForm
    {
        string date = "";
        public InfoMenu()
        {
            InitializeComponent();
            // Create a material theme manager and add the form to manage (this)
            MaterialSkinManager materialSkinManager = MaterialSkinManager.Instance;
            materialSkinManager.AddFormToManage(this);
            materialSkinManager.Theme = MaterialSkinManager.Themes.LIGHT;

            // Configure color schema
            materialSkinManager.ColorScheme = new ColorScheme(
                Primary.Blue400, Primary.Blue500,
                Primary.Blue500, Accent.LightBlue200,
                TextShade.WHITE
            );
        }

        private void studentSection_isFocused(object sender, EventArgs e)
        {
            txtStudentSection.Text = "";
        }

        private void studentName_isFocused(object sender, EventArgs e)
        {
            txtStudentName.Text = "";
        }

        private void dateTimePicker1_ValueChanged()
        {
            string Day = dateTimePicker1.Value.Day.ToString();
            string Month = dateTimePicker1.Value.Month.ToString();
            string Year = dateTimePicker1.Value.Year.ToString();
            date = $"{Month}/{Day}/{Year}";
            
        }

        private void materialFlatButton1_Click(object sender, EventArgs e)
        {
            dateTimePicker1_ValueChanged();
            Questions questions = new Questions(txtStudentName.Text, txtStudentSection.Text, date);
            this.Hide();
            questions.ShowDialog();
            this.Close();
        }
    }
}
