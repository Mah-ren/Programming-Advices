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
    public partial class frmWelcome : Form
    {
        public frmWelcome()
        {
            InitializeComponent();
        }



        private void lbPlay_Click(object sender, EventArgs e)
        {
            Form frm = new frmQuestionsInfo();
            Hide();
            frm.Show();
        }


        void SettingSizeForm()
        {

            this.Size = new Size(355, 433);

            int Width = (Screen.PrimaryScreen.Bounds.Width - this.Width) / 2;
            int Height = (Screen.PrimaryScreen.Bounds.Height - this.Height) / 2;

            this.Location = new Point(Width, Height);

        }

        private void frmWelcome_Move(object sender, EventArgs e)
        {
            SettingSizeForm();
        }

        private void frmWelcome_Resize(object sender, EventArgs e)
        {
            SettingSizeForm();
        }
     
    }
}
