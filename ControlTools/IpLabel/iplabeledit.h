#ifndef IPLABELEDIT_H
#define IPLABELEDIT_H

/*
 * IP输入框控件 作者:greycatya(greycatya@163.com)
 * 1:可设置IP地址,自动填入框
 * 2:可清空IP地址
 * 3:支持退格键自动切换
 * 4:支持IP地址过滤
 * 6:可设置背景,边框颜色
 * 7:可设置圆角,字体设置
*/

#include <QWidget>
#include <QVector>

class QLabel;
class QLineEdit;
class QFrame;
class QVBoxLayout;
class QHBoxLayout;

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif
class QDESIGNER_WIDGET_EXPORT IpLabelEdit : public QWidget
#else
class IpLabelEdit : public QWidget
#endif
{
    Q_OBJECT
    Q_PROPERTY(QString m_qIp READ GetIp WRITE SetIp)
    Q_PROPERTY(QColor m_qBackGroundColor READ GetBackGroundColor WRITE SetBackGroundColor)
    Q_PROPERTY(QColor m_qBorderColor READ GetBorderColor WRITE SetBorderColor)
    Q_PROPERTY(QFont m_qFont READ GetTextFont WRITE SetTextFont)
    Q_PROPERTY(QColor m_qTextColor READ GetTextColor WRITE SetTextColor)
    Q_PROPERTY(int m_nBorderRadius READ GetBorderRadius WRITE SetBorderRadius)

public:
    explicit IpLabelEdit(QWidget *parent = nullptr);
    ~IpLabelEdit();

    QString GetIp( void ) const;
    QColor GetBackGroundColor( void ) const;
    QColor GetBorderColor( void ) const;
    QColor GetTextColor( void ) const;
    int    GetBorderRadius( void ) const;
    QFont  GetTextFont( void ) const;

public Q_SLOTS:
    void SetIp(const QString &ip);
    void Clear();
    void SetBackGroundColor(const QColor &backgroundcolor);
    void SetBorderColor(const QColor &bordercolor);
    void SetBorderRadius(const int &borderradius);
    void SetTextColor(const QColor &textColor);
    void SetTextFont(const QFont &textfont);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    void SetStyleSheet( void );

private slots:
    void textChanged(const QString &text);

private:
    QString             m_qIp;                      //Ip地址存储
    QColor              m_qBackGroundColor;         //背景颜色
    QColor              m_qBorderColor;             //边框颜色
    QFont               m_qFont;                    //设置字体
    QColor              m_qTextColor;               //设置字体颜色
    int                 m_nBorderRadius;            //边框圆角度
    QVector<QLabel*>    m_qCircleDot;               //圆点
    QVector<QLineEdit*> m_qTextIp;                  //输入框
    QFrame              *m_qFrame;                  //样式
    QVBoxLayout         *verticalLayout;
    QHBoxLayout         *layout;
};

#endif // IPLABELEDIT_H
