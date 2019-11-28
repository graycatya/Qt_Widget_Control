#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif
class QDESIGNER_WIDGET_EXPORT ControlWidget : public QObject
#else
class ControlWidget : public QObject
#endif
{
    Q_OBJECT
public:
    explicit ControlWidget(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

signals:

public slots:

public Q_SLOTS:
    void SetWidget(QWidget *widget);
    void SetPadding(int padding);
    void SetMoveEnable(bool moveenable);
    void SetResizeEnable(bool resizeenable);

private:
    QWidget *m_pWidget;

    int m_nPadding;                     //边距
    bool m_bMoveEnable;                 //可移动
    bool m_bResizeEnable;               //可拉伸
    bool m_bMouse_Pressed;              //鼠标按下
    bool m_bMouse_Pressed_Left;         //鼠标按下-左
    bool m_bMouse_Pressed_Right;        //鼠标按下-右
    bool m_bMouse_Pressed_Top;          //鼠标按下-上
    bool m_bMouse_Pressed_Bottom;       //鼠标按下-下
    bool m_bMouse_Pressed_Left_Top;     //鼠标按下-左上
    bool m_bMouse_Pressed_Right_Top;    //鼠标按下-右上
    bool m_bMouse_Pressed_Left_Bottom;  //鼠标按下-左下
    bool m_bMouse_Pressed_Right_Bottom; //鼠标按下-右下

    int m_nRectX, m_nRectY, m_nRectW, m_nRectH;     //窗体坐标+宽度
    QPoint m_qLastPos;                              //鼠标按下处坐标

    QRect m_qRect_Left;                             //左侧区域-值缓存
    QRect m_qRect_Right;                            //右侧区域-值缓存
    QRect m_qRect_Top;                              //上侧区域-值缓存
    QRect m_qRect_Botton;                           //下侧区域-值缓存
    QRect m_qRect_Left_Top;                         //左上侧区域-值缓存
    QRect m_qRect_Right_Top;                        //右上侧区域-值缓存
    QRect m_qRect_Left_Bottom;                      //左下侧区域-值缓存
    QRect m_qRect_Right_Bottom;                     //右下侧区域-值缓存

};

#endif // CONTROLWIDGET_H
