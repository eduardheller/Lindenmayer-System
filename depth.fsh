#version 330

in vec2 TexCoords;
uniform sampler2D colorTexture;

void main()
{
    if(texture(colorTexture, TexCoords).a < 0.5)
      discard;
    // gl_FragDepth = gl_FragCoord.z;
}
