#include "MainPage.h"
int acedemicYearNow = 2019;
static QString host_Name, second_year, third_year, final_year;
static int tempACVal;


MainPage::MainPage(QString uN, QString pss,QDialog *parent): QDialog(parent){
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
    isChangeOccured  = false;
    USERNAME = uN;
    PASSWORD = pss;

    ui_insertDetails = new Ui_InsertDetails();
    if( !ui_insertDetails )
        return;
    ui_insertDetails -> setupUi(this);

		//QTabWidget
    tab = ui_insertDetails ->tabWidget;
    tab-> setCurrentIndex(0);
		close = ui_insertDetails -> close;
////////////////////////////////Search STudent //////////////////////////////////
    //QComboBox
    searchType = ui_insertDetails -> searchType;
    //QLIneEdit
    searchBy_name = ui_insertDetails -> searchByName;
    searchBy_eNum = ui_insertDetails -> searchByENum;
    //QPushButtons
    search = ui_insertDetails -> search;
    //QLabel
    detailsLabel = ui_insertDetails -> detailsLabel;

/////////////////////////////////Insert Student//////////////////////////////////
    initials = ui_insertDetails -> initial;
    //initials->setToolTip("test");
    firstName = ui_insertDetails -> first;
    middleName = ui_insertDetails -> middle;
    lastName = ui_insertDetails ->last;
    eNumber = ui_insertDetails -> eNum;
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
/////////////////////////////Settings/////////////////////////////////////////
    //QTextEdits
    hostName = ui_insertDetails -> hostName;
    secondYrBatch = ui_insertDetails -> secondYrBatch;
    thirdYrBatch = ui_insertDetails -> thirdYrBatch;
    finalYrBatch = ui_insertDetails -> finalYrBatch;
    //QLIneEdits
    setAcYear = ui_insertDetails -> setAcYear;
    secondYear_noOfStudents = ui_insertDetails -> secondYear__noOfStudents;
    secondYear = ui_insertDetails -> secondYear;

    //QPushButtons
    submitHostName = ui_insertDetails -> submitHostName;
    changeAcedemicYear = ui_insertDetails -> changeAcedemicYear;
    confirmAcedemicYear = ui_insertDetails -> confirmAcedemicYear;
    setAceYear = ui_insertDetails -> setAceYear;
    //QLabel
    acedemicYear = ui_insertDetails -> acedemicYear;


/////////////////////////////////////////////////////////////////////////////////////

    confirm = new Confirm(PASSWORD, USERNAME,NULL);
    second_year = "e15"; 
    third_year = "e14";
    final_year = "e13";
    
//////////////////////////////////////////////////////////////////////////////    
    names = new str_T[3];

    connect2Database("studentmgtsystem", "");
    createDatabaseForBasicDetails();
    Register();
    searchBy_eNum -> setDisabled(true);
}

//use for signals and slots
void MainPage::Register(){
  
    connect( close, SIGNAL( clicked() ), this, SLOT( onClose() ) );
    connect( submit, SIGNAL( clicked() ), this, SLOT( onSubmit() ) );
    connect( scanFromDatabase, SIGNAL( clicked() ), this, SLOT( onClickScanFromDatabase() ) );
	connect( searchByENumber_btn, SIGNAL( clicked() ), this, SLOT( onClickSearchStudentByENumber() ) );
	connect( searchByName_btn, SIGNAL( clicked() ), this, SLOT( onClickSearchStudentByName() ) );
    connect( search, SIGNAL( clicked() ), this, SLOT( onSearch() ) );
    connect( searchType, SIGNAL(currentIndexChanged(int)), this, SLOT( onIndexChange(int) ) );
    connect( submitHostName, SIGNAL( clicked() ), this, SLOT( onSubmitHostName() ) );
    connect( changeAcedemicYear, SIGNAL( clicked() ), this, SLOT( onChangeAcedemicYear() ) );
    connect( setAceYear, SIGNAL( clicked() ), this, SLOT( onSetAcedemicYear() ) );
    connect( confirmAcedemicYear, SIGNAL( clicked() ), this, SLOT( onConfirmBatch() ) );
}


