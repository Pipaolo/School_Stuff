using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1st_MidTerm_Quiz
{
    public partial class SummaryPage : Form
    {
        public SummaryPage()
        {
            InitializeComponent();
        }

        private void SummaryPage_Load(object sender, EventArgs e)
        {
            //Add Labels
            txtMidTermsLecture.Text = "Lecture: ";
            txtMidTermsLab.Text = "Laboratory: ";
            txtMidTermsSoftSkills.Text = "Soft Skills: ";
            txtMidTermsTotal.Text = "Mid Terms: ";

            txtFinalsLecture.Text = "Lecture: ";
            txtFinalsLab.Text = "Laboratory: ";
            txtFinalsSoftSkills.Text = "Soft Skills: ";
            txtFinalsTotal.Text = "Finals: ";

            txtTrimesterGrade.Text = "Trimester Grade: ";

            //End Of Labels
            txtMidTermsLecture.Text += GradingMenu.lectureFinalLecture.ToString();
            txtMidTermsLab.Text += GradingMenu.lectureFinalLab.ToString();
            txtMidTermsSoftSkills.Text += GradingMenu.lectureFinalSoftS.ToString();
            txtMidTermsTotal.Text += GradingMenu.lectureFinalGrade.ToString();

            txtFinalsLecture.Text += GradingMenu_Finals_.lectureFinalLecture.ToString();
            txtFinalsLab.Text += GradingMenu_Finals_.lectureFinalLab.ToString();
            txtFinalsSoftSkills.Text += GradingMenu_Finals_.lectureFinalSoftS.ToString();
            txtFinalsTotal.Text += GradingMenu_Finals_.lectureFinalGrade.ToString();

            txtTrimesterGrade.Text += (GradingMenu_Finals_.lectureFinalGrade * .50) + (GradingMenu.lectureFinalGrade * .50);

        }
    }
}
