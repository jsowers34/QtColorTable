/****************************************************************************/
/* BEGIN FILE hexsearch.cpp                                              */
/****************************************************************************/
/* PURPOSE                                                                  */
/*        Handles the 6-Char HEX search feature.                            */
/****************************************************************************/
/* DESIGN NOTES                                                             */
/*                                                                          */
/****************************************************************************/
/* REVISION HISTORY                                                         */
/*                                                                          */
/*   Initial Code:                                                          */
/*      @author    jsowers           08JUN24                                */
/*                                                                          */
/*   Modifications:                                                         */
/****************************************************************************/
/* INCLUDE FILES                                                            */
/*                                                                          */

#include "hexsearch.h"
#include <set>

/*                                                                          */
/****************************************************************************/
/* DEFINES                                                                  */
/*                                                                          */
/****************************************************************************/

/**
* Default Constructor.
*/
HexSearch::HexSearch(QWidget *parent) : QDialog(parent), ui(new Ui::HexSearchClass()) {
	ui->setupUi(this);
	ui->hexTB->setInputMask ("HHHHHH;_");
	ui->hexTB->setCursorPosition (0);
	ui->hexTB->setFocus ();
	typingTimer = new QTimer (this);
	typingTimer->setSingleShot (true);

	connect (ui->hexTB, &QLineEdit::textEdited, this, &HexSearch::textEntered);
	connect (ui->searchBtn, &QPushButton::clicked, this, &HexSearch::hexSearch);
}

/**
* Default Destructor.
*/
HexSearch::~HexSearch() {
	delete ui;
}

/**
* Callback function for Search Button.
* Converts input to uppercase.  If nothing was entered, it keeps
* the dialog up (need Close to remove it); if a hexstring was entered,
* it closes the dialog.
*/
void HexSearch::hexSearch () {
	hexValue = ui->hexTB->text ().toUpper();
	if (!hexValue.isEmpty()) {
		this->accept ();
		this->close ();
	}
}


/**
* Callback on user entering text into the Hex input box.  Since the
* callback is called for every key press, the timer puts in a brief delay 
* so that the user can enter more characters (aka all 6). Each keypress restarts
* the timer.
*/
void HexSearch::textEntered () {
	typingTimer->start (100);
	hexValue = ui->hexTB->text ().toUpper ();
}

/**
*  Access function. Returns result to caller.
*/
QString HexSearch::getHexValue () {
	return hexValue;
}