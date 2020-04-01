#version 330
attribute highp vec3 position;
attribute highp vec3 normal;
attribute highp vec3 textureCoords;

uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;
uniform float time;
uniform mat4 lightSpaceMatrix;
uniform bool isAnimation;


out VS_OUT{
	vec3 FragPos;
	vec3 Normal;
	vec2 TexCoords;
	vec4 FragPosLightSpace;
} vs_out;



void main(void)
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

	gl_Position = projection * view * model * vec4(newVertex, 1.0);

	vs_out.FragPos = vec3(model * vec4(position, 1.0));
	vs_out.Normal = transpose(inverse(mat3(model))) * normal;
	vs_out.TexCoords = textureCoords.xy;
	vs_out.FragPosLightSpace = lightSpaceMatrix * vec4(vs_out.FragPos, 1.0);
}

