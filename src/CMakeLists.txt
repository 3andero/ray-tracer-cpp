project(ray-tracer-cpp-lib)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
add_library(ray-tracer-cpp-lib utils/vec3.h material/material.h hittable/hit_record.h ray.h utils/vec.h utils/point.h utils/vec.cpp material/lambertian.h utils/color.h utils/enum_utils.h utils/rand_utils.h hittable/hittable.h hittable/sphere.h material/material_variant.h hittable/sphere.cpp hittable/hittable_variant.h hittable/hittable_container.cpp hittable/hittable_container.h material/lambertian.cpp hittable/hittable_variant.cpp camera.h ray_tracer.h material/material_variant.cpp anti_aliasing.h utils/vec3.cpp hittable/plane.cpp hittable/plane.h utils/common.h material/mirror.cpp material/mirror.h utils/rand_utils.cpp material/refraction.cpp material/refraction.h)
