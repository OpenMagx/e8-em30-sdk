//Change for not warning by Ant-ON

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZOPTMENUPARSER_H
#define PUBLIC_API_WIDGET_ZOPTMENUPARSER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qlist.h>
#include <qstring.h>

typedef enum
{
   STATE1 = 0,      
   STATE2 = 1,      
   STATE3 = 2,      
   STATE4 = 3,      
   STATE5 = 4,      
   STATE6 = 5,      
   STATE7 = 6,      
   STATE8 = 7,      
   STATE9 = -1,    
}ITEM_STATE;

typedef struct MenuItem
 {
     QString ItemText;
     int ItemId;
     int ItemParent;
     ITEM_STATE ItemState;
 }menuItem;

typedef QList<menuItem> itemList;

typedef QListIterator<menuItem> itemListIt;

class ZOptMenuParser
{
public:
   //virtual void getList(itemList & iList, QString screenName)
   virtual void getList(itemList & , QString)
   {
   }
};

#endif  
