#ifndef DATA_H
#define DATA_H

#include <hstnode.h>
#include <point.h>
#include <obfuscated_node.h>
#include <QString>
#include <QMap>
#include <QVector>

typedef obfuscated_node ob_node;

extern HSTnode *trie;
extern double budget, totalDistance;
extern int cnt;
extern QString res;
extern QMap <int, double> probability;
extern QVector <point> s, order, worker;
extern QMap <point, QString> mirror;
extern QMap <HSTnode*, int> symbol;
extern QMap <int, point> reverse_set;
extern QVector <ob_node> obfuscated_worker, obfuscated_order;

#endif // DATA_H
