#include "widget.h"

#include <QApplication>             //QT的框架头文件
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);     //QT框架的初始化
    Widget w;                       //定义一个窗口对象（控件）
    w.show();                       //显示这个窗口对象（控件）
    qDebug()<<"hello";//bedug界面输出
    return a.exec();                //a.exec()使程序不死，类似于while(1)循环，循环检测事件的发生
}
