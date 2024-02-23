using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Notify_Icon
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        private void btnShowNotification_Click(object sender, EventArgs e)
        {
            notifyIcon1.Icon = SystemIcons.Application;
            notifyIcon1.BalloonTipIcon = ToolTipIcon.Info;


            notifyIcon1.BalloonTipText = "صلى الله على محمد \"صلى الله عليه و سلم \"";
            notifyIcon1.BalloonTipTitle = "طيب قلبك بالصلاة على النبي";

            notifyIcon1.ShowBalloonTip (1000);

        }

        private void ShowNotificationClickWarning(object sender, EventArgs e)
        {
            // Display a warning message when the notification is clicked
            MessageBox.Show("You clicked on the notification", "Warning" );
        }

    }
}
