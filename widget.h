#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include "com.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    //串口打开关闭按钮触发的方法
	void OpenPushButton();

	void StopPointRun();

    void SetTimer();

    void SetPointButton();

    //设置COM相关
    void SetComButton();

	void SendPointInfo(int iDir);
	void SendStopInfo();

private:
    Ui::Widget *ui;

    //串口管理类
    Com* m_pCom = new Com;
	
    QVector<QByteArray> m_vecPointArrSend;
    int m_iCurPointNum = 0;
	QTimer* pTimerPoint = new QTimer;

public slots:

    //槽函数
    void RecvInfoFromSerialSlot(QByteArray);
	void SendInfoFromSerialSlot(QByteArray);
	void AddText(QString strInfo, bool bRecv = true);

private:

};

#endif // WIDGET_H
