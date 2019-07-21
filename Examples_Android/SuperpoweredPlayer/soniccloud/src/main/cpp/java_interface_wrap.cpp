//#include <jni.h>
//#include <string>
//#include <android/log.h>
//#include <malloc.h>
//#include "ScDsp.h"
//
//extern "C" JNIEXPORT void
//Java_com_soniccloud_sdk_AudioProcessorJNI_setParameter(JNIEnv *env, jclass type, jint index,
//                                                       jfloat value) {
//    __android_log_print(ANDROID_LOG_ERROR, "SonicCloudSDK", "setParameter %d", index);
//
//
//}
//
//extern "C" JNIEXPORT void
//Java_com_soniccloud_sdk_AudioProcessorJNI_setAudiogram(JNIEnv *env, jclass type, jint numPoints,
//                                                       jfloatArray frequencies_,
//                                                       jfloatArray values_) {
//    jfloat *frequencies = env->GetFloatArrayElements(frequencies_, NULL);
//    jfloat *values = env->GetFloatArrayElements(values_, NULL);
//
//
//    __android_log_print(ANDROID_LOG_ERROR, "SonicCloudSDK", "setAudiogram");
//
//    env->ReleaseFloatArrayElements(frequencies_, frequencies, 0);
//    env->ReleaseFloatArrayElements(values_, values, 0);
//}