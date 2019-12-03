

/* Lösung Aufgabe 8:
** MFC Dialog Application mttels MFC Wizzard erstellen
** In der Resourcenansicht zwei Textfelder und einen Button in den Dialog hinzufügen 
** Für die Textfelder je eine Variable hinzufügen
** Für den Button das Event OnBnClicked hinzufügen
** die gewünshcte Funktionalität in diese neue Funktion schreiben:
*/


void CMFCApplication3Dlg::OnBnClickedButton1()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	
	CString strText;
	myText1.GetWindowText(strText);
	
	myText2.SetWindowText(strText);

}
