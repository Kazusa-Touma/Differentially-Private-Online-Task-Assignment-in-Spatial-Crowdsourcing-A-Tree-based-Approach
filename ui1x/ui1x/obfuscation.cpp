#include <obfuscation.h>

HSTnode* find(point p)
{
    HSTnode* rnt = trie;
    while (rnt->son.size() > 0) {
        for (int i = 0; i < rnt->son.size(); i++) {
            HSTnode* tmp = rnt->son[i];
            int f = 0;
            for (int j = 0; j < tmp->size; j++) {
                if (tmp->v[j] == p) {
                    rnt = tmp;
                    f = 1;
                    break;
                }
            }
            if (f) break;
        }
    }
    return rnt;
}

HSTnode* randomwalk(HSTnode* p)
{
    HSTnode* tmp = p, * last = p;
    int C = HSTnode::c;
    while (true) {
        int r = rand() % C;
        double b = r / (double)C;
        if (b < probability[tmp->level]) {
            last = tmp;
            tmp = tmp->father;
        }
        else break;
    }
    if (tmp->level != 0) {
        while (true) {
            int r = rand() % C;
            if (tmp->son[r] != last) {
                tmp = tmp->son[r];
                break;
            }
        }
    }

    while (tmp->level != 0) {
        int r = rand() % C;
        tmp = tmp->son[r];
    }
    return tmp;
}

void obfuscate()
{
    for (int i = 0; i < worker.size(); i++) {
        HSTnode *ob = randomwalk(find(worker[i]));
        obfuscated_worker.push_back(ob_node(symbol[ob],mirror[worker[i]]));
        reverse_set[symbol[ob]] = worker[i];
    }
    for (int i = 0; i < order.size(); i++) {
        HSTnode* ob = randomwalk(find(order[i]));
        obfuscated_order.push_back(ob_node(symbol[ob],mirror[order[i]]));
        reverse_set[symbol[ob]] = order[i];
    }
    qSort(obfuscated_worker);
    qSort(obfuscated_order);
 }
