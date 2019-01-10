#include <QCoreApplication>
#include "SmartPointer.h"
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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test();

    return a.exec();
}
