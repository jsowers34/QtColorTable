/****************************************************************************/
/* BEGIN FILE qtcolortable.cpp                                              */
/****************************************************************************/
/* PURPOSE                                                                  */
/*        Main code for ColorTable application                              */
/****************************************************************************/
/* DESIGN NOTES                                                             */
/*                                                                          */
/****************************************************************************/
/* REVISION HISTORY                                                         */
/*                                                                          */
/*   Initial Code:                                                          */
/*      @author    jsowers           26MAY24                                */
/*                                                                          */
/*   Modifications:                                                         */
/*                 jsowers           01JUN24   Added means to tie sliders   */
/****************************************************************************/
/* INCLUDE FILES                                                            */
/*                                                                          */

#include <iostream>
#include <QComboBox>
#include <QPushButton>
#include <QMenuBar>
#include <QDialog>
#include <QString>
#include <qcolor.h>
#include "qtcolortable.h"
#include "Color.h"
#include "ColorTable.h"
#include <cmath>
#include "HelpDialog.h"
#include "rgb_search.h"
#include "namesearch.h"
#include "hexsearch.h"

using namespace std;

/*                                                                          */
/****************************************************************************/
/* DEFINES                                                                  */
/*                                                                          */ 
/****************************************************************************/

/**
 * Default Constructor.
 *
 * @param parent a pointer to a QWidget.
 */
QtColorTable::QtColorTable (QWidget* parent) : QMainWindow (parent) {
	ui.setupUi (this);
	ui.redSlider->setStyleSheet ("QSlider::groove:horizontal {background-color:red;height:16px;}"
		"QSlider::handle:horizontal {background-color:black; height: 16px; width: 4px;}");
	ui.greenSlider_2->setStyleSheet ("QSlider::groove:horizontal {background-color:green;height:16px;}"
		"QSlider::handle:horizontal {background-color:black; height: 16px; width: 4px;}");
	ui.blueSlider_3->setStyleSheet ("QSlider::groove:horizontal {background-color:blue;height:16px;}"
		"QSlider::handle:horizontal {background-color:black; height: 16px; width: 4px;}");

	connect (ui.findBtn, &QPushButton::clicked, this, &QtColorTable::findClosestNamedColor);

	setSignals (true);

	createNameList ();
	loadComboBox ();
	ui.colorNameCB->setCurrentIndex (0);

	createActions ();
	createMenus ();

}

/**
 * Default Destructor.
 */
QtColorTable::~QtColorTable () {}

/**
 * Loads the combobox with the name list.
 */
void QtColorTable::loadComboBox () {
	ui.colorNameCB->addItems (nameList);
}

void QtColorTable::createNameList () {
	ColorTable* ct = new ColorTable ();
	ColorTable::NameMap localMap = ct->getNameMap ();
	for (auto& it : localMap) {
		QString name = QString::fromStdString(it.second);
		nameList.append (name);
	}
	nameList.sort ();
}

/**
 * Build all the menu choices relating the menu item to their action
 */
void QtColorTable::createMenus () {
	fileMenu = menuBar ()->addMenu (tr ("&File"));
	fileMenu->addAction (exitAct);

	findMenu = menuBar ()->addMenu (tr ("&Search"));
	findMenu->addAction (nameAct);
	findMenu->addAction (hexAct);
	findMenu->addAction (rgbAct);

	helpMenu = menuBar ()->addMenu (tr ("&Help"));
	helpMenu->addAction (aboutAct);
	helpMenu->addAction (helpAct);
}

/**
 * Localized method to create all of the Actions needed.
 */
