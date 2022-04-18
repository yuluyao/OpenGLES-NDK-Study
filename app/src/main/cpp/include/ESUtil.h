#ifndef GLES_ESUTIL_H
#define GLES_ESUTIL_H
#include "../../../../../../../../Library/Android/sdk/ndk/21.4.7075529/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/GLES3/gl3.h"
#include "../../../../../../../../Library/Android/sdk/ndk/21.4.7075529/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/android/log.h"
#include "../../../../../../../../Library/Android/sdk/ndk/21.4.7075529/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/jni.h"
#ifndef LOG_TAG
#define LOG_TAG "ES_LIB"
#endif
#define STR(s) #s
#define STRV(s) STR(s)
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define ALOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#include "../../../../../../../../Library/Android/sdk/ndk/21.4.7075529/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/c++/v1/cstdlib"
#include "../../../../../../../../Library/Android/sdk/ndk/21.4.7075529/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/c++/v1/cmath"
#define  PI 3.1415
//检查当前程序错误
bool checkGlError(const char *funcName);
//获取并编译着色器对象
GLuint createShader(GLenum shaderType, const char *src);
//使用着色器生成着色器程序对象
GLuint createProgram(const char *vtxSrc, const char *fragSrc);
//产生一个立方体
int createCube(float scale, GLfloat **vertices, GLfloat **normals,
               GLfloat **texCoords, GLuint **indices);
int createSquareGrid ( int size, GLfloat **vertices, GLuint **indices );
//生成一个球
int createSphere(int numSlices, float radius, GLfloat **vertices, GLfloat **normals,
                 GLfloat **texCoords, GLuint **indices);
typedef struct {
    GLfloat m[4][4];
} Matrix;
//初始化一个矩阵
void matrixLoadIdentity(Matrix *result);
//矩阵变换
void translate(Matrix *result, GLfloat tx, GLfloat ty, GLfloat tz);
//矩阵旋转
void rotate(Matrix *result, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
//矩阵相乘
void matrixMultiply(Matrix *result, Matrix *srcA, Matrix *srcB);
//矩阵截取
void frustum(Matrix *result, float w, float h, float nearZ, float farZ);
//矩阵透视变换
void perspective(Matrix *result, float fovy, float aspect, float nearZ, float farZ);
void ortho(Matrix *result, float left, float right, float bottom, float top, float nearZ,
           float farZ);
void scale(Matrix *result, GLfloat sx, GLfloat sy, GLfloat sz);
void matrixLookAt(Matrix *result, float posX, float posY, float posZ, float lookAtX, float lookAtY,
                  float lookAtZ, float upX, float upY, float upZ);
#endif