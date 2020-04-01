#version 330
attribute highp vec3 position;
attribute highp vec3 textureCoords;

uniform mat4 lightSpaceMatrix;
uniform mat4 model;
uniform float time;
uniform bool isAnimation;

out vec2 TexCoords;

void main()
{
    vec3 newVertex;

    newVertex.x = position.x;
    newVertex.y = position.y;
    newVertex.z = position.z;

    if (isAnimation) {
      if (position.y > 0) {
        newVertex.x = position.x + 0.01 * position.y * sin((time * 0.001) + 0.5);
        newVertex.y = position.y;
        newVertex.z = position.z + 0.01 * position.y * sin((time * 0.001) + 0.5);
      }
    }

    gl_Position = lightSpaceMatrix * model * vec4(newVertex, 1.0f);
    TexCoords = textureCoords.xy;
}
