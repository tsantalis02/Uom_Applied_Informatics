using September2023_01.org.oorsprong.www;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace September2023_01
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        Sept2023Exams myWS = new Sept2023Exams();

        org.oorsprong.www.CountryInfoService fbWS = new org.oorsprong.www.CountryInfoService();    
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack == false)
            {
                // η λειτουργία επιστρέφει πίνακα string
                tCountryCodeAndName[] CountryTable = fbWS.ListOfCountryNamesByName();
                lstCountryNames.Items.Add("‐Επίλεξε Χώρα‐");
                for (int i = 0; i < CountryTable.Length; i++)

                    lstCountryNames.Items.Add(CountryTable[i].sName);
            }
        }

        protected void btnZigos_Click(object sender, EventArgs e)
        {
            int l;
            l = Convert.ToInt32(Number.Text);
            lblZigos.Text = myWS.Zigos(l);
            lblZigos.Visible = true;
        }

        protected void lstCountryNames_SelectedIndexChanged(object sender, EventArgs e)
        {
            tCountryCodeAndName[] Countries = fbWS.ListOfCountryNamesByName();
            int nr;
            nr = lstCountryNames.SelectedIndex;

            if (nr > 0)
            {
                nr = nr - 1;
                lblISO.Text = fbWS.CountryISOCode(Countries[nr].sName);
                lblCapital.Text = fbWS.CapitalCity(Countries[nr].sISOCode);
            }
            Label2.Visible = true;
            lblISO.Visible = true;
            Label3.Visible = true;
            lblCapital.Visible = true;
        }
    }
}