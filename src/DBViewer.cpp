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
	m_topPanel->SetBackgroundColour(wxColor(0, 0, 0)); // Black

	m_tablePanel = new wxPanel(m_topPanel, wxID_ANY, wxDefaultPosition, wxSize(200,400));
	m_tablePanel->SetBackgroundColour(wxColor(100,100,100)); // Dark gray

	m_searchPanel = new wxPanel(m_topPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 40));
	m_searchPanel->SetBackgroundColour(wxColor(100, 0, 100)); // Purple

	m_viewPanel = new wxPanel(m_topPanel, wxID_ANY, wxDefaultPosition, wxSize(300,300));
	m_viewPanel->SetBackgroundColour(wxColor(300, 200, 100)); // Green

	m_controlPanel = new wxPanel(m_topPanel, wxID_ANY, wxDefaultPosition, wxSize(100,300));
	m_controlPanel->SetBackgroundColour(wxColor(100, 300, 200));


}

void DBViewer::setupSizers() {
	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->Add(m_tablePanel, wxSizerFlags().Expand());
	m_topPanel->SetSizer(topSizer);

	wxBoxSizer* midSizer = new wxBoxSizer(wxVERTICAL);
	midSizer->Add(m_searchPanel, wxSizerFlags().Expand());
	topSizer->Add(midSizer, wxSizerFlags().Expand().Proportion(1));

	wxSizer* lowSizer = new wxBoxSizer(wxHORIZONTAL);
	lowSizer->Add(m_viewPanel, wxSizerFlags().Expand().Proportion(1));
	lowSizer->Add(m_controlPanel, wxSizerFlags().Expand());
	midSizer->Add(lowSizer, wxSizerFlags().Expand().Proportion(1));

	topSizer->SetSizeHints(this);

}

void DBViewer::bindEvents() {

}