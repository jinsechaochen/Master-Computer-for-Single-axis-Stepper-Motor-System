/*
 * 这是给我们的课程实验写的上位机，我基本都写了详细的注释，如果有问题请在我的Github项目里留言
 * 希望你的开发一切顺利捏！
 * DuskyBook @ Github： https://github.com/jinsechaochen/Epigynous-Computer-for-Single-axis-Stepper-Motor-System
*/

// 引入 Widget 类的头文件 widget.h 和 ui_widget.h
#include "widget.h"
#include "ui_widget.h"
// 引入 Qt 的消息框和计时器类的头文件
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#pragma execution_character_set("utf-8")  // 设置代码执行时的字符集为 UTF-8

Widget::Widget(QWidget *parent) :  // Widget 类的构造函数，初始化类的成员变量和 UI 界面
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //this->showMaximized();
    QStringList listCom = m_pCom->GetComAll();  // 在下拉框中添加所有可用的串口
	for (int i = 0; i < listCom.size(); i++)
	{
		ui->comboBoxName->insertItem(i, listCom.at(i));
	}

    connect(ui->pushButtonOpen, &QPushButton::clicked, [=](){  // 连接打开串口按钮的点击事件和相应的槽函数
		OpenPushButton();
    });
    connect(ui->pushButtonReset, &QPushButton::clicked, [=]() {  // 连接复位按钮的点击事件和相应的槽函数
        // 构造复位指令的字节数组
		unsigned char szBuf[] = { 0xAA, 0x00, 0x00,
									0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
									0x55, 0x55, 0x55, 0x55, 0x55,
									0xff };
		int iNum = ui->comboBoxNum->currentText().toInt();
		szBuf[1] = iNum & 0xff;
		
        QByteArray arr((char*)szBuf, sizeof(szBuf));  // 将字节数组转换成 QByteArray 对象，并发送到串口
		m_pCom->SendInfo(arr);
	});
    connect(ui->pushButtonStopFast, &QPushButton::clicked, [=]() {  // 连接急停按钮的点击事件和相应的槽函数
		SendStopInfo();
	});

    // 连接串口对象的接收和发送信号和相应的槽函数
    connect(m_pCom, SIGNAL(RecvByteSignal(QByteArray)), this, SLOT(RecvInfoFromSerialSlot(QByteArray)));
    connect(m_pCom, SIGNAL(SendByteSignal(QByteArray)), this, SLOT(SendInfoFromSerialSlot(QByteArray)));
    // 调用成员函数，设置计时器、坐标点和串口相关的按钮
    SetTimer();
    SetPointButton();
    SetComButton();
}
// Widget类的析构函数，释放ui指针的内存空间
Widget::~Widget()
{
    delete ui;
}

void Widget::RecvInfoFromSerialSlot(QByteArray arr)  // 从串口接收到数据时，将接收到的数据显示在文本框中

{
    if(ui->checkBoxRecvHex->isChecked())
    {
        AddText(m_pCom->ByteToHexString(arr));
    }
    else
    {
        AddText(QString(arr));
    }
}

void Widget::SendInfoFromSerialSlot(QByteArray arr)
{
    if(ui->checkBoxSendHex->isChecked())  // 如果用户勾选了“十六进制接收”选项，则将接收到的数据转换成十六进制格式再显示

    {
        AddText(m_pCom->ByteToHexString(arr), false);
    }
    else  // 如果用户没有勾选“十六进制接收”选项，则直接将接收到的数据以字符串形式显示

    {
        AddText(QString(arr), false);
    }
}

