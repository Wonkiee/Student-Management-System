#include "MainPage.h"

MainPage::MainPage(QDialog *parent): QDialog(parent){
 /* 
  intials = NULL; firstName = NULL; middleName = NULL; lastName = NULL;
  ENumber = NULL; idNumber = NULL; birthDate = NULL; email = NULL;
  HomeContactNum = NULL; mobilePhoneNum = NULL; homeTown = NULL; postalCode = NULL;
  addressLine_1 = NULL; addressLine_2 = NULL; addressLine_3 = NULL;
  errorMessege - NULL; batch = NULL; department = NULL; submit = NULL' 
  close - NULL;
*/
    
    //isDatabaseCreatedForSecondYear = true;
    //isDatabaseCreatedForThirdYear = true;
    //isDatabaseCreatedForFinalYear = true; 
    ui_insertDetails = new Ui_InsertDetails();
    if( !ui_insertDetails )
        return;
    ui_insertDetails -> setupUi(this);

		//QTabWidget
    tab = ui_insertDetails ->tabWidget;
    tab-> setCurrentIndex(0);
		close = ui_insertDetails -> close;

/////////////////////////////////Insert Student//////////////////////////////////
    initials = ui_insertDetails -> initial;
    //initials->setToolTip("test");
    firstName = ui_insertDetails -> first;
    middleName = ui_insertDetails -> middle;
    lastName = ui_insertDetails ->last;
    ENumber = ui_insertDetails -> eNum;
    idNumber = ui_insertDetails -> idNum;
    email = ui_insertDetails -> email;
    HomeContactNum = ui_insertDetails -> homeNum;
    mobilePhoneNum = ui_insertDetails -> mobileNum;
    homeTown = ui_insertDetails -> homeTown;
    postalCode = ui_insertDetails -> postalCode;
    addressLine_1 = ui_insertDetails -> addressLine1;
    addressLine_2 = ui_insertDetails -> addressLine2;
    addressLine_3 = ui_insertDetails -> addressLine3;
  
    batch = ui_insertDetails -> batch;
    birthDate = ui_insertDetails -> date;
    department = ui_insertDetails -> department;
    //QPushuch buttons
    submit = ui_insertDetails -> submit;

///////////////////////////////ScanData////////////////////////////////////// 


    scanFromDatabase = ui_insertDetails -> scanFromDatabase;
    
//////////////////////////////////2nd Year////////////////////////////////////
    
    //QLabels
    studentDetailSummary = ui_insertDetails -> studentDetailSummary;
		
		//	QTextEdit
		searchByENumbr = ui_insertDetails -> searchByENumber;   
		searchStudentByNme = ui_insertDetails -> searchStudentByName;
 
		//QPushButton
		searchByENumber_btn = ui_insertDetails -> searchByENumber_btn;
		searchByName_btn = ui_insertDetails -> searchByName_btn;

///////////////////////////////////////////////////////////////////////////////
    Register();
    names = new str_T[3];

    connect2Database("studentmgtsystem", "");
}

void MainPage::Register(){
  
    connect( close, SIGNAL( clicked() ), this, SLOT( onClose() ) );
    connect( submit, SIGNAL( clicked() ), this, SLOT( onSubmit() ) );
    connect( scanFromDatabase, SIGNAL( clicked() ), this, SLOT( onClickScanFromDatabase() ) );
		connect( searchByENumber_btn, SIGNAL( clicked() ), this, SLOT( onClickSearchStudentByENumber() ) );
		connect( searchByName_btn, SIGNAL( clicked() ), this, SLOT( onClickSearchStudentByName() ) );
}


bool MainPage::emptyFieldCheck(){

    if( lastName->text().isEmpty() || firstName->text().isEmpty() || ENumber->text().isEmpty() || idNumber->text().isEmpty() || email->text().isEmpty()
        || HomeContactNum->text().isEmpty() || mobilePhoneNum->text().isEmpty() || homeTown->text().isEmpty() || postalCode->text().isEmpty() || addressLine_1->text().isEmpty() || addressLine_2->text().isEmpty() || addressLine_3->text().isEmpty()){     
        QMessageBox::information( 
        this, 
        tr("Missing Fields"), 
        tr("Please fill the empty fields") );
        return false;
    }
    return true;
}

