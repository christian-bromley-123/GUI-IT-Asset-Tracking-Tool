#pragma once
#include <wx/wx.h>
#include <sql.h>
#include <sqlext.h>
#include <DBFunctions.hpp>
#include <tests.hpp>


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, SQLHENV& hEnv, SQLHDBC& hDbc, SQLHSTMT& hStmt, bool isTestServer);
};

