#include "controlwidget.h"

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
