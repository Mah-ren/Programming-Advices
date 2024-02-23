using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Guess_Number_Game
{
    public partial class frmQuestionsInfo : Form
    {
        public frmQuestionsInfo()
        {
            InitializeComponent();
        }



        struct stQuestionsInfo
        {
            public byte HowManyQuestions;
            public byte QuestionsLevel;
        };
        stQuestionsInfo QuestionsInfo;



        void SettingSizeForm()
        {

            this.Size = new Size(339, 439);

            int Width = (Screen.PrimaryScreen.Bounds.Width - this.Width) / 2;
            int Height = (Screen.PrimaryScreen.Bounds.Height - this.Height) / 2;

            this.Location = new Point(Width, Height);

        }

        private void frmQuestionsInfo_Move(object sender, EventArgs e)
        {
            SettingSizeForm();
        }

        private void frmQuestionsInfo_Resize(object sender, EventArgs e)
        {
            SettingSizeForm();
        }



        private void frmQuestionsInfo_Load(object sender, EventArgs e)
        {
            cbQuestionsLevel.SelectedIndex = 0;
        }

        private void cbQuestionsLevel_SelectedIndexChanged(object sender, EventArgs e)
        {
            //QuestionsInfo.QuestionsLevel = cbQuestionsLevel.Text == "Easy"? 0: cbQuestionsLevel.Text == "Medum"? 1: cbQuestionsLevel.Text == "Hard" ? 2: 3 ; 
            
            switch (cbQuestionsLevel.Text)
            {
                case "Easy":
                    QuestionsInfo.QuestionsLevel = 0;
                    break;

                case "Medum":
                    QuestionsInfo.QuestionsLevel = 1;
                    break;

                case "Hard":
                    QuestionsInfo.QuestionsLevel = 2;
                    break;

                case "Mix":
                    QuestionsInfo.QuestionsLevel = 3;
                    break;
            }          
        }

        private void btPlay_Click(object sender, EventArgs e)
        {
            QuestionsInfo.HowManyQuestions = Convert.ToByte(nrcHowManyQuestions.Value);

            frmBeginGame frm = new frmBeginGame(QuestionsInfo.HowManyQuestions, QuestionsInfo.QuestionsLevel);
            Hide();
            frm.Show();
        }


        

    }
}
