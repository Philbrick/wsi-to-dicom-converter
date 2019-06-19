# Dicomizer

### Requirements:
  - g++ >=8
  - cmake >=3
  - boost >=1.69
  - dcmtk source ==3.6.2
  - openslide >=3.4.1
  - libjpeg >= 8
  - openjpeg >= 2.3.0
  - jsoncpp >= 1.8.0

>https://www.boost.org/users/history/version_1_69_0.html

>https://dicom.offis.de/download/dcmtk/dcmtk362/dcmtk-3.6.2.zip

#### deb based 
>sudo apt install libtiff-dev libopenslide-dev libjpeg8-dev libjsoncpp-dev
#### rpm based
>sudo yum install libtiff-devel openslide-devel jsoncpp-devel


### How to build

If you're using Ubuntu then we have a script to help download dependencies and build the tool:

```shell
sudo ./cloud_build/ubuntuBuild.sh
```

Otherwise, make sure you've downloaded and installed the required dependencies and then run:
```shell
mkdir build
cd build
cp -R %dcmtkDir% ./dcmtk-3.6.2 
cmake ..
make -j%threads%
```


### How to use:
#### minimal
>./wsi2dcm --input <wsiFile> --outFolder <folder for generated files> --seriesDescription <text description>
#### all options
##### tileHeight 
tile height in px, 500 by default
##### tileWidth
tile width in px, 500 by default
##### levels 
number of levels to be generated, if levels == 0 levels and downsamples will be readed from wsi file
##### downsamples
downsample for each level, downsample is size factor for each level, if downsamples is not set then downsample[i]==2^i
##### startOn 
level to start
##### stopOn
level to stop, by default -1 which means stop on last one
##### sparse             
use TILED_SPARSE frame organization, by default it's TILED_FULL
##### compression 
supported compressions: jpeg, jpeg2000, raw
##### studyId 
StudyID, generated if not set
##### seriesId 
SeriesID
##### jsonFile    
json file with additional tags, which will be added to each dcm file without overwriting tags generated by wsi2dcm
##### batch 
maximum frames in one file, unlimited by default, if level have more frames than batch size, level will be splited to few files with additional tags: [ConcatenationFrameOffsetNumber](https://dicom.innolitics.com/ciods/vl-whole-slide-microscopy-image/multi-frame-functional-groups/00209228)
[InConcatenationNumber](https://dicom.innolitics.com/ciods/vl-whole-slide-microscopy-image/multi-frame-functional-groups/00209162)
[InConcatenationTotalNumber](https://dicom.innolitics.com/ciods/vl-whole-slide-microscopy-image/multi-frame-functional-groups/00209163)
##### threads 
number of threads to be used, if threads<1 then all threads is going to be used
##### debug
more debug messages
