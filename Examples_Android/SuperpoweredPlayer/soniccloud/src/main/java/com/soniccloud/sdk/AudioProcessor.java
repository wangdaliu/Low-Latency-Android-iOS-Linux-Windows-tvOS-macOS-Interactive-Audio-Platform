package com.soniccloud.sdk;

public class AudioProcessor {

    /**
     * set the user's HL levels from test results.
     *
     * @param numPoints   number of points for each ear (e.g., 4 in the current demo)
     * @param frequencies an array of floats representing the tested frequencies in Hz
     * @param leftValues  left ear, representing test results per frequency in dBHL
     * @param rightValues right ear, representing test results per frequency in dBHL
     */
    public static void setAudiogram(int numPoints, float[] frequencies, float[] leftValues, float[] rightValues) {
        AudioProcessorJNI.setAudiogram(numPoints, frequencies, leftValues, rightValues);
    }

    /**
     * set the value of an abstract UI parameter.
     * (there will only be a small number of these, e.g. "personalization" or "naturalism")
     *
     * @param index (integer in [0,...N-1])
     * @param value in [0, 1]
     */
    public static void setParameter(int index, float value) {
        AudioProcessorJNI.setParameter(index, value);
    }



}
