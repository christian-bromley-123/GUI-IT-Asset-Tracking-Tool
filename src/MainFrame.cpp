#include "../include/MainFrame.h"

#include <wx/wx.h>
#include <sql.h>
#include <sqlext.h>
#include <dbfunctions.hpp>

MainFrame::MainFrame(const wxString& title, SQLHENV& hEnv, SQLHDBC& hDbc, SQLHSTMT& hStmt, bool isTestServer) : wxFrame(nullptr, wxID_ANY, title) {

	// Variables
	static char dbChoice = '1';

	// Window/Controls layout
	wxPanel* panel = new wxPanel(this);
	wxButton* connectButton = new wxButton(panel, wxID_ANY, "Connect", wxPoint(170, 50), wxSize(100, 20));
	wxStaticText* instructions = new wxStaticText(panel, wxID_ANY, "Which server would you like to connect to?", wxPoint(30, 15));

	// Set up server list
	wxArrayString choices;
	choices.Add("Test Server");
	choices.Add("Live Server");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(40, 50), wxSize(100, 30), choices);
	choice->Select(0);

	// Binds
	
	choice->Bind(wxEVT_CHOICE, [=](wxCommandEvent evt){
		// Save the selection in 'choice' to a variable
		int dbGetChoice = 100;
			
		dbGetChoice = choice->GetSelection();

		if (dbGetChoice == 0)
		{
			dbChoice = '1';
		}

		if (dbGetChoice == 1)
		{
			dbChoice = '2';
		}

		});
		
	connectButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent& evt) {

		int connectDbRet = dbfunctions::connectDatabase(hEnv, hDbc, hStmt, dbChoice, isTestServer);
		
		if (connectDbRet == 0 || connectDbRet == 1) {
			if (dbChoice == '1') {
				wxLogStatus("Connected to test server");
			}

			if (dbChoice == '2') {
				wxLogStatus("Connected to live server");
			}
		}
		else {
			wxLogStatus("Connection failed");
		}
		});

	// Allows for checking the status of the window
	CreateStatusBar();
}
	