package com.vegeta.glndk

import android.opengl.GLSurfaceView
import android.os.Bundle
import android.widget.FrameLayout
import androidx.appcompat.app.AppCompatActivity
import com.vegeta.glndk.databinding.GlActivityBinding
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class GLESActivity : AppCompatActivity() {
  private lateinit var binding: GlActivityBinding

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    binding = GlActivityBinding.inflate(layoutInflater)
    setContentView(binding.root)

    GLSurfaceView(this).apply {
      layoutParams = FrameLayout.LayoutParams(
        FrameLayout.LayoutParams.MATCH_PARENT,
        FrameLayout.LayoutParams.MATCH_PARENT
      )
      setEGLContextClientVersion(3)
    }.run {
      setRenderer(TriangleRenderer())
      binding.parent.addView(this)
    }


  }


}

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



