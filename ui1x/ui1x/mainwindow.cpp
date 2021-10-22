#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <data.h>
#include <initialization.h>
#include <matching.h>
#include <obfuscation.h>

bool flag = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonfirst_clicked()
{
    QString file_path_1 = QFileDialog::getOpenFileName(this, "请选择文件路径...","/", tr("text(*.txt)"));
    ui->lineEditfirst->setText(file_path_1);

}


void MainWindow::on_pushButtonworker_clicked()
{
    QString file_path_worker = QFileDialog::getOpenFileName(this, "请选择文件路径...","/", tr("text(*.txt)"));
    ui->lineEditworker->setText(file_path_worker);

}


void MainWindow::on_pushButton_3_clicked()
{
    QString str1;//str是订单名字（第一列）
    double x1, y1;//x，y为经纬度
    QFile file(ui->lineEditfirst->text());
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    while(!file.atEnd()) {
        QByteArray line = file.readLine();
        QString str = line;
        QStringList strList = str.split(" ");
        QString str1=strList[0];
        QString c2=strList[4];
        QString c3=strList[5];
        x1 = c2.toDouble();
        y1 = c3.toDouble();
        point tmp1 = point(x1, y1);
        s.push_back(tmp1);
        order.push_back(tmp1);
        mirror.insert(tmp1, str1);
    }

    QString str2;//str是工人名字（第一列）
    double x2, y2;//x，y为经纬度
    QFile file2(ui->lineEditworker->text());
    if(!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    while(!file2.atEnd()) {
        QByteArray line = file2.readLine();
        QString str = line;
        QStringList strList = str.split(" ");
        QString str2=strList[0];                         //工人位置
        QString c2=strList[4];
        QString c3=strList[5];
        x2 = c2.toDouble();
        y2 = c3.toDouble();
        point tmp2 = point(x2, y2);
        s.push_back(tmp2);
        worker.push_back(tmp2);
        mirror.insert(tmp2, str2);
    }

    HSTnode::c = 0;
    budget = 0.6;
    buildtree(s);
    init(trie);
    symbolize(trie);
    obfuscate();
    flag = true;
}


void MainWindow::on_pushButton_4_clicked()
{
    qDebug()<<1<<endl;
    if(flag){
        qDebug()<<2<<endl;
        matching(trie, obfuscated_worker, obfuscated_order);
        qDebug()<<res<<endl;
    }
}

