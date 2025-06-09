#include "../include/DBViewer.hpp"

#include <wx/wx.h>
#include "wx/grid.h"
#include <sql.h>
#include <sqlext.h>
#include <dbfunctions.hpp>


DBViewer::DBViewer(const wxString& title, SQLHENV& hEnv, SQLHDBC& hDbc, SQLHSTMT& hStmt, bool isTestServer) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize)

{
	// Execute SELECT
	std::wstring testSelect = L"SELECT [Device_Model_Name] as Model,[Device_Model_Type] as Type FROM [Device_Models]";
	int retcode = SQLExecDirect(hStmt, (wchar_t*)testSelect.c_str(), SQL_NTS);

	// Get number of columns and rows
	long long rowCount;
	SQLRowCount(hStmt, &rowCount);
	
	short columnCount;
	SQLNumResultCols(hStmt, &columnCount);

	// Get column names
	std::vector<std::wstring> colNames = dbfunctions::getAllResultColumnNames(hStmt);
	
	// Get table of results
	std::vector<std::vector<std::wstring>> tableData = dbfunctions::getResultTable(hStmt);


	// Building Frame
	wxPanel* panel = new wxPanel(this);
	wxGrid* grid = new wxGrid(panel, -1, wxPoint(0, 0), wxSize(400, 1000));
	grid->CreateGrid(rowCount, columnCount);
	grid->EnableEditing(false);
	grid->HideRowLabels();
	for (int i=0; i<columnCount;i++) {
		grid->SetColLabelValue(i, colNames[i]);
	}

	for (int i=0; i< columnCount; i++) {
		for (int j = 0; j<tableData.size(); j++) {
			grid->SetCellValue(j, i, tableData[j][i]);
		}
	}

	grid->AutoSize();

};