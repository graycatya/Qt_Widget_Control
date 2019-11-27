#pragma execution_character_set("utf-8")

#include "iplabel.h"
#include <QDebug>
#include <QLabel>
#include <QLineEdit>

IpLabel::IpLabel(QWidget *parent) : QWidget(parent)
{
    //0.初始化参数
   /* m_qWidget = nullptr;
    m_qBorderColor.setNamedColor("#FFFFFF");
    m_qBackGroundColor.setNamedColor("#A6B5B8");
    m_nBorderRadius = 3;
    //1.widget
    //m_qWidget = new QWidget(this);
    //m_qWidget->set
    //2.创建ip组件
    for(int i = 0; i < 3; i++)
    {
        QLabel *dot = new QLabel;
        dot->setAlignment(Qt::AlignCenter);
        dot->setText(".");
        m_qCircleDot[i] = dot;
    }
    for(int i = 0; i < 4; i++)
    {
        QLineEdit *ip = new QLineEdit;
        ip->setObjectName(QString("ip%1").arg(i));
        ip->setAlignment(Qt::AlignCenter);
        ip->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        //connect(ip, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));
    }
*/
    //qDebug() << m_qBorderColor.name();
}

QString IpLabel::GetIp() const
{

}

QSize IpLabel::GetSizeHint() const
{

}

QSize IpLabel::GetMinmumSizeHint() const
{

}

/*IpLabel::~IpLabel()
{

}*/

void IpLabel::SetIp(const QString &ip)
{
    QRegExp regexp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
    if(!regexp.exactMatch(ip))
    {
        return;
    }
    if(this->m_qIp != ip)
    {
        this->m_qIp = ip;
        QStringList list = ip.split('.');

    }
}

void IpLabel::SetBackGroundColor(const QColor &backgroundcolor)
{

}

void IpLabel::SetBorderRadius(const QColor &borderradius)
{

}

bool IpLabel::eventFilter(QObject *watched, QEvent *event)
{

}

void IpLabel::textChanged(const QString &text)
{
    text;
}