QSqlDatabase MainPage::connect2Database(QString dbName, QString conName, QString hostName, int port, QString userName, QString password){

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(hostName);
    db.setDatabaseName(dbName);
    db.setUserName(userName);
    db.setPort(port);
    db.setPassword(password);
    bool ok = db.open();
    
    if(db.open())
        qDebug() << "connected " << db.hostName();
    else
        qDebug()<<db.lastError();
    return db;
}


//retrieve data from main DB and store in local DBs
void MainPage::retrieveDataFromDatabase(){
    QSqlQuery query, tempQ;
    query.exec("SELECT name, enumber, batch FROM studentdata WHERE department='co'");
    
    while (query.next()) {
        QString name = query.value(0).toString();
        QString eNum = query.value(1).toString();
        QString batch = query.value(2).toString();
        QString dept = query.value(3).toString();

        QString e13 = "e13";
        QString e14 = "e14";
        QString e15 = "e15";

        if( batch == e13 ){
            
            tempQ.exec( "CREATE TABLE IF NOT EXISTS e13 (name VARCHAR(30), enumbr VARCHAR(7) PRIMARY KEY, batch VARCHAR(4), dept VARCHAR(4))" );
            //tempQ.exec();
            tempQ.prepare("INSERT INTO e13 (name, enumbr, batch, dept)" "VALUES (:name, :enumbr, :batch, :dept)");
            tempQ.bindValue(":name",name);
            tempQ.bindValue(":enumbr",eNum);
            tempQ.bindValue(":batch",batch);
            tempQ.bindValue(":dept",dept);
            tempQ.exec();

        }
        if( batch == e14 ){
            tempQ.prepare( "CREATE TABLE IF NOT EXISTS e14 (name VARCHAR(30), enumbr VARCHAR(7) PRIMARY KEY, batch VARCHAR(4), dept VARCHAR(4))" );
            tempQ.exec();
        }
        if( batch == e14 ){
            tempQ.prepare( "CREATE TABLE IF NOT EXISTS e15 (name VARCHAR(30), enumbr VARCHAR(7) PRIMARY KEY, batch VARCHAR(4), dept VARCHAR(4))" );
            tempQ.exec();
        }

        qDebug() << name << eNum << batch;
    
    }

}

void MainPage::storeFormDataIntoVariables(){
    

}

void MainPage::searchStudentByENumber(){
    QSqlQuery query;
    QString eNumber = searchByENumbr -> toPlainText();
    query.prepare("SELECT name, batch FROM e13 WHERE enumbr=:enum");
    query.bindValue(":enum",eNumber);
    query.exec();
    QString name, batch;
    while (query.next()) {
        name = query.value(0).toString();
        batch = query.value(1).toString();
    }

    studentDetailSummary -> setText(name+"\n"+batch);
    
}

//slots
void MainPage::onClickSearchStudentByENumber(){
    searchStudentByENumber();
}

void MainPage::searchStudentByName(){
    QSqlQuery query;
    QString name = searchStudentByNme -> toPlainText();
    query.prepare("SELECT enumbr, batch FROM e13 WHERE name=:name");
    query.bindValue(":name",name);
    query.exec();
    QString enumbr, batch;
    while (query.next()) {
        enumbr = query.value(0).toString();
        batch = query.value(1).toString();
    }

    if()
			studentDetailSummary -> setText("Student Not Found!");
    
}

//slots
void MainPage::onClickSearchStudentByName(){
    searchStudentByName();
}


void MainPage::onClickScanFromDatabase(){
    retrieveDataFromDatabase();
}

void MainPage::onSubmit(){
    if( emptyFieldCheck() ){
        storeFormDataIntoVariables();
    } 
}
void MainPage::onClose(){
  	hide();
  	exit(1);
}

