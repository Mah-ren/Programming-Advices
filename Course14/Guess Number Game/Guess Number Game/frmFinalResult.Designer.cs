namespace Guess_Number_Game
{
    partial class frmFinalResult
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
            this.btRestart = new System.Windows.Forms.Button();
            this.lblTitle = new System.Windows.Forms.Label();
            this.gbQuestionsInfo = new System.Windows.Forms.GroupBox();
            this.lbDescriptionResult = new System.Windows.Forms.Label();
            this.lbDescriptipnQuestionsLevel = new System.Windows.Forms.Label();
            this.lbNumberOfWrongAnswer = new System.Windows.Forms.Label();
            this.lbNumberOfRigthAnswer = new System.Windows.Forms.Label();
            this.lbNumberOfQuestaions = new System.Windows.Forms.Label();
            this.lbResult = new System.Windows.Forms.Label();
            this.lbQuestionsLevel = new System.Windows.Forms.Label();
            this.lbWrongAnswer = new System.Windows.Forms.Label();
            this.lbRigthAnswer = new System.Windows.Forms.Label();
            this.lbQuestions = new System.Windows.Forms.Label();
            this.gbQuestionsInfo.SuspendLayout();
            this.SuspendLayout();
            // 
            // btRestart
            // 
            this.btRestart.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btRestart.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btRestart.Font = new System.Drawing.Font("Copperplate Gothic Light", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btRestart.ForeColor = System.Drawing.Color.SteelBlue;
            this.btRestart.Location = new System.Drawing.Point(117, 330);
            this.btRestart.Name = "btRestart";
            this.btRestart.Size = new System.Drawing.Size(100, 28);
            this.btRestart.TabIndex = 1;
            this.btRestart.Text = "ReStart";
            this.btRestart.UseVisualStyleBackColor = true;
            this.btRestart.Click += new System.EventHandler(this.btRestart_Click);
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Copperplate Gothic Bold", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.ForeColor = System.Drawing.Color.SteelBlue;
            this.lblTitle.Location = new System.Drawing.Point(82, 29);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(185, 26);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "Final Result";
            // 
            // gbQuestionsInfo
            // 
            this.gbQuestionsInfo.Controls.Add(this.lbDescriptionResult);
            this.gbQuestionsInfo.Controls.Add(this.lbDescriptipnQuestionsLevel);
            this.gbQuestionsInfo.Controls.Add(this.lbNumberOfWrongAnswer);
            this.gbQuestionsInfo.Controls.Add(this.lbNumberOfRigthAnswer);
            this.gbQuestionsInfo.Controls.Add(this.lbNumberOfQuestaions);
            this.gbQuestionsInfo.Controls.Add(this.lbResult);
            this.gbQuestionsInfo.Controls.Add(this.lbQuestionsLevel);
            this.gbQuestionsInfo.Controls.Add(this.lbWrongAnswer);
            this.gbQuestionsInfo.Controls.Add(this.lbRigthAnswer);
            this.gbQuestionsInfo.Controls.Add(this.lbQuestions);
            this.gbQuestionsInfo.Location = new System.Drawing.Point(62, 78);
            this.gbQuestionsInfo.Name = "gbQuestionsInfo";
            this.gbQuestionsInfo.Size = new System.Drawing.Size(216, 226);
            this.gbQuestionsInfo.TabIndex = 0;
            this.gbQuestionsInfo.TabStop = false;
            // 
            // lbDescriptionResult
            // 
            this.lbDescriptionResult.AutoSize = true;
            this.lbDescriptionResult.Font = new System.Drawing.Font("Tahoma", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbDescriptionResult.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.lbDescriptionResult.Location = new System.Drawing.Point(142, 194);
            this.lbDescriptionResult.Name = "lbDescriptionResult";
            this.lbDescriptionResult.Size = new System.Drawing.Size(46, 14);
            this.lbDescriptionResult.TabIndex = 0;
            this.lbDescriptionResult.Text = "Winner";
            // 
            // lbDescriptipnQuestionsLevel
            // 
            this.lbDescriptipnQuestionsLevel.AutoSize = true;
            this.lbDescriptipnQuestionsLevel.Font = new System.Drawing.Font("Tahoma", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbDescriptipnQuestionsLevel.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.lbDescriptipnQuestionsLevel.Location = new System.Drawing.Point(158, 67);
            this.lbDescriptipnQuestionsLevel.Name = "lbDescriptipnQuestionsLevel";
            this.lbDescriptipnQuestionsLevel.Size = new System.Drawing.Size(47, 14);
            this.lbDescriptipnQuestionsLevel.TabIndex = 0;
            this.lbDescriptipnQuestionsLevel.Text = "Medum";
            // 
            // lbNumberOfWrongAnswer
            // 
            this.lbNumberOfWrongAnswer.AutoSize = true;
            this.lbNumberOfWrongAnswer.Font = new System.Drawing.Font("Tahoma", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbNumberOfWrongAnswer.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.lbNumberOfWrongAnswer.Location = new System.Drawing.Point(158, 140);
            this.lbNumberOfWrongAnswer.Name = "lbNumberOfWrongAnswer";
            this.lbNumberOfWrongAnswer.Size = new System.Drawing.Size(14, 14);
            this.lbNumberOfWrongAnswer.TabIndex = 0;
            this.lbNumberOfWrongAnswer.Text = "0";
            // 
            // lbNumberOfRigthAnswer
            // 
            this.lbNumberOfRigthAnswer.AutoSize = true;
            this.lbNumberOfRigthAnswer.Font = new System.Drawing.Font("Tahoma", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbNumberOfRigthAnswer.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.lbNumberOfRigthAnswer.Location = new System.Drawing.Point(158, 114);
            this.lbNumberOfRigthAnswer.Name = "lbNumberOfRigthAnswer";
            this.lbNumberOfRigthAnswer.Size = new System.Drawing.Size(14, 14);
            this.lbNumberOfRigthAnswer.TabIndex = 0;
            this.lbNumberOfRigthAnswer.Text = "0";
            // 
            // lbNumberOfQuestaions
            // 
            this.lbNumberOfQuestaions.AutoSize = true;
            this.lbNumberOfQuestaions.Font = new System.Drawing.Font("Tahoma", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbNumberOfQuestaions.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.lbNumberOfQuestaions.Location = new System.Drawing.Point(158, 30);
            this.lbNumberOfQuestaions.Name = "lbNumberOfQuestaions";
            this.lbNumberOfQuestaions.Size = new System.Drawing.Size(14, 14);
            this.lbNumberOfQuestaions.TabIndex = 0;
            this.lbNumberOfQuestaions.Text = "0";
            // 
            // lbResult
            // 
            this.lbResult.AutoSize = true;
            this.lbResult.Font = new System.Drawing.Font("Copperplate Gothic Bold", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbResult.Location = new System.Drawing.Point(15, 193);
            this.lbResult.Name = "lbResult";
            this.lbResult.Size = new System.Drawing.Size(61, 15);
            this.lbResult.TabIndex = 0;
            this.lbResult.Text = "Result:";
            // 
            // lbQuestionsLevel
            // 
            this.lbQuestionsLevel.AutoSize = true;
            this.lbQuestionsLevel.Font = new System.Drawing.Font("Copperplate Gothic Bold", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbQuestionsLevel.Location = new System.Drawing.Point(15, 67);
            this.lbQuestionsLevel.Name = "lbQuestionsLevel";
            this.lbQuestionsLevel.Size = new System.Drawing.Size(128, 15);
            this.lbQuestionsLevel.TabIndex = 0;
            this.lbQuestionsLevel.Text = "Questions Level:";
            // 
            // lbWrongAnswer
            // 
            this.lbWrongAnswer.AutoSize = true;
            this.lbWrongAnswer.Font = new System.Drawing.Font("Copperplate Gothic Bold", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbWrongAnswer.ForeColor = System.Drawing.Color.Red;
            this.lbWrongAnswer.Location = new System.Drawing.Point(15, 140);
            this.lbWrongAnswer.Name = "lbWrongAnswer";
            this.lbWrongAnswer.Size = new System.Drawing.Size(124, 15);
            this.lbWrongAnswer.TabIndex = 0;
            this.lbWrongAnswer.Text = "Wrong Answer:";
            // 
            // lbRigthAnswer
            // 
            this.lbRigthAnswer.AutoSize = true;
            this.lbRigthAnswer.Font = new System.Drawing.Font("Copperplate Gothic Bold", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbRigthAnswer.ForeColor = System.Drawing.Color.Green;
            this.lbRigthAnswer.Location = new System.Drawing.Point(15, 114);
            this.lbRigthAnswer.Name = "lbRigthAnswer";
            this.lbRigthAnswer.Size = new System.Drawing.Size(112, 15);
            this.lbRigthAnswer.TabIndex = 0;
            this.lbRigthAnswer.Text = "Rigth Answer:";
            // 
            // lbQuestions
            // 
            this.lbQuestions.AutoSize = true;
            this.lbQuestions.Font = new System.Drawing.Font("Copperplate Gothic Bold", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbQuestions.Location = new System.Drawing.Point(15, 30);
            this.lbQuestions.Name = "lbQuestions";
            this.lbQuestions.Size = new System.Drawing.Size(85, 15);
            this.lbQuestions.TabIndex = 0;
            this.lbQuestions.Text = "Questions:";
            // 
            // frmFinalResult
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(334, 380);
            this.Controls.Add(this.btRestart);
            this.Controls.Add(this.lblTitle);
            this.Controls.Add(this.gbQuestionsInfo);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmFinalResult";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Guess Number Game";
            this.Load += new System.EventHandler(this.frmFinalResult_Load);
            this.Move += new System.EventHandler(this.frmFinalResult_Move);
            this.Resize += new System.EventHandler(this.frmFinalResult_Resize);
            this.gbQuestionsInfo.ResumeLayout(false);
            this.gbQuestionsInfo.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btRestart;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.GroupBox gbQuestionsInfo;
        private System.Windows.Forms.Label lbDescriptionResult;
        private System.Windows.Forms.Label lbDescriptipnQuestionsLevel;
        private System.Windows.Forms.Label lbNumberOfWrongAnswer;
        private System.Windows.Forms.Label lbNumberOfRigthAnswer;
        private System.Windows.Forms.Label lbNumberOfQuestaions;
        private System.Windows.Forms.Label lbResult;
        private System.Windows.Forms.Label lbQuestionsLevel;
        private System.Windows.Forms.Label lbWrongAnswer;
        private System.Windows.Forms.Label lbRigthAnswer;
        private System.Windows.Forms.Label lbQuestions;
    }
}