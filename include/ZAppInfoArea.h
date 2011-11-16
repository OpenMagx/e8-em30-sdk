//Fixed for compatibility by Ant-ON, 03.03.2011

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZAPPINFOAREA_H  
#define ZAPPINFOAREA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"
#include <qrect.h>
#include <qsize.h>
#include "ZSkinBase.h"
class QString;
class ZAppInfoAreaPrivate;
class ZFmwArea;
class QPixmap;
class ZFmwItem;
class ZMeterModule;
class QPainter;
class QTimer;

class ZAppInfoArea : public ZWidget
{
    Q_OBJECT
public:

    enum AREA_IDX
    {
        INPUT,      
        ACTIVITY,   
        COUNTER,    
        STORAGE,    
        AREA_NUM    
    };

	#define activity ACTIVITY

    enum COUNTER_MODE
    {
        TWO_VARIABLE_QUALIFIER, 
        ONE_VARIABLE_QUALIFIER, 
        ONE_VARIABLE,           
        FREE                    
    };

    enum COUNTERICON_ALIGN
    {
        LEFT,           
        RIGHT,          
        INVALID_ALIGN   
    };

    enum COUNTER_V
    {
        LEFT_V,     
        RIGHT_V     
    };

    enum ACTIVITY_MODE
    {
        PROGRESS_METER,     
        NO_PROGRESS_METER   
    };

	#define no_progress_meter NO_PROGRESS_METER
	#define progress_meter PROGRESS_METER

    enum METER_STYLE
    {
        METER_A,    
        METER_B     
    };

    ZAppInfoArea(QWidget* parent,
                 const char* name = 0,  WFlags f = 0,
                 const ZSkinService::WidgetClsID clsId =
                 ZSkinService::clsZAppInfoArea);

    bool removeArea(AREA_IDX nAreaIdx);

    bool setStorageIcon(const QString& strResID);

    bool setStorageIcon(const QPixmap& pmap);

    bool setCounterArea(COUNTER_MODE m = FREE);

    bool setCounterIcon(COUNTERICON_ALIGN align, const QString& strResID);

    bool setCounterIcon(COUNTERICON_ALIGN align, const QPixmap& pmap);

    bool removeCounterIcon();

    bool setCounterVariable(COUNTER_V nIdx, const QString& text);

    bool setCounterQualifier(const QString& text);

    bool setActArea(ACTIVITY_MODE m);

    void  setMeterStyle(METER_STYLE s);

    METER_STYLE getMeterStyle();

    bool setInputArea();

    bool insertText(AREA_IDX nAreaIdx,
                    int nItemIdx,
                    const QString& text,
                    const QString& key = QString::null);

    bool insertIcon(AREA_IDX nAreaIdx,
                    int nItemIdx,
                    const QString& strResID,
                    const QString& key = QString::null);

    bool insertIcon(AREA_IDX nAreaIdx,
                    int nItemIdx,
                    const QPixmap& pmap,
                    const QString& key = QString::null);

    bool insertWidget(AREA_IDX nAreaIdx,
                      int nItemIdx,
                      QWidget* pWidget,
                      const QString& key = QString::null);
    bool insertAnimation(AREA_IDX nAreaIdx,
                         int nItemIdx,
                         const QString& strFileName,
                         const QString& key = QString::null);

    bool appendAnimation(AREA_IDX nAreaIdx,
                         const QString& strFileName,
                         const QString& key = QString::null);

    bool appendWidget(AREA_IDX nAreaIdx,
                      QWidget* pWidget,
                      const QString& key = QString::null);

    bool appendText(AREA_IDX nAreaIdx,
                    const QString& text,
                    const QString& key = QString::null);

    bool appendIcon(AREA_IDX nAreaIdx,
                    const QString& strResID,
                    const QString& key = QString::null);

    bool appendIcon(AREA_IDX nAreaIdx,
                    const QPixmap& pmap,
                    const QString& key = QString::null);


    bool removeItem(AREA_IDX nAreaIdx, int nItemIdx);

    bool removeItem(AREA_IDX nAreaIdx, const QString& key);

    bool setIcon(AREA_IDX nAreaIdx, int nItemIdx, const QString& strResID);

