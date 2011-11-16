// Fix for Motorola E8 by Ant-ON

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef __ZSKINSERVICE_H__
#define __ZSKINSERVICE_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qlist.h>
#include <qmap.h>
#include <qpixmap.h>
#include <qfile.h>
#include <qapplication.h>
#include <ZWidgetSkinProps.h>
#include <ZConfig.h>

struct SkinInfo
{
    QString name;
    QString dir;
    QPixmap previewPixmap;
};

struct WidgetSkinInfo
{
    QString backgroundPixmapID;
    QString borderPixmapID;
    void* extProps;
};

typedef QList<struct SkinInfo> SkinInfoList;
typedef QListIterator<struct SkinInfo> SkinInfoListIt;
typedef QMap<QString, ZBASIC_SKINNABLE_PROP_T *> ZBasicSkinPropsMap;

class ZConfig;
class QStringList;

class ZSkinService
{
public:
    ZSkinService(const char * app = NULL)
    {
        ref ++;
        if (app)
	    appName = new QCString(app);
        else
            appName = NULL;

	this->screenProps = NULL;

    }

    ~ZSkinService()
    {
        if(appName)
            delete appName;

        ref --;
        if (!ref)
        {
            if (theme)
            {
                delete theme;
                theme = NULL;
            }
            if (device)
            {
                delete device;
                device = NULL;
            }
        }
	if (screenProps)
        {
	    delete screenProps;
	    screenProps = NULL;
        }
    }

    enum WidgetClsID
    {
        clsZAlternatesChooser,
        clsZAlternatesItem,
        clsZAlternatesList,
        clsZAppInfoArea,
        clsZCalendarModule,
        clsZCalendarModule_Day,
        clsZCalendarModule_CurDay,
        clsZCalendarModule_DayHeader,
        clsZCalendarModule_CurDayHeader,
        clsZCalendarModule_EmptyDay,
        clsZCalendarModule_Grid,
        clsZCheckBox,
        clsZColorModule,
        clsZColorModule_Cname,
        clsZColorModule_Well,
        clsZColorPicker,
        clsZColorPicker_Well,
        clsZComboBox,
        clsZDateModule,
        clsZTimeModule = clsZDateModule,
        clsZNumModule = clsZDateModule,
        clsZDatePicker,
        clsZTimePicker = clsZDatePicker,
        clsZNumPicker = clsZDatePicker,
        clsZExhibitButton,
        clsZFiveWayButton1,
        clsZFiveWayButton2,
        clsZFormContainer,
        clsZFormItem,
        clsZGroupBox,
        clsZHeader1,
        clsZHeader2,
        clsZHeader3,
        clsZHeader4,
        clsZHeaderPopup,     
        clsZIconView1,
        clsZIconView2,
        clsZIconViewItem1,
        clsZIconViewItem2,
        clsZInputMatrix,
        clsZInteractiveHighlight,
        clsZJumpBox,
        clsZJumpBox_Field,
        clsZLineEdit,
        clsZListBox1,
        clsZSettingView1 = clsZListBox1,
        clsZListBox2,
        clsZSettingView2 = clsZListBox2,
        clsZListItem1,
        clsZListItem2,
        clsZMatrixItem,
        clsZMeter,
        clsZMeter_Indicator1,
        clsZMeter_Indicator2,
        clsZMeter_Indicator3,
	clsZMeter_Indicator4 = clsZMeter_Indicator3, 
        clsZMeter_Indicator5,   
        clsZMeterModule,
        clsZSliderModule = clsZMeterModule,
        clsZProgressSliderModule = clsZMeterModule,
        clsZMultiLineEdit1,
        clsZMultiLineEdit2,
        clsZNavTabWidget,
	clsZNavTabWidget_TabArea,
        clsZOptionsMenu,
        clsZOptionsMenuItem,
        clsZPanel1,
        clsZPanel2,
        clsZPopup1,
        clsZPopup2,
        clsZPressButton,
        clsZRadioButton,
        clsZScrollPanel,
        clsZScrollView = clsZScrollPanel,
        clsZSegmentField,
        clsZSeparator1,
        clsZSeparator2,
        clsZSettingItem,
        clsZSlider,
        clsZProgressSlider = clsZSlider,
        clsZSoftKeyLeft,
        clsZSoftKeyRight,
	clsZSoftKeyMiddle,
        clsZSplitPane,
        clsZDetailView1,
	clsZDetailView2,
	clsZDetailItem,
	clsZImageContainer,
        clsZImageContainer1,
	clsZImageContainer2,
	clsZMediaControl,
	clsZScrollbar,
	clsZScrollbar_Input,
	clsZScrollbar_Field,
        clsZStructDataImage,
    clsZFieldButton,//for field button
///
//        clsZSearchBox,
//        clsZCLISoftKeyTop,
//        clsZCLISoftKeyBottom,
///
	clsZFsba1,
	clsZFsba2,
        clsMax = clsZFsba2,
        clsTotal = clsMax + 1
    };

    typedef WidgetClsID SkinStyle;

    QString getAppThemeSkinFile( const QString & appName );

    QString getAppDeviceSkinFile( const QString & appName );

    const ZBASIC_SKINNABLE_PROP_T * const getBasicSkinnableProps(
        const enum WidgetClsID clsId ) const;

    void getSkinInfoList( SkinInfoList & list );

    QString getSkinName( const QString &dir = QString::null );

    QFont getSkinFont(const FONT_INFO_T & ftInfo);

    static const struct ZWidgetSkinProps * const getAllSkinnableProps();

    void updateThemeSkin(const QString themeSkinDir = QString::null);

     void updateAppCommonSkin( ZWidgetSkinProps * props );

     void updateAppScreenSkin( QString uScreenCfgName );

     ZWidgetSkinProps * getEntireSkinnableProps();

    int readNumEntryFromSkin(
        ZConfig & device,
        ZConfig & theme,
        const QString & section,
        const QString & tag,
        const int dft = -1 );

    int readNumEntryFromSkin(
        const QString & section,
        const QString & tag,
        const int dft = -1 );

    QString readStringEntryFromSkin(
        ZConfig & device,
        ZConfig & theme,
        const QString & section,
        const QString & tag,
        const QString & dft = QString::null );

    QString readStringEntryFromSkin(
        const QString & section,
        const QString & tag,
        const QString & dft = QString::null );

    QCString getAppName();

    void setAppName(const char * str);

    WidgetSkinInfo getWidgetSkinInfo(const WidgetClsID clsId);

    void updateAppThemeFile(); 

protected:

private:

    ZBASIC_SKINNABLE_PROP_T * internalGetBasicSkinnableProps(
        const enum WidgetClsID clsId,
        ZWidgetSkinProps * pProps = NULL ) const;

    ZConfig* getThemeConfig();
    ZConfig* getDeviceConfig();

    QCString *appName;
    static ZConfig *theme;
    static ZConfig *device;
    static QString oldThemeConfigFileName;
    static int ref;
    ZWidgetSkinProps * screenProps;
};

#endif  
