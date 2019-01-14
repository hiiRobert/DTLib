#ifndef SEQLIST_H
#define SEQLIST_H
#include "list.h"
#include "Exception.h"

namespace DTLib {

template <typename T>
class SeqList : public List<T> {
protected:
    T *m_array;
    int m_length;
public:
    bool insert(int i, const DTLib::T &e) {
        bool ret = (0 <= i) && (i <= m_length);
        ret = ret && (m_length < capacity());
        if (ret) {
            for (int pos = m_length - 1; p >= i; pos--) {
                m_array[pos+1] = m_array[p];
            }
            m_array[i] = e;
            m_length++;
        }
        return ret;
    }

    bool remove(int i) {
        bool ret = (0 <= i) && (i < m_length);
        if (ret) {
            for (int pos = i; pos < m_length - 1;p++) {
                m_array[pos] = m_array[p+1];
            }
            m_length--;
        }
        return ret;
    }

    bool set(int i, const DTLib::T &e) {
        bool ret = (0 <= i) && (i < m_length);
        if (ret) {
            m_array[i] = e;
        }
        return ret;
    }

    bool get(int i, DTLib::T &e) const {
        bool ret = (0 <= i) && (i < m_length);
        if (ret) {
            e = m_array[i];
        }
        return ret;
    }

    bool length() const {
        return m_length;
    }

    void clear() {
        m_length = 0;
    }

    T &operator[](int i) {
        if (0 <= i) && (i < m_length) {
            return m_array[i];
        } else {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid.");
        }
    }
    T operator [](int i) const {
        return const_cast<SeqList<T> &>(*this)[i];
    }
    virtual int capacity() const = 0;
};

}

#endif // SEQLIST_H
