#include "widget.h"
#include "ui_widget.h"
#include "ProgressBar/progressarc.h"
#include "Marquee/marquee.h"
#include "Button/switchbutton.h"
#include "IpLabel/iplabeledit.h"
#include "ControlWidget/controlwidget.h"

#include <QSlider>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //TextProgressArc();
    //TextMarquee();
    //TextSwitchButton();
    //TextIpLabel();
    TextControlWidget();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::TextProgressArc()
{
    QSlider *TestSlider;
    TestSlider = new QSlider(this);
    TestSlider->setObjectName(QString::fromUtf8("TestSlider"));
    TestSlider->setGeometry(QRect(110, 270, 160, 16));
    TestSlider->setMaximum(100);
    TestSlider->setOrientation(Qt::Horizontal);
    ProgressArc *TestArcWidget = new ProgressArc(this);
    TestArcWidget->setGeometry(0,0,95,95);
    TestArcWidget->setMinimumWidth(40);
    TestArcWidget->setMinimumHeight(40);
    TestArcWidget->SetBorderWidth(3);
    TestArcWidget->SetLineWidth(3);
    TestArcWidget->SetLineColor(QColor(Qt::white));
    TestArcWidget->SetBorderColor(QColor(Qt::white));
    TestArcWidget->SetBgColor(QColor(Qt::gray));
    TestArcWidget->SetValue(0);
    TestArcWidget->SetCortoon(true);
    connect(TestSlider, SIGNAL(valueChanged(int)), TestArcWidget, SLOT(Update_Value(int)));
}

void Widget::TextMarquee()
{
    Marquee *marquee = new Marquee(this);
    marquee->setGeometry(100,100, 600, 50);
    marquee->AddText("nokia nokia nokia nokia nokia nokia nokia nokia nokia nokia nokia nokia");
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setBold(true);
    font.setPointSize(50);
    marquee->setFont(font);
    marquee->SetSpeed(Marquee::Quick);
    marquee->Start(0);
}

void Widget::TextSwitchButton()
{
    SwitchButton *m_pBinButton0;
    m_pBinButton0 = new SwitchButton(this);
    m_pBinButton0->SetButtonStyle(SwitchButton::Slide_InCircle);
    m_pBinButton0->setGeometry(0,5,50, 20);
    m_pBinButton0->SetBlockInterval(2);
    m_pBinButton0->SetAnimation(true);
    m_pBinButton0->SetDisable(true);
    m_pBinButton0->SetDisable(false);

    SwitchButton *m_pBinButton1;
    m_pBinButton1 = new SwitchButton(this);
    m_pBinButton1->SetButtonStyle(SwitchButton::Slide_Roundrect);
    m_pBinButton1->setGeometry(60,5,50, 20);
    m_pBinButton1->SetBlockInterval(1);
    m_pBinButton1->SetRectRadius(3);
    m_pBinButton1->SetAnimation(true);

    SwitchButton *m_pBinButton2;
    m_pBinButton2 = new SwitchButton(this);
    m_pBinButton2->SetButtonStyle(SwitchButton::Slide_OutCIrcle);
    m_pBinButton2->setGeometry(0,30,50, 20);
    m_pBinButton2->SetBlockInterval(1);
    m_pBinButton2->SetRectRadius(3);
    m_pBinButton2->SetAnimation(true);

    SwitchButton *m_pBinButton4;
    m_pBinButton4 = new SwitchButton(this);
    m_pBinButton4->SetButtonStyle(SwitchButton::Circle);
    m_pBinButton4->setGeometry(60,30,50, 50);
    m_pBinButton4->SetBlockInterval(1);
    m_pBinButton4->SetRectRadius(3);
    m_pBinButton4->SetAnimation(true);
}

void Widget::TextIpLabel()
{
    IpLabelEdit *iplabeledit = new IpLabelEdit(this);
    iplabeledit->SetBorderRadius(15);
    QColor color;
    color.setNamedColor("#FFFFFF");
    iplabeledit->SetBackGroundColor(color);
    color.setNamedColor("#BEBEBE");
    iplabeledit->SetBorderColor(color);
    iplabeledit->setGeometry(10,10, 200, 30);
    iplabeledit->SetIp("192.168.3.175");

    QColor textcolor;
    textcolor.setNamedColor("#FFFFFF");
    iplabeledit->SetTextColor(textcolor);


    iplabeledit->Clear();

}

void Widget::TextControlWidget()
{
    //QSysInfo::WinVersion ver = QSysInfo::windowsVersion();
    //qDebug() << ver;
    ControlWidget *widget = new ControlWidget(this);
    /*FramelessWidget *widget = new FramelessWidget(this);*/
    this->setMinimumWidth(100);
    this->setMinimumHeight(100);
/*
    Marquee *marquee = new Marquee(this);
    marquee->setGeometry(100,100, 600, 50);
    marquee->AddText("nokia nokia nokia nokia nokia nokia nokia nokia nokia nokia nokia nokia");
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setBold(true);
    font.setPointSize(50);
    marquee->setFont(font);
    marquee->SetSpeed(Marquee::Quick);
    marquee->Start(0);*/

}
