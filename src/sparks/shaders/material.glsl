
struct Material {
  vec3 albedo_color;
  int albedo_texture_id;
  vec3 emission;
  float emission_strength;
  float alpha;
  uint material_type;
  float refraction_rate;
  int normal_texture_id;
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
};

#define MATERIAL_TYPE_LAMBERTIAN 0
#define MATERIAL_TYPE_SPECULAR 1
#define MATERIAL_TYPE_TRANSMISSIVE 2
#define MATERIAL_TYPE_PRINCIPLED 3
#define MATERIAL_TYPE_EMISSION 4

#define DEFAULT_REFRACTION_RATE 1.2