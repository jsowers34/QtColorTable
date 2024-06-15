/****************************************************************************/
/* BEGIN FILE rgbsearch.cpp                                                */
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

#include "rgb_search.h"

/*                                                                          */
/****************************************************************************/
/* DEFINES                                                                  */
/*                                                                          */
/****************************************************************************/
/*                                                                          */


/**
* Default Constructor.
*/
RGB_Search::RGB_Search(QWidget *parent ) : QDialog(parent), ui(new Ui::RGB_SearchClass()) {
	ui->setupUi(this);
	ui->redSpin->setMaximum (255);
	ui->greenSpin->setMaximum (255);
	ui->blueSpin->setMaximum (255);
	connect (ui->searchBtn, &QPushButton::clicked, this, &RGB_Search::setRGB);
}


/**
* Default Destructor.
*/
RGB_Search::~RGB_Search() {
	delete ui;
}

/**
* Callback method for Search Button.
* Saves RGB values.
*/
void RGB_Search::setRGB () {
	searchValues.searchRed = ui->redSpin->value ();
	searchValues.searchGreen = ui->greenSpin->value ();
	searchValues.searchBlue = ui->blueSpin->value ();
	this->accept ();
}

/**
* Accessor Function. 
* \return integer value of RED.
*/
int RGB_Search::getRedValue () {
	return searchValues.searchRed;
}

/**
* Accessor Function.
* \return integer value of BLUE.
*/
int RGB_Search::getBlueValue () {
	return searchValues.searchBlue;
}

/**
* Accessor Function.
* \return integer value of GREEN.
*/
int RGB_Search::getGreenValue () {
	return searchValues.searchGreen;
}