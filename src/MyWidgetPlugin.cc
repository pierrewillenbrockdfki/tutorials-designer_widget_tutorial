#include "MyWidgetPlugin.h"
#include "MyWidget.h"

#if QT_VERSION < 0x050000
#include <QtPlugin>
Q_EXPORT_PLUGIN2(MyWidget, MyWidgetPlugin)
#endif

MyWidgetPlugin::MyWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

MyWidgetPlugin::~MyWidgetPlugin()
{
}

bool MyWidgetPlugin::isContainer() const
{
    return false;
}

bool MyWidgetPlugin::isInitialized() const
{
    return initialized;
}

QIcon MyWidgetPlugin::icon() const
{
    return QIcon("");
}

QString MyWidgetPlugin::domXml() const
{
        return "<ui language=\"c++\">\n"
            " <widget class=\"MyWidget\" name=\"mywidget\">\n"
            "  <property name=\"geometry\">\n"
            "   <rect>\n"
            "    <x>0</x>\n"
            "    <y>0</y>\n"
            "     <width>300</width>\n"
            "     <height>120</height>\n"
            "   </rect>\n"
            "  </property>\n"
//            "  <property name=\"toolTip\" >\n"
//            "   <string>MyWidget</string>\n"
//            "  </property>\n"
//            "  <property name=\"whatsThis\" >\n"
//            "   <string>MyWidget</string>\n"
//            "  </property>\n"
            " </widget>\n"
            "</ui>\n";
}

QString MyWidgetPlugin::group() const {
    return "MyWidget";
}

QString MyWidgetPlugin::includeFile() const {
    return "MyWidget/MyWidget.h";
}

QString MyWidgetPlugin::name() const {
    return "MyWidget";
}

QString MyWidgetPlugin::toolTip() const {
    return whatsThis();
}

QString MyWidgetPlugin::whatsThis() const
{
    return "MyWidget";
}

QWidget* MyWidgetPlugin::createWidget(QWidget *parent)
{
    return new MyWidget(parent);
}

void MyWidgetPlugin::initialize(QDesignerFormEditorInterface *core)
{
     if (initialized)
         return;
     initialized = true;
}
