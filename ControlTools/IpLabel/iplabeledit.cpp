#include "iplabeledit.h"
#include <QLabel>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QVBoxLayout>
#include <QEvent>
#include <QKeyEvent>

#include <QDebug>

IpLabelEdit::IpLabelEdit(QWidget *parent) : QWidget(parent)
{
    m_qBorderColor.setNamedColor("#FFFFFF");
    m_qBackGroundColor.setNamedColor("#A6B5B8");
    m_nBorderRadius = 3;
    m_qFrame = nullptr;
    verticalLayout = nullptr;
    layout = nullptr;
    m_qFont.setFamily("wenquanyi");
    m_qFont.setBold(false);
    m_qFont.setPointSize(10);
    m_qTextColor.setNamedColor("#000000");

    //2.创建ip组件
    SetStyleSheet();
}

IpLabelEdit::~IpLabelEdit()
{

}

QString IpLabelEdit::GetIp() const
{
    return m_qIp;
}

QColor IpLabelEdit::GetBackGroundColor() const
{
    return m_qBackGroundColor;
}

QColor IpLabelEdit::GetBorderColor() const
{
    return m_qBorderColor;
}

QColor IpLabelEdit::GetTextColor() const
{
    return m_qTextColor;
}

int IpLabelEdit::GetBorderRadius() const
{
    return m_nBorderRadius;
}

QFont IpLabelEdit::GetTextFont() const
{
    return m_qFont;
}


void IpLabelEdit::SetIp(const QString &ip)
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
        if(m_qTextIp.size() == 4)
        {
            for(int i = 0; i < 4; i++)
            {
                m_qTextIp[i]->setText(list.at(i));
            }
        }
    }
}

void IpLabelEdit::Clear()
{
    for(int i = 0; i < 4; i++)
    {
        m_qTextIp[i]->clear();
    }
    m_qTextIp[0]->setFocus();
}

void IpLabelEdit::SetBackGroundColor(const QColor &backgroundcolor)
{
    if(this->m_qBackGroundColor != backgroundcolor)
    {
        this->m_qBackGroundColor = backgroundcolor;
        SetStyleSheet();
    }
}

void IpLabelEdit::SetBorderColor(const QColor &bordercolor)
{
    if(this->m_qBorderColor != bordercolor)
    {
        this->m_qBorderColor = bordercolor;
        SetStyleSheet();
    }
}

void IpLabelEdit::SetBorderRadius(const int &borderradius)
{
    if(this->m_nBorderRadius != borderradius)
    {
        this->m_nBorderRadius = borderradius;
        SetStyleSheet();
    }
}

void IpLabelEdit::SetTextColor(const QColor &textPalette)
{
    if(this->m_qTextColor != textPalette)
    {
        this->m_qTextColor = textPalette;
        SetStyleSheet();
    }

}


void IpLabelEdit::SetTextFont(const QFont &textfont)
{
    if(m_qFont != textfont)
    {
        this->m_qFont = textfont;
        SetStyleSheet();
    }
}


bool IpLabelEdit::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QLineEdit *txt = reinterpret_cast<QLineEdit *>(watched);
        if (txt == m_qTextIp[0] || txt == m_qTextIp[1] || txt == m_qTextIp[2] || txt == m_qTextIp[3]) {
            QKeyEvent *key = reinterpret_cast<QKeyEvent *>(event);
            //如果当前按下了小数点则移动焦点到下一个输入框
            if (key->text() == ".") {
                this->focusNextChild();
            }
            //如果按下了退格键并且当前文本框已经没有了内容则焦点往前移
            if (key->key() == Qt::Key_Backspace) {
                if (txt->text().length() <= 1 && txt != m_qTextIp[0]) {
                    this->focusNextPrevChild(false);
                }
            }
        }
    }
    return QWidget::eventFilter(watched, event);
}

