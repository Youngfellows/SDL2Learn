#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP
#include "GL/glew.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Program.hpp"
#include "math.hpp"
#include <map>
using namespace std;

enum KeyState{
    PRESSED,    /** 在这一帧中才按下*/
    PRESSING,   /** 已经按下超过一帧了*/
    RELEASED,   /** 在这一帧中才松开*/
    RELEASING   /** 已经松开超过一帧了*/
};

class Director{
public:
    static void Init(SDL_Window* window, int w, int h, int fps);
    static void Quit();
    static Director* GetInstance();
    SDL_Window* GetWindow();
    SDL_Event& GetEvent();
    int Width() const;
    int Height() const;
    int WindowWidth();
    int WindowHeight();
    void EventHandle();
    void SizeAdapt(int neww, int newh);
    enum KeyState Key_State(SDL_Keycode keycode);
    enum KeyState MouseButtonState(Uint8 button);
    Vec GetMousePos() const;
    void Exit();
    void Update();
    bool IsQuit() const;
    int fps;
    void ChangeScene(int num);
    int GetSceneID() const;
    bool isquit;
    bool isover;
private:
    static Director* director;
    SDL_Window* window;
    SDL_Event event;
    int width;
    int height;
    map<SDL_Keycode, bool> keys;
    map<SDL_Keycode, bool> oldkeys;
    map<Uint8, bool> mousekeys;
    map<Uint8, bool> oldmousekeys;
    Vec mousepos;
    int scene_num;
    Director(SDL_Window* window, int w, int h, int fps);
};

#endif
