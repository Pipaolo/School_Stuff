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
    public partial class Student_Identification : Form
    {
        public class Student
        {
            public string firstName = "";
            public string lastName = "";
            public string middleName = "";
            public string section = "";
        }

        public static string studentName = "";
        public static string studentSection = "";

        public Student_Identification()
        {
            InitializeComponent();
        }

        private void checkKeypress(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                Student student = new Student();
                student.firstName = txtFirstN.Text;
                student.lastName = txtLastN.Text;
                student.middleName = txtMiddleN.Text;
                student.section = txtSection.Text;
                studentName = $"{student.firstName} {student.middleName} {student.lastName}";
                studentSection = student.section;
                GradingMenu gradingMenu = new GradingMenu(studentName, studentSection);
                this.Hide();
                gradingMenu.ShowDialog();
                this.Close();
            }
        }

        private void btnSubmit_Click(object sender, EventArgs e)
        {
            Student student = new Student();
            student.firstName = txtFirstN.Text;
            student.lastName = txtLastN.Text;
            student.middleName = txtMiddleN.Text;
            student.section = txtSection.Text;
            studentName = $"{student.firstName} {student.middleName} {student.lastName}";
            studentSection = student.section;
            GradingMenu gradingMenu = new GradingMenu(studentName, studentSection);
            this.Hide();
            gradingMenu.ShowDialog();
            this.Close();

        }
    }
}