////////////////////////////////////////////////Search Student///////////////////////////////////////////
void MainPage::search_Student(){
    detailsLabel -> clear();
    if( searchType -> currentText() == "Name" ){
        QString name = searchBy_name -> text(); 
        if(name.isEmpty()){
            errorMessegePopUp("Error", "Field is empty!");
            return;
        }
    }
    else if( searchType -> currentText() == "E Number" ){
        
        QString eNumb = searchBy_eNum -> text();
        if(eNumb.isEmpty()){
            errorMessegePopUp("Error", "Field is empty!");
            return;
        }
        
        QSqlQuery query;
        query.prepare("SELECT initials, first, middle, last, batch, enumber, idnumber, birthdate,email,department,contacthome,mobile,hometown,postalcode,address FROM basicdata WHERE enumber=:enum");
        query.bindValue(":enum",eNumb);
        query.exec();
        //if( !query.next() )
        //        detailsLabel -> setText("Record Not Found!");

        QString initial,first,middle,last,batch, enumber, idnumber, birthdate,email,department,contacthome,mobile,hometown,postalcode,address;
        while (query.next()) {

            //if( query.value(0).toString() == NULL ){
            //    detailsLabel -> setText("Record Not Found!");
            //    return;
            //}

            initial = query.value(0).toString();
            first = query.value(1).toString();
            middle = query.value(2).toString();
            last = query.value(3).toString();
            batch = query.value(4).toString();
            enumber = query.value(5).toString();
            idnumber = query.value(6).toString();
            birthdate = query.value(7).toString();
            email = query.value(8).toString();
            department = query.value(9).toString();
            contacthome = query.value(10).toString();
            mobile = query.value(11).toString();
            hometown = query.value(12).toString();
            postalcode = query.value(13).toString();
            address = query.value(14).toString();

        }
        //detailsLabel -> setText(initial+" "+first+" "+middle+" "+last+"\n");
        detailsLabel -> setText(initial+" "+first+" "+middle+" "+last+"\n"+batch+"\n"+enumber+"\n"+idnumber+"\n"+birthdate+"\n"+email+"\n"+department+"\n"+contacthome+"\n"+mobile+"\n"+hometown+"\n"+postalcode+"\n"+address);

    }
}

//////////////////////////////////////////////////////////////ADD Student Tab//////////////////////////////////////////////////////////
bool MainPage::emptyFieldCheck(){

    if( lastName->text().isEmpty() || firstName->text().isEmpty() || eNumber->text().isEmpty() || idNumber->text().isEmpty() || email->text().isEmpty()
        || HomeContactNum->text().isEmpty() || mobilePhoneNum->text().isEmpty() || homeTown->text().isEmpty() || postalCode->text().isEmpty() || addressLine_1->text().isEmpty() || addressLine_2->text().isEmpty() || addressLine_3->text().isEmpty()){     
        QMessageBox::information( 
        this, 
        tr("Missing Fields"), 
        tr("Please fill the empty fields") );
        return false;
    }
    return true;
}

void MainPage::storeFormDataIntoVariables(){
    QSqlQuery query;
    //query.exec( "CREATE TABLE IF NOT EXISTS basicdata ( initials VARCHAR(30), first VARCHAR(30), middle VARCHAR(30), last VARCHAR(30), batch VARCHAR(5), enumber VARCHAR(7), idnumber VARCHAR(13), birthdate VARCHAR(30), email VARCHAR(50), department VARCHAR(50), contacthome VARCHAR(12), mobile VARCHAR(12), hometown VARCHAR(15), postalcode VARCHAR(6), address VARCHAR(50))" );
    query.exec( "CREATE TABLE IF NOT EXISTS basicdata (initials VARCHAR(30), first VARCHAR(30), middle VARCHAR(30), last VARCHAR(30), batch VARCHAR(5), enumber VARCHAR(7), idnumber VARCHAR(13), birthdate VARCHAR(30), email VARCHAR(50),department VARCHAR(50), contacthome VARCHAR(12), mobile VARCHAR(12), hometown VARCHAR(15), postalcode VARCHAR(6),address VARCHAR(50))" );
    qDebug()<<query.lastError();
    query.prepare("INSERT INTO basicdata (initials, first, middle, last, batch, enumber, idnumber, birthdate,email,department,contacthome,mobile,hometown,postalcode,address)" "VALUES (:initials, :first, :middle, :last, :batch, :enumber, :idnumber, :birthdate,:email,:department,:contacthome,:mobile,:hometown,:postalcode,:address)");
    query.bindValue(":initials", initials->text());
    query.bindValue(":first", firstName->text());
    query.bindValue(":middle", middleName->text());
    query.bindValue(":last", lastName->text());
    query.bindValue(":batch", batch->currentText());
    query.bindValue(":enumber", eNumber->text());
    query.bindValue(":idnumber", idNumber->text());
    query.bindValue(":birthdate", birthDate->text());///////////////
    query.bindValue(":email", email->text());
    query.bindValue(":department", department->currentText() );////////////
    query.bindValue(":contacthome", HomeContactNum->text());
    query.bindValue(":mobile", mobilePhoneNum->text());
    query.bindValue(":hometown", homeTown->text());
    query.bindValue(":postalcode", postalCode->text());
    QString addr = addressLine_1 -> text() + "\n" + addressLine_2 -> text() + "\n" + addressLine_3 -> text();
    query.bindValue(":address", addr);
    query.exec();

}

