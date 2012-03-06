#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    resize(300,120);

    label = new QLabel("Rock 'n Robots!");
    label->setFont(QFont("Verdana", 20));
    label->setAlignment(Qt::AlignCenter);

    QVBoxLayout vbox(this);
    vbox.addWidget(label);
    vbox.setAlignment(Qt::AlignVCenter);

    show();
}

MyWidget::~MyWidget()
{
}

void MyWidget::setPose(const base::samples::RigidBodyState &pose)
{
    QString str;
    QTextStream(&str) << "pose.x: " << pose.position[0];
    label->setText(str);
    update();
}

const QString MyWidget::getLabelText()
{
    return label->text();
}

void MyWidget::setLabelText(const QString &text)
{
    label->setText(text);
    update();
}
