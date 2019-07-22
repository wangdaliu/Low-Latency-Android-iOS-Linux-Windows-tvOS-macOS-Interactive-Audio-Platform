package com.superpowered.playerexample;

public class AudioProcessorJNI {

    static {
        try {
            java.lang.System.loadLibrary("audio_processing");
        } catch (UnsatisfiedLinkError e) {
        }
    }

    public static native void new_ScDsp();

    public static native void setAudiogram(int numPoints, float[] frequencies, float[] leftValues, float[] rightValues);

    public static native void setParameter(int index, float value);
}