void Widget::OpenPushButton()
{
    if (m_pCom->IsOpenCom())  // 检查串口是否已经打开
	{
        m_pCom->CloseComs();   // 如果已经打开，就关闭它
        ui->pushButtonOpen->setStyleSheet("background-color:rgb(255,0,0);");  // 按钮变红
        ui->pushButtonOpen->setText(tr("打开串口"));  // 按钮上的文字改为“打开串口”
	}
	else
	{
        QString strPortName = ui->comboBoxName->currentText();  // 获取串口名称
        int iBaund = ui->comboBoxBaund->currentText().toInt();  // 获取波特率
        int iData = 8;  // 数据位默认为8
        int iStop = 1;  // 停止位默认为1
        int iParty = 0;  // 校验位默认为0

        bool bRet = m_pCom->OpenCom(strPortName, iBaund, iData, iStop, iParty);
        if (bRet)  // 如果打开成功
		{
            ui->pushButtonOpen->setStyleSheet("background-color:rgb(0,255,0);");  // 按钮变绿
            ui->pushButtonOpen->setText(tr("关闭串口"));  // 按钮上的文字改为“关闭串口”
		}
		else
		{
            QMessageBox::warning(this, tr("提示"), tr("串口打开失败，请检查"), tr("确定"));  // 显示打开失败的提示框
		}
	}
}

void Widget::AddText(QString strInfo, bool bRecv)
{
    QDateTime time = QDateTime::currentDateTime();   // 获取当前时间
    QString strTemp;
    if(bRecv)  // 如果是接收到的数据
    {
        strTemp = QString(tr("<font color=red>[%1][接收]%2</font>")).arg(time.toString("hh:mm:ss.zzz")).arg(strInfo);  // 构造接收数据的字符串
        ui->textEditRecv->append(strTemp);   // 在接收框中添加接收数据
        ui->textEditRecv->moveCursor(QTextCursor::End);  // 将光标移到接收框的末尾
    }
    else
    {
        strTemp = QString(tr("<font color=blue>[%1][发送]%2</font>")).arg(time.toString("hh:mm:ss.zzz")).arg(strInfo);  // 构造发送数据的字符串
        ui->textEditSend->append(strTemp);  // 在发送框中添加发送数据
        ui->textEditSend->moveCursor(QTextCursor::End);   // 将光标移到发送框的末尾
    }
}

// 停止计时器
void Widget::StopPointRun()
{
    pTimerPoint->stop();  // 停止计时器
}
// 计算校验和
unsigned char GetCrcSum(char* pData, int iLen)
{
    unsigned char uAdd = 0x00;
    if(pData == NULL)  // 如果数据为空，则返回0x00
    {
        return uAdd;
    }

    unsigned short usData = 0;
    for(int i = 0; i < iLen; i++)  // 计算校验和
    {
        usData += pData[i];
    }

    uAdd = usData & 0x00ff;  // 取校验和的低8位

    return uAdd;  // 返回校验和
}
// 设置计时器
void Widget::SetTimer()
{
    connect(pTimerPoint, &QTimer::timeout, [=]() {  // 将超时事件与一个 Lambda 表达式连接起来
        if (!m_pCom->IsOpenCom())  // 如果串口没有打开，弹出警告框并停止计时器
        {
            QMessageBox::warning(this, tr("提示"), tr("串口未打开，失败"));
            pTimerPoint->stop();
            return;
        }

        if(m_iCurPointNum >= m_vecPointArrSend.size() || m_iCurPointNum < 0)  // 如果当前点的序号超出范围，则重置为0
        {
            m_iCurPointNum = 0;
        }

        QByteArray arr = m_vecPointArrSend.at(m_iCurPointNum);  // 获取下一个点
        m_pCom->SendInfo(arr);  // 通过串口发送该点

        m_iCurPointNum++;  // 更新当前点的序号
    });

}

