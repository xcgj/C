#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <windows.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QMessageBox::information(this,"success!","xcgj");
}

void Widget::on_pushButton_2_clicked()
{
    system("notepad");
}

void Widget::on_pushButton_3_clicked()
{
    system("regedit");
}

void Widget::on_pushButton_4_clicked()
{
    WinExec("calc",SW_NORMAL);
}

void Widget::on_pushButton_5_clicked()
{
    WinExec("snippingtool",SW_NORMAL);
}

void Widget::on_pushButton_6_clicked()
{
    //ui->lineEdit->text().toStdString().data()
    WinExec(ui->lineEdit->text().toStdString().data(),SW_NORMAL);
}
