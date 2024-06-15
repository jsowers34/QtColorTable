/****************************************************************************/
/* BEGIN FILE HelpDialog.cpp                                                */
/****************************************************************************/
/* PURPOSE                                                                  */
/*      Provides a basic help class.                                        */
/****************************************************************************/
/* DESIGN NOTES                                                             */
/*                                                                          */
/****************************************************************************/
/* REVISION HISTORY                                                         */
/*                                                                          */
/*   Initial Code:                                                          */
/*      @author    jsowers           24MAY24                                */
/*                                                                          */
/*   Modifications:                                                         */
/*                                                                          */
/****************************************************************************/
/* INCLUDE FILES                                                            */
/*                                                                          */

#include "HelpDialog.h"


/**
* Default Constructor.
*/
HelpDialog::HelpDialog(QWidget *parent) : QDialog(parent), ui(new Ui::HelpDialogClass()) {
    ui->setupUi(this);
}

/**
* Default Destructor.
*/
HelpDialog::~HelpDialog() {
    delete ui;
}
