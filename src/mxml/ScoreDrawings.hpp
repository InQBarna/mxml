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
    std::vector<std::shared_ptr<ScorePitchEstimation>> pitchEstimations;
    std::vector<std::shared_ptr<ScoreNoteEstimation>> noteEstimations;
    std::vector<std::shared_ptr<ScoreCurvePoint>> curvePoints;
    float backgroundCurveMax;
};
