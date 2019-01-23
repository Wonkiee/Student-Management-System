#include <iostream>
#include <string>
//QT libraries
#include <QDialog>
#include <QtGui>
#include <QMessageBox>
#include <QToolTip>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QFileDialog>

//headers
#include "ui_confirm.h"

class Confirm: public QDialog{
Q_OBJECT  

public:
  	Confirm(QString, QString, QDialog *parent = 0);

private:
	
	Ui_Confirm *ui_confirm;
	QString USERNAME,PASSWORD;
	QLineEdit *userName, *password;
	QPushButton *confirm;
	QLabel *details;
	
	void Register();
public:
	bool isDetailsCorrect();

private slots:
	void onClickConfirm();
};