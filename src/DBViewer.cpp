#include "../include/DBViewer.hpp"

#include <wx/wx.h>
#include "wx/grid.h"
#include <sql.h>
#include <sqlext.h>
#include <dbfunctions.hpp>


DBViewer::DBViewer(const wxString& title, SQLHENV& hEnv, SQLHDBC& hDbc, SQLHSTMT& hStmt, bool isTestServer) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize)

{
	createControls();
	setupSizers();
	bindEvents();
};

void DBViewer::createControls() {
	m_topPanel = new wxPanel(this);

	// Table Panel
	m_tablePanel = new wxPanel(m_topPanel, wxID_ANY, wxDefaultPosition, wxSize(150,400));

	// Object list
	m_objListLabel = new wxStaticText(m_tablePanel, wxID_ANY, "Object tables:");
	wxArrayString objTables;
	// TODO: replace sample data with SELECT
	objTables.Add("Customers");
	objTables.Add("Employees");
	objTables.Add("Objects");
	m_objListBox = new wxListBox(m_tablePanel, wxID_ANY, wxDefaultPosition, wxSize(-1, 200), objTables);

	// Transaction list
	m_tranListLabel = new wxStaticText(m_tablePanel, wxID_ANY, "Transaction tables:");
	wxArrayString tranTables;
	// TODO: replace sample data with SELECT
	tranTables.Add("Invoices");
	tranTables.Add("Customer registrations");
	tranTables.Add("Employee transactions");
	m_tranListBox = new wxListBox(m_tablePanel, wxID_ANY, wxDefaultPosition, wxSize(-1, 200), tranTables);

	// Search Panel
	m_searchPanel = new wxPanel(m_topPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 40));
	m_searchPanel->SetBackgroundColour(wxColor(100, 0, 100)); // Purple

	// View Panel
	m_viewPanel = new wxPanel(m_topPanel, wxID_ANY, wxDefaultPosition, wxSize(300,300));
	m_viewPanel->SetBackgroundColour(wxColor(300, 200, 100)); // Green

	m_viewGrid = new wxGrid(m_viewPanel, wxID_ANY);
	m_viewGrid->CreateGrid(5,5);

	m_controlPanel = new wxPanel(m_topPanel, wxID_ANY, wxDefaultPosition, wxSize(100,300));
	m_controlPanel->SetBackgroundColour(wxColor(100, 300, 200));


}

void DBViewer::setupSizers() {

	// Border
	wxGridSizer* borderSizer = new wxGridSizer(1);

	// Top level layout
	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->Add(m_tablePanel, wxSizerFlags().Border(wxRIGHT, 10).Expand());
	m_topPanel->SetSizer(borderSizer);
	borderSizer->Add(topSizer, wxSizerFlags().Border(wxALL, 20).Expand().Proportion(1));

	// Mid level layout
	wxBoxSizer* midSizer = new wxBoxSizer(wxVERTICAL);
	midSizer->Add(m_searchPanel, wxSizerFlags().Expand());
	topSizer->Add(midSizer, wxSizerFlags().Expand().Proportion(1));

	// Low level layout
	wxSizer* lowSizer = new wxBoxSizer(wxHORIZONTAL);
	lowSizer->Add(m_viewPanel, wxSizerFlags().Expand().Proportion(1));
	lowSizer->Add(m_controlPanel, wxSizerFlags().Expand());
	midSizer->Add(lowSizer, wxSizerFlags().Expand().Proportion(1));

	// Table panel
	wxBoxSizer* tableSizer = new wxBoxSizer(wxVERTICAL);
	tableSizer->Add(m_objListLabel);
	tableSizer->Add(m_objListBox, wxSizerFlags().Expand().Proportion(1));
	tableSizer->Add(m_tranListLabel);
	tableSizer->Add(m_tranListBox, wxSizerFlags().Expand().Proportion(1));
	m_tablePanel->SetSizer(tableSizer);
	
	// View port
	wxBoxSizer* viewSizer = new wxBoxSizer(wxVERTICAL);
	viewSizer->Add(m_viewGrid, wxSizerFlags().Expand().Proportion(1));
	m_viewPanel->SetSizer(viewSizer);


	borderSizer->SetSizeHints(this);

}

void DBViewer::bindEvents() {

}