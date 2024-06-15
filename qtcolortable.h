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
#include <qmenu.h>
#include <qstringlist.h>
#include <string>
#include "ui_qtcolortable.h"
#include "AboutDialog.h"
#include "rgb_search.h"

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
    void setAreaColor (string rrggbb);
    void setSignals (bool tf);
    string lookupName (string hexval);
    int whosInControl (int dR, int dG, int dB);
    void displayRGB (string hexvalue);
    void createMenus ();
    void createActions ();

    void createNameList ();   // TODO possibly replacement for loadNameList


    QStringList nameList;
    QMenu* fileMenu;
    QMenu* findMenu;
    QMenu* helpMenu;
    QAction* exitAct;
    QAction* aboutAct;
    QAction* helpAct;
    QAction* rgbAct;
    QAction* nameAct;
    QAction* hexAct;

    int currentRed = 0;
    int currentBlue = 0;
    int currentGreen = 0;

    QString searchName;          /**< String value holding the color name selected from the combobox. */

    RGB_Search::RGB searchRGB;

public slots:
    void processNamedColor ();
    void processSliders ();
    void findClosestNamedColor ();
    void about ();
    void help ();
    void findByRGB ();
    void findByName ();
    void findByHex ();

};
