#include <matching.h>

void matching(HSTnode* T, QVector <ob_node> w, QVector <ob_node> t)
{
    int a, b;
    while ((!w.empty()) || (!t.empty())) {
        ob_node current_task = t.front();
        int order_pos = current_task.getnum();
        ob_node current_work = w.front();
        a = current_work.getnum();
        w.pop_front();
        if (w.empty()) {
            double dis;
            dis = reverse_set[current_work.getnum()].countdistance(reverse_set[current_task.getnum()]);
            totalDistance += dis;
            res += "worker:" + current_work.getname() + " task:" + current_task.getname() ;
            res.append("\n");
            break;
        }
        ob_node next_work = w.front();
        b = next_work.getnum();
        if (abs(order_pos - a) <= abs(order_pos - b)) {
            double dis;
            dis = reverse_set[current_work.getnum()].countdistance(reverse_set[current_task.getnum()]);
            totalDistance += dis;
            t.pop_front();
            totalDistance += reverse_set[current_work.getnum()].countdistance(reverse_set[current_task.getnum()]);
            res += "worker:" + current_work.getname() + " task:" + current_task.getname() ;
            res.append("\n");
        }
    }
}
