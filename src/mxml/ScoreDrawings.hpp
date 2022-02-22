//
//  ScoreDrawings.hpp
//  MusicKit
//
//  Created by Alexis Katsaprakakis on 15/2/22.
//

#ifndef ScoreDrawings_hpp
#define ScoreDrawings_hpp

#include <stdio.h>
#include <vector>
#include "ScoreCurvePoint.hpp"
#include "ScorePitchEstimation.hpp"
#include "ScoreNoteEstimation.hpp"

#endif /* ScoreDrawings_hpp */

class ScoreDrawings {
    
public:
    std::vector<ScorePitchEstimation> pitchEstimations() {
        return _pitchEstimations;
    }

    void configurePitchEstimations(std::vector<ScorePitchEstimation> estimations) {
        _pitchEstimations = estimations;
    }
    
    void emptyPitchEstimations() {
        _pitchEstimations.clear();
    }
    
    float backgroundCurveMax() {
        return _backgroundCurveMax;
    }
    
    void configureBackgroundCurveMaximum(float max) {
        _backgroundCurveMax = max;
    }
    
private:
    std::vector<ScorePitchEstimation> _pitchEstimations;
    std::vector<ScoreNoteEstimation> _noteEstimations;
    std::vector<ScoreCurvePoint> _curvePoints;
    float _backgroundCurveMax;
};