void IpLabelEdit::SetStyleSheet()
{

    for(int i = 0; i < m_qTextIp.size(); i++)
    {
        if(m_qTextIp[i] != nullptr)
        {
            delete m_qTextIp[i];
            m_qTextIp[i] = nullptr;
        }
    }
    m_qTextIp.clear();
    for(int i = 0; i < m_qCircleDot.size(); i++)
    {
        if(m_qCircleDot[i] != nullptr)
        {
            delete m_qCircleDot[i];
            m_qCircleDot[i] = nullptr;
        }
    }
    m_qCircleDot.clear();

    if(verticalLayout != nullptr)
    {
        delete verticalLayout;
        verticalLayout = nullptr;
    }

    if(layout != nullptr)
    {
        delete layout;
        layout = nullptr;
    }

    if(m_qFrame != nullptr)
    {
        delete m_qFrame;
        m_qFrame = nullptr;
    }

    //设置IP地址校验过滤
    QRegExp regExp("(2[0-5]{2}|2[0-4][0-9]|1?[0-9]{1,2})");
    QRegExpValidator *validator = new QRegExpValidator(regExp, this);
    for(int i = 0; i < 4; i++)
    {

        QLineEdit *ip = new QLineEdit;
        ip->setObjectName(QString("ip%1").arg(i));
        ip->setAlignment(Qt::AlignCenter);
        ip->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        ip->setValidator(validator);
        ip->installEventFilter(this);
        ip->setFont(m_qFont);
        QPalette palette;
        palette.setColor(QPalette::Text, m_qTextColor);
        ip->setPalette(palette);
        connect(ip, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));
        m_qTextIp.push_back(ip);
        //圆点
        if(i <= 2)
        {
            QLabel *dot = new QLabel;
            dot->setAlignment(Qt::AlignCenter);
            dot->setText(".");
            dot->setFont(m_qFont);
            //palette.setColor(Qt::WindowText)
            dot->setPalette(palette);
            m_qCircleDot.push_back(dot);
        }
    }

    m_qFrame = new QFrame;
    m_qFrame->setObjectName("ipframe");
    QStringList qss;
    qss.append(QString("QFrame#ipframe{border:1px solid%1; border-radius:%2px; background:%3;}").arg(m_qBorderColor.name()).arg(m_nBorderRadius).arg(m_qBackGroundColor.name()));
    qss.append(QString("QLabel{min-width:15px;background: transparent;}"));
    qss.append(QString("QLineEdit{background: transparent;border:none;}"));
    qss.append(QString("QLineEdit#ip0{border-top-left-radius:%1px;border-bottom-left-radius:%1px;}").arg(m_nBorderRadius));
    qss.append(QString("QLineEdit#ip4{border-top-right-radius:%1px;border-bottom-right-radius:%1px;}").arg(m_nBorderRadius));
    m_qFrame->setStyleSheet(qss.join(""));

    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setMargin(0);
    verticalLayout->setSpacing(0);
    verticalLayout->addWidget(m_qFrame);

    //将控件按照横向布局排列
    layout = new QHBoxLayout(m_qFrame);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(m_qTextIp[0]);
    layout->addWidget(m_qCircleDot[0]);
    layout->addWidget(m_qTextIp[1]);
    layout->addWidget(m_qCircleDot[1]);
    layout->addWidget(m_qTextIp[2]);
    layout->addWidget(m_qCircleDot[2]);
    layout->addWidget(m_qTextIp[3]);
}

void IpLabelEdit::textChanged(const QString &text)
{
    int len = text.length();
    int value = text.toInt();
    //判断当前是否输入完成一个网段,是的话则自动移动到下一个输入框
    if (len == 3) {
        if (value >= 100 && value <= 255) {
            if(!m_qTextIp[3]->hasFocus())
            {
                this->focusNextChild();
            }
        }
    }
    //拼接成完整IP地址
    this->m_qIp = QString("%1.%2.%3.%4").arg(m_qTextIp[0]->text())
                                        .arg(m_qTextIp[1]->text())
                                        .arg(m_qTextIp[2]->text())
                                        .arg(m_qTextIp[3]->text());
}
