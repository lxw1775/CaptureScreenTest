#pragma once
#include <QDialog>
/*
	Qt ����ͨ�Ų��Դ���
	�ο���https://blog.csdn.net/weixin_42837024/article/details/81669540

*/


#include <QWidget>
#include "ui_QSerialPortDlg.h"

class QSerialPortDlg : public QDialog
{
	Q_OBJECT

public:
	QSerialPortDlg(QWidget *parent = Q_NULLPTR);
	~QSerialPortDlg();

private:
	Ui::QSerialPortDlg ui;
};
