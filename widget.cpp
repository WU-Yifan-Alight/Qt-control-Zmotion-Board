#include "widget.h"
#include "ui_widget.h"
#include "zauxdll2.h"



ZMC_HANDLE g_handle = NULL; //连接控制器 句柄
int countn=0;
int m_nAxis = 0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //代码直接写在窗口的构造函数里，尽量不要写在main函数中
    ui->setupUi(this);
    ui->lineEdit_Input_IP_Adress->setText("请输入仿真器的IP地址"); //初始化ip地址输入框中的字符显示
    ui->lineEdit_Show_Position->setText("暂未获得位置数据");       //初始化 显示位置 单行文本编辑控件
    ui->lineEdit_Show_Speed->setText("暂未获得速度数据");          //初始化 显示速度 单行文本编辑控件
    ui->lineEdit_Set_Speed->setText("0");                       //初始化 设置速度 单行文本编辑控件
    ui->lineEdit_Set_PositiveAcc->setText("0");                 //初始化 设置正向加速度 单行文本编辑控件
    ui->lineEdit_Set_NegativeAcc->setText("0");                 //初始化 设置反向加速度 单行文本编辑控件

    t = new QTimer;                                             //初始化定时器

    connect(t,&QTimer::timeout,this,&Widget::updateData);       //连接定时器超时事件的信号与槽
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateData()
{
    countn++;
    qDebug()<<"定时器正常";
    qDebug()<<countn;
    if (NULL == g_handle)
    {
        QMessageBox::about(this,"未成功连接","请尝试重新连接到仿真器"); //提示与仿真器断开连接
        return;
    }

    QString stringPosition;
    QString stringSpeed;
    float position = 0;
    ZAux_Direct_GetDpos(g_handle, m_nAxis, &position);  //获取当前轴的位置
    stringPosition.setNum(position);
    ui->lineEdit_Show_Position->setText(stringPosition);

    float speed= 0;
    ZAux_Direct_GetVpSpeed(g_handle, m_nAxis, &speed);  //获取当前轴的速度
    stringSpeed.setNum(speed);
    ui->lineEdit_Show_Speed->setText(stringSpeed);
}

void Widget::on_pushButton_Connect_clicked()
{
    QString   ipadress;                                     //注意！！此定义最终需放在头文件中
    int32  connectresult;
    char* ipadressChar;                                     //注意！！此定义最终需放在头文件中
    if (NULL != g_handle)
    {
        ZAux_Close(g_handle);
    // 这是Zmotion库中的函数 ZAux_Close(ZMC_HANDLE) ，它是用于断开仿真器的。
        g_handle = NULL;
    }
    ipadress=ui->lineEdit_Input_IP_Adress->text();         //获取ip地址输入框中的ip地址，但不能直接使用
    // 从这里开始进行 QString 到 char* 的转化，需要用到QByteArray类
    QByteArray ipadressQBA = ipadress.toLatin1();          //进行转换
    ipadressChar = ipadressQBA.data();                     //转化结束
    connectresult=ZAux_OpenEth(ipadressChar, &g_handle);   //尝试连接到仿真器，返回连接结果
    // 上面的ZAux_OpenEth(char*, ZMC_HANDLE)也是Zmotion库中的函数，用来连接到仿真器。
    if (ERR_SUCCESS != connectresult)
    {
        g_handle = NULL;
        //若没有成功连接到仿真器，则弹出窗口提示重试尝试连接
        QMessageBox::about(this,"未成功连接","请尝试重新连接到仿真器");
        return;
    }
    ui->label_ConnectState->setText("已连接");              //若连接到仿真器，则显示连接状态为已连接
    ui->pushButton_Connect->setEnabled(false);             //连接后禁用连接按钮，防止重连
    t->start(100);                                         //建立定时器，0.1秒触发一次
}

void Widget::on_pushButton_Disconnect_clicked()
{
    if (NULL != g_handle)
    {
        t->stop();						                   //关定时器
        ZAux_Close(g_handle);
        // 再在此函数内部添加Zmotion库中的函数 ZAux_Close(ZMC_HANDLE)。
        g_handle = NULL;
        ui->label_ConnectState->setText("已断开");          //显示连接状态为已断开
        ui->pushButton_Connect->setEnabled(true);          //恢复连接按钮
    }
}

