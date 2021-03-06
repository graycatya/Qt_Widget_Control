#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void TextProgressArc( void );
    void TextMarquee( void );
    void TextSwitchButton( void );
    void TextIpLabel( void );
    void TextControlWidget( void );

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