/////////////////////////////////////////////////////////Scan Data Tab//////////////////////////////////////////////////////////////
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
            tempQ.prepare("INSERT INTO e14 (name, enumbr, batch, dept)" "VALUES (:name, :enumbr, :batch, :dept)");
            tempQ.bindValue(":name",name);
            tempQ.bindValue(":enumbr",eNum);
            tempQ.bindValue(":batch",batch);
            tempQ.bindValue(":dept",dept);
            tempQ.exec();
        }
        if( batch == e15 ){
            tempQ.prepare( "CREATE TABLE IF NOT EXISTS e15 (name VARCHAR(30), enumbr VARCHAR(7) PRIMARY KEY, batch VARCHAR(4), dept VARCHAR(4))" );
            tempQ.prepare("INSERT INTO e15 (name, enumbr, batch, dept)" "VALUES (:name, :enumbr, :batch, :dept)");
            tempQ.bindValue(":name",name);
            tempQ.bindValue(":enumbr",eNum);
            tempQ.bindValue(":batch",batch);
            tempQ.bindValue(":dept",dept);
            tempQ.exec();
        }

        qDebug() << name << eNum << batch;
    
    }

}

////////////////////////////////////////////////////////////////2nd Year Tab///////////////////////////////////////////////////////////////

void MainPage::searchStudentByENumber(){
    QSqlQuery query;
    QString eNumber = searchByENumbr -> toPlainText();
		
	if( eNumber == NULL ){
		errorMessegePopUp("Wrong ENumber", "Field is empty!");
		return;	
	}
	if( !validateENumber(eNumber) ){
		errorMessegePopUp("Wrong ENumber", "The E Number is wrong!");
		return;
	}
    query.prepare("SELECT name, batch FROM e13 WHERE enumbr=:enum");
    query.bindValue(":enum",eNumber);
    query.exec();
    QString name, batch;
    while (query.next()) {
        name = query.value(0).toString();
        batch = query.value(1).toString();
    }

    //if(query.isValid()){
		studentDetailSummary -> setText(name+"\n"+batch);
		return;		
	//}
    //else
		//studentDetailSummary -> setText("Student not found!");
    
    
}



void MainPage::searchStudentByName(){
    QSqlQuery query;
    QString name = searchStudentByNme -> toPlainText();

	if( name == NULL ){
		errorMessegePopUp("Error", "Field is empty!");
		return;	
	}

    query.prepare("SELECT enumbr, batch FROM e13 WHERE name=:name");
    query.bindValue(":name",name);
    query.exec();
	
	//bool isRecordFound = query.isValid();
    QString enumbr, batch;
    while (query.next()) {
        enumbr = query.value(0).toString();
        batch = query.value(1).toString();
    }

    //if(query.exec()){
		studentDetailSummary -> setText(enumbr+"\n"+batch);
		return;		
	//}
    //else
		//studentDetailSummary -> setText("Student not found!");
QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                "/home",
                                                tr("Images (*.png *.xpm *.jpg)"));
}

///////////////////////////////////////////////Settings//////////////////////////////////////////////////////////////////
void MainPage::createDatabaseForBasicDetails(){
    QSqlQuery query;

    query.exec( "CREATE TABLE IF NOT EXISTS basicdetails (acedemicYear INT(5), secondyr VARCHAR(4), thirdyr VARCHAR(4), finalyr VARCHAR(4))" );
    
    if( !checkRecordExistsInTable("basicdetails") || isChangeOccured == true){
        
            query.prepare("INSERT INTO basicdetails (acedemicYear, secondyr, thirdyr, finalyr)" "VALUES (:acYr, :secndYr, :thirdYr, :fnlYr)");
            query.bindValue(":acYr",acedemicYearNow);
            query.bindValue(":secndYr",second_year);
            query.bindValue(":thirdYr",third_year);
            query.bindValue(":fnlYr",final_year);
            query.exec();
            isChangeOccured = false;
    }else{
        query.exec("SELECT acedemicYear, secondyr, thirdyr, finalyr FROM basicdetails");
        QString sY,tY,fY,aY;

        while (query.next()) {
            aY = query.value(0).toString();
            sY = query.value(1).toString();     
            tY = query.value(2).toString();
            fY = query.value(3).toString();
        }
        acedemicYearNow = aY.toInt();
        second_year = sY;
        third_year = tY;
        final_year = fY;
        
    }
    updateFields();
}

