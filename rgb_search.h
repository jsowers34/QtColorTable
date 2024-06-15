//---------------------------------------------------------------------------
// BEGIN FILE  rgbsearch.h
//---------------------------------------------------------------------------
// PURPOSE
//   
//---------------------------------------------------------------------------
// DESIGN NOTES
// 
//---------------------------------------------------------------------------
// REVISION HISTORY
//   Initial code:    JL Sowers    08JUN24
//   Modifications:
//---------------------------------------------------------------------------
// DEFINES
//

#ifndef RGBSEARCH_H
#define RGBSEARCH_H

//---------------------------------------------------------------------------
// INCLUDE FILES
//

#pragma once

#include <QDialog>
#include  <QString>
#include "ui_rgb_search.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RGB_SearchClass; };
QT_END_NAMESPACE

class RGB_Search : public QDialog {
	Q_OBJECT

public:

	typedef struct search_rgb {
		int searchRed = 0;
		int searchGreen = 0;
		int searchBlue = 0;
	} RGB;

	RGB_Search(QWidget *parent = nullptr);
	~RGB_Search();

	int getBlueValue ();
	int getRedValue ();
	int getGreenValue ();


private:
	Ui::RGB_SearchClass *ui;
	RGB searchValues;          /**< String value holding the user's RGB input. */


public slots:
	void setRGB ();
};

#endif

