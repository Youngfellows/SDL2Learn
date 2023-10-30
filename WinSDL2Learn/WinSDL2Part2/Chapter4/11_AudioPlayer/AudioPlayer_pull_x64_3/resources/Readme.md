# PCM 文件素材制作

### 一、使用 ffmpeg 查看 mp3 文件的一些信息，比如采样率、声道数等

```c++
ffmpeg -i 慕容雪-薛凯琪.mp3
```
* 结果

  ```java
  Input #0, mp3, from '慕容雪-薛凯琪.mp3':
    Metadata:
      artist          : 薛凯琪
      album           : Read Me
      title           : 慕容雪
      TYER            : 2009-10-16
    Duration: 00:04:00.54, start: 0.000000, bitrate: 256 kb/s
    Stream #0:0: Audio: mp3, 44100 Hz, stereo, fltp, 256 kb/s
    Stream #0:1: Video: mjpeg (Baseline), yuvj444p(pc, bt470bg/unknown/unknown), 240x240 [SAR 72:72 DAR 1:1], 90k tbr, 90k tbn (attached pic)
      Metadata:
        title           : e
        comment         : Cover (front)
  ```



### 二、使用 FFmpeg 转换时要用到上面的信息为pcm原始音频

```c++
ffmpeg -i 慕容雪-薛凯琪.mp3 -acodec pcm_s16le -f s16le -ac 2 -ar 44100 慕容雪-薛凯琪.pcm
```

* 其中：

  ```java
  -acodec pcm_s16le
  ·指定编码器
  -f s16le
  ·指定文件格式，是大端模式还是小端模式
  -ac 2
  ·指定通道数，2 代表双通道
  -ar 44100
  ·指定采样率，这里是 44100 Hz
  在转换时要根据原文件的采样率和声道数进行转换，否则转换后的 pcm 文件播放声音不对了。
  ```



### 三、验证转换后的pcm是否正确

  ```c++
ffplay -ar 44100 -channels 2 -f s16le -i 慕容雪-薛凯琪.pcm		
  ```
