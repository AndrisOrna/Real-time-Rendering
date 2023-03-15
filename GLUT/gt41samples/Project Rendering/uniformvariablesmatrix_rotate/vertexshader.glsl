#version 330
                                       
layout (location = 0) in vec3 Position;
layout (location = 1) in vec4 Colour;

out vec4 Colour0;

uniform float gScale;
uniform vec2 gOffset;
uniform mat4 gTransform;
uniform mat4 gRotate;

//uniform float moveY;
                                                                   
void main()
{   gl_Position = vec4(gScale * Position.x, gScale * Position.y, Position.z, 1.0);

    gl_Position = gTransform * vec4(Position.x, Position.y, Position.z, 1.0);
	Colour0 = Colour;

    gl_Position = gRotate * vec4(Position.x, Position.y, Position.z, 1.0);
    Colour0 = Colour;

}