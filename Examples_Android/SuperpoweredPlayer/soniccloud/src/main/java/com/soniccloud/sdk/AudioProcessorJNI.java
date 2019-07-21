package com.soniccloud.sdk;

class AudioProcessorJNI {

    static {
        try {
            java.lang.System.loadLibrary("audio_processing");
        } catch (UnsatisfiedLinkError e) {
            java.lang.System.err.println("native code library failed to load.\n" + e);
            java.lang.System.exit(1);
        }
    }

    public static native void setAudiogram(int numPoints, float[] frequencies, float[] leftValues, float[] rightValues);

    public static native void setParameter(int index, float value);
}
