#include "scene.h"

class Facade {
    private:
        Napi::Env env;
        Scene *scene;

    public:
        Facade(Napi::Env &env);
        void createCube();
        Napi::Object createExports(Napi::Object exports);
};