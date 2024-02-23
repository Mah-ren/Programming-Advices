using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics.Eventing.Reader;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Tic_Tac_Toe.Properties;

namespace Tic_Tac_Toe
{
    public partial class Form1 : Form
    {
        enPlayer PlayerTurn = enPlayer.Player1;
        stGameStatus GameStatus;


        enum enPlayer
        {
            Player1,
            Player2,

        };

        enum enWinner
        {
            Player1,
            Player2,
            draw,
            InProgress
        };

        struct stGameStatus
        {
            public enWinner Winner;
            public bool GameOver;
            public short PlayCount;
        };



        public Form1()
        {
            InitializeComponent();
        }


        private void Form1_Paint(object sender, PaintEventArgs e)
        {

            Color Black = Color.FromArgb(255, 255, 255, 255);

            Pen Pen = new Pen(Black);
            Pen.Width = 20;

            // Pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dash;
            Pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            Pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            // draw horizental lines
            e.Graphics.DrawLine(Pen, 900, 300, 1550, 300);
            e.Graphics.DrawLine(Pen, 900, 460, 1550, 460);

            // draw vertical lines
            e.Graphics.DrawLine(Pen, 1110, 140, 1110, 620);
            e.Graphics.DrawLine(Pen, 1340, 140, 1340, 620);

        }


        private void label1_Click(object sender, EventArgs e)
        {

        }

        /*
         * ********************************************************************************
         * the same thing from Button1 - Button9
         * ********************************************************************************
         */

        private void button_Click(object sender, EventArgs e)
        {
            ChangeImage((Button)sender);
        }

        public void ChangeImage(Button button)
        {
            if (button.Tag.ToString() == "?")
            {
                switch (PlayerTurn)
                {
                    case enPlayer.Player1:   
                        button.Tag = "X";
                        button.Image = Resources.X;
                        PlayerTurn = enPlayer.Player2;
                        lblTurn.Text = "Player2";
                        break;
                    case enPlayer.Player2:
                        button.Tag = "O";
                        button.Image = Resources.O;
                        PlayerTurn = enPlayer.Player1;
                        lblTurn.Text = "Player1";
                        break;
                }
            }

            else
                MessageBox.Show("You can't click on it cause it's not a Question Mark", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            
            GameStatus.PlayCount++;
            CheckWinner();


            if (GameStatus.PlayCount == 9)
            {
                GameStatus.GameOver = true;
                GameStatus.Winner = enWinner.draw;
                EndGame();
            }
        }

        public void ResetButtons(Button button)
        {
            button.Image = Resources.questionMark;
            button.Tag = "?";
            button.BackColor = Color.Transparent;
        }

        void EndGame()
        {
            lblTurn.Text = "Game Over";

            switch (GameStatus.Winner)
            {
                case enWinner.Player1:
                    lblWinner.Text = "Player1";
                    break;
                case enWinner.Player2:
                    lblWinner.Text = "Player2";
                    break;
                default:
                    lblWinner.Text = "Draw";
                    break;
            };

            MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }


        public void RestartGame()
        {

            ResetButtons(bn1);
            ResetButtons(bn2);
            ResetButtons(bn3);

            ResetButtons(bn4);
            ResetButtons(bn5);
            ResetButtons(bn6);

            ResetButtons(bn7);
            ResetButtons(bn8);
            ResetButtons(bn9);


            PlayerTurn = enPlayer.Player1;
            lblTurn.Text = "Player1";

            lblWinner.Text = "In Progress";
            
            GameStatus.Winner= enWinner.InProgress;
            GameStatus.PlayCount = 0;
            GameStatus.GameOver = false;

        }


        private void lblTurn_Click(object sender, EventArgs e)
        {

        }


        public void CheckWinner()
        {
            // horizontal
            if (CheckValues(bn1, bn2, bn3))
                return;
            if (CheckValues(bn4, bn5, bn6))
                return;
            if (CheckValues(bn7, bn8, bn9))
                return;

            // vertical 
            if (CheckValues(bn1, bn4, bn7))
                return;
            if (CheckValues(bn2, bn5, bn8))
                return;
            if (CheckValues(bn3, bn6, bn9))
                return;

            // diagonal
            if (CheckValues(bn1, bn5, bn9))
                return;
            if (CheckValues(bn3, bn5, bn7))
                return;

        }

        public bool CheckValues(Button bn1, Button bn2, Button bn3)
        {
            if (bn1.Tag.ToString() != "?" && bn1.Text.ToString() == bn2.Text.ToString() && bn1.Text.ToString() == bn3.Text.ToString())
            {

                bn1.BackColor = Color.Cyan;
                bn2.BackColor = Color.Cyan;
                bn3.BackColor = Color.Cyan;


                if (bn1.Tag.ToString() == "X")
                    GameStatus.Winner = enWinner.Player1;

                else
                    GameStatus.Winner = enWinner.Player2;


                GameStatus.GameOver = true;
                EndGame();
                return true;
            }
            GameStatus.GameOver = false;
            return false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            RestartGame();
        }

        private void bn1_Click(object sender, EventArgs e)
        {

        }

    }
}
