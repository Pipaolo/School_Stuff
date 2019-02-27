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
    public partial class Questions : MaterialForm

    {
        int points = 0;
        int currentNumber = 0;
        string nameInput = "";
        string sectionInput = "";
        string dateInput = "";

        //Questions

        string[] answerSheet = new string[5] {"Lord Voldemort", "Boston, MA", "Rosh Hashanah",
                                              "Kaley Cuoco", "Subway"};

        string[] questionsList = new string[5] {
                                                "Which of these antagonist characters was created by novelist J.K. Rowling?",
                                                "Which of these cities is closest to London, UK?",
                                                "What is the name for the Jewish New Year?",
                                                "Which actress plays a major role on the TV show 'The Big Bang Theory'?",
                                                "What restaurant franchise advises you to 'Eat Fresh'?"
                                                };

        string[,] choiceList = new string[5, 4] { 
                                                {"Lord Voldemort","Professor Moriarty",
                                                 "Darth Vader", "Lord Farqaad"}, 
                                                {"Miami, FL", "Atlanta, GA",
                                                 "Boston, MA", "New York, NY"},
                                                {"Yom Kippur", "Kwanzaa",
                                                 "Hanukkah", "Rosh Hashanah"}, 
                                                {"Portia de Rossi", "Emily Deschanel",
                                                 "Kaley Cuoco", "Sofia Vergara"},
                                                {"McDonald's", "Subway",
                                                 "KFC", "Taco Bell"}
                                                };
        //End of Questions

        public Questions(string name, string section, string date)
        {
            InitializeComponent();
            nameInput = name;
            sectionInput = section;
            dateInput = date;
            this.timer1.Enabled = true;
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

        private void changeQuestions(int currentQuestion)
        {
            int i = 0;
            try
            {
                rtxtQuestion.Text = questionsList[currentQuestion];
                this.Text = "Question " + (currentNumber + 1).ToString();

                if (currentNumber != 0)
                {
                    tsProgress.Increment(20);
                }

                foreach (Control buttons in this.Controls)
                {
                    if (buttons is Button)
                    {
                        buttons.Text = choiceList[currentQuestion, i];
                        i++;
                    }
                }
                msPoints.Text = "Points: " + points.ToString();
            }
            catch (Exception exception)
            {
                tsProgress.Value += 20;
                this.timer1.Stop();
                MessageBox.Show($"Congratulations {nameInput} of {sectionInput}.\n You scored {points} out of 100.\n Date answered: {dateInput}.");
                this.Close();
            }
        }

        private void btnAnswerPressed(object sender, EventArgs e)
        {
            Button btnSender = (Button)sender;
            if (currentNumber == 0 && btnSender.Text == answerSheet[currentNumber])
            {
                MessageBox.Show("Correct!");
                currentNumber += 1;
                points += 20;
                changeQuestions(currentNumber);
                
            }
            else if (currentNumber == 1 && btnSender.Text == answerSheet[currentNumber])
            {
                MessageBox.Show("Correct!");
                currentNumber += 1;
                points += 20;
                changeQuestions(currentNumber);
            }
            else if (currentNumber == 2 && btnSender.Text == answerSheet[currentNumber])
            {
                MessageBox.Show("Correct!");
                currentNumber += 1;
                points += 20;
                changeQuestions(currentNumber);
            }
            else if (currentNumber == 3 && btnSender.Text == answerSheet[currentNumber])
            {
                MessageBox.Show("Correct!");
                currentNumber += 1;
                points += 20;
                changeQuestions(currentNumber);
            }
            else if (currentNumber == 4 && btnSender.Text == answerSheet[currentNumber])
            {              
                MessageBox.Show("Correct!");
                currentNumber += 1;
                points += 20;
                changeQuestions(currentNumber);
            }
            else
            {
                currentNumber += 1;
                changeQuestions(currentNumber);               
            }
            pbTime.Value = 0;
        }

        private void Questions_Load(object sender, EventArgs e)
        {
            changeQuestions(currentNumber);
            this.timer1.Start();
            msPoints.Text = "Points: " + points.ToString();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.pbTime.Increment(1);
            if(pbTime.Value == 100)
            {
                pbTime.Value = 0;
                currentNumber += 1;
                changeQuestions(currentNumber);
            }
        }

        private void tsExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
