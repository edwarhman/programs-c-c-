#ifndef NEWDIALOG_H
#define NEWDIALOG_H

//(*Headers(NewDialog)
#include <wx/dialog.h>
//*)

class NewDialog: public wxDialog
{
	public:

		NewDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~NewDialog();

		//(*Declarations(NewDialog)
		//*)

	protected:

		//(*Identifiers(NewDialog)
		//*)

	private:

		//(*Handlers(NewDialog)
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