void Widget::SendPointInfo(int iDir)  //设置寸动（点动）命令
{
    // 定义一个长度为15的unsigned char数组，并初始化为给定的值
    unsigned char szBuf[] = { 0xAA,  //1字节帧头
                                0x00, 0x00,  //1字节细分数量，1字节模式选择
                                0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  //1字节运转方向，6字节控制数据
                                0x55, 0x55, 0x55, 0x55, 0x55,  //5字节占位符
                                0xff };  //1字节帧尾
    int iNum = ui->comboBoxNum->currentText().toInt();   //获取细分数量下拉框中选中的数字编号，将其转换为int类型，并保存在iNum变量中
    szBuf[1] = iNum & 0xff;   // 将细分数量写入到数组的第二个元素中（低8位）

    szBuf[2] = 2;   // 设置为二区模式(寸动)
     // 获取长度和速度的值，保存在iLength和iSpeed变量中
	int iLength = ui->lineEditLengthTwo->text().toInt();
	int iSpeed = ui->lineEditSpeedTwo->text().toInt();

    szBuf[3] = iDir;   // 将方向值写入到数组的第4个元素中
    // 将长度值的高8位写入到数组的第5个元素中，中间8位写入到第6个元素中，低8位写入到第7个元素中
	szBuf[4] = iLength >> 16 & 0xff;
	szBuf[5] = iLength >> 8 & 0xff;
	szBuf[6] = iLength & 0xff;
     // 将速度值的高8位写入到数组的第8个元素中，中间8位写入到第9个元素中，低8位写入到第10个元素中
	szBuf[7] = iSpeed >> 16 & 0xff;
	szBuf[8] = iSpeed >> 8 & 0xff;
	szBuf[9] = iSpeed & 0xff;
     // 将szBuf数组转换为QByteArray类型的arr，并通过m_pCom对象发送给外部设备
	QByteArray arr((char*)szBuf, sizeof(szBuf));
	m_pCom->SendInfo(arr);
}

void Widget::SendStopInfo()  //设置停止命令，意思跟上面差不多，参考一下
{
    unsigned char szBuf[] = { 0xAA,
                                0x00, 0x00,
								0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
								0x55, 0x55, 0x55, 0x55, 0x55,
								0xff };
    // 从下拉框中获取设备编号，转换为整型，并将其写入数组的第2个元素
	int iNum = ui->comboBoxNum->currentText().toInt();
	szBuf[1] = iNum & 0xff;
	szBuf[2] = 0;

	QByteArray arr((char*)szBuf, sizeof(szBuf));
    m_pCom->SendInfo(arr);  // 调用串口对象的SendInfo函数，将指令信息发送给设备

}

void Widget::SetPointButton()  //意思跟上面的上面是差不多的，不细写了
{
    // 设置添加点按钮按下时的操作
    connect(ui->pushButtonPointAdd, &QPushButton::pressed, [=](){
        ui->lineEditPointSpeed->setText(ui->lineEditSpeedTwo->text());  // 将第二个速度框中的内容赋给添加点框的速度框中
		if (ui->checkBoxPoint->isChecked())
		{
			SendPointInfo(1);
		}
		
    });
    connect(ui->pushButtonPointAdd, &QPushButton::released, [=](){
		if (ui->checkBoxPoint->isChecked())
		{
			SendStopInfo();
		}
    });

    connect(ui->pushButtonPointSub, &QPushButton::pressed, [=](){
		ui->lineEditPointSpeed->setText(ui->lineEditSpeedTwo->text());
		if (ui->checkBoxPoint->isChecked())
		{
			SendPointInfo(0);
		}
    });
    connect(ui->pushButtonPointSub, &QPushButton::released, [=](){
		if (ui->checkBoxPoint->isChecked())
		{
			SendStopInfo();
		}
    });

	connect(ui->pushButtonSendMode, &QPushButton::clicked, [=]() {
		unsigned char szBuf[] = { 0xAA, 0x00, 0x00,
								0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
								0x55, 0x55, 0x55, 0x55, 0x55,
								0xff };
		int iNum = ui->comboBoxNum->currentText().toInt();
		szBuf[1] = iNum & 0xff;
		if (ui->checkBoxOne->isChecked())
		{
			szBuf[2] = 1;

			int iDir = ui->comboBoxDirOne->currentIndex();
			int iAngle = ui->lineEditAngleOne->text().toInt();
			int iSpeed = ui->lineEditSpeedOne->text().toInt();

			szBuf[3] = iDir;
			
			szBuf[4] = iAngle >> 16 & 0xff;
			szBuf[5] = iAngle >> 8 & 0xff;
			szBuf[6] = iAngle & 0xff;

			szBuf[7] = iSpeed >> 16 & 0xff;
			szBuf[8] = iSpeed >> 8 & 0xff;
			szBuf[9] = iSpeed & 0xff;

			QByteArray arr((char*)szBuf, sizeof(szBuf));
			m_pCom->SendInfo(arr);
		}
		else if(ui->checkBoxTwo->isChecked())
		{
			szBuf[2] = 2;

			int iDir = ui->comboBoxDirTwo->currentIndex();
			int iLength = ui->lineEditLengthTwo->text().toInt();
			int iSpeed = ui->lineEditSpeedTwo->text().toInt();

			szBuf[3] = iDir;
			szBuf[4] = iLength >> 16 & 0xff;
			szBuf[5] = iLength >> 8 & 0xff;
			szBuf[6] = iLength & 0xff;

			szBuf[7] = iSpeed >> 16 & 0xff;
			szBuf[8] = iSpeed >> 8 & 0xff;
			szBuf[9] = iSpeed & 0xff;
			QByteArray arr((char*)szBuf, sizeof(szBuf));
			m_pCom->SendInfo(arr);
		}
	});

}

