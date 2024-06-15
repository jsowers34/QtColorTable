//---------------------------------------------------------------------------
// BEGIN FILE  AboutDialog.h
//---------------------------------------------------------------------------
// PURPOSE
//   A Qt-flavor popup About dialog.
//---------------------------------------------------------------------------
// DESIGN NOTES
//     Designed to be used as a template for when a help is needed.
//---------------------------------------------------------------------------
// REVISION HISTORY
//   Initial code:    JL Sowers    04JUN24
//   Modifications:
//---------------------------------------------------------------------------
// DEFINES
//

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

//---------------------------------------------------------------------------
// INCLUDE FILES
//
#pragma once

#include <QtWidgets/QDialog>
#include "ui_AboutDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AboutDialogClass; };
QT_END_NAMESPACE

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();

private:
    Ui::AboutDialogClass *ui;
};

#endif

