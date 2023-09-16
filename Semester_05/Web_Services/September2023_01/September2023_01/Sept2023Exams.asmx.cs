using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;

namespace September2023_01
{
    /// <summary>
    /// Summary description for Sept2023Exams
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class Sept2023Exams : System.Web.Services.WebService
    {

        [WebMethod]
        public string Zigos(int a)
        {
            if (a % 2 == 0)
                return "Ζυγός αριθμός";
            else
                return "Μονός αριθμός";
        }
    }
}
