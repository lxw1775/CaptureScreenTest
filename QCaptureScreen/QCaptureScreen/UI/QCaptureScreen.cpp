#include "QCaptureScreen.h"
#include <QMouseEvent>


QCaptureScreen::QCaptureScreen(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//����ʾ������
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Dialog);
}


void QCaptureScreen::mouseMoveEvent(QMouseEvent* event)
{
	if (m_bDrag)
	{
		//��ȡ����ƶ��ľ���
		QPoint pt = event->globalPos() - m_ptMouseStartPoint;
		//�ı䴰�ڵ�λ��
		this->move(m_ptWindowTopleftPoint + pt);
	}

}

void QCaptureScreen::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bDrag = true;
		//��ȡ����λ��
		m_ptMouseStartPoint = event->globalPos();
		//�ı䴰�ڵĳ�ʼλ��
		m_ptWindowTopleftPoint = this->frameGeometry().topLeft();
	}
}

void QCaptureScreen::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bDrag = false;
	}
}