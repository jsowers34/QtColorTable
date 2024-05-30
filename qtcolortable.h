/****************************************************************************/
/* BEGIN FILE qtcolortable.h                                                */
/*                                                                          */
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
/*      @author    jsowers           26MAY24                                */
/*                                                                          */
/*   Modifications:                                                         */
/*                                                                          */
/****************************************************************************/
/* INCLUDE FILES                                                            */
/*          
*/
#include <QtWidgets/QMainWindow>
#include <qstringlist.h>
#include <string>
#include "ui_qtcolortable.h"

/*                                                                          */
/****************************************************************************/
/* DEFINES                                                                  */
/*                                                                          */

#pragma once
using namespace std;

/****************************************************************************/
/*	 Begin Code                                                             */

class QtColorTable : public QMainWindow {
    Q_OBJECT

public:
    QtColorTable(QWidget *parent = nullptr);
    ~QtColorTable();

private:
    Ui::QtColorTableClass ui;
    void loadComboBox ();
    void loadNameList ();
    void setAreaColor (string rrggbb);
    void setSignals (bool tf);
    string lookupName (string hexval);

    QStringList nameList;


public slots:
    void processNamedColor ();
    void processSliders ();
    void findClosestNamedColor ();

};
