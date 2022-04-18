package com.vegeta.glndk

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.vegeta.glndk.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

  private lateinit var binding: ActivityMainBinding

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)

    binding = ActivityMainBinding.inflate(layoutInflater)
    setContentView(binding.root)

    // Example of a call to a native method
    binding.sampleText.text = stringFromJNI()

    binding.btnHelloJava.setOnClickListener { startActivity(Intent(this,HelloJavaActivity::class.java)) }

    binding.btnGL.setOnClickListener { startActivity(Intent(this,GLESActivity::class.java)) }
  }

  /**
   * A native method that is implemented by the 'glndk' native library,
   * which is packaged with this application.
   */
  external fun stringFromJNI(): String



  companion object {
    // Used to load the 'glndk' library on application startup.
    init {
      System.loadLibrary("glndk")
    }
  }
}


