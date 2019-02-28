using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Web;
using System.Net;
using System.IO;
using MaterialSkin;
using MaterialSkin.Controls;
using Newtonsoft.Json;

namespace _5th_Act
{
    public partial class Questions : MaterialForm
    {
        Items jQuestions;

        int points = 0;
        int maxPoints = 0;
        int currentNumber = 0;

        int incrementValue = 0;

        string nameInput = "";
        string sectionInput = "";
        string dateInput = "";

        #region loadJson

        private void githubAccess()
        {
            string json = string.Empty;
            string githubToken = "14f3b838055fc41748a814b66e6fd07c01b39635";
            var request = (HttpWebRequest)WebRequest.Create("https://raw.githubusercontent.com/Pipaolo/QuestionsList/master/Questions.json");
            request.Headers.Add(HttpRequestHeader.Authorization, "token " + githubToken);
            request.Accept = "application/vnd.github.v3.raw";
            request.UserAgent = "Quiz App";
            using (var response = request.GetResponse())
            {
                using (StreamReader file = new StreamReader(response.GetResponseStream()))
                {
                    json = file.ReadToEnd();
                }
            }
            loadJson(json);
        }

        private void loadJson(string json)
        {
            try
            {
                jQuestions = JsonConvert.DeserializeObject<Items>(json);
            }
            catch(Exception ex)
            {
                System.Diagnostics.Debug.Write(ex.Message.ToString());
            }
        }
        #endregion


        public Questions(string name, string section, string date)
        {
            InitializeComponent();
            //Get Json Data from Github
            githubAccess();
            //End
            //Get Credentials
            nameInput = name;
            sectionInput = section;
            dateInput = date;
            //End
            this.timer1.Enabled = true;
            //Get MaxPoints
            maxPoints = jQuestions.QuestionsList.Count() * 20;
            //
            //Get Increment Value
            incrementValue = 100 / jQuestions.QuestionsList.Count();
            //

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
            try
            {
                int i = 0;
                rtxtQuestion.Text = jQuestions.QuestionsList[currentQuestion];
                this.Text = "Question " + (currentQuestion + 1).ToString();

                if (currentNumber != 0)
                {
                    tsProgress.Increment(incrementValue);
                }

                foreach (Control buttons in this.Controls)
                {
                    if (buttons is Button)
                    {
                        buttons.Text = jQuestions.ChoicesList[currentQuestion].choices[i];
                        i++;
                    }
                }
                msPoints.Text = "Points: " + points.ToString();
            }
            catch (Exception ex)
            {
                if (tsProgress.Value != 100)
                {
                    while(tsProgress.Value < 100)
                    {
                        tsProgress.Value += 1;
                    }
                }
                this.timer1.Stop();
                MessageBox.Show($"Congratulations {nameInput} of {sectionInput}.\n You scored {points} out of {maxPoints}.\n Date answered: {dateInput}.");
                this.Close();
            }
        }

        private void btnAnswerPressed(object sender, EventArgs e)
        {
            bool isCorrect = false;
            Button btnSender = (Button)sender;

            foreach(string index in jQuestions.Answersheet)
            {
                if(index == btnSender.Text)
                {
                    currentNumber += 1;
                    points += 20;
                    pbTime.Value = 0;
                    changeQuestions(currentNumber);
                    isCorrect = true;
                    break;
                }
            }
            
            if (isCorrect != true)
            {
                currentNumber += 1;
                changeQuestions(currentNumber);
                pbTime.Value = 0;
            }
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
