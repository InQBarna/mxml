// Copyright © 2016 Venture Media Labs.
//
// This file is part of mxml. The full mxml copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "BaseRecursiveHandler.h"
#include <mxml/dom/Turn.h>

namespace mxml {

class TurnHandler : public lxml::BaseRecursiveHandler<std::unique_ptr<dom::Turn>> {
public:
    void startElement(const lxml::QName& qname, const AttributeMap& attributes);
};

} // namespace
