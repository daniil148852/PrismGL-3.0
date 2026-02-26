package com.prismgl.app

import android.Manifest
import android.content.pm.PackageManager
import android.os.Build
import android.os.Bundle
import android.os.Environment
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import org.json.JSONObject
import java.io.File

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val textView = TextView(this)
        textView.text = "PrismGL registration"
        setContentView(textView)

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            val permission = Manifest.permission.WRITE_EXTERNAL_STORAGE
            if (ContextCompat.checkSelfPermission(this, permission) != PackageManager.PERMISSION_GRANTED) {
                ActivityCompat.requestPermissions(this, arrayOf(permission), 1001)
            } else {
                writeConfig()
            }
        } else {
            writeConfig()
        }
    }

    override fun onRequestPermissionsResult(requestCode: Int, permissions: Array<out String>, grantResults: IntArray) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        if (requestCode == 1001 && grantResults.isNotEmpty() && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
            writeConfig()
        }
    }

    private fun writeConfig() {
        val root = Environment.getExternalStorageDirectory()
        val configDir = File(root, "PrismGL")
        if (!configDir.exists()) {
            configDir.mkdirs()
        }
        val configFile = File(configDir, "config.json")
        val rendererJson = JSONObject()
        rendererJson.put("name", "PrismGL 3.0")
        rendererJson.put("version", "3.0.0")
        rendererJson.put("library", "libprismgl.so")
        rendererJson.put("supported_versions", listOf("1.16.5", "1.18.2", "1.19.4", "1.20.1"))
        rendererJson.put("features", listOf("shader_cache", "adaptive_rendering", "sodium_compat"))
        rendererJson.put("gl_version", "3.2")
        rendererJson.put("gles_version", "3.2")

        val rootJson = JSONObject()
        rootJson.put("renderer", rendererJson)

        configFile.writeText(rootJson.toString(2))
    }
}
