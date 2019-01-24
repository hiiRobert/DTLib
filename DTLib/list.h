#ifndef LIST_H
#define LIST_H
#include "object.h"

namespace DTLib {

template <typename T>
class List : public Object {
protected: // 禁用容器的拷贝和复制
    List(const List &l);
    List &operator=(const List &l);
public:
    virtual bool insert(const T &e) = 0;
    virtual bool insert(int i, const T &e) = 0;
    virtual bool remove(int i) = 0;
    virtual bool set(int i, const T &e) = 0;
    virtual bool get(int i, T &e) const = 0;
    virtual int length() const = 0;
    virtual void clear() = 0;

    virtual int find(const T& e) const = 0;
//    virtual void print() = 0;
};

}

#endif // LIST_H
