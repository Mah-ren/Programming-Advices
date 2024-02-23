using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CheckListBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Add_5_Items(object sender, EventArgs e)
        {
            for (short i = 0; i < 5; ++i)
            {
                checkedListBox1.Items.Add("Item"+ (i+1));
            }
        }

        //private void button3_Click(object sender, EventArgs e)
        //{

        //    for (short i = 0; i < checkedListBox1.CheckedItems.Count; ++i)
        //    {
        //        checkedListBox1.
        //    }
        //}

        private void ShowSelectedItems(object sender, EventArgs e)
        {
            for (short i = 0; i < checkedListBox1.CheckedItems.Count; ++i)
            {
                MessageBox.Show("this is Item " + checkedListBox1.CheckedItems[i].ToString());
            }
        }

        

        private void Check_UnCheck_All_Items(object sender, EventArgs e, bool enable)
        {
            for (short i = 0; i < checkedListBox1.Items.Count; ++i)
            {
                checkedListBox1.SetItemChecked(i, enable);
            }
        }
        private void CheckAllItems(object sender, EventArgs e)
        {
            Check_UnCheck_All_Items(sender, e, true);
        }
        private void UnCheckAllItems(object sender, EventArgs e)
        {
            Check_UnCheck_All_Items(sender, e, false);
        }

        private void Delete_the_first_Item(object sender, EventArgs e)
        {
            checkedListBox1.Items.RemoveAt(0);
        }
 
    }
}
