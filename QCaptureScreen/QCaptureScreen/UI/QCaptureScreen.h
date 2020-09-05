#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QCaptureScreen.h"

class QCaptureScreen : public QMainWindow
{
	Q_OBJECT

public:
	QCaptureScreen(QWidget *parent = Q_NULLPTR);


protected:
	//������ʾ������ʱ �����ƶ�����
	virtual void mousePressEvent(QMouseEvent*);
	virtual void mouseMoveEvent(QMouseEvent*);
	virtual void mouseReleaseEvent(QMouseEvent*);

private:
	Ui::QCaptureScreenClass ui;

	//������ʾ������ʱ �����ƶ��� ����
	bool		m_bDrag;
	QPoint		m_ptMouseStartPoint;
	QPoint		m_ptWindowTopleftPoint;
};
