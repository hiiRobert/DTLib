#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include "array.h"

namespace DTLib {

template <typename T>
class DynamicArray : public Array<T>
{
protected:
    int m_length;

    T *copy(T *array, int len, int newLen) {
        T *ret = new T[newLen];
        if (ret) {
            int size = len < newLen ? len : newLen;

            for (int i = 0; i < size; i++) {
                ret[i] = array[i];
            }
        }

        return ret;
    }


    void update(T *array, int len) {
        if (array) {
            T * temp = this->m_array;
            this->m_array = array;
            this->m_length = len;

            delete[] temp;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create dynamic array object.");
        }
    }

    void init(T *array, int length) {
        if (array) {
            this->m_array = array;
            this->m_length = length;
        } else {
             THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create dynamic array object.");
        }

    }

public:
    DynamicArray (int length) {
        this->m_array = new T[length];
        if (this->m_array) {
            this->m_length = length;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create dynamic array object.");
        }

    }

    DynamicArray(const DynamicArray<T> &obj) {
        init(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);
    }

    DynamicArray<T> &operator=(const DynamicArray<T> &obj) {
        if (this != &obj) {
            update(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);
        }
        return *this;
    }


    int length() const {
        return m_length;
    }

    void resize(int length) {
        if (length != m_length) {
            update(copy(this->m_array, m_length, length), length);
            T *array = new T[length];
        }
    }

    ~DynamicArray() {
        delete[] this->m_array;
    }


};

}

#endif // DYNAMICARRAY_H
