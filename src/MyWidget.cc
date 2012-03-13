#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    resize(100, 100);
    setMinimumWidth(100);
    setMinimumHeight(100);

    gbox = new QGroupBox("Position", this);

    label_x = new QLabel("<value>");
    label_y = new QLabel("<value>");
    label_z = new QLabel("<value>");
    
    l1 = new QLabel("x:");
    l2 = new QLabel("y:");
    l3 = new QLabel("z:");
    
    flay = new QFormLayout(gbox);
    flay->addRow(l1, label_x);
    flay->addRow(l2, label_y);
    flay->addRow(l3, label_z);
    
    gbox->setLayout(flay);
    
    show();
}

MyWidget::~MyWidget()
{
    delete label_x;
    delete label_y;
    delete label_z;
    delete l1;
    delete l2;
    delete l3;
    delete gbox;
    delete flay;
}

base::samples::RigidBodyState MyWidget::getPose()
{
    return pose;
}

void MyWidget::setPose(const base::samples::RigidBodyState pose)
{
    this->pose = pose;
    
    label_x->setText(QString::number(pose.position[0]));
    label_y->setText(QString::number(pose.position[1]));
    label_z->setText(QString::number(pose.position[2]));
    update();
}
