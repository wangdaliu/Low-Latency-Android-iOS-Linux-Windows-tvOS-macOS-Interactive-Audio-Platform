#include <jni.h>
#include <string>
#include <android/log.h>
#include <AndroidIO/SuperpoweredAndroidAudioIO.h>
#include <Superpowered.h>
#include <SuperpoweredAdvancedAudioPlayer.h>
#include <SuperpoweredSimple.h>
#include <SuperpoweredCPU.h>
#include <malloc.h>
#include <SLES/OpenSLES_AndroidConfiguration.h>
#include <SLES/OpenSLES.h>
#include "ScDsp.h"


#define log_print __android_log_print

static SuperpoweredAndroidAudioIO *audioIO;
static SuperpoweredAdvancedAudioPlayer *player;
static float *floatBuffer;

// This is called periodically by the audio engine.
static bool audioProcessing (
        void * __unused clientdata, // custom pointer
        short int *audio,           // buffer of interleaved samples
        int numberOfFrames,         // number of frames to process
        int __unused samplerate     // sampling rate
) {
    if (player->process(floatBuffer, false, (unsigned int)numberOfFrames)) {

        // TODO Should process SC dsp


        SuperpoweredFloatToShortInt(floatBuffer, audio, (unsigned int)numberOfFrames);
        return true;
    } else {
        return false;
    }
}

// Called by the player.
static void playerEventCallback (
        void * __unused clientData,
        SuperpoweredAdvancedAudioPlayerEvent event,
        void *value
) {
    switch (event) {
        case SuperpoweredAdvancedAudioPlayerEvent_LoadSuccess:
            break;
        case SuperpoweredAdvancedAudioPlayerEvent_LoadError:
            log_print(ANDROID_LOG_ERROR, "PlayerExample", "Open error: %s", (char *)value);
            break;
        case SuperpoweredAdvancedAudioPlayerEvent_EOF:
            player->seek(0);    // loop track
            break;
        default:;
    };
}

// StartAudio - Start audio engine and initialize player.
extern "C" JNIEXPORT void
Java_com_superpowered_playerexample_MainActivity_StartAudio (
        JNIEnv * __unused env,
        jobject  __unused obj,
        jint samplerate,
        jint buffersize
) {
    SuperpoweredInitialize(
            "ExampleLicenseKey-WillExpire-OnNextUpdate",
            false, // enableAudioAnalysis (using SuperpoweredAnalyzer, SuperpoweredLiveAnalyzer, SuperpoweredWaveform or SuperpoweredBandpassFilterbank)
            false, // enableFFTAndFrequencyDomain (using SuperpoweredFrequencyDomain, SuperpoweredFFTComplex, SuperpoweredFFTReal or SuperpoweredPolarFFT)
            false, // enableAudioTimeStretching (using SuperpoweredTimeStretching)
            false, // enableAudioEffects (using any SuperpoweredFX class)
            true, // enableAudioPlayerAndDecoder (using SuperpoweredAdvancedAudioPlayer or SuperpoweredDecoder)
            false, // enableCryptographics (using Superpowered::RSAPublicKey, Superpowered::RSAPrivateKey, Superpowered::hasher or Superpowered::AES)
            false  // enableNetworking (using Superpowered::httpRequest)
    );

    // Allocate audio buffer.
    floatBuffer = (float *)malloc(sizeof(float) * 2 * buffersize);

    // Initialize player and pass callback function.
    player = new SuperpoweredAdvancedAudioPlayer (
            NULL,                           // clientData
            playerEventCallback,            // callback function
            (unsigned int)samplerate,       // sampling rate
            0                               // cachedPointCount
    );

    // Initialize audio with audio callback function.
    audioIO = new SuperpoweredAndroidAudioIO (
            samplerate,                     // sampling rate
            buffersize,                     // buffer size
            false,                          // enableInput
            true,                           // enableOutput
            audioProcessing,                // process callback function
            NULL,                           // clientData
            -1,                             // inputStreamType (-1 = default)
            SL_ANDROID_STREAM_MEDIA         // outputStreamType (-1 = default)
    );
}

// OpenFile - Open file in player, specifying offset and length.
extern "C" JNIEXPORT void
Java_com_superpowered_playerexample_MainActivity_OpenFile (
        JNIEnv *env,
        jobject __unused obj,
        jstring path,       // path to APK file
        jint offset,        // offset of audio file
        jint length         // length of audio file
) {
    const char *str = env->GetStringUTFChars(path, 0);
    player->open(str, offset, length);
    env->ReleaseStringUTFChars(path, str);
}

// TogglePlayback - Toggle Play/Pause state of the player.
extern "C" JNIEXPORT void
Java_com_superpowered_playerexample_MainActivity_TogglePlayback (
        JNIEnv * __unused env,
        jobject __unused obj
) {
    player->togglePlayback();
    SuperpoweredCPU::setSustainedPerformanceMode(player->playing);  // prevent dropouts
}

// onBackground - Put audio processing to sleep.
extern "C" JNIEXPORT void
Java_com_superpowered_playerexample_MainActivity_onBackground (
        JNIEnv * __unused env,
        jobject __unused obj
) {
    audioIO->onBackground();
}

// onForeground - Resume audio processing.
extern "C" JNIEXPORT void
Java_com_superpowered_playerexample_MainActivity_onForeground (
        JNIEnv * __unused env,
        jobject __unused obj
) {
    audioIO->onForeground();
}

// Cleanup - Free resources.
extern "C" JNIEXPORT void
Java_com_superpowered_playerexample_MainActivity_Cleanup (
        JNIEnv * __unused env,
        jobject __unused obj
) {
    delete audioIO;
    delete player;
    free(floatBuffer);
}






// Add SC process
ScDsp *scDsp;


extern "C"
JNIEXPORT jlong JNICALL
Java_com_superpowered_playerexample_AudioProcessorJNI_new_1ScDsp(
        JNIEnv * __unused env,
        jobject __unused obj) {
    jlong jresult;

    (void)env;
    (void)obj;
    scDsp = new ScDsp();
    *(ScDsp **)&jresult = scDsp;
    return jresult;
}

extern "C" JNIEXPORT void
Java_com_superpowered_playerexample_AudioProcessorJNI_setParameter(
        JNIEnv * __unused env,
        jobject __unused obj,
        jlong jarg,
        jint index,
        jfloat value) {

    __android_log_print(ANDROID_LOG_ERROR, "SonicCloudSDK", "setParameter %d", index);

}


extern "C" JNIEXPORT void
Java_com_superpowered_playerexample_AudioProcessorJNI_setAudiogram(
        JNIEnv * __unused env,
        jobject __unused obj,
        jlong jarg,
        jint numPoints,
        jfloatArray frequencies_,
        jfloatArray values_) {
    jfloat *frequencies = env->GetFloatArrayElements(frequencies_, NULL);
    jfloat *values = env->GetFloatArrayElements(values_, NULL);

    ScDsp *arg1;
    arg1 = *(ScDsp **)&jarg;

    scDsp->setAudiogram(numPoints, frequencies, values);


    __android_log_print(ANDROID_LOG_ERROR, "SonicCloudSDK", "setAudiogram %d", numPoints);

    env->ReleaseFloatArrayElements(frequencies_, frequencies, 0);
    env->ReleaseFloatArrayElements(values_, values, 0);
}
