// Copyright © 2016 Venture Media Labs.
//
// This file is part of mxml. The full mxml copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "ArticulationHandler.h"
#include "EmptyPlacementHandler.h"
#include <mxml/dom/InvalidDataError.h>
#include "StringHandler.h"

namespace mxml {

using dom::Articulation;
using lxml::QName;

static const char* kPlacementAttribute = "placement";
const std::string ArticulationHandler::kTagNames[] = {
    "accent",
    "breath-mark",
    "caesura",
    "detached-legato",
    "doit",
    "falloff",
    "other-articulation",
    "plop",
    "scoop",
    "spiccato",
    "staccatissimo",
    "staccato",
    "stress",
    "strong-accent",
    "tenuto",
    "unstress",
    "up-bow",
    "down-bow"
};

void ArticulationHandler::startElement(const QName& qname, const AttributeMap& attributes) {
    _result.reset(new Articulation());
    _result->setType(typeFromString(qname.localName()));
    
    auto placement = attributes.find(kPlacementAttribute);
    if (placement != attributes.end())
        _result->setPlacement(presentOptional(EmptyPlacementHandler::placementFromString(placement->second)));
}

void ArticulationHandler::endElement(const lxml::QName& qname, const std::string& contents) {
    _result->setContents(lxml::StringHandler::trim(contents));
}

Articulation::Type ArticulationHandler::typeFromString(const std::string& string) {
    if (string == "accent") return Articulation::Type::Accent;
    if (string == "breath-mark") return Articulation::Type::BreathMark;
    if (string == "caesura") return Articulation::Type::Caesura;
    if (string == "detached-legato") return Articulation::Type::DetachedLegato;
    if (string == "doit") return Articulation::Type::Doit;
    if (string == "falloff") return Articulation::Type::Falloff;
    if (string == "other-articulation") return Articulation::Type::OtherArticulation;
    if (string == "plop") return Articulation::Type::Plop;
    if (string == "scoop") return Articulation::Type::Scoop;
    if (string == "spiccato") return Articulation::Type::Spiccato;
    if (string == "staccatissimo") return Articulation::Type::Staccatissimo;
    if (string == "staccato") return Articulation::Type::Staccato;
    if (string == "stress") return Articulation::Type::Stress;
    if (string == "strong-accent") return Articulation::Type::StrongAccent;
    if (string == "tenuto") return Articulation::Type::Tenuto;
    if (string == "unstress") return Articulation::Type::Unstress;
    if (string == "up-bow") return Articulation::Type::UpBow;
    if (string == "down-bow") return Articulation::Type::DownBow;
    if (string == "fingering") return Articulation::Type::Fingering;
    if (string == "string") return Articulation::Type::Fingering;
    throw dom::InvalidDataError("Invalid articulation type " + string);
}

} // namespace mxml
