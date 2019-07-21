#include "ScDsp.h"
#include <android/log.h>

// set the user's HL levels from test results.
// @param numPoints: number of points for each ear (e.g., 4 in the current demo)
// @param frequencies: an array of floats representing the tested frequencies in Hz
// @param values: 2 float arrays, one per ear, representing test results per frequency in dBHL
void ScDsp::setAudiogram(int numPoints, float *frequencies, float *values) {

    __android_log_print(ANDROID_LOG_ERROR, "SonicCloudSDK", "setAudiogram");
}

// set the value of an abstract UI parameter.
// (there will only be a small number of these, e.g. "personalization" or "naturalism")
// @param index: parameter index (integer in [0,...N-1])
// @param value: parameter value (float in [0.f, 1.f])
void ScDsp::setParameter(int index, float value) {

    __android_log_print(ANDROID_LOG_ERROR, "SonicCloudSDK", "setParameter");
}

// process a block of audio samples.
// @param numSamples: count of sample frames in this block
// @param in: 2 arrays of const float (pointer-to-pointer); de-interleaved input audio channels for reading
// @param out: 2 arrays of float (pointer-to-pointer); de-interleaved output audio channels for writing
void ScDsp::process(int numSamples, const float *in[2], float *out[2]) {

    __android_log_print(ANDROID_LOG_ERROR, "SonicCloudSDK", "process");
}