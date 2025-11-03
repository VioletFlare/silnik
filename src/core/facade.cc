#include <napi.h>
#include "facade.h"

Facade::Facade(Napi::Env &env): env{ env } {
    this->env = env;
    this->scene = new Scene();
}

void Facade::createCube() {
    this->scene->createCube();
}

Napi::Object Facade::createExports(Napi::Object exports) {
    std::function<void(Napi::CallbackInfo info)> createCube = std::bind(&Facade::createCube, this);

    exports.Set(
        Napi::String::New(env, "createCube"),
        Napi::Function::New(env, createCube)
    );

    return exports;
}