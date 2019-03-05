namespace _5th_Act
{
    partial class Questions
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.rtxtQuestion = new System.Windows.Forms.RichTextBox();
            this.btnChoice1 = new MaterialSkin.Controls.MaterialFlatButton();
            this.btnChoice3 = new MaterialSkin.Controls.MaterialFlatButton();
            this.btnChoice2 = new MaterialSkin.Controls.MaterialFlatButton();
            this.btnChoice4 = new MaterialSkin.Controls.MaterialFlatButton();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.tsProgress = new System.Windows.Forms.ToolStripProgressBar();
            this.pbTime = new MaterialSkin.Controls.MaterialProgressBar();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.msInfos = new System.Windows.Forms.MenuStrip();
            this.msPoints = new System.Windows.Forms.ToolStripMenuItem();
            this.tsExit = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStrip1.SuspendLayout();
            this.msInfos.SuspendLayout();
            this.SuspendLayout();
            // 
            // rtxtQuestion
            // 
            this.rtxtQuestion.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rtxtQuestion.Location = new System.Drawing.Point(85, 104);
            this.rtxtQuestion.Name = "rtxtQuestion";
            this.rtxtQuestion.Size = new System.Drawing.Size(490, 72);
            this.rtxtQuestion.TabIndex = 0;
            this.rtxtQuestion.Text = "Which of these antagonist characters was created by novelist J.K. Rowling?";
            // 
            // btnChoice1
            // 
            this.btnChoice1.AutoSize = true;
            this.btnChoice1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnChoice1.Depth = 0;
            this.btnChoice1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnChoice1.Icon = null;
            this.btnChoice1.Location = new System.Drawing.Point(95, 211);
            this.btnChoice1.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.btnChoice1.MouseState = MaterialSkin.MouseState.HOVER;
            this.btnChoice1.Name = "btnChoice1";
            this.btnChoice1.Primary = false;
            this.btnChoice1.Size = new System.Drawing.Size(29, 36);
            this.btnChoice1.TabIndex = 1;
            this.btnChoice1.Text = "1";
            this.btnChoice1.UseVisualStyleBackColor = true;
            this.btnChoice1.Click += new System.EventHandler(this.btnAnswerPressed);
            // 
            // btnChoice3
            // 
            this.btnChoice3.AutoSize = true;
            this.btnChoice3.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnChoice3.Depth = 0;
            this.btnChoice3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.btnChoice3.Icon = null;
            this.btnChoice3.Location = new System.Drawing.Point(95, 279);
            this.btnChoice3.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.btnChoice3.MouseState = MaterialSkin.MouseState.HOVER;
            this.btnChoice3.Name = "btnChoice3";
            this.btnChoice3.Primary = false;
            this.btnChoice3.Size = new System.Drawing.Size(29, 36);
            this.btnChoice3.TabIndex = 2;
            this.btnChoice3.Text = "2";
            this.btnChoice3.UseVisualStyleBackColor = true;
            this.btnChoice3.Click += new System.EventHandler(this.btnAnswerPressed);
            // 
            // btnChoice2
            // 
            this.btnChoice2.AutoSize = true;
            this.btnChoice2.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnChoice2.Depth = 0;
            this.btnChoice2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.btnChoice2.Icon = null;
            this.btnChoice2.Location = new System.Drawing.Point(344, 212);
            this.btnChoice2.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.btnChoice2.MouseState = MaterialSkin.MouseState.HOVER;
            this.btnChoice2.Name = "btnChoice2";
            this.btnChoice2.Primary = false;
            this.btnChoice2.Size = new System.Drawing.Size(29, 36);
            this.btnChoice2.TabIndex = 3;
            this.btnChoice2.Text = "3";
            this.btnChoice2.UseVisualStyleBackColor = true;
            this.btnChoice2.Click += new System.EventHandler(this.btnAnswerPressed);
            // 
            // btnChoice4
            // 
            this.btnChoice4.AutoSize = true;
            this.btnChoice4.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnChoice4.Depth = 0;
            this.btnChoice4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.btnChoice4.Icon = null;
            this.btnChoice4.Location = new System.Drawing.Point(344, 279);
            this.btnChoice4.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.btnChoice4.MouseState = MaterialSkin.MouseState.HOVER;
            this.btnChoice4.Name = "btnChoice4";
            this.btnChoice4.Primary = false;
            this.btnChoice4.Size = new System.Drawing.Size(29, 36);
            this.btnChoice4.TabIndex = 4;
            this.btnChoice4.Text = "5";
            this.btnChoice4.UseVisualStyleBackColor = true;
            this.btnChoice4.Click += new System.EventHandler(this.btnAnswerPressed);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsProgress});
            this.statusStrip1.Location = new System.Drawing.Point(0, 428);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(658, 22);
            this.statusStrip1.TabIndex = 6;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // tsProgress
            // 
            this.tsProgress.Name = "tsProgress";
            this.tsProgress.Size = new System.Drawing.Size(643, 16);
            // 
            // pbTime
            // 
            this.pbTime.Depth = 0;
            this.pbTime.Location = new System.Drawing.Point(0, 63);
            this.pbTime.MarqueeAnimationSpeed = 1000;
            this.pbTime.Maximum = 60000;
            this.pbTime.MouseState = MaterialSkin.MouseState.HOVER;
            this.pbTime.Name = "pbTime";
            this.pbTime.Size = new System.Drawing.Size(658, 5);
            this.pbTime.TabIndex = 7;
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // msInfos
            // 
            this.msInfos.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.msPoints,
            this.tsExit});
            this.msInfos.Location = new System.Drawing.Point(0, 0);
            this.msInfos.Name = "msInfos";
            this.msInfos.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.msInfos.Size = new System.Drawing.Size(658, 24);
            this.msInfos.TabIndex = 8;
            this.msInfos.Text = "msInfos";
            // 
            // msPoints
            // 
            this.msPoints.Enabled = false;
            this.msPoints.Name = "msPoints";
            this.msPoints.Size = new System.Drawing.Size(55, 20);
            this.msPoints.Text = "Points:";
            // 
            // tsExit
            // 
            this.tsExit.Name = "tsExit";
            this.tsExit.Size = new System.Drawing.Size(37, 20);
            this.tsExit.Text = "Exit";
            this.tsExit.Click += new System.EventHandler(this.tsExit_Click);
            // 
            // Questions
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(658, 450);
            this.Controls.Add(this.pbTime);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.msInfos);
            this.Controls.Add(this.btnChoice4);
            this.Controls.Add(this.btnChoice2);
            this.Controls.Add(this.btnChoice3);
            this.Controls.Add(this.btnChoice1);
            this.Controls.Add(this.rtxtQuestion);
            this.MainMenuStrip = this.msInfos;
            this.Name = "Questions";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Question 1";
            this.Load += new System.EventHandler(this.Questions_Load);
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.msInfos.ResumeLayout(false);
            this.msInfos.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox rtxtQuestion;
        private MaterialSkin.Controls.MaterialFlatButton btnChoice1;
        private MaterialSkin.Controls.MaterialFlatButton btnChoice3;
        private MaterialSkin.Controls.MaterialFlatButton btnChoice2;
        private MaterialSkin.Controls.MaterialFlatButton btnChoice4;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripProgressBar tsProgress;
        private MaterialSkin.Controls.MaterialProgressBar pbTime;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.MenuStrip msInfos;
        private System.Windows.Forms.ToolStripMenuItem msPoints;
        private System.Windows.Forms.ToolStripMenuItem tsExit;
    }
}