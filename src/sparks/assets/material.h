#pragma once
#include "cstdint"
#include "glm/glm.hpp"
#include "sparks/assets/util.h"

namespace sparks {

enum MaterialType : int {
  MATERIAL_TYPE_LAMBERTIAN = 0,
  MATERIAL_TYPE_SPECULAR = 1,
  MATERIAL_TYPE_TRANSMISSIVE = 2,
  MATERIAL_TYPE_PRINCIPLED = 3,
  MATERIAL_TYPE_EMISSION = 4
};

class Scene;

struct Material {
  glm::vec3 albedo_color{0.8f};
  int albedo_texture_id{0};
  glm::vec3 emission{0.0f};
  float emission_strength{1.0f};
  float alpha{1.0f};
  MaterialType material_type{MATERIAL_TYPE_LAMBERTIAN};
  float refraction_rate;
  int normal_texture_id{-1};
  /* BSDF PARAMETERS START */
  float anisotrophic;
  float clearcoat;
  float clearcoat_gloss;
  float metallic;
  float roughness;
  float sheen;
  float sheen_tint;
  float specular;
  float specular_tint;
  float specular_transmission;
  float subsurface;
  /* BSDF PARAMETERS END */
  float reserve[1]{};
  Material() = default;
  explicit Material(const glm::vec3 &albedo);
  Material(Scene *scene, const tinyxml2::XMLElement *material_element);
};
}  // namespace sparks
