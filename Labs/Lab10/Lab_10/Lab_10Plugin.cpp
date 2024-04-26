#include "Song_ui.h"
#include "Lab_10Plugin.h"

#include <QtCore/QtPlugin>

Lab_10Plugin::Lab_10Plugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void Lab_10Plugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool Lab_10Plugin::isInitialized() const
{
    return initialized;
}

QWidget *Lab_10Plugin::createWidget(QWidget *parent)
{
    return new Song_ui(parent);
}

QString Lab_10Plugin::name() const
{
    return "Song_ui";
}

QString Lab_10Plugin::group() const
{
    return "My Plugins";
}

QIcon Lab_10Plugin::icon() const
{
    return QIcon();
}

QString Lab_10Plugin::toolTip() const
{
    return QString();
}

QString Lab_10Plugin::whatsThis() const
{
    return QString();
}

bool Lab_10Plugin::isContainer() const
{
    return false;
}

QString Lab_10Plugin::domXml() const
{
    return "<widget class=\"Song_ui\" name=\"Song_ui\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QString Lab_10Plugin::includeFile() const
{
    return "Song_ui.h";
}