void QtColorTable::createActions () {
	exitAct = new QAction (tr ("E&xit"), this);
	exitAct->setShortcuts (QKeySequence::Quit);
	exitAct->setStatusTip (tr ("Exit the application"));
	connect (exitAct, &QAction::triggered, this, &QWidget::close);

	nameAct = new QAction (tr ("&Name"), this);
	nameAct->setStatusTip (tr ("Search for a Name"));
	connect (nameAct, &QAction::triggered, this,  &QtColorTable::findByName);

	hexAct  = new QAction (tr ("&Hex"), this);
	hexAct->setStatusTip (tr ("Search using 6-character Hex code; e.g., FF0000"));
	connect (hexAct, &QAction::triggered, this,  &QtColorTable::findByHex);

	rgbAct  = new QAction (tr ("&RGB"), this);
	rgbAct->setStatusTip (tr ("Search using rgb values"));
	connect (rgbAct, &QAction::triggered, this,  &QtColorTable::findByRGB);


	aboutAct = new QAction (tr ("&About"), this);
	aboutAct->setStatusTip (tr ("Show the application's About box"));
	connect (aboutAct, &QAction::triggered, this, &QtColorTable::about);

	helpAct = new QAction (tr ("&Help"), this);
	helpAct->setStatusTip (tr ("Show the application's Help box"));
	connect (helpAct, &QAction::triggered, this, &QtColorTable::help);
}

/**
 * Display the brag box.
 * @brief MainWindow::about
 */
void QtColorTable::about () {
	AboutDialog* about = new AboutDialog (this);
	about->exec ();
}

/**
 * Display a rudimentary help file.
 * @brief MainWindow::help
 */
void QtColorTable::help () {
	HelpDialog* help = new HelpDialog (this);
	help->exec ();
}

/**
 * Convenience method.
 * Connects/Disconnects the sliders and the combobox.
 * @param tf : if true, signals are connected; if false, signals are disconnected.
 */
void QtColorTable::setSignals (bool tf) {
	if (tf) {
		connect (ui.colorNameCB, &QComboBox::currentTextChanged, this, &QtColorTable::processNamedColor);
		connect (ui.redSlider, &QSlider::sliderReleased, this, &QtColorTable::processSliders);
		connect (ui.greenSlider_2, &QSlider::sliderReleased, this, &QtColorTable::processSliders);
		connect (ui.blueSlider_3, &QSlider::sliderReleased, this, &QtColorTable::processSliders);
	} else {
		disconnect (ui.colorNameCB, &QComboBox::currentTextChanged, this, &QtColorTable::processNamedColor);
		disconnect (ui.redSlider, &QSlider::sliderReleased, this, &QtColorTable::processSliders);
		disconnect (ui.greenSlider_2, &QSlider::sliderReleased, this, &QtColorTable::processSliders);
		disconnect (ui.blueSlider_3, &QSlider::sliderReleased, this, &QtColorTable::processSliders);
	}
}

/**
 * Finds the closest named color to the current slider positions.
 * Expensive. Computes the sum of squared differences between the current positions and
 * every color. Saves the one with the smallest squared difference and sets the NameComboBox.
 */
void QtColorTable::findClosestNamedColor () {
	ColorTable* ct = new ColorTable ();
	ColorTable::NameMap localMap = ct->getNameMap ();
	int rval = ui.redSlider->value ();
	int gval = ui.greenSlider_2->value ();
	int bval = ui.blueSlider_3->value ();
	int colorValue = 256 * (256 * rval + gval) + bval;
	string hexval = Color::int2hex (colorValue);
	string closestName = "";
	int deltamin = INT_MAX;
	for (auto& it : localMap) {
		string namedHexval = it.first;
		int rnam = Color::getRedInt (namedHexval);
		int gnam = Color::getGreenInt (namedHexval);
		int bnam = Color::getBlueInt (namedHexval);
		int delta = pow (rnam - rval, 2) + pow (gnam - gval, 2) + pow (bnam - bval, 2);
		if (delta < deltamin) {
			deltamin = delta;
			closestName = it.second;
		}
	}
	ui.colorNameCB->setCurrentText (QString::fromStdString (closestName));
}

