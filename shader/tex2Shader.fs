#version 330 core

out vec4 FragColor;
in vec2 TexCoord;
in vec3 ourColor;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_diffuse2;

void main() {
  FragColor = mix(texture(texture_diffuse2, TexCoord) * vec4(ourColor, 1.0), texture(texture_diffuse1, TexCoord), 0.2);
}
