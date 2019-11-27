#ifndef PROGRESSARC_H
#define PROGRESSARC_H

/*
 * 圆形进度条 作者:Graycatya(graycatya@163.com)
 * 1:设置字体
 * 2:线条颜色
 * 3:边框宽度
 * 4:边框颜色
 * 5:背景颜色
 * 6:手动设置参数
*/

#include <QWidget>
#include <QTimer>

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif
class QDESIGNER_WIDGET_EXPORT ProgressArc : public QWidget
#else
class ProgressArc : public QWidget
#endif
{
    Q_OBJECT
    Q_PROPERTY(int m_plineWidth READ GetLineWidth WRITE SetLineWidth)
    Q_PROPERTY(QColor m_plineColor READ GetLineColor WRITE SetLineColor)
    Q_PROPERTY(int m_pborderWidth READ GetBorderWidth WRITE SetBorderWidth)
    Q_PROPERTY(QColor m_pborderColor READ GetBorderColor WRITE SetBorderColor)
    Q_PROPERTY(QColor m_pbgColor READ GetBgColor WRITE SetBgColor)
    Q_PROPERTY(int m_yvalue READ GetValue WRITE SetValue)
    Q_PROPERTY(bool m_bCortoon READ GetCortoon WRITE SetCortoon)

public:
    explicit ProgressArc(QWidget *parent = nullptr);
    ~ProgressArc();

protected:
    void paintEvent(QPaintEvent *event);
    void drawProress(QPainter *painter);

private:
    int     m_plineWidth;   //线条宽度
    QColor  m_plineColor;   //线条颜色
    int     m_pborderWidth; //边框宽度
    QColor  m_pborderColor; //边框颜色
    QColor  m_pbgColor;     //背景颜色
    int     m_yvalue;       //当前值

    int     m_yLastValue;
    double  dvalue;
    bool    m_bCortoon;

    QTimer *m_pTimer;

public:
    int GetLineWidth()      const;
    QColor GetLineColor()   const;
    int GetBorderWidth()    const;
    QColor GetBorderColor() const;
    QColor GetBgColor()     const;
    int GetValue()          const;
    bool GetCortoon()       const;




signals:
    void ProgressOutSlot();

public Q_SLOT:
    void SetLineWidth(int linewidth);
    void SetLineColor(const QColor &color);
    void SetBorderWidth(int borderwidth);
    void SetBorderColor(const QColor &bordercolor);
    void SetBgColor(const QColor &bgcolor);
    void SetValue(int value);
    void SetCortoon(bool cortoon);

public slots:
    void Update_Value(int value);

private slots:
    void Update_Cortoon();

};

#endif // PROGRESSARC_H
