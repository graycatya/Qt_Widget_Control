#include "progressarc.h"
#include <QPainter>
#include <QDebug>
ProgressArc::ProgressArc(QWidget *parent) : QWidget(parent)
{
    m_yvalue = 0;
    this->dvalue = static_cast<double>(m_yvalue)/100.0 * static_cast<double>(360.0);
    m_pborderWidth = 0;
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(Update_Cortoon()));
}

ProgressArc::~ProgressArc()
{
    if(m_pTimer->isActive())
    {
        m_pTimer->stop();
        delete m_pTimer;
        m_pTimer = nullptr;
    }
}

void ProgressArc::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter paint(this);
    paint.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    drawProress(&paint);
}

void ProgressArc::drawProress(QPainter *painter)
{
    painter->save();

    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);         //侧面
    int radius = side - m_pborderWidth;     //半径 需要减去边宽
    //绘制外圆
    QPen pen;
    pen.setWidth(m_pborderWidth);   //设置外圆线宽
    pen.setColor(m_pborderColor);   //设置外圆颜色

    painter->setPen(m_pborderWidth > 0 ? pen : Qt::NoPen);
    painter->setBrush(m_pbgColor);

    //平移坐标轴中心，等比例缩放
    QRectF rectCircle(-radius, -radius, radius * 2, radius * 2); //-radius 因为上一步平移剧中了所以需要回退
    painter->translate(width / 2, height / 2);  //平移坐标到控件中心
    painter->scale(0.5, 0.5); //改变qpainter的刻度长度
    painter->drawEllipse(rectCircle);   //绘制椭圆

    //绘制圆弧进度
    pen.setWidth(m_plineWidth); //设置线宽
    pen.setColor(m_plineColor);
    painter->setPen(pen);

    int offset = radius - m_plineWidth - 5; //计算补偿距离
    QRectF rectArc(-offset, -offset, offset * 2, offset * 2);
    int startAngle = 85 * 16;   //圆弧起始位置
    int spanAngle = static_cast<int>(-this->dvalue) * 16;  //圆弧结束位置
    painter->drawArc(rectArc, startAngle, spanAngle);

    //绘制进度文字
    QFont font;
    font.setPixelSize(static_cast<int>(static_cast<double>(offset) * 0.7));
    painter->setFont(font);
    QString strValue = QString("%1%").arg((this->dvalue/360.0)*100);
    painter->drawText(rectCircle, Qt::AlignCenter, strValue);

    painter->restore();
}

int ProgressArc::GetLineWidth() const
{
    return m_plineWidth;
}

QColor ProgressArc::GetLineColor() const
{
    return m_plineColor;
}

int ProgressArc::GetBorderWidth() const
{
    return m_pborderWidth;
}

QColor ProgressArc::GetBorderColor() const
{
    return m_pborderColor;
}

QColor ProgressArc::GetBgColor() const
{
    return m_pbgColor;
}

int ProgressArc::GetValue() const
{
    return this->m_yvalue;
}

bool ProgressArc::GetCortoon() const
{
    return m_bCortoon;
}

void ProgressArc::SetLineWidth(int linewidth)
{
    m_plineWidth = linewidth;
    repaint();
}

void ProgressArc::SetLineColor(const QColor &color)
{
    m_plineColor = color;
    repaint();
}

void ProgressArc::SetBorderWidth(int borderwidth)
{
    m_pborderWidth = borderwidth;
    repaint();
}

void ProgressArc::SetBorderColor(const QColor &bordercolor)
{
    m_pborderColor = bordercolor;
    repaint();
}

void ProgressArc::SetBgColor(const QColor &bgcolor)
{
    m_pbgColor = bgcolor;
    repaint();
}

void ProgressArc::SetValue(int value)
{
    if(!m_bCortoon)
    {
        m_yvalue = value;
        this->dvalue = static_cast<double>(m_yvalue)/100.0 * static_cast<double>(360.0);
    } else {
        if(m_pTimer->isActive())
        {
            //m_yLastValue = m_yvalue;
            m_yvalue = value;
        } else {
            m_yLastValue = m_yvalue;
            m_yvalue = value;
            m_pTimer->start(10);
        }
    }
    repaint();
}

void ProgressArc::SetCortoon(bool cortoon)
{
    this->m_bCortoon = cortoon;
}

void ProgressArc::Update_Value(int value)
{
    if(!m_bCortoon)
    {
        m_yvalue = value;
        this->dvalue = static_cast<double>(m_yvalue)/100.0 * static_cast<double>(360.0);
    } else {
        if(m_pTimer->isActive())
        {
            //m_yLastValue = m_yvalue;
            m_yvalue = value;
        } else {
            m_yLastValue = m_yvalue;
            m_yvalue = value;
            m_pTimer->start(10);
        }
    }
    repaint();
}

void ProgressArc::Update_Cortoon()
{
    if(m_yLastValue <= m_yvalue)
    {
        this->dvalue = static_cast<double>(m_yLastValue)/100.0 * static_cast<double>(360.0);
        if(m_yLastValue < m_yvalue)
        {
            m_yLastValue++;
        }
    } else if(m_yLastValue >= m_yvalue){
        this->dvalue = static_cast<double>(m_yLastValue)/100.0 * static_cast<double>(360.0);
        if(m_yLastValue > m_yvalue)
        {
            m_yLastValue--;
        }
    } else {
        m_pTimer->stop();
    }
    //qDebug() << "...";
    repaint();
}
