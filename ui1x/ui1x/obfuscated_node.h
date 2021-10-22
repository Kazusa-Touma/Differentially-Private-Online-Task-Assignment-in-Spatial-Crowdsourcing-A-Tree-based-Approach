#ifndef OBFUSCATED_NODE_H
#define OBFUSCATED_NODE_H
#include <qstring.h>

class obfuscated_node
{
private:
    int number;
    QString name;

public:
    obfuscated_node(){}

    obfuscated_node(int num, QString n) {
        number = num;
        name = n;
    }

    bool operator < (const obfuscated_node& x) const
    {
        return number < x.number;
    }

    int getnum() {
        return number;
    }

    QString getname() {
        return name;
    }
};

#endif // OBFUSCATED_NODE_H
