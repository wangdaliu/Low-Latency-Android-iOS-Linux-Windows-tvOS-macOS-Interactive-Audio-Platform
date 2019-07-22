package com.superpowered.playerexample;

public class ScDsp {

    public ScDsp() {
        AudioProcessorJNI.new_ScDsp();
    }

    void setAudiogram(int numPoints, float[] frequencies, float[] leftValues, float[] rightValues) {
        AudioProcessorJNI.setAudiogram(numPoints, frequencies, leftValues, rightValues);
    }

    void setParameter(int index, float value) {
        AudioProcessorJNI.setParameter(index, value);
    }
}