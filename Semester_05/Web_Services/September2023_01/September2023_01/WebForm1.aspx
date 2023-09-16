<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="September2023_01.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="Label1" runat="server" Font-Bold="True" Text="Αριθμός:"></asp:Label>
&nbsp;<asp:TextBox ID="Number" runat="server"></asp:TextBox>
            <br />
            <br />
            <asp:Button ID="btnZigos" runat="server" OnClick="btnZigos_Click" Text="Υπολογισμός" />
            <br />
            <br />
            <asp:Label ID="lblZigos" runat="server" Font-Bold="True" Visible="False"></asp:Label>
            <br />
            <br />
            <asp:DropDownList ID="lstCountryNames" runat="server" OnSelectedIndexChanged="lstCountryNames_SelectedIndexChanged" AutoPostBack="true">
            </asp:DropDownList>
            <br />
            <br />
            <asp:Label ID="Label2" runat="server" Font-Bold="True" Text="Κωδικός ISO:" Visible="False"></asp:Label>
&nbsp;<asp:Label ID="lblISO" runat="server" Visible="False"></asp:Label>
            <br />
            <br />
            <asp:Label ID="Label3" runat="server" Font-Bold="True" Text="Πρωτεύουσα:" Visible="False"></asp:Label>
&nbsp;<asp:Label ID="lblCapital" runat="server" Visible="False"></asp:Label>
        </div>
    </form>
</body>
</html>
