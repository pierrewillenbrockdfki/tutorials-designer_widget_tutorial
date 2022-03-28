#ifndef MYWIDGETPLUGIN_H
#define MYWIDGETPLUGIN_H

#include <QtUiPlugin/QDesignerCustomWidgetInterface>

class MyWidgetPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.dfki-rock-tutorial")
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    MyWidgetPlugin(QObject *parent = 0);
    virtual ~MyWidgetPlugin();

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget* createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool initialized; 
};

#endif /* MYWIDGETPLUGIN_H */  
