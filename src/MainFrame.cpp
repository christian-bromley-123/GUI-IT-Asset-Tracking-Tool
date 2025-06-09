#include "../include/MainFrame.hpp"
#include "../include/DBViewer.hpp"

#include <wx/wx.h>
#include <sql.h>
#include <sqlext.h>
#include <dbfunctions.hpp>


MainFrame::MainFrame(const wxString& title, SQLHENV& hEnv, SQLHDBC& hDbc, SQLHSTMT& hStmt, bool isTestServer) 
	: wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {

	// Variables
	static char dbChoice = '1';

	// Window/Controls layout
	wxPanel* panel = new wxPanel(this);
	wxButton* connectButton = new wxButton(panel, wxID_ANY, "Connect", wxPoint(170, 45), wxSize(100, 25));
	wxStaticText* instructions = new wxStaticText(panel, wxID_ANY, "Which server would you like to connect to?", wxPoint(30, 15));

	// Set up server list
	wxArrayString choices;
	choices.Add("Test Server");
	choices.Add("Live Server");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(40, 45), wxSize(100, 30), choices);
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
			
			OnConnection(evt, hEnv, hDbc, hStmt, isTestServer);
			this->Close();
			
		}
	});
}

void MainFrame::OnConnection(wxCommandEvent& evt, SQLHENV& hEnv, SQLHDBC& hDbc, SQLHSTMT& hStmt, bool isTestServer) {
	wxString viewerTitle;
	if (isTestServer) {
		viewerTitle = "Test server";
	}

	else {
		viewerTitle = "Live Server";
	}

	//Get a table
	DBViewer* DBView = new DBViewer(viewerTitle, hEnv, hDbc, hStmt, isTestServer);
	DBView->SetClientSize(1000, 800);
	DBView->Center();
	DBView->Show();
}