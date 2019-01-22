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
//headrers
#include "ui_insertDetails.h"

using namespace std;
typedef char* str_T;

class MainPage: public QDialog{
Q_OBJECT  

public:
  	MainPage(QDialog *parent = 0);

private:
  	/* variables */
  	Ui_InsertDetails *ui_insertDetails;
  	//Labels
  	QLabel *errorMessege, *secondYear__noOfStudents, *thirdYear__noOfStudents, *finalYear__noOfStudents, *secondYear, *thirdYear, *finalYear, *studentDetailSummary; 
  	//LineEdits
  	QLineEdit *initials,*firstName,*middleName,*lastName;
  	QLineEdit *ENumber,*idNumber,*email;
  	QLineEdit *HomeContactNum,*mobilePhoneNum,*homeTown,*postalCode;
  	QLineEdit *addressLine_1,*addressLine_2,*addressLine_3;
   
    //QTextEdits
    QTextEdit *searchByENumbr,*searchStudentByNme; 
  	//Date
  	QDateEdit *birthDate, *searchByENumber, *searchByName;
  	//Combo boxes
  	QComboBox *batch,*department;
  	//push buttons
  	QPushButton *submit,*close,*scanFromFile, *scanFromDatabase, *showStudentGradeReport, *searchByENumber_btn, *searchByName_btn;
  	//tabWidget
  	QTabWidget *tab;

  	/* functions */
  	void Register();
    bool emptyFieldCheck();
    void storeFormDataIntoVariables();
    QSqlDatabase connect2Database(QString dbName, QString conName, QString hostName = "localhost", int port=3306, QString userName = "root", QString password="");
    void retrieveDataFromDatabase();
    void searchStudentByENumber();
		void searchStudentByName();


    /*Data Storing Variables*/
    str_T *names;
    str_T btch,eNo,IDNo,bithDate,emailAddr,deptmnt;
    str_T homeContactNo,mobilePhone,hmeTown,postlCode;
    str_T *address;
    static bool isDatabaseCreatedForSecondYear;
    static bool isDatabaseCreatedForThirdYear;
    static bool isDatabaseCreatedForFinalYear;
		
private slots:
  	void onClose();
    void onSubmit();
    void onClickScanFromDatabase();
    void onClickSearchStudentByENumber();
		void onClickSearchStudentByName();
};
