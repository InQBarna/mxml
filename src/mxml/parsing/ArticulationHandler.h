// Copyright © 2016 Venture Media Labs.
//
// This file is part of mxml. The full mxml copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "BaseRecursiveHandler.h"
#include "EmptyPlacementHandler.h"
#include <mxml/dom/Articulation.h>

#include <string>

namespace mxml {

class ArticulationHandler : public lxml::BaseRecursiveHandler<std::unique_ptr<dom::Articulation>> {
public:
    static const std::string kTagNames[];
    
public:
    void startElement(const lxml::QName& qname, const lxml::RecursiveHandler::AttributeMap& attributes);
    void endElement(const lxml::QName& qname, const std::string& contents);
    
    static dom::Articulation::Type typeFromString(const std::string& string);
    
private:
    EmptyPlacementHandler _emptyPlacementHandler;
};

} // namespace mxml
