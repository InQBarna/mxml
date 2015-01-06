//  Created by Alejandro Isaza on 2014-05-05.
//  Copyright (c) 2014 Venture Media Labs. All rights reserved.

#pragma once
#include "Geometry.h"
#include "NoteGeometry.h"
#include "TieGeometry.h"
#include "PartGeometry.h"

#include <mxml/dom/Note.h>

#include <map>
#include <memory>
#include <vector>

namespace mxml {

using std::map;
using std::pair;
using std::unique_ptr;
using std::vector;

class TieGeometryFactory {
public:
    static const coord_t kTieSpacing;
    
public:
    explicit TieGeometryFactory(const PartGeometry& partGeometry);
    
    vector<unique_ptr<TieGeometry>>&& buildTieGeometries(const vector<unique_ptr<Geometry>>& geometries);
    
private:
    void createGeometries(const vector<unique_ptr<Geometry>>& geometries);
    void createGeometriesFromNotes(const vector<unique_ptr<NoteGeometry>>& notes);
    void createGeometriesFromNotes(const vector<NoteGeometry*>& notes);
    void createGeometryFromNote(const NoteGeometry& noteGeometry);
    std::unique_ptr<TieGeometry> buildTieGeometry(const NoteGeometry* startGeom, const NoteGeometry* stopGeom, const dom::Optional<dom::Placement>& placement);
    std::unique_ptr<TieGeometry> buildSlurGeometry(const NoteGeometry* startGeom, const NoteGeometry* stopGeom, const dom::Optional<dom::Placement>& placement);
    
private:
    const PartGeometry& _partGeometry;

    vector<unique_ptr<TieGeometry>> _tieGeometries;
    map<std::pair<int, int>, const NoteGeometry*> _slurStartGeometries;
    
    typedef std::pair<int, const dom::Pitch*> PitchKey;
    struct PitchComparator {
        bool operator()(const PitchKey& a, const PitchKey& b) const {
            if (a.first < b.first)
                return true;
            
            if (a.first > b.first)
                return false;
            
            if (a.second->step() < b.second->step())
                return true;
            
            if (a.second->step() > b.second->step())
                return false;
            
            return a.second->octave() < b.second->octave();
        }
    };
    map<PitchKey, const NoteGeometry*, PitchComparator> _tieStartGeometries;
};

} // namespace mxml
