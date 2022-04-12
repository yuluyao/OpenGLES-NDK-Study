package com.vegeta.glndk

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.vegeta.glndk.databinding.HelloJavaActivityBinding

class HelloJavaActivity : AppCompatActivity() {

  private lateinit var binding: HelloJavaActivityBinding

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    binding = HelloJavaActivityBinding.inflate(layoutInflater)
    setContentView(binding.root)
    binding.btnCallback.setOnClickListener { callback() }

  }

  external fun callback()
  fun setText(count: Int) {
    binding.sampleText.text = "count: $count"
  }

  companion object {
    // Used to load the 'glndk' library on application startup.
    init {
//      System.loadLibrary("glndk")
    }
  }
}