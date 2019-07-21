package com.superpowered.playerexample;

public class AudioProcessorJNI {

    static {
        try {
            java.lang.System.loadLibrary("audio_processing");
        } catch (UnsatisfiedLinkError e) {
        }
    }

    public static native long new_ScDsp();

    public static native void setAudiogram(long jarg, int numPoints, float[] frequencies, float[] values);

    public static native void setParameter(long jarg, int index, float value);
}