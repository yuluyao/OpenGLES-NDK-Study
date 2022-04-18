#include <GLES3/gl3.h>
#include <android/log.h>
#include "include/es-util.h"

#define LOG_TAG "TRIANGLE-LIB"
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include <jni.h>
#include <stdlib.h>

static const char VERTEX_SHADER[] =
        "#version 300 es\n"
        "layout(location = 0) in vec4 vPosition;\n"
        "void main(){\n"
        "gl_Position = vPosition;\n"
        "}\n";
static const char FRAGMENT_SHADER[] =
        "#version 300 es\n"
        "precision mediump float;\n"
        "out vec4 fragColor;\n"
        "void main(){\n"
        "fragColor = vec4(1.0,0.0,0.0,1.0);\n"
        "}\n";
static const GLfloat VERTEX[] = {
        0.0f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
};

GLuint program;

//extern "C" {
//JNIEXPORT jboolean JNICALL
//Java_com_vegeta_glndk_GLActivity_init(JNIEnv *env, jobject thiz);
//
//JNIEXPORT void JNICALL
//Java_com_vegeta_glndk_GLActivity_resize(JNIEnv *env, jobject thiz, jint width, jint height);
//
//JNIEXPORT void JNICALL
//Java_com_vegeta_glndk_GLActivity_step(JNIEnv *env, jobject thiz);
//
//}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_vegeta_glndk_GLActivity_init(JNIEnv *env, jobject thiz) {
    program = createProgram(VERTEX_SHADER, FRAGMENT_SHADER);
    if (!program) {
        ALOGE("程序创建失败");
        return JNI_FALSE;
    }
    glClearColor(0, 0, 0, 0);
    return JNI_TRUE;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_vegeta_glndk_GLActivity_resize(JNIEnv *env, jobject thiz, jint width, jint height) {
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_vegeta_glndk_GLActivity_step(JNIEnv *env, jobject thiz) {
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, VERTEX);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
