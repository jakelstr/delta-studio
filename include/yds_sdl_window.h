#pragma once

#include "yds_window.h"

#ifdef __APPLE__
#include <SDL.h>
#include <SDL_video.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#endif


class ysSdlWindowSystem;
class ysOpenGLSdlContext;

class ysSdlWindow : public ysWindow {
    friend ysSdlWindowSystem;
    friend ysOpenGLSdlContext;

public:
    ysSdlWindow();
    ~ysSdlWindow();

    // Overrides
    virtual ysError InitializeWindow(ysWindow *parent, std::string title, WindowStyle style, int x, int y, int width, int height, ysMonitor *monitor, ysContextObject::DeviceAPI api) override;
    virtual void SetState(WindowState state) override;
    virtual void SetTitle(std::string title) override;
    virtual bool SetWindowStyle(WindowStyle style) override;
    SDL_Renderer* GetRenderer() const {return m_renderer;}

protected:
    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer;
    int m_old_width = 0;
    int m_old_height = 0;
};
