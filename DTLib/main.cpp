#include <QCoreApplication>
#include "SmartPointer.h"
#include "Exception.h"
#include <iostream>
#include "object.h"
#include "list.h"
#include "dynamiclist.h"
#include "linklist.h"

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

void test_list()
{
//    DynamicList<int> l(20);
//    for (int i = 0; i < 10; i++) {
//        l.insert(i);
//    }
//    l.print();

}

class TestA
{
public:
    TestA() { throw 0;}
};

void test_link_list() {
    cout << "xxxxx...." << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    test_link_list();

    return a.exec();
}
