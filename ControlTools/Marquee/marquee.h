#ifndef MARQUEE_H
#define MARQUEE_H

/*
 * 文字滚动(不卡版)此控件不可在arm平台运行(此控件消耗cpu) 作者:Graycatya(graycatya@163.com)
 * 1:设置字体
 * 2:设置字体颜色
 * 3:添加跑马灯字符串
 * 4:设置跑马灯字符串组
 * 5:设置跑马灯速度
*/

/*
 * 1.根据字符串自动设置宽度和高度
 * 2.速度分3级 慢速，普通速度，快速
 * 3.可切换跑马灯内容
 * 4.长字符串使用分割处理
 * 注意:跑马灯是一个消耗CPU的控件，如需使用性能级的跑马灯建议使用qml，
 * 不推荐使用openglwidget因为它的渲染引擎是用了QOpenGLPaintDevice优化上没有qml的渲染引擎Qt Scene Grap好
*/

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <QString>
#include <QVector>
#include <QMap>
#include <QThread>
#include <QTimer>
#include <QMutex>
#include <QWaitCondition>
#include "ThreadPool/ThreadPool.h"


class Marquee : public QWidget
{
    Q_OBJECT
    Q_ENUMS(SPEED)
public:
    enum SPEED
    {
        Slow,
        Secondary,
        Quick
    };

    Marquee(QWidget *parent = nullptr);
    ~Marquee();
	
	//设置字体
    void SetFont(QFont font);
    //设置字体颜色
	void SetColor(QString Color);
    //添加跑马灯字符串
	void AddText(QString text);
    //设置跑马灯字符串组
	void SetTexts(QVector<QString> texts);
    //设置跑马灯速度
    void SetSpeed(SPEED speed);
	
	//启动跑马灯
    void Start( int index = 0 );
    //停止跑马灯
	void Stop( void );

private:
    //更新 - 字符串
    void Update_Marquee(QString str);
    void Delete_Marquee( void );

protected:

private:
    struct Marquee_StackedWidgets
    {
        QWidget* MarqueeWidget = nullptr;
        QVBoxLayout* VerticalLayout = nullptr;
        QStackedWidget* StackedWidget = nullptr;
    };
    struct Marquee_StackedWidget
    {
        QWidget* Widget = nullptr;
        QLabel* Label = nullptr;
    };

    //SPEED m_ySpeed;                     //跑马灯速度

    ThreadPool* m_pThreadPool;          //线程池 - 用来刷新界面切换时间
    bool m_bThreadStart;                //线程启动标志位
    QMutex m_qThreadMutex;              //锁 与 条件变量配合使用
    QWaitCondition m_qThreadCondition;

    //核心控件 - 跑马灯核心
    QStackedWidget *m_pStackedWidget;
    QHBoxLayout *m_pHorizontalLayout;

    //每个跑马等都分配一个StackedWidget
    QMap<QString, Marquee_StackedWidgets*> m_qMarqueeStackedWidgets;


    //跑马灯的位图分配
    QMap<QString, QVector<Marquee_StackedWidget*>> m_qMarqueeStackedWidget;


    //储存跑马灯要显示的内容
    QVector<QString> m_vMarquee_Texts;
    int m_nIndexMarquee;
    int m_nIndexMarqueeSeat;
    int m_nMarqueeSpeen;


    //字体属性， 字体颜色 
    QFont m_qFont;
    QString m_qColor;

    //核心 - 字符长度所占位素
    //int m_nWidget;
    //int m_nHeight;


signals:
    void Update_Marquee_Signal();

public slots:
    void Update_Marquee_Slot();
};

#endif // MARQUEE_H