    bool setIcon(AREA_IDX nAreaIdx, int nItemIdx, const QPixmap& pmap);

    bool setText(AREA_IDX nAreaIdx, int nItemIdx, const QString& text);

    bool setWidget(AREA_IDX nAreaIdx, int nItemIdx, QWidget* pWidget);

    bool setIcon(AREA_IDX nAreaIdx,
                 const QString& key,
                 const QString& strResID);

    bool setIcon(AREA_IDX nAreaIdx, const QString& key, const QPixmap& pmap);

    bool setText(AREA_IDX nAreaIdx, const QString& key, const QString& text);

    bool setWidget(AREA_IDX nAreaIdx, const QString& key, QWidget* pWidget);

    ZMeterModule* getActMeter();

    void setPalette(const QPalette& pal);

    bool isZEnable();

    int getTotalItemNum();

    void enableOutlineText(bool isEnable);

    bool isOutlineText();

    virtual QSize sizeHint() const;

    ~ZAppInfoArea();

    int getWidth(AREA_IDX nIdx);
    bool printArea(AREA_IDX nIdx);

signals:
    void itemNum(int num);

protected slots:
    void slotHideIconOfInputArea();
protected:
    typedef bool (ZAppInfoArea::*REMOVEICON_FROM_INPUTAREA)(
                                                ZAppInfoArea::AREA_IDX,
                                                ZFmwItem* pItem);

    bool setStorage(const QString& strResID, const QPixmap& pmap);

    bool isValidArea(AREA_IDX nAreaIdx);

    bool isAreaCouldInsertItem(AREA_IDX nAreaIdx);

    ZFmwItem* createIconItem(const QString& strResID,
                             const QString& key = QString::null);

    ZFmwItem* createIconItem(const QPixmap& pmap,
                             const QString& key = QString::null);

    ZFmwItem* createTextItem(const QString& text);

    ZFmwItem* createTextItem(const QString& text, const QString& key);

    ZFmwItem* createWidgetItem(QWidget* pWidget,
                               const QString& key = QString::null);

    bool appendIcon(AREA_IDX nAreaIdx,
                    const QString& strResID,
                    const QPixmap& pmap, const QString& key);

    bool setCounterIcon(COUNTERICON_ALIGN align,
                        const QString& strResID,
                        const QPixmap& pmap);

    int getAreaWidthExceptStorage();

    void setAllAreaWidth();

    int getInitAreaWidth(ZFmwArea* pArea);

    int removeIconFromArea(AREA_IDX nIdx, int& w, REMOVEICON_FROM_INPUTAREA isRemoveIcon);

    int truncateTextFromArea(AREA_IDX nIdx, int& w);

    int cropWidgetFromArea(AREA_IDX nIdx, int& w);

    int deleteArea(AREA_IDX nIdx, int& w);

    void paintBorder(QPainter* p);

    void paintBackground(QPainter* p);
protected:

    bool isHasNewWordIcon();

    bool isRemoveNewWordFromInput(AREA_IDX nIdx, ZFmwItem* pItem);

    bool isRemoveIconFromArea(AREA_IDX nIdx, ZFmwItem* pItem);

    bool scaleArea();

    bool restoreArea();

    virtual void paintEvent(QPaintEvent* );

    void paint(QPainter* p);

    void paintFrame(QPainter* p);

    int getInternalSpacing() const;

    int getSpacing() const;

    void drawInputArea(QPainter* p);

    void drawCounterArea(QPainter* p);

    void drawActivityArea(QPainter* p);

    void drawStorageArea(QPainter* p);

    QRect getRect();

    void drawArea(ZFmwArea* pArea, QPainter* p, const QRect& rect);

    int getAreaWidth(ZFmwArea* pArea) const;

    int getItemHeight(ZFmwItem* pItem) const;

    int getAreaHeight(ZFmwArea* pArea) const;

    int getPadding(int nIdx) const;

    int getContentHeight() const;

    int getWidgetHeight() const;

    void resizeWidget();

    QColor getOutlineColor() const;

    QRect getWidgetRect();
private:
    ZAppInfoAreaPrivate *d;
};
#endif
