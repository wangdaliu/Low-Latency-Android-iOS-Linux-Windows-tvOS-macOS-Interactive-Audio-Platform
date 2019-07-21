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

Select module `Soniccloud`, Build -> Make Project. so file will in `jnilibs` module

# Build jar

```groovy

    task deleteJar(type: Delete) {
        delete 'libs/jars/soniccloud.jar'
    }

    task createJar(type: Copy) {
        from('build/intermediates/packaged-classes/release/')
        into('libs/jars/')
        include('classes.jar')
        rename('classes.jar', 'soniccloud.jar')
    }

    createJar.dependsOn(deleteJar, build)

```

- Expand gradle panel from right and open all tasks under yourlibrary->others. You will see two new tasks there -- createJar and deleteJar 
- Double click on createJar
- Once the task run successfully, get your generated jar from path mentioned in createJar task i.e. libs/xxxx.jar 
- copy the newly generated jar into your required project's lib folder-->right click-->select "add as library"