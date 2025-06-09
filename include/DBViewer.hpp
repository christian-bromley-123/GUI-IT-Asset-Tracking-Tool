#pragma once

#include <wx/wx.h>
#include <sql.h>
#include <sqlext.h>

class DBViewer : public wxFrame
{
public:
	DBViewer(const wxString& title, SQLHENV& hEnv, SQLHDBC& hDbc, SQLHSTMT& hStmt, bool isTestServer);
};

