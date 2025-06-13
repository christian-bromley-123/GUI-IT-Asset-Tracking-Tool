#pragma once

#include <wx/wx.h>
#include "wx/grid.h"
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
	wxStaticText* m_objListLabel;
	wxListBox* m_objListBox;
	wxStaticText* m_tranListLabel;
	wxListBox* m_tranListBox;

	wxPanel* m_searchPanel;

	wxPanel* m_viewPanel;
	wxGrid* m_viewGrid;

	wxPanel* m_controlPanel;
};

