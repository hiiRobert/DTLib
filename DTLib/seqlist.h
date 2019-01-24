#ifndef SEQLIST_H
#define SEQLIST_H
#include "list.h"
#include "Exception.h"

namespace DTLib {
using namespace std;
template <typename T>
class SeqList : public List<T> {
protected:
    T *m_array;
    int m_length;
public:
    bool insert(int i, const T &e) {
        bool ret = (0 <= i) && (i <= m_length);
        ret = ret && (m_length < capacity());
        if (ret) {
            for (int pos = m_length - 1; pos >= i; pos--) {
                m_array[pos+1] = m_array[pos];
            }
            m_array[i] = e;
            m_length++;
        }
        return ret;
    }


    int find(const T &e) const {
        int ret = -1;
        for (int i= 0; i < m_length; i++) {
            if (m_array[i] == e) {
                return i;
                break;
            }
        }

        return ret;
    }
    bool insert(const T &e) {
        return insert(m_length, e);
    }

    bool remove(int i) {
        bool ret = (0 <= i) && (i < m_length);
        if (ret) {
            for (int pos = i; pos < m_length - 1;pos++) {
                m_array[pos] = m_array[pos+1];
            }
            m_length--;
        }
        return ret;
    }

    bool set(int i, const T &e) {
        bool ret = (0 <= i) && (i < m_length);
        if (ret) {
            m_array[i] = e;
        }
        return ret;
    }

    bool get(int i, T &e) const {
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
        if ((0 <= i) && (i < m_length)) {
            return m_array[i];
        } else {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid.");
        }
    }
    T operator [](int i) const {
        return const_cast<SeqList<T> &>(*this)[i];
    }

    void print() {
        cout << "ADDRESS: " << this << " | ";
        for (int i = 0; i < m_length; i++) {
            if (i == m_length - 1) {
                cout << m_array[i];
            } else {
                cout << m_array[i] << ", ";
            }
        }
        cout << endl;
    }

    virtual int capacity() const = 0;


};

}

#endif // SEQLIST_H
