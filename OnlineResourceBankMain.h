/***************************************************************
 * Name:      OnlineResourceBankMain.h
 * Purpose:   Defines Application Frame
 * Author:    Lewis J Hannah (lewis.j..hannah@gmail.com)
 * Created:   2024-11-21
 * Copyright: Lewis J Hannah ()
 * License:
 **************************************************************/

#ifndef ONLINERESOURCEBANKMAIN_H
#define ONLINERESOURCEBANKMAIN_H

//(*Headers(OnlineResourceBankFrame)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/gbsizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)

#include "OrbDAO.h"

class OnlineResourceBankFrame: public wxFrame
{
    public:

        OnlineResourceBankFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~OnlineResourceBankFrame();
        void FillStates();

    private:

        OrbDAO* dao;

        //(*Handlers(OnlineResourceBankFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnchoStateSelect(wxCommandEvent& event);
        //*)

        //(*Identifiers(OnlineResourceBankFrame)
        static const long ID_STATICTEXT1;
        static const long ID_CHO_STATE;
        static const long ID_STATICTEXT2;
        static const long ID_CHO_COUNTY;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTON_SEARCH;
        static const long ID_BUTTONRESET;
        static const long ID_BUTTONEDIT;
        static const long ID_STATICTEXT4;
        static const long ID_CHO_TAX_AUTH;
        static const long ID_CHO_TAX_TYPE;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(OnlineResourceBankFrame)
        wxButton* btnEdit;
        wxButton* btnReset;
        wxButton* btnSearch;
        wxChoice* chTaxAuth;
        wxChoice* chTaxType;
        wxChoice* choCounty;
        wxChoice* choState;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ONLINERESOURCEBANKMAIN_H