void Widget::SetComButton()
{
    // 连接发送清空按钮的信号和槽
     connect(ui->pushButtonSendClear, &QPushButton::clicked, [=](){
           ui->textEditSend->setText(""); // 将发送区清空
     });
    // 连接接收清空按钮的信号和槽
     connect(ui->pushButtonClearRecv, &QPushButton::clicked, [=](){
           ui->textEditRecv->setText(""); // 将接收区清空
     });
    // 连接发送按钮的信号和槽
     connect(ui->pushButtonSendSend, &QPushButton::clicked, [=](){
          QString strSend = ui->textEditSend->toPlainText();  // 获取发送区的内容
          QByteArray arr;
          if (ui->checkBoxSendHex->isChecked())  // 如果勾选了“16进制发送”，则将字符串转换为16进制的字节数组
          {
             arr  = m_pCom->HexStringToByte(strSend);
          }
           else  // 否则将字符串转换为本地字符集编码的字节数组
          {
              arr = strSend.toLocal8Bit();
          }

          m_pCom->SendInfo(arr);  // 调用串口对象的SendInfo()函数发送字节数组
     });
    // 连接更新串口按钮的信号和槽
     connect(ui->pushButtonUpdateCom, &QPushButton::clicked, [=](){
        QStringList lstInfo = m_pCom->GetComAll();  // 获取所有可用串口的信息
        ui->comboBoxName->clear(); // 获取所有可用串口的信息
        for(int i = 0; i < lstInfo.size(); i++)
        {
            ui->comboBoxName->insertItem(i, lstInfo.at(i));  // 将串口号添加到下拉框中
        }
     });
     // 连接设置电机脉冲数按钮的信号和槽
	 connect(ui->pushButtonSetOne, &QPushButton::clicked, [=]() {
         double dAngle = ui->lineEditAngleOne->text().toDouble();  // 获取电机角度值
         double dSpeed = ui->lineEditSpeedOne->text().toDouble();  // 获取电机角度值
         int iNum = ui->comboBoxNum->currentText().toInt();  // 获取电机数量
		 
         double dPules = (dAngle * 100.0 + dSpeed) / 360.0 * 200.0 * (double)iNum;   // 计算电机的脉冲数

         ui->lineEditPulesOne->setText(QString::number(dPules));  // 在界面上显示电机的脉冲数
	 });
}



