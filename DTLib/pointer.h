#ifndef POINTER_H
#define POINTER_H

#include "object.h"

namespace DTLib {

template <typename T>
class Pointer : public Object {

protected:
    T *m_pointer;
public:
    Pointer(T *p = nullptr) {
        m_pointer = p;
    }

    T *operator->() {
        return m_pointer;
    }

    T &operator*() {
        return *m_pointer;
    }

    bool isNull() {
        return m_pointer == nullptr;
    }

    T *get() {
        return m_pointer;
    }
};

}

#endif // POINTER_H
