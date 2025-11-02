#include "scene.h"

class Facade {
    private:
        Napi::Env env;
        Scene scene;
        
    public:
        Facade(Napi::Env env) {
            this.env = info.Env();
            this.scene = new Scene();
        }

        void createCube() {
            this.scene.createCube();
        }

        Napi::Object createExports(Napi::Object exports) {
            exports.Set(
              Napi::String::New(env, "createCube"),
              Napi::Function::New(env, createCube)
            );
        }

}