#include <QCoreApplication>
#include "SmartPointer.h"
#include "Exception.h"
#include <iostream>

using namespace std;
using namespace DTLib;

class Test {
public:
    Test() {
        cout << "Test()" << endl;
    }

    ~Test() {
        cout << "~Test()" << endl;

    }
};


void test() {
    SmartPointer<Test> sp = new Test();
    SmartPointer<Test> nsp;
    nsp = sp;
    cout << sp.isNull() << endl;
    cout << nsp.isNull() << endl;
}

void test_exception() {
    try {
        THROW_EXCEPTION(ArithmeticException, "test");
    } catch(const Exception &e) {
        cout << "catch exception here..." << endl;
        cout << e.message() << endl;
        cout << e.location()<< endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test_exception();

    return a.exec();
}
