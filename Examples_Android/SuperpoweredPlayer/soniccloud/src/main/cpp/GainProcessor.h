//
// Created by emb on 7/24/2019.
//

#ifndef SCDSP_GAINPROCESSOR_H
#define SCDSP_GAINPROCESSOR_H

class GainProcessor {
private:
    float gain;
public:

    GainProcessor() : gain(0.f) {}

    void process(int numFrames, float* inL, float* inR, float *outL, float *outR) {
        for (int fr=0; fr<numFrames; ++fr) {
            outL[fr] = inL[fr] * gain;
            outR[fr] = inR[fr] * gain;
        }
    }

    void setGain(float val) {
        gain = val;
    }
};

#endif //SCDSP_GAINPROCESSOR_H
