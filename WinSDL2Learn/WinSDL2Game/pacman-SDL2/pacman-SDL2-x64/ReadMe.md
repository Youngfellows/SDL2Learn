# 使用SDL2实现的吃豆人游戏

## 使用
- 向左移动: 按键A
- 向右移动: 按键D
- 向上移动: 按键W
- 向下移动: 按键S



## 截图

![snapshot](./snapshot/snapshot.png)



## 编译

Windows下使用CMake可以进行编译：

```bash
cmake -S . -B cmake-build -DSDL2_ROOT=<your SDL path>
cmake --build cmake-build
```
