#include "QHomePage.h"
#include <QMouseEvent>

//�Ƿ��ڲر�����
//#define TITLEBAR_HIDE


QCaptureScreen::QCaptureScreen(QWidget *parent)
	: QMainWindow(parent)
	, m_bDrag(false)
{
	ui.setupUi(this);

#ifdef TITLEBAR_HIDE
	//����ʾ������
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Dialog);
#endif // TITLEBAR_HIDE
}


void QCaptureScreen::mouseMoveEvent(QMouseEvent* event)
{

#ifdef TITLEBAR_HIDE
	if (m_bDrag)
	{
		//��ȡ����ƶ��ľ���
		QPoint pt = event->globalPos() - m_ptMouseStartPoint;
		//�ı䴰�ڵ�λ��
		this->move(m_ptWindowTopleftPoint + pt);
	}
#endif // TITLEBAR_HIDE
}

void QCaptureScreen::mousePressEvent(QMouseEvent* event)
{
#ifdef TITLEBAR_HIDE
	if (event->button() == Qt::LeftButton)
	{
		m_bDrag = true;
		//��ȡ����λ��
		m_ptMouseStartPoint = event->globalPos();
		//�ı䴰�ڵĳ�ʼλ��
		m_ptWindowTopleftPoint = this->frameGeometry().topLeft();
	}
#endif // TITLEBAR_HIDE
}

void QCaptureScreen::mouseReleaseEvent(QMouseEvent* event)
{
#ifdef TITLEBAR_HIDE
	if (event->button() == Qt::LeftButton)
	{
		m_bDrag = false;
	}
#endif // TITLEBAR_HIDE
}