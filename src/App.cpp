#include "../include/App.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {

	bool isTestServer = true;
	SQLHENV  hEnv = NULL;
	SQLHDBC  hDbc = NULL;
	SQLHSTMT hStmt = NULL;

	MainFrame* mainFrame = new MainFrame("Connect to server", hEnv, hDbc, hStmt, isTestServer);
	mainFrame->SetClientSize(300, 100);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}

