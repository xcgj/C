#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <stdlib.h>
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
    WinExec("mspaint", SW_NORMAL);
}


void Widget::on_pushButton_2_clicked()
{
    WinExec("calc", SW_NORMAL);
}

void Widget::on_pushButton_3_clicked()
{
    system("cmd");
}


void Widget::on_pushButton_4_clicked()
{
    QMessageBox::information(0,"提示","01");
}
