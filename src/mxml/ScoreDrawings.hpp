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

    /**
        Pitch Estimation Curve
     */
    std::vector<std::vector<ScorePitchEstimation>> pitchEstimations() {
        return _pitchEstimations;
    }

    void configurePitchEstimations(std::vector<std::vector<ScorePitchEstimation>> estimations) {
        _pitchEstimations = estimations;
    }
    
    void emptyPitchEstimations() {
        _pitchEstimations.clear();
    }
    
    /**
        Background Curve points
     */
    std::vector<std::vector<ScoreCurvePoint>> curvePoints() {
        return _curvePoints;
    }
    
    void configureCurvePoints(std::vector<std::vector<ScoreCurvePoint>> points) {
        _curvePoints = points;
    }
    
    void emptyCurvePoints() {
        _curvePoints.clear();
    }
    
    float backgroundCurveMax() {
        return _backgroundCurveMax;
    }
    
    void configureBackgroundCurveMaximum(float max) {
        _backgroundCurveMax = max;
    }
    
    /**
        Note Estimation Colorings
     */
    std::vector<std::vector<ScoreNoteEstimation>> noteEstimations() {
        return _noteEstimations;
    }
    
    void configureNoteEstimations(std::vector<std::vector<ScoreNoteEstimation>> estimations) {
        _noteEstimations = estimations;
    }
    
    void emptyNoteEstimations() {
        _noteEstimations.clear();
    }
    
private:
    std::vector<std::vector<ScorePitchEstimation>> _pitchEstimations;
    std::vector<std::vector<ScoreCurvePoint>> _curvePoints;
    std::vector<std::vector<ScoreNoteEstimation>> _noteEstimations;
    float _backgroundCurveMax;
};
