#ifndef MYWIDGETPLUGIN_H
#define MYWIDGETPLUGIN_H

#include <QtCore/QObject>

#if QT_VERSION >= 0x050000
#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#else
#include <QtDesigner/QDesignerCustomWidgetInterface>
#endif

class MyWidgetPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetCollectionInterface")
#endif
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
