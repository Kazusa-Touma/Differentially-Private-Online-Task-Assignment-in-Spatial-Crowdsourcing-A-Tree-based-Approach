#ifndef INITIALIZATION_H
#define INITIALIZATION_H
#include <data.h>
#include <QVector>
#include <qmath.h>
#include <QTime>

void symbolize(HSTnode *p);
void init(HSTnode* t);
void buildtree(QVector <point> s);
void addbranch(HSTnode* s, int depth);
void addnode(HSTnode* f, double p, int depth);
double Find_mostfar(QVector <point> s);

#endif // INITIALIZATION_H
