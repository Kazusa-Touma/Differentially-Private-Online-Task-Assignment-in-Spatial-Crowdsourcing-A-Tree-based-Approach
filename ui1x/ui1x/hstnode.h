#ifndef HSTNODE_H
#define HSTNODE_H
#include <point.h>
#include <qvector.h>
#include <qdebug.h>

class HSTnode
{
public:
    QVector <point> v;
    int size;
    int level;
    HSTnode* father;
    QVector <HSTnode*> son;
    static int c;

    HSTnode() {
        father = NULL;
        size = 0;
    }
    HSTnode(QVector <point> vec) {
        for(int i = 0; i < vec.size(); i++){
            this->v.append(vec[i]);
        }
        this->size = vec.size();
        this->father = NULL;
    }
};

#endif // HSTNODE_H
