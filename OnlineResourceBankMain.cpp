/***************************************************************
 * Name:      OnlineResourceBankMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Lewis J Hannah (lewis.j..hannah@gmail.com)
 * Created:   2024-11-21
 * Copyright: Lewis J Hannah ()
 * License:
 **************************************************************/

#include "OnlineResourceBankMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(OnlineResourceBankFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(OnlineResourceBankFrame)
const long OnlineResourceBankFrame::ID_STATICTEXT1 = wxNewId();
const long OnlineResourceBankFrame::ID_CHO_STATE = wxNewId();
const long OnlineResourceBankFrame::ID_STATICTEXT2 = wxNewId();
const long OnlineResourceBankFrame::ID_CHO_COUNTY = wxNewId();
const long OnlineResourceBankFrame::ID_STATICTEXT3 = wxNewId();
const long OnlineResourceBankFrame::ID_BUTTON_SEARCH = wxNewId();
const long OnlineResourceBankFrame::ID_BUTTONRESET = wxNewId();
const long OnlineResourceBankFrame::ID_BUTTONEDIT = wxNewId();
const long OnlineResourceBankFrame::ID_STATICTEXT4 = wxNewId();
const long OnlineResourceBankFrame::ID_CHO_TAX_AUTH = wxNewId();
const long OnlineResourceBankFrame::ID_CHO_TAX_TYPE = wxNewId();
const long OnlineResourceBankFrame::ID_STATICTEXT6 = wxNewId();
const long OnlineResourceBankFrame::ID_STATICTEXT7 = wxNewId();
const long OnlineResourceBankFrame::ID_STATICTEXT8 = wxNewId();
const long OnlineResourceBankFrame::ID_PANEL1 = wxNewId();
const long OnlineResourceBankFrame::idMenuQuit = wxNewId();
const long OnlineResourceBankFrame::idMenuAbout = wxNewId();
const long OnlineResourceBankFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(OnlineResourceBankFrame,wxFrame)
    //(*EventTable(OnlineResourceBankFrame)
    //*)
END_EVENT_TABLE()

OnlineResourceBankFrame::OnlineResourceBankFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(OnlineResourceBankFrame)
    wxGridBagSizer* GridBagSizer1;
    wxGridBagSizer* GridBagSizer2;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("Online Resource Bank"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(850,500));
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("State:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    choState = new wxChoice(this, ID_CHO_STATE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHO_STATE"));
    GridBagSizer1->Add(choState, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("County:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridBagSizer1->Add(StaticText2, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    choCounty = new wxChoice(this, ID_CHO_COUNTY, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHO_COUNTY"));
    GridBagSizer1->Add(choCounty, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Tax Auth:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    GridBagSizer1->Add(StaticText3, wxGBPosition(0, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnSearch = new wxButton(this, ID_BUTTON_SEARCH, _("SEARCH"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SEARCH"));
    GridBagSizer1->Add(btnSearch, wxGBPosition(0, 4), wxGBSpan(2, 1), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnReset = new wxButton(this, ID_BUTTONRESET, _("RESET"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONRESET"));
    GridBagSizer1->Add(btnReset, wxGBPosition(0, 5), wxGBSpan(2, 1), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnEdit = new wxButton(this, ID_BUTTONEDIT, _("EDIT"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONEDIT"));
    GridBagSizer1->Add(btnEdit, wxGBPosition(0, 6), wxGBSpan(2, 1), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Tax Type:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    GridBagSizer1->Add(StaticText4, wxGBPosition(0, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    chTaxAuth = new wxChoice(this, ID_CHO_TAX_AUTH, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHO_TAX_AUTH"));
    GridBagSizer1->Add(chTaxAuth, wxGBPosition(1, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    chTaxType = new wxChoice(this, ID_CHO_TAX_TYPE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHO_TAX_TYPE"));
    GridBagSizer1->Add(chTaxType, wxGBPosition(1, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    GridBagSizer2 = new wxGridBagSizer(0, 0);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("User"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    GridBagSizer2->Add(StaticText6, wxGBPosition(1, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    GridBagSizer2->Add(StaticText7, wxGBPosition(1, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("SEARCHABLE INDEXES"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    GridBagSizer2->Add(StaticText8, wxGBPosition(0, 0), wxGBSpan(1, 4), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(GridBagSizer2);
    GridBagSizer1->Add(Panel1, wxGBPosition(3, 0), wxGBSpan(1, 6), wxALL, 5);
    SetSizer(GridBagSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Layout();
    Center();

    Connect(ID_CHO_STATE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&OnlineResourceBankFrame::OnchoStateSelect);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OnlineResourceBankFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OnlineResourceBankFrame::OnAbout);
    //*)

    dao = new OrbDAO();
    FillStates();
}

OnlineResourceBankFrame::~OnlineResourceBankFrame()
{
    //(*Destroy(OnlineResourceBankFrame)
    //*)
}

void OnlineResourceBankFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void OnlineResourceBankFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void OnlineResourceBankFrame::FillStates()
{
    std::vector<std::string> states;
    states = dao->GetStates();

    // Populate the combo box
    for(const auto& state : states) {
        choState->Append(state);
    }
}

void OnlineResourceBankFrame::OnchoStateSelect(wxCommandEvent& event)
{
    std::vector<std::string> counties;
    counties = dao->GetCountiesByState(event.GetString().ToStdString());

    choCounty->Clear();
    for(const auto&county : counties) {
        choCounty->Append(county);
    }
}
