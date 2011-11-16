#ifndef ZKBCONFIG_H
#define ZKBCONFIG_H

#include <quuid.h>
#include <qstring.h>
#include <qstringlist.h>

class ZKbConfig
{
public:
    static bool getInputLangList(QStringList&, QStringList&);
    static bool getDefaultInputLang(QString&);
    static bool setDefaultInputLang(const QString&);
    static bool getFieldInputLang(int, QString&);
    static bool getFieldInputMode(int, QUuid&);
    static QString getModeString(const QUuid&, bool&);
    static QStringList /*???*/ getSupportedLangCodeList();
	static bool isInputModeSupported(const QUuid&);
}; 
#endif
