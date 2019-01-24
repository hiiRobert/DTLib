#ifndef ARRAY_H
#define ARRAY_H
#include "object.h"
#include "Exception.h"


namespace DTLib {

template <typename T>
class Array : Object
{
protected:
    T *m_array;
public:
    virtual bool set(int i, const T &e) {
        bool ret = (0 <= i) && (i < length());

        if (ret) {
            m_array[i] = e;
        }
        return ret;
    }
    virtual bool get(int i, T &e) const {
        bool ret = (0 <= i) && (i < length());

        if (ret) {
            e = m_array[i];
        }
        return ret;
    }

    T &operator[](int i) {
        bool ret = (0 <= i) && (i < length());
        if (ret) {
            return m_array[i];
        } else {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid.");
        }
        return ret;

    }
    T operator[](int i) const {
        return (const_cast<Array<T> &>(*this))[i];
    }

    virtual int length() const = 0;

};

}

#endif // ARRAY_H
