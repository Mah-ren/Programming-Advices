namespace Guess_Number_Game
{
    partial class frmBeginGame
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmBeginGame));
            this.grpMenueGame = new System.Windows.Forms.GroupBox();
            this.lbCounterTimer = new System.Windows.Forms.Label();
            this.picImageTimer = new System.Windows.Forms.PictureBox();
            this.pbWrong = new System.Windows.Forms.PictureBox();
            this.pbRigth = new System.Windows.Forms.PictureBox();
            this.btNext = new System.Windows.Forms.Button();
            this.gbCalclutaor = new System.Windows.Forms.GroupBox();
            this.lbHintDescriptipn = new System.Windows.Forms.Label();
            this.lbHint = new System.Windows.Forms.Label();
            this.btCheck = new System.Windows.Forms.Button();
            this.tbUserAnswer = new System.Windows.Forms.TextBox();
            this.lbGuessNumber = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.lbCounterNumberOfQuestaion = new System.Windows.Forms.Label();
            this.lbNumberOfQuestaion = new System.Windows.Forms.Label();
            this.lbCounterWrong = new System.Windows.Forms.Label();
            this.lbCounterRigth = new System.Windows.Forms.Label();
            this.tmrCounterTime = new System.Windows.Forms.Timer(this.components);
            this.erpExsistError = new System.Windows.Forms.ErrorProvider(this.components);
            this.grpMenueGame.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picImageTimer)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbWrong)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbRigth)).BeginInit();
            this.gbCalclutaor.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.erpExsistError)).BeginInit();
            this.SuspendLayout();
            // 
            // grpMenueGame
            // 
            this.grpMenueGame.Controls.Add(this.lbCounterTimer);
            this.grpMenueGame.Controls.Add(this.picImageTimer);
            this.grpMenueGame.Controls.Add(this.pbWrong);
            this.grpMenueGame.Controls.Add(this.pbRigth);
            this.grpMenueGame.Controls.Add(this.btNext);
            this.grpMenueGame.Controls.Add(this.gbCalclutaor);
            this.grpMenueGame.Controls.Add(this.lbCounterNumberOfQuestaion);
            this.grpMenueGame.Controls.Add(this.lbNumberOfQuestaion);
            this.grpMenueGame.Controls.Add(this.lbCounterWrong);
            this.grpMenueGame.Controls.Add(this.lbCounterRigth);
            this.grpMenueGame.Location = new System.Drawing.Point(18, 11);
            this.grpMenueGame.Name = "grpMenueGame";
            this.grpMenueGame.Size = new System.Drawing.Size(456, 400);
            this.grpMenueGame.TabIndex = 0;
            this.grpMenueGame.TabStop = false;
            // 
            // lbCounterTimer
            // 
            this.lbCounterTimer.AutoSize = true;
            this.lbCounterTimer.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F);
            this.lbCounterTimer.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.lbCounterTimer.Location = new System.Drawing.Point(123, 97);
            this.lbCounterTimer.Name = "lbCounterTimer";
            this.lbCounterTimer.Size = new System.Drawing.Size(24, 18);
            this.lbCounterTimer.TabIndex = 6;
            this.lbCounterTimer.Text = "15";
            // 
            // picImageTimer
            // 
            this.picImageTimer.Image = ((System.Drawing.Image)(resources.GetObject("picImageTimer.Image")));
            this.picImageTimer.Location = new System.Drawing.Point(21, 57);
            this.picImageTimer.Name = "picImageTimer";
            this.picImageTimer.Size = new System.Drawing.Size(118, 68);
            this.picImageTimer.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picImageTimer.TabIndex = 7;
            this.picImageTimer.TabStop = false;
            // 
            // pbWrong
            // 
            this.pbWrong.Image = ((System.Drawing.Image)(resources.GetObject("pbWrong.Image")));
            this.pbWrong.Location = new System.Drawing.Point(366, 79);
            this.pbWrong.Name = "pbWrong";
            this.pbWrong.Size = new System.Drawing.Size(49, 36);
            this.pbWrong.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pbWrong.TabIndex = 4;
            this.pbWrong.TabStop = false;
            // 
            // pbRigth
            // 
            this.pbRigth.Image = ((System.Drawing.Image)(resources.GetObject("pbRigth.Image")));
            this.pbRigth.Location = new System.Drawing.Point(364, 19);
            this.pbRigth.Name = "pbRigth";
            this.pbRigth.Size = new System.Drawing.Size(51, 46);
            this.pbRigth.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pbRigth.TabIndex = 3;
            this.pbRigth.TabStop = false;
            // 
            // btNext
            // 
            this.btNext.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btNext.Enabled = false;
            this.btNext.Font = new System.Drawing.Font("Copperplate Gothic Light", 9.75F);
            this.btNext.Location = new System.Drawing.Point(176, 359);
            this.btNext.Name = "btNext";
            this.btNext.Size = new System.Drawing.Size(100, 23);
            this.btNext.TabIndex = 3;
            this.btNext.Text = "Next";
            this.btNext.UseVisualStyleBackColor = true;
            this.btNext.Click += new System.EventHandler(this.btNext_Click);
            // 
            // gbCalclutaor
            // 
            this.gbCalclutaor.Controls.Add(this.lbHintDescriptipn);
            this.gbCalclutaor.Controls.Add(this.lbHint);
            this.gbCalclutaor.Controls.Add(this.btCheck);
            this.gbCalclutaor.Controls.Add(this.tbUserAnswer);
            this.gbCalclutaor.Controls.Add(this.lbGuessNumber);
            this.gbCalclutaor.Controls.Add(this.label5);
            this.gbCalclutaor.Controls.Add(this.label6);
            this.gbCalclutaor.Location = new System.Drawing.Point(45, 178);
            this.gbCalclutaor.Name = "gbCalclutaor";
            this.gbCalclutaor.Size = new System.Drawing.Size(370, 161);
            this.gbCalclutaor.TabIndex = 0;
            this.gbCalclutaor.TabStop = false;
            // 
            // lbHintDescriptipn
            // 
            this.lbHintDescriptipn.AutoSize = true;
            this.lbHintDescriptipn.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbHintDescriptipn.ForeColor = System.Drawing.Color.Black;
            this.lbHintDescriptipn.Location = new System.Drawing.Point(91, 46);
            this.lbHintDescriptipn.Name = "lbHintDescriptipn";
            this.lbHintDescriptipn.Size = new System.Drawing.Size(30, 13);
            this.lbHintDescriptipn.TabIndex = 0;
            this.lbHintDescriptipn.Text = "Hint:";
            // 
            // lbHint
            // 
            this.lbHint.AutoSize = true;
            this.lbHint.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbHint.ForeColor = System.Drawing.Color.Red;
            this.lbHint.Location = new System.Drawing.Point(64, 46);
            this.lbHint.Name = "lbHint";
            this.lbHint.Size = new System.Drawing.Size(30, 13);
            this.lbHint.TabIndex = 0;
            this.lbHint.Text = "Hint:";
            // 
            // btCheck
            // 
            this.btCheck.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btCheck.Font = new System.Drawing.Font("Copperplate Gothic Light", 9.75F);
            this.btCheck.Location = new System.Drawing.Point(132, 124);
            this.btCheck.Name = "btCheck";
            this.btCheck.Size = new System.Drawing.Size(100, 23);
            this.btCheck.TabIndex = 2;
            this.btCheck.Text = "Check";
            this.btCheck.UseVisualStyleBackColor = true;
            this.btCheck.Click += new System.EventHandler(this.btCheck_Click);
            // 
            // tbUserAnswer
            // 
            this.tbUserAnswer.Cursor = System.Windows.Forms.Cursors.Hand;
            this.tbUserAnswer.Location = new System.Drawing.Point(132, 88);
            this.tbUserAnswer.MaxLength = 2;
            this.tbUserAnswer.Name = "tbUserAnswer";
            this.tbUserAnswer.Size = new System.Drawing.Size(100, 20);
            this.tbUserAnswer.TabIndex = 1;
            // 
            // lbGuessNumber
            // 
            this.lbGuessNumber.AutoSize = true;
            this.lbGuessNumber.Font = new System.Drawing.Font("Copperplate Gothic Bold", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbGuessNumber.Location = new System.Drawing.Point(45, 24);
            this.lbGuessNumber.Name = "lbGuessNumber";
            this.lbGuessNumber.Size = new System.Drawing.Size(277, 18);
            this.lbGuessNumber.TabIndex = 0;
            this.lbGuessNumber.Text = "Guess Number Between 1 - 10?";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Showcard Gothic", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label5.Location = new System.Drawing.Point(376, 87);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(21, 23);
            this.label5.TabIndex = 10;
            this.label5.Text = "0";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Showcard Gothic", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label6.Location = new System.Drawing.Point(376, 48);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(21, 23);
            this.label6.TabIndex = 7;
            this.label6.Text = "0";
            // 
            // lbCounterNumberOfQuestaion
            // 
            this.lbCounterNumberOfQuestaion.AutoSize = true;
            this.lbCounterNumberOfQuestaion.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F);
            this.lbCounterNumberOfQuestaion.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.lbCounterNumberOfQuestaion.Location = new System.Drawing.Point(150, 33);
            this.lbCounterNumberOfQuestaion.Name = "lbCounterNumberOfQuestaion";
            this.lbCounterNumberOfQuestaion.Size = new System.Drawing.Size(36, 18);
            this.lbCounterNumberOfQuestaion.TabIndex = 0;
            this.lbCounterNumberOfQuestaion.Text = "0/10";
            // 
            // lbNumberOfQuestaion
            // 
            this.lbNumberOfQuestaion.AutoSize = true;
            this.lbNumberOfQuestaion.Font = new System.Drawing.Font("Copperplate Gothic Bold", 14.25F);
            this.lbNumberOfQuestaion.Location = new System.Drawing.Point(22, 31);
            this.lbNumberOfQuestaion.Name = "lbNumberOfQuestaion";
            this.lbNumberOfQuestaion.Size = new System.Drawing.Size(127, 21);
            this.lbNumberOfQuestaion.TabIndex = 0;
            this.lbNumberOfQuestaion.Text = "Questaion:";
            // 
            // lbCounterWrong
            // 
            this.lbCounterWrong.AutoSize = true;
            this.lbCounterWrong.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F);
            this.lbCounterWrong.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.lbCounterWrong.Location = new System.Drawing.Point(421, 96);
            this.lbCounterWrong.Name = "lbCounterWrong";
            this.lbCounterWrong.Size = new System.Drawing.Size(16, 18);
            this.lbCounterWrong.TabIndex = 0;
            this.lbCounterWrong.Text = "0";
            // 
            // lbCounterRigth
            // 
            this.lbCounterRigth.AutoSize = true;
            this.lbCounterRigth.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F);
            this.lbCounterRigth.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.lbCounterRigth.Location = new System.Drawing.Point(421, 42);
            this.lbCounterRigth.Name = "lbCounterRigth";
            this.lbCounterRigth.Size = new System.Drawing.Size(16, 18);
            this.lbCounterRigth.TabIndex = 0;
            this.lbCounterRigth.Text = "0";
            // 
            // tmrCounterTime
            // 
            this.tmrCounterTime.Interval = 1000;
            this.tmrCounterTime.Tick += new System.EventHandler(this.tmrCounterTime_Tick);
            // 
            // erpExsistError
            // 
            this.erpExsistError.ContainerControl = this;
            // 
            // frmBeginGame
            // 
            this.AcceptButton = this.btCheck;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(493, 425);
            this.Controls.Add(this.grpMenueGame);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmBeginGame";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Guess Number Game";
            this.Load += new System.EventHandler(this.frmBeginGame_Load);
            this.Move += new System.EventHandler(this.frmBeginGame_Move);
            this.Resize += new System.EventHandler(this.frmBeginGame_Resize);
            this.grpMenueGame.ResumeLayout(false);
            this.grpMenueGame.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picImageTimer)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbWrong)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbRigth)).EndInit();
            this.gbCalclutaor.ResumeLayout(false);
            this.gbCalclutaor.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.erpExsistError)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox grpMenueGame;
        private System.Windows.Forms.PictureBox pbWrong;
        private System.Windows.Forms.PictureBox pbRigth;
        private System.Windows.Forms.Button btNext;
        private System.Windows.Forms.GroupBox gbCalclutaor;
        private System.Windows.Forms.Button btCheck;
        private System.Windows.Forms.TextBox tbUserAnswer;
        private System.Windows.Forms.Label lbGuessNumber;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label lbCounterNumberOfQuestaion;
        private System.Windows.Forms.Label lbNumberOfQuestaion;
        private System.Windows.Forms.Label lbCounterWrong;
        private System.Windows.Forms.Label lbCounterRigth;
        private System.Windows.Forms.Label lbHintDescriptipn;
        private System.Windows.Forms.Label lbHint;
        private System.Windows.Forms.Label lbCounterTimer;
        private System.Windows.Forms.PictureBox picImageTimer;
        private System.Windows.Forms.Timer tmrCounterTime;
        private System.Windows.Forms.ErrorProvider erpExsistError;
    }
}