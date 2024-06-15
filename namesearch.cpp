/****************************************************************************/
/* BEGIN FILE namesearch.cpp                                                */
/****************************************************************************/
/* PURPOSE                                                                  */
/*                                                                          */
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

#include "namesearch.h"
#include <QMessageBox>
#include <QChar>
#include <map>
#include <string>
#include "ColorTable.h"

/*                                                                          */
/****************************************************************************/
/* DEFINES                                                                  */
/*                                                                          */
/****************************************************************************/
/*                                                                          */

/**
* Default Constructor.
*/
NameSearch::NameSearch(QWidget *parent) : QDialog(parent), ui(new Ui::NameSearchClass()) {
	ui->setupUi(this);
	connect (ui->searchBtn, &QPushButton::clicked, this, &NameSearch::nameSearch);
	ui->nameTB->setFocus ();
}

/**
* Default Destructor.
*/
NameSearch::~NameSearch() {
	delete ui;
}

/**
* Callback method for Search button. Looks for a match (case-insensitive) to a Named Color.
* If found, the main display will be changed to that color.  If no match, then an Information
* dialog will be presented noting the non-match.
*/
void NameSearch::nameSearch () {
	QString listedName = "";
	QString enteredName = ui->nameTB->text ();
	searchValue = enteredName.toLower ().remove (QChar ('\0')).trimmed();
	ColorTable* ct = new ColorTable ();
	map<string, Color*> colorMap = ct->getColorMap ();
	map<string, Color*>::iterator it;
	it = colorMap.find ("Alaska Sky");
	while (it != colorMap.end ()) {
		listedName = QString::fromStdString (it->first);
		QString matchName = listedName.toLower ().trimmed();
		if (QString::compare(matchName,searchValue) == 0) {
			searchValue = listedName;
			this->accept ();
			return;
		}
		it++;
	}
	// No match - tell the user
	QMessageBox::information (this, "Name Search", "Search Name not in Named Color List", QMessageBox::Ok);
	this->reject ();
}

/**
* Accessor function to return the matched name.
*/
QString NameSearch::getSearchName () {
	return searchValue;
}