// Copyright © 2016 Venture Media Labs.
//
// This file is part of mxml. The full mxml copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "BaseRecursiveHandler.h"
#include "DoubleHandler.h"

#include <mxml/dom/Scaling.h>

namespace mxml {

class ScalingHandler : public lxml::BaseRecursiveHandler<dom::Scaling> {
public:
    RecursiveHandler* startSubElement(const lxml::QName& qname);
    void endSubElement(const lxml::QName& qname, lxml::RecursiveHandler* parser);
    
private:
    lxml::DoubleHandler _doubleHandler;
};

} // namespace mxml
