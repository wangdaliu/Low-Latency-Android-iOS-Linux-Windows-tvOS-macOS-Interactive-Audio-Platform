# Use SonicCloud sdk

- Copy soniccloud.jar and so file to libs

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