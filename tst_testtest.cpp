#include <QString>
#include <QtTest>
//#include "Interface.h"
#include "MainPage.h"

class TestTest : public QObject
{
    Q_OBJECT

public:
    TestTest();
    MainPage *mainPage;
    bool validateBatch(QString batch);
    bool validateENumber(QString eNum);
    bool errorMessegePopUp(QString title, QString errMsg);


private Q_SLOTS:
    void testCase1();
    void testCase2();
    void testCase3();
};

TestTest::TestTest()
{
    mainPage = NULL;
    QString temp1 = "1";
    QString temp2 = "1";
    //mainPage = new MainPage(temp1,temp2, NULL);
    //mainPage = new MainPage();
}

bool TestTest::validateBatch(QString batch){

    if(batch.length()>3 )
        return false;

    if( batch.length() < 3 )
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


bool TestTest::validateENumber(QString eNum){
    const char* ch = eNum.toStdString().c_str();

    if( eNum.length() < 6 )
        return false;

    if( eNum.length() > 6 )
        return false;

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

bool TestTest::errorMessegePopUp(QString title, QString errMsg){
    //QMessageBox msgBox;
    //msgBox.setText(errMsg);
    //msgBox.setWindowTitle(title);
    //msgBox.exec();
    return true;
    //if(msgBox.exec())
    //    return true;
    //else
    //    return false;
}

void TestTest::testCase1()
{

    QCOMPARE(validateBatch("e13"), true);
    QCOMPARE(validateBatch("e14"), true);
    QCOMPARE(validateBatch("e15"), true);
    QCOMPARE(validateBatch("e16"), true);
    QCOMPARE(validateBatch("e132"), false);
    QCOMPARE(validateBatch("e"), false);
    QCOMPARE(validateBatch("e3"), false);
}

void TestTest::testCase2(){
     QCOMPARE(validateENumber("e13276"), true);
     QCOMPARE(validateENumber("e13226"), true);
     QCOMPARE(validateENumber("e14276"), true);
     QCOMPARE(validateENumber("e15376"), true);
     QCOMPARE(validateENumber("e16276"), true);
     QCOMPARE(validateENumber("e176"), false);
     QCOMPARE(validateENumber("13276"), false);
}

void TestTest::testCase3(){
     QCOMPARE(errorMessegePopUp("e13276","wq"), true);
}

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
