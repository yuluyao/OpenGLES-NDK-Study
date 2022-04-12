#include <jni.h>

static int count;
extern "C"
JNIEXPORT void JNICALL
Java_com_vegeta_glndk_HelloJavaActivity_callback(JNIEnv *env, jobject thiz) {
    jclass activityClass = env->GetObjectClass(thiz);
    jmethodID method = env->GetMethodID(activityClass, "setText", "(I)V");
    env->CallVoidMethod(thiz, method, count++);
}