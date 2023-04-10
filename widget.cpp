#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#pragma execution_character_set("utf-8")

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //this->showMaximized();
    QStringList listCom = m_pCom->GetComAll();
	for (int i = 0; i < listCom.size(); i++)
	{
		ui->comboBoxName->insertItem(i, listCom.at(i));
	}

    connect(ui->pushButtonOpen, &QPushButton::clicked, [=](){
		OpenPushButton();
    });
	connect(ui->pushButtonReset, &QPushButton::clicked, [=]() {
		unsigned char szBuf[] = { 0xAA, 0x00, 0x00,
									0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
									0x55, 0x55, 0x55, 0x55, 0x55,
									0xff };
		int iNum = ui->comboBoxNum->currentText().toInt();
		szBuf[1] = iNum & 0xff;
		
		QByteArray arr((char*)szBuf, sizeof(szBuf));
		m_pCom->SendInfo(arr);
	});
	connect(ui->pushButtonStopFast, &QPushButton::clicked, [=]() {
		SendStopInfo();
	});

    connect(m_pCom, SIGNAL(RecvByteSignal(QByteArray)), this, SLOT(RecvInfoFromSerialSlot(QByteArray)));
    connect(m_pCom, SIGNAL(SendByteSignal(QByteArray)), this, SLOT(SendInfoFromSerialSlot(QByteArray)));

    SetTimer();
    SetPointButton();
    SetComButton();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::RecvInfoFromSerialSlot(QByteArray arr)
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
    if(ui->checkBoxSendHex->isChecked())
    {
        AddText(m_pCom->ByteToHexString(arr), false);
    }
    else
    {
        AddText(QString(arr), false);
    }
}

void Widget::OpenPushButton()
{
    if (m_pCom->IsOpenCom())
	{
        m_pCom->CloseComs();
		ui->pushButtonOpen->setStyleSheet("background-color:rgb(255,0,0);");
		ui->pushButtonOpen->setText(tr("打开串口"));
	}
	else
	{
		QString strPortName = ui->comboBoxName->currentText();
		int iBaund = ui->comboBoxBaund->currentText().toInt();
        int iData = 8;
		int iStop = 1;
		int iParty = 0;

        bool bRet = m_pCom->OpenCom(strPortName, iBaund, iData, iStop, iParty);
		if (bRet)
		{
			ui->pushButtonOpen->setStyleSheet("background-color:rgb(0,255,0);");
			ui->pushButtonOpen->setText(tr("关闭串口"));
		}
		else
		{
			QMessageBox::warning(this, tr("提示"), tr("串口打开失败"), tr("确定"));
		}
	}
}

void Widget::AddText(QString strInfo, bool bRecv)
{
    QDateTime time = QDateTime::currentDateTime();
    QString strTemp;
    if(bRecv)
    {
        strTemp = QString(tr("<font color=red>[%1][接收]%2</font>")).arg(time.toString("hh:mm:ss.zzz")).arg(strInfo);
        ui->textEditRecv->append(strTemp);
		ui->textEditRecv->moveCursor(QTextCursor::End);
    }
    else
    {
        strTemp = QString(tr("<font color=blue>[%1][发送]%2</font>")).arg(time.toString("hh:mm:ss.zzz")).arg(strInfo);
        ui->textEditSend->append(strTemp);
        ui->textEditSend->moveCursor(QTextCursor::End);
    }
}


void Widget::StopPointRun()
{
	pTimerPoint->stop();
}

unsigned char GetCrcSum(char* pData, int iLen)
{
    unsigned char uAdd = 0x00;
    if(pData == NULL)
    {
        return uAdd;
    }

    unsigned short usData = 0;
    for(int i = 0; i < iLen; i++)
    {
        usData += pData[i];
    }

    uAdd = usData & 0x00ff;

    return uAdd;
}

void Widget::SetTimer()
{
    connect(pTimerPoint, &QTimer::timeout, [=]() {
        if (!m_pCom->IsOpenCom())
        {
            QMessageBox::warning(this, tr("提示"), tr("串口未打开，失败"));
            pTimerPoint->stop();
            return;
        }

        if(m_iCurPointNum >= m_vecPointArrSend.size() || m_iCurPointNum < 0)
        {
            m_iCurPointNum = 0;
        }

        QByteArray arr = m_vecPointArrSend.at(m_iCurPointNum);
        m_pCom->SendInfo(arr);

        m_iCurPointNum++;
    });

}

void Widget::SendPointInfo(int iDir)
{
	unsigned char szBuf[] = { 0xAA, 0x00, 0x00,
								0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
								0x55, 0x55, 0x55, 0x55, 0x55,
								0xff };
	int iNum = ui->comboBoxNum->currentText().toInt();
	szBuf[1] = iNum & 0xff;

	szBuf[2] = 2;

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

void Widget::SendStopInfo()
{
	unsigned char szBuf[] = { 0xAA, 0x00, 0x00,
								0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
								0x55, 0x55, 0x55, 0x55, 0x55,
								0xff };
	int iNum = ui->comboBoxNum->currentText().toInt();
	szBuf[1] = iNum & 0xff;
	szBuf[2] = 0;

	QByteArray arr((char*)szBuf, sizeof(szBuf));
	m_pCom->SendInfo(arr);

}

void Widget::SetPointButton()//ABC点动暂时不设置功能
{
    connect(ui->pushButtonPointAdd, &QPushButton::pressed, [=](){
		ui->lineEditPointSpeed->setText(ui->lineEditSpeedTwo->text());
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
     connect(ui->pushButtonSendClear, &QPushButton::clicked, [=](){
           ui->textEditSend->setText("");
     });

     connect(ui->pushButtonClearRecv, &QPushButton::clicked, [=](){
           ui->textEditRecv->setText("");
     });

     connect(ui->pushButtonSendSend, &QPushButton::clicked, [=](){
          QString strSend = ui->textEditSend->toPlainText();
          QByteArray arr;
          if (ui->checkBoxSendHex->isChecked())
          {
             arr  = m_pCom->HexStringToByte(strSend);
          }
           else
          {
              arr = strSend.toLocal8Bit();
          }

          m_pCom->SendInfo(arr);
     });

     connect(ui->pushButtonUpdateCom, &QPushButton::clicked, [=](){
        QStringList lstInfo = m_pCom->GetComAll();
        ui->comboBoxName->clear();
        for(int i = 0; i < lstInfo.size(); i++)
        {
            ui->comboBoxName->insertItem(i, lstInfo.at(i));
        }
     });

	 connect(ui->pushButtonSetOne, &QPushButton::clicked, [=]() {
		 double dAngle = ui->lineEditAngleOne->text().toDouble();
		 double dSpeed = ui->lineEditSpeedOne->text().toDouble();
		 int iNum = ui->comboBoxNum->currentText().toInt();
		 
		 double dPules = (dAngle * 100.0 + dSpeed) / 360.0 * 200.0 * (double)iNum;

		 ui->lineEditPulesOne->setText(QString::number(dPules));
	 });
}



