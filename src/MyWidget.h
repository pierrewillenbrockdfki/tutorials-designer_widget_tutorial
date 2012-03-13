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
    base::samples::RigidBodyState getPose();
    void setPose(const base::samples::RigidBodyState pose);
    
private:
    base::samples::RigidBodyState pose;
    
    QGroupBox* gbox;
    QFormLayout* flay;
    
    QLabel* label_x;
    QLabel* label_y;
    QLabel* label_z;
    
    QLabel* l1;
    QLabel* l2;
    QLabel* l3;
    
};

#endif /* MYWIDGET_H */