void MainPage::updateFields(){
    acedemicYear -> setText( QString::number(acedemicYearNow) );

    QSqlQuery qry;
    qry.prepare("SELECT * FROM "+second_year);
    qry.exec();
    secondYear_noOfStudents -> setText( QString::number(qry.size()) ) ;
    secondYear -> setText(second_year);
}

void MainPage::ifBasicDetailsChaanged(){
    //QSqlQuery qry;
    //QString temp = "basicdetails";
    //qry.prepare("truncate "+temp);
    //qry.exec();
    //qDebug()<<qry.lastError();
    createDatabaseForBasicDetails();

    
}
bool MainPage::checkRecordExistsInTable(QString tableName){
    
    QSqlQuery qry;
    qry.prepare("SELECT * FROM "+tableName);
    qry.exec();
    qDebug()<<qry.size();
    if( qry.size() == 0 )
        return false;
    else
        return true;

}



///////////////////////////////////////////////Common Methods///////////////////////////////////////////////////////////////
bool MainPage::validateENumber(QString eNum){
    const char* ch = eNum.toStdString().c_str();    

    if( ch[0] != 'e' )
        return false;

    if( 0 < ((int)ch[1] - 48) && ((int)ch[1] - 48) < 10);
    else return false;

    if( 0 < ((int)ch[2] - 48) && ((int)ch[2] - 48) < 10 );
    else return false;

    quint32 offset = 3;
    QString after = eNum.mid(offset); 

    int num = after.toInt();    
    if( 0 < num && num <= 415 ) return true;
    else return false;

}

bool MainPage::validateBatch(QString batch){

    if(batch.length()>3)
        return false;

    if( batch.at(0) != 'e' )
        return false;

    stringstream strValue;
    strValue << qPrintable(batch.at(1));

    unsigned int intValue;
    strValue >> intValue;

    if( intValue < 0 || intValue > 10 )
        return false;

    strValue << qPrintable(batch.at(2));
    strValue >> intValue;    

    if( intValue < 0 || intValue > 10 )
        return false;


    return true;
}



//slots
void MainPage::onClickSearchStudentByName(){
    searchStudentByName();
}

void MainPage::onClickSearchStudentByENumber(){
    searchStudentByENumber();
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

void MainPage::onSearch(){
    search_Student();
}

void MainPage::errorMessegePopUp(QString title, QString errMsg){
	QMessageBox msgBox;
	msgBox.setText(errMsg);
	msgBox.setWindowTitle(title);
	msgBox.exec();
}

void MainPage::onIndexChange(int index){
    if(index == 0){
        searchBy_eNum -> setDisabled(true);
        searchBy_name -> setDisabled(false);
    }
    else if(index == 1){
        searchBy_name -> setDisabled(true);
        searchBy_eNum -> setDisabled(false);
    }

}

void MainPage::onSubmitHostName(){
    if(!ui_insertDetails)
        return;
    host_Name = hostName ->toPlainText();


}

void MainPage::onSetAcedemicYear(){

    QRegExp re("\\d*"); 

    if( setAcYear ->text().isEmpty() ){
        errorMessegePopUp("Error","Field is Empty!");
        return;
    }
    else if( !re.exactMatch(setAcYear->text() ) ){
        errorMessegePopUp("Error","Incorrect Entry");
        return;
    }

    QString acYr = setAcYear ->text();
    tempACVal = acedemicYearNow;
    acedemicYearNow = acYr.toInt();
    
    confirm -> show();
    confirm -> exec();

    if( confirm -> isDetailsCorrect() ){
        acedemicYear -> setText(acYr);
        isChangeOccured = true;
        ifBasicDetailsChaanged();
    }

}

void MainPage::onChangeAcedemicYear(){
    confirm -> show();
    confirm -> exec();
    qDebug()<<acedemicYearNow;
    if(confirm -> isDetailsCorrect()){
        acedemicYearNow = acedemicYearNow+1;
        tempACVal = acedemicYearNow-1;
        isChangeOccured = true;
        ifBasicDetailsChaanged();
        acedemicYear -> setText(QString::number(acedemicYearNow));
        
    }
}
void MainPage::onConfirmBatch(){

    if( validateBatch(secondYrBatch -> toPlainText()) && validateBatch( thirdYrBatch -> toPlainText() ) && validateBatch(  finalYrBatch -> toPlainText()) ){
        second_year = secondYrBatch -> toPlainText();
        third_year = thirdYrBatch -> toPlainText();
        final_year = finalYrBatch -> toPlainText();
        confirm -> show();
        confirm -> exec();
        isChangeOccured = true;
        ifBasicDetailsChaanged();
    }else{
        errorMessegePopUp("Error!", "Wrong Format!");
    }

}

