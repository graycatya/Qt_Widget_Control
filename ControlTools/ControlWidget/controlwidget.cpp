#include "controlwidget.h"
#include <QEvent>
#include <QHoverEvent>

#include <QDebug>

ControlWidget::ControlWidget(QObject *parent) : QObject(parent)
{
    m_nPadding = 8;
    m_bMoveEnable = true;
    m_bResizeEnable = true;
    m_pWidget = nullptr;

    m_bMouse_Pressed = false;
    m_bMouse_Pressed_Left = false;
    m_bMouse_Pressed_Right = false;
    m_bMouse_Pressed_Top = false;
    m_bMouse_Pressed_Bottom = false;
    m_bMouse_Pressed_Left_Top = false;
    m_bMouse_Pressed_Right_Top = false;
    m_bMouse_Pressed_Left_Bottom = false;
    m_bMouse_Pressed_Right_Bottom = false;

    //设置父窗体
    if(parent->isWidgetType())
    {
        SetWidget(reinterpret_cast<QWidget*>(parent));
    }
}

bool ControlWidget::eventFilter(QObject *watched, QEvent *event)
{
    if(m_pWidget != nullptr && reinterpret_cast<QWidget*>(watched) == m_pWidget)
    {
        //部件的大小发生改变(QResizeEvent)
        if(event->type() == QEvent::Resize)
        {
            int width = m_pWidget->width();
            int height = m_pWidget->height();
            //缓存各各区域的值
            m_qRect_Left = QRect(0, m_nPadding, m_nPadding, height - m_nPadding * 2);

            m_qRect_Top = QRect(m_nPadding, 0, width - m_nPadding * 2, m_nPadding);

            m_qRect_Right = QRect(width - m_nPadding, m_nPadding, m_nPadding, height - m_nPadding * 2);

            m_qRect_Botton = QRect(m_nPadding, height - m_nPadding, width - m_nPadding * 2, m_nPadding);

            m_qRect_Left_Top = QRect(0, 0, m_nPadding, m_nPadding);

            m_qRect_Right_Top = QRect(width - m_nPadding, 0, m_nPadding, m_nPadding);

            m_qRect_Left_Bottom = QRect(0, height - m_nPadding, m_nPadding, m_nPadding);

            m_qRect_Right_Bottom = QRect(width - m_nPadding, height - m_nPadding, m_nPadding, m_nPadding);
        }
        //鼠标在悬停部件内移动（QHoverEvent）
        else if(event->type() == QEvent::HoverMove)
        {
            QHoverEvent *hoverEvent = reinterpret_cast<QHoverEvent*>(event);
            QPoint point = hoverEvent->pos();
            if(m_bResizeEnable)
            {
                //判断点是否在某个区域
                if(m_qRect_Left.contains(point))
                {
                    this->m_pWidget->setCursor(Qt::SizeHorCursor);
                } else if(m_qRect_Right.contains(point))
                {
                    this->m_pWidget->setCursor(Qt::SizeHorCursor);
                } else if(m_qRect_Top.contains(point))
                {
                    this->m_pWidget->setCursor(Qt::SizeVerCursor);
                } else if(m_qRect_Botton.contains(point))
                {
                    this->m_pWidget->setCursor(Qt::SizeVerCursor);
                } else if(m_qRect_Left_Top.contains(point))
                {
                    this->m_pWidget->setCursor(Qt::SizeFDiagCursor);
                } else if(m_qRect_Right_Top.contains(point))
                {
                    this->m_pWidget->setCursor(Qt::SizeBDiagCursor);
                } else if(m_qRect_Left_Bottom.contains(point))
                {
                    this->m_pWidget->setCursor(Qt::SizeBDiagCursor);
                } else if(m_qRect_Right_Bottom.contains(point))
                {
                    this->m_pWidget->setCursor(Qt::SizeFDiagCursor);
                } else {
                    this->m_pWidget->setCursor(Qt::ArrowCursor);
                }
            }
            //根据当前鼠标位置，计算XY轴移动了多少
            int offsetX = point.x() - m_qLastPos.x();
            int offsetY = point.y() - m_qLastPos.y();
            if(m_bMoveEnable)
            {
                if(m_bMouse_Pressed)
                {
                    this->m_pWidget->move(this->m_pWidget->x() + offsetX, this->m_pWidget->y() + offsetY);
                }
            }
            //检测在边距鼠标是否按下
            if(m_bResizeEnable)
            {
                if(m_bMouse_Pressed_Left)
                {
                    int resizeW = this->m_pWidget->width() - offsetX;
                    if(this->m_pWidget->minimumWidth() <= resizeW)
                    {
                        this->m_pWidget->setGeometry(this->m_pWidget->x() + offsetX, m_nRectY, resizeW, m_nRectH);
                    }
                } else if(m_bMouse_Pressed_Right)
                {
                    this->m_pWidget->setGeometry(m_nRectX, m_nRectY, m_nRectW + offsetX, m_nRectH);
                } else if(m_bMouse_Pressed_Top)
                {
                    int resizeH = this->m_pWidget->height() - offsetY;
                    if(this->m_pWidget->minimumHeight() <= resizeH)
                    {
                        this->m_pWidget->setGeometry(m_nRectX, this->m_pWidget->y() + offsetY, m_nRectW, resizeH);
                    }
                } else if(m_bMouse_Pressed_Bottom)
                {
                    this->m_pWidget->setGeometry(m_nRectX, m_nRectY, m_nRectW, m_nRectH + offsetY);
                } else if(m_bMouse_Pressed_Left_Top)
                {
                    int resizeW = this->m_pWidget->width() - offsetX;
                    int resizeH = this->m_pWidget->height() - offsetY;

                    if(this->m_pWidget->minimumWidth() <= resizeW)
                    {
                        this->m_pWidget->setGeometry(this->m_pWidget->x() + offsetX, this->m_pWidget->y(), resizeW, resizeH);
                    }
                    if(this->m_pWidget->minimumWidth() <= resizeH)
                    {
                        this->m_pWidget->setGeometry(this->m_pWidget->x(), this->m_pWidget->y() + offsetY, resizeW, resizeH);
                    }
                } else if(m_bMouse_Pressed_Right_Top)
                {
                    int resizeW = m_nRectW + offsetX;
                    int resizeH = this->m_pWidget->height() - offsetY;
                    if(this->m_pWidget->minimumWidth() <= resizeW)
                    {
                        this->m_pWidget->setGeometry(this->m_pWidget->x(), this->m_pWidget->y(), resizeW, resizeH);
                    }
                    if(this->m_pWidget->minimumHeight() <= resizeH)
                    {
                        this->m_pWidget->setGeometry(this->m_pWidget->x(), this->m_pWidget->y() + offsetY, resizeW, resizeH);
                    }
                }else if(m_bMouse_Pressed_Left_Bottom)
                    {
                        int resizeW = this->m_pWidget->width() - offsetX;
                        int resizeH = m_nRectH + offsetY;
                        if(this->m_pWidget->minimumWidth() <= resizeW)
                        {
                            this->m_pWidget->setGeometry(this->m_pWidget->x() + offsetX, this->m_pWidget->y(), resizeW, resizeH);
                        }
                        if(this->m_pWidget->minimumHeight() <= resizeH)
                        {
                            this->m_pWidget->setGeometry(this->m_pWidget->x(), this->m_pWidget->y(), resizeW, resizeH);
                        }
                    }
                    else if(m_bMouse_Pressed_Right_Bottom)
                    {
                        int resizeW = m_nRectW + offsetX;
                        int resizeH = m_nRectH + offsetY;
                        this->m_pWidget->setGeometry(this->m_pWidget->x(), this->m_pWidget->y(), resizeW, resizeH);
                    }
                }
            } else if(event->type() == QEvent::MouseButtonPress) {
                QMouseEvent *mouseEvent = reinterpret_cast<QMouseEvent*>(event);
                m_nRectX = this->m_pWidget->x();
                m_nRectY = this->m_pWidget->y();
                m_nRectW = this->m_pWidget->width();
                m_nRectH = this->m_pWidget->height();
                m_qLastPos = mouseEvent->pos();

                //判断按下的手柄的区域位置
                if(m_qRect_Left.contains(m_qLastPos))
                {
                    m_bMouse_Pressed_Left = true;
                } else if(m_qRect_Right.contains(m_qLastPos))
                {
                    m_bMouse_Pressed_Right = true;
                } else if(m_qRect_Top.contains(m_qLastPos))
                {
                    m_bMouse_Pressed_Top = true;
                } else if(m_qRect_Botton.contains(m_qLastPos))
                {
                    m_bMouse_Pressed_Bottom = true;
                } else if(m_qRect_Left_Top.contains(m_qLastPos))
                {
                    m_bMouse_Pressed_Left_Top = true;
                } else if(m_qRect_Right_Top.contains(m_qLastPos))
                {
                    m_bMouse_Pressed_Right_Top = true;
                } else if(m_qRect_Left_Bottom.contains(m_qLastPos))
                {
                    m_bMouse_Pressed_Left_Bottom = true;
                } else if(m_qRect_Right_Bottom.contains(m_qLastPos))
                {
                    m_bMouse_Pressed_Right_Bottom = true;
                } else {
                    m_bMouse_Pressed = true;
                }
            } else if(event->type() == QEvent::MouseMove) {

            } else if(event->type() == QEvent::MouseButtonRelease) {
                //恢复所有
                m_bMouse_Pressed = false;
                m_bMouse_Pressed_Left = false;
                m_bMouse_Pressed_Right = false;
                m_bMouse_Pressed_Top = false;
                m_bMouse_Pressed_Bottom = false;
                m_bMouse_Pressed_Left_Top = false;
                m_bMouse_Pressed_Right_Top = false;
                m_bMouse_Pressed_Left_Bottom = false;
                m_bMouse_Pressed_Right_Bottom = false;
                this->m_pWidget->setCursor(Qt::ArrowCursor);
            }
        }
    return QObject::eventFilter(watched, event);
}

void ControlWidget::SetWidget(QWidget *widget)
{
    if(this->m_pWidget == nullptr)
    {
        this->m_pWidget = widget;
        //设置鼠标追踪
        this->m_pWidget->setMouseTracking(true);
        //绑定事件过滤器
        this->m_pWidget->installEventFilter(this);
        //设置悬停为真，必须设置这个，不然当父窗体里边还有子窗体全部遮挡了识别不到MouseMove，需要设别HoverMove
        /*
         * Forces Qt to generate paint events when the mouse enters or leaves the widget.
         * This feature is typically used when implementing custom styles;
         * see the Styles example for details.
        */
        this->m_pWidget->setAttribute(Qt::WA_Hover, true);
        this->m_pWidget->setWindowFlags(Qt::Window |
                                        Qt::FramelessWindowHint |
                                        Qt::Tool);
    }
}

void ControlWidget::SetPadding(int padding)
{
    this->m_nPadding = padding;
}

void ControlWidget::SetMoveEnable(bool moveenable)
{
    this->m_bMoveEnable = moveenable;
}

void ControlWidget::SetResizeEnable(bool resizeenable)
{
    this->m_bResizeEnable = resizeenable;
}
