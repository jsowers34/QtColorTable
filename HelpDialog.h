/****************************************************************************/
/* BEGIN FILE  HelpDialog.h                                                 */
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
/*      @author    jsowers              24MAY24                             */
/*                                                                          */
/*   Modifications:                                                         */
/*                                                                          */
/****************************************************************************/
/* SAFETY DEFINITION                                                        */
/*                                                                          */

#ifndef HELPDIALOG_H
#define HELPDIALOG_H

/****************************************************************************/
/* INCLUDE FILES                                                            */
/*                                                                          */

#pragma once

#include <QtWidgets/QDialog>
#include "ui_HelpDialog.h"

/****************************************************************************/
/*	 Begin Code                                                             */

QT_BEGIN_NAMESPACE
    namespace Ui { class HelpDialogClass; };
QT_END_NAMESPACE

class HelpDialog : public QDialog {
    Q_OBJECT

public:
    HelpDialog(QWidget *parent = nullptr);
    ~HelpDialog();

private:
    Ui::HelpDialogClass *ui;
};

#endif