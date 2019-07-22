# Use SonicCloud sdk

- Move so files to `app/libs/`
- Add in gradle

```groovy

    sourceSets{
        main{
            jniLibs.srcDirs = ['libs']
        }
    }

```
    
- Add in dependencies

```groovy

    implementation fileTree(include: ['*.jar'], dir: 'libs')

```

- Add in CMakeLists

```cmake

    add_library(audio_processing SHARED IMPORTED)

    set_target_properties(audio_processing
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/libs/${CMAKE_ANDROID_ARCH_ABI}/libaudio_processing.so)
        
```