#ifndef ScDsp_h
#define ScDsp_h

class ScDsp {
public:

    ScDsp() {}

    // set the user's HL levels from test results.
    // @param numPoints: number of points for each ear (e.g., 4 in the current demo)
    // @param frequencies: an array of floats representing the tested frequencies in Hz
    // @param leftValues: left ear, representing test results per frequency in dBHL
    // @param rightValues: right ear, representing test results per frequency in dBHL
    void setAudiogram(int numPoints, float *frequencies, float *leftValues, float *rightValues);

    // set the value of an abstract UI parameter.
    // (there will only be a small number of these, e.g. "personalization" or "naturalism")
    // @param index: parameter index (integer in [0,...N-1])
    // @param value: parameter value (float in [0.f, 1.f])
    void setParameter(int index, float value);

    // process a block of audio samples.
    // @param numSamples: count of sample frames in this block
    // @param in: 2 arrays of const float (pointer-to-pointer); de-interleaved input audio channels for reading
    // @param out: 2 arrays of float (pointer-to-pointer); de-interleaved output audio channels for writing
    void process(int numSamples, float *inL, float *inR, float *outL, float *outR);

};

#endif
