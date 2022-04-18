package com.vegeta.glndk

import android.opengl.GLSurfaceView
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class TriangleRenderer : GLSurfaceView.Renderer {
  override fun onSurfaceCreated(gl: GL10?, config: EGLConfig?) {
    init()
  }

  override fun onSurfaceChanged(gl: GL10?, width: Int, height: Int) {
    resize(width, height)
  }

  override fun onDrawFrame(gl: GL10?) {
    step()
  }


  private external fun init(): Boolean
  private external fun resize(width: Int, height: Int)
  private external fun step()
}