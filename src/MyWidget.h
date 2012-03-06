#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtGui>

#include <base/samples/rigid_body_state.h>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent = 0);
    virtual ~MyWidget();
    
public slots:
    void setPose(const base::samples::RigidBodyState &pose);
    const QString getLabelText();
    void setLabelText(const QString &text);
    
    
private:
    QLabel *label;
};

#endif /* MYWIDGET_H */
