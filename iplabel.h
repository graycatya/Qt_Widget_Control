#ifndef IPLABEL_H
#define IPLABEL_H

/*
 * Ip输入框 作者:Graycatya(graycatya@163.com)
*/

#include <QWidget>
#include <QVector>

class QLabel;
class QLineEdit;

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif
class QDESIGNER_WIDGET_EXPORT IpLabel : public QWidget
#else
class IpLabel : public QWidget
#endif
{
    Q_OBJECT
public:
    IpLabel(QWidget *parent = 0);
    //~IpLabel();

    QString GetIp( void ) const;
    QSize   GetSizeHint( void ) const;
    QSize   GetMinmumSizeHint( void ) const;


public Q_SLOTS:
    void SetIp(const QString &ip);
    void Clear();
    void SetBackGroundColor(const QColor &backgroundcolor);
    void SetBorderRadius(const QColor &borderradius);


protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void textChanged(const QString &text);

private:
    QString m_qIp;                      //Ip地址存储
    QColor  m_qBackGroundColor;         //背景颜色
    QColor  m_qBorderColor;             //边框颜色
    int     m_nBorderRadius;            //边框圆角度
    QVector<QLabel*> m_qCircleDot;      //圆点
    QVector<QLineEdit*> m_qTextIp;      //输入框
    //QWidget *m_qWidget;                 //输入窗


};

#endif // IPLABEL_H
