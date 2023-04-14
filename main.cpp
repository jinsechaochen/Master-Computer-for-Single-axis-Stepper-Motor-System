#include "widget.h"  // 包含头文件 widget.h
#include <QApplication>  // 包含 Qt 库的应用程序头文件
#include <QMessageBox>  // 包含 Qt 库的消息框头文件

#pragma execution_character_set("utf-8")  // 设置程序的字符集为 UTF-8

int main(int argc, char *argv[])  // 程序的主函数
{
    QApplication a(argc, argv);  // 创建一个 QApplication 实例，参数为命令行参数
    Widget w;  // 创建一个 Widget 实例
    w.show();  // 显示窗口

    return a.exec();  // 开始事件循环
}
