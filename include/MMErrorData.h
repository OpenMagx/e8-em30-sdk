

// Copyright (c) 20-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMERRORDATA_H 
#define MMERRORDATA_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "MMEventData.h"
#include "MMEvent.h"
#include "MMResult.h"

class MMErrorData: public MMEventData
{

public:
    MMErrorData(MMResult errorType);

    ~MMErrorData();

    virtual MMEventData * clone();

    MMResult getErrorType() const;

protected:

private:
    MMResult a_errorType;
};

#endif  

