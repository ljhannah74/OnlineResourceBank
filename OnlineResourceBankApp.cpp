/***************************************************************
 * Name:      OnlineResourceBankApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Lewis J Hannah (lewis.j..hannah@gmail.com)
 * Created:   2024-11-21
 * Copyright: Lewis J Hannah ()
 * License:
 **************************************************************/

#include "OnlineResourceBankApp.h"

//(*AppHeaders
#include "OnlineResourceBankMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(OnlineResourceBankApp);

bool OnlineResourceBankApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        OnlineResourceBankFrame* Frame = new OnlineResourceBankFrame(0);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
