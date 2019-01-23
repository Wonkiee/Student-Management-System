#include <iostream>
#include <string> 
#include <sstream>
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

//headrers
#include "ui_insertDetails.h"
#include "confirm.h"

using namespace std;
typedef char* str_T;

class MainPage: public QDialog{
Q_OBJECT  

public:
  	MainPage(QString un, QString pss,QDialog *parent = 0);

private:
  	/* variables */
  	Ui_InsertDetails *ui_insertDetails;
  	//Labels
  	QLabel *errorMessege, *secondYear_noOfStudents, *thirdYear_noOfStudents, *finalYear_noOfStudents, *secondYear, *thirdYear, *finalYear, *studentDetailSummary; 
  	QLabel *detailsLabel, *acedemicYear;
  	//LineEdits
  	QLineEdit *initials,*firstName,*middleName,*lastName;
  	QLineEdit *eNumber,*idNumber,*email;
  	QLineEdit *HomeContactNum,*mobilePhoneNum,*homeTown,*postalCode;
  	QLineEdit *addressLine_1,*addressLine_2,*addressLine_3;
   	QLineEdit *searchBy_eNum, *searchBy_name, *setAcYear;
    //QTextEdits
    QTextEdit *searchByENumbr,*searchStudentByNme, *hostName, *secondYrBatch, *thirdYrBatch, *finalYrBatch; 
  	//Date
  	QDateEdit *birthDate;
  	//Combo boxes
  	QComboBox *searchType,*batch,*department, *searchByENumber, *searchByName;
  	//push buttons
  	QPushButton *search,*submit,*close,*scanFromFile, *scanFromDatabase, *showStudentGradeReport, *searchByENumber_btn, *searchByName_btn;
  	QPushButton *searchStudent, *submitHostName, *changeAcedemicYear, *confirmAcedemicYear, *setAceYear;
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
	bool validateENumber(QString eNumber);
	bool validateBatch(QString batch);
	void errorMessegePopUp(QString title, QString errMsg);
	void search_Student();
	void createDatabaseForBasicDetails();
	bool checkRecordExistsInTable(QString tableName);
	void updateFields();
	void ifBasicDetailsChaanged();
    /*Data Storing Variables*/
    str_T *names;
    str_T btch,eNo,IDNo,bithDate,emailAddr,deptmnt;
    str_T homeContactNo,mobilePhone,hmeTown,postlCode;
    str_T *address;
    bool isChangeOccured;
    
    Confirm *confirm;
	QString PASSWORD,USERNAME;
private slots:
  	void onClose();
    void onSubmit();
    void onSearch();
    void onClickScanFromDatabase();
    void onClickSearchStudentByENumber();
	void onClickSearchStudentByName();
	void onIndexChange(int index);
	void onSubmitHostName();
	void onChangeAcedemicYear();
	void onSetAcedemicYear();
	void onConfirmBatch();
};
