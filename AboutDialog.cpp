/**--------------------------------------------------------------------------
* BEGIN FILE  AboutDialog.cpp
*---------------------------------------------------------------------------
* PURPOSE
*      Provides an appropriate 'brag' popup.
*---------------------------------------------------------------------------
* DESIGN NOTES
*
*---------------------------------------------------------------------------
* REVISION HISTORY
*   Initial code:    JL Sowers    04JUN24
*
*   Modifications:
*
*---------------------------------------------------------------------------
* INCLUDE FILES
*/

#include "AboutDialog.h"

/**--------------------------------------------------------------------------
* DEFINES
*          None
*---------------------------------------------------------------------------
*/ 



/**
* Default Constructor.
*/
AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AboutDialogClass()) {
    ui->setupUi(this);
}


/** 
* Default Destructor.
*/
AboutDialog::~AboutDialog() {
    delete ui;
}