/**
* Pops up a dialog which allows entry of the 3 RGB decimal integers and sets the main display.
*/
void QtColorTable::findByRGB () {
	RGB_Search *search = new RGB_Search (this);
	int searchCode = search->exec ();
	if (searchCode == QDialog::Accepted) {
		int red = search->getRedValue ();
		int green = search->getGreenValue ();
		int blue = search->getBlueValue ();
		ui.redSlider->setValue (red);
		ui.greenSlider_2->setValue (green);
		ui.blueSlider_3->setValue (blue);
		processSliders ();
	}
	if (searchCode == QDialog::Rejected) {
		ui.redSlider->setValue (0);
		ui.greenSlider_2->setValue (0);
		ui.blueSlider_3->setValue (0);
	}
}

/**
* Pops up a dialog which allows entry of a 6-Char Hex color value and sets the main display.
*/
void QtColorTable::findByHex () {
	HexSearch* search = new HexSearch (this);
	int searchCode = search->exec ();
	if (searchCode == QDialog::Accepted) {
		QString hexvalue = search->getHexValue ();
		string hex = hexvalue.toStdString ();
		int red = Color::getRedInt (hex);
		int green = Color::getGreenInt (hex);
		int blue = Color::getBlueInt (hex);
		ui.redSlider->setValue (red);
		ui.greenSlider_2->setValue (green);
		ui.blueSlider_3->setValue (blue);
		processSliders ();
	}
	if (searchCode == QDialog::Rejected) {
		// Do nothing
	}
}

/**
* Pops up a dialog accepting a possible name of a color. If the color is found,
* it will display that color on the main display; if not found, then a message is
* displayed to that effect. Note, Case is not significant.
*/
void QtColorTable::findByName () {
	NameSearch* search = new NameSearch (this);
	int searchCode = search->exec ();
	if (searchCode == QDialog::Accepted) {
		QString foundName = search->getSearchName ();
		ui.colorNameCB->setCurrentText (foundName);
	}
	if (searchCode == QDialog::Rejected) {
		// Do Nothing!
	}
}


/**
 * Method that is connected to the Color Name combobox.
 * It extracts the 6-char HEX color value corresponding to the name
 * and sets the text below the color swatch as well as putting the
 * color as background to the swatch. Also sets the slider positions to
 * correspond to the color value.
 */
void QtColorTable::processNamedColor () {
	string name = ui.colorNameCB->currentText ().toStdString ();
	ColorTable* ct = new ColorTable ();
	string hexvalue;
	for (const auto& [key, value] : ct->getNameMap ())
		if (value == name)
			hexvalue = key;
	ui.hexValue->setText (QString::fromStdString (hexvalue));
	setAreaColor (hexvalue);

	// Sliders range from 0 to 255, so we need the int value of the appropriate hex
	currentRed = Color::getRedInt (hexvalue);
	currentGreen = Color::getGreenInt (hexvalue);
	currentBlue = Color::getBlueInt (hexvalue);
	ui.redSlider->setValue (currentRed);
	ui.greenSlider_2->setValue (currentGreen);
	ui.blueSlider_3->setValue (currentBlue);
	displayRGB (hexvalue);
}

/**
* Display the current value of the RGB on the screen.
* @param hexvalue   the RRGGBB HEX string.
*/
void QtColorTable::displayRGB (string hexvalue) {
	int currentRed = Color::getRedInt (hexvalue);
	int currentGreen = Color::getGreenInt (hexvalue);
	int currentBlue = Color::getBlueInt (hexvalue);
	string rgbstring = "RGB(";
	rgbstring.append (to_string (currentRed));
	rgbstring.append (",");
	rgbstring.append (to_string (currentGreen));
	rgbstring.append (",");
	rgbstring.append (to_string (currentBlue));
	rgbstring.append (")");
	ui.rgbvalue->setText (QString::fromStdString (rgbstring));
}

/**
 * Method connected to the Red/Green/Blue sliders.
 * Uses the slider positions to compute the 6-char HEX color value and
 * sets the text below the color swatch as well as putting the
 * color as background to the swatch.  Uses the settings of the Radio buttons
 * to determine if and how the sliders are tied together. Default is the sliders
 * are  independent. Also sets the slider positions to
 * correspond to the color value.  It then disconnects the signals so that
 * when it sets the combobox the corresponding method is not called. Then resets
 * the signals.
 */
