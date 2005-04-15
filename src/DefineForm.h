//---------------------------------------------------------------------------
// DefineForm.h
//
// A form for looking up and displaying word definitions.
//
// Copyright 2004, 2005 Michael W Thelen <mike@pietdepsi.com>.
//
// This file is part of Zyzzyva.
//
// Zyzzyva is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// Zyzzyva is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//---------------------------------------------------------------------------

#ifndef DEFINE_FORM_H
#define DEFINE_FORM_H

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qvgroupbox.h>

class DefinitionLabel;
class WordEngine;

class DefineForm : public QFrame
{
  Q_OBJECT
  public:
    DefineForm (WordEngine* e, QWidget* parent = 0, const char* name = 0,
                WFlags f = 0);

  public slots:
    void wordChanged (const QString& word);
    void defineWord();

  private:
    WordEngine*  engine;
    QLineEdit*   wordLine;
    QPushButton* defineButton;
    QVGroupBox*  resultBox;
    DefinitionLabel* resultLabel;
};

#endif // DEFINE_FORM_H
