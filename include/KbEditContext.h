#ifndef KBEDITCONTEXT_H
#define KBEDITCONTEXT_H

#include <qstring.h>

class KbEditContext
{
	uint fix[5];
public:
    ~KbEditContext(); 

    static KbEditContext * instance();

    void startKbServer();
    void connectKbServer();

    static void appExit(void);
    static bool isShareMemValid;
    void   saveFieldInputMode();

    bool isUADEnabled()const;
    void setUADEnabled(bool enable);
 
    bool isCompletionEnabled()const;
    void setCompletionEnabled(bool enable);

    QString getDefaultInputLang();
    void setDefaultInputLang(const QString& langCode);

    QString getFieldInputLang(int fieldType);
    void setFieldInputLang(int fieldType, const QString& langCode);

    QUuid getFieldInputMode(int fieldType);
    void setFieldInputMode(int fieldType, const QUuid& mode);

public:
    void loadCompletionSetting();
    void loadModeCycle();

protected:
    KbEditContext();
}; 

#endif
