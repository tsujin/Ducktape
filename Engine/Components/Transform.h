/*
Ducktape | An open source C++ 2D & 3D game engine that focuses on being fast, and powerful.
Copyright (C) 2022 Aryan Baburajan

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

In case of any further questions feel free to contact me at
the following email address:
aryanbaburajan2007@gmail.com
*/

#pragma once

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>

#include <Core/Scene.h>
#include <Components/Component.h>
#include <Core/Serialization.h>
#include <Core/Engine.h>

namespace DT
{
    /**
     * @brief Transform class for model transformation set (translation, rotation, scale). Extends Component class
     */
    class Transform : public Component
    {
    public:
        glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);           ///< Translation vector
        glm::quat rotation = glm::quat(0.0f, 0.0f, 0.0f, 0.0f);     ///< Rotation in quaternion form
        glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);              ///< Scale vector

        /**
         * @brief Returns the Translation->Rotation->Scale model matrix
         * @return GLM 4x4 transform matrix
         */
        glm::mat4 GetModelMatrix();

        /**
         * @brief Updates all Transform members from GLM 4x4 combined transform matrix decomposition
         * @param mat GLM 4x4 combined transform matrix
         */
        void SetModelMatrix(glm::mat4);

        /**
         * @brief Returns right vector of Transform rotated model
         * @return GLM 3-vector (rotated X axis)
         */
        glm::vec3 Right();

        /**
         * @brief Returns forward vector of Transform rotated model
         * @return GLM 3-vector (rotated Z axis)
         */
        glm::vec3 Forward();

        /**
         * @brief Returns up vector of Transform rotated model
         * @return GLM 3-vector (rotated Y axis)
         */
        glm::vec3 Up();

        /**
         * @brief Adds value input for position, rotation and scale into ImGui interface
         */
        void Inspector();

        /**
         * @brief Static function for EnTT entity management on Transform objects
         * @param scene Scene object from which call entity management
         */
        static void System(Scene *scene);
    };
}