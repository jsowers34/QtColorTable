//---------------------------------------------------------------------------
// BEGIN FILE  hexsearch.h
//---------------------------------------------------------------------------
// PURPOSE
//   
//---------------------------------------------------------------------------
// DESIGN NOTES
//     Uses a QLineEdit mask to restrict to a 6-char hex value.
//---------------------------------------------------------------------------
// REVISION HISTORY
//   Initial code:    JL Sowers    08JUN24
//   Modifications:
//---------------------------------------------------------------------------
// DEFINES
//

#ifndef HEXSEARCH_H
#define HEXSEARCH_H

//---------------------------------------------------------------------------
// INCLUDE FILES
//
#pragma once

#include <QDialog>
#include <QTimer>
#include <QString>
#include <QLineEdit>
#include <set>
#include "ui_hexsearch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HexSearchClass; };
QT_END_NAMESPACE

class HexSearch : public QDialog {
	Q_OBJECT

public:
	HexSearch(QWidget *parent = nullptr);
	~HexSearch();
	QString getHexValue ();

private:
	Ui::HexSearchClass *ui;
	QString hexValue = NULL;       /**< String value holding the user's hex code input. */
	QTimer *typingTimer;           /**< Pointer to the Timer which controls the user input stream. */


public slots:
	void hexSearch ();
	void textEntered ();
};

#endif

