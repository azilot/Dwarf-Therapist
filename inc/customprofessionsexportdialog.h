/*
Dwarf Therapist
Copyright (c) 2009 Trey Stout (chmod)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#ifndef CUSTOM_PROFESSIONS_EXPORT_DIALOG
#define CUSTOM_PROFESSIONS_EXPORT_DIALOG

#include <QtGui>

namespace Ui {
	class CustomProfessionsExportDialog;
}
class CustomProfession;

class CustomProfessionsExportDialog : public QDialog {
	Q_OBJECT

public:
	CustomProfessionsExportDialog(QWidget *parent = 0);
	void setup_for_export();
	void setup_for_import();

	public slots:
		void accept();

private:
	Ui::CustomProfessionsExportDialog *ui;
	QVector<CustomProfession*> m_profs;
	QString m_path;

	typedef enum {
		MODE_IMPORT,
		MODE_EXPORT
	} DIALOG_MODE;

	DIALOG_MODE m_mode;

	QVector<CustomProfession*> get_profs();
	private slots:
		void select_all();
		void clear_selection();
		void export_selected();
		void import_selected();
	
};

#endif
