using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Date_Time_Picker
{
    public partial class MonthCalender : Form
    {
        public MonthCalender()
        {
            InitializeComponent();
        }
 
        private void SelectInRange(object sender, EventArgs e)
        {
            MessageBox.Show(monthCalendar1.SelectionRange.ToString());
        }

        private void StartDate(object sender, EventArgs e)
        {
            MessageBox.Show(monthCalendar1.SelectionStart.ToString());
        }

        private void EndDate(object sender, EventArgs e)
        {
            MessageBox.Show(monthCalendar1.SelectionEnd.ToString());
        }
    }
}
