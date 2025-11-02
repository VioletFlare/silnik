#include "scene.h"

class Facade {
    private:
        Napi::Env env;
        Scene scene;
        bool isInitialized = false;
        
    public:
        Facade(const Napi::CallbackInfo& info, Napi::Object exports) {
            this.env = info.Env();
        }

        void init() {
            this.scene = new Scene();
        }

        void createCube() {

        }
}