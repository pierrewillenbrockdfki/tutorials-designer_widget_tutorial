#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QGroupBox;
class QFormLayout;
class QLabel;
QT_END_NAMESPACE

#include <base/samples/RigidBodyState.hpp>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent = 0);
    virtual ~MyWidget();
    base::samples::RigidBodyState getPose();
    
public slots:
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
