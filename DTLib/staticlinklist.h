#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H
#include "linklist.h"


namespace DTLib {


template <typename T, int N>
class StaticLinkList : public LinkList<T> {
protected:

    typedef typename LinkList<T>::Node Node;

    struct SNode : public Node
    {
        void *operator new(unsigned int size, void *loc) {
            // get rid of unused-warnings
            (void)size;
            return loc;
        }
    };


    unsigned char m_sapce[sizeof(SNode) * N];
    int m_used[N];

    Node *create() {
        SNode *ret = nullptr;

        for (int i = 0; i < N; i++) {
            if (!m_used[i]) {
                ret = reinterpret_cast<SNode *>(m_sapce) + i;
                ret = new(ret)SNode();
                m_used[i] = 1;
                break;
            }
        }

        return ret;
    }

    void destroy(Node *pn) {
        SNode *space = reinterpret_cast<SNode *>(m_sapce);
        SNode *psn = dynamic_cast<SNode *>(pn);
        for (int i = 0; i < N; i++) {
            if (pn == space + i) {
                m_used[i] = 0;
                pn->~SNode();
                break;
            }
        }
    }


public:
    StaticLinkList() {
        for (int i = 0; i < N; i++) {
            m_used[i] = 0;
        }
    }


    int capacity() {
        return N;
    }

    ~StaticLinkList() {
        this->clear();
    }

};

}

#endif // STATICLINKLIST_H