void Widget::closeEvent(QCloseEvent *event)
{
    switch( QMessageBox::information( this, tr("提示"), tr("请问您是否确认退出?"),tr("是"), tr("否"),
    0, 1 ) )
        {
             case 0:
                 event->accept();
                 t->stop();
                 ZAux_Close(g_handle);
                 g_handle = NULL;
                 break;
             case 1:
                 default:
                 event->ignore();
                 break;
        }

}


void Widget::on_pushButton_Move_clicked()
{
    if (NULL == g_handle)
    {
        QMessageBox::about(this,"未成功连接","请尝试重新连接到仿真器"); //提示与仿真器断开连接
        return;
    }
    QString input_SpeedNumber ;
    int count_number=0;
    input_SpeedNumber=ui->lineEdit_Set_Speed->text(); //获取文本框上的字符
    QString qc ;
    for (int i = 0; i < input_SpeedNumber.length(); i++)  //辨认每个字符
    {
        qc = input_SpeedNumber.mid(i,1);


        if ((qc >= '0' && qc <= '9') || qc == '.')          //统计输入字符的个数
        {
            count_number++;
        }

    }
    if(count_number!= input_SpeedNumber.length())         //比较输入字符的个数与判定为数字的个数
    {
        //若输入不完全为数字，则执行…
        QMessageBox::about(this,"提示","请输入纯数字");
        return;
    }
    else
    {
        //若输入完全为数字，则执行…
        int input_Speed=ui->lineEdit_Set_Speed->text().toInt();
        if(input_Speed>=0&&input_Speed<=200){

        int status = 0;
        ZAux_Direct_GetIfIdle(g_handle, m_nAxis, &status);//判断当前轴是否已经开始运动
        if (status == 0)                                  //已经在运动中
            return;
        ZAux_Direct_SetAtype(g_handle,m_nAxis, 1);        //设定轴类型 1 也即脉冲方向方式的步进或伺服
        ZAux_Direct_SetInvertStep(g_handle,m_nAxis, 0);   //设定脉冲模式及逻辑方向 0表示（脉冲+方向）
        //设置脉冲当量 1 表示以一个脉冲为单位 ，设置为1MM的脉冲个数，这度量单位为MM
        ZAux_Direct_SetUnits(g_handle,m_nAxis, 1);
        //设定速度，加减速
        ZAux_Direct_SetLspeed(g_handle,m_nAxis, 0);		 //设定起始速度为零


        ZAux_Direct_SetSpeed(g_handle, m_nAxis, input_Speed);

        int input_positive_acc=ui->lineEdit_Set_PositiveAcc->text().toInt();
        ZAux_Direct_SetAccel(g_handle, m_nAxis, input_positive_acc);

        int input_negative_acc=ui->lineEdit_Set_NegativeAcc->text().toInt();
        ZAux_Direct_SetDecel(g_handle, m_nAxis, input_negative_acc);
        //设定S曲线时间 设置为0表示梯形加减速，大于0为S型运动，此处为10
        ZAux_Direct_SetSramp(g_handle, m_nAxis, 10);
        //持续驱动(速度模式)
        //ZAux_Direct_Singl_Vmove(g_handle, m_nAxis, m_bLogic ? 1 : 0);
        //若m_bLogic为true则为正向运动，反之为反向运动，这里默认只有正向运动功能
        ZAux_Direct_Singl_Vmove(g_handle, m_nAxis, 1);
        ui->pushButton_Move->setEnabled(false);//运行按钮暂停使能
        }
        else
        {
            QMessageBox::about(this,"提示","请输入在0~200之间的速度值");
            return;
        }
    }
}

void Widget::on_pushButton_Stop_clicked()
{
    if (NULL == g_handle)
        {
            QMessageBox::about(this,"未成功连接","请尝试重新连接到仿真器"); //提示与仿真器断开连接
            return;
        }
    ZAux_Direct_Singl_Cancel(g_handle, m_nAxis, 2);//命令伺服驱动器停止
    ui->pushButton_Move->setEnabled(true);
}
