namespace Date_Time_Picker
{
    partial class MonthCalender
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
            this.monthCalendar1 = new System.Windows.Forms.MonthCalendar();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // monthCalendar1
            // 
            this.monthCalendar1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.monthCalendar1.Font = new System.Drawing.Font("Tahoma", 8F, System.Drawing.FontStyle.Bold);
            this.monthCalendar1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.monthCalendar1.Location = new System.Drawing.Point(240, 39);
            this.monthCalendar1.MaxDate = new System.DateTime(2024, 3, 31, 0, 0, 0, 0);
            this.monthCalendar1.MinDate = new System.DateTime(2024, 1, 20, 0, 0, 0, 0);
            this.monthCalendar1.Name = "monthCalendar1";
            this.monthCalendar1.TabIndex = 0;
            this.monthCalendar1.TitleBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.monthCalendar1.TitleForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.monthCalendar1.TrailingForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Elephant", 18F, System.Drawing.FontStyle.Bold);
            this.button1.Location = new System.Drawing.Point(12, 377);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(236, 61);
            this.button1.TabIndex = 1;
            this.button1.Text = "Select In Range";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.SelectInRange);
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("Elephant", 15F, System.Drawing.FontStyle.Bold);
            this.button2.Location = new System.Drawing.Point(291, 377);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(236, 61);
            this.button2.TabIndex = 2;
            this.button2.Text = "Start Date";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.StartDate);
            // 
            // button3
            // 
            this.button3.Font = new System.Drawing.Font("Elephant", 18F, System.Drawing.FontStyle.Bold);
            this.button3.Location = new System.Drawing.Point(570, 377);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(236, 61);
            this.button3.TabIndex = 3;
            this.button3.Text = "End Date";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.EndDate);
            // 
            // MonthCalender
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.CornflowerBlue;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.monthCalendar1);
            this.Name = "MonthCalender";
            this.Text = "Form2";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.MonthCalendar monthCalendar1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
    }
}