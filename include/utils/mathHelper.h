#pragma once 

#include <glm/glm.hpp>

#include <cmath>

namespace ice{
class mathHelper{
    public:
        static float clamp01(float toClamp){
            float backer = 0;
            if (toClamp > 1 || toClamp < 0){
                backer = toClamp - std::floor(toClamp);
            }

            return backer;
        }
    
        static glm::vec3 lerp(glm::vec3 origin, glm::vec3 target, float alpha){
            glm::vec3 backer(0,0,0);

            backer.x = (1-alpha)*origin.x + target.x*alpha;
            backer.y = (1-alpha)*origin.y + target.x*alpha;
            backer.z = (1-alpha)*origin.z + target.x*alpha;

            return backer;
        };
      
};
}
