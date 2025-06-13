#pragma once

#include <wx/wx.h>
#include <sql.h>
#include <sqlext.h>

class DBViewer : public wxFrame
{
public:
	DBViewer(const wxString& title, SQLHENV& hEnv, SQLHDBC& hDbc, SQLHSTMT& hStmt, bool isTestServer);

private:
	void createControls();
	void setupSizers();
	void bindEvents();

	wxPanel* m_topPanel;
	wxPanel* m_tablePanel;
	wxPanel* m_searchPanel;
	wxPanel* m_viewPanel;
	wxPanel* m_controlPanel;
};