void QtColorTable::processSliders () {
	int rval = ui.redSlider->value ();
	int gval = ui.greenSlider_2->value ();
	int bval = ui.blueSlider_3->value ();
	int deltaR = rval - currentRed;
	int deltaG = gval - currentGreen;
	int deltaB = bval - currentBlue;
	int inCtrl = whosInControl (deltaR, deltaG, deltaB);

	setSignals (false);

	if (ui.rb1->isChecked ()) {
		switch (inCtrl) {
			case 1:  // Red was moved, change bval and gval
				bval += deltaR;
				gval += deltaR;
				ui.blueSlider_3->setValue (bval);
				ui.greenSlider_2->setValue (gval);
				break;
			case 2:  // Green was moved
				rval += deltaG;
				bval += deltaG;
				ui.blueSlider_3->setValue (bval);
				ui.redSlider->setValue (rval);
				break;
			case 3:  // Blue done it.
				rval += deltaB;
				gval += deltaB;
				ui.redSlider->setValue (rval);
				ui.greenSlider_2->setValue (gval);
				break;
		}
	} else if (ui.rb2->isChecked ()) {
		// Red-Green Tied, Blue Independent
		switch (inCtrl) {
		case 1:   // Red moved, change green, let blue be were it is
			gval += deltaR;
			ui.greenSlider_2->setValue (gval);
			break;
		case 2:
			rval += deltaG;
			ui.redSlider->setValue (rval);
			break;
		case 3:
			break;
		}
	} else if (ui.rb3->isChecked ()) {
		// Red-Blue Tied, Green Independent
		switch (inCtrl) {
		case 1:   // Red moved, change blue, let green be were it is
			bval += deltaR;
			ui.blueSlider_3->setValue (bval);
			break;
		case 2:
			break;
		case 3:
			rval += deltaB;
			ui.redSlider->setValue (rval);
			break;
		}
	} else if (ui.rb4->isChecked ()) {
		// Green-Blue Tied, Red Independent
		switch (inCtrl) {
		case 1:   // Red moved, change green, let blue be were it is
			break;
		case 2:
			bval += deltaG;
			ui.blueSlider_3->setValue (bval);
			break;
		case 3:
			gval += deltaB;
			ui.greenSlider_2->setValue (gval);
			break;
		}
	}
	int colorValue = 256 * (256 * rval + gval) + bval;
	string hexval = Color::int2hex (colorValue);
	ui.hexValue->setText (QString::fromStdString (hexval));
	setAreaColor (hexval);
	displayRGB (hexval);

	string name = lookupName (hexval);
	ui.colorNameCB->setCurrentText (QString::fromStdString (name));
	setSignals (true);

	currentBlue = bval;
	currentRed = rval;
	currentGreen = gval;
}

/**
* Determines which slider the user has moved.
* @param dR   value of delta Red (red position - old red position)
* @param dG   value of delta Green
* @param dB   value of delta Blue
*/
int QtColorTable::whosInControl (int dR, int dG, int dB) {
	if (dR != 0) {
		return 1;
	} else if (dG != 0) {
		return 2;
	} else return 3;
}


/**
 * Looks up the name corresponding to the input value.
 *
 * @param hexval :  6 character HEX color value.
 * @return Name of corresponding color or, if the slider positions do not correspond
 * to a named value, returns "UNKNOWN".
 */
string QtColorTable::lookupName (string hexval) {
	ColorTable* ct = new ColorTable ();
	ColorTable::NameMap localMap = ct->getNameMap ();
	// Traverse the map
	for (auto& it : localMap) {
		string foist = it.first;
		if (0 == foist.compare (hexval)) {
			return(it.second);
		}
	}
	// If there is not key mapped with hexval,
	// then return unknown
	return "UNKNOWN";
}

/**
 * Sets the color swatch background color corresponding to the input value.
 * @param rrggbb : 6 character HEX color value.
 */
void QtColorTable::setAreaColor (string rrggbb) {
	QString str = QString::fromStdString ("background-color: #" + rrggbb + ";");
	ui.colorArea->setStyleSheet (str);
}
