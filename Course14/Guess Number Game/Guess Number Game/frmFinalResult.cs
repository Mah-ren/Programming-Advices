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
    public partial class frmFinalResult : Form
    {
       public frmFinalResult(byte HowManyQuestions, string QuestionsLevel, byte NumberOfRightAnswer, byte NumberOfWorngAnswer)
        {
            InitializeComponent();
     
            QuestionsInfo.HowManyQuestions = HowManyQuestions;
            QuestionsInfo.QuestionsLevel = QuestionsLevel;
            QuestionsInfo.NumberOfRightAnswer = NumberOfRightAnswer;
            QuestionsInfo.NumberOfWorngAnswer = NumberOfWorngAnswer;
    
        }



        struct stQuestionsInfo
        {
            public byte HowManyQuestions;
            public string QuestionsLevel;
            public byte NumberOfRightAnswer,
                         NumberOfWorngAnswer;
            public bool IsPass;
        };

        stQuestionsInfo QuestionsInfo;



        void SettingSizeForm()
        {

            this.Size = new Size(350, 419);

            int Width = (Screen.PrimaryScreen.Bounds.Width - this.Width) / 2;
            int Height = (Screen.PrimaryScreen.Bounds.Height - this.Height) / 2;

            this.Location = new Point(Width, Height);

        }

        private void frmFinalResult_Move(object sender, EventArgs e)
        {
            SettingSizeForm();
        }

        private void frmFinalResult_Resize(object sender, EventArgs e)
        {
            SettingSizeForm();
        }



        private void frmFinalResult_Load(object sender, EventArgs e)
        {
            FillGameResult();
        }



        void FillGameResult()
        {


            lbNumberOfQuestaions.Text = QuestionsInfo.HowManyQuestions.ToString();
            lbDescriptipnQuestionsLevel.Text = QuestionsInfo.QuestionsLevel;
            lbNumberOfRigthAnswer.Text = QuestionsInfo.NumberOfRightAnswer.ToString();
            lbNumberOfWrongAnswer.Text = QuestionsInfo.NumberOfWorngAnswer.ToString();

            CheckFinalResult();
        }

        void CheckFinalResult()
        {
            QuestionsInfo.IsPass = (QuestionsInfo.NumberOfRightAnswer >= QuestionsInfo.NumberOfWorngAnswer) ? true : false;
            ShowFinalResult();
        }

        void ShowFinalResult()
        {
            if (QuestionsInfo.IsPass)
            {
                lbDescriptionResult.Text = "Winner";
                lbDescriptionResult.ForeColor = Color.Green;
            }

            else
            {
                lbDescriptionResult.Text = "No Winner";
                lbDescriptionResult.ForeColor = Color.Red;
            }
        }



        private void btRestart_Click(object sender, EventArgs e)
        {
            frmQuestionsInfo frm = new frmQuestionsInfo();
            Hide();
            frm.Show();
        }
    
    }
}
