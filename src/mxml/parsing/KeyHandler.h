// Copyright © 2016 Venture Media Labs.
//
// This file is part of mxml. The full mxml copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "BaseRecursiveHandler.h"
#include "IntegerHandler.h"
#include "StringHandler.h"

#include <mxml/dom/Key.h>

namespace mxml {

class KeyHandler : public lxml::BaseRecursiveHandler<std::unique_ptr<dom::Key>> {
public:
    void startElement(const lxml::QName& qname, const AttributeMap& attributes);
    RecursiveHandler* startSubElement(const lxml::QName& qname);
    void endSubElement(const lxml::QName& qname, RecursiveHandler* parser);
    
    static dom::Key::Mode modeFromString(const std::string& string);
    
private:
    lxml::IntegerHandler _integerHandler;
    lxml::StringHandler _stringHandler;
};

} // namespace mxml
