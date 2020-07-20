#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget> //QWidget是所有控件的基类，就是一个窗口
#include <QDebug>
#include <QMessageBox>//弹出消息对话框类
#include <QTimer>//定时器类
#include <QMouseEvent>//鼠标响应类
#include <string>

extern int m_nAxis;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget() override;
    QTimer *t;
    void updateData();

private slots:
    void on_pushButton_Connect_clicked();

    void on_pushButton_Disconnect_clicked();

    void on_pushButton_Move_clicked();

    void on_pushButton_Stop_clicked();

private:
    Ui::Widget *ui;

protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // WIDGET_H
