# Build so

```groovy
    ndk {
        abiFilters 'armeabi-v7a', 'arm64-v8a', 'x86', 'x86_64'
    }

    externalNativeBuild {
        cmake {
            cppFlags "-frtti -fexceptions"
            abiFilters "x86", "x86_64", "armeabi-v7a", "arm64-v8a"
        }
    }

```

```groovy

    externalNativeBuild {
        cmake {
            path "CMakeLists.txt"
        }
    }

```


- Expand gradle panel from right and open all tasks under yourlibrary->build. You will see the task - assemble
- Double click on assemble
- Once the task run successfully, get your generated so file in `app/libs/`