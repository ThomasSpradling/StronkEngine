#ifndef STRONK_EXAMPLE_H_
#define STRONK_EXAMPLE_H_

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <nlohmann/json.hpp>

#include <spdlog/spdlog.h>

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stb_image.h>

#include <imgui.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>

// Include additional GLM functionality for transformations, quaternions, etc.
#include <glm/gtc/matrix_transform.hpp>  // For glm::lookAt, glm::perspective
#include <glm/gtc/quaternion.hpp>        // For quaternion support
#include <glm/gtx/string_cast.hpp>  

#include <string>

namespace Stronk {

    class Example {
    public:
        Example();
        auto Get() -> std::string;
    private:
        std::string value;
    };

}

#endif // STRONK_EXAMPLE_H_
