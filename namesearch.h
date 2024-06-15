//---------------------------------------------------------------------------
// BEGIN FILE  namesearch.h
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

#ifndef NAMESEARCH_H
#define NAMESEARCH_H

//---------------------------------------------------------------------------
// INCLUDE FILES
//

#pragma once

#include <QDialog>
#include <QString>
#include "ui_namesearch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NameSearchClass; };
QT_END_NAMESPACE

class NameSearch : public QDialog
{
	Q_OBJECT

public:
	NameSearch(QWidget *parent = nullptr);
	~NameSearch();
	QString getSearchName ();

private:
	Ui::NameSearchClass *ui;
	QString searchValue = "UNKNOWN";    /**< String value holding the user's color name input. */

public slots:
	void nameSearch ();
};

#endif

