namespace Guess_Number_Game
{
    partial class frmQuestionsInfo
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
            this.btPlay = new System.Windows.Forms.Button();
            this.lbTitle = new System.Windows.Forms.Label();
            this.gbQuestionsInfo = new System.Windows.Forms.GroupBox();
            this.nrcHowManyQuestions = new System.Windows.Forms.NumericUpDown();
            this.lbQuestionsLevel = new System.Windows.Forms.Label();
            this.lbHowManyQuestions = new System.Windows.Forms.Label();
            this.cbQuestionsLevel = new System.Windows.Forms.ComboBox();
            this.gbQuestionsInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nrcHowManyQuestions)).BeginInit();
            this.SuspendLayout();
            // 
            // btPlay
            // 
            this.btPlay.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btPlay.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btPlay.Font = new System.Drawing.Font("Copperplate Gothic Light", 11.25F);
            this.btPlay.ForeColor = System.Drawing.Color.SeaGreen;
            this.btPlay.Location = new System.Drawing.Point(86, 346);
            this.btPlay.Name = "btPlay";
            this.btPlay.Size = new System.Drawing.Size(151, 26);
            this.btPlay.TabIndex = 3;
            this.btPlay.Text = "Play";
            this.btPlay.UseVisualStyleBackColor = true;
            this.btPlay.Click += new System.EventHandler(this.btPlay_Click);
            // 
            // lbTitle
            // 
            this.lbTitle.AutoSize = true;
            this.lbTitle.Font = new System.Drawing.Font("Copperplate Gothic Bold", 21.75F);
            this.lbTitle.ForeColor = System.Drawing.Color.SeaGreen;
            this.lbTitle.Location = new System.Drawing.Point(33, 50);
            this.lbTitle.Name = "lbTitle";
            this.lbTitle.Size = new System.Drawing.Size(260, 33);
            this.lbTitle.TabIndex = 0;
            this.lbTitle.Text = "Questions Info";
            // 
            // gbQuestionsInfo
            // 
            this.gbQuestionsInfo.Controls.Add(this.nrcHowManyQuestions);
            this.gbQuestionsInfo.Controls.Add(this.lbQuestionsLevel);
            this.gbQuestionsInfo.Controls.Add(this.lbHowManyQuestions);
            this.gbQuestionsInfo.Controls.Add(this.cbQuestionsLevel);
            this.gbQuestionsInfo.Location = new System.Drawing.Point(47, 125);
            this.gbQuestionsInfo.Name = "gbQuestionsInfo";
            this.gbQuestionsInfo.Size = new System.Drawing.Size(226, 178);
            this.gbQuestionsInfo.TabIndex = 0;
            this.gbQuestionsInfo.TabStop = false;
            // 
            // nrcHowManyQuestions
            // 
            this.nrcHowManyQuestions.Location = new System.Drawing.Point(53, 63);
            this.nrcHowManyQuestions.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.nrcHowManyQuestions.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nrcHowManyQuestions.Name = "nrcHowManyQuestions";
            this.nrcHowManyQuestions.Size = new System.Drawing.Size(120, 20);
            this.nrcHowManyQuestions.TabIndex = 1;
            this.nrcHowManyQuestions.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // lbQuestionsLevel
            // 
            this.lbQuestionsLevel.AutoSize = true;
            this.lbQuestionsLevel.Enabled = false;
            this.lbQuestionsLevel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbQuestionsLevel.ForeColor = System.Drawing.Color.LightSlateGray;
            this.lbQuestionsLevel.Location = new System.Drawing.Point(50, 107);
            this.lbQuestionsLevel.Name = "lbQuestionsLevel";
            this.lbQuestionsLevel.Size = new System.Drawing.Size(91, 13);
            this.lbQuestionsLevel.TabIndex = 0;
            this.lbQuestionsLevel.Text = "Questions Level ?";
            this.lbQuestionsLevel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lbHowManyQuestions
            // 
            this.lbHowManyQuestions.AutoSize = true;
            this.lbHowManyQuestions.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbHowManyQuestions.ForeColor = System.Drawing.Color.LightSlateGray;
            this.lbHowManyQuestions.Location = new System.Drawing.Point(50, 45);
            this.lbHowManyQuestions.Name = "lbHowManyQuestions";
            this.lbHowManyQuestions.Size = new System.Drawing.Size(116, 13);
            this.lbHowManyQuestions.TabIndex = 0;
            this.lbHowManyQuestions.Text = "How Many Questions ?";
            // 
            // cbQuestionsLevel
            // 
            this.cbQuestionsLevel.Cursor = System.Windows.Forms.Cursors.Hand;
            this.cbQuestionsLevel.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbQuestionsLevel.FormattingEnabled = true;
            this.cbQuestionsLevel.Items.AddRange(new object[] {
            "Easy",
            "Medum",
            "Hard",
            "Mix"});
            this.cbQuestionsLevel.Location = new System.Drawing.Point(53, 125);
            this.cbQuestionsLevel.Name = "cbQuestionsLevel";
            this.cbQuestionsLevel.Size = new System.Drawing.Size(121, 21);
            this.cbQuestionsLevel.TabIndex = 2;
            this.cbQuestionsLevel.SelectedIndexChanged += new System.EventHandler(this.cbQuestionsLevel_SelectedIndexChanged);
            // 
            // frmQuestionsInfo
            // 
            this.AcceptButton = this.btPlay;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(323, 400);
            this.Controls.Add(this.btPlay);
            this.Controls.Add(this.lbTitle);
            this.Controls.Add(this.gbQuestionsInfo);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmQuestionsInfo";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Guess Number Game";
            this.Load += new System.EventHandler(this.frmQuestionsInfo_Load);
            this.Move += new System.EventHandler(this.frmQuestionsInfo_Move);
            this.Resize += new System.EventHandler(this.frmQuestionsInfo_Resize);
            this.gbQuestionsInfo.ResumeLayout(false);
            this.gbQuestionsInfo.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nrcHowManyQuestions)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btPlay;
        private System.Windows.Forms.Label lbTitle;
        private System.Windows.Forms.GroupBox gbQuestionsInfo;
        private System.Windows.Forms.Label lbQuestionsLevel;
        private System.Windows.Forms.Label lbHowManyQuestions;
        private System.Windows.Forms.ComboBox cbQuestionsLevel;
        private System.Windows.Forms.NumericUpDown nrcHowManyQuestions;
    }
}

