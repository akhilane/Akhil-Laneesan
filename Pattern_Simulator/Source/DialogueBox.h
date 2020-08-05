#pragma once


// DialogueBox

class DialogueBox : public CComboBox
{
	DECLARE_DYNAMIC(DialogueBox)

public:
	DialogueBox();
	virtual ~DialogueBox();

protected:
	DECLARE_MESSAGE_MAP()
};


