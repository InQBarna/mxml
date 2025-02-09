// Copyright © 2016 Venture Media Labs.
//
// This file is part of mxml. The full mxml copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "BaseRecursiveHandler.h"
#include "DoubleHandler.h"

#include <mxml/dom/SystemLayout.h>

#include "SystemDividersHandler.h"
#include "SystemMarginsHandler.h"


namespace mxml {

class SystemLayoutHandler : public lxml::BaseRecursiveHandler<dom::SystemLayout> {
public:
    void startElement(const lxml::QName& qname, const AttributeMap& attributes);
    RecursiveHandler* startSubElement(const lxml::QName& qname);
    void endSubElement(const lxml::QName& qname, RecursiveHandler* handler);

private:
    lxml::DoubleHandler _doubleHandler;
    SystemDividersHandler _systemDividersHandler;
    SystemMarginsHandler _systemMarginsHandler;
};

} // namespace mxml
