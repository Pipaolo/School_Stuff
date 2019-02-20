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
    public partial class GradingMenu : Form
    {

        public static double lectureFinalGrade = 0;
        public static double lectureFinalLecture = 0;
        public static double lectureFinalLab = 0;
        public static double lectureFinalSoftS = 0;

        public class Student
        {
            //LectureGrade
            public double gradeQuizzes = 0;
            public double gradeAttendance = 0;
            public double gradeRecitation = 0;
            public double gradeMajorW = 0;
            public double gradeLecture = 0;
            //LectureGradeEnd
            //SoftSkills
            public double gradeCommunication = 0;
            public double gradeTeamW = 0;
            public double gradeSoftSkills = 0;
            //SoftSkills
            //Laboratory
            public double gradeAct1 = 0;
            public double gradeAct2 = 0;
            public double gradeAct3 = 0;
            public double gradeAct4 = 0;
            public double gradeAct5 = 0;
            public double gradeLab = 0;
            //Laboratory
        }

        public GradingMenu(string name, string section)
        {
            InitializeComponent();
            tstStudentName.Text += name;
            tstSection.Text += section;
            txtFinalLecture.Text = "Lecture: ";
            txtFinalSoftSkill.Text = "Soft Skill: ";
            txtFinalLab.Text = "Laboratory: ";
            txtTotalMidTerm.Text = "MidTerm: ";
        }

        private void checkKeyPress(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                Student student = new Student();
                //Compute For Lecture Grade
                student.gradeQuizzes = ((Convert.ToInt64(txtQuizzes.Text) / Convert.ToInt64(txtQuizItems.Text) * 50) + 50) * .20;
                student.gradeAttendance = ((Convert.ToInt64(txtAttendance.Text) / Convert.ToInt64(txtAttendanceItems.Text) * 50) + 50) * .40;
                student.gradeRecitation = ((Convert.ToInt64(txtRecitation.Text) / Convert.ToInt64(txtRecitationItems.Text) * 50) + 50) * .10;
                student.gradeMajorW = ((Convert.ToInt64(txtMajorW.Text) / Convert.ToInt64(txtMajorWItems.Text) * 50) + 50) * .30;
                student.gradeLecture = (student.gradeQuizzes + student.gradeAttendance +
                                        student.gradeRecitation + student.gradeMajorW) * .25;
                //End of Compute
                //Compute For SoftSkills Grade
                student.gradeCommunication = ((Convert.ToInt64(txtComms.Text) / Convert.ToInt64(txtCommsItem.Text) * 50) + 50) * .50;
                student.gradeTeamW = ((Convert.ToInt64(txtTeamW.Text) / Convert.ToInt64(txtTeamWItems.Text) * 50) + 50) * .50;
                student.gradeSoftSkills = (student.gradeCommunication + student.gradeTeamW) * .30;
                //End of Compute
                //Compute For Laboratory Grade
                student.gradeAct1 = ((Convert.ToInt64(txtAct1.Text) / Convert.ToInt64(txtAct1Items.Text) * 50) + 50) * .20;
                student.gradeAct2 = ((Convert.ToInt64(txtAct2.Text) / Convert.ToInt64(txtAct2Items.Text) * 50) + 50) * .20;
                student.gradeAct3 = ((Convert.ToInt64(txtAct3.Text) / Convert.ToInt64(txtAct3Items.Text) * 50) + 50) * .20;
                student.gradeAct4 = ((Convert.ToInt64(txtAct4.Text) / Convert.ToInt64(txtAct4Items.Text) * 50) + 50) * .20;
                student.gradeAct5 = ((Convert.ToInt64(txtAct5.Text) / Convert.ToInt64(txtAct5Items.Text) * 50) + 50) * .20;
                student.gradeLab = (student.gradeAct1 + student.gradeAct2 + student.gradeAct3 +
                                    student.gradeAct4 + student.gradeAct5) * .45;
                //End of Compute

                txtFinalLecture.Text += student.gradeLecture.ToString();
                txtFinalSoftSkill.Text += student.gradeSoftSkills.ToString();
                txtFinalLab.Text += student.gradeLab.ToString();
                txtTotalMidTerm.Text += (student.gradeLecture + student.gradeLab + student.gradeSoftSkills).ToString();

                lectureFinalLecture = student.gradeLecture;
                lectureFinalSoftS = student.gradeSoftSkills;
                lectureFinalLab = student.gradeLab;
                lectureFinalGrade = student.gradeLecture + student.gradeLab + student.gradeSoftSkills;
            }
        }

        private void btnSubmit_Click(object sender, EventArgs e)
        {
            Student student = new Student();
            //Compute For Lecture Grade
            student.gradeQuizzes = ((Convert.ToInt64(txtQuizzes.Text) / Convert.ToInt64(txtQuizItems.Text) * 50) + 50) * .20;
            student.gradeAttendance = ((Convert.ToInt64(txtAttendance.Text) / Convert.ToInt64(txtAttendanceItems.Text) * 50) + 50) * .40;
            student.gradeRecitation = ((Convert.ToInt64(txtRecitation.Text) / Convert.ToInt64(txtRecitationItems.Text) * 50) + 50) * .10;
            student.gradeMajorW = ((Convert.ToInt64(txtMajorW.Text) / Convert.ToInt64(txtMajorWItems.Text) * 50) + 50) * .30;
            student.gradeLecture = (student.gradeQuizzes + student.gradeAttendance +
                                    student.gradeRecitation + student.gradeMajorW) * .25;
            //End of Compute
            //Compute For SoftSkills Grade
            student.gradeCommunication = ((Convert.ToInt64(txtComms.Text) / Convert.ToInt64(txtCommsItem.Text) * 50) + 50) * .50;
            student.gradeTeamW = ((Convert.ToInt64(txtTeamW.Text) / Convert.ToInt64(txtTeamWItems.Text) * 50) + 50) * .50;
            student.gradeSoftSkills = (student.gradeCommunication + student.gradeTeamW) * .30;
            //End of Compute
            //Compute For Laboratory Grade
            student.gradeAct1 = ((Convert.ToInt64(txtAct1.Text) / Convert.ToInt64(txtAct1Items.Text) * 50) + 50) * .20;
            student.gradeAct2 = ((Convert.ToInt64(txtAct2.Text) / Convert.ToInt64(txtAct2Items.Text) * 50) + 50) * .20;
            student.gradeAct3 = ((Convert.ToInt64(txtAct3.Text) / Convert.ToInt64(txtAct3Items.Text) * 50) + 50) * .20;
            student.gradeAct4 = ((Convert.ToInt64(txtAct4.Text) / Convert.ToInt64(txtAct4Items.Text) * 50) + 50) * .20;
            student.gradeAct5 = ((Convert.ToInt64(txtAct5.Text) / Convert.ToInt64(txtAct5Items.Text) * 50) + 50) * .20;
            student.gradeLab = (student.gradeAct1 + student.gradeAct2 + student.gradeAct3 + 
                                student.gradeAct4 + student.gradeAct5) * .45;
            //End of Compute

            txtFinalLecture.Text += student.gradeLecture.ToString();
            txtFinalSoftSkill.Text += student.gradeSoftSkills.ToString();
            txtFinalLab.Text += student.gradeLab.ToString();
            txtTotalMidTerm.Text += (student.gradeLecture + student.gradeLab + student.gradeSoftSkills).ToString();

            lectureFinalLecture = student.gradeLecture;
            lectureFinalSoftS = student.gradeSoftSkills;
            lectureFinalLab = student.gradeLab;
            lectureFinalGrade = student.gradeLecture + student.gradeLab + student.gradeSoftSkills;

            GradingMenu_Finals_ gradingMenu_Finals = new GradingMenu_Finals_(tstStudentName.Text, tstSection.Text);

            this.Hide();
            gradingMenu_Finals.ShowDialog();
            this.Close();

        }

    }
}
