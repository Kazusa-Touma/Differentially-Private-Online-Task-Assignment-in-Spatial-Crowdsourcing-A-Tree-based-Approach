#include <initialization.h>
#include <QDebug>

HSTnode *trie;
double budget, totalDistance;
int cnt;
QString res;
QMap <int, double> probability;
QVector <point> s, order, worker;
QMap <point, QString> mirror;
QMap <HSTnode*, int> symbol;
QMap <int, point> reverse_set;
QVector <ob_node> obfuscated_worker, obfuscated_order;

int HSTnode::c;

double Find_mostfar(QVector <point> s)
{
    int n = s.size();
    qDebug()<<n<<endl;
    double maxdistance = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            maxdistance = qMax(maxdistance, s[i].countdistance(s[j]));
        }
    }
    return maxdistance;
}

void addnode(HSTnode* f, double p, int depth)
{
    if (depth < 0) return;
    double r = p * (double)(1 << depth);
    int size = f->size, cnt, branch = 0;
    cnt = size;
    bool vis[10005] = { 0 };
    for (int i = 0; i < size && cnt; i++) {
        QVector <point> v;
        if (!vis[i]) {
            v.push_back(f->v[i]);
            vis[i] = true;
            cnt--;
        }
        for (int j = i + 1; j < size; j++) {
            if (!vis[j] && f->v[i].countdistance(f->v[j]) <= r) {
                vis[j] = true;
                v.push_back(f->v[j]);
                cnt--;
            }
        }
        HSTnode* tmp = new HSTnode(v);
        tmp->father = f;
        f->son.push_back(tmp);
        branch++;
        addnode(tmp, p, depth - 1);
    }
    HSTnode::c = qMax(HSTnode::c, branch);
}

void addbranch(HSTnode* s, int depth)
{
    s->level = depth;
    if (depth == 0) {
        return;
    }
    int size = s->son.size();
    if (size < HSTnode::c) {
        while (size++ < HSTnode::c) {
            HSTnode* tmp = new HSTnode();
            s->son.push_back(tmp);
            tmp->father = s;
        }
    }
    for (int i = 0; i < HSTnode::c; i++) {
        addbranch(s->son[i], depth - 1);
    }
}

void buildtree(QVector <point> s)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    trie = new HSTnode(s);
    double maxdistance = Find_mostfar(s);
    int D = ceil(log(2 * maxdistance) / log(2));
    double b = rand() / RAND_MAX / 2 + 0.5;
    addnode(trie, b, D - 1);
    addbranch(trie, D);
}

void init(HSTnode* t)
{
    int C = HSTnode::c, D = t->level;
    double wt1 = 0, wt2 = 0;
    wt1 = pow(C, D - 1) * (C - 1) * exp((4 - pow(2, D + 2)) * budget);
    for (int i = D - 1; i >= 0; i--) {
        if (i > 0) {
            wt2 = wt1 + pow(C, i - 1) * (C - 1) * exp((4 - pow(2, i + 2)) * budget);
        }
        else {
            wt2 = wt1 + 1;
        }
        probability.insert(i, wt1 / wt2);
        wt1 = wt2;
    }
}
void symbolize(HSTnode *p)
{
    if (p->level == 0) {
        symbol[p] = ++cnt;
        return;
    }
    for (int i = 0; i < p->son.size(); i++) {
        symbolize(p->son[i]);
    }
}
