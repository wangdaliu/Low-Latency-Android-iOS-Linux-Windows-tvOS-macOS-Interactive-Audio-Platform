#include "ScDsp.h"
#include <android/log.h>

void ScDsp::setAudiogram(int numPoints, float *frequencies, float *leftValues, float *rightValues) {

    __android_log_print(ANDROID_LOG_ERROR, "SonicCloudSDK", "setAudiogram %d", numPoints);
}

void ScDsp::setParameter(int index, float value) {
    if (index == 0) {
        gain.setGain(value);
    }
    __android_log_print(ANDROID_LOG_ERROR, "SonicCloudSDK", "setParameter %f", value);
}

void ScDsp::process(int numSamples, float *inL, float *inR, float *outL, float *outR) {
    gain.process(numSamples, inL, inR, outL, outR);
    __android_log_print(ANDROID_LOG_ERROR, "SonicCloudSDK", "process %d", numSamples);
}