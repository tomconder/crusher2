#ifndef INCLUDE_CRUSHER2_H
#define INCLUDE_CRUSHER2_H

#include "core/engine.h"
#include "core/gamecamera.h"
#include "platform/opengl/openglsprite.h"

#include <memory>
#include <string>

class Crusher2 : public Engine {
public:
    Crusher2();

    bool onUserCreate() override;
    bool onUserUpdate(Uint32 elapsedTime) override;
    bool onUserDestroy() override;
    bool onUserResize(int width, int height) override;

private:
    std::unique_ptr<GameCamera> camera;
    std::unique_ptr<OpenGLSprite> sprite;
};

#endif //INCLUDE_CRUSHER2_H
