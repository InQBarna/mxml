// Copyright © 2016 Venture Media Labs.
//
// This file is part of mxml. The full mxml copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "EmptyPlacement.h"
#include "Node.h"
#include "Optional.h"
#include <string>

namespace mxml {
namespace dom {

class Articulation : public EmptyPlacement {
public:
    enum class Type {
        Accent,
        BreathMark,
        Caesura,
        DetachedLegato,
        Doit,
        Falloff,
        OtherArticulation,
        Plop,
        Scoop,
        Spiccato,
        Staccatissimo,
        Staccato,
        Stress,
        StrongAccent,
        Tenuto,
        Unstress,
        UpBow,
        DownBow,
        Fingering
    };
    
public:
    Articulation() = default;
    Articulation(Type type) : _type(type) {}
    
    Type type() const {
        return _type;
    }
    void setType(Type type) {
        _type = type;
    }
    
    const std::string& contents() const {
        return _contents;
    }
    void setContents(const std::string& contents) {
        _contents = contents;
    }
    
private:
    Type _type;
    std::string _contents;
};

} // namespace dom
} // namespace mxml
