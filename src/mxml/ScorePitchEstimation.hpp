//
//  ScorePitchEstimation.hpp
//  MusicKit
//
//  Created by Alexis Katsaprakakis on 15/2/22.
//

#ifndef ScorePitchEstimation_hpp
#define ScorePitchEstimation_hpp

#include <stdio.h>
#include <string>
#include "SpanRectangle.hpp"
#endif /* ScorePitchEstimation_hpp */

class ScorePitchEstimation {
    
public:
    float spanPctFilled;
    SpanRectangle *rect;
    
    int octave;
    double offset;
    std::string note;
    
    float timeInMeasures;
};
