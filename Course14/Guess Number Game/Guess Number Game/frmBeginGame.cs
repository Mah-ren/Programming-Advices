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
    public partial class frmBeginGame : Form
    {
        public frmBeginGame(byte HowManyQuestions, byte QuestionsLevel)
        {
            InitializeComponent();

            QuestionsInfo.HowManyQuestions = HowManyQuestions;
            QuestionsInfo.QuestionsLevel = (enQuestionsLevel)QuestionsLevel;        
        }


        enum enQuestionsLevel
        {
            Easy = 0,
            Medum,
            Hard,
            Mix
        }

        
        struct stQuestion
        {
            public byte CorrectAnswer;
            public byte UserAnswer;
        };

        stQuestion Question;

        struct stQuestionsInfo
        {
            public byte HowManyQuestions;
            public enQuestionsLevel QuestionsLevel;
            public byte NumberOfRightAnswer,
                         NumberOfWorngAnswer;
        };  
        stQuestionsInfo QuestionsInfo;



        void SettingSizeForm()
        {

            this.Size = new Size(509, 464);

            int Width = (Screen.PrimaryScreen.Bounds.Width - this.Width) / 2;
            int Height = (Screen.PrimaryScreen.Bounds.Height - this.Height) / 2;

            this.Location = new Point(Width, Height);

        }

        private void frmBeginGame_Move(object sender, EventArgs e)
        {
            SettingSizeForm();
        }

        private void frmBeginGame_Resize(object sender, EventArgs e)
        {
            SettingSizeForm();
        }



        byte NumberOfQuestion = 1;

        private void frmBeginGame_Load(object sender, EventArgs e)
        {
            StartCounterTime();

            NumberOfQuestion = 1;
            QuestionsInfo.NumberOfWorngAnswer = QuestionsInfo.NumberOfRightAnswer = 0;

            Start();
        }



        void Start()
        {
            lbCounterNumberOfQuestaion.Text = NumberOfQuestion.ToString() + "/" + QuestionsInfo.HowManyQuestions.ToString();
            BeginQuestions();
        }

        void BeginQuestions()
        {

            GenerateQuestion(QuestionsInfo.QuestionsLevel);
            ShowQuestion();

        }



        void GenerateQuestion(enQuestionsLevel QuestionsLevel)
        {

            if (QuestionsLevel == enQuestionsLevel.Mix)
                QuestionsLevel = (enQuestionsLevel)GetRandomNumber(1, 3);


            Question.CorrectAnswer = (QuestionsLevel == enQuestionsLevel.Easy)? GetRandomNumber(1, 5) : (QuestionsLevel == enQuestionsLevel.Medum)? GetRandomNumber(1, 7) : GetRandomNumber(1, 10);
            GenerateHint();
        }

        Random Rand = new Random();

        byte GetRandomNumber(byte From, byte To)
        {
            return Convert.ToByte(Rand.Next(From, To));
        }



        void GenerateHint()
        {
            byte FirstNumber = Convert.ToByte(GetRandomNumber(1, 5));
            byte SecondNumber = Convert.ToByte(GetRandomNumber(1, 10));
            byte ThiredNumber = Convert.ToByte(GetRandomNumber(1, 7));

            lbHintDescriptipn.Text = " ? + " + FirstNumber.ToString() + " * " + SecondNumber.ToString() + " - " + ThiredNumber.ToString() + " = " + (Question.CorrectAnswer + FirstNumber * SecondNumber - ThiredNumber).ToString();
        }

        void ShowQuestion()
        {
            lbGuessNumber.Text = "Guess Number Between ";
            lbGuessNumber.Text += QuestionsInfo.QuestionsLevel == enQuestionsLevel.Easy ? "1 - 5" : QuestionsInfo.QuestionsLevel == enQuestionsLevel.Medum ? "1 - 7" : "1 - 10" ;
            lbGuessNumber.Text += " ? ";
        }



        sbyte CounterTime = 15;

        void GetTimeByLevel()
        {
            CounterTime = Convert.ToSByte(QuestionsInfo.QuestionsLevel == enQuestionsLevel.Easy ? 10 : QuestionsInfo.QuestionsLevel == enQuestionsLevel.Medum ? 20 : 30);
        }

        void StartCounterTime()
        {
            GetTimeByLevel();
            lbCounterTimer.Text = CounterTime.ToString();
            tmrCounterTime.Enabled = true;
        }

        private void tmrCounterTime_Tick(object sender, EventArgs e)
        {
            lbCounterTimer.Text = (CounterTime--).ToString();

            if (CounterTime == 0)
            {
                QuestionsInfo.NumberOfWorngAnswer++;
                lbCounterWrong.Text = QuestionsInfo.NumberOfWorngAnswer.ToString();
                tmrCounterTime.Enabled = false;


                if (MessageBox.Show("End Time, Rigth Answer is " + Question.CorrectAnswer.ToString(), "Sorry", MessageBoxButtons.OK, MessageBoxIcon.Error) == DialogResult.OK)
                {
                    btCheck.Enabled = false;
                    btNext.Enabled = true;
                    tbUserAnswer.Enabled = false;
                }
            }

        }



        private void btCheck_Click(object sender, EventArgs e)
        {
            GetUserAnswer();
        }



        void GetUserAnswer()
        {
            if (!(CheckIsEmpty() || CheckExsistLetters()))
            {
                tbUserAnswer.Enabled = false;
                tmrCounterTime.Enabled = false;
                CorrectTheQuestionAnswer();
            }
        }

        bool CheckExsistLetters()
        {
            if (ExsistLetters())
            {
                tbUserAnswer.Focus();
                erpExsistError.SetError(tbUserAnswer, "No Accept Letters\nOnly Numbers");
                return true;
            }

            erpExsistError.Clear();
            return false;

        }

        bool ExsistLetters()
        {
            return !(byte.TryParse(tbUserAnswer.Text, out Question.UserAnswer));
        }

        bool CheckIsEmpty()
        {
            if (string.IsNullOrWhiteSpace(tbUserAnswer.Text))
            {
                tbUserAnswer.Focus();
                erpExsistError.SetError(tbUserAnswer, "No Accept Empty\nEnter Value");
                return true;
            }

            erpExsistError.Clear();
            return false;

        }

        void CorrectTheQuestionAnswer()
        {
            if (Question.UserAnswer != Question.CorrectAnswer)
            {
                QuestionsInfo.NumberOfWorngAnswer++;
                lbCounterWrong.Text = QuestionsInfo.NumberOfWorngAnswer.ToString();

                MessageBox.Show("Rigth Guess is " + Question.CorrectAnswer.ToString(), "Wrong", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            else
            {
                QuestionsInfo.NumberOfRightAnswer++;
                lbCounterRigth.Text = QuestionsInfo.NumberOfRightAnswer.ToString();

                MessageBox.Show("Great.. Rigth Guess", "Rigth", MessageBoxButtons.OK, MessageBoxIcon.Information);

            }

            btCheck.Enabled = false;
            btNext.Enabled = true;
        }



        string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
        {
            string[] QuestionsLevel = { "Easy", "Medum", "Hard", "Mix" };

            return QuestionsLevel[Convert.ToByte(QuestionLevel)];
        }

        private void btNext_Click(object sender, EventArgs e)
        {
            StartCounterTime();

            NumberOfQuestion++;
            
            btNext.Enabled = false;
            btCheck.Enabled = tbUserAnswer.Enabled = true;
            tbUserAnswer.Clear();
            tbUserAnswer.Focus();
            erpExsistError.Clear();

            Start();


            if (NumberOfQuestion > QuestionsInfo.HowManyQuestions)
            {
                tmrCounterTime.Enabled = false;
                frmFinalResult frm = new frmFinalResult(QuestionsInfo.HowManyQuestions, GetQuestionLevelText(QuestionsInfo.QuestionsLevel), QuestionsInfo.NumberOfRightAnswer, QuestionsInfo.NumberOfWorngAnswer);
                Hide();
                frm.Show();
            }
        }

    }
}
